const ipcRenderer = require('electron').ipcRenderer;

var listFirmwareComponent = Vue.extend({
    template: `
    <div>
        <div class="search-bar">
            <input v-on:input="filter($event)" class="inputbox-search" spellcheck=false type="text" placeholder="Search..." />
            <img v-on:click="getFirmwareData" draggable="false" src="./images/refresh.png" title="Update List" />
            <img v-on:click="addLocalFirmware" draggable="false" src="./images/add.png" title="Add Local Firmware" />
            <img style="display:none" v-on:click="openSetting" draggable="false" src="./images/setting.png" title="Open Settings" />
            <div style="display:none" class="notice-update" v-bind:class="{update: needUpdate}"></div>
            <div class="clear"></div>
        </div>
        <div class="list-firmware">
            <div class="firmware-box" v-for="firmware in filterFirmwares">
                <p v-bind:class="{selected: selectedFirmware==firmware.name, undownload: !firmware.local}" v-on:click="selectFirmware(firmware)" class="firmware">{{ firmware.name }}</p>
                <img draggable="false" @click="downloadFirmware(firmware)" v-show="firmware.local == false" class="img-download" src="./images/download.png" />
                <img draggable="false" @click="removeFirmware(firmware)" class="img-remove" src="./images/remove.png" />
                <div class="mask" v-show="isDownload(firmware)">
                    <div class="progress-bar" v-bind:style="{width: computeProgress(firmware)}" ></div>
                </div>
            </div>
        </div>
        <div class="waiting" v-show="isLoading">
            <div class="circle"></div>
        </div>
    </div>
    `,
    data: function() {
        return {
            isLoading: true,
            needUpdate: false,
            downloadLock: false
        }
    },
    mounted: function() {
        this.getFirmwareData();
        this.queryAppVersion();
        ipcRenderer.on('query-app-version-callback', (event, data) => {
            if(data.need_update) {
                this.needUpdate = true;
            }
        });
    },
    beforeMount: function() {
        this.downloadList = [];
    },
    props: {
        firmwares: [],
        selectedFirmware: '',
        filterFirmwares: [],
        downloadList: []
    },
    methods: {
        selectFirmware: function(firmware) {
            this.selectedFirmware = firmware.name;
            window.firmware = firmware;
            this.$root.$emit('update-select-firmware', firmware);
        },
        filter: function($event) {
            var name = $event.target.value;
            if(name == '') {
                this.filterFirmwares = this.firmwares;
                return;
            }
            this.filterFirmwares = this.firmwares.filter(f => new RegExp(name, 'ig').test(f.name) );
            if(this.filterFirmwares.length > 0) {
                this.selectedFirmware = this.filterFirmwares[0].name;
                window.firmware = this.filterFirmwares[0];
            } else {
                this.selectedFirmware = '';
                window.firmware = '';
            }
        },
        getFirmwareData: function() {
            var _this = this;
            this.isLoading = true;
            ipcRenderer.on('firmware-callback', function(event, data){
                _this.isLoading = false;
                var firmwares = data;
                _this.firmwares = firmwares;
                _this.filterFirmwares = _this.firmwares;
                if(firmwares.length > 0) {
                    _this.selectedFirmware = firmwares[0].name;
                    window.firmware = firmwares[0];
                    _this.$root.$emit('update-select-firmware', firmwares[0]);
                }
            });
            ipcRenderer.send('firmware', '');
        },
        downloadFirmware: function(firmware) {
            if(this.downloadLock) {
                this.$root.$emit('add-message', '[Warning]: Operation too frequently.Please try again later.\n');
                return;
            }
            this.downloadLock = true;
            var _this = this;
            ipcRenderer.on('download-fw-callback', function(event, data){
                switch(data.status) {
                    case 'FINISHED':
                        _this.getFirmwareData();
                        var index = _this.downloadList.findIndex(d => d.target == data.target);
                        if(index != -1) {
                            _this.downloadList.splice(_this.downloadList.findIndex(d => d.target == data.target), 1);
                        }
                        break;
                    case 'DOWNLOADING':
                        var index = _this.downloadList.findIndex(d => d.target == data.target);
                        _this.downloadList[index].progress = data.progress;
                        break;
                    default:
                        _this.downloadList.splice(_this.downloadList.findIndex(d => d.target == data.target), 1);
                        _this.getFirmwareData();
                        break;
                }
            });
            ipcRenderer.send('download-fw', firmware);
            this.downloadList.push({
                target: firmware.name,
                progress: 0
            });
            setTimeout(function() {
                _this.downloadLock = false;
            }, 1000);
        },
        removeFirmware: function(firmware) {
            if(!firmware.local) {
                this.$root.$emit('add-message', 'This firmware had been removed.\n');
                return;
            }
            var result = ipcRenderer.sendSync('remove-fw', firmware.name);
            if(result == 1) {
                this.getFirmwareData();
            }
        },
        isDownload: function(firmware) {
            return this.downloadList.findIndex(d => d.target == firmware.name) > -1;
        },
        computeProgress: function(firmware) {
            var index = this.downloadList.findIndex(d => d.target == firmware.name);
            return index > -1 ? (this.downloadList[index].progress * 0.9 * 100) + '%' : 0;
        },
        addLocalFirmware: function() {
            var _this = this;
            var filebox = document.createElement('input');
            filebox.type = 'file';
            filebox.accept = 'application/zip';
            filebox.click();
            filebox.onchange = function(ev){
                let file = ev.path[0].files[0];
                ipcRenderer.send('add-fw', { name: file.name, path: file.path });
                ipcRenderer.on('add-fw-callback', function(event, data) {
                    if(data) {
                        _this.$root.$emit('add-message', 'Add firmware to M5Burner successfully.\n');
                        ipcRenderer.send('firmware', '');
                    } else {
                        _this.$root.$emit('add-message', 'Add firmware to M5Burner failed.Please check if your firmware file is correct.\n');
                    }
                });
            };
        },
        queryAppVersion: function() {
            ipcRenderer.send('query-app-version', '');
        },
        openSetting: function() {
            this.$root.$emit('open-setting-panel');
        }
    }
});

Vue.component('list-firmware', listFirmwareComponent);

var burnerFormComponent = Vue.extend({
    template: `
    <div>
        <form>
            <div class="form-input line">
                <span>COM:</span>
                <select id="val_com" @mousedown="updateCOM">
                    <option v-for="c in com" v-bind:value="c">{{ c }}</option>
                </select>
            </div>

            <div class="form-input line">
                <span>Baudrate:</span>
                <select id="val_baudrate" v-bind:value="default_baud">
                    <option value="921600">921600</option>
                    <option value="750000">750000</option>
                    <option value="512000">512000</option>
                    <option value="256000">256000</option>
                    <option value="230400">230400</option>
                    <option value="115200">115200</option>
                </select>
            </div>

            <div class="form-input line" v-show="versions.length>0">
                <span>Series:</span>
                <select id="val_version" v-on:change="updateFormData">
                    <option v-for="v in versions" v-bind:value="v">{{ v }}</option>
                </select>
            </div>
            
            <div class="form-input clear">
                <span>Author:</span>
                <span class="text">{{ author }}</span>
            </div>

            <div class="form-input">
                <span>Device:</span>
                <span class="text">{{ device }}</span>
            </div>

            <div class="form-input">
                <span>Framework:</span>
                <span class="text">{{ framework }}</span>
            </div>

            <div class="form-input">
                <span>Description:</span>
                <span class="text">{{ description }}</span>
            </div>

            <div class="form-input" v-if="isUIFlow">
                <span>SSID:</span>
                <input id="val_ssid" type="text" v-on:input="saveSSID($event)" v-model="last_ssid" />
            </div>

            <div class="form-input" v-if="isUIFlow">
                <span>Password:</span>
                <input id="val_pwd" type="text" v-on:input="savePWD($event)" v-model="last_pwd" />
            </div>

            <div class="form-button">
                <button id="btn_erase" v-on:click="erase($event)">Erase</button>
                <button id="btn_burn" v-on:click="burn($event)">Burn</button>
            </div>
        </form>
    </div>
    `,
    methods: {
        burn: function($event) {
            $event.preventDefault();
            var firmware = window.firmware;
            if(!firmware.local) {
                this.$root.$emit('add-message', 'You must download this firmware before burn it.\n');
                return;
            }
            var val_com = document.getElementById('val_com').value;
            var val_baudrate = document.getElementById('val_baudrate').value;
            var val_version = this.versions.length > 0 ? document.getElementById('val_version').value : '';
            var val_ssid = null;
            var val_pwd = null;
            if(document.getElementById('val_ssid') != null && document.getElementById('val_pwd') != null) {
                val_ssid = document.getElementById('val_ssid').value;
                val_pwd = document.getElementById('val_pwd').value;
            }
            if(firmware == '' || val_com == '' || val_baudrate == '') {
                this.$root.$emit('add-message', 'Check your configuration.\n');
                return;
            }
            var burnInfo = {
                com: val_com,
                baudrate: val_baudrate,
                version: val_version,
                firmware: firmware.name,
                pk: firmware.pk
            };
            if(val_ssid != null && val_pwd != null) {
                burnInfo['ssid'] = val_ssid;
                burnInfo['pwd'] = val_pwd;
            }
            ipcRenderer.send('burn', burnInfo);
        },
        erase: function($event) {
            $event.preventDefault();
            var val_com = document.getElementById('val_com').value;
            ipcRenderer.send('erase', {com: val_com});
        },
        updateCOM: function() {
            var com = ipcRenderer.sendSync('com', '');
            this.com = com;
        },
        updateFormData: function() {
            if(this.category instanceof Array) {
                var val_version = document.getElementById('val_version').value;
                this.category.forEach(c => {
                    if(c[val_version] != undefined) {
                        this.device = c[val_version]['device'].join(', ');
                        this.default_baud = c[val_version]['default_baud'];
                    }
                });
            } else {
                this.device = this.category['device'].join(', ');
                this.default_baud = this.category['default_baud'];
            }
        },
        saveSSID: function(ev) {
            localStorage.setItem('ssid', ev.target.value);
        },
        savePWD: function(ev) {
            localStorage.setItem('pwd', ev.target.value);
        }
    },
    data: function(){
        return {
            com: [],
            versions: [],
            author: '',
            description: '',
            framework: '',
            default_baud: 921600,
            device: '',
            category: null,
            isUIFlow: false,
            last_ssid: localStorage.getItem('ssid') || '',
            last_pwd: localStorage.getItem('pwd')  || ''
        }
    },
    mounted: function() {
        var com = ipcRenderer.sendSync('com', '');
        this.com = com;

        this.$root.$on('update-select-firmware', data => {
            this.versions = data.versions;
            this.author = data.author;
            this.description = data.description;
            this.framework = data.framework;
            this.category = data.category;
            this.isUIFlow = data.name >= 'UIFlow-v1.4.5';
            this.last_ssid = localStorage.getItem('ssid') || '';
            this.last_pwd = localStorage.getItem('pwd')  || '';
            this.updateFormData();
        });
    }
});

Vue.component('burner-form', burnerFormComponent);

var terminalComponent = Vue.extend({
    template: `
    <div>
        <textarea id="message_box" spellcheck="false" readonly v-model="msg"></textarea>
    </div>
    `,
    beforeMount: function() {
        this.msg = '';
    },
    mounted: function() {
        var _this = this;
        var message_box = document.getElementById('message_box');
        ipcRenderer.on('burner-callback', function(event, data) {
            if(data == undefined) return;
            message_box.scrollTop = message_box.scrollHeight;
            _this.msg += data;
        });
        this.$root.$on('add-message', function(data){
            message_box.scrollTop = message_box.scrollHeight;
            _this.msg += data;
        });
    },
    props: {
        msg: ''
    }
});

Vue.component('ternimal', terminalComponent);

var settingPanelComponent = Vue.extend({
    template: `
        <div class="wrapper" v-bind:class="{display: lazy_load}" v-show="visibility" v-on:click="handleClosePanel">
            <div class="panel" v-on:click="handleStopPropagetion">
                <h1>Setting</h1>
                <div class="text-label">
                    <span>Version:</span>
                    <span style="font-weight: bolder;">{{ version }}</span>
                    <span style="color:rgb(0, 100, 160);text-decoration: underline;" v-show="is_update_success">Restart Now</span>
                    <button class="btn_update" v-on:click="handleUpdateApp" v-show="btn_update_visibility">Update</button>
                </div>
                <div class="update-progress" v-show="is_updating">
                    <p class="progress-text">{{ update_status }}</p>
                    <div class="progress-bar" v-bind:style="{width: progress + '%'}"></div>
                    <a class="btn-restart" v-on:click="handleRestart" v-show="restartable">Restart Now</a>
                </div>
                <img draggable="false" class="btn-close" src="./images/fork.png" v-on:click="handleClosePanel" />
            </div>
        </div>
    `,
    mounted: function() {
        this.$root.$on('open-setting-panel', () => {
            this.visibility = true;
            setTimeout(() => {
                this.lazy_load = true;
            }, 10);
        });
        ipcRenderer.on('query-app-version-callback', (event, data) => {
            if(data['disconnect'] != undefined) {
                this.btn_update_visibility = false;
                this.version = data.local_version;
                this.need_update = true;
                return;
            }
            this.version = data.local_version;
            this.need_update = data.need_updat;
            if(data.need_update) {
                this.btn_update_visibility = true;
            }
        });
    },
    data: function() {
        return {
            visibility: false,
            lazy_load: false,
            version: 'Unknow',
            update_status: 'Preparing Update ...',
            is_update_success: false,
            btn_update_visibility: false,
            progress: 0,
            need_update: false,
            is_updating: false,
            restartable: false
        }
    },
    methods: {
        handleClosePanel: function() {
            this.lazy_load = false;
            setTimeout(() => {
                this.visibility = false;
            }, 250);
        },
        handleStopPropagetion: function(ev) {
            ev.preventDefault();
            ev.stopPropagation();
        },
        handleUpdateApp: function() {
            this.btn_update_visibility = false;
            this.is_updating = true;
            ipcRenderer.send('update-app', '');
            ipcRenderer.on('update-app-callback', (event, data) => {
                switch(data.status) {
                    case 'FAILED':
                        this.update_status = `Update Failed.Please retry.`;
                        this.btn_update_visibility = true;
                        this.is_updating = false;
                        break;
                    case 'FINISH':
                        this.update_status = `Update Successfully.`;
                        this.restartable = true;
                        break;
                    case 'DOWNLOADING':
                        this.update_status = `Downloading (${ parseFloat(data.progress * 100).toFixed(2) })`;
                        this.progress = data.progress * 100;
                        break;
                    default:
                        break;
                }
            });
        },
        handleRestart: function() {
            ipcRenderer.send('restart-app', '');
        }
    }
});

Vue.component('setting-panel', settingPanelComponent);

// 实例化Vue
var vm = new Vue({
    el: '#main'
});