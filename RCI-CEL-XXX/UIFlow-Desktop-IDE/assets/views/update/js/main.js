var ipcRenderer = require('electron').ipcRenderer;

var current_version = document.getElementById('current_version');
var latest_version = document.getElementById('latest_version');
var btn_check = document.getElementById('btn_check');
var btn_update = document.getElementById('btn_update');
var update_box = document.getElementById('update_box');
var text_update = document.getElementById('text_update');
var progress_bar = document.getElementById('progress_bar');

var TIP_PREPARE = 'Prepare download ...';
var TIP_DOWNLOADING = 'Downloading ...';
var TIP_SUCCESSFULLY = 'Download successfully.';
var TIP_FAILED = 'Download failed.';

ipcRenderer.send('query-uiflow-version', '');

ipcRenderer.on('query-uiflow-version-callback', function(event, data){
    current_version.innerText = data;
});

ipcRenderer.on('query-uiflow-latest-version-callback', function(event, data){
    btn_check.style.display = 'none';
    latest_version.style.display = 'inline';
    if(current_version.innerText != data && data != 'Unknow') {
        btn_update.style.display = 'inline';
    }
    latest_version.innerText = data;
});

ipcRenderer.on('update-uiflow-callback', function(event, data){
    switch(data.status) {
        case 'DOWNLOADING':
            text_update.innerText = TIP_DOWNLOADING;
            progress_bar.style.width = (data.progress * 100) + '%';
            var red = 255 * (1 - data.progress);
            var green = 255 * data.progress;
            progress_bar.style.backgroundColor = 'rgb(' + red + ', ' + green + ', 0)';
            break;
        case 'FINISH':
            text_update.innerText = TIP_SUCCESSFULLY;
            text_update.style.color = 'green';
            break;
        case 'FAILED':
            text_update.innerText = TIP_FAILED;
            text_update.style.color = 'red';
            btn_update.style.display = 'inline';
            break;
        default:
            text_update.innerText = TIP_FAILED;
            text_update.style.color = 'red';
            btn_update.style.display = 'inline';
            break;
    }
});

btn_check.onclick = function() {
    ipcRenderer.send('query-uiflow-latest-version', '');
}

btn_update.onclick = function() {
    btn_update.style.display = 'none';
    update_box.style.opacity = '1';
    text_update.innerText = TIP_PREPARE;
    progress_bar.style.width = '1%';
    progress_bar.style.backgroundColor = 'red';
    ipcRenderer.send('update-uiflow', '');
}