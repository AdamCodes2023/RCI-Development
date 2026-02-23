(function(){

    var ipcRenderer = require('electron').ipcRenderer;

    var cancelBtn = document.getElementById('btn_cancel');
    var skipBtn = document.getElementById('btn_skip');
    var installBtn = document.getElementById('btn_install');

    cancelBtn.addEventListener('click', function() {
        ipcRenderer.send('cancel-checker', '');
    });

    skipBtn.addEventListener('click', function() {
        ipcRenderer.send('skip-checker', '');
    });

    installBtn.addEventListener('click', function() {
        if(/x86_64|Win64|WOW64/.test(navigator.userAgent)) {
            ipcRenderer.send('install-checker', 64);
            return;
        }
        ipcRenderer.send('install-checker', 32);
    });

})();