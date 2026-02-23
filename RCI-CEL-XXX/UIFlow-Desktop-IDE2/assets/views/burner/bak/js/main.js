const ipcRenderer = require('electron').ipcRenderer;

var listFirmwareComponent = Vue.extend({
    template: `
    <div>
        <div class="search-bar">
            <input v-on:input="filter($event)" class="inputbox-search" spellcheck=false type="text" placeholder="Search..." />
            <img v-on:click="getFirmwareData" draggable="false" src="./images/refresh.png" />
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
            isLoading: true
        }
    },
    mounted: function() {
        this.getFirmwareData();
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
                }
            });
            ipcRenderer.send('firmware', '');
        },
        downloadFirmware: function(firmware) {
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
        }
    }
});

Vue.component('list-firmware', listFirmwareComponent);

var burnerFormComponent = Vue.extend({
    template: `
    <div>
        <form>
            <div class="form-input">
                <span>COM:</span>
                <select id="val_com" @mousedown="updateCOM">
                    <option v-for="c in com" v-bind:value="c">{{ c }}</option>
                </select>
            </div>
            <div class="form-input">
                <span>Baudrate:</span>
                <select id="val_baudrate">
                    <option value="921600">921600</option>
                    <option value="750000">750000</option>
                    <option value="512000">512000</option>
                    <option value="256000">256000</option>
                    <option value="230400">230400</option>
                    <option value="115200">115200</option>
                </select>
            </div>
            <div class="form-button">
                <button id="btn_burn" v-on:click="burn($event)">Burn</button>
                <button id="btn_erase" v-on:click="erase($event)">Erase</button>
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
            if(firmware == '' || val_com == '' || val_baudrate == '') {
                this.$root.$emit('add-message', 'Check your configuration.\n');
                return;
            }
            ipcRenderer.send('burn', {com: val_com, baudrate: val_baudrate, firmware: firmware.name, pk: firmware.pk});
        },
        erase: function($event) {
            $event.preventDefault();
            var val_com = document.getElementById('val_com').value;
            ipcRenderer.send('erase', {com: val_com});
        },
        updateCOM: function() {
            var com = ipcRenderer.sendSync('com', '');
            this.com = com;
        }
    },
    props: {
        com: []
    },
    mounted: function() {
        var com = ipcRenderer.sendSync('com', '');
        this.com = com;
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

// 实例化Vue
var vm = new Vue({
    el: '#main'
});