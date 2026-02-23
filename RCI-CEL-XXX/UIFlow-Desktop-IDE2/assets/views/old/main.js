(window["webpackJsonp"] = window["webpackJsonp"] || []).push([["main"],{

/***/ "./src/$$_lazy_route_resource lazy recursive":
/*!**********************************************************!*\
  !*** ./src/$$_lazy_route_resource lazy namespace object ***!
  \**********************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

function webpackEmptyAsyncContext(req) {
	// Here Promise.resolve().then() is used instead of new Promise() to prevent
	// uncaught exception popping up in devtools
	return Promise.resolve().then(function() {
		var e = new Error("Cannot find module '" + req + "'");
		e.code = 'MODULE_NOT_FOUND';
		throw e;
	});
}
webpackEmptyAsyncContext.keys = function() { return []; };
webpackEmptyAsyncContext.resolve = webpackEmptyAsyncContext;
module.exports = webpackEmptyAsyncContext;
webpackEmptyAsyncContext.id = "./src/$$_lazy_route_resource lazy recursive";

/***/ }),

/***/ "./src/app/animations/header.anim.ts":
/*!*******************************************!*\
  !*** ./src/app/animations/header.anim.ts ***!
  \*******************************************/
/*! exports provided: slideDownAnimation, alertAnimation, setting_docAnimation, setting_imgAnimation, videoAnimation */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "slideDownAnimation", function() { return slideDownAnimation; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "alertAnimation", function() { return alertAnimation; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "setting_docAnimation", function() { return setting_docAnimation; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "setting_imgAnimation", function() { return setting_imgAnimation; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "videoAnimation", function() { return videoAnimation; });
/* harmony import */ var _angular_animations__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/animations */ "./node_modules/@angular/animations/fesm5/animations.js");

// exemple下拉显示
var slideDownAnimation = Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["trigger"])('dropdownAnim', [
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["state"])('show', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["style"])({
        height: '*'
    })),
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["state"])('hide', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["style"])({
        height: 0
    })),
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["transition"])('show <=> hide', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["animate"])('.25s ease'))
]);
// blockly右侧显示弹窗
var alertAnimation = Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["trigger"])('alertAnim', [
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["state"])('show', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["style"])({
        width: '*',
        right: 0,
        opacity: 0.85,
        display: 'block'
    })),
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["state"])('hide', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["style"])({
        width: 0,
        right: -350,
        opacity: 0,
        display: ' none'
    })),
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["transition"])('show <=> hide', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["animate"])('.3s ease'))
]);
// setting doc显示隐藏
var setting_docAnimation = Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["trigger"])('settin_doc', [
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["state"])('show', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["style"])({
        height: '*'
    })),
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["state"])('hide', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["style"])({
        height: 0
    })),
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["transition"])('show <=> hide', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["animate"])('.25s ease'))
]);
// setting 图片旋转
var setting_imgAnimation = Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["trigger"])('settin_img', [
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["state"])('show', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["style"])({
        // height: '*'
        transform: 'rotate(0deg)'
    })),
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["state"])('hide', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["style"])({
        transform: 'rotate(-90deg)'
    })),
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["transition"])('show <=> hide', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["animate"])('.2s ease'))
]);
// 视频说明显示隐藏
var videoAnimation = Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["trigger"])('video_anima', [
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["state"])('show', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["style"])({
        height: '*'
    })),
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["state"])('hide', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["style"])({
        height: 0
    })),
    Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["transition"])('show <=> hide', Object(_angular_animations__WEBPACK_IMPORTED_MODULE_0__["animate"])('.25s ease'))
]);


/***/ }),

/***/ "./src/app/animations/index.ts":
/*!*************************************!*\
  !*** ./src/app/animations/index.ts ***!
  \*************************************/
/*! exports provided: slideDownAnimation, alertAnimation, setting_docAnimation, setting_imgAnimation, videoAnimation */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _header_anim__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./header.anim */ "./src/app/animations/header.anim.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "slideDownAnimation", function() { return _header_anim__WEBPACK_IMPORTED_MODULE_0__["slideDownAnimation"]; });

/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "alertAnimation", function() { return _header_anim__WEBPACK_IMPORTED_MODULE_0__["alertAnimation"]; });

/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "setting_docAnimation", function() { return _header_anim__WEBPACK_IMPORTED_MODULE_0__["setting_docAnimation"]; });

/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "setting_imgAnimation", function() { return _header_anim__WEBPACK_IMPORTED_MODULE_0__["setting_imgAnimation"]; });

/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "videoAnimation", function() { return _header_anim__WEBPACK_IMPORTED_MODULE_0__["videoAnimation"]; });




/***/ }),

/***/ "./src/app/app.component.html":
/*!************************************!*\
  !*** ./src/app/app.component.html ***!
  \************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div id=\"app\" class=\"app\" (mousedown)=\"stopPropagation($event)\" >\r\n  <header>\r\n    <app-header></app-header>\r\n  </header>\r\n  <main>\r\n    <app-workspace></app-workspace>\r\n  </main>\r\n  \r\n  <footer>\r\n    <app-footer></app-footer>\r\n  </footer>\r\n\r\n\r\n</div>\r\n<div class=\"orientation-show\" *ngIf=\"isPhone\">\r\n   <div class=\"phone-re\"></div>\r\n  </div>"

/***/ }),

/***/ "./src/app/app.component.scss":
/*!************************************!*\
  !*** ./src/app/app.component.scss ***!
  \************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".app {\n  -webkit-filter: blur(0px);\n          filter: blur(0px);\n  transition: all 0.35s ease; }\n  .app.blur {\n    -webkit-filter: blur(2px);\n            filter: blur(2px); }\n  main {\n  height: 100%;\n  overflow: hidden; }\n  app-workspace {\n  height: 100%; }\n  .orientation-show {\n  display: none;\n  position: fixed;\n  top: 0;\n  left: 0;\n  width: 100%;\n  height: 100%;\n  background-color: #000;\n  color: #fff;\n  text-align: center;\n  z-index: 100001; }\n  .orientation-show .phone-re {\n    width: 128px;\n    height: 128px;\n    position: fixed;\n    top: 50%;\n    left: 50%;\n    -webkit-transform: translate(-50%, -50%);\n            transform: translate(-50%, -50%);\n    background-size: 128px 128px;\n    background-image: url('phone-re.png');\n    -webkit-animation: retote 2s infinite;\n            animation: retote 2s infinite; }\n  @media all and (orientation: portrait) {\n  .orientation-show {\n    display: block; } }\n  @-webkit-keyframes retote {\n  from {\n    -webkit-transform: translate(-50%, -50%) rotate(0deg);\n            transform: translate(-50%, -50%) rotate(0deg); }\n  to {\n    -webkit-transform: translate(-50%, -50%) rotate(90deg);\n            transform: translate(-50%, -50%) rotate(90deg); } }\n  @keyframes retote {\n  from {\n    -webkit-transform: translate(-50%, -50%) rotate(0deg);\n            transform: translate(-50%, -50%) rotate(0deg); }\n  to {\n    -webkit-transform: translate(-50%, -50%) rotate(90deg);\n            transform: translate(-50%, -50%) rotate(90deg); } }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvWjpcXHdvcmtzcGFjZVxcbXlfenJlbmRlclxcZmxvdy9zcmNcXGFwcFxcYXBwLmNvbXBvbmVudC5zY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUFBO0VBQ0ksMEJBQWlCO1VBQWpCLGtCQUFpQjtFQUNqQiwyQkFBMEIsRUFLN0I7RUFQRDtJQUtRLDBCQUFpQjtZQUFqQixrQkFBaUIsRUFDcEI7RUFFTDtFQUVJLGFBQVk7RUFDWixpQkFBZ0IsRUFDbkI7RUFDRDtFQUNJLGFBQVksRUFDZjtFQUVEO0VBQ0ksY0FBYTtFQUNiLGdCQUFlO0VBQ2YsT0FBTTtFQUNOLFFBQU87RUFDUCxZQUFXO0VBQ1gsYUFBWTtFQUNaLHVCQUFzQjtFQUN0QixZQUFXO0VBQ1gsbUJBQWtCO0VBQ2xCLGdCQUFlLEVBWWxCO0VBdEJEO0lBWVEsYUFBWTtJQUNaLGNBQWE7SUFDYixnQkFBZTtJQUNmLFNBQVE7SUFDUixVQUFTO0lBQ1QseUNBQWdDO1lBQWhDLGlDQUFnQztJQUNoQyw2QkFBNEI7SUFDNUIsc0NBQXNEO0lBQ3RELHNDQUE2QjtZQUE3Qiw4QkFBNkIsRUFDaEM7RUFHTDtFQUNJO0lBQ0ksZUFBYyxFQUNqQixFQUFBO0VBR0w7RUFDSTtJQUNJLHNEQUE2QztZQUE3Qyw4Q0FBNkMsRUFBQTtFQUVqRDtJQUNJLHVEQUE4QztZQUE5QywrQ0FBOEMsRUFBQSxFQUFBO0VBTHREO0VBQ0k7SUFDSSxzREFBNkM7WUFBN0MsOENBQTZDLEVBQUE7RUFFakQ7SUFDSSx1REFBOEM7WUFBOUMsK0NBQThDLEVBQUEsRUFBQSIsImZpbGUiOiJzcmMvYXBwL2FwcC5jb21wb25lbnQuc2NzcyIsInNvdXJjZXNDb250ZW50IjpbIi5hcHAge1xyXG4gICAgZmlsdGVyOiBibHVyKDBweCk7XHJcbiAgICB0cmFuc2l0aW9uOiBhbGwgMC4zNXMgZWFzZTtcclxuXHJcbiAgICAmLmJsdXIge1xyXG4gICAgICAgIGZpbHRlcjogYmx1cigycHgpO1xyXG4gICAgfVxyXG59XHJcbm1haW4ge1xyXG4gICAgLy8gaGVpZ2h0OiBjYWxjKDEwMHZoIC0gMzBweCk7XHJcbiAgICBoZWlnaHQ6IDEwMCU7XHJcbiAgICBvdmVyZmxvdzogaGlkZGVuO1xyXG59XHJcbmFwcC13b3Jrc3BhY2Uge1xyXG4gICAgaGVpZ2h0OiAxMDAlO1xyXG59XHJcblxyXG4ub3JpZW50YXRpb24tc2hvdyB7XHJcbiAgICBkaXNwbGF5OiBub25lO1xyXG4gICAgcG9zaXRpb246IGZpeGVkO1xyXG4gICAgdG9wOiAwO1xyXG4gICAgbGVmdDogMDtcclxuICAgIHdpZHRoOiAxMDAlO1xyXG4gICAgaGVpZ2h0OiAxMDAlO1xyXG4gICAgYmFja2dyb3VuZC1jb2xvcjogIzAwMDtcclxuICAgIGNvbG9yOiAjZmZmO1xyXG4gICAgdGV4dC1hbGlnbjogY2VudGVyO1xyXG4gICAgei1pbmRleDogMTAwMDAxO1xyXG4gICAgLnBob25lLXJlIHtcclxuICAgICAgICB3aWR0aDogMTI4cHg7XHJcbiAgICAgICAgaGVpZ2h0OiAxMjhweDtcclxuICAgICAgICBwb3NpdGlvbjogZml4ZWQ7XHJcbiAgICAgICAgdG9wOiA1MCU7XHJcbiAgICAgICAgbGVmdDogNTAlO1xyXG4gICAgICAgIHRyYW5zZm9ybTogdHJhbnNsYXRlKC01MCUsIC01MCUpO1xyXG4gICAgICAgIGJhY2tncm91bmQtc2l6ZTogMTI4cHggMTI4cHg7XHJcbiAgICAgICAgYmFja2dyb3VuZC1pbWFnZTogdXJsKCcuLi9hc3NldHMvaW1hZ2VzL3Bob25lLXJlLnBuZycpO1xyXG4gICAgICAgIGFuaW1hdGlvbjogcmV0b3RlIDJzIGluZmluaXRlO1xyXG4gICAgfVxyXG59XHJcblxyXG5AbWVkaWEgYWxsIGFuZCAob3JpZW50YXRpb24gOiBwb3J0cmFpdCl7XHJcbiAgICAub3JpZW50YXRpb24tc2hvdyB7XHJcbiAgICAgICAgZGlzcGxheTogYmxvY2s7XHJcbiAgICB9XHJcbn1cclxuXHJcbkBrZXlmcmFtZXMgcmV0b3Rle1xyXG4gICAgZnJvbXtcclxuICAgICAgICB0cmFuc2Zvcm06IHRyYW5zbGF0ZSgtNTAlLCAtNTAlKSByb3RhdGUoMGRlZyk7XHJcbiAgICB9XHJcbiAgICB0b3tcclxuICAgICAgICB0cmFuc2Zvcm06IHRyYW5zbGF0ZSgtNTAlLCAtNTAlKSByb3RhdGUoOTBkZWcpO1xyXG4gICAgfVxyXG59Il19 */"

/***/ }),

/***/ "./src/app/app.component.ts":
/*!**********************************!*\
  !*** ./src/app/app.component.ts ***!
  \**********************************/
/*! exports provided: AppComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "AppComponent", function() { return AppComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _services_services_module__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ./services/services.module */ "./src/app/services/services.module.ts");
/* harmony import */ var _ngx_translate_core__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @ngx-translate/core */ "./node_modules/@ngx-translate/core/fesm5/ngx-translate-core.js");
/* harmony import */ var _services_zrender_helper_service__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./services/zrender-helper.service */ "./src/app/services/zrender-helper.service.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};




var AppComponent = /** @class */ (function () {
    function AppComponent(globalOperatorSrv, uploadSrv, storeSrv, translate, zrenderWorkspace) {
        this.globalOperatorSrv = globalOperatorSrv;
        this.uploadSrv = uploadSrv;
        this.storeSrv = storeSrv;
        this.translate = translate;
        this.zrenderWorkspace = zrenderWorkspace;
        this.isPhone = false;
        var language = localStorage.getItem('mui_language') || 'en';
        translate.setDefaultLang('en');
        translate.use(language);
    }
    AppComponent.prototype.ngOnInit = function () {
        window['remoteURL'] = 'http://flow-remote.m5stack.com/';
        window['startClientWidth'] = document.body.clientWidth;
        window.onorientationchange = function (ev) {
            window['UIEditor'].resize();
            window['zrenderWorkspace'].redrawSvg();
        };
        window.onresize = function (ev) {
            // window['zrenderWorkspace'].redrawSvg();
            if (window['startClientWidth'] <= 1400 && document.body.clientWidth > 1400) {
                window['UIEditor'].resize();
            }
            else if (window['startClientWidth'] > 1400 && document.body.clientWidth <= 1400) {
                window['UIEditor'].resize();
            }
            window['startClientWidth'] = document.body.clientWidth;
        };
        // if (environment.production) {
        //   window.onbeforeunload = function (e) {
        //     var e = window.event || e;
        //     e.returnValue = ("Do you sure close this page?");
        //   }
        // }
        // this.uploadSrv.getDeviceInfo().subscribe(res => {      
        //   this.translate.get('EXECUTECODE_ERROR').subscribe((res: string) => {
        //     this.globalOperatorSrv.createMessageBox().instance.error(res);
        //   });
        //   try {
        //     if (res.data[0] !== this.storeSrv.VERSION) {
        //       this.translate.get('FIRMWARE_WARNING', {value: this.storeSrv.VERSION }).subscribe((res: string) => {
        //         this.globalOperatorSrv.createMessageBox().instance.warning(res);
        //       });
        //     }
        //   } catch (error) {
        //     console.log(error);
        //   }
        // }, err => {
        //   // this.translate.get('EXECUTECODE_ERROR').subscribe((res: string) => {
        //   //   this.globalOperatorSrv.createMessageBox().instance.error(res);
        //   // });
        // });
        if (/Android|webOS|iPad|iPhone|iPod|BlackBerry/i.test(navigator.userAgent)) {
            this.isPhone = true;
        }
        // 设置主题
        if (document.documentElement.hasAttribute('theme')) {
            document.documentElement.removeAttribute('theme');
        }
        document.documentElement.setAttribute('theme', localStorage.getItem('theme'));
    };
    AppComponent.prototype.stopPropagation = function (ev) {
        if (/Android|webOS|iPad|iPhone|iPod|BlackBerry/i.test(navigator.userAgent)) {
        }
        else {
            this.globalOperatorSrv.setSelectedComponent(null);
            this.globalOperatorSrv.setSelectedUnit(null);
        }
    };
    AppComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-root',
            template: __webpack_require__(/*! ./app.component.html */ "./src/app/app.component.html"),
            styles: [__webpack_require__(/*! ./app.component.scss */ "./src/app/app.component.scss")]
        }),
        __metadata("design:paramtypes", [_services_services_module__WEBPACK_IMPORTED_MODULE_1__["GlobalOperatorService"], _services_services_module__WEBPACK_IMPORTED_MODULE_1__["UploadService"],
            _services_services_module__WEBPACK_IMPORTED_MODULE_1__["StoreService"], _ngx_translate_core__WEBPACK_IMPORTED_MODULE_2__["TranslateService"], _services_zrender_helper_service__WEBPACK_IMPORTED_MODULE_3__["ZrenderHelperService"]])
    ], AppComponent);
    return AppComponent;
}());



/***/ }),

/***/ "./src/app/app.module.ts":
/*!*******************************!*\
  !*** ./src/app/app.module.ts ***!
  \*******************************/
/*! exports provided: createTranslateLoader, AppModule */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "createTranslateLoader", function() { return createTranslateLoader; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "AppModule", function() { return AppModule; });
/* harmony import */ var _angular_platform_browser__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/platform-browser */ "./node_modules/@angular/platform-browser/fesm5/platform-browser.js");
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _shared_shared_module__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./shared/shared.module */ "./src/app/shared/shared.module.ts");
/* harmony import */ var _core_core_module__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./core/core.module */ "./src/app/core/core.module.ts");
/* harmony import */ var _workspace_workspace_module__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ./workspace/workspace.module */ "./src/app/workspace/workspace.module.ts");
/* harmony import */ var _services_services_module__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ./services/services.module */ "./src/app/services/services.module.ts");
/* harmony import */ var _app_component__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./app.component */ "./src/app/app.component.ts");
/* harmony import */ var _ngx_translate_core__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! @ngx-translate/core */ "./node_modules/@ngx-translate/core/fesm5/ngx-translate-core.js");
/* harmony import */ var _angular_common_http__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! @angular/common/http */ "./node_modules/@angular/common/fesm5/http.js");
/* harmony import */ var _ngx_translate_http_loader__WEBPACK_IMPORTED_MODULE_9__ = __webpack_require__(/*! @ngx-translate/http-loader */ "./node_modules/@ngx-translate/http-loader/esm5/ngx-translate-http-loader.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};










// 支持AOT
function createTranslateLoader(http) {
    return new _ngx_translate_http_loader__WEBPACK_IMPORTED_MODULE_9__["TranslateHttpLoader"](http, './assets/blockly/language/', '.json');
}
var AppModule = /** @class */ (function () {
    function AppModule() {
        localStorage.removeItem('mui_apikey');
    }
    AppModule = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_1__["NgModule"])({
            declarations: [
                _app_component__WEBPACK_IMPORTED_MODULE_6__["AppComponent"],
            ],
            imports: [
                _angular_platform_browser__WEBPACK_IMPORTED_MODULE_0__["BrowserModule"],
                _shared_shared_module__WEBPACK_IMPORTED_MODULE_2__["SharedModule"],
                _services_services_module__WEBPACK_IMPORTED_MODULE_5__["ServicesModule"].forRoot(),
                _core_core_module__WEBPACK_IMPORTED_MODULE_3__["CoreModule"],
                _workspace_workspace_module__WEBPACK_IMPORTED_MODULE_4__["WorkspaceModule"],
                _ngx_translate_core__WEBPACK_IMPORTED_MODULE_7__["TranslateModule"].forRoot({
                    loader: {
                        provide: _ngx_translate_core__WEBPACK_IMPORTED_MODULE_7__["TranslateLoader"],
                        useFactory: createTranslateLoader,
                        deps: [_angular_common_http__WEBPACK_IMPORTED_MODULE_8__["HttpClient"]]
                    }
                })
            ],
            providers: [],
            bootstrap: [_app_component__WEBPACK_IMPORTED_MODULE_6__["AppComponent"]]
        }),
        __metadata("design:paramtypes", [])
    ], AppModule);
    return AppModule;
}());



/***/ }),

/***/ "./src/app/core/core.module.ts":
/*!*************************************!*\
  !*** ./src/app/core/core.module.ts ***!
  \*************************************/
/*! exports provided: CoreModule */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "CoreModule", function() { return CoreModule; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _shared_shared_module__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../shared/shared.module */ "./src/app/shared/shared.module.ts");
/* harmony import */ var angularx_qrcode__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! angularx-qrcode */ "./node_modules/angularx-qrcode/dist/index.js");
/* harmony import */ var _header_header_component__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./header/header.component */ "./src/app/core/header/header.component.ts");
/* harmony import */ var _footer_footer_component__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ./footer/footer.component */ "./src/app/core/footer/footer.component.ts");
/* harmony import */ var _updata_updata__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ./updata/updata */ "./src/app/core/updata/updata.ts");
/* harmony import */ var _setting_panel_setting_panel_component__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./setting-panel/setting-panel.component */ "./src/app/core/setting-panel/setting-panel.component.ts");
/* harmony import */ var _resource_manager_resource_manager_component__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ./resource-manager/resource-manager.component */ "./src/app/core/resource-manager/resource-manager.component.ts");
/* harmony import */ var _message_message__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! ./message/message */ "./src/app/core/message/message.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};









var CoreModule = /** @class */ (function () {
    function CoreModule() {
    }
    CoreModule = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["NgModule"])({
            imports: [_shared_shared_module__WEBPACK_IMPORTED_MODULE_1__["SharedModule"], angularx_qrcode__WEBPACK_IMPORTED_MODULE_2__["QRCodeModule"]],
            declarations: [_message_message__WEBPACK_IMPORTED_MODULE_8__["Message"], _header_header_component__WEBPACK_IMPORTED_MODULE_3__["HeaderComponent"], _footer_footer_component__WEBPACK_IMPORTED_MODULE_4__["FooterComponent"], _updata_updata__WEBPACK_IMPORTED_MODULE_5__["UpdataComponent"], _setting_panel_setting_panel_component__WEBPACK_IMPORTED_MODULE_6__["SettingPanelComponent"], _resource_manager_resource_manager_component__WEBPACK_IMPORTED_MODULE_7__["ResourceManagerComponent"]],
            exports: [_header_header_component__WEBPACK_IMPORTED_MODULE_3__["HeaderComponent"], _footer_footer_component__WEBPACK_IMPORTED_MODULE_4__["FooterComponent"]],
            entryComponents: [_setting_panel_setting_panel_component__WEBPACK_IMPORTED_MODULE_6__["SettingPanelComponent"], _resource_manager_resource_manager_component__WEBPACK_IMPORTED_MODULE_7__["ResourceManagerComponent"], _updata_updata__WEBPACK_IMPORTED_MODULE_5__["UpdataComponent"]]
        })
    ], CoreModule);
    return CoreModule;
}());



/***/ }),

/***/ "./src/app/core/footer/footer.component.html":
/*!***************************************************!*\
  !*** ./src/app/core/footer/footer.component.html ***!
  \***************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"wrapper\">\r\n  <span class=\"txt--info\" (click)=\"openSettingPanel()\">\r\n    <!-- <span class=\"txt--key\">{{ \"API_KEY\" | translate}}</span> -->\r\n    <span class=\"txt--key\">{{ 'COM:' }}</span>\r\n    <img src=\"../../../assets/images/key.png\" alt=\"Key\">\r\n    <span class=\"txt--key\">{{ (apikey$ | async) || 'Unknow' }}</span>\r\n  </span>\r\n  <span class=\"tips--info\">\r\n    <!-- <span *ngIf=\"storeSrv.connectStatus === 'DISCONNECTED'\"> -->\r\n    <span *ngIf=\"storeSrv.connectStatus === 'DISCONNECTED'\">\r\n      <span class=\"txt--bracket\">[ <span class=\"status status--disconnected\">{{ storeSrv.connectStatus | translate}}</span> ]</span>\r\n    </span>\r\n    <span *ngIf=\"storeSrv.connectStatus === 'CONNECTED'\">\r\n      <span class=\"txt--bracket\">[ <span class=\"status status--connected\">{{ storeSrv.connectStatus | translate}}</span> ]</span>\r\n      <span class=\"txt--version\">{{ 'VERSION' | translate }} {{ (storeSrv.deviceInfo | async)?.version }}</span>\r\n    </span>\r\n    <!-- <span *ngIf=\"storeSrv.connectStatus === 'CONNECTING'\">\r\n      <span class=\"txt--bracket\">[ <span class=\"status status--connecting\">{{ storeSrv.connectStatus | translate}}</span> ]</span>\r\n    </span> -->\r\n  </span>\r\n  <!-- <span class=\"btn--refresh\" (click)=\"refreshStatus()\">\r\n    <img src=\"../../../assets/images/loop.png\" alt=\"Refresh\">\r\n  </span> -->\r\n  <span *ngIf=\"(mode$ | async) === 'code'\" class=\"btn--codelock\" (click)=\"toggleCodeLock()\">\r\n    <img *ngIf=\"(codeLock$ | async)\" src=\"../../../assets/images/lock.png\" alt=\"lock\">\r\n    <img *ngIf=\"!(codeLock$ | async)\" src=\"../../../assets/images/unlock.png\" alt=\"lock\">\r\n    <span class=\"txt--lock\">{{ 'CodeLock :' }}</span>\r\n    <span class=\"txt--lock\">{{ (codeLock$ | async) ? 'ON' : 'OFF' }}</span>\r\n  </span>\r\n</div>\r\n"

/***/ }),

/***/ "./src/app/core/footer/footer.component.scss":
/*!***************************************************!*\
  !*** ./src/app/core/footer/footer.component.scss ***!
  \***************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper {\n  height: 20px;\n  background-color: var(--bg-color);\n  padding-left: 10px;\n  overflow: hidden; }\n\n.txt--info {\n  display: block;\n  float: left;\n  height: 20px;\n  transition: all .25s ease;\n  text-align: center;\n  cursor: pointer;\n  padding: 0 10px; }\n\n.txt--info:hover {\n    background-color: rgba(233, 233, 233, 0.3); }\n\n.txt--info img {\n    height: 16px;\n    margin: 2px 0; }\n\n.txt--info .txt--key {\n    font-size: 12px;\n    color: #FFF;\n    vertical-align: 35%;\n    margin-left: 6px;\n    -webkit-user-select: none;\n       -moz-user-select: none;\n        -ms-user-select: none;\n            user-select: none;\n    font-family: Arial; }\n\n.tips--info {\n  display: block;\n  float: left;\n  padding: 0 4px;\n  -webkit-user-select: none;\n     -moz-user-select: none;\n      -ms-user-select: none;\n          user-select: none;\n  line-height: 20px; }\n\n.tips--info .txt--bracket {\n    color: #FFF; }\n\n.tips--info .txt--version {\n    font-size: 14px;\n    font-family: Arial;\n    color: white;\n    padding-left: 6px; }\n\n.tips--info .status {\n    font-family: Arial;\n    font-size: 12px;\n    font-weight: bolder; }\n\n.tips--info .status.status--disconnected {\n      color: #fe4365; }\n\n.tips--info .status.status--connected {\n      color: #75D701; }\n\n.tips--info .status.status--connecting {\n      color: #f9c00c; }\n\n.btn--refresh {\n  display: block;\n  float: left;\n  transition: all .25s ease;\n  text-align: center;\n  cursor: pointer;\n  padding: 0 4px; }\n\n.btn--refresh:hover {\n    background-color: rgba(233, 233, 233, 0.3); }\n\n.btn--refresh img {\n    height: 16px;\n    margin: 2px 0; }\n\n.btn--codelock {\n  float: right;\n  padding: 0 12px;\n  margin-right: 40px;\n  cursor: pointer;\n  text-align: left;\n  transition: all .25s ease; }\n\n.btn--codelock:hover {\n    background-color: rgba(233, 233, 233, 0.3); }\n\n.btn--codelock img {\n    height: 16px;\n    margin: 2px 0; }\n\n.btn--codelock .txt--lock {\n    font-size: 12px;\n    color: #FFF;\n    vertical-align: 35%;\n    margin-left: 6px;\n    -webkit-user-select: none;\n       -moz-user-select: none;\n        -ms-user-select: none;\n            user-select: none;\n    font-family: Arial; }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvY29yZS9mb290ZXIvWjpcXHdvcmtzcGFjZVxcbXlfenJlbmRlclxcZmxvdy9zcmNcXGFwcFxcY29yZVxcZm9vdGVyXFxmb290ZXIuY29tcG9uZW50LnNjc3MiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IkFBR0E7RUFDSSxhQUpTO0VBS1Qsa0NBSnFCO0VBS3JCLG1CQUFrQjtFQUNsQixpQkFBZ0IsRUFDbkI7O0FBRUQ7RUFDSSxlQUFjO0VBQ2QsWUFBVztFQUNYLGFBYlM7RUFjVCwwQkFBeUI7RUFDekIsbUJBQWtCO0VBQ2xCLGdCQUFlO0VBQ2YsZ0JBQWUsRUFrQmxCOztBQXpCRDtJQVVRLDJDQUEwQyxFQUM3Qzs7QUFYTDtJQWNRLGFBQVk7SUFDWixjQUFhLEVBQ2hCOztBQWhCTDtJQWtCUSxnQkFBZTtJQUNmLFlBQVc7SUFDWCxvQkFBbUI7SUFDbkIsaUJBQWdCO0lBQ2hCLDBCQUFpQjtPQUFqQix1QkFBaUI7UUFBakIsc0JBQWlCO1lBQWpCLGtCQUFpQjtJQUNqQixtQkFBa0IsRUFDckI7O0FBR0w7RUFDSSxlQUFjO0VBQ2QsWUFBVztFQUNYLGVBQWM7RUFDZCwwQkFBaUI7S0FBakIsdUJBQWlCO01BQWpCLHNCQUFpQjtVQUFqQixrQkFBaUI7RUFDakIsa0JBMUNTLEVBZ0VaOztBQTNCRDtJQVFRLFlBQVcsRUFDZDs7QUFUTDtJQVlRLGdCQUFlO0lBQ2YsbUJBQWtCO0lBQ2xCLGFBQVk7SUFDWixrQkFBaUIsRUFDcEI7O0FBaEJMO0lBbUJRLG1CQUFrQjtJQUNsQixnQkFBZTtJQUNmLG9CQUFtQixFQUt0Qjs7QUExQkw7TUF1QmlDLGVBQWMsRUFBSTs7QUF2Qm5EO01Bd0I4QixlQUFjLEVBQUk7O0FBeEJoRDtNQXlCK0IsZUFBYyxFQUFJOztBQUlqRDtFQUNJLGVBQWM7RUFDZCxZQUFXO0VBQ1gsMEJBQXlCO0VBQ3pCLG1CQUFrQjtFQUNsQixnQkFBZTtFQUNmLGVBQWMsRUFVakI7O0FBaEJEO0lBU1EsMkNBQTBDLEVBQzdDOztBQVZMO0lBYVEsYUFBWTtJQUNaLGNBQWEsRUFDaEI7O0FBR0w7RUFDSSxhQUFZO0VBQ1osZ0JBQWU7RUFDZixtQkFBa0I7RUFDbEIsZ0JBQWU7RUFDZixpQkFBZ0I7RUFDaEIsMEJBQXlCLEVBbUI1Qjs7QUF6QkQ7SUFTUSwyQ0FBMEMsRUFDN0M7O0FBVkw7SUFhUSxhQUFZO0lBQ1osY0FBYSxFQUNoQjs7QUFmTDtJQWtCUSxnQkFBZTtJQUNmLFlBQVc7SUFDWCxvQkFBbUI7SUFDbkIsaUJBQWdCO0lBQ2hCLDBCQUFpQjtPQUFqQix1QkFBaUI7UUFBakIsc0JBQWlCO1lBQWpCLGtCQUFpQjtJQUNqQixtQkFBa0IsRUFDckIiLCJmaWxlIjoic3JjL2FwcC9jb3JlL2Zvb3Rlci9mb290ZXIuY29tcG9uZW50LnNjc3MiLCJzb3VyY2VzQ29udGVudCI6WyIkaGVpZ2h0OiAyMHB4O1xyXG4kYmdDb2xvcjogdmFyKC0tYmctY29sb3IpO1xyXG5cclxuLndyYXBwZXIge1xyXG4gICAgaGVpZ2h0OiAkaGVpZ2h0O1xyXG4gICAgYmFja2dyb3VuZC1jb2xvcjogJGJnQ29sb3I7XHJcbiAgICBwYWRkaW5nLWxlZnQ6IDEwcHg7XHJcbiAgICBvdmVyZmxvdzogaGlkZGVuO1xyXG59XHJcblxyXG4udHh0LS1pbmZvIHtcclxuICAgIGRpc3BsYXk6IGJsb2NrO1xyXG4gICAgZmxvYXQ6IGxlZnQ7XHJcbiAgICBoZWlnaHQ6ICRoZWlnaHQ7XHJcbiAgICB0cmFuc2l0aW9uOiBhbGwgLjI1cyBlYXNlO1xyXG4gICAgdGV4dC1hbGlnbjogY2VudGVyO1xyXG4gICAgY3Vyc29yOiBwb2ludGVyO1xyXG4gICAgcGFkZGluZzogMCAxMHB4O1xyXG5cclxuICAgICY6aG92ZXIge1xyXG4gICAgICAgIGJhY2tncm91bmQtY29sb3I6IHJnYmEoMjMzLCAyMzMsIDIzMywgMC4zKTtcclxuICAgIH1cclxuXHJcbiAgICBpbWcge1xyXG4gICAgICAgIGhlaWdodDogMTZweDtcclxuICAgICAgICBtYXJnaW46IDJweCAwO1xyXG4gICAgfVxyXG4gICAgLnR4dC0ta2V5IHtcclxuICAgICAgICBmb250LXNpemU6IDEycHg7XHJcbiAgICAgICAgY29sb3I6ICNGRkY7XHJcbiAgICAgICAgdmVydGljYWwtYWxpZ246IDM1JTtcclxuICAgICAgICBtYXJnaW4tbGVmdDogNnB4O1xyXG4gICAgICAgIHVzZXItc2VsZWN0OiBub25lO1xyXG4gICAgICAgIGZvbnQtZmFtaWx5OiBBcmlhbDtcclxuICAgIH1cclxufVxyXG5cclxuLnRpcHMtLWluZm8ge1xyXG4gICAgZGlzcGxheTogYmxvY2s7XHJcbiAgICBmbG9hdDogbGVmdDtcclxuICAgIHBhZGRpbmc6IDAgNHB4O1xyXG4gICAgdXNlci1zZWxlY3Q6IG5vbmU7XHJcbiAgICBsaW5lLWhlaWdodDogJGhlaWdodDtcclxuXHJcbiAgICAudHh0LS1icmFja2V0IHtcclxuICAgICAgICBjb2xvcjogI0ZGRjtcclxuICAgIH1cclxuXHJcbiAgICAudHh0LS12ZXJzaW9uIHtcclxuICAgICAgICBmb250LXNpemU6IDE0cHg7XHJcbiAgICAgICAgZm9udC1mYW1pbHk6IEFyaWFsO1xyXG4gICAgICAgIGNvbG9yOiB3aGl0ZTtcclxuICAgICAgICBwYWRkaW5nLWxlZnQ6IDZweDtcclxuICAgIH1cclxuXHJcbiAgICAuc3RhdHVzIHtcclxuICAgICAgICBmb250LWZhbWlseTogQXJpYWw7XHJcbiAgICAgICAgZm9udC1zaXplOiAxMnB4O1xyXG4gICAgICAgIGZvbnQtd2VpZ2h0OiBib2xkZXI7XHJcblxyXG4gICAgICAgICYuc3RhdHVzLS1kaXNjb25uZWN0ZWQgeyBjb2xvcjogI2ZlNDM2NTsgfVxyXG4gICAgICAgICYuc3RhdHVzLS1jb25uZWN0ZWQgeyBjb2xvcjogIzc1RDcwMTsgfVxyXG4gICAgICAgICYuc3RhdHVzLS1jb25uZWN0aW5nIHsgY29sb3I6ICNmOWMwMGM7IH1cclxuICAgIH1cclxufVxyXG5cclxuLmJ0bi0tcmVmcmVzaCB7XHJcbiAgICBkaXNwbGF5OiBibG9jaztcclxuICAgIGZsb2F0OiBsZWZ0O1xyXG4gICAgdHJhbnNpdGlvbjogYWxsIC4yNXMgZWFzZTtcclxuICAgIHRleHQtYWxpZ246IGNlbnRlcjtcclxuICAgIGN1cnNvcjogcG9pbnRlcjtcclxuICAgIHBhZGRpbmc6IDAgNHB4O1xyXG5cclxuICAgICY6aG92ZXIge1xyXG4gICAgICAgIGJhY2tncm91bmQtY29sb3I6IHJnYmEoMjMzLCAyMzMsIDIzMywgMC4zKTtcclxuICAgIH1cclxuXHJcbiAgICBpbWcge1xyXG4gICAgICAgIGhlaWdodDogMTZweDtcclxuICAgICAgICBtYXJnaW46IDJweCAwO1xyXG4gICAgfVxyXG59XHJcblxyXG4uYnRuLS1jb2RlbG9jayB7XHJcbiAgICBmbG9hdDogcmlnaHQ7XHJcbiAgICBwYWRkaW5nOiAwIDEycHg7XHJcbiAgICBtYXJnaW4tcmlnaHQ6IDQwcHg7XHJcbiAgICBjdXJzb3I6IHBvaW50ZXI7XHJcbiAgICB0ZXh0LWFsaWduOiBsZWZ0O1xyXG4gICAgdHJhbnNpdGlvbjogYWxsIC4yNXMgZWFzZTtcclxuXHJcbiAgICAmOmhvdmVyIHtcclxuICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiByZ2JhKDIzMywgMjMzLCAyMzMsIDAuMyk7XHJcbiAgICB9XHJcblxyXG4gICAgaW1nIHtcclxuICAgICAgICBoZWlnaHQ6IDE2cHg7XHJcbiAgICAgICAgbWFyZ2luOiAycHggMDtcclxuICAgIH1cclxuXHJcbiAgICAudHh0LS1sb2NrIHtcclxuICAgICAgICBmb250LXNpemU6IDEycHg7XHJcbiAgICAgICAgY29sb3I6ICNGRkY7XHJcbiAgICAgICAgdmVydGljYWwtYWxpZ246IDM1JTtcclxuICAgICAgICBtYXJnaW4tbGVmdDogNnB4O1xyXG4gICAgICAgIHVzZXItc2VsZWN0OiBub25lO1xyXG4gICAgICAgIGZvbnQtZmFtaWx5OiBBcmlhbDtcclxuICAgIH1cclxufSJdfQ== */"

/***/ }),

/***/ "./src/app/core/footer/footer.component.ts":
/*!*************************************************!*\
  !*** ./src/app/core/footer/footer.component.ts ***!
  \*************************************************/
/*! exports provided: FooterComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "FooterComponent", function() { return FooterComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _services_services_module__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../../services/services.module */ "./src/app/services/services.module.ts");
/* harmony import */ var src_app_shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! src/app/shared/mask/mask.component */ "./src/app/shared/mask/mask.component.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
/* harmony import */ var _ngx_translate_core__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @ngx-translate/core */ "./node_modules/@ngx-translate/core/fesm5/ngx-translate-core.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};





var FooterComponent = /** @class */ (function () {
    function FooterComponent(uploadSrv, globalOperatorSrv, codeEditorSrv, storeSrv, translate) {
        this.uploadSrv = uploadSrv;
        this.globalOperatorSrv = globalOperatorSrv;
        this.codeEditorSrv = codeEditorSrv;
        this.storeSrv = storeSrv;
        this.translate = translate;
    }
    FooterComponent.prototype.ngOnInit = function () {
        this.codeLock$ = this.globalOperatorSrv.getCodeLock();
        this.mode$ = this.globalOperatorSrv.getMode();
        this.apikey$ = this.storeSrv.getApikey();
    };
    FooterComponent.prototype.refreshStatus = function () {
        var _this = this;
        this.uploadSrv.getDeviceInfo().subscribe(function (res) {
            if (res.code === 3)
                return;
            if (res.data[0] !== _this.storeSrv.VERSION) {
                _this.translate.get('FIRMWARE_WARNING', { value: _this.storeSrv.VERSION }).subscribe(function (res) {
                    _this.globalOperatorSrv.createMessageBox().instance.warning(res);
                });
            }
        }, function (err) {
            _this.translate.get('EXECUTECODE_ERROR').subscribe(function (res) {
                _this.globalOperatorSrv.createMessageBox().instance.error(res);
            });
        });
    };
    // 右下刷新
    FooterComponent.prototype.toggleCodeLock = function () {
        this.globalOperatorSrv.setCodeLock(!this.globalOperatorSrv.codeLock.value);
        if (!this.globalOperatorSrv.codeLock.value) {
            this.codeEditorSrv.updateWorkspaceValue();
        }
    };
    // 打开设置模态框
    FooterComponent.prototype.openSettingPanel = function () {
        var modal = this.globalOperatorSrv.createMaskModal(src_app_shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_2__["MaskComponent"]);
        modal.instance.createDynamicComponent(src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_3__["DYNAMIC_COMPONENT_TYPE"].SETTING_PANEL);
    };
    FooterComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-footer',
            template: __webpack_require__(/*! ./footer.component.html */ "./src/app/core/footer/footer.component.html"),
            styles: [__webpack_require__(/*! ./footer.component.scss */ "./src/app/core/footer/footer.component.scss")]
        }),
        __metadata("design:paramtypes", [_services_services_module__WEBPACK_IMPORTED_MODULE_1__["UploadService"],
            _services_services_module__WEBPACK_IMPORTED_MODULE_1__["GlobalOperatorService"],
            _services_services_module__WEBPACK_IMPORTED_MODULE_1__["CodeEditorService"],
            _services_services_module__WEBPACK_IMPORTED_MODULE_1__["StoreService"],
            _ngx_translate_core__WEBPACK_IMPORTED_MODULE_4__["TranslateService"]])
    ], FooterComponent);
    return FooterComponent;
}());



/***/ }),

/***/ "./src/app/core/header/header.component.html":
/*!***************************************************!*\
  !*** ./src/app/core/header/header.component.html ***!
  \***************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"wrapper\">\r\n  <img class=\"img--logo\" src=\"../../../assets/images/flow_logo.png\" alt=\"logo\">\r\n  <span class=\"txt--version\">{{ version }}</span>\r\n\r\n  <div class=\"info--project\">\r\n    <img class=\"img\" src=\"../../../assets/images/file.png\" alt=\"Project\">\r\n    <span class=\"txt--project\">{{ 'PROJECT' | translate }}</span>\r\n    <input class=\"input--project\" spellcheck=\"false\" type=\"text\" [value]=\"(projectName$ | async)\" (input)=\"changeProjectName($event)\">\r\n  </div>\r\n\r\n  <div class=\"top-nav\" (click)=\"hideExample()\">\r\n    <button class=\"btn blockly\" [class.active]=\"(mode$ | async) === 'blockly'\" (click)=\"setMode('blockly')\">\r\n      <img src=\"../../../assets/images/puzzle.png\" alt=\"Blockly\">\r\n      <span>{{ 'Blockly' }}</span>\r\n    </button>\r\n    <button class=\"btn code\" [class.active]=\"(mode$ | async) === 'code'\" (click)=\"setMode('code')\">\r\n      <img src=\"../../../assets/images/code.png\" alt=\"Python\">\r\n      <span>{{ 'Python' }}</span>\r\n    </button>\r\n  </div>\r\n\r\n  <div class=\"list--btn\">\r\n      <span>\r\n          <a href=\"/beta\">\r\n            <img src=\"../../../assets/images/icon-beta.png\" alt=\"BETA\" title=\"BETA\">\r\n          </a>\r\n          </span>\r\n          <span>\r\n            <a href=\"http://forum.m5stack.com/category/5/uiflow\" target=\"_blank\">\r\n              <img src=\"../../../assets/images/luntan.png\" alt=\"FORUM\" title=\"FORUM\">\r\n            </a>\r\n            </span>\r\n      <span>\r\n        <a href=\"https://m5stack.github.io/UIFlow_doc/\" target=\"_blank\">\r\n          <img src=\"../../../assets/images/doc.png\" alt=\"DOCS\" title=\"DOCS\">\r\n        </a>\r\n        </span>\r\n    <span (click)=\"showExample()\"  [class.isstick]=\"stick\">\r\n      <img src=\"../../../assets/images/example.png\" alt=\"Examples\" title=\"EXAMPLES\">\r\n    </span>\r\n    <span (click)=\"undo()\">\r\n      <img src=\"../../../assets/images/undo.png\" alt=\"Undo\" title=\"UNDO\">\r\n    </span>\r\n    <span (click)=\"redo()\">\r\n      <img src=\"../../../assets/images/redo.png\" alt=\"Redo\" title=\"REDO\">\r\n    </span>\r\n    <span (click)=\"openResourceManager()\">\r\n      <img src=\"../../../assets/images/cloud_open.png\" alt=\"closeDropdownListOpen Cloud\" title=\"MANAGER\">\r\n    </span>\r\n    <span (click)=\"execCode()\" class=\"mb-show\">\r\n      <img src=\"../../../assets/images/play.png\" alt=\"Run\" title=\"RUN\">\r\n    </span>\r\n    <button class=\"btn--more mb-show\" (click)=\"openDropdownList()\" (blur)=\"closeDropdownList($event)\">\r\n      <img src=\"../../../assets/images/moreclass.png\" alt=\"More\">\r\n    </button>\r\n  </div>\r\n\r\n  <div class=\"dropdown--list\" [@dropdownAnim]=\"dropdownState\">\r\n    <ul>\r\n      <li (mousedown)=\"openM5F()\"> \r\n        <img src=\"../../../assets/images/open.png\" alt=\"Open\">\r\n        <span>{{ \"OPEN\" | translate }}</span>\r\n        <input id=\"__openM5FBox\" type=\"file\" style=\"display:none;\" accept=\".m5f\">\r\n      </li>\r\n      <li (mousedown)=\"saveM5F()\">\r\n        <img src=\"../../../assets/images/save.png\" alt=\"Save\">\r\n        <span>{{ 'SAVE' | translate }}</span>\r\n      </li>\r\n\r\n      <li (mousedown)=\"uploadCode()\">\r\n        <img src=\"../../../assets/images/download.png\" alt=\"Download\">\r\n        <span>{{ 'DOWNLOAD' | translate }}</span>\r\n      </li>\r\n\r\n      <li class=\"pc-hide\">\r\n        <a href=\"https://m5stack.github.io/UIFlow_doc/\" target=\"_blank\">\r\n          <img src=\"../../../assets/images/doc.png\" alt=\"Examples\">\r\n         <span>{{ 'DOC' | translate }}</span>\r\n        </a>\r\n      </li>\r\n      <li (mousedown)=\"showExample()\" class=\"pc-hide\" [class.isstick]=\"stick\">\r\n        <img src=\"../../../assets/images/example.png\" alt=\"Examples\">\r\n        <span>{{ 'EXAMPLE' | translate }}</span>\r\n      </li>\r\n      <li (mousedown)=\"openResourceManager()\" class=\"pc-hide\">\r\n        <img src=\"../../../assets/images/cloud_open.png\" alt=\"closeDropdownListOpen Cloud\">\r\n        <span>{{ 'MANAGER' | translate }}</span>\r\n      </li>\r\n\r\n      <li (mousedown)=\"openUpdateRecord($event)\">\r\n        <img src=\"../../../assets/images/cloud_open.png\" alt=\"Updata\">\r\n        <span>{{ 'UPDATA' | translate }}</span>\r\n      </li>\r\n\r\n      <li (mousedown)=\"openSettingPanel($event)\">\r\n        <img src=\"../../../assets/images/setting.png\" alt=\"Setting\">\r\n        <span>{{ 'SETTING' | translate }}</span>\r\n      </li>\r\n    </ul>\r\n  </div>\r\n</div>\r\n\r\n<div class=\"wrapper--example\" (click)=\"hideExample()\" [@dropdownAnim]=\"exampleVisibility ? 'show':'hide'\">\r\n  <h1 class=\"title\" (click)=\"stopPropagation($event)\">{{ 'Examples'| translate }}</h1>\r\n  <div class=\"example-list\" (click)=\"stopPropagation($event)\">\r\n    <div class=\"example-item\" (click)=\"showExampleDetail($event, example)\" *ngFor=\"let example of exampleList\">\r\n      <img draggable=\"false\" [src]=\"'../../../assets/images/examples/' + example.icon\" alt=\"example\">\r\n      <p>{{ example.title }}</p>\r\n    </div>\r\n  </div>\r\n  <div class=\"example-detail\" [@dropdownAnim]=\"exampleDetail !== null ? 'show':'hide'\" (click)=\"stopPropagation($event)\">\r\n    <h1 class=\"txt--title\">{{ exampleDetail?.title }}</h1>\r\n    <p class=\"txt--description\">{{ exampleDetail?.description }}</p>\r\n    <p class=\"txt--required bolder\" *ngIf=\"exampleDetail?.required.length > 0\">{{ 'Required : ' }}</p>\r\n    <p class=\"txt--required\" *ngFor=\"let required of exampleDetail?.required\">\r\n      <span>{{ 'Connect the Unit ' }}</span>\r\n      <span class=\"keyword\">{{ required.unit }}</span>\r\n      <span>{{ ' to the port ' }}</span>\r\n      <span class=\"keyword\">{{ required.port }}</span>\r\n    </p>\r\n    <p class=\"txt--required\" *ngFor=\"let other of exampleDetail?.others\">{{ other }}</p>\r\n    <p class=\"txt--author\" *ngIf=\"exampleDetail?.author\"><span class=\"author-info\">Thanks for <span class=\"author\">{{ exampleDetail?.author }}</span></span></p>\r\n    <footer>\r\n      <button class=\"btn load\" (click)=\"runExample($event)\">Load</button>\r\n    </footer>\r\n  </div>\r\n  \r\n</div>\r\n\r\n<div class=\"eweima\" *ngIf=\"erweima$ | async\">\r\n    <span (click)=\"showQRCode()\">\r\n      <img src=\"../../../assets/images/erweima.svg\" alt=\"QRCode\">\r\n      <div class=\"wrapper--qrcode\" *ngIf=\"(remoteKey$ | async) !== '' && isShowQRcode\">\r\n        <qrcode [qrdata]=\"(remoteKey$ | async)\" [size]=\"128\" [level]=\"'M'\"></qrcode>\r\n        <button class=\"btn-clipboard\" (click)=\"copyQRcodeUrl()\">{{ 'Copy Url' }}</button>\r\n        <span class=\"tip--copy\" *ngIf=\"copyTip !== ''\">{{ copyTip }}</span>\r\n      </div>\r\n    </span>\r\n</div>\r\n\r\n<div class=\"float-btn\">\r\n    <button class=\"btn blockly\" [class.active]=\"(mode$ | async) === 'uieditor'\" (click)=\"setuieditorMode('uieditor')\">\r\n        <img src=\"../../../assets/images/pro.png\" alt=\"uieditor\">\r\n      </button>\r\n    <button class=\"btn blockly\" [class.active]=\"(mode$ | async) === 'blockly'\" (click)=\"setMBMode('blockly')\">\r\n        <img src=\"../../../assets/images/puzzle.png\" alt=\"Blockly\">\r\n      </button>\r\n      <button class=\"btn code\" [class.active]=\"(mode$ | async) === 'code'\" (click)=\"setMBMode('code')\">\r\n        <img src=\"../../../assets/images/code.png\" alt=\"Python\">\r\n      </button>\r\n</div>\r\n<app-loading *ngIf=\"loddingMode\"></app-loading>\r\n<!-- <div class=\"alert_position\">\r\n  <app-message #alert></app-message>\r\n</div> -->\r\n"

/***/ }),

/***/ "./src/app/core/header/header.component.scss":
/*!***************************************************!*\
  !*** ./src/app/core/header/header.component.scss ***!
  \***************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper {\n  position: relative;\n  -webkit-user-select: none;\n     -moz-user-select: none;\n      -ms-user-select: none;\n          user-select: none;\n  -webkit-user-drag: none;\n  width: 100%;\n  height: 48px;\n  background-color: var(--bg-color);\n  padding-left: 10px; }\n\n.img--logo {\n  display: block;\n  float: left;\n  height: 36px;\n  margin: 6px 0; }\n\n.txt--version {\n  -webkit-user-select: none;\n     -moz-user-select: none;\n      -ms-user-select: none;\n          user-select: none;\n  display: block;\n  float: left;\n  height: 36px;\n  margin: 6px 0;\n  line-height: 62px;\n  padding-left: 10px;\n  font-size: 14px;\n  font-family: Arial;\n  color: white; }\n\n.info--project {\n  position: relative;\n  display: block;\n  float: left;\n  margin: 6px 0 6px 20px;\n  height: 36px; }\n\n.info--project .img {\n    display: block;\n    float: left;\n    height: 28px;\n    margin: 8px 0 0 0; }\n\n.info--project .txt--project {\n    -webkit-user-select: none;\n       -moz-user-select: none;\n        -ms-user-select: none;\n            user-select: none;\n    display: block;\n    float: left;\n    height: 28px;\n    margin: 6px 10px 6px 0;\n    line-height: 46px;\n    font-size: 16px;\n    font-family: Arial;\n    color: white;\n    padding-left: 4px; }\n\n.info--project .input--project {\n    height: 100%;\n    padding-left: 10px;\n    font-size: 20px;\n    font-family: Arial;\n    color: white;\n    background-color: rgba(255, 255, 255, 0.5);\n    border-radius: 5px;\n    border: none;\n    outline: none; }\n\n.top-nav {\n  position: absolute;\n  top: 0;\n  bottom: 0;\n  left: 0;\n  right: 0;\n  margin: 6px auto;\n  width: 240px;\n  text-align: center; }\n\n.top-nav .btn {\n    width: 120px;\n    height: 36px;\n    border: 0;\n    outline: none;\n    background-color: var(--blockCodeBtn-color);\n    color: #ffffff;\n    cursor: pointer; }\n\n.top-nav .btn img {\n      -webkit-user-select: none;\n         -moz-user-select: none;\n          -ms-user-select: none;\n              user-select: none;\n      -webkit-user-drag: none; }\n\n.top-nav .btn.blockly {\n      border-top-left-radius: 30px;\n      border-bottom-left-radius: 30px;\n      padding-left: 12px; }\n\n.top-nav .btn.code {\n      border-top-right-radius: 30px;\n      border-bottom-right-radius: 30px;\n      padding-right: 12px; }\n\n.top-nav .btn.focus {\n      background-color: var(--blockCodeBtnFocus-color); }\n\n.top-nav .btn.blockly, .top-nav .btn.code {\n      transition: .35s all ease; }\n\n.top-nav .btn.blockly.active, .top-nav .btn.code.active {\n        background-color: var(--blockCodeBtnFocus-color); }\n\n.top-nav img,\n  .top-nav span {\n    display: block;\n    float: left;\n    -webkit-user-select: none;\n       -moz-user-select: none;\n        -ms-user-select: none;\n            user-select: none;\n    -webkit-user-drag: none; }\n\n.top-nav img {\n    width: 28px;\n    height: 28px;\n    margin: 4px 8px; }\n\n.top-nav span {\n    font-size: 16px;\n    height: 36px;\n    line-height: 36px; }\n\n.list--btn {\n  float: right;\n  padding-right: 10px; }\n\n.list--btn img {\n    display: block;\n    float: left;\n    width: 36px;\n    height: 36px;\n    margin: 6px 0;\n    padding: 4px;\n    cursor: pointer;\n    border-radius: 6px;\n    transition: all .25s;\n    -webkit-user-drag: none; }\n\n.list--btn img:hover {\n      background-color: var(--blockCodeBtnFocus-color); }\n\n.list--btn a {\n    -webkit-user-select: none;\n       -moz-user-select: none;\n        -ms-user-select: none;\n            user-select: none;\n    -webkit-user-drag: none; }\n\n.list--btn .btn--more {\n    width: 36px;\n    height: 36px;\n    margin: 6px 0;\n    border: none;\n    background-color: transparent;\n    outline: none; }\n\n.list--btn .btn--more img {\n      margin: 0; }\n\n.dropdown--list {\n  position: absolute;\n  top: 48px;\n  right: 0;\n  width: 160px;\n  background-color: var(--bg-color);\n  overflow: hidden;\n  z-index: 888888; }\n\n.dropdown--list ul > li {\n    width: 100%;\n    list-style: none;\n    cursor: pointer;\n    -webkit-user-select: none;\n       -moz-user-select: none;\n        -ms-user-select: none;\n            user-select: none; }\n\n.dropdown--list ul > li.pc-hide {\n      display: none; }\n\n.dropdown--list ul > li:hover {\n      background-color: var(--blockCodeBtnFocus-color); }\n\n.dropdown--list img {\n    width: 28px;\n    height: 28px;\n    margin: 6px 8px; }\n\n.dropdown--list span {\n    font-size: 16px;\n    vertical-align: 75%;\n    color: white;\n    font-family: Arial; }\n\n.wrapper--example {\n  position: absolute;\n  z-index: 9999999;\n  width: 100%;\n  height: calc(100% - 48px);\n  background-color: rgba(0, 0, 0, 0.76);\n  overflow: hidden; }\n\n.wrapper--example .title {\n    color: white;\n    font-size: 28px;\n    background-color: rgba(68, 68, 68, 0.96);\n    font-family: Arial, Helvetica, sans-serif;\n    padding: 10px 0 10px 10px; }\n\n.wrapper--example .example-list {\n    background-color: rgba(68, 68, 68, 0.96);\n    padding-bottom: 10px;\n    max-height: 220px;\n    overflow: auto; }\n\n.wrapper--example .example-list .example-item {\n      display: inline-block;\n      transition: .25s all;\n      border: 2px rgba(68, 68, 68, 0.96) solid; }\n\n.wrapper--example .example-list .example-item:hover {\n        border-radius: 8px;\n        border: 2px #eee solid; }\n\n.wrapper--example .example-list .example-item img {\n        background-color: #eee;\n        max-width: 128px;\n        border-radius: 5px;\n        margin: 10px;\n        cursor: pointer; }\n\n.wrapper--example .example-list .example-item > p {\n        text-align: center;\n        color: #FFFFFF;\n        font-size: 20px;\n        padding: 0 0 8px 0;\n        font-family: Arial, Helvetica, sans-serif; }\n\n.wrapper--example .example-detail {\n    width: 100%;\n    background-color: rgba(32, 32, 32, 0.96);\n    font-family: Arial, Helvetica, sans-serif;\n    overflow: hidden;\n    color: #FFF; }\n\n.wrapper--example .example-detail .txt--title {\n      padding: 10px 0 10px 10px; }\n\n.wrapper--example .example-detail .txt--description {\n      padding: 10px 0 10px 10px;\n      font-size: 22px;\n      color: #eee; }\n\n.wrapper--example .example-detail .txt--required {\n      padding: 10px 0 10px 10px;\n      font-size: 18px;\n      color: #d9d9d9; }\n\n.wrapper--example .example-detail .txt--required.bolder {\n        font-weight: bolder;\n        color: #E71D36;\n        padding: 10px 0 0 10px; }\n\n.wrapper--example .example-detail .txt--required .keyword {\n        color: #E71D36;\n        font-weight: bolder; }\n\n.wrapper--example .example-detail .txt--author {\n      position: relative; }\n\n.wrapper--example .example-detail .txt--author .author-info {\n        position: absolute;\n        right: 5%; }\n\n.wrapper--example .example-detail .txt--author .author-info .author {\n          font-weight: bolder;\n          color: #E71D36; }\n\n.wrapper--example .example-detail footer .btn {\n      margin: 10px;\n      outline: none;\n      border: none;\n      border-radius: 6px;\n      background-color: var(--bg-color);\n      color: white;\n      padding: 8px 12px;\n      cursor: pointer;\n      font-size: 24px; }\n\n.isstick {\n  display: none; }\n\n.eweima {\n  position: fixed;\n  top: 50%;\n  right: 32px;\n  z-index: 5;\n  -webkit-transform: translateY(-50%);\n          transform: translateY(-50%); }\n\n.eweima .wrapper--qrcode {\n    position: fixed;\n    right: 46px;\n    top: 50%;\n    -webkit-transform: translateY(-50%);\n            transform: translateY(-50%);\n    background-color: rgba(255, 255, 255, 0.96);\n    border-radius: 5px;\n    z-index: 1099;\n    padding: 10px; }\n\n.eweima .wrapper--qrcode button {\n      outline: none;\n      border: none;\n      margin-top: 6px;\n      padding: 4px 12px;\n      font-family: Arial;\n      color: white;\n      background-color: orange;\n      border-radius: 4px;\n      cursor: pointer; }\n\n.eweima .wrapper--qrcode .tip--copy {\n      font-size: 12px;\n      margin-left: 4px;\n      color: #3ac569;\n      font-weight: bolder;\n      font-family: Arial, Helvetica, sans-serif; }\n\n.float-btn {\n  display: none; }\n\n@media only screen and (min-height: 320px) and (max-height: 767px) {\n  .wrapper .top-nav {\n    display: none; }\n  .wrapper .list--btn span:not(.mb-show) {\n    display: none; }\n  .wrapper .dropdown--list li.pc-hide {\n    display: block; }\n  .wrapper .dropdown--list li a {\n    text-decoration: none;\n    display: block;\n    width: 100%;\n    height: 100%; }\n  .wrapper--example .example-list {\n    max-height: 80px;\n    overflow-y: scroll;\n    padding-bottom: 10px; }\n    .wrapper--example .example-list .example-item img {\n      display: block;\n      max-width: 60px;\n      border-radius: 5px;\n      margin: 5px;\n      cursor: pointer; }\n    .wrapper--example .example-list .example-item > p {\n      display: none; }\n  .wrapper--example .example-detail {\n    max-height: 120px;\n    width: 100%;\n    overflow-y: scroll;\n    font-size: 12px; }\n    .wrapper--example .example-detail .txt--title {\n      font-size: 16px;\n      padding: 5px 0 5px 5px; }\n    .wrapper--example .example-detail .txt--description {\n      padding: 5px 0 5px 5px;\n      font-size: 12px; }\n    .wrapper--example .example-detail .txt--required {\n      padding: 5px 0 5px 5px; }\n      .wrapper--example .example-detail .txt--required.bolder {\n        padding: 5px 0 5px 5px; }\n  .float-btn {\n    position: fixed;\n    display: block;\n    top: 48px;\n    right: 20px;\n    z-index: 1; }\n    .float-btn .btn {\n      height: 36px;\n      border: 0;\n      outline: none;\n      background-color: var(--blockCodeBtn-color);\n      color: #ffffff;\n      border-radius: 0 0 50% 50%;\n      cursor: pointer; }\n      .float-btn .btn img {\n        -webkit-user-select: none;\n           -moz-user-select: none;\n            -ms-user-select: none;\n                user-select: none;\n        -webkit-user-drag: none; }\n      .float-btn .btn.focus {\n        background-color: var(--blockCodeBtnFocus-color); }\n      .float-btn .btn.blockly, .float-btn .btn.code {\n        transition: .35s all ease; }\n        .float-btn .btn.blockly.active, .float-btn .btn.code.active {\n          background-color: var(--blockCodeBtnFocus-color); }\n      .float-btn .btn img,\n      .float-btn .btn span {\n        display: block;\n        float: left;\n        -webkit-user-select: none;\n           -moz-user-select: none;\n            -ms-user-select: none;\n                user-select: none;\n        -webkit-user-drag: none; }\n      .float-btn .btn img {\n        width: 28px;\n        height: 28px;\n        margin: 4px 8px; }\n      .float-btn .btn span {\n        font-size: 16px;\n        height: 36px;\n        line-height: 36px; }\n  .eweima {\n    position: fixed;\n    top: 67px;\n    right: 178px; }\n    .eweima .wrapper--qrcode {\n      position: fixed;\n      top: 142px;\n      right: -53px;\n      background-color: rgba(255, 255, 255, 0.96);\n      border-radius: 5px;\n      z-index: 1099;\n      padding: 10px; }\n  .isstick {\n    display: none !important; } }\n\n@media only screen and (min-width: 1024px) {\n  .wrapper .top-nav {\n    display: block; }\n  .wrapper .dropdown--list li a {\n    text-decoration: none;\n    display: block;\n    width: 100%;\n    height: 100%; }\n  .float-btn {\n    display: none; } }\n\n.alert_position {\n  position: fixed;\n  z-index: 100;\n  top: 38%;\n  right: 0;\n  max-width: 300px;\n  max-height: 300px;\n  background-color: var(--bg-color);\n  border-radius: 10px;\n  box-shadow: 20px;\n  opacity: 0.85;\n  overflow: hidden; }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvY29yZS9oZWFkZXIvWjpcXHdvcmtzcGFjZVxcbXlfenJlbmRlclxcZmxvdy9zcmNcXGFwcFxcY29yZVxcaGVhZGVyXFxoZWFkZXIuY29tcG9uZW50LnNjc3MiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IkFBQ0E7RUFDSSxtQkFBa0I7RUFDbEIsMEJBQWlCO0tBQWpCLHVCQUFpQjtNQUFqQixzQkFBaUI7VUFBakIsa0JBQWlCO0VBQ2pCLHdCQUF1QjtFQUN2QixZQUFXO0VBQ1gsYUFOUztFQU9ULGtDQUFpQztFQUNqQyxtQkFBa0IsRUFDckI7O0FBRUQ7RUFDSSxlQUFjO0VBQ2QsWUFBVztFQUNYLGFBQVk7RUFDWixjQUFhLEVBQ2hCOztBQUVEO0VBQ0ksMEJBQWlCO0tBQWpCLHVCQUFpQjtNQUFqQixzQkFBaUI7VUFBakIsa0JBQWlCO0VBQ2pCLGVBQWM7RUFDZCxZQUFXO0VBQ1gsYUFBWTtFQUNaLGNBQWE7RUFDYixrQkFBaUI7RUFDakIsbUJBQWtCO0VBQ2xCLGdCQUFlO0VBQ2YsbUJBQWtCO0VBQ2xCLGFBQVksRUFDZjs7QUFFRDtFQUNJLG1CQUFrQjtFQUNsQixlQUFjO0VBQ2QsWUFBVztFQUNYLHVCQUFzQjtFQUN0QixhQUFZLEVBOEJmOztBQW5DRDtJQU9RLGVBQWM7SUFDZCxZQUFXO0lBQ1gsYUFBWTtJQUNaLGtCQUFpQixFQUNwQjs7QUFYTDtJQWFRLDBCQUFpQjtPQUFqQix1QkFBaUI7UUFBakIsc0JBQWlCO1lBQWpCLGtCQUFpQjtJQUNqQixlQUFjO0lBQ2QsWUFBVztJQUNYLGFBQVk7SUFDWix1QkFBc0I7SUFDdEIsa0JBQWlCO0lBQ2pCLGdCQUFlO0lBQ2YsbUJBQWtCO0lBQ2xCLGFBQVk7SUFDWixrQkFBaUIsRUFDcEI7O0FBdkJMO0lBeUJRLGFBQVk7SUFDWixtQkFBa0I7SUFDbEIsZ0JBQWU7SUFDZixtQkFBa0I7SUFDbEIsYUFBWTtJQUNaLDJDQUEwQztJQUMxQyxtQkFBa0I7SUFDbEIsYUFBWTtJQUNaLGNBQWEsRUFDaEI7O0FBR0w7RUFDSSxtQkFBa0I7RUFDbEIsT0FBTTtFQUNOLFVBQVM7RUFDVCxRQUFPO0VBQ1AsU0FBUTtFQUNSLGlCQUFnQjtFQUNoQixhQUFZO0VBQ1osbUJBQWtCLEVBbURyQjs7QUEzREQ7SUFVUSxhQUFZO0lBQ1osYUFBWTtJQUNaLFVBQVM7SUFDVCxjQUFhO0lBQ2IsNENBQTJDO0lBQzNDLGVBQWM7SUFDZCxnQkFBZSxFQXlCbEI7O0FBekNMO01Ba0JZLDBCQUFpQjtTQUFqQix1QkFBaUI7VUFBakIsc0JBQWlCO2NBQWpCLGtCQUFpQjtNQUNqQix3QkFBdUIsRUFDMUI7O0FBcEJUO01Bc0JZLDZCQUE0QjtNQUM1QixnQ0FBK0I7TUFDL0IsbUJBQWtCLEVBQ3JCOztBQXpCVDtNQTJCWSw4QkFBNkI7TUFDN0IsaUNBQWdDO01BQ2hDLG9CQUFtQixFQUN0Qjs7QUE5QlQ7TUFnQ1ksaURBQWdELEVBQ25EOztBQWpDVDtNQW9DWSwwQkFBeUIsRUFJNUI7O0FBeENUO1FBc0NnQixpREFBZ0QsRUFDbkQ7O0FBdkNiOztJQTRDUSxlQUFjO0lBQ2QsWUFBVztJQUNYLDBCQUFpQjtPQUFqQix1QkFBaUI7UUFBakIsc0JBQWlCO1lBQWpCLGtCQUFpQjtJQUNqQix3QkFBdUIsRUFDMUI7O0FBaERMO0lBa0RRLFlBQVc7SUFDWCxhQUFZO0lBQ1osZ0JBQWUsRUFDbEI7O0FBckRMO0lBdURRLGdCQUFlO0lBQ2YsYUFBWTtJQUNaLGtCQUFpQixFQUNwQjs7QUFHTDtFQUNJLGFBQVk7RUFDWixvQkFBbUIsRUErQnRCOztBQWpDRDtJQUlRLGVBQWM7SUFDZCxZQUFXO0lBQ1gsWUFBVztJQUNYLGFBQVk7SUFDWixjQUFhO0lBQ2IsYUFBWTtJQUNaLGdCQUFlO0lBQ2YsbUJBQWtCO0lBQ2xCLHFCQUFvQjtJQUNwQix3QkFBdUIsRUFJMUI7O0FBakJMO01BZVksaURBQWdELEVBQ25EOztBQWhCVDtJQW1CUSwwQkFBaUI7T0FBakIsdUJBQWlCO1FBQWpCLHNCQUFpQjtZQUFqQixrQkFBaUI7SUFDakIsd0JBQXVCLEVBQzFCOztBQXJCTDtJQXVCUSxZQUFXO0lBQ1gsYUFBWTtJQUNaLGNBQWE7SUFDYixhQUFZO0lBQ1osOEJBQTZCO0lBQzdCLGNBQWEsRUFJaEI7O0FBaENMO01BOEJZLFVBQVMsRUFDWjs7QUFJVDtFQUNJLG1CQUFrQjtFQUNsQixVQUFTO0VBQ1QsU0FBUTtFQUNSLGFBQVk7RUFDWixrQ0FBaUM7RUFDakMsaUJBQWdCO0VBQ2hCLGdCQUFlLEVBd0JsQjs7QUEvQkQ7SUFTUSxZQUFXO0lBQ1gsaUJBQWdCO0lBQ2hCLGdCQUFlO0lBQ2YsMEJBQWlCO09BQWpCLHVCQUFpQjtRQUFqQixzQkFBaUI7WUFBakIsa0JBQWlCLEVBT3BCOztBQW5CTDtNQWNZLGNBQWEsRUFDaEI7O0FBZlQ7TUFpQlksaURBQWdELEVBQ25EOztBQWxCVDtJQXFCUSxZQUFXO0lBQ1gsYUFBWTtJQUNaLGdCQUFlLEVBQ2xCOztBQXhCTDtJQTBCUSxnQkFBZTtJQUNmLG9CQUFtQjtJQUNuQixhQUFZO0lBQ1osbUJBQWtCLEVBQ3JCOztBQUdMO0VBQ0ksbUJBQWtCO0VBQ2xCLGlCQUFnQjtFQUNoQixZQUFXO0VBQ1gsMEJBQXlCO0VBQ3pCLHNDQUFxQztFQUNyQyxpQkFBZ0IsRUErRm5COztBQXJHRDtJQVFRLGFBQVk7SUFDWixnQkFBZTtJQUNmLHlDQUF3QztJQUN4QywwQ0FBeUM7SUFDekMsMEJBQXlCLEVBQzVCOztBQWJMO0lBZVEseUNBQXdDO0lBQ3hDLHFCQUFvQjtJQUNwQixrQkFBaUI7SUFDakIsZUFBYyxFQXlCakI7O0FBM0NMO01Bb0JZLHNCQUFxQjtNQUNyQixxQkFBb0I7TUFDcEIseUNBQXdDLEVBb0IzQzs7QUExQ1Q7UUF3QmdCLG1CQUFrQjtRQUNsQix1QkFBc0IsRUFDekI7O0FBMUJiO1FBNkJnQix1QkFBc0I7UUFDdEIsaUJBQWdCO1FBQ2hCLG1CQUFrQjtRQUNsQixhQUFZO1FBQ1osZ0JBQWUsRUFDbEI7O0FBbENiO1FBb0NnQixtQkFBa0I7UUFDbEIsZUFBYztRQUNkLGdCQUFlO1FBQ2YsbUJBQWtCO1FBQ2xCLDBDQUF5QyxFQUM1Qzs7QUF6Q2I7SUE2Q1EsWUFBVztJQUNYLHlDQUF3QztJQUN4QywwQ0FBeUM7SUFDekMsaUJBQWdCO0lBQ2hCLFlBQVcsRUFtRGQ7O0FBcEdMO01Bb0RZLDBCQUF5QixFQUM1Qjs7QUFyRFQ7TUF1RFksMEJBQXlCO01BQ3pCLGdCQUFlO01BQ2YsWUFBVyxFQUNkOztBQTFEVDtNQTREWSwwQkFBeUI7TUFDekIsZ0JBQWU7TUFDZixlQUFjLEVBVWpCOztBQXhFVDtRQWdFZ0Isb0JBQW1CO1FBQ25CLGVBQWM7UUFDZCx1QkFBc0IsRUFDekI7O0FBbkViO1FBcUVnQixlQUFjO1FBQ2Qsb0JBQW1CLEVBQ3RCOztBQXZFYjtNQTBFWSxtQkFBa0IsRUFTckI7O0FBbkZUO1FBNEVnQixtQkFBa0I7UUFDbEIsVUFBUyxFQUtaOztBQWxGYjtVQStFb0Isb0JBQW1CO1VBQ25CLGVBQWMsRUFDakI7O0FBakZqQjtNQXlGZ0IsYUFBWTtNQUNaLGNBQWE7TUFDYixhQUFZO01BQ1osbUJBQWtCO01BQ2xCLGtDQUFpQztNQUNqQyxhQUFZO01BQ1osa0JBQWlCO01BQ2pCLGdCQUFlO01BQ2YsZ0JBQWUsRUFDbEI7O0FBS2I7RUFDSSxjQUFhLEVBQ2hCOztBQUVEO0VBQ0ksZ0JBQWU7RUFDZixTQUFRO0VBQ1IsWUFBVztFQUNYLFdBQVU7RUFDVixvQ0FBMkI7VUFBM0IsNEJBQTJCLEVBNkI5Qjs7QUFsQ0Q7SUFPUSxnQkFBZTtJQUNmLFlBQVc7SUFDWCxTQUFRO0lBQ1Isb0NBQTJCO1lBQTNCLDRCQUEyQjtJQUMzQiw0Q0FBMkM7SUFDM0MsbUJBQWtCO0lBQ2xCLGNBQWE7SUFDYixjQUFhLEVBbUJoQjs7QUFqQ0w7TUFnQlksY0FBYTtNQUNiLGFBQVk7TUFDWixnQkFBZTtNQUNmLGtCQUFpQjtNQUNqQixtQkFBa0I7TUFDbEIsYUFBWTtNQUNaLHlCQUF3QjtNQUN4QixtQkFBa0I7TUFDbEIsZ0JBQWUsRUFDbEI7O0FBekJUO01BMkJZLGdCQUFlO01BQ2YsaUJBQWdCO01BQ2hCLGVBQWM7TUFDZCxvQkFBbUI7TUFDbkIsMENBQXlDLEVBQzVDOztBQUlUO0VBQ0ksY0FBYSxFQUNoQjs7QUFFRDtFQUNJO0lBRVEsY0FBYSxFQUNoQjtFQUhMO0lBTVksY0FBYSxFQUNoQjtFQVBUO0lBWWdCLGVBQWMsRUFDakI7RUFiYjtJQWVnQixzQkFBcUI7SUFDckIsZUFBYztJQUNkLFlBQVc7SUFDWCxhQUFZLEVBQ2Y7RUFJYjtJQUVRLGlCQUFnQjtJQUNoQixtQkFBa0I7SUFDbEIscUJBQW9CLEVBYXZCO0lBakJMO01BT2dCLGVBQWM7TUFDZCxnQkFBZTtNQUNmLG1CQUFrQjtNQUNsQixZQUFXO01BQ1gsZ0JBQWUsRUFDbEI7SUFaYjtNQWNnQixjQUFhLEVBQ2hCO0VBZmI7SUFtQlEsa0JBQWlCO0lBQ2pCLFlBQVc7SUFDWCxtQkFBa0I7SUFDbEIsZ0JBQWUsRUFlbEI7SUFyQ0w7TUF3QlksZ0JBQWU7TUFDZix1QkFBc0IsRUFDekI7SUExQlQ7TUE0QlksdUJBQXNCO01BQ3RCLGdCQUFlLEVBQ2xCO0lBOUJUO01BZ0NZLHVCQUFzQixFQUl6QjtNQXBDVDtRQWtDZ0IsdUJBQXNCLEVBQ3pCO0VBSWI7SUFDSSxnQkFBZTtJQUNmLGVBQWM7SUFDZCxVQUFTO0lBQ1QsWUFBVztJQUNYLFdBQVUsRUF5Q2I7SUE5Q0Q7TUFPUSxhQUFZO01BQ1osVUFBUztNQUNULGNBQWE7TUFDYiw0Q0FBMkM7TUFDM0MsZUFBYztNQUNkLDJCQUEwQjtNQUMxQixnQkFBZSxFQWdDbEI7TUE3Q0w7UUFlWSwwQkFBaUI7V0FBakIsdUJBQWlCO1lBQWpCLHNCQUFpQjtnQkFBakIsa0JBQWlCO1FBQ2pCLHdCQUF1QixFQUMxQjtNQWpCVDtRQW1CWSxpREFBZ0QsRUFDbkQ7TUFwQlQ7UUF1QlksMEJBQXlCLEVBSTVCO1FBM0JUO1VBeUJnQixpREFBZ0QsRUFDbkQ7TUExQmI7O1FBOEJZLGVBQWM7UUFDZCxZQUFXO1FBQ1gsMEJBQWlCO1dBQWpCLHVCQUFpQjtZQUFqQixzQkFBaUI7Z0JBQWpCLGtCQUFpQjtRQUNqQix3QkFBdUIsRUFDMUI7TUFsQ1Q7UUFvQ1ksWUFBVztRQUNYLGFBQVk7UUFDWixnQkFBZSxFQUNsQjtNQXZDVDtRQXlDWSxnQkFBZTtRQUNmLGFBQVk7UUFDWixrQkFBaUIsRUFDcEI7RUFHVDtJQUNJLGdCQUFlO0lBQ2YsVUFBUztJQUNULGFBQVksRUFVZjtJQWJEO01BS1EsZ0JBQWU7TUFDZixXQUFVO01BQ1YsYUFBWTtNQUNaLDRDQUEyQztNQUMzQyxtQkFBa0I7TUFDbEIsY0FBYTtNQUNiLGNBQWEsRUFDaEI7RUFFTDtJQUNJLHlCQUF3QixFQUMzQixFQUFBOztBQUdMO0VBQ0k7SUFFUSxlQUFjLEVBQ2pCO0VBSEw7SUFPZ0Isc0JBQXFCO0lBQ3JCLGVBQWM7SUFDZCxZQUFXO0lBQ1gsYUFBWSxFQUNmO0VBSWI7SUFDSSxjQUFhLEVBQ2hCLEVBQUE7O0FBR0w7RUFDSSxnQkFBZTtFQUNmLGFBQVk7RUFDWixTQUFPO0VBQ1AsU0FBTztFQUNQLGlCQUFnQjtFQUVoQixrQkFBaUI7RUFFakIsa0NBQWdDO0VBQ2hDLG9CQUFrQjtFQUNsQixpQkFBZ0I7RUFDaEIsY0FBYTtFQUNiLGlCQUFnQixFQUNuQiIsImZpbGUiOiJzcmMvYXBwL2NvcmUvaGVhZGVyL2hlYWRlci5jb21wb25lbnQuc2NzcyIsInNvdXJjZXNDb250ZW50IjpbIiRoZWlnaHQ6IDQ4cHg7XHJcbi53cmFwcGVyIHtcclxuICAgIHBvc2l0aW9uOiByZWxhdGl2ZTtcclxuICAgIHVzZXItc2VsZWN0OiBub25lO1xyXG4gICAgLXdlYmtpdC11c2VyLWRyYWc6IG5vbmU7XHJcbiAgICB3aWR0aDogMTAwJTtcclxuICAgIGhlaWdodDogJGhlaWdodDtcclxuICAgIGJhY2tncm91bmQtY29sb3I6IHZhcigtLWJnLWNvbG9yKTtcclxuICAgIHBhZGRpbmctbGVmdDogMTBweDtcclxufVxyXG5cclxuLmltZy0tbG9nbyB7XHJcbiAgICBkaXNwbGF5OiBibG9jaztcclxuICAgIGZsb2F0OiBsZWZ0O1xyXG4gICAgaGVpZ2h0OiAzNnB4O1xyXG4gICAgbWFyZ2luOiA2cHggMDtcclxufVxyXG5cclxuLnR4dC0tdmVyc2lvbiB7XHJcbiAgICB1c2VyLXNlbGVjdDogbm9uZTtcclxuICAgIGRpc3BsYXk6IGJsb2NrO1xyXG4gICAgZmxvYXQ6IGxlZnQ7XHJcbiAgICBoZWlnaHQ6IDM2cHg7XHJcbiAgICBtYXJnaW46IDZweCAwO1xyXG4gICAgbGluZS1oZWlnaHQ6IDYycHg7XHJcbiAgICBwYWRkaW5nLWxlZnQ6IDEwcHg7XHJcbiAgICBmb250LXNpemU6IDE0cHg7XHJcbiAgICBmb250LWZhbWlseTogQXJpYWw7XHJcbiAgICBjb2xvcjogd2hpdGU7XHJcbn1cclxuXHJcbi5pbmZvLS1wcm9qZWN0IHtcclxuICAgIHBvc2l0aW9uOiByZWxhdGl2ZTtcclxuICAgIGRpc3BsYXk6IGJsb2NrO1xyXG4gICAgZmxvYXQ6IGxlZnQ7XHJcbiAgICBtYXJnaW46IDZweCAwIDZweCAyMHB4O1xyXG4gICAgaGVpZ2h0OiAzNnB4O1xyXG4gICAgLmltZyB7XHJcbiAgICAgICAgZGlzcGxheTogYmxvY2s7XHJcbiAgICAgICAgZmxvYXQ6IGxlZnQ7XHJcbiAgICAgICAgaGVpZ2h0OiAyOHB4O1xyXG4gICAgICAgIG1hcmdpbjogOHB4IDAgMCAwO1xyXG4gICAgfVxyXG4gICAgLnR4dC0tcHJvamVjdCB7XHJcbiAgICAgICAgdXNlci1zZWxlY3Q6IG5vbmU7XHJcbiAgICAgICAgZGlzcGxheTogYmxvY2s7XHJcbiAgICAgICAgZmxvYXQ6IGxlZnQ7XHJcbiAgICAgICAgaGVpZ2h0OiAyOHB4O1xyXG4gICAgICAgIG1hcmdpbjogNnB4IDEwcHggNnB4IDA7XHJcbiAgICAgICAgbGluZS1oZWlnaHQ6IDQ2cHg7XHJcbiAgICAgICAgZm9udC1zaXplOiAxNnB4O1xyXG4gICAgICAgIGZvbnQtZmFtaWx5OiBBcmlhbDtcclxuICAgICAgICBjb2xvcjogd2hpdGU7XHJcbiAgICAgICAgcGFkZGluZy1sZWZ0OiA0cHg7XHJcbiAgICB9XHJcbiAgICAuaW5wdXQtLXByb2plY3Qge1xyXG4gICAgICAgIGhlaWdodDogMTAwJTtcclxuICAgICAgICBwYWRkaW5nLWxlZnQ6IDEwcHg7XHJcbiAgICAgICAgZm9udC1zaXplOiAyMHB4O1xyXG4gICAgICAgIGZvbnQtZmFtaWx5OiBBcmlhbDtcclxuICAgICAgICBjb2xvcjogd2hpdGU7XHJcbiAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogcmdiYSgyNTUsIDI1NSwgMjU1LCAwLjUpO1xyXG4gICAgICAgIGJvcmRlci1yYWRpdXM6IDVweDtcclxuICAgICAgICBib3JkZXI6IG5vbmU7XHJcbiAgICAgICAgb3V0bGluZTogbm9uZTtcclxuICAgIH1cclxufVxyXG5cclxuLnRvcC1uYXYge1xyXG4gICAgcG9zaXRpb246IGFic29sdXRlO1xyXG4gICAgdG9wOiAwO1xyXG4gICAgYm90dG9tOiAwO1xyXG4gICAgbGVmdDogMDtcclxuICAgIHJpZ2h0OiAwO1xyXG4gICAgbWFyZ2luOiA2cHggYXV0bztcclxuICAgIHdpZHRoOiAyNDBweDtcclxuICAgIHRleHQtYWxpZ246IGNlbnRlcjtcclxuICAgIC5idG4ge1xyXG4gICAgICAgIHdpZHRoOiAxMjBweDtcclxuICAgICAgICBoZWlnaHQ6IDM2cHg7XHJcbiAgICAgICAgYm9yZGVyOiAwO1xyXG4gICAgICAgIG91dGxpbmU6IG5vbmU7XHJcbiAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogdmFyKC0tYmxvY2tDb2RlQnRuLWNvbG9yKTtcclxuICAgICAgICBjb2xvcjogI2ZmZmZmZjtcclxuICAgICAgICBjdXJzb3I6IHBvaW50ZXI7XHJcbiAgICAgICAgaW1nIHtcclxuICAgICAgICAgICAgdXNlci1zZWxlY3Q6IG5vbmU7XHJcbiAgICAgICAgICAgIC13ZWJraXQtdXNlci1kcmFnOiBub25lO1xyXG4gICAgICAgIH1cclxuICAgICAgICAmLmJsb2NrbHkge1xyXG4gICAgICAgICAgICBib3JkZXItdG9wLWxlZnQtcmFkaXVzOiAzMHB4O1xyXG4gICAgICAgICAgICBib3JkZXItYm90dG9tLWxlZnQtcmFkaXVzOiAzMHB4O1xyXG4gICAgICAgICAgICBwYWRkaW5nLWxlZnQ6IDEycHg7XHJcbiAgICAgICAgfVxyXG4gICAgICAgICYuY29kZSB7XHJcbiAgICAgICAgICAgIGJvcmRlci10b3AtcmlnaHQtcmFkaXVzOiAzMHB4O1xyXG4gICAgICAgICAgICBib3JkZXItYm90dG9tLXJpZ2h0LXJhZGl1czogMzBweDtcclxuICAgICAgICAgICAgcGFkZGluZy1yaWdodDogMTJweDtcclxuICAgICAgICB9XHJcbiAgICAgICAgJi5mb2N1cyB7XHJcbiAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6IHZhcigtLWJsb2NrQ29kZUJ0bkZvY3VzLWNvbG9yKTtcclxuICAgICAgICB9XHJcbiAgICAgICAgJi5ibG9ja2x5LFxyXG4gICAgICAgICYuY29kZSB7XHJcbiAgICAgICAgICAgIHRyYW5zaXRpb246IC4zNXMgYWxsIGVhc2U7XHJcbiAgICAgICAgICAgICYuYWN0aXZlIHtcclxuICAgICAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6IHZhcigtLWJsb2NrQ29kZUJ0bkZvY3VzLWNvbG9yKTtcclxuICAgICAgICAgICAgfVxyXG4gICAgICAgIH1cclxuICAgIH1cclxuICAgIGltZyxcclxuICAgIHNwYW4ge1xyXG4gICAgICAgIGRpc3BsYXk6IGJsb2NrO1xyXG4gICAgICAgIGZsb2F0OiBsZWZ0O1xyXG4gICAgICAgIHVzZXItc2VsZWN0OiBub25lO1xyXG4gICAgICAgIC13ZWJraXQtdXNlci1kcmFnOiBub25lO1xyXG4gICAgfVxyXG4gICAgaW1nIHtcclxuICAgICAgICB3aWR0aDogMjhweDtcclxuICAgICAgICBoZWlnaHQ6IDI4cHg7XHJcbiAgICAgICAgbWFyZ2luOiA0cHggOHB4O1xyXG4gICAgfVxyXG4gICAgc3BhbiB7XHJcbiAgICAgICAgZm9udC1zaXplOiAxNnB4O1xyXG4gICAgICAgIGhlaWdodDogMzZweDtcclxuICAgICAgICBsaW5lLWhlaWdodDogMzZweDtcclxuICAgIH1cclxufVxyXG5cclxuLmxpc3QtLWJ0biB7XHJcbiAgICBmbG9hdDogcmlnaHQ7XHJcbiAgICBwYWRkaW5nLXJpZ2h0OiAxMHB4O1xyXG4gICAgaW1nIHtcclxuICAgICAgICBkaXNwbGF5OiBibG9jaztcclxuICAgICAgICBmbG9hdDogbGVmdDtcclxuICAgICAgICB3aWR0aDogMzZweDtcclxuICAgICAgICBoZWlnaHQ6IDM2cHg7XHJcbiAgICAgICAgbWFyZ2luOiA2cHggMDtcclxuICAgICAgICBwYWRkaW5nOiA0cHg7XHJcbiAgICAgICAgY3Vyc29yOiBwb2ludGVyO1xyXG4gICAgICAgIGJvcmRlci1yYWRpdXM6IDZweDtcclxuICAgICAgICB0cmFuc2l0aW9uOiBhbGwgLjI1cztcclxuICAgICAgICAtd2Via2l0LXVzZXItZHJhZzogbm9uZTtcclxuICAgICAgICAmOmhvdmVyIHtcclxuICAgICAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogdmFyKC0tYmxvY2tDb2RlQnRuRm9jdXMtY29sb3IpO1xyXG4gICAgICAgIH1cclxuICAgIH1cclxuICAgIGEge1xyXG4gICAgICAgIHVzZXItc2VsZWN0OiBub25lO1xyXG4gICAgICAgIC13ZWJraXQtdXNlci1kcmFnOiBub25lO1xyXG4gICAgfVxyXG4gICAgLmJ0bi0tbW9yZSB7XHJcbiAgICAgICAgd2lkdGg6IDM2cHg7XHJcbiAgICAgICAgaGVpZ2h0OiAzNnB4O1xyXG4gICAgICAgIG1hcmdpbjogNnB4IDA7XHJcbiAgICAgICAgYm9yZGVyOiBub25lO1xyXG4gICAgICAgIGJhY2tncm91bmQtY29sb3I6IHRyYW5zcGFyZW50O1xyXG4gICAgICAgIG91dGxpbmU6IG5vbmU7XHJcbiAgICAgICAgaW1nIHtcclxuICAgICAgICAgICAgbWFyZ2luOiAwO1xyXG4gICAgICAgIH1cclxuICAgIH1cclxufVxyXG5cclxuLmRyb3Bkb3duLS1saXN0IHtcclxuICAgIHBvc2l0aW9uOiBhYnNvbHV0ZTtcclxuICAgIHRvcDogNDhweDtcclxuICAgIHJpZ2h0OiAwO1xyXG4gICAgd2lkdGg6IDE2MHB4O1xyXG4gICAgYmFja2dyb3VuZC1jb2xvcjogdmFyKC0tYmctY29sb3IpO1xyXG4gICAgb3ZlcmZsb3c6IGhpZGRlbjtcclxuICAgIHotaW5kZXg6IDg4ODg4ODtcclxuICAgIHVsPmxpIHtcclxuICAgICAgICB3aWR0aDogMTAwJTtcclxuICAgICAgICBsaXN0LXN0eWxlOiBub25lO1xyXG4gICAgICAgIGN1cnNvcjogcG9pbnRlcjtcclxuICAgICAgICB1c2VyLXNlbGVjdDogbm9uZTtcclxuICAgICAgICAmLnBjLWhpZGUge1xyXG4gICAgICAgICAgICBkaXNwbGF5OiBub25lO1xyXG4gICAgICAgIH1cclxuICAgICAgICAmOmhvdmVyIHtcclxuICAgICAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogdmFyKC0tYmxvY2tDb2RlQnRuRm9jdXMtY29sb3IpO1xyXG4gICAgICAgIH1cclxuICAgIH1cclxuICAgIGltZyB7XHJcbiAgICAgICAgd2lkdGg6IDI4cHg7XHJcbiAgICAgICAgaGVpZ2h0OiAyOHB4O1xyXG4gICAgICAgIG1hcmdpbjogNnB4IDhweDtcclxuICAgIH1cclxuICAgIHNwYW4ge1xyXG4gICAgICAgIGZvbnQtc2l6ZTogMTZweDtcclxuICAgICAgICB2ZXJ0aWNhbC1hbGlnbjogNzUlO1xyXG4gICAgICAgIGNvbG9yOiB3aGl0ZTtcclxuICAgICAgICBmb250LWZhbWlseTogQXJpYWw7XHJcbiAgICB9XHJcbn1cclxuXHJcbi53cmFwcGVyLS1leGFtcGxlIHtcclxuICAgIHBvc2l0aW9uOiBhYnNvbHV0ZTtcclxuICAgIHotaW5kZXg6IDk5OTk5OTk7XHJcbiAgICB3aWR0aDogMTAwJTtcclxuICAgIGhlaWdodDogY2FsYygxMDAlIC0gNDhweCk7XHJcbiAgICBiYWNrZ3JvdW5kLWNvbG9yOiByZ2JhKDAsIDAsIDAsIDAuNzYpO1xyXG4gICAgb3ZlcmZsb3c6IGhpZGRlbjtcclxuICAgIC50aXRsZSB7XHJcbiAgICAgICAgY29sb3I6IHdoaXRlO1xyXG4gICAgICAgIGZvbnQtc2l6ZTogMjhweDtcclxuICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiByZ2JhKDY4LCA2OCwgNjgsIDAuOTYpO1xyXG4gICAgICAgIGZvbnQtZmFtaWx5OiBBcmlhbCwgSGVsdmV0aWNhLCBzYW5zLXNlcmlmO1xyXG4gICAgICAgIHBhZGRpbmc6IDEwcHggMCAxMHB4IDEwcHg7XHJcbiAgICB9XHJcbiAgICAuZXhhbXBsZS1saXN0IHtcclxuICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiByZ2JhKDY4LCA2OCwgNjgsIDAuOTYpO1xyXG4gICAgICAgIHBhZGRpbmctYm90dG9tOiAxMHB4O1xyXG4gICAgICAgIG1heC1oZWlnaHQ6IDIyMHB4O1xyXG4gICAgICAgIG92ZXJmbG93OiBhdXRvO1xyXG4gICAgICAgIC5leGFtcGxlLWl0ZW0ge1xyXG4gICAgICAgICAgICBkaXNwbGF5OiBpbmxpbmUtYmxvY2s7XHJcbiAgICAgICAgICAgIHRyYW5zaXRpb246IC4yNXMgYWxsO1xyXG4gICAgICAgICAgICBib3JkZXI6IDJweCByZ2JhKDY4LCA2OCwgNjgsIDAuOTYpIHNvbGlkO1xyXG4gICAgICAgICAgICAmOmhvdmVyIHtcclxuICAgICAgICAgICAgICAgIGJvcmRlci1yYWRpdXM6IDhweDtcclxuICAgICAgICAgICAgICAgIGJvcmRlcjogMnB4ICNlZWUgc29saWQ7XHJcbiAgICAgICAgICAgIH1cclxuICAgICAgICAgICAgaW1nIHtcclxuICAgICAgICAgICAgICAgIC8vIGJhY2tncm91bmQtY29sb3I6IHJnYigxNjgsIDE2OCwgMTY4KTtcclxuICAgICAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6ICNlZWU7XHJcbiAgICAgICAgICAgICAgICBtYXgtd2lkdGg6IDEyOHB4OyAvLyBwYWRkaW5nOiAyMHB4O1xyXG4gICAgICAgICAgICAgICAgYm9yZGVyLXJhZGl1czogNXB4O1xyXG4gICAgICAgICAgICAgICAgbWFyZ2luOiAxMHB4O1xyXG4gICAgICAgICAgICAgICAgY3Vyc29yOiBwb2ludGVyO1xyXG4gICAgICAgICAgICB9XHJcbiAgICAgICAgICAgID5wIHtcclxuICAgICAgICAgICAgICAgIHRleHQtYWxpZ246IGNlbnRlcjtcclxuICAgICAgICAgICAgICAgIGNvbG9yOiAjRkZGRkZGO1xyXG4gICAgICAgICAgICAgICAgZm9udC1zaXplOiAyMHB4O1xyXG4gICAgICAgICAgICAgICAgcGFkZGluZzogMCAwIDhweCAwO1xyXG4gICAgICAgICAgICAgICAgZm9udC1mYW1pbHk6IEFyaWFsLCBIZWx2ZXRpY2EsIHNhbnMtc2VyaWY7XHJcbiAgICAgICAgICAgIH1cclxuICAgICAgICB9XHJcbiAgICB9XHJcbiAgICAuZXhhbXBsZS1kZXRhaWwge1xyXG4gICAgICAgIHdpZHRoOiAxMDAlO1xyXG4gICAgICAgIGJhY2tncm91bmQtY29sb3I6IHJnYmEoMzIsIDMyLCAzMiwgMC45Nik7XHJcbiAgICAgICAgZm9udC1mYW1pbHk6IEFyaWFsLCBIZWx2ZXRpY2EsIHNhbnMtc2VyaWY7XHJcbiAgICAgICAgb3ZlcmZsb3c6IGhpZGRlbjtcclxuICAgICAgICBjb2xvcjogI0ZGRjsgLy8gaGVpZ2h0OiAzNjBweDtcclxuICAgICAgICAvLyBiYWNrZ3JvdW5kOiB1cmwoJy4uLy4uLy4uL2Fzc2V0cy9pbWFnZXMvd2VhdGhlci5wbmcnKSBuby1yZXBlYXQgMCAxMDAlO1xyXG4gICAgICAgIC50eHQtLXRpdGxlIHtcclxuICAgICAgICAgICAgcGFkZGluZzogMTBweCAwIDEwcHggMTBweDtcclxuICAgICAgICB9XHJcbiAgICAgICAgLnR4dC0tZGVzY3JpcHRpb24ge1xyXG4gICAgICAgICAgICBwYWRkaW5nOiAxMHB4IDAgMTBweCAxMHB4O1xyXG4gICAgICAgICAgICBmb250LXNpemU6IDIycHg7XHJcbiAgICAgICAgICAgIGNvbG9yOiAjZWVlO1xyXG4gICAgICAgIH1cclxuICAgICAgICAudHh0LS1yZXF1aXJlZCB7XHJcbiAgICAgICAgICAgIHBhZGRpbmc6IDEwcHggMCAxMHB4IDEwcHg7XHJcbiAgICAgICAgICAgIGZvbnQtc2l6ZTogMThweDtcclxuICAgICAgICAgICAgY29sb3I6ICNkOWQ5ZDk7XHJcbiAgICAgICAgICAgICYuYm9sZGVyIHtcclxuICAgICAgICAgICAgICAgIGZvbnQtd2VpZ2h0OiBib2xkZXI7XHJcbiAgICAgICAgICAgICAgICBjb2xvcjogI0U3MUQzNjtcclxuICAgICAgICAgICAgICAgIHBhZGRpbmc6IDEwcHggMCAwIDEwcHg7XHJcbiAgICAgICAgICAgIH1cclxuICAgICAgICAgICAgLmtleXdvcmQge1xyXG4gICAgICAgICAgICAgICAgY29sb3I6ICNFNzFEMzY7XHJcbiAgICAgICAgICAgICAgICBmb250LXdlaWdodDogYm9sZGVyO1xyXG4gICAgICAgICAgICB9XHJcbiAgICAgICAgfVxyXG4gICAgICAgIC50eHQtLWF1dGhvciB7XHJcbiAgICAgICAgICAgIHBvc2l0aW9uOiByZWxhdGl2ZTtcclxuICAgICAgICAgICAgLmF1dGhvci1pbmZvIHtcclxuICAgICAgICAgICAgICAgIHBvc2l0aW9uOiBhYnNvbHV0ZTtcclxuICAgICAgICAgICAgICAgIHJpZ2h0OiA1JTtcclxuICAgICAgICAgICAgICAgIC5hdXRob3Ige1xyXG4gICAgICAgICAgICAgICAgICAgIGZvbnQtd2VpZ2h0OiBib2xkZXI7XHJcbiAgICAgICAgICAgICAgICAgICAgY29sb3I6ICNFNzFEMzY7XHJcbiAgICAgICAgICAgICAgICB9XHJcbiAgICAgICAgICAgIH1cclxuICAgICAgICB9XHJcbiAgICAgICAgZm9vdGVyIHtcclxuICAgICAgICAgICAgLy8gcG9zaXRpb246IGFic29sdXRlO1xyXG4gICAgICAgICAgICAvLyBib3R0b206IDA7XHJcbiAgICAgICAgICAgIC8vIGxlZnQ6IDA7XHJcbiAgICAgICAgICAgIC5idG4ge1xyXG4gICAgICAgICAgICAgICAgbWFyZ2luOiAxMHB4O1xyXG4gICAgICAgICAgICAgICAgb3V0bGluZTogbm9uZTtcclxuICAgICAgICAgICAgICAgIGJvcmRlcjogbm9uZTtcclxuICAgICAgICAgICAgICAgIGJvcmRlci1yYWRpdXM6IDZweDtcclxuICAgICAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6IHZhcigtLWJnLWNvbG9yKTtcclxuICAgICAgICAgICAgICAgIGNvbG9yOiB3aGl0ZTtcclxuICAgICAgICAgICAgICAgIHBhZGRpbmc6IDhweCAxMnB4O1xyXG4gICAgICAgICAgICAgICAgY3Vyc29yOiBwb2ludGVyO1xyXG4gICAgICAgICAgICAgICAgZm9udC1zaXplOiAyNHB4O1xyXG4gICAgICAgICAgICB9XHJcbiAgICAgICAgfVxyXG4gICAgfVxyXG59XHJcblxyXG4uaXNzdGljayB7XHJcbiAgICBkaXNwbGF5OiBub25lO1xyXG59XHJcblxyXG4uZXdlaW1hIHtcclxuICAgIHBvc2l0aW9uOiBmaXhlZDtcclxuICAgIHRvcDogNTAlO1xyXG4gICAgcmlnaHQ6IDMycHg7XHJcbiAgICB6LWluZGV4OiA1O1xyXG4gICAgdHJhbnNmb3JtOiB0cmFuc2xhdGVZKC01MCUpO1xyXG4gICAgLndyYXBwZXItLXFyY29kZSB7XHJcbiAgICAgICAgcG9zaXRpb246IGZpeGVkO1xyXG4gICAgICAgIHJpZ2h0OiA0NnB4O1xyXG4gICAgICAgIHRvcDogNTAlO1xyXG4gICAgICAgIHRyYW5zZm9ybTogdHJhbnNsYXRlWSgtNTAlKTtcclxuICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiByZ2JhKDI1NSwgMjU1LCAyNTUsIDAuOTYpO1xyXG4gICAgICAgIGJvcmRlci1yYWRpdXM6IDVweDtcclxuICAgICAgICB6LWluZGV4OiAxMDk5O1xyXG4gICAgICAgIHBhZGRpbmc6IDEwcHg7XHJcbiAgICAgICAgYnV0dG9uIHtcclxuICAgICAgICAgICAgb3V0bGluZTogbm9uZTtcclxuICAgICAgICAgICAgYm9yZGVyOiBub25lO1xyXG4gICAgICAgICAgICBtYXJnaW4tdG9wOiA2cHg7XHJcbiAgICAgICAgICAgIHBhZGRpbmc6IDRweCAxMnB4O1xyXG4gICAgICAgICAgICBmb250LWZhbWlseTogQXJpYWw7XHJcbiAgICAgICAgICAgIGNvbG9yOiB3aGl0ZTtcclxuICAgICAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogb3JhbmdlO1xyXG4gICAgICAgICAgICBib3JkZXItcmFkaXVzOiA0cHg7XHJcbiAgICAgICAgICAgIGN1cnNvcjogcG9pbnRlcjtcclxuICAgICAgICB9XHJcbiAgICAgICAgLnRpcC0tY29weSB7XHJcbiAgICAgICAgICAgIGZvbnQtc2l6ZTogMTJweDtcclxuICAgICAgICAgICAgbWFyZ2luLWxlZnQ6IDRweDtcclxuICAgICAgICAgICAgY29sb3I6ICMzYWM1Njk7XHJcbiAgICAgICAgICAgIGZvbnQtd2VpZ2h0OiBib2xkZXI7XHJcbiAgICAgICAgICAgIGZvbnQtZmFtaWx5OiBBcmlhbCwgSGVsdmV0aWNhLCBzYW5zLXNlcmlmO1xyXG4gICAgICAgIH1cclxuICAgIH1cclxufVxyXG5cclxuLmZsb2F0LWJ0biB7XHJcbiAgICBkaXNwbGF5OiBub25lO1xyXG59XHJcblxyXG5AbWVkaWEgb25seSBzY3JlZW4gYW5kIChtaW4taGVpZ2h0OjMyMHB4KSBhbmQgKG1heC1oZWlnaHQ6NzY3cHgpIHtcclxuICAgIC53cmFwcGVyIHtcclxuICAgICAgICAudG9wLW5hdiB7XHJcbiAgICAgICAgICAgIGRpc3BsYXk6IG5vbmU7XHJcbiAgICAgICAgfVxyXG4gICAgICAgIC5saXN0LS1idG4ge1xyXG4gICAgICAgICAgICBzcGFuOm5vdCgubWItc2hvdykge1xyXG4gICAgICAgICAgICAgICAgZGlzcGxheTogbm9uZTtcclxuICAgICAgICAgICAgfVxyXG4gICAgICAgIH1cclxuICAgICAgICAuZHJvcGRvd24tLWxpc3Qge1xyXG4gICAgICAgICAgICBsaSB7XHJcbiAgICAgICAgICAgICAgICAmLnBjLWhpZGUge1xyXG4gICAgICAgICAgICAgICAgICAgIGRpc3BsYXk6IGJsb2NrO1xyXG4gICAgICAgICAgICAgICAgfVxyXG4gICAgICAgICAgICAgICAgYSB7XHJcbiAgICAgICAgICAgICAgICAgICAgdGV4dC1kZWNvcmF0aW9uOiBub25lO1xyXG4gICAgICAgICAgICAgICAgICAgIGRpc3BsYXk6IGJsb2NrO1xyXG4gICAgICAgICAgICAgICAgICAgIHdpZHRoOiAxMDAlO1xyXG4gICAgICAgICAgICAgICAgICAgIGhlaWdodDogMTAwJTtcclxuICAgICAgICAgICAgICAgIH1cclxuICAgICAgICAgICAgfVxyXG4gICAgICAgIH1cclxuICAgIH1cclxuICAgIC53cmFwcGVyLS1leGFtcGxlIHtcclxuICAgICAgICAuZXhhbXBsZS1saXN0IHtcclxuICAgICAgICAgICAgbWF4LWhlaWdodDogODBweDtcclxuICAgICAgICAgICAgb3ZlcmZsb3cteTogc2Nyb2xsO1xyXG4gICAgICAgICAgICBwYWRkaW5nLWJvdHRvbTogMTBweDtcclxuICAgICAgICAgICAgLmV4YW1wbGUtaXRlbSB7XHJcbiAgICAgICAgICAgICAgICBpbWcge1xyXG4gICAgICAgICAgICAgICAgICAgIGRpc3BsYXk6IGJsb2NrO1xyXG4gICAgICAgICAgICAgICAgICAgIG1heC13aWR0aDogNjBweDtcclxuICAgICAgICAgICAgICAgICAgICBib3JkZXItcmFkaXVzOiA1cHg7XHJcbiAgICAgICAgICAgICAgICAgICAgbWFyZ2luOiA1cHg7XHJcbiAgICAgICAgICAgICAgICAgICAgY3Vyc29yOiBwb2ludGVyO1xyXG4gICAgICAgICAgICAgICAgfVxyXG4gICAgICAgICAgICAgICAgPnAge1xyXG4gICAgICAgICAgICAgICAgICAgIGRpc3BsYXk6IG5vbmU7XHJcbiAgICAgICAgICAgICAgICB9XHJcbiAgICAgICAgICAgIH1cclxuICAgICAgICB9XHJcbiAgICAgICAgLmV4YW1wbGUtZGV0YWlsIHtcclxuICAgICAgICAgICAgbWF4LWhlaWdodDogMTIwcHg7XHJcbiAgICAgICAgICAgIHdpZHRoOiAxMDAlO1xyXG4gICAgICAgICAgICBvdmVyZmxvdy15OiBzY3JvbGw7XHJcbiAgICAgICAgICAgIGZvbnQtc2l6ZTogMTJweDtcclxuICAgICAgICAgICAgLnR4dC0tdGl0bGUge1xyXG4gICAgICAgICAgICAgICAgZm9udC1zaXplOiAxNnB4O1xyXG4gICAgICAgICAgICAgICAgcGFkZGluZzogNXB4IDAgNXB4IDVweDtcclxuICAgICAgICAgICAgfVxyXG4gICAgICAgICAgICAudHh0LS1kZXNjcmlwdGlvbiB7XHJcbiAgICAgICAgICAgICAgICBwYWRkaW5nOiA1cHggMCA1cHggNXB4O1xyXG4gICAgICAgICAgICAgICAgZm9udC1zaXplOiAxMnB4O1xyXG4gICAgICAgICAgICB9XHJcbiAgICAgICAgICAgIC50eHQtLXJlcXVpcmVkIHtcclxuICAgICAgICAgICAgICAgIHBhZGRpbmc6IDVweCAwIDVweCA1cHg7XHJcbiAgICAgICAgICAgICAgICAmLmJvbGRlciB7XHJcbiAgICAgICAgICAgICAgICAgICAgcGFkZGluZzogNXB4IDAgNXB4IDVweDtcclxuICAgICAgICAgICAgICAgIH1cclxuICAgICAgICAgICAgfVxyXG4gICAgICAgIH1cclxuICAgIH1cclxuICAgIC5mbG9hdC1idG4ge1xyXG4gICAgICAgIHBvc2l0aW9uOiBmaXhlZDtcclxuICAgICAgICBkaXNwbGF5OiBibG9jaztcclxuICAgICAgICB0b3A6IDQ4cHg7XHJcbiAgICAgICAgcmlnaHQ6IDIwcHg7XHJcbiAgICAgICAgei1pbmRleDogMTtcclxuICAgICAgICAuYnRuIHtcclxuICAgICAgICAgICAgaGVpZ2h0OiAzNnB4O1xyXG4gICAgICAgICAgICBib3JkZXI6IDA7XHJcbiAgICAgICAgICAgIG91dGxpbmU6IG5vbmU7XHJcbiAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6IHZhcigtLWJsb2NrQ29kZUJ0bi1jb2xvcik7XHJcbiAgICAgICAgICAgIGNvbG9yOiAjZmZmZmZmO1xyXG4gICAgICAgICAgICBib3JkZXItcmFkaXVzOiAwIDAgNTAlIDUwJTtcclxuICAgICAgICAgICAgY3Vyc29yOiBwb2ludGVyO1xyXG4gICAgICAgICAgICBpbWcge1xyXG4gICAgICAgICAgICAgICAgdXNlci1zZWxlY3Q6IG5vbmU7XHJcbiAgICAgICAgICAgICAgICAtd2Via2l0LXVzZXItZHJhZzogbm9uZTtcclxuICAgICAgICAgICAgfVxyXG4gICAgICAgICAgICAmLmZvY3VzIHtcclxuICAgICAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6IHZhcigtLWJsb2NrQ29kZUJ0bkZvY3VzLWNvbG9yKTtcclxuICAgICAgICAgICAgfVxyXG4gICAgICAgICAgICAmLmJsb2NrbHksXHJcbiAgICAgICAgICAgICYuY29kZSB7XHJcbiAgICAgICAgICAgICAgICB0cmFuc2l0aW9uOiAuMzVzIGFsbCBlYXNlO1xyXG4gICAgICAgICAgICAgICAgJi5hY3RpdmUge1xyXG4gICAgICAgICAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6IHZhcigtLWJsb2NrQ29kZUJ0bkZvY3VzLWNvbG9yKTtcclxuICAgICAgICAgICAgICAgIH1cclxuICAgICAgICAgICAgfVxyXG4gICAgICAgICAgICBpbWcsXHJcbiAgICAgICAgICAgIHNwYW4ge1xyXG4gICAgICAgICAgICAgICAgZGlzcGxheTogYmxvY2s7XHJcbiAgICAgICAgICAgICAgICBmbG9hdDogbGVmdDtcclxuICAgICAgICAgICAgICAgIHVzZXItc2VsZWN0OiBub25lO1xyXG4gICAgICAgICAgICAgICAgLXdlYmtpdC11c2VyLWRyYWc6IG5vbmU7XHJcbiAgICAgICAgICAgIH1cclxuICAgICAgICAgICAgaW1nIHtcclxuICAgICAgICAgICAgICAgIHdpZHRoOiAyOHB4O1xyXG4gICAgICAgICAgICAgICAgaGVpZ2h0OiAyOHB4O1xyXG4gICAgICAgICAgICAgICAgbWFyZ2luOiA0cHggOHB4O1xyXG4gICAgICAgICAgICB9XHJcbiAgICAgICAgICAgIHNwYW4ge1xyXG4gICAgICAgICAgICAgICAgZm9udC1zaXplOiAxNnB4O1xyXG4gICAgICAgICAgICAgICAgaGVpZ2h0OiAzNnB4O1xyXG4gICAgICAgICAgICAgICAgbGluZS1oZWlnaHQ6IDM2cHg7XHJcbiAgICAgICAgICAgIH1cclxuICAgICAgICB9XHJcbiAgICB9XHJcbiAgICAuZXdlaW1hIHtcclxuICAgICAgICBwb3NpdGlvbjogZml4ZWQ7XHJcbiAgICAgICAgdG9wOiA2N3B4O1xyXG4gICAgICAgIHJpZ2h0OiAxNzhweDtcclxuICAgICAgICAud3JhcHBlci0tcXJjb2RlIHtcclxuICAgICAgICAgICAgcG9zaXRpb246IGZpeGVkO1xyXG4gICAgICAgICAgICB0b3A6IDE0MnB4O1xyXG4gICAgICAgICAgICByaWdodDogLTUzcHg7XHJcbiAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6IHJnYmEoMjU1LCAyNTUsIDI1NSwgMC45Nik7XHJcbiAgICAgICAgICAgIGJvcmRlci1yYWRpdXM6IDVweDtcclxuICAgICAgICAgICAgei1pbmRleDogMTA5OTtcclxuICAgICAgICAgICAgcGFkZGluZzogMTBweDtcclxuICAgICAgICB9XHJcbiAgICB9XHJcbiAgICAuaXNzdGljayB7XHJcbiAgICAgICAgZGlzcGxheTogbm9uZSAhaW1wb3J0YW50O1xyXG4gICAgfVxyXG59XHJcblxyXG5AbWVkaWEgb25seSBzY3JlZW4gYW5kIChtaW4td2lkdGg6MTAyNHB4KSB7XHJcbiAgICAud3JhcHBlciB7XHJcbiAgICAgICAgLnRvcC1uYXYge1xyXG4gICAgICAgICAgICBkaXNwbGF5OiBibG9jaztcclxuICAgICAgICB9XHJcbiAgICAgICAgLmRyb3Bkb3duLS1saXN0IHtcclxuICAgICAgICAgICAgbGkge1xyXG4gICAgICAgICAgICAgICAgYSB7XHJcbiAgICAgICAgICAgICAgICAgICAgdGV4dC1kZWNvcmF0aW9uOiBub25lO1xyXG4gICAgICAgICAgICAgICAgICAgIGRpc3BsYXk6IGJsb2NrO1xyXG4gICAgICAgICAgICAgICAgICAgIHdpZHRoOiAxMDAlO1xyXG4gICAgICAgICAgICAgICAgICAgIGhlaWdodDogMTAwJTtcclxuICAgICAgICAgICAgICAgIH1cclxuICAgICAgICAgICAgfVxyXG4gICAgICAgIH1cclxuICAgIH1cclxuICAgIC5mbG9hdC1idG4ge1xyXG4gICAgICAgIGRpc3BsYXk6IG5vbmU7XHJcbiAgICB9XHJcbn1cclxuXHJcbi5hbGVydF9wb3NpdGlvbntcclxuICAgIHBvc2l0aW9uOiBmaXhlZDs7XHJcbiAgICB6LWluZGV4OiAxMDA7XHJcbiAgICB0b3A6MzglO1xyXG4gICAgcmlnaHQ6MDtcclxuICAgIG1heC13aWR0aDogMzAwcHg7XHJcbiAgICAvLyBtaW4td2lkdGg6IDE1MHB4O1xyXG4gICAgbWF4LWhlaWdodDogMzAwcHg7XHJcbiAgICAvLyBtaW4taGVpZ2h0OiAxMDBweDtcclxuICAgIGJhY2tncm91bmQtY29sb3I6dmFyKC0tYmctY29sb3IpOyBcclxuICAgIGJvcmRlci1yYWRpdXM6MTBweDsgXHJcbiAgICBib3gtc2hhZG93OiAyMHB4O1xyXG4gICAgb3BhY2l0eTogMC44NTtcclxuICAgIG92ZXJmbG93OiBoaWRkZW47XHJcbn0iXX0= */"

/***/ }),

/***/ "./src/app/core/header/header.component.ts":
/*!*************************************************!*\
  !*** ./src/app/core/header/header.component.ts ***!
  \*************************************************/
/*! exports provided: HeaderComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "HeaderComponent", function() { return HeaderComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _animations__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../../animations */ "./src/app/animations/index.ts");
/* harmony import */ var src_app_services_services_module__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! src/app/services/services.module */ "./src/app/services/services.module.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
/* harmony import */ var src_app_shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! src/app/shared/mask/mask.component */ "./src/app/shared/mask/mask.component.ts");
/* harmony import */ var _ngx_translate_core__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @ngx-translate/core */ "./node_modules/@ngx-translate/core/fesm5/ngx-translate-core.js");
/* harmony import */ var sweetalert__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! sweetalert */ "./node_modules/sweetalert/dist/sweetalert.min.js");
/* harmony import */ var sweetalert__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(sweetalert__WEBPACK_IMPORTED_MODULE_6__);
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};







var HeaderComponent = /** @class */ (function () {
    function HeaderComponent(globalOperatorSrv, uploadSrv, codeEditorSrv, codeMakerSrv, storeSrv, translate) {
        this.globalOperatorSrv = globalOperatorSrv;
        this.uploadSrv = uploadSrv;
        this.codeEditorSrv = codeEditorSrv;
        this.codeMakerSrv = codeMakerSrv;
        this.storeSrv = storeSrv;
        this.translate = translate;
        this.dropdownState = 'hide';
        this.copyTip = '';
        this.exampleVisibility = false;
        this.exampleDetail = null;
        this.isShowQRcode = false;
        this.exampleList = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_3__["EXAMPLES"];
        this.loddingMode = false;
        this.version = '';
    }
    HeaderComponent.prototype.ngOnInit = function () {
        var _this_1 = this;
        this.version = this.storeSrv.VERSION;
        this.mode$ = this.globalOperatorSrv.getMode();
        this.projectName$ = this.storeSrv.getProjectName();
        this.remoteKey$ = this.storeSrv.getRemoteKey();
        this.erweima$ = this.storeSrv.showerweima();
        this.storeSrv.setLoddingMode().subscribe(function (mode) {
            _this_1.loddingMode = mode;
        });
        this.storeSrv.getType().subscribe(function (res) {
            if (res === 'stick') {
                _this_1.stick = true;
            }
            else if (res === 'core') {
                _this_1.stick = false;
            }
            else if (res === 'stick-C') {
                _this_1.stick = true;
            }
        });
        // 打开更新模态框
        var _this = this;
        if (localStorage.getItem('version')) {
            if (localStorage.getItem('version') == this.version) {
                if (this.storeSrv.apiKey.value === '') {
                    this.openSettingPanel(null);
                }
                return;
            }
            else {
                var modal = this.globalOperatorSrv.createMaskModal(src_app_shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_4__["MaskComponent"]);
                modal.instance.createDynamicComponent(src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_3__["DYNAMIC_COMPONENT_TYPE"].UPDATA_PANEL);
                localStorage.setItem('version', this.version);
            }
        }
        else {
            var modal = this.globalOperatorSrv.createMaskModal(src_app_shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_4__["MaskComponent"]);
            modal.instance.createDynamicComponent(src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_3__["DYNAMIC_COMPONENT_TYPE"].UPDATA_PANEL);
            localStorage.setItem('version', this.version);
        }
    };
    HeaderComponent.prototype.openDropdownList = function () {
        if (this.dropdownState === 'show')
            return this.dropdownState = 'hide';
        this.dropdownState = 'show';
    };
    HeaderComponent.prototype.closeDropdownList = function (ev) {
        this.dropdownState = 'hide';
    };
    // python和blockly切换
    HeaderComponent.prototype.setMode = function (mode) {
        var _this = this;
        if (mode === src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_3__["MODE"].CODE) {
            _this.globalOperatorSrv.setMode(mode);
            _this.codeEditorSrv.updateWorkspaceValue();
        }
        else {
            // 此处是应该生成的代码
            // 判断是否产生变化  后续可保存此值以方便后用  _this.codeEditorSrv.getWorkspaceValue()应生成的字符串   this.codeEditorSrv.workspace.getValue()当前区域内代码字符串
            if (_this.codeEditorSrv.getWorkspaceValue() == this.codeEditorSrv.workspace.getValue()) {
                _this.globalOperatorSrv.setMode(mode);
                var _timeout_1 = setTimeout(function () {
                    var e = document.createEvent("Event");
                    e.initEvent("resize", true, true);
                    window.dispatchEvent(e);
                    clearTimeout(_timeout_1);
                });
            }
            else {
                // console.log(this.codeEditorSrv.workspace.getValue())
                if (_this.globalOperatorSrv.getMode().source["_value"] == 'blockly') {
                    return false;
                }
                else {
                    this.globalOperatorSrv.setUIVisibility(true);
                    // 提示切换回blockly则失效
                    sweetalert__WEBPACK_IMPORTED_MODULE_6___default()('Blockly does not retain your newly created python. Are you sure you want to return it?', {
                        icon: 'warning',
                        dangerMode: true,
                        closeOnClickOutside: false,
                        buttons: { confirm: true, cancel: true },
                    }).then(function (value) {
                        if (value) {
                            _this.globalOperatorSrv.setMode(mode);
                            var _timeout_2 = setTimeout(function () {
                                var e = document.createEvent("Event");
                                e.initEvent("resize", true, true);
                                window.dispatchEvent(e);
                                clearTimeout(_timeout_2);
                            });
                        }
                        else {
                            return false;
                        }
                    });
                }
            }
        }
    };
    HeaderComponent.prototype.setMBMode = function (mode) {
        var _this_1 = this;
        setTimeout(function () {
            _this_1.globalOperatorSrv.setSelectedUnit(null);
            _this_1.globalOperatorSrv.setSelectedComponent(null);
        }, 1);
        this.globalOperatorSrv.setMode(mode);
        this.storeSrv.uieditorMode.next(true);
        if (mode === src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_3__["MODE"].CODE) {
            this.codeEditorSrv.updateWorkspaceValue();
        }
    };
    HeaderComponent.prototype.setuieditorMode = function (mode) {
        this.globalOperatorSrv.setMode(mode);
        this.storeSrv.uieditorMode.next(false);
    };
    HeaderComponent.prototype.execCode = function () {
        var _this_1 = this;
        var code = '';
        if (this.globalOperatorSrv.mode.value === src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_3__["MODE"].CODE) {
            code = this.codeEditorSrv.workspace.getValue();
        }
        else {
            code = this.codeMakerSrv.makeCode();
        }
        if (this.storeSrv.apiKey.value === '') {
            this.translate.get('KEY_ISNULL_ERROR').subscribe(function (res) {
                _this_1.globalOperatorSrv.createMessageBox().instance.error(res);
            });
            return;
        }
        if (window['Blockly']['Remotes'].length === 0) {
            this.uploadSrv.execCode(code).subscribe(function (data) {
                _this_1.translate.get('EXECUTCODE_SUCCESS').subscribe(function (res) {
                    _this_1.globalOperatorSrv.createMessageBox().instance.success(res);
                });
            }, function (err) {
                _this_1.translate.get('EXECUTECODE_ERROR').subscribe(function (res) {
                    _this_1.globalOperatorSrv.createMessageBox().instance.error(res);
                });
            });
            return;
        }
        else {
            var dataObj = [];
            for (var j = 0; j < window["Blockly"].Remotes.length; j++) {
                dataObj.push({
                    name: window["Blockly"].Remotes[j].name,
                    event: window["Blockly"].Remotes[j].event,
                    type: window["Blockly"].Remotes[j].type,
                    icon: window["Blockly"].Remotes[j].icon || null
                });
            }
            var remoteData = JSON.stringify({
                id: this.storeSrv.apiKey.value,
                data: dataObj
            });
            this.uploadSrv.getRemoteKey(remoteData).subscribe(function (res) {
                window['Blockly'].REMOTE_KEY = res.data;
                _this_1.storeSrv.setRemoteKey("http://flow-remote.m5stack.com/?remote=" + res.data);
                _this_1.uploadSrv.execCode(_this_1.codeMakerSrv.makeCode()).subscribe(function (data) {
                    _this_1.translate.get('EXECUTCODE_SUCCESS').subscribe(function (res) {
                        _this_1.globalOperatorSrv.createMessageBox().instance.success(res);
                    });
                }, function (err) {
                    _this_1.translate.get('APIKRY_ERROR').subscribe(function (res) {
                        _this_1.globalOperatorSrv.createMessageBox().instance.error(res);
                    });
                });
            });
        }
    };
    HeaderComponent.prototype.openSettingPanel = function (ev) {
        if (ev !== null) {
            ev.stopPropagation();
            ev.preventDefault();
            this.dropdownState = 'hide';
        }
        var modal = this.globalOperatorSrv.createMaskModal(src_app_shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_4__["MaskComponent"]);
        modal.instance.createDynamicComponent(src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_3__["DYNAMIC_COMPONENT_TYPE"].SETTING_PANEL);
    };
    HeaderComponent.prototype.openResourceManager = function () {
        var modal = this.globalOperatorSrv.createMaskModal(src_app_shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_4__["MaskComponent"]);
        modal.instance.createDynamicComponent(src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_3__["DYNAMIC_COMPONENT_TYPE"].RESOURCE_MANAGER);
    };
    HeaderComponent.prototype.changeProjectName = function (ev) {
        this.storeSrv.setProjectName(ev.target.value);
    };
    HeaderComponent.prototype.uploadCode = function () {
        var _this_1 = this;
        this.globalOperatorSrv.getCodeLock().subscribe(function (res) {
            if (!res) {
                _this_1.codeEditorSrv.updateWorkspaceValue();
            }
        });
        if (this.storeSrv.apiKey.value === '') {
            this.translate.get('KEY_ISNULL_ERROR').subscribe(function (res) {
                _this_1.globalOperatorSrv.createMessageBox().instance.error(res);
            });
            return;
        }
        if (this.storeSrv.projectName.value === '') {
            this.translate.get('NAME_ISNULL_ERROR').subscribe(function (res) {
                _this_1.globalOperatorSrv.createMessageBox().instance.error(res);
            });
            return;
        }
        var code = '';
        if (this.globalOperatorSrv.mode.value === src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_3__["MODE"].CODE) {
            code = this.codeEditorSrv.workspace.getValue();
        }
        else {
            // code = this.codeEditorSrv.workspace.getValue();
            code = this.codeMakerSrv.makeCode();
        }
        this.uploadSrv.beforeUploadCode().subscribe(function (res) {
            _this_1.translate.get('UPLOADING_LOADING').subscribe(function (res) {
                _this_1.globalOperatorSrv.createMessageBox().instance.loading(res);
            });
            _this_1.uploadSrv.uploadCode(code).subscribe(function (data) {
                _this_1.translate.get('UPLOADING_SUCCESS').subscribe(function (res) {
                    _this_1.globalOperatorSrv.createMessageBox().instance.error(res);
                });
                _this_1.uploadSrv.saveBlocklyFile(_this_1.globalOperatorSrv.saveM5F()).subscribe(function (res) {
                    _this_1.uploadSrv.afterUploadCode().subscribe();
                });
            }, function (err) {
                _this_1.translate.get('EXECUTECODE_ERROR').subscribe(function (res) {
                    _this_1.globalOperatorSrv.createMessageBox().instance.error(res);
                });
            });
        });
    };
    // 保存m5
    HeaderComponent.prototype.saveM5F = function () {
        var data = this.globalOperatorSrv.saveM5F();
        window['doSave'](JSON.stringify(data), 'text/latex', this.storeSrv.projectName.value + '.m5f');
    };
    // 打开m5
    HeaderComponent.prototype.openM5F = function () {
        var _this_1 = this;
        var fileDom = document.getElementById('__openM5FBox');
        fileDom.click();
        fileDom.onchange = function (ev) {
            if (ev.target['files'].length === 0)
                return;
            var reader = new FileReader();
            reader.readAsText(ev.target['files'][0], "utf8");
            reader.onload = function (e) {
                var dataStr = e.target['result'];
                var type = JSON.parse(dataStr).type ? JSON.parse(dataStr).type : 'core';
                if (_this_1.storeSrv.getType().source['_value'] !== type) {
                    sweetalert__WEBPACK_IMPORTED_MODULE_6___default()("Please open this file in " + type + " mode", {
                        icon: 'info',
                        dangerMode: true,
                        closeOnClickOutside: false,
                        buttons: { confirm: true },
                    }).then(function (value) {
                        return false;
                    });
                    return false;
                }
                else {
                    try {
                        var data = JSON.parse(dataStr);
                        _this_1.globalOperatorSrv.openM5F(data);
                        _this_1.storeSrv.setProjectName(ev.target['files'][0].name.split(ev.target['files'][0].name.match(/.m5f/g)[0])[0]);
                    }
                    catch (err) {
                        console.log(err);
                        try {
                            var data = JSON.parse(dataStr);
                            _this_1.globalOperatorSrv.openOldM5F(data);
                            _this_1.storeSrv.setProjectName(ev.target['files'][0].name.split(ev.target['files'][0].name.match(/.m5f/g)[0])[0]);
                        }
                        catch (err) {
                            console.log(err);
                        }
                    }
                    finally {
                        ev.target['value'] = '';
                    }
                }
            };
        };
    };
    HeaderComponent.prototype.undo = function () {
        this.globalOperatorSrv.undo();
    };
    HeaderComponent.prototype.redo = function () {
        this.globalOperatorSrv.redo();
    };
    // 二维码
    HeaderComponent.prototype.showQRCode = function () {
        var _this_1 = this;
        if (this.storeSrv.remoteKey.value === '') {
            this.translate.get('REMOTE_ERROR').subscribe(function (res) {
                _this_1.globalOperatorSrv.createMessageBox().instance.error(res);
            });
            return;
        }
        if (this.isShowQRcode)
            return this.isShowQRcode = false;
        this.isShowQRcode = true;
    };
    HeaderComponent.prototype.copyQRcodeUrl = function () {
        var _this_1 = this;
        this.copyTip = 'Copied';
        new window['ClipboardJS']('.btn-clipboard', {
            text: function () {
                return this.storeSrv.remoteKey.value;
            }.bind(this)
        });
        var timer = setTimeout(function () {
            _this_1.copyTip = '';
            clearTimeout(timer);
        }, 3000);
    };
    HeaderComponent.prototype.showExample = function () {
        if (this.exampleVisibility) {
            this.exampleDetail = null;
            this.exampleVisibility = false;
            return;
        }
        this.exampleVisibility = true;
    };
    HeaderComponent.prototype.hideExample = function () {
        this.exampleDetail = null;
        this.exampleVisibility = false;
    };
    HeaderComponent.prototype.showExampleDetail = function (ev, example) {
        ev.stopPropagation();
        ev.preventDefault();
        this.exampleDetail = example;
    };
    HeaderComponent.prototype.runExample = function (ev) {
        var _this_1 = this;
        ev.stopPropagation();
        ev.preventDefault();
        if (this.exampleDetail === null)
            return;
        this.storeSrv.loddingMODE.next(false);
        this.uploadSrv.loadExample(this.exampleDetail.file).subscribe(function (res) {
            var data = res;
            try {
                _this_1.globalOperatorSrv.openM5F(data);
                _this_1.storeSrv.setProjectName(_this_1.exampleDetail.title);
            }
            catch (err) {
                try {
                    _this_1.globalOperatorSrv.openOldM5F(data);
                    _this_1.storeSrv.setProjectName(_this_1.exampleDetail.title);
                }
                catch (err) {
                }
            }
            finally {
                _this_1.exampleDetail = null;
                _this_1.exampleVisibility = false;
            }
        }, function (err) {
            _this_1.storeSrv.loddingMODE.next(false);
        }, function () {
            _this_1.storeSrv.loddingMODE.next(false);
        });
    };
    HeaderComponent.prototype.stopPropagation = function (ev) {
        ev.stopPropagation();
        ev.preventDefault();
    };
    // 打开更新历史模态框
    HeaderComponent.prototype.openUpdateRecord = function (ev) {
        var modal = this.globalOperatorSrv.createMaskModal(src_app_shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_4__["MaskComponent"]);
        modal.instance.createDynamicComponent(src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_3__["DYNAMIC_COMPONENT_TYPE"].UPDATA_PANEL);
    };
    HeaderComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-header',
            template: __webpack_require__(/*! ./header.component.html */ "./src/app/core/header/header.component.html"),
            styles: [__webpack_require__(/*! ./header.component.scss */ "./src/app/core/header/header.component.scss")],
            animations: [_animations__WEBPACK_IMPORTED_MODULE_1__["slideDownAnimation"]]
        }),
        __metadata("design:paramtypes", [src_app_services_services_module__WEBPACK_IMPORTED_MODULE_2__["GlobalOperatorService"],
            src_app_services_services_module__WEBPACK_IMPORTED_MODULE_2__["UploadService"],
            src_app_services_services_module__WEBPACK_IMPORTED_MODULE_2__["CodeEditorService"],
            src_app_services_services_module__WEBPACK_IMPORTED_MODULE_2__["CodeMakerService"],
            src_app_services_services_module__WEBPACK_IMPORTED_MODULE_2__["StoreService"],
            _ngx_translate_core__WEBPACK_IMPORTED_MODULE_5__["TranslateService"]])
    ], HeaderComponent);
    return HeaderComponent;
}());



/***/ }),

/***/ "./src/app/core/message/message.html":
/*!*******************************************!*\
  !*** ./src/app/core/message/message.html ***!
  \*******************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"panel\" appHighlight [@alertAnim]=\"exampleVisibility ? 'show':'hide'\">\r\n  <div class=\"panel_div\">\r\n    \r\n    <div class=\"alert_p main\">\r\n        <span class=\"hide\" (click)=\"hide_alert()\">×</span>\r\n        <div class=\"div_p\">\r\n          <p>{{Alert_Blockly}}</p>\r\n          <p>{{Alert_Blockly}}</p>\r\n    </div>\r\n    </div>\r\n  </div>\r\n</div>"

/***/ }),

/***/ "./src/app/core/message/message.scss":
/*!*******************************************!*\
  !*** ./src/app/core/message/message.scss ***!
  \*******************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "@charset \"UTF-8\";\n.panel {\n  position: relative;\n  z-index: 9999999999999999999999;\n  box-shadow: 10px;\n  background-color: var(--bg-color);\n  background-size: 100% 100%; }\n.alert_p {\n  font-size: 18px !important;\n  display: flex;\n  justify-content: center; }\n.panel_div, .alert_p {\n  opacity: 1; }\n.alert_p {\n  font-size: 22px;\n  color: red;\n  padding: 8px;\n  border-radius: 10px; }\n* {\n  margin: 0;\n  padding: 0; }\n.main {\n  max-width: 300px;\n  min-width: 150px;\n  max-height: 300px;\n  min-height: 100px;\n  display: inline-block;\n  color: #ffffff;\n  line-height: 28px;\n  position: relative;\n  padding: 10px;\n  -webkit-border-radius: 5px;\n  -moz-border-radius: 5px;\n  overflow: hidden; }\n/*左三角*/\n.main:before {\n  content: ' ';\n  border-top: 8px solid transparent;\n  border-bottom: 8px solid transparent;\n  border-right: 12px solid var(--bg-color);\n  position: absolute;\n  top: 15px;\n  left: -12px; }\n/*右三角*/\n.main > p {\n  min-width: 100%;\n  max-width: 100%;\n  min-height: 100%;\n  max-height: 100%;\n  color: #ffffff;\n  font-weight: 10; }\n.hide {\n  position: relative;\n  font-size: 20px;\n  right: -95%;\n  top: -14px;\n  cursor: pointer;\n  color: #ffffff; }\n.panel_div {\n  position: relative; }\n.div_p {\n  position: relative;\n  top: -10px;\n  overflow: hidden;\n  max-height: 112px; }\n.div_p > p {\n  max-height: 56px;\n  overflow: hidden; }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvY29yZS9tZXNzYWdlL21lc3NhZ2Uuc2NzcyIsInNyYy9hcHAvY29yZS9tZXNzYWdlL1o6XFx3b3Jrc3BhY2VcXG15X3pyZW5kZXJcXGZsb3cvc3JjXFxhcHBcXGNvcmVcXG1lc3NhZ2VcXG1lc3NhZ2Uuc2NzcyJdLCJuYW1lcyI6W10sIm1hcHBpbmdzIjoiQUFBQSxpQkFBaUI7QUNBakI7RUFDSSxtQkFBa0I7RUFDbEIsZ0NBQStCO0VBQy9CLGlCQUFnQjtFQUdqQixrQ0FBaUM7RUFDcEMsMkJBQTBCLEVBRXpCO0FBQ0Q7RUFDSSwyQkFBMEI7RUFDMUIsY0FBYTtFQUNiLHdCQUF1QixFQUUxQjtBQUNEO0VBQ0ksV0FBVSxFQUNiO0FBRUQ7RUFDSSxnQkFBZTtFQUFDLFdBQVU7RUFDMUIsYUFBWTtFQUNaLG9CQUFtQixFQUN0QjtBQUVEO0VBQ0ksVUFBUztFQUNULFdBQVUsRUFDVjtBQUNEO0VBQ0MsaUJBQWU7RUFDZixpQkFBZ0I7RUFDaEIsa0JBQWlCO0VBQ2pCLGtCQUFpQjtFQUNqQixzQkFBcUI7RUFDckIsZUFBYztFQUNkLGtCQUFpQjtFQUdqQixtQkFBa0I7RUFDbEIsY0FBYTtFQUNiLDJCQUF5QjtFQUN6Qix3QkFBc0I7RUFDdEIsaUJBQWdCLEVBQ2hCO0FBQ0QsT0FBQTtBQUNBO0VBQ0MsYUFBWTtFQUNaLGtDQUFpQztFQUNqQyxxQ0FBb0M7RUFFcEMseUNBQXdDO0VBR3hDLG1CQUFrQjtFQUNsQixVQUFTO0VBQ1QsWUFBVyxFQUNYO0FBQ0QsT0FBQTtBQVVBO0VBQ0gsZ0JBQWU7RUFDZixnQkFBZTtFQUNmLGlCQUFnQjtFQUNoQixpQkFBZ0I7RUFDaEIsZUFBYztFQUNkLGdCQUFlLEVBRVg7QUFFRDtFQUNJLG1CQUFrQjtFQUNsQixnQkFBZTtFQUNmLFlBQVc7RUFDWCxXQUFVO0VBQ1YsZ0JBQWU7RUFDZixlQUNKLEVBQUM7QUFDRDtFQUNILG1CQUFrQixFQUdkO0FBRUQ7RUFDSSxtQkFBa0I7RUFDbEIsV0FBVTtFQUNWLGlCQUFnQjtFQUNoQixrQkFBa0IsRUFDckI7QUFDRDtFQUNJLGlCQUFnQjtFQUNoQixpQkFBZ0IsRUFDbkIiLCJmaWxlIjoic3JjL2FwcC9jb3JlL21lc3NhZ2UvbWVzc2FnZS5zY3NzIiwic291cmNlc0NvbnRlbnQiOlsiQGNoYXJzZXQgXCJVVEYtOFwiO1xuLnBhbmVsIHtcbiAgcG9zaXRpb246IHJlbGF0aXZlO1xuICB6LWluZGV4OiA5OTk5OTk5OTk5OTk5OTk5OTk5OTk5O1xuICBib3gtc2hhZG93OiAxMHB4O1xuICBiYWNrZ3JvdW5kLWNvbG9yOiB2YXIoLS1iZy1jb2xvcik7XG4gIGJhY2tncm91bmQtc2l6ZTogMTAwJSAxMDAlOyB9XG5cbi5hbGVydF9wIHtcbiAgZm9udC1zaXplOiAxOHB4ICFpbXBvcnRhbnQ7XG4gIGRpc3BsYXk6IGZsZXg7XG4gIGp1c3RpZnktY29udGVudDogY2VudGVyOyB9XG5cbi5wYW5lbF9kaXYsIC5hbGVydF9wIHtcbiAgb3BhY2l0eTogMTsgfVxuXG4uYWxlcnRfcCB7XG4gIGZvbnQtc2l6ZTogMjJweDtcbiAgY29sb3I6IHJlZDtcbiAgcGFkZGluZzogOHB4O1xuICBib3JkZXItcmFkaXVzOiAxMHB4OyB9XG5cbioge1xuICBtYXJnaW46IDA7XG4gIHBhZGRpbmc6IDA7IH1cblxuLm1haW4ge1xuICBtYXgtd2lkdGg6IDMwMHB4O1xuICBtaW4td2lkdGg6IDE1MHB4O1xuICBtYXgtaGVpZ2h0OiAzMDBweDtcbiAgbWluLWhlaWdodDogMTAwcHg7XG4gIGRpc3BsYXk6IGlubGluZS1ibG9jaztcbiAgY29sb3I6ICNmZmZmZmY7XG4gIGxpbmUtaGVpZ2h0OiAyOHB4O1xuICBwb3NpdGlvbjogcmVsYXRpdmU7XG4gIHBhZGRpbmc6IDEwcHg7XG4gIC13ZWJraXQtYm9yZGVyLXJhZGl1czogNXB4O1xuICAtbW96LWJvcmRlci1yYWRpdXM6IDVweDtcbiAgb3ZlcmZsb3c6IGhpZGRlbjsgfVxuXG4vKuW3puS4ieinkiovXG4ubWFpbjpiZWZvcmUge1xuICBjb250ZW50OiAnICc7XG4gIGJvcmRlci10b3A6IDhweCBzb2xpZCB0cmFuc3BhcmVudDtcbiAgYm9yZGVyLWJvdHRvbTogOHB4IHNvbGlkIHRyYW5zcGFyZW50O1xuICBib3JkZXItcmlnaHQ6IDEycHggc29saWQgdmFyKC0tYmctY29sb3IpO1xuICBwb3NpdGlvbjogYWJzb2x1dGU7XG4gIHRvcDogMTVweDtcbiAgbGVmdDogLTEycHg7IH1cblxuLyrlj7PkuInop5IqL1xuLm1haW4gPiBwIHtcbiAgbWluLXdpZHRoOiAxMDAlO1xuICBtYXgtd2lkdGg6IDEwMCU7XG4gIG1pbi1oZWlnaHQ6IDEwMCU7XG4gIG1heC1oZWlnaHQ6IDEwMCU7XG4gIGNvbG9yOiAjZmZmZmZmO1xuICBmb250LXdlaWdodDogMTA7IH1cblxuLmhpZGUge1xuICBwb3NpdGlvbjogcmVsYXRpdmU7XG4gIGZvbnQtc2l6ZTogMjBweDtcbiAgcmlnaHQ6IC05NSU7XG4gIHRvcDogLTE0cHg7XG4gIGN1cnNvcjogcG9pbnRlcjtcbiAgY29sb3I6ICNmZmZmZmY7IH1cblxuLnBhbmVsX2RpdiB7XG4gIHBvc2l0aW9uOiByZWxhdGl2ZTsgfVxuXG4uZGl2X3Age1xuICBwb3NpdGlvbjogcmVsYXRpdmU7XG4gIHRvcDogLTEwcHg7XG4gIG92ZXJmbG93OiBoaWRkZW47XG4gIG1heC1oZWlnaHQ6IDExMnB4OyB9XG5cbi5kaXZfcCA+IHAge1xuICBtYXgtaGVpZ2h0OiA1NnB4O1xuICBvdmVyZmxvdzogaGlkZGVuOyB9XG4iLCIucGFuZWx7XHJcbiAgICBwb3NpdGlvbjogcmVsYXRpdmU7XHJcbiAgICB6LWluZGV4OiA5OTk5OTk5OTk5OTk5OTk5OTk5OTk5O1xyXG4gICAgYm94LXNoYWRvdzogMTBweDtcclxuLy8gICAgYmFja2dyb3VuZC1jb2xvcjonJyxcclxuICAgXHJcbiAgIGJhY2tncm91bmQtY29sb3I6IHZhcigtLWJnLWNvbG9yKTtcclxuYmFja2dyb3VuZC1zaXplOiAxMDAlIDEwMCU7XHJcbi8vIG9wYWNpdHk6IDAuNTtcclxufVxyXG4uYWxlcnRfcHtcclxuICAgIGZvbnQtc2l6ZTogMThweCAhaW1wb3J0YW50O1xyXG4gICAgZGlzcGxheTogZmxleDtcclxuICAgIGp1c3RpZnktY29udGVudDogY2VudGVyO1xyXG4gICAgXHJcbn1cclxuLnBhbmVsX2RpdiwuYWxlcnRfcHtcclxuICAgIG9wYWNpdHk6IDE7XHJcbn1cclxuXHJcbi5hbGVydF9we1xyXG4gICAgZm9udC1zaXplOiAyMnB4O2NvbG9yOiByZWQ7XHJcbiAgICBwYWRkaW5nOiA4cHg7XHJcbiAgICBib3JkZXItcmFkaXVzOiAxMHB4O1xyXG59XHJcblxyXG4qe1xyXG4gICAgbWFyZ2luOiAwO1xyXG4gICAgcGFkZGluZzogMDtcclxuICAgfSAgXHJcbiAgIC5tYWlue1xyXG4gICAgbWF4LXdpZHRoOjMwMHB4O1xyXG4gICAgbWluLXdpZHRoOiAxNTBweDtcclxuICAgIG1heC1oZWlnaHQ6MzAwcHggO1xyXG4gICAgbWluLWhlaWdodDogMTAwcHg7XHJcbiAgICBkaXNwbGF5OiBpbmxpbmUtYmxvY2s7XHJcbiAgICBjb2xvcjogI2ZmZmZmZjtcclxuICAgIGxpbmUtaGVpZ2h0OiAyOHB4O1xyXG4gICAgLy8gYmFja2dyb3VuZDogI0YwOTgxQztcclxuICAgXHJcbiAgICBwb3NpdGlvbjogcmVsYXRpdmU7XHJcbiAgICBwYWRkaW5nOiAxMHB4O1xyXG4gICAgLXdlYmtpdC1ib3JkZXItcmFkaXVzOjVweDtcclxuICAgIC1tb3otYm9yZGVyLXJhZGl1czo1cHg7XHJcbiAgICBvdmVyZmxvdzogaGlkZGVuO1xyXG4gICB9XHJcbiAgIC8q5bem5LiJ6KeSKi9cclxuICAgLm1haW46YmVmb3Jle1xyXG4gICAgY29udGVudDogJyAnO1xyXG4gICAgYm9yZGVyLXRvcDogOHB4IHNvbGlkIHRyYW5zcGFyZW50O1xyXG4gICAgYm9yZGVyLWJvdHRvbTogOHB4IHNvbGlkIHRyYW5zcGFyZW50O1xyXG4gICAgLy8gYm9yZGVyLXJpZ2h0OiAxMnB4IHNvbGlkICNGMDk4MUM7XHJcbiAgICBib3JkZXItcmlnaHQ6IDEycHggc29saWQgdmFyKC0tYmctY29sb3IpO1xyXG5cclxuICAgIC8vIGJhY2tncm91bmQtaW1hZ2U6ICcvc3JjL2Fzc2V0cy9pbWFnZXMvYWxlcnQucG5nJztcclxuICAgIHBvc2l0aW9uOiBhYnNvbHV0ZTtcclxuICAgIHRvcDogMTVweDtcclxuICAgIGxlZnQ6IC0xMnB4O1xyXG4gICB9XHJcbiAgIC8q5Y+z5LiJ6KeSKi9cclxuLy8gICAgLm1haW46YWZ0ZXJ7XHJcbi8vICAgICBjb250ZW50OiAnICc7XHJcbi8vICAgICBib3JkZXItdG9wOiA4cHggc29saWQgdHJhbnNwYXJlbnQ7XHJcbi8vICAgICBib3JkZXItYm90dG9tOiA4cHggc29saWQgdHJhbnNwYXJlbnQ7XHJcbi8vICAgICBib3JkZXItbGVmdDogMTJweCBzb2xpZCAjRjA5ODFDO1xyXG4vLyAgICAgcG9zaXRpb246IGFic29sdXRlO1xyXG4vLyAgICAgYm90dG9tOiAxNXB4O1xyXG4vLyAgICAgcmlnaHQ6IC0xMnB4O1xyXG4vLyAgICB9XHJcbiAgIC5tYWluPnB7XHJcbm1pbi13aWR0aDogMTAwJTtcclxubWF4LXdpZHRoOiAxMDAlO1xyXG5taW4taGVpZ2h0OiAxMDAlO1xyXG5tYXgtaGVpZ2h0OiAxMDAlO1xyXG5jb2xvcjogI2ZmZmZmZjtcclxuZm9udC13ZWlnaHQ6IDEwO1xyXG4vLyBjb2xvcjogcmVkO1xyXG4gICB9XHJcblxyXG4gICAuaGlkZXtcclxuICAgICAgIHBvc2l0aW9uOiByZWxhdGl2ZTtcclxuICAgICAgIGZvbnQtc2l6ZTogMjBweDtcclxuICAgICAgIHJpZ2h0OiAtOTUlO1xyXG4gICAgICAgdG9wOiAtMTRweDtcclxuICAgICAgIGN1cnNvcjogcG9pbnRlcjtcclxuICAgICAgIGNvbG9yOiAjZmZmZmZmXHJcbiAgIH1cclxuICAgLnBhbmVsX2RpdntcclxucG9zaXRpb246IHJlbGF0aXZlO1xyXG4vLyBiYWNrZ3JvdW5kLWltYWdlOnVybCgnaHR0cHM6Ly9kb2NzLm01c3RhY2suY29tL2Fzc2V0cy9pbWcvcHJvZHVjdF9waWNzL2FwcC9hcHBfZmxpcl8wMS5wbmcnKSAhaW1wb3J0YW50O1xyXG4vLyBiYWNrZ3JvdW5kLXNpemU6IDEwMCUgMTAwJTtcclxuICAgfVxyXG5cclxuICAgLmRpdl9we1xyXG4gICAgICAgcG9zaXRpb246IHJlbGF0aXZlO1xyXG4gICAgICAgdG9wOiAtMTBweDtcclxuICAgICAgIG92ZXJmbG93OiBoaWRkZW47XHJcbiAgICAgICBtYXgtaGVpZ2h0OiA1NioycHhcclxuICAgfVxyXG4gICAuZGl2X3A+cHtcclxuICAgICAgIG1heC1oZWlnaHQ6IDU2cHg7XHJcbiAgICAgICBvdmVyZmxvdzogaGlkZGVuO1xyXG4gICB9Il19 */"

/***/ }),

/***/ "./src/app/core/message/message.ts":
/*!*****************************************!*\
  !*** ./src/app/core/message/message.ts ***!
  \*****************************************/
/*! exports provided: Message */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "Message", function() { return Message; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
/* harmony import */ var _animations__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ../../animations */ "./src/app/animations/index.ts");
/* harmony import */ var src_app_services_blockly_editor_service__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! src/app/services/blockly-editor.service */ "./src/app/services/blockly-editor.service.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};




// import { footerService } from 'src/app/services/blockly-editor.service';
var Message = /** @class */ (function () {
    function Message(service, el, renderer2) {
        this.service = service;
        this.el = el;
        this.renderer2 = renderer2;
        this.Alert_Blockly = '122';
        this.exampleVisibility = false;
        this.languageList = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["LANG"];
    }
    Message.prototype.ngOnInit = function () {
        var _this_1 = this;
        this.Alert_Blockly = this.service.blockly_alert;
        var _this = this;
        var t;
        var t1;
        this.service.getAlert().subscribe({
            next: function (v) {
                if (v && _this.Alert_Blockly !== v) {
                    _this.Alert_Blockly = v;
                    if (_this_1.exampleVisibility) {
                        _this_1.exampleVisibility = false;
                        if (t1) {
                            // clearInterval(t);
                            clearTimeout(t); // 清除定时器
                        }
                        t1 = setTimeout(function () {
                            _this_1.exampleVisibility = true;
                        }, 300);
                    }
                    else {
                        _this_1.exampleVisibility = true;
                    }
                    if (t) {
                        // clearInterval(t);
                        clearTimeout(t); // 清除定时器
                    }
                    t = setTimeout(function () {
                        _this_1.exampleVisibility = false;
                    }, 4000);
                }
                else {
                    _this.Alert_Blockly = v;
                    return false;
                }
            }
        });
    };
    Message.prototype.hide_alert = function () {
        // console.log('关闭')
        this.exampleVisibility = false;
        // this.renderer2.setStyle(this.el.nativeElement.parentNode, 'display', 'none');
    };
    Message = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-message',
            template: __webpack_require__(/*! ./message.html */ "./src/app/core/message/message.html"),
            styles: [__webpack_require__(/*! ./message.scss */ "./src/app/core/message/message.scss")],
            animations: [_animations__WEBPACK_IMPORTED_MODULE_2__["alertAnimation"]]
        }),
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Directive"])({
            selector: '[appHighlight]'
        }),
        __metadata("design:paramtypes", [src_app_services_blockly_editor_service__WEBPACK_IMPORTED_MODULE_3__["BlocklyEditorService"],
            _angular_core__WEBPACK_IMPORTED_MODULE_0__["ElementRef"],
            _angular_core__WEBPACK_IMPORTED_MODULE_0__["Renderer2"]])
    ], Message);
    return Message;
}());



/***/ }),

/***/ "./src/app/core/resource-manager/resource-manager.component.html":
/*!***********************************************************************!*\
  !*** ./src/app/core/resource-manager/resource-manager.component.html ***!
  \***********************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"wrapper--resource-manager\">\r\n  <div class=\"resource-manager\">\r\n    <header>\r\n      <p>{{ 'RESOURCEMANAGER' | translate }}</p>\r\n    </header>\r\n\r\n    <div class=\"main\">\r\n      \r\n      <div class=\"file-type\">\r\n        <a [class.selected]=\"selectedFileType === 'images'\" (click)=\"selectFile('images')\">{{ 'IMAGES' | translate }}</a>\r\n        <span>|</span>\r\n        <a [class.selected]=\"selectedFileType === 'blocklys'\" (click)=\"selectFile('blocklys')\">{{ 'BLOCKLYS' | translate }}</a>\r\n      </div>\r\n\r\n      <ul class=\"ul--data\" *ngIf=\"selectedFileType === 'blocklys'\">\r\n        <p class=\"txt--no-data\" *ngIf=\"(deviceInfo$ | async)?.blocklys?.length === 0\">{{ 'NODATE' | translate }}</p>\r\n        <li class=\"list-file\" *ngFor=\"let blockly of (deviceInfo$ | async)?.blocklys\">\r\n          <span>{{ blockly }}</span>\r\n          <button class=\"btn delete\" (click)=\"deleteM5FHandler(blockly)\">{{ 'DELETE' | translate  }}</button>\r\n          <button class=\"btn load\" (click)=\"loadM5FHandler(blockly)\">{{ 'Load' }}</button>\r\n        </li>\r\n      </ul>\r\n\r\n      <ul class=\"ul--data\" *ngIf=\"selectedFileType === 'images'\">\r\n        <div>\r\n          <button class=\"btn--add\" (click)=\"uploadImgHandler()\" [disabled]=\"uploading\">{{ 'ADDIMG' | translate }}</button>\r\n          <input id=\"__uploadImgBox\" type=\"file\" multiple=\"false\" accept=\"image/bmp,image/jpeg\" style=\"display:none\">\r\n        </div>\r\n        <p class=\"txt--no-data\" *ngIf=\"(deviceInfo$ | async)?.resources?.length === 0 && uploadingFile === ''\">{{ 'NODATE' | translate }}</p>\r\n        <li class=\"list-file\" *ngFor=\"let file of (deviceInfo$ | async)?.resources\">\r\n          <span>{{ file.filename }}</span>\r\n          <button class=\"btn delete\" (click)=\"deleteImageHandler(file.filename)\">{{ 'DELETE' | translate }}</button>\r\n        </li>\r\n        <li class=\"list-file uploading\" *ngIf=\"uploadingFile !== ''\">\r\n          <span>{{ uploadingFile }}</span>\r\n          <button class=\"btn--disabled\" disabled>{{ 'UPLOAD' | translate }}</button>\r\n        </li>\r\n      </ul>\r\n\r\n    </div>\r\n\r\n    <footer>\r\n      <button class=\"btn cancel\" (click)=\"cancel()\">{{ 'CANCEL'| translate }}</button>\r\n      <button class=\"btn ok\" (click)=\"refresh()\">{{ 'RELOAD' | translate }}</button>\r\n    </footer>\r\n  </div>\r\n</div>"

/***/ }),

/***/ "./src/app/core/resource-manager/resource-manager.component.scss":
/*!***********************************************************************!*\
  !*** ./src/app/core/resource-manager/resource-manager.component.scss ***!
  \***********************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper--resource-manager {\n  width: 100%;\n  height: 100%;\n  -webkit-animation: zoomIn .35s ease;\n          animation: zoomIn .35s ease; }\n\n.resource-manager {\n  width: 70%;\n  background-color: #383838;\n  position: relative;\n  top: 50%;\n  left: 50%;\n  -webkit-transform: translate(-50%, -50%);\n          transform: translate(-50%, -50%);\n  border-radius: 10px; }\n\nheader p {\n  padding: 8px 12px;\n  font-size: 28px;\n  font-family: Arial;\n  border-bottom: 1px solid #555;\n  color: #FFF;\n  font-weight: bolder; }\n\nfooter {\n  text-align: right;\n  border-top: 1px solid #555; }\n\nfooter .btn {\n  outline: none;\n  padding: 6px 16px;\n  font-size: 18px;\n  border: none;\n  border-radius: 5px;\n  margin: 12px 8px;\n  color: white;\n  cursor: pointer;\n  font-weight: bolder; }\n\nfooter .btn.cancel {\n    background-color: #FF5F2E; }\n\nfooter .btn.ok {\n    background-color: #3ac569; }\n\n.main {\n  padding: 0 20px; }\n\n.main .ul--data {\n    padding: 10px 0; }\n\n.main .ul--data .txt--no-data {\n      text-align: center;\n      font-size: 20px;\n      color: #888;\n      margin: 20px 0;\n      font-family: Arial; }\n\n.main .ul--data .btn--add {\n      outline: none;\n      border: none;\n      border-radius: 4px;\n      padding: 4px 12px;\n      cursor: pointer;\n      color: #FFF;\n      background-color: #2B90D9;\n      font-size: 16px; }\n\n.main .ul--data li {\n      list-style: none;\n      padding: 10px;\n      border-bottom: 1px #aaa solid; }\n\n.main .ul--data li span {\n        color: #FFF;\n        font-family: Arial; }\n\n.main .ul--data li button {\n        outline: none;\n        border: none;\n        border-radius: 4px;\n        padding: 4px 12px;\n        cursor: pointer;\n        color: #FFF;\n        font-size: 16px;\n        float: right;\n        font-family: Arial;\n        margin: 0 6px; }\n\n.main .ul--data li button.btn--disabled {\n          background-color: grey; }\n\n.main .ul--data li button.delete {\n          background-color: #E53A40; }\n\n.main .ul--data li button.load {\n          background-color: #30A9DE; }\n\n.file-type {\n  padding: 8px 0 0 0; }\n\n.file-type a {\n    text-decoration: underline;\n    cursor: pointer;\n    font-size: 20px;\n    color: #00b9f1;\n    font-family: Arial; }\n\n.file-type a.selected {\n      color: #FFF; }\n\n.file-type span {\n    margin: 0 12px;\n    color: #FFF; }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvY29yZS9yZXNvdXJjZS1tYW5hZ2VyL1o6XFx3b3Jrc3BhY2VcXG15X3pyZW5kZXJcXGZsb3cvc3JjXFxhcHBcXGNvcmVcXHJlc291cmNlLW1hbmFnZXJcXHJlc291cmNlLW1hbmFnZXIuY29tcG9uZW50LnNjc3MiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IkFBQUE7RUFDSSxZQUFXO0VBQ1gsYUFBWTtFQUNaLG9DQUEyQjtVQUEzQiw0QkFBMkIsRUFDOUI7O0FBRUQ7RUFDSSxXQUFVO0VBQ1YsMEJBQXlCO0VBQ3pCLG1CQUFrQjtFQUNsQixTQUFRO0VBQ1IsVUFBUztFQUNULHlDQUFnQztVQUFoQyxpQ0FBZ0M7RUFDaEMsb0JBQW1CLEVBRXRCOztBQUVEO0VBQ0ksa0JBQWlCO0VBQ2pCLGdCQUFlO0VBQ2YsbUJBQWtCO0VBQ2xCLDhCQUE2QjtFQUM3QixZQUFXO0VBQ1gsb0JBQW1CLEVBQ3RCOztBQUVEO0VBQ0ksa0JBQWlCO0VBQ2pCLDJCQUEwQixFQUM3Qjs7QUFFRDtFQUNJLGNBQWE7RUFDYixrQkFBaUI7RUFDakIsZ0JBQWU7RUFDZixhQUFZO0VBQ1osbUJBQWtCO0VBQ2xCLGlCQUFnQjtFQUNoQixhQUFZO0VBQ1osZ0JBQWU7RUFDZixvQkFBbUIsRUFTdEI7O0FBbEJEO0lBWVEsMEJBQXlCLEVBQzVCOztBQWJMO0lBZ0JRLDBCQUF5QixFQUM1Qjs7QUFHTDtFQUNJLGdCQUFlLEVBcURsQjs7QUF0REQ7SUFJUSxnQkFBZSxFQWlEbEI7O0FBckRMO01BTVksbUJBQWtCO01BQ2xCLGdCQUFlO01BQ2YsWUFBVztNQUNYLGVBQWM7TUFDZCxtQkFBa0IsRUFDckI7O0FBWFQ7TUFhWSxjQUFhO01BQ2IsYUFBWTtNQUNaLG1CQUFrQjtNQUNsQixrQkFBaUI7TUFDakIsZ0JBQWU7TUFDZixZQUFXO01BQ1gsMEJBQXlCO01BQ3pCLGdCQUFlLEVBQ2xCOztBQXJCVDtNQXVCWSxpQkFBZ0I7TUFDaEIsY0FBYTtNQUNiLDhCQUE2QixFQTJCaEM7O0FBcERUO1FBMkJnQixZQUFXO1FBQ1gsbUJBQWtCLEVBQ3JCOztBQTdCYjtRQStCZ0IsY0FBYTtRQUNiLGFBQVk7UUFDWixtQkFBa0I7UUFDbEIsa0JBQWlCO1FBQ2pCLGdCQUFlO1FBQ2YsWUFBVztRQUNYLGdCQUFlO1FBQ2YsYUFBWTtRQUNaLG1CQUFrQjtRQUNsQixjQUFhLEVBV2hCOztBQW5EYjtVQTJDb0IsdUJBQXNCLEVBQ3pCOztBQTVDakI7VUE4Q29CLDBCQUF5QixFQUM1Qjs7QUEvQ2pCO1VBaURvQiwwQkFBeUIsRUFDNUI7O0FBTWpCO0VBQ0ksbUJBQWtCLEVBZ0JyQjs7QUFqQkQ7SUFHUSwyQkFBMEI7SUFDMUIsZ0JBQWU7SUFDZixnQkFBZTtJQUNmLGVBQWM7SUFDZCxtQkFBa0IsRUFLckI7O0FBWkw7TUFVWSxZQUFXLEVBQ2Q7O0FBWFQ7SUFjUSxlQUFjO0lBQ2QsWUFBVyxFQUNkIiwiZmlsZSI6InNyYy9hcHAvY29yZS9yZXNvdXJjZS1tYW5hZ2VyL3Jlc291cmNlLW1hbmFnZXIuY29tcG9uZW50LnNjc3MiLCJzb3VyY2VzQ29udGVudCI6WyIud3JhcHBlci0tcmVzb3VyY2UtbWFuYWdlcntcclxuICAgIHdpZHRoOiAxMDAlO1xyXG4gICAgaGVpZ2h0OiAxMDAlO1xyXG4gICAgYW5pbWF0aW9uOiB6b29tSW4gLjM1cyBlYXNlO1xyXG59XHJcblxyXG4ucmVzb3VyY2UtbWFuYWdlciB7XHJcbiAgICB3aWR0aDogNzAlO1xyXG4gICAgYmFja2dyb3VuZC1jb2xvcjogIzM4MzgzODtcclxuICAgIHBvc2l0aW9uOiByZWxhdGl2ZTtcclxuICAgIHRvcDogNTAlO1xyXG4gICAgbGVmdDogNTAlO1xyXG4gICAgdHJhbnNmb3JtOiB0cmFuc2xhdGUoLTUwJSwgLTUwJSk7XHJcbiAgICBib3JkZXItcmFkaXVzOiAxMHB4O1xyXG4gICAgLy8gYW5pbWF0aW9uOiB6b29tSW4gLjM1cyBlYXNlO1xyXG59XHJcblxyXG5oZWFkZXIgcCB7XHJcbiAgICBwYWRkaW5nOiA4cHggMTJweDtcclxuICAgIGZvbnQtc2l6ZTogMjhweDtcclxuICAgIGZvbnQtZmFtaWx5OiBBcmlhbDtcclxuICAgIGJvcmRlci1ib3R0b206IDFweCBzb2xpZCAjNTU1O1xyXG4gICAgY29sb3I6ICNGRkY7XHJcbiAgICBmb250LXdlaWdodDogYm9sZGVyO1xyXG59XHJcblxyXG5mb290ZXIge1xyXG4gICAgdGV4dC1hbGlnbjogcmlnaHQ7XHJcbiAgICBib3JkZXItdG9wOiAxcHggc29saWQgIzU1NTtcclxufVxyXG5cclxuZm9vdGVyIC5idG4ge1xyXG4gICAgb3V0bGluZTogbm9uZTtcclxuICAgIHBhZGRpbmc6IDZweCAxNnB4O1xyXG4gICAgZm9udC1zaXplOiAxOHB4O1xyXG4gICAgYm9yZGVyOiBub25lO1xyXG4gICAgYm9yZGVyLXJhZGl1czogNXB4O1xyXG4gICAgbWFyZ2luOiAxMnB4IDhweDtcclxuICAgIGNvbG9yOiB3aGl0ZTtcclxuICAgIGN1cnNvcjogcG9pbnRlcjtcclxuICAgIGZvbnQtd2VpZ2h0OiBib2xkZXI7XHJcblxyXG4gICAgJi5jYW5jZWwge1xyXG4gICAgICAgIGJhY2tncm91bmQtY29sb3I6ICNGRjVGMkU7XHJcbiAgICB9XHJcblxyXG4gICAgJi5vayB7XHJcbiAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogIzNhYzU2OTtcclxuICAgIH1cclxufVxyXG5cclxuLm1haW4ge1xyXG4gICAgcGFkZGluZzogMCAyMHB4O1xyXG5cclxuICAgIC51bC0tZGF0YSB7XHJcbiAgICAgICAgcGFkZGluZzogMTBweCAwO1xyXG4gICAgICAgIC50eHQtLW5vLWRhdGEge1xyXG4gICAgICAgICAgICB0ZXh0LWFsaWduOiBjZW50ZXI7XHJcbiAgICAgICAgICAgIGZvbnQtc2l6ZTogMjBweDtcclxuICAgICAgICAgICAgY29sb3I6ICM4ODg7XHJcbiAgICAgICAgICAgIG1hcmdpbjogMjBweCAwO1xyXG4gICAgICAgICAgICBmb250LWZhbWlseTogQXJpYWw7XHJcbiAgICAgICAgfVxyXG4gICAgICAgIC5idG4tLWFkZCB7XHJcbiAgICAgICAgICAgIG91dGxpbmU6IG5vbmU7XHJcbiAgICAgICAgICAgIGJvcmRlcjogbm9uZTtcclxuICAgICAgICAgICAgYm9yZGVyLXJhZGl1czogNHB4O1xyXG4gICAgICAgICAgICBwYWRkaW5nOiA0cHggMTJweDtcclxuICAgICAgICAgICAgY3Vyc29yOiBwb2ludGVyO1xyXG4gICAgICAgICAgICBjb2xvcjogI0ZGRjtcclxuICAgICAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogIzJCOTBEOTtcclxuICAgICAgICAgICAgZm9udC1zaXplOiAxNnB4O1xyXG4gICAgICAgIH1cclxuICAgICAgICBsaSB7XHJcbiAgICAgICAgICAgIGxpc3Qtc3R5bGU6IG5vbmU7XHJcbiAgICAgICAgICAgIHBhZGRpbmc6IDEwcHg7XHJcbiAgICAgICAgICAgIGJvcmRlci1ib3R0b206IDFweCAjYWFhIHNvbGlkO1xyXG4gICAgICAgICAgICBzcGFuIHtcclxuICAgICAgICAgICAgICAgIGNvbG9yOiAjRkZGO1xyXG4gICAgICAgICAgICAgICAgZm9udC1mYW1pbHk6IEFyaWFsO1xyXG4gICAgICAgICAgICB9XHJcbiAgICAgICAgICAgIGJ1dHRvbiB7XHJcbiAgICAgICAgICAgICAgICBvdXRsaW5lOiBub25lO1xyXG4gICAgICAgICAgICAgICAgYm9yZGVyOiBub25lO1xyXG4gICAgICAgICAgICAgICAgYm9yZGVyLXJhZGl1czogNHB4O1xyXG4gICAgICAgICAgICAgICAgcGFkZGluZzogNHB4IDEycHg7XHJcbiAgICAgICAgICAgICAgICBjdXJzb3I6IHBvaW50ZXI7XHJcbiAgICAgICAgICAgICAgICBjb2xvcjogI0ZGRjtcclxuICAgICAgICAgICAgICAgIGZvbnQtc2l6ZTogMTZweDtcclxuICAgICAgICAgICAgICAgIGZsb2F0OiByaWdodDtcclxuICAgICAgICAgICAgICAgIGZvbnQtZmFtaWx5OiBBcmlhbDtcclxuICAgICAgICAgICAgICAgIG1hcmdpbjogMCA2cHg7XHJcblxyXG4gICAgICAgICAgICAgICAgJi5idG4tLWRpc2FibGVkIHtcclxuICAgICAgICAgICAgICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiBncmV5O1xyXG4gICAgICAgICAgICAgICAgfVxyXG4gICAgICAgICAgICAgICAgJi5kZWxldGUge1xyXG4gICAgICAgICAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6ICNFNTNBNDA7XHJcbiAgICAgICAgICAgICAgICB9XHJcbiAgICAgICAgICAgICAgICAmLmxvYWQge1xyXG4gICAgICAgICAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6ICMzMEE5REU7XHJcbiAgICAgICAgICAgICAgICB9XHJcbiAgICAgICAgICAgIH1cclxuICAgICAgICB9XHJcbiAgICB9XHJcbn1cclxuXHJcbi5maWxlLXR5cGUge1xyXG4gICAgcGFkZGluZzogOHB4IDAgMCAwO1xyXG4gICAgYSB7XHJcbiAgICAgICAgdGV4dC1kZWNvcmF0aW9uOiB1bmRlcmxpbmU7XHJcbiAgICAgICAgY3Vyc29yOiBwb2ludGVyO1xyXG4gICAgICAgIGZvbnQtc2l6ZTogMjBweDtcclxuICAgICAgICBjb2xvcjogIzAwYjlmMTtcclxuICAgICAgICBmb250LWZhbWlseTogQXJpYWw7XHJcbiAgICBcclxuICAgICAgICAmLnNlbGVjdGVkIHtcclxuICAgICAgICAgICAgY29sb3I6ICNGRkY7XHJcbiAgICAgICAgfVxyXG4gICAgfVxyXG4gICAgc3BhbiB7XHJcbiAgICAgICAgbWFyZ2luOiAwIDEycHg7XHJcbiAgICAgICAgY29sb3I6ICNGRkY7XHJcbiAgICB9XHJcbn0iXX0= */"

/***/ }),

/***/ "./src/app/core/resource-manager/resource-manager.component.ts":
/*!*********************************************************************!*\
  !*** ./src/app/core/resource-manager/resource-manager.component.ts ***!
  \*********************************************************************/
/*! exports provided: ResourceManagerComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "ResourceManagerComponent", function() { return ResourceManagerComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_services_global_operator_service__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/services/global-operator.service */ "./src/app/services/global-operator.service.ts");
/* harmony import */ var src_app_services_store_service__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! src/app/services/store.service */ "./src/app/services/store.service.ts");
/* harmony import */ var src_app_services_upload_service__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! src/app/services/upload.service */ "./src/app/services/upload.service.ts");
/* harmony import */ var _ngx_translate_core__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @ngx-translate/core */ "./node_modules/@ngx-translate/core/fesm5/ngx-translate-core.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};





var ResourceManagerComponent = /** @class */ (function () {
    function ResourceManagerComponent(globalOperatorSrv, storeSrv, uploadSrv, translate) {
        this.globalOperatorSrv = globalOperatorSrv;
        this.storeSrv = storeSrv;
        this.uploadSrv = uploadSrv;
        this.translate = translate;
        this.selectedFileType = 'images';
        this.uploadingFile = '';
        this.uploading = false;
    }
    ResourceManagerComponent.prototype.ngOnInit = function () {
        this.deviceInfo$ = this.storeSrv.getDeviceInfo();
    };
    ResourceManagerComponent.prototype.refresh = function () {
        this.uploadSrv.getDeviceInfo().subscribe();
    };
    ResourceManagerComponent.prototype.cancel = function () {
        this.globalOperatorSrv.maskModal.instance.removeMask();
    };
    ResourceManagerComponent.prototype.selectFile = function (type) {
        this.selectedFileType = type;
    };
    ResourceManagerComponent.prototype.uploadImgHandler = function () {
        var _this_1 = this;
        var uploadImgBox = document.getElementById('__uploadImgBox');
        uploadImgBox.click();
        uploadImgBox.onchange = function (ev) {
            // 是否没有选择文件
            if (ev.target['files'].length === 0) {
                ev.target['value'] = '';
                _this_1.globalOperatorSrv.createMessageBox().instance.error('');
                return;
            }
            // 是否超出25kb
            if (ev.target['files'][0].size > 25 * 1000) {
                ev.target['value'] = '';
                _this_1.translate.get('FILE_SIZE_ERROR').subscribe(function (res) {
                    _this_1.globalOperatorSrv.createMessageBox().instance.error(res);
                });
                return;
            }
            // 文件名长度是否大于10
            if (ev.target['files'][0].name.replace(/.jpg|.bmp/g, '').length > 10) {
                ev.target['value'] = '';
                _this_1.translate.get('FILE_NAME_EROR').subscribe(function (res) {
                    _this_1.globalOperatorSrv.createMessageBox().instance.error(res);
                });
                return;
            }
            _this_1.uploadingFile = ev.target['files'][0].name;
            _this_1.uploading = true;
            var _file = ev.target['files'][0];
            _this_1.uploadSrv.uploadImg(ev.target['files'][0]).subscribe(function (event) {
                if (event.status === 200) {
                    var fr = new FileReader();
                    var _this_2 = _this_1;
                    fr.onload = function () {
                        var _this_1 = this;
                        var deviceInfo = _this_2.storeSrv.deviceInfo.value;
                        var flag = deviceInfo.resources.filter(function (f) { return f.filename === _file.name; });
                        if (flag.length === 0) {
                            deviceInfo.resources.push({ filename: _file.name, base64: this.result.toString() });
                        }
                        else {
                            deviceInfo.resources.forEach(function (f) {
                                if (f.filename === _file.name) {
                                    f.base64 = _this_1.result.toString();
                                }
                            });
                        }
                        _this_2.storeSrv.setDeviceInfo(deviceInfo);
                    };
                    fr.readAsDataURL(_file);
                    ev.target['value'] = '';
                    _this_1.uploadingFile = '';
                    _this_1.uploading = false;
                }
            }, function (err) {
                ev.target['value'] = '';
                _this_1.uploadingFile = '';
                _this_1.uploading = false;
            });
        };
    };
    ResourceManagerComponent.prototype.deleteImageHandler = function (filename) {
        var _this_1 = this;
        if (!window.confirm('Do you sure remove this file from your device?'))
            return;
        this.uploadSrv.deleteImg(filename).subscribe(function (res) {
            var deviceInfo = _this_1.storeSrv.deviceInfo.value;
            deviceInfo.resources.splice(deviceInfo.resources.findIndex(function (f) { return f.filename === filename; }), 1);
            _this_1.storeSrv.setDeviceInfo(deviceInfo);
        }, function (err) {
            console.log(err);
        });
    };
    ResourceManagerComponent.prototype.loadM5FHandler = function (filename) {
        var _this_1 = this;
        this.uploadSrv.loadBlocklyFile(filename).subscribe(function (res) {
            var data = res;
            _this_1.globalOperatorSrv.openM5F(data);
            _this_1.cancel();
        });
    };
    ResourceManagerComponent.prototype.deleteM5FHandler = function (filename) {
        var _this_1 = this;
        if (!window.confirm('Do you sure remove this file?'))
            return;
        this.uploadSrv.deleteBlocklyFile(filename).subscribe(function (res) {
            var deviceInfo = _this_1.storeSrv.deviceInfo.value;
            deviceInfo.blocklys.splice(deviceInfo.blocklys.findIndex(function (b) { return b === filename; }), 1);
            _this_1.storeSrv.setDeviceInfo(deviceInfo);
        });
    };
    ResourceManagerComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-resource-manager',
            template: __webpack_require__(/*! ./resource-manager.component.html */ "./src/app/core/resource-manager/resource-manager.component.html"),
            styles: [__webpack_require__(/*! ./resource-manager.component.scss */ "./src/app/core/resource-manager/resource-manager.component.scss")]
        }),
        __metadata("design:paramtypes", [src_app_services_global_operator_service__WEBPACK_IMPORTED_MODULE_1__["GlobalOperatorService"],
            src_app_services_store_service__WEBPACK_IMPORTED_MODULE_2__["StoreService"],
            src_app_services_upload_service__WEBPACK_IMPORTED_MODULE_3__["UploadService"],
            _ngx_translate_core__WEBPACK_IMPORTED_MODULE_4__["TranslateService"]])
    ], ResourceManagerComponent);
    return ResourceManagerComponent;
}());



/***/ }),

/***/ "./src/app/core/setting-panel/setting-panel.component.html":
/*!*****************************************************************!*\
  !*** ./src/app/core/setting-panel/setting-panel.component.html ***!
  \*****************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"wrapper--setting-panel\">\r\n  <div class=\"setting-panel\">\r\n    <header>\r\n      <div class=\"video\">\r\n        <p>{{ (setting ? 'SETTING' : 'SETTING_first') | translate }} </p>\r\n      </div>\r\n    </header>\r\n    <div class=\"wapper-scroll\">\r\n    <table>\r\n      <tr>\r\n        <td class=\"title\">{{ 'COM :' | translate }}</td>\r\n        <td class=\"apikey\">\r\n          <select #apikeyBox [value]=\"apikey$ | async\" [value]=\"selectedCOM\" (click)=\"refreshList()\" (change)=\"preventRefresh()\">\r\n            <option *ngFor=\"let c of com\" [value]=\"c\">{{ c }}</option>\r\n          </select>\r\n        </td>\r\n      </tr>\r\n      <tr>\r\n        <td class=\"title\">{{ 'LANGUAGE' | translate }}</td>\r\n        <td>\r\n          <select class=\"td--inputbox\" [value]=\"storeSrv.defaultLanguage\" #languageBox>\r\n            <option *ngFor=\"let lang of languageList\" [value]=\"lang.file\">{{ lang.name }}</option>\r\n          </select>\r\n        </td>\r\n      </tr>\r\n      <tr>\r\n        <td class=\"title\">{{ 'CATEGORY' | translate }}</td>\r\n        <td>\r\n          <select class=\"td--inputbox\" [value]=\"defineType\" #categoryBox>\r\n            <!-- <option *ngFor=\"let cateitem of categoryArr\" [value]=\"cateitem\">{{ cateitem == 'core' ? 'Core' : 'Stick' }}</option> -->\r\n            <option *ngFor=\"let cateitem of categoryArr\" [value]=\"cateitem\">{{ cateitem == 'core' ? 'Core' : cateitem == 'stick' ? 'Stick' : 'Stick-C' }}</option>\r\n            \r\n          </select>\r\n        </td>\r\n      </tr>\r\n      <tr>\r\n        <td class=\"title\">{{ 'THEME' | translate }}</td>\r\n        <td class=\"theme\">\r\n          <div class=\"clod\" (click)=\"settheme('clod')\"></div>\r\n          <div class=\"warn\" (click)=\"settheme('warn')\"></div>\r\n          <div class=\"blank\" (click)=\"settheme('blank')\"></div>\r\n          <div class=\"pink\" (click)=\"settheme('pink')\"></div>\r\n          <div class=\"green\" (click)=\"settheme('green')\"></div>\r\n          <!-- <input type=\"color\" name=\"color\" id=\"color\" onchange=\"changeColor()\">  -->\r\n        </td>\r\n      </tr>\r\n    </table>\r\n    </div> \r\n    <footer>\r\n      <button class=\"btn cancel\" (click)=\"cancel()\">{{ 'CANCEL' | translate }}</button>\r\n      <button class=\"btn ok\"\r\n        (click)=\"ok(apikeyBox.value, languageBox.value, categoryBox.value)\">{{ 'OK'| translate }}</button>\r\n    </footer>\r\n  </div>\r\n</div>"

/***/ }),

/***/ "./src/app/core/setting-panel/setting-panel.component.scss":
/*!*****************************************************************!*\
  !*** ./src/app/core/setting-panel/setting-panel.component.scss ***!
  \*****************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper--setting-panel {\n  width: 100%;\n  height: 100%;\n  -webkit-animation: zoomIn .35s ease;\n          animation: zoomIn .35s ease; }\n\n.setting-panel {\n  width: 600px;\n  position: relative;\n  top: 50%;\n  left: 50%;\n  -webkit-transform: translate(-50%, -50%);\n          transform: translate(-50%, -50%);\n  background-color: #383838;\n  border-radius: 10px; }\n\nheader p {\n  padding: 8px 12px;\n  font-size: 28px;\n  font-family: Arial;\n  border-bottom: 1px solid #555;\n  color: #FFF;\n  font-weight: bolder; }\n\nfooter {\n  text-align: right;\n  border-top: 1px solid #555; }\n\nfooter .btn {\n  outline: none;\n  padding: 6px 16px;\n  font-size: 18px;\n  border: none;\n  border-radius: 5px;\n  margin: 12px 8px;\n  color: white;\n  cursor: pointer;\n  font-weight: bolder; }\n\nfooter .btn.cancel {\n    background-color: #FF5F2E; }\n\nfooter .btn.ok {\n    background-color: #3ac569; }\n\n.setting-panel table {\n  text-align: right;\n  font-size: 18px;\n  padding: 20px;\n  width: 100%;\n  color: #FFF;\n  font-family: Arial;\n  padding-top: 0; }\n\n.setting-panel table tr {\n    height: 50px; }\n\n.setting-panel table td {\n    font-size: 20px; }\n\n.setting-panel table td.title {\n      width: 140px; }\n\n.setting-panel table td.td--link {\n      text-align: left; }\n\n.setting-panel table td.td--link a {\n        color: #00a0c8; }\n\n.setting-panel table td.apikey {\n      position: relative; }\n\n.setting-panel table td.apikey .apikey-select {\n        position: absolute;\n        width: 100%;\n        color: #000;\n        max-height: 0;\n        overflow: hidden;\n        line-height: 1.5;\n        text-align: center;\n        background-color: #fff;\n        border-radius: 5px;\n        transition: all 0.3s ease; }\n\n.setting-panel table td.apikey .apikey-select.show {\n          max-height: 300px; }\n\n.setting-panel table td.apikey .apikey-select > div:hover {\n          background-color: #eee; }\n\n.setting-panel table td.theme {\n      display: flex;\n      height: 70px;\n      align-items: center;\n      padding: 0; }\n\n.setting-panel table td.theme div {\n        flex: 1;\n        height: 50px;\n        line-height: 50px;\n        text-align: center;\n        border-radius: 4px;\n        margin: 0px 5px;\n        transition: all 0.5s cubic-bezier(0.075, 0.82, 0.165, 1); }\n\n.setting-panel table td.theme div.clod {\n          background-color: #007ACC;\n          box-shadow: 0 0 10px #007ACC; }\n\n.setting-panel table td.theme div.warn {\n          background-color: #ee9922;\n          box-shadow: 0 0 10px #ee9922; }\n\n.setting-panel table td.theme div.blank {\n          background-color: #000200;\n          box-shadow: 0 0 10px #000200; }\n\n.setting-panel table td.theme div.pink {\n          background-color: #FFB1B0;\n          box-shadow: 0 0 10px #FFB1B0; }\n\n.setting-panel table td.theme div.green {\n          background-color: #2fb303;\n          box-shadow: 0 0 10px #2fb303; }\n\n.setting-panel table td.theme div:hover {\n          -webkit-transform: scale(1.1);\n                  transform: scale(1.1); }\n\n.setting-panel table .top {\n    width: 45px;\n    height: 30px; }\n\n.setting-panel table input {\n    width: 100%;\n    font-size: 20px;\n    border: none;\n    outline: none;\n    padding: 4px 8px;\n    border-radius: 4px; }\n\n.setting-panel table .doc {\n    min-height: 50px;\n    line-height: 50px;\n    display: flex;\n    justify-content: flex-end;\n    align-items: flex-start; }\n\n.setting-panel table .flexd {\n    display: flex;\n    padding: 10px 15px; }\n\n.setting-panel table .doc {\n    position: relative; }\n\n.setting-panel table .doc_block {\n    min-height: 30px;\n    overflow: hidden;\n    padding-left: 10px; }\n\n.setting-panel table .dixd_doc {\n    border-radius: 8px;\n    min-height: 100px;\n    overflow: hidden; }\n\n.setting-panel table .doc_block a {\n    display: inline-block;\n    width: 45px;\n    height: 30px;\n    margin-right: 15px; }\n\n.setting-panel table select {\n    width: 100%;\n    height: 30px;\n    background-color: #FFF;\n    border-radius: 5px;\n    outline: none;\n    border: none;\n    font-size: 18px;\n    padding-left: 6px; }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvY29yZS9zZXR0aW5nLXBhbmVsL1o6XFx3b3Jrc3BhY2VcXG15X3pyZW5kZXJcXGZsb3cvc3JjXFxhcHBcXGNvcmVcXHNldHRpbmctcGFuZWxcXHNldHRpbmctcGFuZWwuY29tcG9uZW50LnNjc3MiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IkFBQUE7RUFDSSxZQUFXO0VBQ1gsYUFBWTtFQUNaLG9DQUEyQjtVQUEzQiw0QkFBMkIsRUFDOUI7O0FBQ0Q7RUFDSSxhQUFZO0VBQ1osbUJBQWtCO0VBQ2xCLFNBQVE7RUFDUixVQUFTO0VBQ1QseUNBQWdDO1VBQWhDLGlDQUFnQztFQUNoQywwQkFBeUI7RUFDekIsb0JBQW1CLEVBQ3RCOztBQUVEO0VBQ0ksa0JBQWlCO0VBQ2pCLGdCQUFlO0VBQ2YsbUJBQWtCO0VBQ2xCLDhCQUE2QjtFQUM3QixZQUFXO0VBQ1gsb0JBQW1CLEVBQ3RCOztBQUVEO0VBQ0ksa0JBQWlCO0VBQ2pCLDJCQUEwQixFQUM3Qjs7QUFFRDtFQUNJLGNBQWE7RUFDYixrQkFBaUI7RUFDakIsZ0JBQWU7RUFDZixhQUFZO0VBQ1osbUJBQWtCO0VBQ2xCLGlCQUFnQjtFQUNoQixhQUFZO0VBQ1osZ0JBQWU7RUFDZixvQkFBbUIsRUFPdEI7O0FBaEJEO0lBV1EsMEJBQXlCLEVBQzVCOztBQVpMO0lBY1EsMEJBQXlCLEVBQzVCOztBQUdMO0VBQ0ksa0JBQWlCO0VBQ2pCLGdCQUFlO0VBQ2YsY0FBYTtFQUNiLFlBQVc7RUFDWCxZQUFXO0VBQ1gsbUJBQWtCO0VBQ2xCLGVBQWMsRUFrSWpCOztBQXpJRDtJQVNRLGFBQVksRUFDZjs7QUFWTDtJQVlRLGdCQUFlLEVBc0VsQjs7QUFsRkw7TUFjWSxhQUFZLEVBQ2Y7O0FBZlQ7TUFpQlksaUJBQWdCLEVBSW5COztBQXJCVDtRQW1CZ0IsZUFBYyxFQUNqQjs7QUFwQmI7TUF1QlksbUJBQWtCLEVBb0JyQjs7QUEzQ1Q7UUEwQmdCLG1CQUFrQjtRQUNsQixZQUFXO1FBQ1gsWUFBVztRQUNYLGNBQWE7UUFDYixpQkFBZ0I7UUFDaEIsaUJBQWdCO1FBQ2hCLG1CQUFrQjtRQUNsQix1QkFBc0I7UUFDdEIsbUJBQWtCO1FBQ2xCLDBCQUF5QixFQU81Qjs7QUExQ2I7VUFxQ29CLGtCQUFpQixFQUNwQjs7QUF0Q2pCO1VBd0NvQix1QkFBc0IsRUFDekI7O0FBekNqQjtNQTZDWSxjQUFhO01BQ2IsYUFBWTtNQUNaLG9CQUFtQjtNQUNuQixXQUFVLEVBaUNiOztBQWpGVDtRQWtEZ0IsUUFBTztRQUNQLGFBQVk7UUFDWixrQkFBaUI7UUFDakIsbUJBQWtCO1FBQ2xCLG1CQUFrQjtRQUNsQixnQkFBZTtRQUNmLHlEQUF3RCxFQXdCM0Q7O0FBaEZiO1VBMERvQiwwQkFBMEI7VUFDMUIsNkJBQTRCLEVBQy9COztBQTVEakI7VUE4RG9CLDBCQUEwQjtVQUMxQiw2QkFBNEIsRUFDL0I7O0FBaEVqQjtVQWtFb0IsMEJBQTBCO1VBQzFCLDZCQUE0QixFQUMvQjs7QUFwRWpCO1VBc0VvQiwwQkFBMEI7VUFDMUIsNkJBQTRCLEVBQy9COztBQXhFakI7VUEwRW9CLDBCQUEwQjtVQUMxQiw2QkFBNEIsRUFDL0I7O0FBNUVqQjtVQThFb0IsOEJBQXFCO2tCQUFyQixzQkFBcUIsRUFDeEI7O0FBL0VqQjtJQW9GUSxZQUFXO0lBQ1gsYUFBWSxFQUNmOztBQXRGTDtJQXdGUSxZQUFXO0lBQ1gsZ0JBQWU7SUFDZixhQUFZO0lBQ1osY0FBYTtJQUNiLGlCQUFnQjtJQUNoQixtQkFBa0IsRUFDckI7O0FBOUZMO0lBZ0dRLGlCQUFnQjtJQUFDLGtCQUFpQjtJQUNsQyxjQUFhO0lBQ2IsMEJBQXlCO0lBQ3pCLHdCQUF1QixFQUMxQjs7QUFwR0w7SUFzR1EsY0FBYTtJQUNiLG1CQUFrQixFQUNyQjs7QUF4R0w7SUEyR1EsbUJBQ0osRUFBQzs7QUE1R0w7SUErR1EsaUJBQWdCO0lBQ2hCLGlCQUFnQjtJQUNoQixtQkFDSixFQUFDOztBQWxITDtJQW9IUSxtQkFBbUI7SUFDbkIsa0JBQWlCO0lBQ2pCLGlCQUFnQixFQUNuQjs7QUF2SEw7SUF5SFEsc0JBQXFCO0lBQ3JCLFlBQVc7SUFDWCxhQUFZO0lBQ1osbUJBQWlCLEVBQ3BCOztBQTdITDtJQWdJUSxZQUFXO0lBQ1gsYUFBWTtJQUNaLHVCQUFzQjtJQUN0QixtQkFBa0I7SUFDbEIsY0FBYTtJQUNiLGFBQVk7SUFDWixnQkFBZTtJQUNmLGtCQUFpQixFQUNwQiIsImZpbGUiOiJzcmMvYXBwL2NvcmUvc2V0dGluZy1wYW5lbC9zZXR0aW5nLXBhbmVsLmNvbXBvbmVudC5zY3NzIiwic291cmNlc0NvbnRlbnQiOlsiLndyYXBwZXItLXNldHRpbmctcGFuZWwge1xyXG4gICAgd2lkdGg6IDEwMCU7XHJcbiAgICBoZWlnaHQ6IDEwMCU7XHJcbiAgICBhbmltYXRpb246IHpvb21JbiAuMzVzIGVhc2U7XHJcbn1cclxuLnNldHRpbmctcGFuZWwge1xyXG4gICAgd2lkdGg6IDYwMHB4O1xyXG4gICAgcG9zaXRpb246IHJlbGF0aXZlO1xyXG4gICAgdG9wOiA1MCU7XHJcbiAgICBsZWZ0OiA1MCU7XHJcbiAgICB0cmFuc2Zvcm06IHRyYW5zbGF0ZSgtNTAlLCAtNTAlKTtcclxuICAgIGJhY2tncm91bmQtY29sb3I6ICMzODM4Mzg7XHJcbiAgICBib3JkZXItcmFkaXVzOiAxMHB4O1xyXG59XHJcblxyXG5oZWFkZXIgcCB7XHJcbiAgICBwYWRkaW5nOiA4cHggMTJweDtcclxuICAgIGZvbnQtc2l6ZTogMjhweDtcclxuICAgIGZvbnQtZmFtaWx5OiBBcmlhbDtcclxuICAgIGJvcmRlci1ib3R0b206IDFweCBzb2xpZCAjNTU1O1xyXG4gICAgY29sb3I6ICNGRkY7XHJcbiAgICBmb250LXdlaWdodDogYm9sZGVyO1xyXG59XHJcblxyXG5mb290ZXIge1xyXG4gICAgdGV4dC1hbGlnbjogcmlnaHQ7XHJcbiAgICBib3JkZXItdG9wOiAxcHggc29saWQgIzU1NTtcclxufVxyXG5cclxuZm9vdGVyIC5idG4ge1xyXG4gICAgb3V0bGluZTogbm9uZTtcclxuICAgIHBhZGRpbmc6IDZweCAxNnB4O1xyXG4gICAgZm9udC1zaXplOiAxOHB4O1xyXG4gICAgYm9yZGVyOiBub25lO1xyXG4gICAgYm9yZGVyLXJhZGl1czogNXB4O1xyXG4gICAgbWFyZ2luOiAxMnB4IDhweDtcclxuICAgIGNvbG9yOiB3aGl0ZTtcclxuICAgIGN1cnNvcjogcG9pbnRlcjtcclxuICAgIGZvbnQtd2VpZ2h0OiBib2xkZXI7XHJcbiAgICAmLmNhbmNlbCB7XHJcbiAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogI0ZGNUYyRTtcclxuICAgIH1cclxuICAgICYub2sge1xyXG4gICAgICAgIGJhY2tncm91bmQtY29sb3I6ICMzYWM1Njk7XHJcbiAgICB9XHJcbn1cclxuXHJcbi5zZXR0aW5nLXBhbmVsIHRhYmxlIHtcclxuICAgIHRleHQtYWxpZ246IHJpZ2h0O1xyXG4gICAgZm9udC1zaXplOiAxOHB4O1xyXG4gICAgcGFkZGluZzogMjBweDtcclxuICAgIHdpZHRoOiAxMDAlO1xyXG4gICAgY29sb3I6ICNGRkY7XHJcbiAgICBmb250LWZhbWlseTogQXJpYWw7XHJcbiAgICBwYWRkaW5nLXRvcDogMDtcclxuICAgIHRyIHtcclxuICAgICAgICBoZWlnaHQ6IDUwcHg7XHJcbiAgICB9XHJcbiAgICB0ZCB7XHJcbiAgICAgICAgZm9udC1zaXplOiAyMHB4O1xyXG4gICAgICAgICYudGl0bGUge1xyXG4gICAgICAgICAgICB3aWR0aDogMTQwcHg7XHJcbiAgICAgICAgfVxyXG4gICAgICAgICYudGQtLWxpbmsge1xyXG4gICAgICAgICAgICB0ZXh0LWFsaWduOiBsZWZ0O1xyXG4gICAgICAgICAgICBhIHtcclxuICAgICAgICAgICAgICAgIGNvbG9yOiAjMDBhMGM4O1xyXG4gICAgICAgICAgICB9XHJcbiAgICAgICAgfVxyXG4gICAgICAgICYuYXBpa2V5IHtcclxuICAgICAgICAgICAgcG9zaXRpb246IHJlbGF0aXZlO1xyXG4gICAgICAgICAgICBpbnB1dCB7fVxyXG4gICAgICAgICAgICAuYXBpa2V5LXNlbGVjdCB7XHJcbiAgICAgICAgICAgICAgICBwb3NpdGlvbjogYWJzb2x1dGU7XHJcbiAgICAgICAgICAgICAgICB3aWR0aDogMTAwJTtcclxuICAgICAgICAgICAgICAgIGNvbG9yOiAjMDAwO1xyXG4gICAgICAgICAgICAgICAgbWF4LWhlaWdodDogMDtcclxuICAgICAgICAgICAgICAgIG92ZXJmbG93OiBoaWRkZW47XHJcbiAgICAgICAgICAgICAgICBsaW5lLWhlaWdodDogMS41O1xyXG4gICAgICAgICAgICAgICAgdGV4dC1hbGlnbjogY2VudGVyO1xyXG4gICAgICAgICAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogI2ZmZjtcclxuICAgICAgICAgICAgICAgIGJvcmRlci1yYWRpdXM6IDVweDtcclxuICAgICAgICAgICAgICAgIHRyYW5zaXRpb246IGFsbCAwLjNzIGVhc2U7XHJcbiAgICAgICAgICAgICAgICAmLnNob3cge1xyXG4gICAgICAgICAgICAgICAgICAgIG1heC1oZWlnaHQ6IDMwMHB4O1xyXG4gICAgICAgICAgICAgICAgfVxyXG4gICAgICAgICAgICAgICAgJj5kaXY6aG92ZXIge1xyXG4gICAgICAgICAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6ICNlZWU7XHJcbiAgICAgICAgICAgICAgICB9XHJcbiAgICAgICAgICAgIH1cclxuICAgICAgICB9XHJcbiAgICAgICAgJi50aGVtZSB7XHJcbiAgICAgICAgICAgIGRpc3BsYXk6IGZsZXg7XHJcbiAgICAgICAgICAgIGhlaWdodDogNzBweDtcclxuICAgICAgICAgICAgYWxpZ24taXRlbXM6IGNlbnRlcjtcclxuICAgICAgICAgICAgcGFkZGluZzogMDtcclxuICAgICAgICAgICAgZGl2IHtcclxuICAgICAgICAgICAgICAgIGZsZXg6IDE7XHJcbiAgICAgICAgICAgICAgICBoZWlnaHQ6IDUwcHg7XHJcbiAgICAgICAgICAgICAgICBsaW5lLWhlaWdodDogNTBweDtcclxuICAgICAgICAgICAgICAgIHRleHQtYWxpZ246IGNlbnRlcjtcclxuICAgICAgICAgICAgICAgIGJvcmRlci1yYWRpdXM6IDRweDtcclxuICAgICAgICAgICAgICAgIG1hcmdpbjogMHB4IDVweDtcclxuICAgICAgICAgICAgICAgIHRyYW5zaXRpb246IGFsbCAwLjVzIGN1YmljLWJlemllcigwLjA3NSwgMC44MiwgMC4xNjUsIDEpOyBcclxuICAgICAgICAgICAgICAgICYuY2xvZCB7XHJcbiAgICAgICAgICAgICAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogICMwMDdBQ0M7XHJcbiAgICAgICAgICAgICAgICAgICAgYm94LXNoYWRvdzogMCAwIDEwcHggIzAwN0FDQztcclxuICAgICAgICAgICAgICAgIH1cclxuICAgICAgICAgICAgICAgICYud2FybiB7XHJcbiAgICAgICAgICAgICAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogICNlZTk5MjI7XHJcbiAgICAgICAgICAgICAgICAgICAgYm94LXNoYWRvdzogMCAwIDEwcHggI2VlOTkyMjtcclxuICAgICAgICAgICAgICAgIH1cclxuICAgICAgICAgICAgICAgICYuYmxhbmsge1xyXG4gICAgICAgICAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6ICAjMDAwMjAwO1xyXG4gICAgICAgICAgICAgICAgICAgIGJveC1zaGFkb3c6IDAgMCAxMHB4ICMwMDAyMDA7XHJcbiAgICAgICAgICAgICAgICB9XHJcbiAgICAgICAgICAgICAgICAmLnBpbmsge1xyXG4gICAgICAgICAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6ICAjRkZCMUIwO1xyXG4gICAgICAgICAgICAgICAgICAgIGJveC1zaGFkb3c6IDAgMCAxMHB4ICNGRkIxQjA7XHJcbiAgICAgICAgICAgICAgICB9XHJcbiAgICAgICAgICAgICAgICAmLmdyZWVuIHtcclxuICAgICAgICAgICAgICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiAgIzJmYjMwMztcclxuICAgICAgICAgICAgICAgICAgICBib3gtc2hhZG93OiAwIDAgMTBweCAjMmZiMzAzO1xyXG4gICAgICAgICAgICAgICAgfVxyXG4gICAgICAgICAgICAgICAgJjpob3ZlciB7XHJcbiAgICAgICAgICAgICAgICAgICAgdHJhbnNmb3JtOiBzY2FsZSgxLjEpO1xyXG4gICAgICAgICAgICAgICAgfVxyXG4gICAgICAgICAgICB9XHJcbiAgICAgICAgfVxyXG4gICAgfVxyXG4gICAgLnRvcHtcclxuICAgICAgICB3aWR0aDogNDVweDtcclxuICAgICAgICBoZWlnaHQ6IDMwcHg7XHJcbiAgICB9XHJcbiAgICBpbnB1dCB7XHJcbiAgICAgICAgd2lkdGg6IDEwMCU7XHJcbiAgICAgICAgZm9udC1zaXplOiAyMHB4O1xyXG4gICAgICAgIGJvcmRlcjogbm9uZTtcclxuICAgICAgICBvdXRsaW5lOiBub25lO1xyXG4gICAgICAgIHBhZGRpbmc6IDRweCA4cHg7XHJcbiAgICAgICAgYm9yZGVyLXJhZGl1czogNHB4O1xyXG4gICAgfVxyXG4gICAgLmRvY3tcclxuICAgICAgICBtaW4taGVpZ2h0OiA1MHB4O2xpbmUtaGVpZ2h0OiA1MHB4O1xyXG4gICAgICAgIGRpc3BsYXk6IGZsZXg7XHJcbiAgICAgICAganVzdGlmeS1jb250ZW50OiBmbGV4LWVuZDtcclxuICAgICAgICBhbGlnbi1pdGVtczogZmxleC1zdGFydDtcclxuICAgIH1cclxuICAgIC5mbGV4ZHtcclxuICAgICAgICBkaXNwbGF5OiBmbGV4O1xyXG4gICAgICAgIHBhZGRpbmc6IDEwcHggMTVweDtcclxuICAgIH1cclxuXHJcbiAgICAuZG9je1xyXG4gICAgICAgIHBvc2l0aW9uOiByZWxhdGl2ZVxyXG4gICAgfVxyXG5cclxuICAgIC5kb2NfYmxvY2t7XHJcbiAgICAgICAgbWluLWhlaWdodDogMzBweDtcclxuICAgICAgICBvdmVyZmxvdzogaGlkZGVuO1xyXG4gICAgICAgIHBhZGRpbmctbGVmdDogMTBweFxyXG4gICAgfVxyXG4gICAgLmRpeGRfZG9je1xyXG4gICAgICAgIGJvcmRlci1yYWRpdXM6ICA4cHg7IFxyXG4gICAgICAgIG1pbi1oZWlnaHQ6IDEwMHB4O1xyXG4gICAgICAgIG92ZXJmbG93OiBoaWRkZW47XHJcbiAgICB9XHJcbiAgICAuZG9jX2Jsb2NrIGF7XHJcbiAgICAgICAgZGlzcGxheTogaW5saW5lLWJsb2NrO1xyXG4gICAgICAgIHdpZHRoOiA0NXB4O1xyXG4gICAgICAgIGhlaWdodDogMzBweDsgICBcclxuICAgICAgICBtYXJnaW4tcmlnaHQ6MTVweDtcclxuICAgIH1cclxuXHJcbiAgICBzZWxlY3Qge1xyXG4gICAgICAgIHdpZHRoOiAxMDAlO1xyXG4gICAgICAgIGhlaWdodDogMzBweDtcclxuICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiAjRkZGO1xyXG4gICAgICAgIGJvcmRlci1yYWRpdXM6IDVweDtcclxuICAgICAgICBvdXRsaW5lOiBub25lO1xyXG4gICAgICAgIGJvcmRlcjogbm9uZTtcclxuICAgICAgICBmb250LXNpemU6IDE4cHg7XHJcbiAgICAgICAgcGFkZGluZy1sZWZ0OiA2cHg7XHJcbiAgICB9XHJcbn1cclxuIl19 */"

/***/ }),

/***/ "./src/app/core/setting-panel/setting-panel.component.ts":
/*!***************************************************************!*\
  !*** ./src/app/core/setting-panel/setting-panel.component.ts ***!
  \***************************************************************/
/*! exports provided: SettingPanelComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "SettingPanelComponent", function() { return SettingPanelComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
/* harmony import */ var src_app_services_global_operator_service__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! src/app/services/global-operator.service */ "./src/app/services/global-operator.service.ts");
/* harmony import */ var src_app_services_store_service__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! src/app/services/store.service */ "./src/app/services/store.service.ts");
/* harmony import */ var src_app_services_upload_service__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! src/app/services/upload.service */ "./src/app/services/upload.service.ts");
/* harmony import */ var _ngx_translate_core__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @ngx-translate/core */ "./node_modules/@ngx-translate/core/fesm5/ngx-translate-core.js");
/* harmony import */ var src_app_services_blockly_editor_service__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! src/app/services/blockly-editor.service */ "./src/app/services/blockly-editor.service.ts");
/* harmony import */ var _animations__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ../../animations */ "./src/app/animations/index.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};








var SettingPanelComponent = /** @class */ (function () {
    function SettingPanelComponent(globalOperatorSrv, storeSrv, uploadSrv, translateSrv, blocklyEditorSrv, el) {
        this.globalOperatorSrv = globalOperatorSrv;
        this.storeSrv = storeSrv;
        this.uploadSrv = uploadSrv;
        this.translateSrv = translateSrv;
        this.blocklyEditorSrv = blocklyEditorSrv;
        this.el = el;
        this.languageList = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["LANG"];
        this.allapikey = [];
        this.categoryArr = ['core', 'stick', 'stick-C'];
        this.setting = false;
        this.com = [];
        this.selectedCOM = '';
        this.isNeedRefresh = true;
    }
    SettingPanelComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.defineType = localStorage.getItem('_type') || 'core';
        this.apikey$ = this.storeSrv.getApikey();
        this.uploadSrv.getComList().subscribe(function (res) {
            _this.com = res.data;
            _this.selectedCOM = _this.storeSrv.apiKey.value;
        });
        setTimeout(function () {
            _this.allapikey = _this.storeSrv.getAllkey();
        }, 0);
        if (localStorage.getItem('new_user')) {
            this.setting = true;
        }
        else {
            this.setting = false;
            localStorage.setItem('new_user', 'false');
        }
    };
    SettingPanelComponent.prototype.ok = function (apikey, lang, cate) {
        var _this = this;
        if (this.storeSrv.apiKey.value !== apikey) {
            this.storeSrv.setApikey(apikey);
            this.storeSrv.setAllkey(apikey);
            this.uploadSrv.getDeviceInfo().subscribe();
        }
        if (this.storeSrv.defaultLanguage !== lang) {
            this.storeSrv.loddingMODE.next(true);
            var xml = window['Blockly'].Xml.workspaceToDom(window['BlocklyEditor']);
            var xml_text = window['Blockly'].Xml.domToText(xml);
            window.sessionStorage.setItem('xml', xml_text);
            this.storeSrv.setLanguage(lang);
            this.blocklyEditorSrv.init({ language: lang, wrapperId: 'wrapper_blockly_editor', toolboxId: 'wrapper_blockly_toolbox' });
            this.translateSrv.use(lang);
            // 延时1S 解决语言切换后units Blockly显示不出来
            setTimeout(function () {
                _this.storeSrv.componentList.next(_this.storeSrv.componentList.value);
                _this.storeSrv.unitList.next(_this.storeSrv.unitList.value);
            }, 1000);
        }
        // this.storeSrv.getType().subscribe( res => {
        //   console.log(res);
        // });
        if (localStorage.getItem('_type') !== cate) {
            // this.storeSrv.loddingMODE.next(true);
            this.storeSrv.setType(cate);
            localStorage.setItem('_type', cate);
        }
        this.globalOperatorSrv.maskModal.instance.removeMask();
    };
    SettingPanelComponent.prototype.cancel = function () {
        this.globalOperatorSrv.maskModal.instance.removeMask();
    };
    SettingPanelComponent.prototype.enter = function (ev, apikey, lang, cate) {
        if (ev.keyCode === 13) {
            return this.ok(apikey, lang, cate);
        }
    };
    SettingPanelComponent.prototype.convertUpperCase = function (ev) {
        this.apikeyBox.nativeElement.value = ev.target.value.toUpperCase();
    };
    SettingPanelComponent.prototype.apifocus = function () {
        this.show = true;
    };
    SettingPanelComponent.prototype.apiblur = function () {
        this.show = false;
    };
    SettingPanelComponent.prototype.selectapi = function (e) {
        this.apikeyBox.nativeElement.value = e.toUpperCase();
    };
    SettingPanelComponent.prototype.settheme = function (e) {
        if (document.documentElement.hasAttribute('theme')) {
            document.documentElement.removeAttribute('theme');
        }
        document.documentElement.setAttribute('theme', e);
        localStorage.setItem('theme', e);
    };
    SettingPanelComponent.prototype.paly = function (e) {
        e.video_hidden = false;
    };
    SettingPanelComponent.prototype.pause = function (e) {
        e.video_hidden = true;
    };
    SettingPanelComponent.prototype.ended = function (e) {
        e.video_hidden = true;
    };
    SettingPanelComponent.prototype.refreshList = function () {
        var _this = this;
        if (!this.isNeedRefresh) {
            this.isNeedRefresh = true;
            return;
        }
        this.uploadSrv.getComList().subscribe(function (res) {
            _this.com = res.data;
            _this.selectedCOM = _this.storeSrv.apiKey.value;
        });
    };
    SettingPanelComponent.prototype.preventRefresh = function () {
        this.isNeedRefresh = false;
    };
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ViewChild"])('apikeyBox'),
        __metadata("design:type", _angular_core__WEBPACK_IMPORTED_MODULE_0__["ElementRef"])
    ], SettingPanelComponent.prototype, "apikeyBox", void 0);
    SettingPanelComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-setting-panel',
            template: __webpack_require__(/*! ./setting-panel.component.html */ "./src/app/core/setting-panel/setting-panel.component.html"),
            styles: [__webpack_require__(/*! ./setting-panel.component.scss */ "./src/app/core/setting-panel/setting-panel.component.scss")],
            animations: [_animations__WEBPACK_IMPORTED_MODULE_7__["videoAnimation"]]
        }),
        __metadata("design:paramtypes", [src_app_services_global_operator_service__WEBPACK_IMPORTED_MODULE_2__["GlobalOperatorService"],
            src_app_services_store_service__WEBPACK_IMPORTED_MODULE_3__["StoreService"],
            src_app_services_upload_service__WEBPACK_IMPORTED_MODULE_4__["UploadService"],
            _ngx_translate_core__WEBPACK_IMPORTED_MODULE_5__["TranslateService"],
            src_app_services_blockly_editor_service__WEBPACK_IMPORTED_MODULE_6__["BlocklyEditorService"],
            _angular_core__WEBPACK_IMPORTED_MODULE_0__["ElementRef"]])
    ], SettingPanelComponent);
    return SettingPanelComponent;
}());



/***/ }),

/***/ "./src/app/core/updata/updata.html":
/*!*****************************************!*\
  !*** ./src/app/core/updata/updata.html ***!
  \*****************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"wrapper--setting-panel\" (click)=\"cancel()\">\r\n    <div class=\"setting-panel\" (click)=\"cancel_show()\">\r\n      <header>\r\n        <p>{{ 'UPDATA' | translate }}</p>\r\n      </header>\r\n      <div class=\"wapper-scroll\">\r\n      <table>\r\n        <tr class=\"_ngcontent-c14\">\r\n          <td class=\"td--link \">\r\n            <p> <span class=\"versions\">1.2.3-1: </span>  Add stick-c LED,RTC setting time,axp and other modules<span class=\"span\">time : 2019.4.8</span></p> \r\n          </td>\r\n\r\n        </tr>\r\n\r\n      </table>\r\n      </div> \r\n\r\n    </div>\r\n  </div>\r\n"

/***/ }),

/***/ "./src/app/core/updata/updata.scss":
/*!*****************************************!*\
  !*** ./src/app/core/updata/updata.scss ***!
  \*****************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper--setting-panel {\n  width: 100%;\n  height: 100%;\n  -webkit-animation: zoomIn .35s ease;\n          animation: zoomIn .35s ease; }\n\n.setting-panel {\n  width: 600px;\n  position: relative;\n  top: 50%;\n  left: 50%;\n  -webkit-transform: translate(-50%, -50%);\n          transform: translate(-50%, -50%);\n  background-color: #383838;\n  border-radius: 10px; }\n\n.setting-panel .wapper-scroll {\n    height: 320px;\n    overflow-y: scroll; }\n\nheader p {\n  padding: 8px 12px;\n  font-size: 28px;\n  font-family: Arial;\n  border-bottom: 1px solid #555;\n  color: #FFF;\n  font-weight: bolder;\n  height: 80px;\n  line-height: 72px; }\n\nfooter {\n  text-align: right;\n  border-top: 1px solid #555; }\n\nfooter .btn {\n  outline: none;\n  padding: 6px 16px;\n  font-size: 18px;\n  border: none;\n  border-radius: 5px;\n  margin: 12px 8px;\n  color: white;\n  cursor: pointer;\n  font-weight: bolder; }\n\nfooter .btn.cancel {\n    background-color: #FF5F2E; }\n\nfooter .btn.ok {\n    background-color: #3ac569; }\n\n.td--block {\n  width: 100%;\n  text-align: left;\n  line-height: 60px;\n  padding: 0 20px; }\n\n._ngcontent-c14 {\n  display: flex;\n  justify-content: center;\n  align-items: center; }\n\n._ngcontent-c14 > td {\n  width: 100%;\n  padding-left: 40px;\n  height: 100px; }\n\n._ngcontent-c14 > td > p {\n  padding: 10px 0px;\n  position: relative;\n  line-height: 35px; }\n\n.td--link .span {\n  position: absolute;\n  right: 20px;\n  color: #00a0c8; }\n\n.versions {\n  color: #00a0c8; }\n\n.setting-panel table {\n  text-align: right;\n  font-size: 18px;\n  padding-bottom: 20px;\n  width: 100%;\n  color: #FFF;\n  font-family: Arial; }\n\n.setting-panel table td {\n    font-size: 20px; }\n\n.setting-panel table td.td--link {\n      text-align: left; }\n\n.setting-panel table td.td--link a {\n        color: #00a0c8; }\n\n.setting-panel table td.apikey {\n      position: relative; }\n\n.setting-panel table td.apikey .apikey-select {\n        position: absolute;\n        width: 100%;\n        color: #000;\n        max-height: 0;\n        overflow: hidden;\n        line-height: 1.5;\n        text-align: center;\n        background-color: #fff;\n        border-radius: 5px;\n        transition: all 0.3s ease; }\n\n.setting-panel table td.apikey .apikey-select.show {\n          max-height: 300px; }\n\n.setting-panel table td.apikey .apikey-select > div:hover {\n          background-color: #eee; }\n\n.setting-panel table td.theme {\n      display: flex;\n      height: 50px;\n      padding: 0; }\n\n.setting-panel table td.theme div {\n        flex: 1;\n        height: 100%;\n        line-height: 50px;\n        text-align: center;\n        border-radius: 4px;\n        margin: 0px 5px;\n        transition: all 0.5s cubic-bezier(0.075, 0.82, 0.165, 1); }\n\n.setting-panel table td.theme div.clod {\n          background-color: #007ACC;\n          box-shadow: 0 0 10px #007ACC; }\n\n.setting-panel table td.theme div.warn {\n          background-color: #ee9922;\n          box-shadow: 0 0 10px #ee9922; }\n\n.setting-panel table td.theme div.blank {\n          background-color: #000200;\n          box-shadow: 0 0 10px #000200; }\n\n.setting-panel table td.theme div.pink {\n          background-color: #FFB1B0;\n          box-shadow: 0 0 10px #FFB1B0; }\n\n.setting-panel table td.theme div.green {\n          background-color: #2fb303;\n          box-shadow: 0 0 10px #2fb303; }\n\n.setting-panel table td.theme div:hover {\n          -webkit-transform: scale(1.1);\n                  transform: scale(1.1); }\n\n.setting-panel table input {\n    width: 100%;\n    font-size: 20px;\n    border: none;\n    outline: none;\n    padding: 4px 8px;\n    border-radius: 4px; }\n\n.setting-panel table select {\n    width: 100%;\n    height: 30px;\n    background-color: #FFF;\n    border-radius: 5px;\n    outline: none;\n    border: none;\n    font-size: 18px;\n    padding-left: 6px; }\n\n@media only screen and (min-width: 320px) and (max-height: 767px) {\n  .setting-panel {\n    width: 70%; }\n    .setting-panel .wapper-scroll {\n      height: 160px;\n      overflow-y: scroll; } }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvY29yZS91cGRhdGEvWjpcXHdvcmtzcGFjZVxcbXlfenJlbmRlclxcZmxvdy9zcmNcXGFwcFxcY29yZVxcdXBkYXRhXFx1cGRhdGEuc2NzcyJdLCJuYW1lcyI6W10sIm1hcHBpbmdzIjoiQUFBQTtFQUNJLFlBQVc7RUFDWCxhQUFZO0VBQ1osb0NBQTJCO1VBQTNCLDRCQUEyQixFQUM5Qjs7QUFDRDtFQUNJLGFBQVk7RUFDWixtQkFBa0I7RUFDbEIsU0FBUTtFQUNSLFVBQVM7RUFDVCx5Q0FBZ0M7VUFBaEMsaUNBQWdDO0VBQ2hDLDBCQUF5QjtFQUN6QixvQkFBbUIsRUFLdEI7O0FBWkQ7SUFTUSxjQUFhO0lBQ2IsbUJBQWtCLEVBQ3JCOztBQUdMO0VBQ0ksa0JBQWlCO0VBQ2pCLGdCQUFlO0VBQ2YsbUJBQWtCO0VBQ2xCLDhCQUE2QjtFQUM3QixZQUFXO0VBQ1gsb0JBQW1CO0VBQ25CLGFBQVk7RUFDWixrQkFBaUIsRUFDcEI7O0FBRUQ7RUFDSSxrQkFBaUI7RUFDakIsMkJBQTBCLEVBQzdCOztBQUVEO0VBQ0ksY0FBYTtFQUNiLGtCQUFpQjtFQUNqQixnQkFBZTtFQUNmLGFBQVk7RUFDWixtQkFBa0I7RUFDbEIsaUJBQWdCO0VBQ2hCLGFBQVk7RUFDWixnQkFBZTtFQUNmLG9CQUFtQixFQU90Qjs7QUFoQkQ7SUFXUSwwQkFBeUIsRUFDNUI7O0FBWkw7SUFjUSwwQkFBeUIsRUFDNUI7O0FBRUw7RUFDSSxZQUFXO0VBQ1gsaUJBQWdCO0VBQ2hCLGtCQUFpQjtFQUNqQixnQkFBYyxFQUNqQjs7QUFDRDtFQUNJLGNBQWE7RUFBQyx3QkFBdUI7RUFBQyxvQkFDMUMsRUFBQzs7QUFDRDtFQUNJLFlBQVc7RUFDWCxtQkFBa0I7RUFFbEIsY0FBYSxFQUNoQjs7QUFDRDtFQUVJLGtCQUFpQjtFQUNqQixtQkFBa0I7RUFDbEIsa0JBQ0osRUFBQzs7QUFDRDtFQUNJLG1CQUFrQjtFQUNsQixZQUFXO0VBQ1gsZUFBYyxFQUNqQjs7QUFDRDtFQUNJLGVBQWMsRUFDakI7O0FBQ0Q7RUFDSSxrQkFBaUI7RUFDakIsZ0JBQWU7RUFDZixxQkFBb0I7RUFDcEIsWUFBVztFQUNYLFlBQVc7RUFDWCxtQkFBa0IsRUEwRnJCOztBQWhHRDtJQVdRLGdCQUFlLEVBa0VsQjs7QUE3RUw7TUFhWSxpQkFBZ0IsRUFJbkI7O0FBakJUO1FBZWdCLGVBQWMsRUFDakI7O0FBaEJiO01BbUJZLG1CQUFrQixFQW9CckI7O0FBdkNUO1FBc0JnQixtQkFBa0I7UUFDbEIsWUFBVztRQUNYLFlBQVc7UUFDWCxjQUFhO1FBQ2IsaUJBQWdCO1FBQ2hCLGlCQUFnQjtRQUNoQixtQkFBa0I7UUFDbEIsdUJBQXNCO1FBQ3RCLG1CQUFrQjtRQUNsQiwwQkFBeUIsRUFPNUI7O0FBdENiO1VBaUNvQixrQkFBaUIsRUFDcEI7O0FBbENqQjtVQW9Db0IsdUJBQXNCLEVBQ3pCOztBQXJDakI7TUF5Q1ksY0FBYTtNQUNiLGFBQVk7TUFDWixXQUFVLEVBaUNiOztBQTVFVDtRQTZDZ0IsUUFBTztRQUNQLGFBQVk7UUFDWixrQkFBaUI7UUFDakIsbUJBQWtCO1FBQ2xCLG1CQUFrQjtRQUNsQixnQkFBZTtRQUNmLHlEQUF3RCxFQXdCM0Q7O0FBM0ViO1VBcURvQiwwQkFBMEI7VUFDMUIsNkJBQTRCLEVBQy9COztBQXZEakI7VUF5RG9CLDBCQUEwQjtVQUMxQiw2QkFBNEIsRUFDL0I7O0FBM0RqQjtVQTZEb0IsMEJBQTBCO1VBQzFCLDZCQUE0QixFQUMvQjs7QUEvRGpCO1VBaUVvQiwwQkFBMEI7VUFDMUIsNkJBQTRCLEVBQy9COztBQW5FakI7VUFxRW9CLDBCQUEwQjtVQUMxQiw2QkFBNEIsRUFDL0I7O0FBdkVqQjtVQXlFb0IsOEJBQXFCO2tCQUFyQixzQkFBcUIsRUFDeEI7O0FBMUVqQjtJQStFUSxZQUFXO0lBQ1gsZ0JBQWU7SUFDZixhQUFZO0lBQ1osY0FBYTtJQUNiLGlCQUFnQjtJQUNoQixtQkFBa0IsRUFDckI7O0FBckZMO0lBdUZRLFlBQVc7SUFDWCxhQUFZO0lBQ1osdUJBQXNCO0lBQ3RCLG1CQUFrQjtJQUNsQixjQUFhO0lBQ2IsYUFBWTtJQUNaLGdCQUFlO0lBQ2Ysa0JBQWlCLEVBQ3BCOztBQUlMO0VBQ0k7SUFDSSxXQUFVLEVBS2I7SUFORDtNQUdRLGNBQWE7TUFDYixtQkFBa0IsRUFDckIsRUFBQSIsImZpbGUiOiJzcmMvYXBwL2NvcmUvdXBkYXRhL3VwZGF0YS5zY3NzIiwic291cmNlc0NvbnRlbnQiOlsiLndyYXBwZXItLXNldHRpbmctcGFuZWwge1xyXG4gICAgd2lkdGg6IDEwMCU7XHJcbiAgICBoZWlnaHQ6IDEwMCU7XHJcbiAgICBhbmltYXRpb246IHpvb21JbiAuMzVzIGVhc2U7XHJcbn1cclxuLnNldHRpbmctcGFuZWwge1xyXG4gICAgd2lkdGg6IDYwMHB4O1xyXG4gICAgcG9zaXRpb246IHJlbGF0aXZlO1xyXG4gICAgdG9wOiA1MCU7XHJcbiAgICBsZWZ0OiA1MCU7XHJcbiAgICB0cmFuc2Zvcm06IHRyYW5zbGF0ZSgtNTAlLCAtNTAlKTtcclxuICAgIGJhY2tncm91bmQtY29sb3I6ICMzODM4Mzg7XHJcbiAgICBib3JkZXItcmFkaXVzOiAxMHB4O1xyXG4gICAgLndhcHBlci1zY3JvbGwge1xyXG4gICAgICAgIGhlaWdodDogMzIwcHg7XHJcbiAgICAgICAgb3ZlcmZsb3cteTogc2Nyb2xsO1xyXG4gICAgfVxyXG59XHJcblxyXG5oZWFkZXIgcCB7XHJcbiAgICBwYWRkaW5nOiA4cHggMTJweDtcclxuICAgIGZvbnQtc2l6ZTogMjhweDtcclxuICAgIGZvbnQtZmFtaWx5OiBBcmlhbDtcclxuICAgIGJvcmRlci1ib3R0b206IDFweCBzb2xpZCAjNTU1O1xyXG4gICAgY29sb3I6ICNGRkY7XHJcbiAgICBmb250LXdlaWdodDogYm9sZGVyO1xyXG4gICAgaGVpZ2h0OiA4MHB4O1xyXG4gICAgbGluZS1oZWlnaHQ6IDcycHg7XHJcbn1cclxuXHJcbmZvb3RlciB7XHJcbiAgICB0ZXh0LWFsaWduOiByaWdodDtcclxuICAgIGJvcmRlci10b3A6IDFweCBzb2xpZCAjNTU1O1xyXG59XHJcblxyXG5mb290ZXIgLmJ0biB7XHJcbiAgICBvdXRsaW5lOiBub25lO1xyXG4gICAgcGFkZGluZzogNnB4IDE2cHg7XHJcbiAgICBmb250LXNpemU6IDE4cHg7XHJcbiAgICBib3JkZXI6IG5vbmU7XHJcbiAgICBib3JkZXItcmFkaXVzOiA1cHg7XHJcbiAgICBtYXJnaW46IDEycHggOHB4O1xyXG4gICAgY29sb3I6IHdoaXRlO1xyXG4gICAgY3Vyc29yOiBwb2ludGVyO1xyXG4gICAgZm9udC13ZWlnaHQ6IGJvbGRlcjtcclxuICAgICYuY2FuY2VsIHtcclxuICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiAjRkY1RjJFO1xyXG4gICAgfVxyXG4gICAgJi5vayB7XHJcbiAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogIzNhYzU2OTtcclxuICAgIH1cclxufVxyXG4udGQtLWJsb2Nre1xyXG4gICAgd2lkdGg6IDEwMCU7XHJcbiAgICB0ZXh0LWFsaWduOiBsZWZ0O1xyXG4gICAgbGluZS1oZWlnaHQ6IDYwcHg7XHJcbiAgICBwYWRkaW5nOjAgMjBweDtcclxufVxyXG4uX25nY29udGVudC1jMTR7XHJcbiAgICBkaXNwbGF5OiBmbGV4O2p1c3RpZnktY29udGVudDogY2VudGVyO2FsaWduLWl0ZW1zOiBjZW50ZXJcclxufVxyXG4uX25nY29udGVudC1jMTQ+dGR7XHJcbiAgICB3aWR0aDogMTAwJTtcclxuICAgIHBhZGRpbmctbGVmdDogNDBweDtcclxuICAgIC8vIGRpc3BsYXk6IGZsZXg7anVzdGlmeS1jb250ZW50OiBjZW50ZXJcclxuICAgIGhlaWdodDogMTAwcHg7XHJcbn1cclxuLl9uZ2NvbnRlbnQtYzE0PnRkPnB7XHJcbiAgICAvLyBoZWlnaHQ6IDEwMHB4O1xyXG4gICAgcGFkZGluZzogMTBweCAwcHg7XHJcbiAgICBwb3NpdGlvbjogcmVsYXRpdmU7XHJcbiAgICBsaW5lLWhlaWdodDogMzVweFxyXG59XHJcbi50ZC0tbGluayAuc3BhbntcclxuICAgIHBvc2l0aW9uOiBhYnNvbHV0ZTtcclxuICAgIHJpZ2h0OiAyMHB4O1xyXG4gICAgY29sb3I6ICMwMGEwYzg7XHJcbn1cclxuLnZlcnNpb25ze1xyXG4gICAgY29sb3I6ICMwMGEwYzg7XHJcbn1cclxuLnNldHRpbmctcGFuZWwgdGFibGUge1xyXG4gICAgdGV4dC1hbGlnbjogcmlnaHQ7XHJcbiAgICBmb250LXNpemU6IDE4cHg7XHJcbiAgICBwYWRkaW5nLWJvdHRvbTogMjBweDtcclxuICAgIHdpZHRoOiAxMDAlO1xyXG4gICAgY29sb3I6ICNGRkY7XHJcbiAgICBmb250LWZhbWlseTogQXJpYWw7XHJcbiAgICB0ciB7XHJcbiAgICAgICBcclxuICAgIH1cclxuICAgIHRkIHtcclxuICAgICAgICBmb250LXNpemU6IDIwcHg7XHJcbiAgICAgICAgJi50ZC0tbGluayB7XHJcbiAgICAgICAgICAgIHRleHQtYWxpZ246IGxlZnQ7XHJcbiAgICAgICAgICAgIGEge1xyXG4gICAgICAgICAgICAgICAgY29sb3I6ICMwMGEwYzg7XHJcbiAgICAgICAgICAgIH1cclxuICAgICAgICB9XHJcbiAgICAgICAgJi5hcGlrZXkge1xyXG4gICAgICAgICAgICBwb3NpdGlvbjogcmVsYXRpdmU7XHJcbiAgICAgICAgICAgIGlucHV0IHt9XHJcbiAgICAgICAgICAgIC5hcGlrZXktc2VsZWN0IHtcclxuICAgICAgICAgICAgICAgIHBvc2l0aW9uOiBhYnNvbHV0ZTtcclxuICAgICAgICAgICAgICAgIHdpZHRoOiAxMDAlO1xyXG4gICAgICAgICAgICAgICAgY29sb3I6ICMwMDA7XHJcbiAgICAgICAgICAgICAgICBtYXgtaGVpZ2h0OiAwO1xyXG4gICAgICAgICAgICAgICAgb3ZlcmZsb3c6IGhpZGRlbjtcclxuICAgICAgICAgICAgICAgIGxpbmUtaGVpZ2h0OiAxLjU7XHJcbiAgICAgICAgICAgICAgICB0ZXh0LWFsaWduOiBjZW50ZXI7XHJcbiAgICAgICAgICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiAjZmZmO1xyXG4gICAgICAgICAgICAgICAgYm9yZGVyLXJhZGl1czogNXB4O1xyXG4gICAgICAgICAgICAgICAgdHJhbnNpdGlvbjogYWxsIDAuM3MgZWFzZTtcclxuICAgICAgICAgICAgICAgICYuc2hvdyB7XHJcbiAgICAgICAgICAgICAgICAgICAgbWF4LWhlaWdodDogMzAwcHg7XHJcbiAgICAgICAgICAgICAgICB9XHJcbiAgICAgICAgICAgICAgICAmPmRpdjpob3ZlciB7XHJcbiAgICAgICAgICAgICAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogI2VlZTtcclxuICAgICAgICAgICAgICAgIH1cclxuICAgICAgICAgICAgfVxyXG4gICAgICAgIH1cclxuICAgICAgICAmLnRoZW1lIHtcclxuICAgICAgICAgICAgZGlzcGxheTogZmxleDtcclxuICAgICAgICAgICAgaGVpZ2h0OiA1MHB4O1xyXG4gICAgICAgICAgICBwYWRkaW5nOiAwO1xyXG4gICAgICAgICAgICBkaXYge1xyXG4gICAgICAgICAgICAgICAgZmxleDogMTtcclxuICAgICAgICAgICAgICAgIGhlaWdodDogMTAwJTtcclxuICAgICAgICAgICAgICAgIGxpbmUtaGVpZ2h0OiA1MHB4O1xyXG4gICAgICAgICAgICAgICAgdGV4dC1hbGlnbjogY2VudGVyO1xyXG4gICAgICAgICAgICAgICAgYm9yZGVyLXJhZGl1czogNHB4O1xyXG4gICAgICAgICAgICAgICAgbWFyZ2luOiAwcHggNXB4O1xyXG4gICAgICAgICAgICAgICAgdHJhbnNpdGlvbjogYWxsIDAuNXMgY3ViaWMtYmV6aWVyKDAuMDc1LCAwLjgyLCAwLjE2NSwgMSk7IFxyXG4gICAgICAgICAgICAgICAgJi5jbG9kIHtcclxuICAgICAgICAgICAgICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiAgIzAwN0FDQztcclxuICAgICAgICAgICAgICAgICAgICBib3gtc2hhZG93OiAwIDAgMTBweCAjMDA3QUNDO1xyXG4gICAgICAgICAgICAgICAgfVxyXG4gICAgICAgICAgICAgICAgJi53YXJuIHtcclxuICAgICAgICAgICAgICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiAgI2VlOTkyMjtcclxuICAgICAgICAgICAgICAgICAgICBib3gtc2hhZG93OiAwIDAgMTBweCAjZWU5OTIyO1xyXG4gICAgICAgICAgICAgICAgfVxyXG4gICAgICAgICAgICAgICAgJi5ibGFuayB7XHJcbiAgICAgICAgICAgICAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogICMwMDAyMDA7XHJcbiAgICAgICAgICAgICAgICAgICAgYm94LXNoYWRvdzogMCAwIDEwcHggIzAwMDIwMDtcclxuICAgICAgICAgICAgICAgIH1cclxuICAgICAgICAgICAgICAgICYucGluayB7XHJcbiAgICAgICAgICAgICAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogICNGRkIxQjA7XHJcbiAgICAgICAgICAgICAgICAgICAgYm94LXNoYWRvdzogMCAwIDEwcHggI0ZGQjFCMDtcclxuICAgICAgICAgICAgICAgIH1cclxuICAgICAgICAgICAgICAgICYuZ3JlZW4ge1xyXG4gICAgICAgICAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6ICAjMmZiMzAzO1xyXG4gICAgICAgICAgICAgICAgICAgIGJveC1zaGFkb3c6IDAgMCAxMHB4ICMyZmIzMDM7XHJcbiAgICAgICAgICAgICAgICB9XHJcbiAgICAgICAgICAgICAgICAmOmhvdmVyIHtcclxuICAgICAgICAgICAgICAgICAgICB0cmFuc2Zvcm06IHNjYWxlKDEuMSk7XHJcbiAgICAgICAgICAgICAgICB9XHJcbiAgICAgICAgICAgIH1cclxuICAgICAgICB9XHJcbiAgICB9XHJcbiAgICBpbnB1dCB7XHJcbiAgICAgICAgd2lkdGg6IDEwMCU7XHJcbiAgICAgICAgZm9udC1zaXplOiAyMHB4O1xyXG4gICAgICAgIGJvcmRlcjogbm9uZTtcclxuICAgICAgICBvdXRsaW5lOiBub25lO1xyXG4gICAgICAgIHBhZGRpbmc6IDRweCA4cHg7XHJcbiAgICAgICAgYm9yZGVyLXJhZGl1czogNHB4O1xyXG4gICAgfVxyXG4gICAgc2VsZWN0IHtcclxuICAgICAgICB3aWR0aDogMTAwJTtcclxuICAgICAgICBoZWlnaHQ6IDMwcHg7XHJcbiAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogI0ZGRjtcclxuICAgICAgICBib3JkZXItcmFkaXVzOiA1cHg7XHJcbiAgICAgICAgb3V0bGluZTogbm9uZTtcclxuICAgICAgICBib3JkZXI6IG5vbmU7XHJcbiAgICAgICAgZm9udC1zaXplOiAxOHB4O1xyXG4gICAgICAgIHBhZGRpbmctbGVmdDogNnB4O1xyXG4gICAgfVxyXG59XHJcblxyXG5cclxuQG1lZGlhIG9ubHkgc2NyZWVuIGFuZCAobWluLXdpZHRoOjMyMHB4KSBhbmQgKG1heC1oZWlnaHQ6NzY3cHgpIHtcclxuICAgIC5zZXR0aW5nLXBhbmVsIHtcclxuICAgICAgICB3aWR0aDogNzAlO1xyXG4gICAgICAgIC53YXBwZXItc2Nyb2xsIHtcclxuICAgICAgICAgICAgaGVpZ2h0OiAxNjBweDtcclxuICAgICAgICAgICAgb3ZlcmZsb3cteTogc2Nyb2xsO1xyXG4gICAgICAgIH1cclxuICAgIH1cclxuICAgIFxyXG59XHJcblxyXG4uX25nY29udGVudC1jMTR7XHJcbiAgIFxyXG59Il19 */"

/***/ }),

/***/ "./src/app/core/updata/updata.ts":
/*!***************************************!*\
  !*** ./src/app/core/updata/updata.ts ***!
  \***************************************/
/*! exports provided: UpdataComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UpdataComponent", function() { return UpdataComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
/* harmony import */ var src_app_services_global_operator_service__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! src/app/services/global-operator.service */ "./src/app/services/global-operator.service.ts");
/* harmony import */ var src_app_services_store_service__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! src/app/services/store.service */ "./src/app/services/store.service.ts");
/* harmony import */ var src_app_services_upload_service__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! src/app/services/upload.service */ "./src/app/services/upload.service.ts");
/* harmony import */ var _ngx_translate_core__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @ngx-translate/core */ "./node_modules/@ngx-translate/core/fesm5/ngx-translate-core.js");
/* harmony import */ var src_app_services_blockly_editor_service__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! src/app/services/blockly-editor.service */ "./src/app/services/blockly-editor.service.ts");
/* harmony import */ var src_app_shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! src/app/shared/mask/mask.component */ "./src/app/shared/mask/mask.component.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};









var UpdataComponent = /** @class */ (function () {
    function UpdataComponent(globalOperatorSrv, storeSrv, uploadSrv, translateSrv, blocklyEditorSrv) {
        this.globalOperatorSrv = globalOperatorSrv;
        this.storeSrv = storeSrv;
        this.uploadSrv = uploadSrv;
        this.translateSrv = translateSrv;
        this.blocklyEditorSrv = blocklyEditorSrv;
        this.languageList = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["LANG"];
        this.allapikey = [];
        this.categoryArr = ['core', 'stick', 'stick-C'];
    }
    UpdataComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.defineType = localStorage.getItem('_type') || 'core';
        this.apikey$ = this.storeSrv.getApikey();
        setTimeout(function () {
            _this.allapikey = _this.storeSrv.getAllkey();
        }, 0);
    };
    UpdataComponent.prototype.ok = function (apikey, lang, cate) {
        var _this = this;
        if (this.storeSrv.apiKey.value !== apikey) {
            this.storeSrv.setApikey(apikey);
            this.storeSrv.setAllkey(apikey);
            this.uploadSrv.getDeviceInfo().subscribe();
        }
        if (this.storeSrv.defaultLanguage !== lang) {
            this.storeSrv.loddingMODE.next(true);
            var xml = window['Blockly'].Xml.workspaceToDom(window['BlocklyEditor']);
            var xml_text = window['Blockly'].Xml.domToText(xml);
            window.sessionStorage.setItem('xml', xml_text);
            this.storeSrv.setLanguage(lang);
            this.blocklyEditorSrv.init({ language: lang, wrapperId: 'wrapper_blockly_editor', toolboxId: 'wrapper_blockly_toolbox' });
            this.translateSrv.use(lang);
            // 延时1S 解决语言切换后units Blockly显示不出来
            setTimeout(function () {
                _this.storeSrv.componentList.next(_this.storeSrv.componentList.value);
                _this.storeSrv.unitList.next(_this.storeSrv.unitList.value);
            }, 1000);
        }
        if (localStorage.getItem('_type') !== cate) {
            // this.storeSrv.loddingMODE.next(true);
            this.storeSrv.setType(cate);
            localStorage.setItem('_type', cate);
        }
        this.globalOperatorSrv.maskModal.instance.removeMask();
    };
    UpdataComponent.prototype.cancel = function () {
        var _this = this;
        this.globalOperatorSrv.maskModal.instance.removeMask(function () {
            var modal = _this.globalOperatorSrv.createMaskModal(src_app_shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_7__["MaskComponent"]);
            modal.instance.createDynamicComponent(src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["DYNAMIC_COMPONENT_TYPE"].SETTING_PANEL);
        });
    };
    UpdataComponent.prototype.cancel_show = function () {
        // this.globalOperatorSrv.maskModal.instance.ngOnInit();//destroy /createDynamicComponent
    };
    UpdataComponent.prototype.enter = function (ev, apikey, lang, cate) {
        if (ev.keyCode === 13) {
            return this.ok(apikey, lang, cate);
        }
    };
    UpdataComponent.prototype.convertUpperCase = function (ev) {
        this.apikeyBox.nativeElement.value = ev.target.value.toUpperCase();
    };
    UpdataComponent.prototype.apifocus = function () {
        this.show = true;
    };
    UpdataComponent.prototype.apiblur = function () {
        this.show = false;
    };
    UpdataComponent.prototype.selectapi = function (e) {
        this.apikeyBox.nativeElement.value = e.toUpperCase();
    };
    UpdataComponent.prototype.settheme = function (e) {
        if (document.documentElement.hasAttribute('theme')) {
            document.documentElement.removeAttribute('theme');
        }
        document.documentElement.setAttribute('theme', e);
        localStorage.setItem('theme', e);
    };
    UpdataComponent.prototype.close = function () {
    };
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ViewChild"])('apikeyBox'),
        __metadata("design:type", _angular_core__WEBPACK_IMPORTED_MODULE_0__["ElementRef"])
    ], UpdataComponent.prototype, "apikeyBox", void 0);
    UpdataComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-updata',
            template: __webpack_require__(/*! ./updata.html */ "./src/app/core/updata/updata.html"),
            styles: [__webpack_require__(/*! ./updata.scss */ "./src/app/core/updata/updata.scss")]
        })
        // tslint:disable-next-line: component-class-suffix
        // tslint:disable-next-line: class-name
        ,
        __metadata("design:paramtypes", [src_app_services_global_operator_service__WEBPACK_IMPORTED_MODULE_2__["GlobalOperatorService"],
            src_app_services_store_service__WEBPACK_IMPORTED_MODULE_3__["StoreService"],
            src_app_services_upload_service__WEBPACK_IMPORTED_MODULE_4__["UploadService"],
            _ngx_translate_core__WEBPACK_IMPORTED_MODULE_5__["TranslateService"],
            src_app_services_blockly_editor_service__WEBPACK_IMPORTED_MODULE_6__["BlocklyEditorService"]])
    ], UpdataComponent);
    return UpdataComponent;
}());

function close() {
}


/***/ }),

/***/ "./src/app/domain/component/BaseComponent.class.ts":
/*!*********************************************************!*\
  !*** ./src/app/domain/component/BaseComponent.class.ts ***!
  \*********************************************************/
/*! exports provided: BaseComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "BaseComponent", function() { return BaseComponent; });
/* harmony import */ var _utils_common_tool__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ../../utils/common-tool */ "./src/app/utils/common-tool.ts");
/* harmony import */ var _utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../../utils/common-data */ "./src/app/utils/common-data.ts");


var BaseComponent = /** @class */ (function () {
    function BaseComponent(prop) {
        this.id = prop.id || _utils_common_tool__WEBPACK_IMPORTED_MODULE_0__["genComponentId"]();
        this.createTime = prop.createTime || Date.now();
    }
    /**
     * 判断是否可更改属性
     * @param key 属性名
     */
    BaseComponent.prototype.checkSettable = function (key) {
        if (key === _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].ID || key === _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].TYPE || key === _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].CREATE_TIME)
            return false;
        return true;
    };
    /**
     * 获取组件属性
     * @param key 属性名
     */
    BaseComponent.prototype.getProp = function (key) {
        return this[key];
    };
    /**
     * 修改组件属性
     * 取整
     * @param key 属性名
     * @param value 属性值
     */
    BaseComponent.prototype.setProp = function (key, value) {
        if (!this.checkSettable(key))
            return;
        if (key === _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].WIDTH ||
            key === _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].HEIGHT ||
            key === _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].X ||
            key === _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].Y ||
            key === _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].RADIUS ||
            key === _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].LAYER || key === _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].ROTATION) {
            return this[key] = parseInt(value);
        }
        else if (key === _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].VISIBILITY) {
            return this[key] = value == 'true';
        }
        this[key] = value;
    };
    /** 转化颜色字符串格式 */
    BaseComponent.prototype.transformColorStr = function (color) {
        return color.replace('#', '0x');
    };
    return BaseComponent;
}());



/***/ }),

/***/ "./src/app/domain/component/ButtonComponent.class.ts":
/*!***********************************************************!*\
  !*** ./src/app/domain/component/ButtonComponent.class.ts ***!
  \***********************************************************/
/*! exports provided: ButtonIndex, ButtonComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "ButtonIndex", function() { return ButtonIndex; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "ButtonComponent", function() { return ButtonComponent; });
/* harmony import */ var _BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseComponent.class */ "./src/app/domain/component/BaseComponent.class.ts");
/* harmony import */ var _utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../../utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var ButtonIndex;
(function (ButtonIndex) {
    ButtonIndex[ButtonIndex["A"] = 0] = "A";
    ButtonIndex[ButtonIndex["B"] = 1] = "B";
    ButtonIndex[ButtonIndex["C"] = 2] = "C";
})(ButtonIndex || (ButtonIndex = {}));
var ButtonComponent = /** @class */ (function (_super) {
    __extends(ButtonComponent, _super);
    function ButtonComponent(prop) {
        var _this = _super.call(this, prop) || this;
        /** 组件名 */
        _this.name = 'button';
        /** 按钮索引 */
        _this.buttonIndex = ButtonIndex.A;
        /** X坐标 */
        _this.x = 105;
        /** Y坐标 */
        _this.y = 381;
        /** 宽 */
        _this.width = 64;
        /** 高 */
        _this.height = 24;
        /** 文本 */
        _this.text = 'Button';
        /** 可见性 */
        _this.visibility = false;
        /** 组件Svg */
        _this.componentSvg = null;
        _this.type = _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].BUTTON;
        _this.buttonIndex = prop.buttonIndex;
        _this.name = prop.name;
        switch (prop.buttonIndex) {
            case ButtonIndex.A:
                _this.id = '____buttonA';
                _this.name = 'ButtonA';
                _this.text = prop.text || 'ButtonA';
                _this.x = 35;
                _this.y = 216;
                break;
            case ButtonIndex.B:
                _this.id = '____buttonB';
                _this.name = 'ButtonB';
                _this.text = prop.text || 'ButtonB';
                _this.x = 125;
                _this.y = 216;
                break;
            case ButtonIndex.C:
                _this.id = '____buttonC';
                _this.name = 'ButtonC';
                _this.text = prop.text || 'ButtonC';
                _this.x = 215;
                _this.y = 216;
                break;
            default:
                return;
        }
        _this.visibility = prop.visibility || false;
        _this.componentSvg = prop.componentSvg || null;
        return _this;
    }
    ButtonComponent.prototype.getAllProps = function () {
        var _a, _b;
        return [
            (_a = {}, _a[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].TEXT] = this.text, _a),
            (_b = {}, _b[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].VISIBILITY] = this.visibility, _b)
        ];
    };
    ButtonComponent.prototype.transformToCode = function () {
        var btnName = '';
        switch (this.name) {
            case 'ButtonA':
                btnName = 'btnA';
                break;
            case 'ButtonB':
                btnName = 'btnB';
                break;
            case 'ButtonC':
                btnName = 'btnC';
                break;
        }
        return btnName + " = M5Button(name=\"" + this.name + "\", text=\"" + this.text + "\", visibility=" + (this.visibility ? 'True' : 'False') + ")\n";
    };
    return ButtonComponent;
}(_BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__["BaseComponent"]));



/***/ }),

/***/ "./src/app/domain/component/CircleComponent.class.ts":
/*!***********************************************************!*\
  !*** ./src/app/domain/component/CircleComponent.class.ts ***!
  \***********************************************************/
/*! exports provided: CircleComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "CircleComponent", function() { return CircleComponent; });
/* harmony import */ var _BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseComponent.class */ "./src/app/domain/component/BaseComponent.class.ts");
/* harmony import */ var _utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../../utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var CircleComponent = /** @class */ (function (_super) {
    __extends(CircleComponent, _super);
    function CircleComponent(prop) {
        var _this = _super.call(this, prop) || this;
        /** 组件名 */
        _this.name = 'circle';
        /** X坐标 */
        _this.x = 0;
        /** Y坐标 */
        _this.y = 0;
        /** 半径 */
        _this.radius = 15;
        /** 边框颜色 */
        _this.borderColor = '#FFFFFF';
        /** 填充颜色 */
        _this.backgroundColor = '#FFFFFF';
        /** 组件Svg对象 */
        _this.componentSvg = null;
        _this.type = _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].CIRCLE;
        _this.name = prop.name;
        _this.layer = prop.layer;
        _this.x = Math.floor(prop.x) || 0;
        _this.y = Math.floor(prop.y) || 0;
        _this.radius = Math.floor(prop.radius) || 15;
        _this.borderColor = prop.borderColor || '#FFFFFF';
        _this.backgroundColor = prop.backgroundColor || '#FFFFFF';
        _this.componentSvg = prop.componentSvg || null;
        return _this;
    }
    CircleComponent.prototype.getAllProps = function () {
        var _a, _b, _c, _d, _e, _f, _g, _h, _j, _k;
        return [
            (_a = {}, _a[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].ID] = this.id, _a),
            (_b = {}, _b[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].CREATE_TIME] = this.createTime, _b),
            (_c = {}, _c[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].TYPE] = this.type, _c),
            (_d = {}, _d[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].NAME] = this.name, _d),
            (_e = {}, _e[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].X] = this.x, _e),
            (_f = {}, _f[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].Y] = this.y, _f),
            (_g = {}, _g[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].RADIUS] = this.radius, _g),
            (_h = {}, _h[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].BORDER_COLOR] = this.borderColor, _h),
            (_j = {}, _j[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].BACKGROUND_COLOR] = this.backgroundColor, _j),
            (_k = {}, _k[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].LAYER] = this.layer, _k),
        ];
    };
    CircleComponent.prototype.transformToCode = function () {
        return this.name + " = M5Circle(" + this.x + ", " + this.y + ", " + this.radius + ", " + this.transformColorStr(this.backgroundColor) + ", " + this.transformColorStr(this.borderColor) + ")\n";
    };
    return CircleComponent;
}(_BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__["BaseComponent"]));



/***/ }),

/***/ "./src/app/domain/component/ImageComponent.class.ts":
/*!**********************************************************!*\
  !*** ./src/app/domain/component/ImageComponent.class.ts ***!
  \**********************************************************/
/*! exports provided: ImageComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "ImageComponent", function() { return ImageComponent; });
/* harmony import */ var _BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseComponent.class */ "./src/app/domain/component/BaseComponent.class.ts");
/* harmony import */ var _utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../../utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var ImageComponent = /** @class */ (function (_super) {
    __extends(ImageComponent, _super);
    function ImageComponent(prop) {
        var _this = _super.call(this, prop) || this;
        /** 组件名 */
        _this.name = 'image';
        /** X坐标 */
        _this.x = 0;
        /** Y坐标 */
        _this.y = 0;
        /** 图片路径 */
        _this.imagePath = 'default.jpg';
        /** 可见性 */
        _this.visibility = true;
        /** 组件Svg对象 */
        _this.componentSvg = null;
        _this.type = _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].IMAGE;
        _this.name = prop.name;
        _this.layer = prop.layer;
        _this.x = Math.floor(prop.x) || 0;
        _this.y = Math.floor(prop.y) || 0;
        _this.imagePath = prop.imagePath || 'default.jpg';
        _this.visibility = prop.visibility || true;
        _this.componentSvg = prop.componentSvg || null;
        return _this;
    }
    ImageComponent.prototype.getAllProps = function () {
        var _a, _b, _c, _d, _e, _f, _g, _h, _j;
        return [
            (_a = {}, _a[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].ID] = this.id, _a),
            (_b = {}, _b[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].CREATE_TIME] = this.createTime, _b),
            (_c = {}, _c[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].TYPE] = this.type, _c),
            (_d = {}, _d[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].NAME] = this.name, _d),
            (_e = {}, _e[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].X] = this.x, _e),
            (_f = {}, _f[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].Y] = this.y, _f),
            (_g = {}, _g[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].IMAGE_PATH] = this.imagePath, _g),
            (_h = {}, _h[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].VISIBILITY] = this.visibility, _h),
            (_j = {}, _j[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].LAYER] = this.layer, _j),
        ];
    };
    ImageComponent.prototype.transformToCode = function () {
        return this.name + " = M5Img(" + this.x + ", " + this.y + ", \"res/" + this.imagePath + "\", " + (this.visibility ? 'True' : 'False') + ")\n";
    };
    return ImageComponent;
}(_BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__["BaseComponent"]));



/***/ }),

/***/ "./src/app/domain/component/LabelComponent.class.ts":
/*!**********************************************************!*\
  !*** ./src/app/domain/component/LabelComponent.class.ts ***!
  \**********************************************************/
/*! exports provided: LabelComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "LabelComponent", function() { return LabelComponent; });
/* harmony import */ var _BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseComponent.class */ "./src/app/domain/component/BaseComponent.class.ts");
/* harmony import */ var _utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../../utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var LabelComponent = /** @class */ (function (_super) {
    __extends(LabelComponent, _super);
    function LabelComponent(prop) {
        var _this = _super.call(this, prop) || this;
        /** 组件名 */
        _this.name = 'label';
        /** X坐标 */
        _this.x = 0;
        /** Y坐标 */
        _this.y = 0;
        /** 字体颜色 */
        _this.color = '#FFFFFF';
        /** 标题文本 */
        _this.text = 'Text';
        /** 文本字体 */
        _this.font = _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["FONT_ALIAS"].DEFAULT;
        /*rotation  旋转角度*/
        _this.rotation = 0;
        /** 组件Svg对象 */
        _this.componentSvg = null;
        /** 等比系数 */
        _this.eRetio = 1;
        _this.type = _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].LABEL;
        _this.name = prop.name;
        _this.eRetio = prop.eretio;
        _this.layer = prop.layer;
        _this.x = Math.floor(prop.x) || 0;
        _this.y = Math.floor(prop.y) || 0;
        _this.color = prop.color || '#FFFFFF';
        _this.text = prop.text || 'Text';
        _this.font = prop.font || _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["FONT_ALIAS"].DEFAULT;
        _this.componentSvg = prop.componentSvg || null;
        _this.rotation = prop.rotation || 0;
        return _this;
    }
    LabelComponent.prototype.getAllProps = function () {
        var _a, _b, _c, _d, _e, _f, _g, _h, _j, _k, _l;
        return [
            (_a = {}, _a[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].ID] = this.id, _a),
            (_b = {}, _b[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].CREATE_TIME] = this.createTime, _b),
            (_c = {}, _c[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].TYPE] = this.type, _c),
            (_d = {}, _d[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].NAME] = this.name, _d),
            (_e = {}, _e[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].X] = this.x, _e),
            (_f = {}, _f[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].Y] = this.y, _f),
            (_g = {}, _g[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].COLOR] = this.color, _g),
            (_h = {}, _h[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].TEXT] = this.text, _h),
            (_j = {}, _j[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].FONT] = this.font, _j),
            (_k = {}, _k[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].ROTATION] = this.rotation, _k),
            (_l = {}, _l[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].LAYER] = this.layer, _l),
        ];
    };
    // 变化执行
    LabelComponent.prototype.transformToCode = function () {
        // console.log(`${this.name} = M5TextBox(${Math.floor(this.x)}, ${Math.floor(this.y)}, "${this.text}", ${this.font},${this.transformColorStr(this.color)}, ${this.rotation})\n`)
        return this.name + " = M5TextBox(" + Math.floor(this.x) + ", " + Math.floor(this.y) + ", \"" + this.text + "\", " + this.font + "," + this.transformColorStr(this.color) + ", rotate=" + this.rotation + ")\n";
    };
    return LabelComponent;
}(_BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__["BaseComponent"]));



/***/ }),

/***/ "./src/app/domain/component/RectangleComponent.class.ts":
/*!**************************************************************!*\
  !*** ./src/app/domain/component/RectangleComponent.class.ts ***!
  \**************************************************************/
/*! exports provided: RectangleComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "RectangleComponent", function() { return RectangleComponent; });
/* harmony import */ var _BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseComponent.class */ "./src/app/domain/component/BaseComponent.class.ts");
/* harmony import */ var _utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../../utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var RectangleComponent = /** @class */ (function (_super) {
    __extends(RectangleComponent, _super);
    function RectangleComponent(prop) {
        var _this = _super.call(this, prop) || this;
        /** 组件名 */
        _this.name = 'rectangle';
        /** X坐标 */
        _this.x = 0;
        /** Y坐标 */
        _this.y = 0;
        /** 宽 */
        _this.width = 30;
        /** 宽 */
        _this.height = 30;
        /** 边框颜色 */
        _this.borderColor = '#FFFFFF';
        /** 填充颜色 */
        _this.backgroundColor = '#FFFFFF';
        /** 组件Svg对象 */
        _this.componentSvg = null;
        /** 等比系数 */
        _this.eRetio = 1;
        _this.type = _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].RECTANGLE;
        _this.name = prop.name;
        _this.eRetio = prop.eretio;
        _this.layer = prop.layer;
        _this.x = Math.floor(prop.x) || 0;
        _this.y = Math.floor(prop.y) || 0;
        _this.width = Math.floor(prop.width) || 30;
        _this.height = Math.floor(prop.height) || 30;
        _this.borderColor = prop.borderColor || '#FFFFFF';
        _this.backgroundColor = prop.backgroundColor || '#FFFFFF';
        _this.componentSvg = prop.componentSvg || null;
        return _this;
    }
    RectangleComponent.prototype.getAllProps = function () {
        var _a, _b, _c, _d, _e, _f, _g, _h, _j, _k, _l;
        return [
            (_a = {}, _a[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].ID] = this.id, _a),
            (_b = {}, _b[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].CREATE_TIME] = this.createTime, _b),
            (_c = {}, _c[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].TYPE] = this.type, _c),
            (_d = {}, _d[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].NAME] = this.name, _d),
            (_e = {}, _e[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].X] = this.x, _e),
            (_f = {}, _f[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].Y] = this.y, _f),
            (_g = {}, _g[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].WIDTH] = this.width, _g),
            (_h = {}, _h[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].HEIGHT] = this.height, _h),
            (_j = {}, _j[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].BORDER_COLOR] = this.borderColor, _j),
            (_k = {}, _k[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].BACKGROUND_COLOR] = this.backgroundColor, _k),
            (_l = {}, _l[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].LAYER] = this.layer, _l),
        ];
    };
    RectangleComponent.prototype.transformToCode = function () {
        // tslint:disable-next-line:max-line-length
        return this.name + " = M5Rect(" + Math.floor(this.x) + ", " + Math.floor(this.y) + ", " + Math.floor(this.width) + ", " + Math.floor(this.height) + ", " + this.transformColorStr(this.backgroundColor) + ", " + this.transformColorStr(this.borderColor) + ")\n";
    };
    return RectangleComponent;
}(_BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__["BaseComponent"]));



/***/ }),

/***/ "./src/app/domain/component/ScreenComponent.class.ts":
/*!***********************************************************!*\
  !*** ./src/app/domain/component/ScreenComponent.class.ts ***!
  \***********************************************************/
/*! exports provided: ScreenComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "ScreenComponent", function() { return ScreenComponent; });
/* harmony import */ var _BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseComponent.class */ "./src/app/domain/component/BaseComponent.class.ts");
/* harmony import */ var _utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../../utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var ScreenComponent = /** @class */ (function (_super) {
    __extends(ScreenComponent, _super);
    // score 屏幕定义
    function ScreenComponent(prop) {
        var _this = _super.call(this, prop) || this;
        /** 名称 */
        _this.name = 'Screen';
        /** X坐标 */
        _this.x = 0;
        /** Y坐标 */
        _this.y = 0;
        /** 宽 */
        _this.width = 320;
        /** 高 */
        _this.height = 240;
        /** 背景色 */
        _this.backgroundColor = '#111111';
        /** 背景图 */
        _this.backgroundImage = '';
        /** 组件Svg */
        _this.componentSvg = null;
        _this.id = '____screen';
        _this.type = _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].SCREEN;
        _this.x = prop.x || 0;
        _this.y = prop.y || 0;
        _this.width = prop.width || 320;
        _this.height = prop.height || 240;
        _this.backgroundColor = prop.backgroundColor || '#222222';
        _this.backgroundImage = prop.backgroundImage || '';
        _this.componentSvg = prop.componentSvg || null;
        return _this;
    }
    ScreenComponent.prototype.getAllProps = function () {
        var _a;
        return [
            (_a = {}, _a[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].BACKGROUND_COLOR] = this.backgroundColor, _a),
        ];
    };
    ScreenComponent.prototype.transformToCode = function () {
        // return `clear_bg(${this.transformColorStr(this.backgroundColor)})\n`;
        return "";
    };
    return ScreenComponent;
}(_BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__["BaseComponent"]));



/***/ }),

/***/ "./src/app/domain/component/TitleComponent.class.ts":
/*!**********************************************************!*\
  !*** ./src/app/domain/component/TitleComponent.class.ts ***!
  \**********************************************************/
/*! exports provided: TitleComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "TitleComponent", function() { return TitleComponent; });
/* harmony import */ var _BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseComponent.class */ "./src/app/domain/component/BaseComponent.class.ts");
/* harmony import */ var _utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../../utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


/**
 * 标题组件
 */
var TitleComponent = /** @class */ (function (_super) {
    __extends(TitleComponent, _super);
    function TitleComponent(prop) {
        var _this = _super.call(this, prop) || this;
        /** 组件名 */
        _this.name = 'title';
        /** X坐标 */
        _this.x = 0;
        /** Y坐标 */
        _this.y = 0;
        /** 宽 */
        _this.width = 320;
        /** 高 */
        _this.height = 20;
        /** 字体颜色 */
        _this.color = '#FFFFFF';
        /** 背景颜色 */
        _this.backgroundColor = '#0000FF';
        /** 标题文本 */
        _this.text = 'Title';
        /** 组件Svg对象 */
        _this.componentSvg = null;
        _this.type = _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].TITLE;
        _this.name = prop.name;
        _this.layer = prop.layer;
        _this.x = prop.x || 0;
        _this.y = prop.y || 0;
        _this.width = prop.width || 320;
        _this.height = prop.height || 20;
        _this.color = prop.color || '#FFFFFF';
        _this.backgroundColor = prop.backgroundColor || '#0000FF';
        _this.text = prop.text || 'Title';
        _this.componentSvg = prop.componentSvg || null;
        return _this;
    }
    TitleComponent.prototype.getAllProps = function () {
        var _a, _b, _c, _d, _e, _f, _g, _h;
        return [
            (_a = {}, _a[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].ID] = this.id, _a),
            (_b = {}, _b[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].CREATE_TIME] = this.createTime, _b),
            (_c = {}, _c[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].TYPE] = this.type, _c),
            (_d = {}, _d[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].NAME] = this.name, _d),
            (_e = {}, _e[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].COLOR] = this.color, _e),
            (_f = {}, _f[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].BACKGROUND_COLOR] = this.backgroundColor, _f),
            (_g = {}, _g[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].TEXT] = this.text, _g),
            (_h = {}, _h[_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["COMPONENT_ALIAS"].LAYER] = this.layer, _h),
        ];
    };
    TitleComponent.prototype.transformToCode = function () {
        return this.name + " = M5Title(title=\"" + this.text + "\", fgcolor=" + this.transformColorStr(this.color) + ", bgcolor=" + this.transformColorStr(this.backgroundColor) + ")\n";
    };
    return TitleComponent;
}(_BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__["BaseComponent"]));



/***/ }),

/***/ "./src/app/domain/component/index.ts":
/*!*******************************************!*\
  !*** ./src/app/domain/component/index.ts ***!
  \*******************************************/
/*! exports provided: BaseComponent, TitleComponent, LabelComponent, RectangleComponent, CircleComponent, ImageComponent, ScreenComponent, ButtonIndex, ButtonComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseComponent.class */ "./src/app/domain/component/BaseComponent.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "BaseComponent", function() { return _BaseComponent_class__WEBPACK_IMPORTED_MODULE_0__["BaseComponent"]; });

/* harmony import */ var _TitleComponent_class__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ./TitleComponent.class */ "./src/app/domain/component/TitleComponent.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "TitleComponent", function() { return _TitleComponent_class__WEBPACK_IMPORTED_MODULE_1__["TitleComponent"]; });

/* harmony import */ var _LabelComponent_class__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./LabelComponent.class */ "./src/app/domain/component/LabelComponent.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "LabelComponent", function() { return _LabelComponent_class__WEBPACK_IMPORTED_MODULE_2__["LabelComponent"]; });

/* harmony import */ var _RectangleComponent_class__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./RectangleComponent.class */ "./src/app/domain/component/RectangleComponent.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "RectangleComponent", function() { return _RectangleComponent_class__WEBPACK_IMPORTED_MODULE_3__["RectangleComponent"]; });

/* harmony import */ var _CircleComponent_class__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ./CircleComponent.class */ "./src/app/domain/component/CircleComponent.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "CircleComponent", function() { return _CircleComponent_class__WEBPACK_IMPORTED_MODULE_4__["CircleComponent"]; });

/* harmony import */ var _ImageComponent_class__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ./ImageComponent.class */ "./src/app/domain/component/ImageComponent.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "ImageComponent", function() { return _ImageComponent_class__WEBPACK_IMPORTED_MODULE_5__["ImageComponent"]; });

/* harmony import */ var _ScreenComponent_class__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./ScreenComponent.class */ "./src/app/domain/component/ScreenComponent.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "ScreenComponent", function() { return _ScreenComponent_class__WEBPACK_IMPORTED_MODULE_6__["ScreenComponent"]; });

/* harmony import */ var _ButtonComponent_class__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ./ButtonComponent.class */ "./src/app/domain/component/ButtonComponent.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "ButtonIndex", function() { return _ButtonComponent_class__WEBPACK_IMPORTED_MODULE_7__["ButtonIndex"]; });

/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "ButtonComponent", function() { return _ButtonComponent_class__WEBPACK_IMPORTED_MODULE_7__["ButtonComponent"]; });











/***/ }),

/***/ "./src/app/domain/editor/UIEditorToolbar.class.ts":
/*!********************************************************!*\
  !*** ./src/app/domain/editor/UIEditorToolbar.class.ts ***!
  \********************************************************/
/*! exports provided: ToolItem, ToolBar */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "ToolItem", function() { return ToolItem; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "ToolBar", function() { return ToolBar; });
/**
 * 工具项类
 */
var ToolItem = /** @class */ (function () {
    function ToolItem(obj) {
        this.icon = '';
        this.builder = null;
        this.icon = obj.icon;
        this.builder = obj.builder;
    }
    return ToolItem;
}());

/**
 * 工具栏类
 */
var ToolBar = /** @class */ (function () {
    function ToolBar(toolList) {
        /** 工具项数组 */
        this.toolList = [];
        this.toolList = toolList;
    }
    return ToolBar;
}());



/***/ }),

/***/ "./src/app/domain/unit/BaseUnit.class.ts":
/*!***********************************************!*\
  !*** ./src/app/domain/unit/BaseUnit.class.ts ***!
  \***********************************************/
/*! exports provided: BaseUnit */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "BaseUnit", function() { return BaseUnit; });
/* harmony import */ var src_app_utils_common_tool__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! src/app/utils/common-tool */ "./src/app/utils/common-tool.ts");

/** Unit基类 */
var BaseUnit = /** @class */ (function () {
    function BaseUnit() {
        this.id = Object(src_app_utils_common_tool__WEBPACK_IMPORTED_MODULE_0__["genComponentId"])();
        this.createTime = Date.now();
    }
    return BaseUnit;
}());



/***/ }),

/***/ "./src/app/domain/unit/Unit396.class.ts":
/*!**********************************************!*\
  !*** ./src/app/domain/unit/Unit396.class.ts ***!
  \**********************************************/
/*! exports provided: Unit396 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "Unit396", function() { return Unit396; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var Unit396 = /** @class */ (function (_super) {
    __extends(Unit396, _super);
    function Unit396(opt) {
        var _this = _super.call(this) || this;
        _this.hidden = true;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].TPNX;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = '3.96.png';
        return _this;
    }
    Unit396.prototype.getCode = function () {
    };
    return Unit396;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitADC.class.ts":
/*!**********************************************!*\
  !*** ./src/app/domain/unit/UnitADC.class.ts ***!
  \**********************************************/
/*! exports provided: UnitADC */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitADC", function() { return UnitADC; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitADC = /** @class */ (function (_super) {
    __extends(UnitADC, _super);
    // hidden = true
    function UnitADC(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].ADC;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'adc.png';
        return _this;
    }
    UnitADC.prototype.getCode = function () {
        return this.name + " = units.get(units.adc,units.PORT" + this.port + ")\n";
    };
    return UnitADC;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitAngle.class.ts":
/*!************************************************!*\
  !*** ./src/app/domain/unit/UnitAngle.class.ts ***!
  \************************************************/
/*! exports provided: UnitAngle */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitAngle", function() { return UnitAngle; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitAngle = /** @class */ (function (_super) {
    __extends(UnitAngle, _super);
    function UnitAngle(opt) {
        var _this = _super.call(this) || this;
        _this.stickType = 'stick';
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].ANGLE;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'angle.png';
        return _this;
    }
    UnitAngle.prototype.getCode = function () {
        return this.name + " = units.ANGLE(units.PORT" + this.port + ")\n";
    };
    return UnitAngle;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitButton.class.ts":
/*!*************************************************!*\
  !*** ./src/app/domain/unit/UnitButton.class.ts ***!
  \*************************************************/
/*! exports provided: UnitButton */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitButton", function() { return UnitButton; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitButton = /** @class */ (function (_super) {
    __extends(UnitButton, _super);
    // hidden = true;
    function UnitButton(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].BUTTON;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'button.png';
        return _this;
    }
    UnitButton.prototype.getCode = function () {
        return this.name + " = units.get(units.button,units.PORT" + this.port + ")\n";
    };
    return UnitButton;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitCardKb.class.ts":
/*!*************************************************!*\
  !*** ./src/app/domain/unit/UnitCardKb.class.ts ***!
  \*************************************************/
/*! exports provided: UnitCardkb */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitCardkb", function() { return UnitCardkb; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitCardkb = /** @class */ (function (_super) {
    __extends(UnitCardkb, _super);
    function UnitCardkb(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].CARDKB;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].A;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'cardkb.png';
        return _this;
    }
    UnitCardkb.prototype.getCode = function () {
        return this.name + " = units.get(units.cardKB,units.PORT" + this.port + ")\n";
    };
    return UnitCardkb;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitColor.class.ts":
/*!************************************************!*\
  !*** ./src/app/domain/unit/UnitColor.class.ts ***!
  \************************************************/
/*! exports provided: UnitColor */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitColor", function() { return UnitColor; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitColor = /** @class */ (function (_super) {
    __extends(UnitColor, _super);
    // hidden = true;
    function UnitColor(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].COLOR;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].A;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'color.png';
        return _this;
    }
    UnitColor.prototype.getCode = function () {
        return this.name + " = units.get(units.color,units.PORT" + this.port + ")\n";
    };
    return UnitColor;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitDAC.class.ts":
/*!**********************************************!*\
  !*** ./src/app/domain/unit/UnitDAC.class.ts ***!
  \**********************************************/
/*! exports provided: UnitDac */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitDac", function() { return UnitDac; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitDac = /** @class */ (function (_super) {
    __extends(UnitDac, _super);
    // hidden = true;
    function UnitDac(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].DAC;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'dac.png';
        return _this;
    }
    UnitDac.prototype.getCode = function () {
        return this.name + " = units.get(units.dac,units.PORT" + this.port + ")\n";
    };
    return UnitDac;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitDualButton.class.ts":
/*!*****************************************************!*\
  !*** ./src/app/domain/unit/UnitDualButton.class.ts ***!
  \*****************************************************/
/*! exports provided: UnitDualButton */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitDualButton", function() { return UnitDualButton; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitDualButton = /** @class */ (function (_super) {
    __extends(UnitDualButton, _super);
    // hidden = true;
    function UnitDualButton(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].DUALBUTTON;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'dualbutton.png';
        return _this;
    }
    UnitDualButton.prototype.getCode = function () {
        return this.name + " = units.get(units.dual_button,units.PORT" + this.port + ")\n";
    };
    return UnitDualButton;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitEarth.class.ts":
/*!************************************************!*\
  !*** ./src/app/domain/unit/UnitEarth.class.ts ***!
  \************************************************/
/*! exports provided: UnitEarth */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitEarth", function() { return UnitEarth; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitEarth = /** @class */ (function (_super) {
    __extends(UnitEarth, _super);
    function UnitEarth(opt) {
        var _this = _super.call(this) || this;
        _this.stickType = 'stick';
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].EARTH;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'earth.png';
        return _this;
    }
    UnitEarth.prototype.getCode = function () {
        return this.name + " = units.Earth(units.PORT" + this.port + ")\n";
    };
    return UnitEarth;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitEnv.class.ts":
/*!**********************************************!*\
  !*** ./src/app/domain/unit/UnitEnv.class.ts ***!
  \**********************************************/
/*! exports provided: UnitEnv */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitEnv", function() { return UnitEnv; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitEnv = /** @class */ (function (_super) {
    __extends(UnitEnv, _super);
    function UnitEnv(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].ENV;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].A;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'env.png';
        return _this;
    }
    UnitEnv.prototype.getCode = function () {
        return this.name + " = units.ENV(units.PORT" + this.port + ")\n";
    };
    return UnitEnv;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitExtio.class.ts":
/*!************************************************!*\
  !*** ./src/app/domain/unit/UnitExtio.class.ts ***!
  \************************************************/
/*! exports provided: UnitExtio */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitExtio", function() { return UnitExtio; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitExtio = /** @class */ (function (_super) {
    __extends(UnitExtio, _super);
    function UnitExtio(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].EXTIO;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].A;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'extio.png';
        return _this;
    }
    UnitExtio.prototype.getCode = function () {
        return this.name + " = units.get(units.ext_io,units.PORT" + this.port + ")\n";
    };
    return UnitExtio;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitFinger.class.ts":
/*!*************************************************!*\
  !*** ./src/app/domain/unit/UnitFinger.class.ts ***!
  \*************************************************/
/*! exports provided: UnitFinger */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitFinger", function() { return UnitFinger; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitFinger = /** @class */ (function (_super) {
    __extends(UnitFinger, _super);
    // hidden = true;
    function UnitFinger(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].FINGER;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].C;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'finger.png';
        return _this;
    }
    UnitFinger.prototype.getCode = function () {
        return this.name + " = units.get(units.finger,units.PORT" + this.port + ")\n";
    };
    return UnitFinger;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitHub.class.ts":
/*!**********************************************!*\
  !*** ./src/app/domain/unit/UnitHub.class.ts ***!
  \**********************************************/
/*! exports provided: UnitHub */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitHub", function() { return UnitHub; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitHub = /** @class */ (function (_super) {
    __extends(UnitHub, _super);
    function UnitHub(opt) {
        var _this = _super.call(this) || this;
        _this.hidden = true;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].HUB;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'hub.png';
        return _this;
    }
    UnitHub.prototype.getCode = function () {
    };
    return UnitHub;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitIR.class.ts":
/*!*********************************************!*\
  !*** ./src/app/domain/unit/UnitIR.class.ts ***!
  \*********************************************/
/*! exports provided: UnitIR */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitIR", function() { return UnitIR; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitIR = /** @class */ (function (_super) {
    __extends(UnitIR, _super);
    // hidden = true;
    function UnitIR(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].IR;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'ir.png';
        return _this;
    }
    UnitIR.prototype.getCode = function () {
        return this.name + " = units.get(units.ir,units.PORT" + this.port + ")\n";
    };
    return UnitIR;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitJoystick.class.ts":
/*!***************************************************!*\
  !*** ./src/app/domain/unit/UnitJoystick.class.ts ***!
  \***************************************************/
/*! exports provided: UnitJoystick */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitJoystick", function() { return UnitJoystick; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitJoystick = /** @class */ (function (_super) {
    __extends(UnitJoystick, _super);
    function UnitJoystick(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].JOYSTICK;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].A;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'joystick.png';
        return _this;
    }
    UnitJoystick.prototype.getCode = function () {
        return this.name + " = units.Joystick(units.PORT" + this.port + ")\n";
    };
    return UnitJoystick;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitLidarCar.class.ts":
/*!***************************************************!*\
  !*** ./src/app/domain/unit/UnitLidarCar.class.ts ***!
  \***************************************************/
/*! exports provided: UnitLidarCar */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitLidarCar", function() { return UnitLidarCar; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitLidarCar = /** @class */ (function (_super) {
    __extends(UnitLidarCar, _super);
    function UnitLidarCar(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].LIDARCAR;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'joystick.png';
        return _this;
    }
    UnitLidarCar.prototype.getCode = function () {
        return this.name + " = units.LidarCar(units.PORT" + this.port + ")\n";
    };
    return UnitLidarCar;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitLight.class.ts":
/*!************************************************!*\
  !*** ./src/app/domain/unit/UnitLight.class.ts ***!
  \************************************************/
/*! exports provided: UnitLight */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitLight", function() { return UnitLight; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitLight = /** @class */ (function (_super) {
    __extends(UnitLight, _super);
    function UnitLight(opt) {
        var _this = _super.call(this) || this;
        _this.stickType = 'stick';
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].LIGHT;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'light.png';
        return _this;
    }
    UnitLight.prototype.getCode = function () {
        return this.name + " = units.Light(units.PORT" + this.port + ")\n";
    };
    return UnitLight;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitM5Camera.class.ts":
/*!***************************************************!*\
  !*** ./src/app/domain/unit/UnitM5Camera.class.ts ***!
  \***************************************************/
/*! exports provided: UnitM5Camera */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitM5Camera", function() { return UnitM5Camera; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitM5Camera = /** @class */ (function (_super) {
    __extends(UnitM5Camera, _super);
    function UnitM5Camera(opt) {
        var _this = _super.call(this) || this;
        _this.hidden = true;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].M5CAMEAR;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'm5camera.png';
        return _this;
    }
    UnitM5Camera.prototype.getCode = function () {
    };
    return UnitM5Camera;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitMakey.class.ts":
/*!************************************************!*\
  !*** ./src/app/domain/unit/UnitMakey.class.ts ***!
  \************************************************/
/*! exports provided: UnitMakey */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitMakey", function() { return UnitMakey; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitMakey = /** @class */ (function (_super) {
    __extends(UnitMakey, _super);
    function UnitMakey(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].MAKEY;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].A;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'makey.png';
        return _this;
    }
    UnitMakey.prototype.getCode = function () {
        return this.name + " = units.Makey(units.PORT" + this.port + ")\n";
    };
    return UnitMakey;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitNcir.class.ts":
/*!***********************************************!*\
  !*** ./src/app/domain/unit/UnitNcir.class.ts ***!
  \***********************************************/
/*! exports provided: UnitNicr */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitNicr", function() { return UnitNicr; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitNicr = /** @class */ (function (_super) {
    __extends(UnitNicr, _super);
    // hidden = true;
    function UnitNicr(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].NCIR;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'ncir.png';
        return _this;
    }
    UnitNicr.prototype.getCode = function () {
        return this.name + " = units.get(units.ncir,units.PORT" + this.port + ")\n";
    };
    return UnitNicr;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitNeopixel.class.ts":
/*!***************************************************!*\
  !*** ./src/app/domain/unit/UnitNeopixel.class.ts ***!
  \***************************************************/
/*! exports provided: UnitNeopixel */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitNeopixel", function() { return UnitNeopixel; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitNeopixel = /** @class */ (function (_super) {
    __extends(UnitNeopixel, _super);
    function UnitNeopixel(opt) {
        var _this = _super.call(this) || this;
        /** Neopixel灯数量 */
        _this.count = 10;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].NEOPIXEL;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].A;
        _this.count = opt.count || 10;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'neopixel.png';
        return _this;
    }
    UnitNeopixel.prototype.getCode = function () {
        return this.name + " = units.RGB_Multi(units.PORT" + this.port + ", " + this.count + ")\n";
    };
    return UnitNeopixel;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitPIR.class.ts":
/*!**********************************************!*\
  !*** ./src/app/domain/unit/UnitPIR.class.ts ***!
  \**********************************************/
/*! exports provided: UnitPIR */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitPIR", function() { return UnitPIR; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitPIR = /** @class */ (function (_super) {
    __extends(UnitPIR, _super);
    function UnitPIR(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].PIR;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'pir.png';
        return _this;
    }
    UnitPIR.prototype.getCode = function () {
        return this.name + " = units.PIR(units.PORT" + this.port + ")\n";
    };
    return UnitPIR;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitProto.class.ts":
/*!************************************************!*\
  !*** ./src/app/domain/unit/UnitProto.class.ts ***!
  \************************************************/
/*! exports provided: UnitProto */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitProto", function() { return UnitProto; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitProto = /** @class */ (function (_super) {
    __extends(UnitProto, _super);
    function UnitProto(opt) {
        var _this = _super.call(this) || this;
        _this.hidden = true;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].PROTO;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'proto.png';
        return _this;
    }
    UnitProto.prototype.getCode = function () {
    };
    return UnitProto;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitPulse.class.ts":
/*!************************************************!*\
  !*** ./src/app/domain/unit/UnitPulse.class.ts ***!
  \************************************************/
/*! exports provided: UnitPulse */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitPulse", function() { return UnitPulse; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitPulse = /** @class */ (function (_super) {
    __extends(UnitPulse, _super);
    function UnitPulse(opt) {
        var _this = _super.call(this) || this;
        _this.hidden = true;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].PULSE;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].A;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'pulse.png';
        return _this;
    }
    UnitPulse.prototype.getCode = function () {
        return this.name + " = units.Pulse(units.PORT" + this.port + ")\n";
    };
    return UnitPulse;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitRGB.class.ts":
/*!**********************************************!*\
  !*** ./src/app/domain/unit/UnitRGB.class.ts ***!
  \**********************************************/
/*! exports provided: UnitRGB */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitRGB", function() { return UnitRGB; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitRGB = /** @class */ (function (_super) {
    __extends(UnitRGB, _super);
    // hidden = true;
    function UnitRGB(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].RGB;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].C;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'rgb.png';
        return _this;
    }
    UnitRGB.prototype.getCode = function () {
        return this.name + " = units.get(units.rgb,units.PORT" + this.port + ", 3)\n";
    };
    return UnitRGB;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitRelay.class.ts":
/*!************************************************!*\
  !*** ./src/app/domain/unit/UnitRelay.class.ts ***!
  \************************************************/
/*! exports provided: UnitRelay */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitRelay", function() { return UnitRelay; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitRelay = /** @class */ (function (_super) {
    __extends(UnitRelay, _super);
    // hidden = true;
    function UnitRelay(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].RELAY;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'relay.png';
        return _this;
    }
    UnitRelay.prototype.getCode = function () {
        return this.name + " = units.get(units.relay,units.PORT" + this.port + ")\n";
    };
    return UnitRelay;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitRfid.class.ts":
/*!***********************************************!*\
  !*** ./src/app/domain/unit/UnitRfid.class.ts ***!
  \***********************************************/
/*! exports provided: UnitRfid */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitRfid", function() { return UnitRfid; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitRfid = /** @class */ (function (_super) {
    __extends(UnitRfid, _super);
    // hidden = true;
    function UnitRfid(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].RFID;
        _this.name = opt.name;
        // this.port=opt.port.port?opt.port.port:opt.port?opt.port: PORT.A;
        // this.default= opt.port.default?opt.port.default:opt['default']?opt['default']:['A','B','C'];
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].A;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'rfid.png';
        return _this;
    }
    UnitRfid.prototype.getCode = function () {
        return this.name + " = units.get(units.rfid,units.PORT" + this.port + ")\n";
    };
    return UnitRfid;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitServo.class.ts":
/*!************************************************!*\
  !*** ./src/app/domain/unit/UnitServo.class.ts ***!
  \************************************************/
/*! exports provided: UnitServo */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitServo", function() { return UnitServo; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitServo = /** @class */ (function (_super) {
    __extends(UnitServo, _super);
    function UnitServo(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].SERVO;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].A;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'servo.png';
        return _this;
    }
    UnitServo.prototype.getCode = function () {
        return this.name + " = units.Servo(units.PORT" + this.port + ")\n";
    };
    return UnitServo;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitTOF.class.ts":
/*!**********************************************!*\
  !*** ./src/app/domain/unit/UnitTOF.class.ts ***!
  \**********************************************/
/*! exports provided: UnitTOF */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitTOF", function() { return UnitTOF; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitTOF = /** @class */ (function (_super) {
    __extends(UnitTOF, _super);
    function UnitTOF(opt) {
        var _this = _super.call(this) || this;
        // hidden = true;
        _this.stickNone = 'stick';
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].TOF;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'tof.png';
        return _this;
    }
    UnitTOF.prototype.getCode = function () {
        return this.name + " = units.get(units.tof,units.PORT" + this.port + ")\n";
    };
    return UnitTOF;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitThermal.class.ts":
/*!**************************************************!*\
  !*** ./src/app/domain/unit/UnitThermal.class.ts ***!
  \**************************************************/
/*! exports provided: UnitThermal */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitThermal", function() { return UnitThermal; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitThermal = /** @class */ (function (_super) {
    __extends(UnitThermal, _super);
    function UnitThermal(opt) {
        var _this = _super.call(this) || this;
        _this.hidden = true;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].THERMAL;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].B;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'thermal.png';
        return _this;
    }
    UnitThermal.prototype.getCode = function () {
    };
    return UnitThermal;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitTrack.class.ts":
/*!************************************************!*\
  !*** ./src/app/domain/unit/UnitTrack.class.ts ***!
  \************************************************/
/*! exports provided: UnitTrack */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitTrack", function() { return UnitTrack; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitTrack = /** @class */ (function (_super) {
    __extends(UnitTrack, _super);
    function UnitTrack(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].TRACK;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].A;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'C'];
        _this.icon = 'track.png';
        return _this;
    }
    UnitTrack.prototype.getCode = function () {
        return this.name + " = units.Tracker(units.PORT" + this.port + ")\n";
    };
    return UnitTrack;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/UnitWeigh.class.ts":
/*!************************************************!*\
  !*** ./src/app/domain/unit/UnitWeigh.class.ts ***!
  \************************************************/
/*! exports provided: UnitWeigh */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitWeigh", function() { return UnitWeigh; });
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __extends = (undefined && undefined.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
        return extendStatics(d, b);
    }
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();


var UnitWeigh = /** @class */ (function (_super) {
    __extends(UnitWeigh, _super);
    function UnitWeigh(opt) {
        var _this = _super.call(this) || this;
        _this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].WEIGH;
        _this.name = opt.name;
        _this.port = opt.port.port ? opt.port.port : opt.port ? opt.port : src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["PORT"].A;
        _this.default = opt.port.default ? opt.port.default : opt['default'] ? opt['default'] : ['A', 'B', 'C'];
        _this.icon = 'weigh.png';
        return _this;
    }
    UnitWeigh.prototype.getCode = function () {
        return this.name + " = units.Weigh(units.PORT" + this.port + ")\n";
    };
    return UnitWeigh;
}(_BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]));



/***/ }),

/***/ "./src/app/domain/unit/index.ts":
/*!**************************************!*\
  !*** ./src/app/domain/unit/index.ts ***!
  \**************************************/
/*! exports provided: BaseUnit, UnitEnv, UnitAngle, UnitPIR, UnitNeopixel, UnitJoystick, UnitLight, UnitEarth, UnitMakey, UnitServo, UnitWeigh, UnitPulse, UnitTrack, Unit396, UnitADC, UnitButton, UnitColor, UnitDac, UnitDualButton, UnitHub, UnitIR, UnitM5Camera, UnitNicr, UnitProto, UnitRelay, UnitRGB, UnitThermal, UnitTOF, UnitExtio, UnitFinger, UnitRfid, UnitLidarCar, UnitCardkb */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./BaseUnit.class */ "./src/app/domain/unit/BaseUnit.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "BaseUnit", function() { return _BaseUnit_class__WEBPACK_IMPORTED_MODULE_0__["BaseUnit"]; });

/* harmony import */ var _UnitEnv_class__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ./UnitEnv.class */ "./src/app/domain/unit/UnitEnv.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitEnv", function() { return _UnitEnv_class__WEBPACK_IMPORTED_MODULE_1__["UnitEnv"]; });

/* harmony import */ var _UnitAngle_class__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./UnitAngle.class */ "./src/app/domain/unit/UnitAngle.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitAngle", function() { return _UnitAngle_class__WEBPACK_IMPORTED_MODULE_2__["UnitAngle"]; });

/* harmony import */ var _UnitPIR_class__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./UnitPIR.class */ "./src/app/domain/unit/UnitPIR.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitPIR", function() { return _UnitPIR_class__WEBPACK_IMPORTED_MODULE_3__["UnitPIR"]; });

/* harmony import */ var _UnitNeopixel_class__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ./UnitNeopixel.class */ "./src/app/domain/unit/UnitNeopixel.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitNeopixel", function() { return _UnitNeopixel_class__WEBPACK_IMPORTED_MODULE_4__["UnitNeopixel"]; });

/* harmony import */ var _UnitJoystick_class__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ./UnitJoystick.class */ "./src/app/domain/unit/UnitJoystick.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitJoystick", function() { return _UnitJoystick_class__WEBPACK_IMPORTED_MODULE_5__["UnitJoystick"]; });

/* harmony import */ var _UnitLight_class__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./UnitLight.class */ "./src/app/domain/unit/UnitLight.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitLight", function() { return _UnitLight_class__WEBPACK_IMPORTED_MODULE_6__["UnitLight"]; });

/* harmony import */ var _UnitEarth_class__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ./UnitEarth.class */ "./src/app/domain/unit/UnitEarth.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitEarth", function() { return _UnitEarth_class__WEBPACK_IMPORTED_MODULE_7__["UnitEarth"]; });

/* harmony import */ var _UnitMakey_class__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! ./UnitMakey.class */ "./src/app/domain/unit/UnitMakey.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitMakey", function() { return _UnitMakey_class__WEBPACK_IMPORTED_MODULE_8__["UnitMakey"]; });

/* harmony import */ var _UnitServo_class__WEBPACK_IMPORTED_MODULE_9__ = __webpack_require__(/*! ./UnitServo.class */ "./src/app/domain/unit/UnitServo.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitServo", function() { return _UnitServo_class__WEBPACK_IMPORTED_MODULE_9__["UnitServo"]; });

/* harmony import */ var _UnitWeigh_class__WEBPACK_IMPORTED_MODULE_10__ = __webpack_require__(/*! ./UnitWeigh.class */ "./src/app/domain/unit/UnitWeigh.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitWeigh", function() { return _UnitWeigh_class__WEBPACK_IMPORTED_MODULE_10__["UnitWeigh"]; });

/* harmony import */ var _UnitPulse_class__WEBPACK_IMPORTED_MODULE_11__ = __webpack_require__(/*! ./UnitPulse.class */ "./src/app/domain/unit/UnitPulse.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitPulse", function() { return _UnitPulse_class__WEBPACK_IMPORTED_MODULE_11__["UnitPulse"]; });

/* harmony import */ var _UnitTrack_class__WEBPACK_IMPORTED_MODULE_12__ = __webpack_require__(/*! ./UnitTrack.class */ "./src/app/domain/unit/UnitTrack.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitTrack", function() { return _UnitTrack_class__WEBPACK_IMPORTED_MODULE_12__["UnitTrack"]; });

/* harmony import */ var _Unit396_class__WEBPACK_IMPORTED_MODULE_13__ = __webpack_require__(/*! ./Unit396.class */ "./src/app/domain/unit/Unit396.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "Unit396", function() { return _Unit396_class__WEBPACK_IMPORTED_MODULE_13__["Unit396"]; });

/* harmony import */ var _UnitADC_class__WEBPACK_IMPORTED_MODULE_14__ = __webpack_require__(/*! ./UnitADC.class */ "./src/app/domain/unit/UnitADC.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitADC", function() { return _UnitADC_class__WEBPACK_IMPORTED_MODULE_14__["UnitADC"]; });

/* harmony import */ var _UnitButton_class__WEBPACK_IMPORTED_MODULE_15__ = __webpack_require__(/*! ./UnitButton.class */ "./src/app/domain/unit/UnitButton.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitButton", function() { return _UnitButton_class__WEBPACK_IMPORTED_MODULE_15__["UnitButton"]; });

/* harmony import */ var _UnitColor_class__WEBPACK_IMPORTED_MODULE_16__ = __webpack_require__(/*! ./UnitColor.class */ "./src/app/domain/unit/UnitColor.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitColor", function() { return _UnitColor_class__WEBPACK_IMPORTED_MODULE_16__["UnitColor"]; });

/* harmony import */ var _UnitDAC_class__WEBPACK_IMPORTED_MODULE_17__ = __webpack_require__(/*! ./UnitDAC.class */ "./src/app/domain/unit/UnitDAC.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitDac", function() { return _UnitDAC_class__WEBPACK_IMPORTED_MODULE_17__["UnitDac"]; });

/* harmony import */ var _UnitDualButton_class__WEBPACK_IMPORTED_MODULE_18__ = __webpack_require__(/*! ./UnitDualButton.class */ "./src/app/domain/unit/UnitDualButton.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitDualButton", function() { return _UnitDualButton_class__WEBPACK_IMPORTED_MODULE_18__["UnitDualButton"]; });

/* harmony import */ var _UnitHub_class__WEBPACK_IMPORTED_MODULE_19__ = __webpack_require__(/*! ./UnitHub.class */ "./src/app/domain/unit/UnitHub.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitHub", function() { return _UnitHub_class__WEBPACK_IMPORTED_MODULE_19__["UnitHub"]; });

/* harmony import */ var _UnitIR_class__WEBPACK_IMPORTED_MODULE_20__ = __webpack_require__(/*! ./UnitIR.class */ "./src/app/domain/unit/UnitIR.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitIR", function() { return _UnitIR_class__WEBPACK_IMPORTED_MODULE_20__["UnitIR"]; });

/* harmony import */ var _UnitM5Camera_class__WEBPACK_IMPORTED_MODULE_21__ = __webpack_require__(/*! ./UnitM5Camera.class */ "./src/app/domain/unit/UnitM5Camera.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitM5Camera", function() { return _UnitM5Camera_class__WEBPACK_IMPORTED_MODULE_21__["UnitM5Camera"]; });

/* harmony import */ var _UnitNcir_class__WEBPACK_IMPORTED_MODULE_22__ = __webpack_require__(/*! ./UnitNcir.class */ "./src/app/domain/unit/UnitNcir.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitNicr", function() { return _UnitNcir_class__WEBPACK_IMPORTED_MODULE_22__["UnitNicr"]; });

/* harmony import */ var _UnitProto_class__WEBPACK_IMPORTED_MODULE_23__ = __webpack_require__(/*! ./UnitProto.class */ "./src/app/domain/unit/UnitProto.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitProto", function() { return _UnitProto_class__WEBPACK_IMPORTED_MODULE_23__["UnitProto"]; });

/* harmony import */ var _UnitRelay_class__WEBPACK_IMPORTED_MODULE_24__ = __webpack_require__(/*! ./UnitRelay.class */ "./src/app/domain/unit/UnitRelay.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitRelay", function() { return _UnitRelay_class__WEBPACK_IMPORTED_MODULE_24__["UnitRelay"]; });

/* harmony import */ var _UnitRGB_class__WEBPACK_IMPORTED_MODULE_25__ = __webpack_require__(/*! ./UnitRGB.class */ "./src/app/domain/unit/UnitRGB.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitRGB", function() { return _UnitRGB_class__WEBPACK_IMPORTED_MODULE_25__["UnitRGB"]; });

/* harmony import */ var _UnitThermal_class__WEBPACK_IMPORTED_MODULE_26__ = __webpack_require__(/*! ./UnitThermal.class */ "./src/app/domain/unit/UnitThermal.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitThermal", function() { return _UnitThermal_class__WEBPACK_IMPORTED_MODULE_26__["UnitThermal"]; });

/* harmony import */ var _UnitTOF_class__WEBPACK_IMPORTED_MODULE_27__ = __webpack_require__(/*! ./UnitTOF.class */ "./src/app/domain/unit/UnitTOF.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitTOF", function() { return _UnitTOF_class__WEBPACK_IMPORTED_MODULE_27__["UnitTOF"]; });

/* empty/unused harmony star reexport *//* harmony import */ var _UnitExtio_class__WEBPACK_IMPORTED_MODULE_28__ = __webpack_require__(/*! ./UnitExtio.class */ "./src/app/domain/unit/UnitExtio.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitExtio", function() { return _UnitExtio_class__WEBPACK_IMPORTED_MODULE_28__["UnitExtio"]; });

/* harmony import */ var _UnitFinger_class__WEBPACK_IMPORTED_MODULE_29__ = __webpack_require__(/*! ./UnitFinger.class */ "./src/app/domain/unit/UnitFinger.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitFinger", function() { return _UnitFinger_class__WEBPACK_IMPORTED_MODULE_29__["UnitFinger"]; });

/* harmony import */ var _UnitRfid_class__WEBPACK_IMPORTED_MODULE_30__ = __webpack_require__(/*! ./UnitRfid.class */ "./src/app/domain/unit/UnitRfid.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitRfid", function() { return _UnitRfid_class__WEBPACK_IMPORTED_MODULE_30__["UnitRfid"]; });

/* harmony import */ var _UnitLidarCar_class__WEBPACK_IMPORTED_MODULE_31__ = __webpack_require__(/*! ./UnitLidarCar.class */ "./src/app/domain/unit/UnitLidarCar.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitLidarCar", function() { return _UnitLidarCar_class__WEBPACK_IMPORTED_MODULE_31__["UnitLidarCar"]; });

/* harmony import */ var _UnitCardKb_class__WEBPACK_IMPORTED_MODULE_32__ = __webpack_require__(/*! ./UnitCardKb.class */ "./src/app/domain/unit/UnitCardKb.class.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UnitCardkb", function() { return _UnitCardKb_class__WEBPACK_IMPORTED_MODULE_32__["UnitCardkb"]; });





































/***/ }),

/***/ "./src/app/services/blockly-editor.service.ts":
/*!****************************************************!*\
  !*** ./src/app/services/blockly-editor.service.ts ***!
  \****************************************************/
/*! exports provided: BlocklyEditorService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "BlocklyEditorService", function() { return BlocklyEditorService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_http__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/http */ "./node_modules/@angular/http/fesm5/http.js");
/* harmony import */ var _code_editor_service__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./code-editor.service */ "./src/app/services/code-editor.service.ts");
/* harmony import */ var src_app_services_store_service__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! src/app/services/store.service */ "./src/app/services/store.service.ts");
/* harmony import */ var _global_operator_service__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ./global-operator.service */ "./src/app/services/global-operator.service.ts");
/* harmony import */ var rxjs__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! rxjs */ "./node_modules/rxjs/_esm5/index.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};






var BlocklyEditorService = /** @class */ (function () {
    function BlocklyEditorService(http, codeEditorSrv, globalOperatorSrv, storeSrv) {
        this.http = http;
        this.codeEditorSrv = codeEditorSrv;
        this.globalOperatorSrv = globalOperatorSrv;
        this.storeSrv = storeSrv;
        this.Blockly = window['Blockly'];
        // blockly_alert='11';
        this.blockly_alert = '';
        // alert
        this.alert = new rxjs__WEBPACK_IMPORTED_MODULE_5__["BehaviorSubject"](this.blockly_alert);
        /** 工作区 */
        this.workspace = null;
        this.init = this.init.bind(this);
        this.extEvent = this.extEvent.bind(this);
    }
    /** 获取设备类型 */
    BlocklyEditorService.prototype.getAlert = function () {
        return this.alert.asObservable();
    };
    BlocklyEditorService.prototype.setAlert = function (tp) {
        this.alert.next(tp);
    };
    /**
     * 初始化Blockly编辑器
     */
    BlocklyEditorService.prototype.init = function (opts, cb) {
        var _this_1 = this;
        if (cb === void 0) { cb = null; }
        this.http.get("../../assets/blockly/language/" + (opts.language || 'en') + ".json").subscribe(function (res) {
            if (_this_1.workspace !== null) {
                _this_1.workspace.dispose();
                if (cb == null) {
                    setTimeout(function () {
                        window['BlocklyEditor'].clear();
                        var toxml_text = window.sessionStorage.getItem('xml');
                        var xml2 = window['Blockly'].Xml.textToDom(toxml_text);
                        window['Blockly'].Xml.domToWorkspace(xml2, window['BlocklyEditor']);
                    }, 0);
                }
            }
            ;
            _this_1.Blockly.Msg = Object.assign(_this_1.Blockly.Msg, res.json());
            _this_1.workspace = _this_1.Blockly.inject(opts.wrapperId, {
                toolbox: document.getElementById(opts.toolboxId),
                trashcan: true,
                sounds: false,
                comments: false,
                zoom: {
                    controls: true,
                    wheel: false,
                    startScale: 1,
                    maxScale: 3,
                    minScale: 0.2,
                    scaleSpeed: 1.2
                },
                grid: {
                    spacing: 20,
                    length: 0,
                    colour: '#666',
                    snap: true
                }
            });
            var setupBlock = _this_1.workspace.newBlock('basic_on_setup', 'setup_block');
            setupBlock.moveBy(50, 50);
            setupBlock.initSvg();
            setupBlock.render();
            _this_1.workspace.addChangeListener(_this_1.extEvent);
            _this_1.bindButtonCallback(opts);
            window['BlocklyEditor'] = _this_1.workspace;
            _this_1.storeSrv.hiddenBlockly.next('');
            if (cb) {
                cb();
            }
        });
    };
    /**
     * Blockly自定义事件
     * @param event 事件对象
     */
    BlocklyEditorService.prototype.extEvent = function (event) {
        var _this_1 = this;
        // console.log(event)
        this.globalOperatorSrv.setSelectedComponent(null);
        this.globalOperatorSrv.setSelectedUnit(null);
        switch (event.type) {
            case 'create':
                // 复制
                if (event.blockId === 'setup_block')
                    return;
                var block = this.workspace.getBlockById(event.blockId);
                if (block.type === 'remote_add_label' ||
                    block.type === 'remote_add_slider' ||
                    block.type === 'remote_add_button' ||
                    block.type === 'remote_add_switch') {
                    this.storeSrv.erweima.next(true);
                }
                block.setDisabled(true);
                break;
            case 'move':
                var blocks = this.workspace.getAllBlocks();
                blocks.forEach(function (block) {
                    block.setDisabled(_this_1.checkDisabled(block));
                });
                if (!this.globalOperatorSrv.codeLock.value) {
                    this.codeEditorSrv.updateWorkspaceValue();
                }
                break;
            case 'delete':
                for (var i = 0; i < window['Blockly']['ButtonEvents'].length; i++) {
                    if (window['Blockly']['ButtonEvents'][i].id == event.blockId) {
                        window['Blockly']['ButtonEvents'].splice(i, 1);
                        break;
                    }
                }
                window['Blockly']['Remotes'].splice(window['Blockly']['Remotes'].findIndex(function (r) { return r.id === event.blockId; }), 1);
                if (window['Blockly']['Remotes'].length === 0) {
                    this.storeSrv.erweima.next(false);
                }
                break;
            case 'ui':
                if (!event.blockId || event.blockId === 'setup_block')
                    return;
                var _block = this.workspace.getBlockById(event.blockId);
                if (_block.isShadow_)
                    return;
                if (window['dblclickObj'] == undefined) {
                    window['dblclickObj'] = {
                        block: _block,
                        timestamp: Date.now()
                    };
                    return;
                }
                else if (window['dblclickObj'].block === _block) {
                    if (Date.now() - window['dblclickObj'].timestamp <= 300) {
                        window['Blockly'].duplicate_(_block);
                        return;
                    }
                    window['dblclickObj'] = {
                        block: _block,
                        timestamp: Date.now()
                    };
                }
                else {
                    window['dblclickObj'] = {
                        block: _block,
                        timestamp: Date.now()
                    };
                }
                this.blockly_alert = this.Blockly.Tooltip.DIV.innerText;
                this.alert.next(this.Blockly.Tooltip.DIV.innerText);
                break;
            default:
                // change事件
                return;
        }
    };
    /**
     * 检查块是否可用
     * @param block 块
     */
    BlocklyEditorService.prototype.checkDisabled = function (block) {
        if (block.id === 'setup_block' || block.type === 'unit_button_callback' || block.type === 'unit_dual_button_callback' || block.type === 'mqtt_sub' || block.type === 'finger_read' || block.type === 'lorawan_initrx' || block.type === 'procedures_defnoreturn' ||
            block.type === 'procedures_defreturn' ||
            block.type === 'button_callback' ||
            block.type === 'remote_add_switch' ||
            block.type === 'remote_add_button' ||
            block.type === 'remote_add_slider' ||
            block.type === 'remote_add_label')
            return false;
        return this.workspace.getBlockById(block.id).getRootBlock().id !== 'setup_block' &&
            this.workspace.getBlockById(block.id).getRootBlock().type !== 'unit_dual_button_callback' &&
            this.workspace.getBlockById(block.id).getRootBlock().type !== 'unit_button_callback' && this.workspace.getBlockById(block.id).getRootBlock().type !== 'mqtt_sub' && this.workspace.getBlockById(block.id).getRootBlock().type !== 'finger_read' &&
            this.workspace.getBlockById(block.id).getRootBlock().type !== 'lorawan_initrx' &&
            this.workspace.getBlockById(block.id).getRootBlock().type !== 'procedures_defnoreturn' &&
            this.workspace.getBlockById(block.id).getRootBlock().type !== 'procedures_defreturn' &&
            this.workspace.getBlockById(block.id).getRootBlock().type !== 'button_callback' &&
            this.workspace.getBlockById(block.id).getRootBlock().type !== 'remote_add_switch' &&
            this.workspace.getBlockById(block.id).getRootBlock().type !== 'remote_add_button' &&
            this.workspace.getBlockById(block.id).getRootBlock().type !== 'remote_add_slider' &&
            this.workspace.getBlockById(block.id).getRootBlock().type !== 'remote_add_label';
    };
    BlocklyEditorService.prototype.bindButtonCallback = function (opts) {
        var _this = this;
        this.workspace.registerButtonCallback('addThirdPartyBlockHandler', function () {
            var fileDom = document.getElementById('__openM5BBox');
            fileDom.click();
            fileDom.onchange = function (ev) {
                if (ev.target['files'].length === 0)
                    return;
                var reader = new FileReader();
                reader.readAsText(ev.target['files'][0], "utf8");
                reader.onload = function (e) {
                    var dataStr = e.target['result'];
                    try {
                        var data = JSON.parse(dataStr);
                        var toolboxDom = document.getElementById(opts.toolboxId);
                        eval(data.jscode);
                        toolboxDom.children[toolboxDom.children.length - 1].append(window['Blockly'].Xml.textToDom("<category name=\"" + data.category + "\" colour=\"" + data.color + "\">" + data.blocks.map(function (b) { return "<block type=\"" + b + "\"></block>"; }).join('') + "</category>"));
                        var tempBlock_1 = window['Blockly'].Xml.workspaceToDom(window['BlocklyEditor']);
                        _this.storeSrv.loddingMODE.next(true);
                        _this.init(opts, function () {
                            window['BlocklyEditor'].clear();
                            window['Blockly'].Xml.domToWorkspace(tempBlock_1, window['BlocklyEditor']);
                        });
                        // 加载 自定义块文件后不显示组件和units问题
                        setTimeout(function () {
                            _this.storeSrv.componentList.next(_this.storeSrv.componentList.value);
                            _this.storeSrv.unitList.next(_this.storeSrv.unitList.value);
                        }, 1100);
                        ev.target['value'] = null;
                    }
                    catch (err) {
                        console.log(err);
                    }
                };
            };
        });
        this.workspace.registerButtonCallback('goToBlockMakerHandler', function () {
            window.open('http://block-maker.m5stack.com');
        });
    };
    BlocklyEditorService = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"])({
            providedIn: 'root',
        }),
        __metadata("design:paramtypes", [_angular_http__WEBPACK_IMPORTED_MODULE_1__["Http"], _code_editor_service__WEBPACK_IMPORTED_MODULE_2__["CodeEditorService"], _global_operator_service__WEBPACK_IMPORTED_MODULE_4__["GlobalOperatorService"], src_app_services_store_service__WEBPACK_IMPORTED_MODULE_3__["StoreService"]])
    ], BlocklyEditorService);
    return BlocklyEditorService;
}());



/***/ }),

/***/ "./src/app/services/code-editor.service.ts":
/*!*************************************************!*\
  !*** ./src/app/services/code-editor.service.ts ***!
  \*************************************************/
/*! exports provided: CodeEditorService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "CodeEditorService", function() { return CodeEditorService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var ace_builds__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ace-builds */ "./node_modules/ace-builds/src-noconflict/ace.js");
/* harmony import */ var ace_builds__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(ace_builds__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _code_maker_service__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./code-maker.service */ "./src/app/services/code-maker.service.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};



var CodeEditorService = /** @class */ (function () {
    function CodeEditorService(codeMakerSrv) {
        this.codeMakerSrv = codeMakerSrv;
    }
    /**
     * 初始化代码编辑器
     * @param opts 配置对象
     */
    CodeEditorService.prototype.init = function (opts) {
        var _this = this;
        ace_builds__WEBPACK_IMPORTED_MODULE_1__["config"].set('basePath', '/assets/ace-builds');
        ace_builds__WEBPACK_IMPORTED_MODULE_1__["config"].loadModule('ace/ext/language_tools', function (m) {
            _this.workspace.setOptions({
                enableBasicAutocompletion: true,
                enableSnippets: true,
                enableLiveAutocompletion: true
            });
        });
        this.workspace = ace_builds__WEBPACK_IMPORTED_MODULE_1__["edit"](opts.id, {
            mode: 'ace/mode/python',
            theme: 'ace/theme/diy',
            fontSize: 16
        });
        this.workspace.$blockScrolling = Infinity;
        // this.workspace.session.setUseSoftTabs(false);
        this.workspace.session.setTabSize(2);
        // console.log(this.workspace.session.getUseSoftTabs())
        window['CodeEditor'] = this.workspace;
    };
    /**
     * 点击python更新代码
     */
    CodeEditorService.prototype.updateWorkspaceValue = function () {
        var code = this.codeMakerSrv.makeCode();
        if (code === '')
            return;
        this.workspace.setValue(code, -1);
        // console.log(code)
        return code;
    };
    // 获取应该生成的代码
    CodeEditorService.prototype.getWorkspaceValue = function () {
        var code = this.codeMakerSrv.makeCode();
        if (code === '')
            return;
        // this.workspace.setValue(code, -1);
        // // console.log(code)
        return code;
    };
    CodeEditorService = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"])({
            providedIn: 'root'
        }),
        __metadata("design:paramtypes", [_code_maker_service__WEBPACK_IMPORTED_MODULE_2__["CodeMakerService"]])
    ], CodeEditorService);
    return CodeEditorService;
}());



/***/ }),

/***/ "./src/app/services/code-maker.service.ts":
/*!************************************************!*\
  !*** ./src/app/services/code-maker.service.ts ***!
  \************************************************/
/*! exports provided: CodeMakerService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "CodeMakerService", function() { return CodeMakerService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _store_service__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ./store.service */ "./src/app/services/store.service.ts");
/* harmony import */ var _utils_common_data__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ../utils/common-data */ "./src/app/utils/common-data.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};



var CodeMakerService = /** @class */ (function () {
    function CodeMakerService(storeSrv) {
        this.storeSrv = storeSrv;
    }
    /**
     * 生成代码
     */
    CodeMakerService.prototype.makeCode = function () {
        var blocks = window['BlocklyEditor'].getAllBlocks();
        var units = this.storeSrv.unitList.value;
        var libraryBlocks = [];
        var unitVarnames = [];
        var defFuncs = [];
        blocks.forEach(function (block) {
            if (block.type === 'procedures_defnoreturn' ||
                block.type === 'procedures_defreturn' ||
                block.type === 'button_callback' ||
                block.type === 'unit_button_callback' ||
                block.type === 'mqtt_sub' ||
                block.type === 'remote_add_switch') {
            }
            else {
                libraryBlocks.push(block);
            }
        });
        unitVarnames = units.map(function (u) { return u.name; });
        defFuncs = window["Blockly"].Procedures.allProcedures(window["BlocklyEditor"])[0].concat(window["Blockly"].Procedures.allProcedures(window["BlocklyEditor"])[1]).filter(function (f) { return f[3] != false; }).map(function (f) { return f[0]; });
        var code = [];
        var libraryCode = this.makeLibraryCode(libraryBlocks);
        var unitCode = this.makeUnitCode();
        var instanceCode = this.makeInstanceCode(libraryBlocks);
        var componentCode = this.makeComponentCode();
        var blockCode = this.makeBlockCode();
        var moduleCode = this.makeModuleCode(window["Blockly"].modules);
        if (this.getblockCode('wifi_connect') !== '') {
            code.push(this.getblockCode('wifi_connect').split('\n').splice(0, 2).join('\n'));
        }
        code.push(libraryCode);
        code.push(moduleCode);
        code.push("clear_bg(" + this.storeSrv.componentList.value[0][_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["COMPONENT_ALIAS"].BACKGROUND_COLOR].replace('#', '0x') + ")");
        code.push(unitCode);
        code.push(instanceCode);
        if (this.getblockCode('lorawan_initp2p') !== '') {
            code.push(this.getblockCode('lorawan_initp2p').split('\n').splice(0, 1).join('\n'));
        }
        code.push(componentCode);
        code.push(blockCode);
        var codeStr = code.join('\n');
        var event = this.makeEventCode();
        codeStr = codeStr.replace('# Define Event\n', event + '\n');
        if (window["Blockly"].defineGlobal().length > 0 || defFuncs.length > 0) {
            codeStr = codeStr.replace(/# global params/g, 'global ' + window["Blockly"].defineGlobal().join(', '));
            // codeStr = codeStr.replace(/# global params/g, 'global ' + window["Blockly"].concat(unitVarnames).concat(defFuncs).join(', '));
        }
        var mqtt_code = '';
        // mqtt_code = this.getblockCode('mqtt_set_client');
        // if (mqtt_code !== '') {
        //   let arrCodeStr = codeStr.split('\n');
        //   for(var i = arrCodeStr.length - 1; i >= 0; i--) {
        //     if(arrCodeStr[i].indexOf('m5mqtt = M5mqtt') > -1) {
        //       arrCodeStr.splice(i, 1);
        //       break;
        //     }
        //   }
        //   codeStr = arrCodeStr.join('\n');
        // }
        codeStr = this.removemoreBlocklyCode('mqtt_set_client', codeStr);
        codeStr = this.removewifiBlocklyCode('wifi_connect', codeStr);
        codeStr = this.removelorwanBlocklyCode('lorawan_initp2p', codeStr);
        return codeStr;
    };
    /**
     * 生成引用库代码
     * @param libraryBlocks 需要引用库的块对象
     */
    CodeMakerService.prototype.makeLibraryCode = function (libraryBlocks) {
        var code = ['from m5stack import *', 'from m5ui import *'];
        libraryBlocks.forEach(function (block) {
            if (block.disabled)
                return;
            // Emoji
            if (block.type === 'emoji_show' || block.type === 'emoji_set_single') {
                if (code.indexOf('from square import Square') === -1)
                    code.push('from square import Square');
            }
            // IMU
            else if (block.type === 'IMU_GET_X' || block.type === 'IMU_GET_Y' || block.type === 'IMU_GET_Z' || block.type === 'IMU_IS_LEVEL' || block.type === 'IMU_IS_STAND' || block.type === 'IMU_IS_LEFT_TILT' || block.type === 'IMU_IS_RIGHT_TILT' || block.type === 'IMU_IS_OTHER_SIDE' || block.type === 'IMU_GET_ACC_Y' || block.type === 'IMU_GET_ACC_X' || block.type === 'IMU_GET_ACC_Z') {
                if (code.indexOf('from mpu6050 import MPU6050') === -1)
                    code.push('from mpu6050 import MPU6050');
                if (code.indexOf('import i2c_bus') === -1)
                    code.push('import i2c_bus');
            }
            // imu tow
            else if (block.type === 'IMU_GET_X_tow' || block.type === 'IMU_GET_Y_tow' || block.type === 'IMU_GET_Z_tow' || block.type === 'IMU_IS_LEVEL_tow' || block.type === 'IMU_IS_STAND_tow' || block.type === 'IMU_IS_LEFT_TILT_tow' || block.type === 'IMU_IS_RIGHT_TILT_tow' || block.type === 'IMU_IS_OTHER_SIDE_tow' || block.type === 'IMU_GET_ACC_Y_tow' || block.type === 'IMU_GET_ACC_X_tow' || block.type === 'IMU_GET_ACC_Z_tow') {
                if (code.indexOf('from hardware import sh200q') === -1)
                    code.push('from hardware import sh200q');
            }
            // Servo
            else if (block.type === 'servo_init' || block.type === 'servo_angle') {
                if (code.indexOf('from servo import *') === -1)
                    code.push('from servo import *');
            }
            // Bala
            else if (block.type === 'm5bala_start' || block.type === 'm5bala_move' || block.type === 'm5bala_turn' || block.type === 'm5bala_rotate' || block.type === 'm5bala_get_angle' || block.type === 'm5bala_set_offset' || block.type === 'm5bala_loop') {
                if (code.indexOf('from m5bala import M5Bala') === -1)
                    code.push('from m5bala import M5Bala');
                if (code.indexOf('import i2c_bus') === -1)
                    code.push('import i2c_bus');
            }
            // Bala Motor
            else if (block.type === 'nxt_init' ||
                block.type === 'nxt_set_pwm' ||
                block.type === 'nxt_run' ||
                block.type === 'nxt_stop' ||
                block.type === 'nxt_read_encoder') {
                if (code.indexOf('import lego') === -1)
                    code.push('import lego');
            }
            // Lego Motor
            else if (block.type === 'lego_register_motor' ||
                block.type === 'lego_set_pwm' ||
                block.type === 'lego_set_speed' ||
                block.type === 'lego_set_angle' ||
                block.type === 'lego_set_angle_zero' ||
                block.type === 'lego_stop' ||
                block.type === 'lego_brake') {
                if (code.indexOf('from lego_board import NXT_Motor') === -1)
                    code.push('from lego_board import NXT_Motor');
            }
            // step Motor
            else if (block.type === 'motor_instance' ||
                block.type === 'motor_move_xyz' ||
                block.type === 'motor_g_code' ||
                block.type === 'motor_set_mode' ||
                block.type === 'motor_lock' ||
                block.type === 'motor_unlock') {
                if (code.indexOf('from step_motor import StepMotor') === -1)
                    code.push('from step_motor import StepMotor');
            }
            // Pin
            else if (block.type === 'pins_analog_read' ||
                block.type === 'pins_analog_write' ||
                block.type === 'pins_digital_read' ||
                block.type === 'pins_digital_write' ||
                block.type === 'pins_set_mode' ||
                block.type === 'pins_set_map' ||
                block.type === 'pins_analog_toggle') {
                if (code.indexOf('from m5_pin import *') === -1)
                    code.push('from m5_pin import *');
            }
            // iic
            else if (block.type === 'iic_set') {
                if (code.indexOf('import i2c_bus') === -1)
                    code.push('import i2c_bus');
            }
            // matt
            else if (block.type === 'mqtt_set_client') {
                if (code.indexOf('from m5mqtt import M5mqtt') === -1)
                    code.push('from m5mqtt import M5mqtt');
            }
            //  rtc  新增
            else if (block.type === 'rtc_set_client' || block.type === 'rtc_set_client_year' || block.type === 'rtc_set_client_month' || block.type === 'rtc_set_client_day'
                || block.type === 'rtc_set_client_hous' || block.type === 'rtc_set_client_minute' || block.type === 'rtc_set_client_second' || block.type === 'rtc_set_client_time') {
                if (code.indexOf('from hardware import bm8563') === -1)
                    code.push('from hardware import bm8563');
            }
            // lidarcar
            else if (block.type === 'lidarcar_setrgb' || block.type === 'lidarcar_setOnergb' || block.type === 'lidarcar_goahead' || block.type === 'lidarcar_goback' || block.type === 'lidarcar_turnLeft' || block.type === 'lidarcar_turnRight' || block.type === 'lidarcar_setStepMotor' || block.type === 'lidarcar_setServo' || block.type === 'lidarcar_drawMap' || block.type === 'lidarcar_getdistance') {
                if (code.indexOf('import module\n') === -1)
                    code.push('import module\n');
            }
            // lorawan
            else if (block.type === 'lorawan_initrx' || block.type === 'lorawan_initp2p' || block.type === 'lorawan_data' || block.type === 'lorawan_txt') {
                if (code.indexOf('import module\n') === -1)
                    code.push('import module\n');
            }
            // Network
            else if (block.type === 'Net_p2p' || block.type === 'Net_getp2p') {
                if (block.type === 'Net_p2p' && code.indexOf('import m5p2p\n') === -1)
                    code.push('import m5p2p\n');
                if (code.indexOf('try:\n  remote_start()\nexcept:\n  pass\n') === -1)
                    code.push('try:\n  remote_start()\nexcept:\n  pass\n');
            }
        });
        if (this.storeSrv.unitList.value.length > 0)
            code.push('import units');
        return code.join('\n');
    };
    /**
     * 生成组件代码
     */
    CodeMakerService.prototype.makeComponentCode = function () {
        var clone = this.storeSrv.componentList.value.slice().sort(function (a, b) { return a.layer - b.layer; });
        var code = [];
        clone.forEach(function (c) { return code.push(c.transformToCode()); });
        return code.join('');
    };
    /**
     * 生成实例化代码
     * @param importBlocks 需要实例化的块对象
     */
    CodeMakerService.prototype.makeInstanceCode = function (importBlocks) {
        var code = [];
        importBlocks.forEach(function (block) {
            if (block.disabled)
                return;
            // Emoji
            if (block.type === 'emoji_show' || block.type === 'emoji_set_single' || block.type === 'emoji_change') {
                if (code.indexOf('emoji = Square(7, 7, 15, 9, lcd)') === -1)
                    code.push('emoji = Square(7, 7, 15, 9, lcd)');
            }
            // IMU
            else if (block.type === 'IMU_GET_X' || block.type === 'IMU_GET_Y' || block.type === 'IMU_GET_Z' || block.type === 'IMU_IS_LEVEL' || block.type === 'IMU_IS_STAND' || block.type === 'IMU_IS_LEFT_TILT' || block.type === 'IMU_IS_RIGHT_TILT' || block.type === 'IMU_IS_OTHER_SIDE' || block.type === 'IMU_GET_ACC_Y' || block.type === 'IMU_GET_ACC_X' || block.type === 'IMU_GET_ACC_Z') {
                if (code.indexOf('imu = MPU6050(i2c_bus.get(i2c_bus.M_BUS))'))
                    code.push('imu = MPU6050(i2c_bus.get(i2c_bus.M_BUS))');
            }
            // IMU _tow
            else if (block.type === 'IMU_GET_X_tow' || block.type === 'IMU_GET_Y_tow' || block.type === 'IMU_GET_Z_tow' || block.type === 'IMU_IS_LEVEL_tow' ||
                block.type === 'IMU_IS_STAND_tow' || block.type === 'IMU_IS_LEFT_TILT_tow' || block.type === 'IMU_IS_RIGHT_TILT_tow' || block.type === 'IMU_IS_OTHER_SIDE_tow' ||
                block.type === 'IMU_GET_ACC_Y_tow' || block.type === 'IMU_GET_ACC_X_tow' || block.type === 'IMU_GET_ACC_Z_tow') {
                if (code.indexOf('imu = sh200q.Sh200q()') === -1)
                    code.push('imu = sh200q.Sh200q()');
                // if (code.indexOf('m5Rtc = bm8563.Bm8563()') === -1) code.push('m5Rtc = bm8563.Bm8563()');
            }
            // Servo
            else if (block.type === 'servo_init' || block.type === 'servo_angle') {
                if (code.indexOf('servo = Servo()') === -1)
                    code.push('servo = Servo()');
            }
            // Bala
            else if (block.type === 'm5bala_start' || block.type === 'm5bala_move' || block.type === 'm5bala_turn' || block.type === 'm5bala_rotate' || block.type === 'm5bala_get_angle' || block.type === 'm5bala_set_offset' || block.type === 'm5bala_loop') {
                if (code.indexOf('m5bala = M5Bala(i2c_bus.get(i2c_bus.M_BUS))') === -1)
                    code.push('m5bala = M5Bala(i2c_bus.get(i2c_bus.M_BUS))');
            }
            // Lego Motor
            // else if(block.type === 'lego_register_motor' || 
            //         block.type === 'lego_set_pwm' || 
            //         block.type === 'lego_set_speed' || 
            //         block.type === 'lego_set_angle' ||
            //         block.type === 'lego_set_angle_zero' ||
            //         block.type === 'lego_stop' ||
            //         block.type === 'lego_brake') {
            //   if(code.indexOf('motor = Lego_Motor()') === -1) code.push('motor = Lego_Motor()');
            // }
            // RGB bar
            else if (block.type === 'rgb_set_all' || block.type === 'rgb_set_dir' || block.type === 'rgb_set') {
                if (code.indexOf('rgb = RGB_Bar()') === -1)
                    code.push('rgb = RGB_Bar()');
            }
            // Pin
            else if (block.type === 'pins_analog_read' ||
                block.type === 'pins_analog_write' ||
                block.type === 'pins_digital_read' ||
                block.type === 'pins_digital_write' ||
                block.type === 'pins_set_mode' ||
                block.type === 'pins_set_map' ||
                block.type === 'pins_analog_toggle') {
                if (code.indexOf('pin = M5_Pin()') === -1)
                    code.push('pin = M5_Pin()');
            }
            else if (block.type === 'lorawan_initrx' || block.type === 'lorawan_initp2p' || block.type === 'lorawan_data' || block.type === 'lorawan_txt') {
                if (code.indexOf('lorawan0 = module.get(module.lorawan)') === -1)
                    code.push('lorawan0 = module.get(module.lorawan)');
            }
            else if (block.type === 'lidarcar_setrgb' || block.type === 'lidarcar_setOnergb' || block.type === 'lidarcar_goahead' || block.type === 'lidarcar_goback' || block.type === 'lidarcar_turnLeft' || block.type === 'lidarcar_turnRight' || block.type === 'lidarcar_setStepMotor' || block.type === 'lidarcar_setServo' || block.type === 'lidarcar_drawMap' || block.type === 'lidarcar_getdistance') {
                if (code.indexOf('lidarcar0 = module.get(module.lidarCar)') === -1)
                    code.push('lidarcar0 = module.get(module.lidarCar)');
            }
            // rtc 实例化
            else if (block.type === 'rtc_set_client' || block.type === 'rtc_set_client_year' || block.type === 'rtc_set_client_month' || block.type === 'rtc_set_client_day' ||
                block.type === 'rtc_set_client_hous' || block.type === 'rtc_set_client_minute' || block.type === 'rtc_set_client_second' || block.type === 'rtc_set_client_time') {
                if (code.indexOf('m5Rtc = bm8563.Bm8563()') === -1)
                    code.push('m5Rtc = bm8563.Bm8563()');
            }
        });
        return code.join('\n');
    };
    // 移除块多余的代码
    CodeMakerService.prototype.removemoreBlocklyCode = function (name, codeStrs) {
        var mqtt_code = '';
        mqtt_code = this.getblockCode(name);
        if (mqtt_code !== '') {
            var arrCodeStr = codeStrs.split('\n');
            for (var i = arrCodeStr.length - 1; i >= 0; i--) {
                if (arrCodeStr[i].indexOf('m5mqtt = M5mqtt') > -1) {
                    arrCodeStr.splice(i, 1);
                    break;
                }
            }
            codeStrs = arrCodeStr.join('\n');
        }
        return codeStrs;
    };
    // 移除块删除代码
    CodeMakerService.prototype.removewifiBlocklyCode = function (name, codeStrs) {
        var mqtt_code = '';
        mqtt_code = this.getblockCode(name);
        if (mqtt_code !== '') {
            var arrCodeStr = codeStrs.split('\n');
            for (var i = arrCodeStr.length - 1; i >= 0; i--) {
                if (arrCodeStr[i].indexOf('wifisetup.auto_connect') > -1) {
                    arrCodeStr.splice(i, 1);
                    arrCodeStr.splice(i - 1, 1);
                    break;
                }
                ;
            }
            codeStrs = arrCodeStr.join('\n');
        }
        return codeStrs;
    };
    CodeMakerService.prototype.removelorwanBlocklyCode = function (name, codeStrs) {
        var mqtt_code = '';
        mqtt_code = this.getblockCode(name);
        if (mqtt_code !== '') {
            var arrCodeStr = codeStrs.split('\n');
            for (var i = arrCodeStr.length - 1; i >= 0; i--) {
                if (arrCodeStr[i].indexOf('lorawan0.initP2PMode') > -1) {
                    arrCodeStr.splice(i, 1);
                    break;
                }
            }
            codeStrs = arrCodeStr.join('\n');
        }
        return codeStrs;
    };
    // 生成一个块代码
    CodeMakerService.prototype.getblockCode = function (name) {
        var a = '';
        window['BlocklyEditor'].getAllBlocks().map(function (b) {
            if (b.type === name) {
                a = window["Blockly"].Python.blockToCode(b);
            }
        });
        return a;
    };
    /**
     * 生成Unit代码
     */
    CodeMakerService.prototype.makeUnitCode = function () {
        var mqtt_code = '';
        mqtt_code = this.getblockCode('mqtt_set_client').split('\n')[0];
        // console.log(mqtt_code);
        // if (mqtt_code === '') {
        //   return;
        // }
        return (this.storeSrv.unitList.value.map(function (u) { return u.getCode(); })).join('') + '\n' + mqtt_code;
    };
    /**
     * 生成块代码
     */
    CodeMakerService.prototype.makeBlockCode = function () {
        var special = ['button_callback'];
        window['BlocklyEditor'].topBlocks_.sort(function (a, b) {
            return special.indexOf(b.type) - special.indexOf(a.type);
        });
        var unbutton = ['unit_button_callback'];
        window['BlocklyEditor'].topBlocks_.sort(function (a, b) {
            return unbutton.indexOf(b.type) - unbutton.indexOf(a.type);
        });
        var dualunbutton = ['unit_dual_button_callback'];
        window['BlocklyEditor'].topBlocks_.sort(function (a, b) {
            return dualunbutton.indexOf(b.type) - dualunbutton.indexOf(a.type);
        });
        var mqtt_sub = ['mqtt_sub'];
        window['BlocklyEditor'].topBlocks_.sort(function (a, b) {
            return mqtt_sub.indexOf(b.type) - mqtt_sub.indexOf(a.type);
        });
        var finger_read = ['finger_read'];
        window['BlocklyEditor'].topBlocks_.sort(function (a, b) {
            return finger_read.indexOf(b.type) - finger_read.indexOf(a.type);
        });
        var lorawan_initrx = ['lorawan_initrx'];
        window['BlocklyEditor'].topBlocks_.sort(function (a, b) {
            return lorawan_initrx.indexOf(b.type) - lorawan_initrx.indexOf(a.type);
        });
        return window['Blockly'].Python.workspaceToCode(window['BlocklyEditor']);
    };
    /**
     * 生成事件代码
     */
    CodeMakerService.prototype.makeEventCode = function () {
        var buttonEvents = [];
        for (var i = 0; i < window['Blockly']['ButtonEvents'].length; i++) {
            buttonEvents.push(window['Blockly']['ButtonEvents'][i].event);
        }
        var remoteEvents = [];
        for (var i = 0; i < window['Blockly']['Remotes'].length; i++) {
            remoteEvents.push(window['Blockly']['Remotes'][i].code);
        }
        return buttonEvents.concat(remoteEvents).join('\n');
    };
    // 添加模块声明
    CodeMakerService.prototype.makeModuleCode = function (modules) {
        var mod = [];
        modules.forEach(function (e) {
            if (e === 'machine') {
                if (mod.indexOf('import machine') === -1)
                    mod.push('import machine');
            }
            else if (e === 'remote') {
                if (mod.indexOf('try:\n  remote_start()\nexcept:\n  pass') === -1)
                    mod.push('try:\n  remote_start()\nexcept:\n  pass');
            }
        });
        if (window['Blockly']['Remotes'].length === 0) {
            mod = [];
        }
        return mod.join('\n');
    };
    CodeMakerService = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"])({
            providedIn: 'root'
        }),
        __metadata("design:paramtypes", [_store_service__WEBPACK_IMPORTED_MODULE_1__["StoreService"]])
    ], CodeMakerService);
    return CodeMakerService;
}());



/***/ }),

/***/ "./src/app/services/global-operator.service.ts":
/*!*****************************************************!*\
  !*** ./src/app/services/global-operator.service.ts ***!
  \*****************************************************/
/*! exports provided: GlobalOperatorService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "GlobalOperatorService", function() { return GlobalOperatorService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../utils/common-data */ "./src/app/utils/common-data.ts");
/* harmony import */ var rxjs__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! rxjs */ "./node_modules/rxjs/_esm5/index.js");
/* harmony import */ var _domain_component__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ../domain/component */ "./src/app/domain/component/index.ts");
/* harmony import */ var _store_service__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ./store.service */ "./src/app/services/store.service.ts");
/* harmony import */ var _utils_common_tool__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ../utils/common-tool */ "./src/app/utils/common-tool.ts");
/* harmony import */ var _shared_message_box_message_box_component__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ../shared/message-box/message-box.component */ "./src/app/shared/message-box/message-box.component.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};







var GlobalOperatorService = /** @class */ (function () {
    function GlobalOperatorService(appRef, cfr, injector, storeSrv) {
        this.appRef = appRef;
        this.cfr = cfr;
        this.injector = injector;
        this.storeSrv = storeSrv;
        /** 编辑模式 */
        this.mode = new rxjs__WEBPACK_IMPORTED_MODULE_2__["BehaviorSubject"](_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["MODE"].BLOCKLY);
        /** 代码锁 */
        this.codeLock = new rxjs__WEBPACK_IMPORTED_MODULE_2__["BehaviorSubject"](false);
        /** UI模拟器可见性 */
        this.UIVisibility = new rxjs__WEBPACK_IMPORTED_MODULE_2__["BehaviorSubject"](true);
        /** 已选中组件 */
        this.selectedComponent = new rxjs__WEBPACK_IMPORTED_MODULE_2__["BehaviorSubject"](null);
        /** 已选中Unit */
        this.selectedUnit = new rxjs__WEBPACK_IMPORTED_MODULE_2__["BehaviorSubject"](null);
        /** 遮盖层Modal */
        this.maskModal = null;
        /** 提示语组件 */
        this.messageBox = null;
        /** 移动设备检测 */
        this.ismb = false;
    }
    /**
     * 设置工作区模式
     * @param mode 模式
     */
    GlobalOperatorService.prototype.setMode = function (mode) {
        this.mode.next(mode);
    };
    /**
     * 获取工作区模式流
     */
    GlobalOperatorService.prototype.getMode = function () {
        return this.mode.asObservable();
    };
    /**
     * 设置UI工作区可见性
     * @param visibility 是否可见
     */
    GlobalOperatorService.prototype.setUIVisibility = function (visibility) {
        this.UIVisibility.next(visibility);
        window['BlocklyEditor'].resize();
        var _timeout = setTimeout(function () {
            var e = document.createEvent("Event");
            e.initEvent("resize", true, true);
            window.dispatchEvent(e);
            clearTimeout(_timeout);
        });
    };
    /**
     * 获取UI工作区可见性
     */
    GlobalOperatorService.prototype.getUIVisibility = function () {
        return this.UIVisibility.asObservable();
    };
    /**
     * 设置已选中组件
     * @param component 组件实例
     */
    GlobalOperatorService.prototype.setSelectedComponent = function (component) {
        if (component === this.selectedComponent.value)
            return this.selectedComponent.next(null);
        this.selectedComponent.next(component);
        this.selectedUnit.next(null);
    };
    /**
     * 获取已选中组件
     */
    GlobalOperatorService.prototype.getSelectedComponent = function () {
        return this.selectedComponent.asObservable();
    };
    /**
     * 设置已选中Unit
     * @param unit Unit实例
     */
    GlobalOperatorService.prototype.setSelectedUnit = function (unit) {
        if (unit === this.selectedUnit.value)
            return this.selectedUnit.next(null);
        this.selectedUnit.next(unit);
        this.selectedComponent.next(null);
    };
    /**
     * 获取已选中Unit
     */
    GlobalOperatorService.prototype.getSelectedUnit = function () {
        return this.selectedUnit.asObservable();
    };
    /**
     * 创建Modal
     * @param maskComponent 遮盖层组件实例
     */
    GlobalOperatorService.prototype.createMaskModal = function (maskComponent) {
        var newNode = document.createElement('div');
        newNode.id = '____mask_modal';
        document.body.appendChild(newNode);
        var factory = this.cfr.resolveComponentFactory(maskComponent);
        var componentRef = factory.create(this.injector, [], newNode);
        componentRef.changeDetectorRef.detectChanges(); // Immediately change detection to avoid multi-checking error
        this.appRef.attachView(componentRef.hostView); // Load view into app root
        this.maskModal = componentRef;
        return componentRef;
    };
    /**
     * 创建MessageBox
     */
    GlobalOperatorService.prototype.createMessageBox = function () {
        var newNode = null;
        if (document.getElementById('____message_box') === null) {
            newNode = document.createElement('div');
            newNode.id = '____message_box';
            document.body.appendChild(newNode);
        }
        else {
            newNode = document.getElementById('____message_box');
        }
        var factory = this.cfr.resolveComponentFactory(_shared_message_box_message_box_component__WEBPACK_IMPORTED_MODULE_6__["MessageBoxComponent"]);
        var componentRef = factory.create(this.injector, [], newNode);
        componentRef.changeDetectorRef.detectChanges(); // Immediately change detection to avoid multi-checking error
        this.appRef.attachView(componentRef.hostView); // Load view into app root
        this.messageBox = componentRef;
        return componentRef;
    };
    /**
     * 设置代码锁
     * @param value 是否锁定代码
     */
    GlobalOperatorService.prototype.setCodeLock = function (value) {
        this.codeLock.next(value);
    };
    /**
     * 获取代码锁
     */
    GlobalOperatorService.prototype.getCodeLock = function () {
        return this.codeLock.asObservable();
    };
    /** 保存为m5f文件 */
    GlobalOperatorService.prototype.saveM5F = function () {
        window['Blockly'].Python.workspaceToCode(window['BlocklyEditor']);
        var data = {};
        data['components'] = this.storeSrv.componentList.value.map(function (c) {
            delete c['componentSvg'];
            return c;
        });
        data['type'] = this.storeSrv.getType().source['_value'];
        data['units'] = this.storeSrv.unitList.value.map(function (u) {
            delete u['unitSvg'];
            return u;
        });
        data['blockly'] = window['Blockly'].Xml.workspaceToDom(window['BlocklyEditor']).innerHTML;
        data['Blockly.ButtonEvents'] = window['Blockly']['ButtonEvents'];
        data['Blockly.Remotes'] = window['Blockly']['Remotes'];
        data['modules'] = window['Blockly']['modules'];
        return data;
    };
    /**
     * 读取m5f文件
     * @param data m5f文件数据
     */
    GlobalOperatorService.prototype.openM5F = function (data) {
        var components = data['components'].map(function (c) {
            return Object(_utils_common_tool__WEBPACK_IMPORTED_MODULE_5__["rebuildComponentInstance"])(c);
        });
        var lackScreen = true;
        for (var i = 0; i < components.length; i++) {
            if (components[i].type === _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].SCREEN) {
                lackScreen = false;
            }
        }
        lackScreen ? components.unshift(new _domain_component__WEBPACK_IMPORTED_MODULE_3__["ScreenComponent"]({})) : null;
        var units = data['units'].map(function (u) {
            return Object(_utils_common_tool__WEBPACK_IMPORTED_MODULE_5__["rebuildUnitInstance"])(u);
        });
        this.storeSrv.componentList.next(components);
        this.storeSrv.unitList.next(units);
        window['Blockly']['Component'] = components;
        window['Blockly']['ButtonEvents'] = data['Blockly.ButtonEvents'];
        window['Blockly']['Remotes'] = data['Blockly.Remotes'];
        window['Blockly']['Units'] = units;
        window['Blockly']['modules'] = data['modules'] || [];
        window['BlocklyEditor'].clear();
        window['Blockly'].Xml.domToWorkspace(window['Blockly'].Xml.textToDom("<xml>" + data['blockly'] + "</xml>"), window['BlocklyEditor']);
        window['UIEditor'].redrawSvg();
        window['UIEditor'].screenContainer.__dirty = true;
        window['UIEditor'].refresh();
    };
    GlobalOperatorService.prototype.openOldM5F = function (data) {
        var newComponets = [];
        var newUnits = [];
        var buttons = data['components'].filter(function (c) {
            if (c.name) {
                return c.name === 'button0' || c.name === 'button1' || c.name === 'button2';
            }
        });
        var oldComponent = data['components'].slice();
        oldComponent.splice(oldComponent.findIndex(function (c) { return c.name === 'button0'; }), 1);
        oldComponent.splice(oldComponent.findIndex(function (c) { return c.name === 'button1'; }), 1);
        oldComponent.splice(oldComponent.findIndex(function (c) { return c.name === 'button2'; }), 1);
        newComponets.push(new _domain_component__WEBPACK_IMPORTED_MODULE_3__["ScreenComponent"]({}));
        buttons.forEach(function (b) {
            newComponets.push(Object(_utils_common_tool__WEBPACK_IMPORTED_MODULE_5__["updateOldComponent"])(b));
        });
        oldComponent.forEach(function (c) {
            newComponets.push(Object(_utils_common_tool__WEBPACK_IMPORTED_MODULE_5__["updateOldComponent"])(c));
        });
        data['units'].forEach(function (u) {
            newUnits.push(Object(_utils_common_tool__WEBPACK_IMPORTED_MODULE_5__["updateOldUnit"])(u));
        });
        this.storeSrv.componentList.next(newComponets);
        this.storeSrv.unitList.next(newUnits);
        window['Blockly']['Component'] = newComponets;
        window['Blockly']['ButtonEvents'] = data['Blockly.ButtonEvents'];
        window['Blockly']['Remotes'] = data['Blockly.Remotes'];
        window['Blockly']['Units'] = newUnits;
        window['Blockly']['modules'] = data['modules'] || [];
        window['BlocklyEditor'].clear();
        window['Blockly'].Xml.domToWorkspace(window['Blockly'].Xml.textToDom("<xml>" + data['blockly'] + "</xml>"), window['BlocklyEditor']);
        window['UIEditor'].redrawSvg();
        window['UIEditor'].screenContainer.__dirty = true;
        window['UIEditor'].refresh();
    };
    GlobalOperatorService.prototype.redo = function () {
        if (this.mode.value === _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["MODE"].BLOCKLY) {
            window['BlocklyEditor'].undo(1);
        }
        else {
            window['CodeEditor'].redo();
        }
    };
    GlobalOperatorService.prototype.undo = function () {
        if (this.mode.value === _utils_common_data__WEBPACK_IMPORTED_MODULE_1__["MODE"].BLOCKLY) {
            if (window['BlocklyEditor'].undoStack_.length === 1)
                return;
            window['BlocklyEditor'].undo();
        }
        else {
            window['CodeEditor'].undo();
        }
    };
    GlobalOperatorService = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"])({
            providedIn: 'root'
        }),
        __metadata("design:paramtypes", [_angular_core__WEBPACK_IMPORTED_MODULE_0__["ApplicationRef"],
            _angular_core__WEBPACK_IMPORTED_MODULE_0__["ComponentFactoryResolver"],
            _angular_core__WEBPACK_IMPORTED_MODULE_0__["Injector"],
            _store_service__WEBPACK_IMPORTED_MODULE_4__["StoreService"]])
    ], GlobalOperatorService);
    return GlobalOperatorService;
}());



/***/ }),

/***/ "./src/app/services/services.module.ts":
/*!*********************************************!*\
  !*** ./src/app/services/services.module.ts ***!
  \*********************************************/
/*! exports provided: UploadService, UiEditorService, BlocklyEditorService, CodeEditorService, StoreService, CodeMakerService, GlobalOperatorService, ZrenderHelperService, ZrenderHelperMbService, ServicesModule */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "ServicesModule", function() { return ServicesModule; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_common__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/common */ "./node_modules/@angular/common/fesm5/common.js");
/* harmony import */ var _angular_http__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @angular/http */ "./node_modules/@angular/http/fesm5/http.js");
/* harmony import */ var _ui_editor_service__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./ui-editor.service */ "./src/app/services/ui-editor.service.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UiEditorService", function() { return _ui_editor_service__WEBPACK_IMPORTED_MODULE_3__["UiEditorService"]; });

/* harmony import */ var _blockly_editor_service__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ./blockly-editor.service */ "./src/app/services/blockly-editor.service.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "BlocklyEditorService", function() { return _blockly_editor_service__WEBPACK_IMPORTED_MODULE_4__["BlocklyEditorService"]; });

/* harmony import */ var _code_editor_service__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ./code-editor.service */ "./src/app/services/code-editor.service.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "CodeEditorService", function() { return _code_editor_service__WEBPACK_IMPORTED_MODULE_5__["CodeEditorService"]; });

/* harmony import */ var _store_service__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./store.service */ "./src/app/services/store.service.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "StoreService", function() { return _store_service__WEBPACK_IMPORTED_MODULE_6__["StoreService"]; });

/* harmony import */ var _code_maker_service__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ./code-maker.service */ "./src/app/services/code-maker.service.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "CodeMakerService", function() { return _code_maker_service__WEBPACK_IMPORTED_MODULE_7__["CodeMakerService"]; });

/* harmony import */ var _global_operator_service__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! ./global-operator.service */ "./src/app/services/global-operator.service.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "GlobalOperatorService", function() { return _global_operator_service__WEBPACK_IMPORTED_MODULE_8__["GlobalOperatorService"]; });

/* harmony import */ var _upload_service__WEBPACK_IMPORTED_MODULE_9__ = __webpack_require__(/*! ./upload.service */ "./src/app/services/upload.service.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "UploadService", function() { return _upload_service__WEBPACK_IMPORTED_MODULE_9__["UploadService"]; });

/* harmony import */ var _shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_10__ = __webpack_require__(/*! ../shared/mask/mask.component */ "./src/app/shared/mask/mask.component.ts");
/* harmony import */ var _workspace_unit_modal_unit_modal_component__WEBPACK_IMPORTED_MODULE_11__ = __webpack_require__(/*! ../workspace/unit-modal/unit-modal.component */ "./src/app/workspace/unit-modal/unit-modal.component.ts");
/* harmony import */ var _zrender_helper_service__WEBPACK_IMPORTED_MODULE_12__ = __webpack_require__(/*! ./zrender-helper.service */ "./src/app/services/zrender-helper.service.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "ZrenderHelperService", function() { return _zrender_helper_service__WEBPACK_IMPORTED_MODULE_12__["ZrenderHelperService"]; });

/* harmony import */ var _shared_message_box_message_box_component__WEBPACK_IMPORTED_MODULE_13__ = __webpack_require__(/*! ../shared/message-box/message-box.component */ "./src/app/shared/message-box/message-box.component.ts");
/* harmony import */ var _zrender_helper_mb_service__WEBPACK_IMPORTED_MODULE_14__ = __webpack_require__(/*! ./zrender-helper-mb.service */ "./src/app/services/zrender-helper-mb.service.ts");
/* harmony reexport (safe) */ __webpack_require__.d(__webpack_exports__, "ZrenderHelperMbService", function() { return _zrender_helper_mb_service__WEBPACK_IMPORTED_MODULE_14__["ZrenderHelperMbService"]; });

var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
















var ServicesModule = /** @class */ (function () {
    function ServicesModule() {
    }
    ServicesModule_1 = ServicesModule;
    ServicesModule.forRoot = function () {
        return {
            ngModule: ServicesModule_1,
            providers: [
                _upload_service__WEBPACK_IMPORTED_MODULE_9__["UploadService"],
                _ui_editor_service__WEBPACK_IMPORTED_MODULE_3__["UiEditorService"],
                _blockly_editor_service__WEBPACK_IMPORTED_MODULE_4__["BlocklyEditorService"],
                _code_editor_service__WEBPACK_IMPORTED_MODULE_5__["CodeEditorService"],
                _store_service__WEBPACK_IMPORTED_MODULE_6__["StoreService"],
                _code_maker_service__WEBPACK_IMPORTED_MODULE_7__["CodeMakerService"],
                _global_operator_service__WEBPACK_IMPORTED_MODULE_8__["GlobalOperatorService"],
                _zrender_helper_service__WEBPACK_IMPORTED_MODULE_12__["ZrenderHelperService"],
                _zrender_helper_mb_service__WEBPACK_IMPORTED_MODULE_14__["ZrenderHelperMbService"]
            ]
        };
    };
    var ServicesModule_1;
    ServicesModule = ServicesModule_1 = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["NgModule"])({
            imports: [
                _angular_common__WEBPACK_IMPORTED_MODULE_1__["CommonModule"],
                _angular_http__WEBPACK_IMPORTED_MODULE_2__["HttpModule"]
            ],
            declarations: [],
            entryComponents: [_shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_10__["MaskComponent"], _workspace_unit_modal_unit_modal_component__WEBPACK_IMPORTED_MODULE_11__["UnitModalComponent"], _shared_message_box_message_box_component__WEBPACK_IMPORTED_MODULE_13__["MessageBoxComponent"]],
        })
    ], ServicesModule);
    return ServicesModule;
}());



/***/ }),

/***/ "./src/app/services/store.service.ts":
/*!*******************************************!*\
  !*** ./src/app/services/store.service.ts ***!
  \*******************************************/
/*! exports provided: StoreService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "StoreService", function() { return StoreService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var rxjs__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! rxjs */ "./node_modules/rxjs/_esm5/index.js");
/* harmony import */ var _utils_common_data__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ../utils/common-data */ "./src/app/utils/common-data.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};



var StoreService = /** @class */ (function () {
    function StoreService() {
        /** 版本号 */
        this.VERSION = 'V1.2.3';
        /** 设备Id */
        this.apiKey = new rxjs__WEBPACK_IMPORTED_MODULE_1__["BehaviorSubject"](localStorage.getItem(_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["LOCALSTORAGE_KEY"].API_KEY) || '');
        /** 设备类型  core stick */
        this.type = new rxjs__WEBPACK_IMPORTED_MODULE_1__["BehaviorSubject"](localStorage.getItem('_type') || 'core');
        /** 默认语言 */
        this.defaultLanguage = localStorage.getItem(_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["LOCALSTORAGE_KEY"].LANGUAGE) || _utils_common_data__WEBPACK_IMPORTED_MODULE_2__["LANG"][0].file;
        /** 连接状态 */
        this.connectStatus = _utils_common_data__WEBPACK_IMPORTED_MODULE_2__["CONNECT_STATUS"].DISCONNECTED;
        /** 项目名称 */
        this.projectName = new rxjs__WEBPACK_IMPORTED_MODULE_1__["BehaviorSubject"]('main');
        /** 遥控码 */
        this.remoteKey = new rxjs__WEBPACK_IMPORTED_MODULE_1__["BehaviorSubject"]('');
        /** 设备数据 */
        this.deviceInfo = new rxjs__WEBPACK_IMPORTED_MODULE_1__["BehaviorSubject"](null);
        /** 工作区已存在的组件队列 */
        this.componentList = new rxjs__WEBPACK_IMPORTED_MODULE_1__["BehaviorSubject"]([]);
        /** 已添加的Units */
        this.unitList = new rxjs__WEBPACK_IMPORTED_MODULE_1__["BehaviorSubject"]([]);
        this.hiddenBlockly = new rxjs__WEBPACK_IMPORTED_MODULE_1__["Subject"]();
        /** loadding */
        this.loddingMODE = new rxjs__WEBPACK_IMPORTED_MODULE_1__["Subject"]();
        /** ui editor */
        this.uieditorMode = new rxjs__WEBPACK_IMPORTED_MODULE_1__["Subject"]();
        /** 二维吗 */
        this.erweima = new rxjs__WEBPACK_IMPORTED_MODULE_1__["BehaviorSubject"](false);
        this.componentsCount = {};
    }
    /**
     * 获取所有组件
     */
    StoreService.prototype.getComponentList = function () {
        return this.componentList.asObservable();
    };
    StoreService.prototype.getUnitList = function () {
        return this.unitList.asObservable();
    };
    StoreService.prototype.setHiddenBlockly = function () {
        return this.hiddenBlockly.asObservable();
    };
    StoreService.prototype.showerweima = function () {
        return this.erweima.asObservable();
    };
    StoreService.prototype.getuiMode = function () {
        return this.uieditorMode.asObservable();
    };
    /**
     * Loading UI
     */
    StoreService.prototype.setLoddingMode = function () {
        return this.loddingMODE.asObservable();
    };
    /** 获取设备类型 */
    StoreService.prototype.getType = function () {
        return this.type.asObservable();
    };
    StoreService.prototype.setType = function (tp) {
        this.type.next(tp);
    };
    /**
     * 添加组件到工作区
     * @param component 组件实例
     */
    StoreService.prototype.addComponent = function (component) {
        this.componentList.next(this.componentList.value.concat(component));
        window['Blockly'].Component = this.componentList.value;
    };
    /**
     * 根据组件Id移除工作区组件
     * @param id 组件Id
     */
    StoreService.prototype.removeComponentById = function (id) {
        this.componentList.value.splice(this.componentList.value.findIndex(function (c) { return c.id === id; }), 1);
        this.componentList.next(this.componentList.value);
    };
    StoreService.prototype.removeComponentAll = function () {
        this.componentList.value.splice(0, this.componentList.value.length);
        this.componentList.next([]);
    };
    /**
     * 根据组件Id查询组件
     * @param id 组件Id
     */
    StoreService.prototype.getComponentById = function (id) {
        var component = null;
        this.componentList.value.forEach(function (c) {
            if (c.id === id) {
                component = c;
            }
        });
        return component;
    };
    /**
     * 获取组件默认名称
     * @param type 组件类型
     */
    StoreService.prototype.getComponentDefaultName = function (type) {
        if (this.componentsCount[type] == undefined) {
            this.componentsCount[type] = 0;
        }
        this.componentsCount[type]++;
        return type + this.componentsCount[type];
        // let count = 0;
        // this.componentList.value.forEach(c => c.type === type && count++);
        // return type + count;
    };
    /**
     * 获取组件默认图层
     */
    StoreService.prototype.getComponentDefaultLayer = function () {
        return this.componentList.value.length + 1 - 4;
    };
    /**
     * 添加Unit
     * @param unit Unit实例
     */
    StoreService.prototype.addUnit = function (unit) {
        this.unitList.next(this.unitList.value.concat(unit));
        window['Blockly'].Units = this.unitList.value;
    };
    /**
     * 根据Unit Id移除Unit
     * @param id Unit Id
     */
    StoreService.prototype.removeUnitById = function (id) {
        this.unitList.value.splice(this.unitList.value.findIndex(function (u) { return u.id === id; }), 1);
        this.unitList.next(this.unitList.value);
    };
    /**
     * 获取Unit默认名称
     * @param type Unit类型
     */
    StoreService.prototype.getUnitDefauleName = function (type) {
        var count = 0;
        this.unitList.value.forEach(function (u) { return u.type === type && count++; });
        if (type === 'button') {
            type = 'btn';
        }
        else if (type === 'dual_button') {
            type = 'dual_btn';
        }
        return type + count;
    };
    /**
     * 设置设备数据
     * @param data 设备数据
     */
    StoreService.prototype.setDeviceInfo = function (data) {
        this.deviceInfo.next(data);
    };
    /**
     * 获取设备数据
     */
    StoreService.prototype.getDeviceInfo = function () {
        return this.deviceInfo.asObservable();
    };
    /** 设置api key */
    StoreService.prototype.setApikey = function (key) {
        this.apiKey.next(key);
        localStorage.setItem(_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["LOCALSTORAGE_KEY"].API_KEY, key);
    };
    /** 获取api key */
    StoreService.prototype.getApikey = function () {
        return this.apiKey.asObservable();
    };
    /** 设置缓存api key*/
    StoreService.prototype.setAllkey = function (key) {
        // console.log(key.length)
        var a = JSON.parse(localStorage.getItem('AllAPIKEY')) || [];
        if (key.length == 8) {
            // console.log(JSON.parse(localStorage.getItem('AllAPIKEY')).indexOf(key)=='-1')
            if (JSON.parse(localStorage.getItem('AllAPIKEY')).indexOf(key) == '-1') {
                a.push(key);
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
        localStorage.setItem('AllAPIKEY', JSON.stringify(a));
    };
    /** 获取缓存 api key */
    StoreService.prototype.getAllkey = function () {
        return JSON.parse(localStorage.getItem('AllAPIKEY')) || [];
    };
    /** 设置语言 */
    StoreService.prototype.setLanguage = function (lang) {
        this.defaultLanguage = lang;
        localStorage.setItem(_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["LOCALSTORAGE_KEY"].LANGUAGE, lang);
    };
    /** 设置项目名 */
    StoreService.prototype.setProjectName = function (name) {
        this.projectName.next(name);
    };
    /** 获取项目名 */
    StoreService.prototype.getProjectName = function () {
        return this.projectName.asObservable();
    };
    /** 设置遥控码 */
    StoreService.prototype.setRemoteKey = function (key) {
        this.remoteKey.next(key);
    };
    /** 获取遥控码 */
    StoreService.prototype.getRemoteKey = function () {
        return this.remoteKey.asObservable();
    };
    StoreService = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"])({
            providedIn: 'root'
        }),
        __metadata("design:paramtypes", [])
    ], StoreService);
    return StoreService;
}());



/***/ }),

/***/ "./src/app/services/ui-editor.service.ts":
/*!***********************************************!*\
  !*** ./src/app/services/ui-editor.service.ts ***!
  \***********************************************/
/*! exports provided: UiEditorService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UiEditorService", function() { return UiEditorService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../domain/editor/UIEditorToolbar.class */ "./src/app/domain/editor/UIEditorToolbar.class.ts");
/* harmony import */ var _zrender_helper_mb_service__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./zrender-helper-mb.service */ "./src/app/services/zrender-helper-mb.service.ts");
/* harmony import */ var _domain_component__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ../domain/component */ "./src/app/domain/component/index.ts");
/* harmony import */ var _store_service__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ./store.service */ "./src/app/services/store.service.ts");
/* harmony import */ var _zrender_helper_service__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ./zrender-helper.service */ "./src/app/services/zrender-helper.service.ts");
/* harmony import */ var _global_operator_service__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./global-operator.service */ "./src/app/services/global-operator.service.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};







var UiEditorService = /** @class */ (function () {
    function UiEditorService(zrenderHelperMb, storeSrv, zenaderHelp, globalStr) {
        this.zrenderHelperMb = zrenderHelperMb;
        this.storeSrv = storeSrv;
        this.zenaderHelp = zenaderHelp;
        this.globalStr = globalStr;
        // 缩放系数
        this.eRatio = 1;
        if (this.globalStr.ismb) {
            this.UIHELP = this.zrenderHelperMb;
        }
        else {
            this.UIHELP = this.zenaderHelp;
        }
    }
    UiEditorService.prototype.init = function (wrapperId, Categroy) {
        // console.log(Categroy)
        if (Categroy === 'stick') {
            this.isStick = 0;
            this.eRatio = 2;
        }
        else if (Categroy === 'core') {
            this.isStick = 1;
            this.eRatio = 1;
        }
        else if (Categroy === 'stick-C') {
            this.isStick = 2;
            this.eRatio = 1.5;
        }
        if (this.UIHELP.zrenderWorkspace) {
            this.UIHELP.screenContainer.removeAll();
            this.UIHELP.zrenderWorkspace.refreshImmediately();
            this.storeSrv.removeComponentAll();
        }
        // this.UIHELP.zrenderWorkspace.removeAll();
        this.UIHELP.init(wrapperId);
        this.createToolbar();
        this.createSimulator();
        this.createMainEditArea();
        this.createDeleteArea();
        this.createUnitArea();
        this.initScene();
        window['UIEditor'] = this.UIHELP.zrenderWorkspace;
        this.workspace = this.UIHELP.zrenderWorkspace;
    };
    UiEditorService.prototype.createToolbar = function () {
        // console.log(this.isStick)
        // 创建工具栏 
        if (this.isStick == 0) {
            var rectangleTool = new _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__["ToolItem"]({ icon: 'rectangle.jpg', builder: _domain_component__WEBPACK_IMPORTED_MODULE_3__["RectangleComponent"] });
            var labelTool = new _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__["ToolItem"]({ icon: 'label.jpg', builder: _domain_component__WEBPACK_IMPORTED_MODULE_3__["LabelComponent"] });
            this.toolBar = new _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__["ToolBar"]([rectangleTool, labelTool]);
        }
        else if (this.isStick == 1) {
            var titleTool = new _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__["ToolItem"]({ icon: 'title.jpg', builder: _domain_component__WEBPACK_IMPORTED_MODULE_3__["TitleComponent"] });
            var labelTool = new _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__["ToolItem"]({ icon: 'label.jpg', builder: _domain_component__WEBPACK_IMPORTED_MODULE_3__["LabelComponent"] });
            var rectangleTool = new _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__["ToolItem"]({ icon: 'rectangle.jpg', builder: _domain_component__WEBPACK_IMPORTED_MODULE_3__["RectangleComponent"] });
            var circleTool = new _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__["ToolItem"]({ icon: 'circle.jpg', builder: _domain_component__WEBPACK_IMPORTED_MODULE_3__["CircleComponent"] });
            var imageTool = new _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__["ToolItem"]({ icon: 'image.jpg', builder: _domain_component__WEBPACK_IMPORTED_MODULE_3__["ImageComponent"] });
            this.toolBar = new _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__["ToolBar"]([titleTool, labelTool, rectangleTool, circleTool, imageTool]);
        }
        else if (this.isStick == 2) {
            // const titleTool = new ToolItem({ icon: 'title.jpg', builder: TitleComponent });
            var labelTool = new _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__["ToolItem"]({ icon: 'label.jpg', builder: _domain_component__WEBPACK_IMPORTED_MODULE_3__["LabelComponent"] });
            var rectangleTool = new _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__["ToolItem"]({ icon: 'rectangle.jpg', builder: _domain_component__WEBPACK_IMPORTED_MODULE_3__["RectangleComponent"] });
            var circleTool = new _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__["ToolItem"]({ icon: 'circle.jpg', builder: _domain_component__WEBPACK_IMPORTED_MODULE_3__["CircleComponent"] });
            var imageTool = new _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__["ToolItem"]({ icon: 'image.jpg', builder: _domain_component__WEBPACK_IMPORTED_MODULE_3__["ImageComponent"] });
            this.toolBar = new _domain_editor_UIEditorToolbar_class__WEBPACK_IMPORTED_MODULE_1__["ToolBar"]([labelTool, rectangleTool, circleTool, imageTool]);
        }
        this.UIHELP.createToolBarSvg(this.toolBar);
    };
    UiEditorService.prototype.createSimulator = function () {
        // 创建M5模拟器
        if (this.isStick == 0) {
            this.UIHELP.creatM5stickSimulator();
        }
        else if (this.isStick == 1) {
            this.UIHELP.createSimulator();
        }
        else if (this.isStick == 2) {
            this.UIHELP.creatStickcMulator();
        }
    };
    UiEditorService.prototype.createMainEditArea = function () {
        // 创建主编辑区域
        this.UIHELP.createMainEditArea();
    };
    UiEditorService.prototype.createDeleteArea = function () {
        // 创建移除区域
        this.UIHELP.createDeleteArea();
    };
    UiEditorService.prototype.createUnitArea = function () {
        // 创建Unit区域
        this.UIHELP.createUnitArea();
    };
    UiEditorService.prototype.initScene = function () {
        // 初始化场景  屏幕
        if (this.isStick == 0) {
            /** stickScreen 即屏幕*/
            var screen_1 = new _domain_component__WEBPACK_IMPORTED_MODULE_3__["ScreenComponent"]({
                id: '_stickscreen',
                width: 128,
                height: 256,
                x: 0,
                y: 0,
                backgroundColor: '#111111'
            });
            this.UIHELP.screenContainer.add(this.UIHELP.createComponentSvg(screen_1));
            this.storeSrv.addComponent(screen_1);
        }
        else if (this.isStick == 1) {
            /** Screen */
            var screen_2 = new _domain_component__WEBPACK_IMPORTED_MODULE_3__["ScreenComponent"]({});
            var buttonA = new _domain_component__WEBPACK_IMPORTED_MODULE_3__["ButtonComponent"]({
                buttonIndex: _domain_component__WEBPACK_IMPORTED_MODULE_3__["ButtonIndex"].A,
                name: 'btnA'
            });
            var buttonB = new _domain_component__WEBPACK_IMPORTED_MODULE_3__["ButtonComponent"]({
                buttonIndex: _domain_component__WEBPACK_IMPORTED_MODULE_3__["ButtonIndex"].B,
                name: 'btnB'
            });
            var buttonC = new _domain_component__WEBPACK_IMPORTED_MODULE_3__["ButtonComponent"]({
                buttonIndex: _domain_component__WEBPACK_IMPORTED_MODULE_3__["ButtonIndex"].C,
                name: 'btnC'
            });
            this.UIHELP.screenContainer.add(this.UIHELP.createComponentSvg(screen_2));
            this.storeSrv.addComponent(screen_2);
            this.UIHELP.screenContainer.add(this.UIHELP.createComponentSvg(buttonA));
            this.storeSrv.addComponent(buttonA);
            this.UIHELP.screenContainer.add(this.UIHELP.createComponentSvg(buttonB));
            this.storeSrv.addComponent(buttonB);
            this.UIHELP.screenContainer.add(this.UIHELP.createComponentSvg(buttonC));
            this.storeSrv.addComponent(buttonC);
        }
        else if (this.isStick == 2) {
            var screen_3 = new _domain_component__WEBPACK_IMPORTED_MODULE_3__["ScreenComponent"]({
                id: '_stickscreen',
                width: 120,
                height: 240,
                x: 0,
                y: 0,
                backgroundColor: '#111111'
            });
            this.UIHELP.screenContainer.add(this.UIHELP.createComponentSvg(screen_3));
            this.storeSrv.addComponent(screen_3);
        }
        this.UIHELP.updateUnitSvg();
    };
    UiEditorService = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"])(),
        __metadata("design:paramtypes", [_zrender_helper_mb_service__WEBPACK_IMPORTED_MODULE_2__["ZrenderHelperMbService"], _store_service__WEBPACK_IMPORTED_MODULE_4__["StoreService"], _zrender_helper_service__WEBPACK_IMPORTED_MODULE_5__["ZrenderHelperService"],
            _global_operator_service__WEBPACK_IMPORTED_MODULE_6__["GlobalOperatorService"]])
    ], UiEditorService);
    return UiEditorService;
}());



/***/ }),

/***/ "./src/app/services/upload.service.ts":
/*!********************************************!*\
  !*** ./src/app/services/upload.service.ts ***!
  \********************************************/
/*! exports provided: UploadService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UploadService", function() { return UploadService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_common_http__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/common/http */ "./node_modules/@angular/common/fesm5/http.js");
/* harmony import */ var _environments_environment__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ../../environments/environment */ "./src/environments/environment.ts");
/* harmony import */ var rxjs_operators__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! rxjs/operators */ "./node_modules/rxjs/_esm5/operators/index.js");
/* harmony import */ var _store_service__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ./store.service */ "./src/app/services/store.service.ts");
/* harmony import */ var _utils_common_data__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ../utils/common-data */ "./src/app/utils/common-data.ts");
/* harmony import */ var rxjs__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! rxjs */ "./node_modules/rxjs/_esm5/index.js");
/* harmony import */ var _global_operator_service__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ./global-operator.service */ "./src/app/services/global-operator.service.ts");
/* harmony import */ var _ngx_translate_core__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! @ngx-translate/core */ "./node_modules/@ngx-translate/core/fesm5/ngx-translate-core.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};









var UploadService = /** @class */ (function () {
    function UploadService(http, storeSrv, globalOperatorSrv, translate) {
        this.http = http;
        this.storeSrv = storeSrv;
        this.globalOperatorSrv = globalOperatorSrv;
        this.translate = translate;
        /** 请求锁 */
        this._locker = false;
    }
    UploadService.prototype.checkApikeyNull = function () {
        if (this.storeSrv.apiKey.value === '') {
            return true;
        }
        return false;
    };
    /** 释放请求锁 */
    UploadService.prototype.releaseLocker = function () {
        var _this = this;
        return Object(rxjs_operators__WEBPACK_IMPORTED_MODULE_3__["tap"])(function (data) {
            _this._locker = false;
            return data;
        }, function (err) {
            _this._locker = false;
            return err;
        });
    };
    /**
     * 获取设备数据
     */
    UploadService.prototype.getDeviceInfo = function () {
        var _this = this;
        if (this.checkApikeyNull())
            return rxjs__WEBPACK_IMPORTED_MODULE_6__["Observable"].create(function (observer) { return observer.next(false); });
        this.translate.get('CONNECT_LOADING').subscribe(function (res) {
            _this.globalOperatorSrv.createMessageBox().instance.loading(res);
        });
        this.storeSrv.connectStatus = _utils_common_data__WEBPACK_IMPORTED_MODULE_5__["CONNECT_STATUS"].CONNECTING;
        return this.http.get(_environments_environment__WEBPACK_IMPORTED_MODULE_2__["environment"].apiUrl + "/" + encodeURIComponent(this.storeSrv.apiKey.value) + "/getFlowInfo").pipe(Object(rxjs_operators__WEBPACK_IMPORTED_MODULE_3__["timeout"])(10000), Object(rxjs_operators__WEBPACK_IMPORTED_MODULE_3__["tap"])(function (res) {
            if (res.code === 0) {
                _this._locker = false;
                window['Blockly']['ResImages'] = res.data[2].filter(function (img) { return /.jpg/g.test(img); });
                var _data = Object.assign(res.data);
                _data[2].splice(_data[2].findIndex(function (f) { return f === 'mix.wav'; }), 1);
                _data[2].splice(_data[2].findIndex(function (f) { return f === 'default.jpg'; }), 1);
                _data[2] = _data[2].map(function (f) {
                    return { filename: f, base64: '' };
                });
                res.data = _data;
                _this.translate.get('CONNECTED').subscribe(function (res) {
                    _this.globalOperatorSrv.createMessageBox().instance.success(res);
                });
                if (res.data[0] !== _this.storeSrv.VERSION) {
                    setTimeout(function () {
                        _this.translate.get('FIRMWARE_WARNING', { value: _this.storeSrv.VERSION }).subscribe(function (res) {
                            _this.globalOperatorSrv.createMessageBox().instance.warning(res);
                        });
                    }, 1000);
                }
                _this.storeSrv.connectStatus = _utils_common_data__WEBPACK_IMPORTED_MODULE_5__["CONNECT_STATUS"].CONNECTED;
                _this.storeSrv.setDeviceInfo({ version: _data[0], blocklys: _data[1], resources: _data[2] });
                return res;
            }
            _this.storeSrv.connectStatus = _utils_common_data__WEBPACK_IMPORTED_MODULE_5__["CONNECT_STATUS"].DISCONNECTED;
            _this.storeSrv.setDeviceInfo(null);
            return res;
        }, function (err) {
            _this._locker = false;
            _this.storeSrv.connectStatus = _utils_common_data__WEBPACK_IMPORTED_MODULE_5__["CONNECT_STATUS"].DISCONNECTED;
            _this.storeSrv.setDeviceInfo(null);
        }, function () {
            _this._locker = false;
        }));
    };
    /**
     * 获取设备状态
     */
    UploadService.prototype.getDeviceStatus = function () {
        var _this = this;
        if (this.checkApikeyNull())
            return rxjs__WEBPACK_IMPORTED_MODULE_6__["Observable"].create(function (observer) { return observer.next(false); });
        this.translate.get('CONNECT_LOADING').subscribe(function (res) {
            _this.globalOperatorSrv.createMessageBox().instance.loading(res);
        });
        this.storeSrv.connectStatus = _utils_common_data__WEBPACK_IMPORTED_MODULE_5__["CONNECT_STATUS"].CONNECTING;
        return this.http.get(_environments_environment__WEBPACK_IMPORTED_MODULE_2__["environment"].apiUrl + "/" + encodeURIComponent(this.storeSrv.apiKey.value) + "/isHardwareConnected").pipe(Object(rxjs_operators__WEBPACK_IMPORTED_MODULE_3__["timeout"])(10000), Object(rxjs_operators__WEBPACK_IMPORTED_MODULE_3__["tap"])(function (res) {
            setTimeout(function () {
                if (res.data !== _this.storeSrv.VERSION) {
                    _this.translate.get('FIRMWARE_WARNING', { value: _this.storeSrv.VERSION }).subscribe(function (res) {
                        _this.globalOperatorSrv.createMessageBox().instance.warning(res);
                    });
                }
            }, 1000);
            if (res.code === 0 && res.data !== false) {
                _this.storeSrv.connectStatus = _utils_common_data__WEBPACK_IMPORTED_MODULE_5__["CONNECT_STATUS"].CONNECTED;
            }
            else {
                _this.translate.get('EXECUTECODE_ERROR').subscribe(function (res) {
                    _this.globalOperatorSrv.createMessageBox().instance.error(res);
                });
                _this.storeSrv.connectStatus = _utils_common_data__WEBPACK_IMPORTED_MODULE_5__["CONNECT_STATUS"].DISCONNECTED;
            }
            return res.code === 0 && res.data !== false;
        }, function (err) {
            _this.translate.get('EXECUTECODE_ERROR').subscribe(function (res) {
                _this.globalOperatorSrv.createMessageBox().instance.error(res);
            });
            _this.storeSrv.connectStatus = _utils_common_data__WEBPACK_IMPORTED_MODULE_5__["CONNECT_STATUS"].DISCONNECTED;
        }), this.releaseLocker());
    };
    /**
     * 获取COM列表
     */
    UploadService.prototype.getComList = function () {
        if (this._locker)
            return new rxjs__WEBPACK_IMPORTED_MODULE_6__["Subject"]();
        this._locker = true;
        return this.http.get(_environments_environment__WEBPACK_IMPORTED_MODULE_2__["environment"].apiUrl + "/ports").pipe(this.releaseLocker());
    };
    /**
     * 执行代码
     */
    UploadService.prototype.execCode = function (code) {
        if (this.checkApikeyNull())
            return rxjs__WEBPACK_IMPORTED_MODULE_6__["Observable"].create(function (observer) { return observer.next(false); });
        if (this._locker)
            return new rxjs__WEBPACK_IMPORTED_MODULE_6__["Subject"]();
        this._locker = true;
        return this.http.post(_environments_environment__WEBPACK_IMPORTED_MODULE_2__["environment"].apiUrl + "/" + encodeURIComponent(this.storeSrv.apiKey.value) + "/exec", code).pipe(this.releaseLocker());
    };
    /**
     * 上传资源文件
     * @param file 文件
     */
    UploadService.prototype.uploadImg = function (file) {
        if (this.checkApikeyNull())
            return rxjs__WEBPACK_IMPORTED_MODULE_6__["Observable"].create(function (observer) { return observer.next(false); });
        if (this._locker)
            return new rxjs__WEBPACK_IMPORTED_MODULE_6__["Subject"]();
        this._locker = true;
        var form = new FormData();
        form.append('file', file);
        var req = new _angular_common_http__WEBPACK_IMPORTED_MODULE_1__["HttpRequest"]('POST', _environments_environment__WEBPACK_IMPORTED_MODULE_2__["environment"].apiUrl + "/" + encodeURIComponent(this.storeSrv.apiKey.value) + "/root/flash/res/" + file.name, form, {
            reportProgress: true,
            responseType: 'text'
        });
        return this.http.request(req).pipe(this.releaseLocker());
    };
    /**
     * 移除资源文件
     * @param filename 文件名
     */
    UploadService.prototype.deleteImg = function (filename) {
        if (this.checkApikeyNull())
            return rxjs__WEBPACK_IMPORTED_MODULE_6__["Observable"].create(function (observer) { return observer.next(false); });
        if (this._locker)
            return new rxjs__WEBPACK_IMPORTED_MODULE_6__["Subject"]();
        this._locker = true;
        return this.http.delete(_environments_environment__WEBPACK_IMPORTED_MODULE_2__["environment"].apiUrl + "/" + encodeURIComponent(this.storeSrv.apiKey.value) + "/root/flash/res/" + filename).pipe(this.releaseLocker());
    };
    /**
     * 预加载设备资源
     * @param filename 文件名
     */
    UploadService.prototype.reloadImg = function (filename) {
        if (this.checkApikeyNull())
            return rxjs__WEBPACK_IMPORTED_MODULE_6__["Observable"].create(function (observer) { return observer.next(false); });
        if (this._locker)
            return new rxjs__WEBPACK_IMPORTED_MODULE_6__["Subject"]();
        this._locker = true;
        return this.http.get(_environments_environment__WEBPACK_IMPORTED_MODULE_2__["environment"].apiUrl + "/" + encodeURIComponent(this.storeSrv.apiKey.value) + "/fs/flash/res/" + filename).pipe(this.releaseLocker());
    };
    /**
     * 上传代码前执行
     */
    UploadService.prototype.beforeUploadCode = function () {
        var code = [
            'lcd.font(lcd.FONT_DejaVu24)',
            'lcd.setTextColor(0xffffff,0x30A9DE)',
            'lcd.fillRoundRect(40,90,240,60,10,0x30A9DE)',
            'lcd.print("Uploading...",86,110)',
        ];
        return this.execCode(code.join('\n'));
    };
    /**
     * 上传代码
     * @param code 代码
     */
    UploadService.prototype.uploadCode = function (code) {
        if (this.checkApikeyNull())
            return rxjs__WEBPACK_IMPORTED_MODULE_6__["Observable"].create(function (observer) { return observer.next(false); });
        if (this._locker)
            return new rxjs__WEBPACK_IMPORTED_MODULE_6__["Subject"]();
        this._locker = true;
        return this.http.post(_environments_environment__WEBPACK_IMPORTED_MODULE_2__["environment"].apiUrl + "/" + encodeURIComponent(this.storeSrv.apiKey.value) + "/root/flash/apps/" + this.storeSrv.projectName.value + ".py", code, { responseType: 'text' }).pipe(this.releaseLocker());
    };
    /**
     * 上传代码后执行
     */
    UploadService.prototype.afterUploadCode = function () {
        var code = [
            'lcd.font(lcd.FONT_DejaVu24)',
            'lcd.setTextColor(0xffffff,lcd.ORANGE)',
            'lcd.fillRoundRect(40,90,240,60,10,lcd.ORANGE)',
            'lcd.print("Reseting...",86,110)',
            'from utils import filecp',
            "filecp('apps/" + this.storeSrv.projectName.value + ".py', 'main.py')",
            "core_start('app')",
            'machine.reset()'
        ];
        return this.execCode(code.join('\n'));
    };
    /**
     * 保存Blockly
     * @param blocklyData Blockly数据
     */
    UploadService.prototype.saveBlocklyFile = function (blocklyData) {
        return this.http.post(_environments_environment__WEBPACK_IMPORTED_MODULE_2__["environment"].apiUrl + "/" + encodeURIComponent(this.storeSrv.apiKey.value) + "/root/flash/blocks/" + this.storeSrv.projectName.value + ".m5f", blocklyData, { responseType: 'text' });
    };
    /**
     * 读取Blockly数据
     * @param filename 文件名
     */
    UploadService.prototype.loadBlocklyFile = function (filename) {
        return this.http.get(_environments_environment__WEBPACK_IMPORTED_MODULE_2__["environment"].apiUrl + "/" + encodeURIComponent(this.storeSrv.apiKey.value) + "/root/flash/blocks/" + filename);
    };
    /**
     * 移除Blockly文件
     * @param filename 文件名
     */
    UploadService.prototype.deleteBlocklyFile = function (filename) {
        return this.http.delete(_environments_environment__WEBPACK_IMPORTED_MODULE_2__["environment"].apiUrl + "/" + encodeURIComponent(this.storeSrv.apiKey.value) + "/root/flash/blocks/" + filename);
    };
    /**
     * 获取遥控Key
     * @param remoteData 遥控数据
     */
    UploadService.prototype.getRemoteKey = function (remoteData) {
        if (this.checkApikeyNull())
            return rxjs__WEBPACK_IMPORTED_MODULE_6__["Observable"].create(function (observer) { return observer.next(false); });
        if (this._locker)
            return new rxjs__WEBPACK_IMPORTED_MODULE_6__["Subject"]();
        this._locker = true;
        return this.http.post(_environments_environment__WEBPACK_IMPORTED_MODULE_2__["environment"].apiUrl + "/" + encodeURIComponent(this.storeSrv.apiKey.value) + "/remotor", remoteData).pipe(this.releaseLocker());
    };
    /**
     * 装载例程
     * @param exampleName 例程名称
     */
    UploadService.prototype.loadExample = function (exampleName) {
        return this.http.get("assets/examples/" + exampleName);
    };
    UploadService = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"])({
            providedIn: 'root'
        }),
        __metadata("design:paramtypes", [_angular_common_http__WEBPACK_IMPORTED_MODULE_1__["HttpClient"], _store_service__WEBPACK_IMPORTED_MODULE_4__["StoreService"], _global_operator_service__WEBPACK_IMPORTED_MODULE_7__["GlobalOperatorService"], _ngx_translate_core__WEBPACK_IMPORTED_MODULE_8__["TranslateService"]])
    ], UploadService);
    return UploadService;
}());



/***/ }),

/***/ "./src/app/services/zrender-helper-mb.service.ts":
/*!*******************************************************!*\
  !*** ./src/app/services/zrender-helper-mb.service.ts ***!
  \*******************************************************/
/*! exports provided: ZrenderHelperMbService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "ZrenderHelperMbService", function() { return ZrenderHelperMbService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var zrender__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! zrender */ "./node_modules/zrender/index.js");
/* harmony import */ var zrender__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(zrender__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _domain_component__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ../domain/component */ "./src/app/domain/component/index.ts");
/* harmony import */ var _utils_common_data__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ../utils/common-data */ "./src/app/utils/common-data.ts");
/* harmony import */ var _services_store_service__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ../services/store.service */ "./src/app/services/store.service.ts");
/* harmony import */ var _code_editor_service__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ./code-editor.service */ "./src/app/services/code-editor.service.ts");
/* harmony import */ var _global_operator_service__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./global-operator.service */ "./src/app/services/global-operator.service.ts");
/* harmony import */ var _shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ../shared/mask/mask.component */ "./src/app/shared/mask/mask.component.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};








var ZrenderHelperMbService = /** @class */ (function () {
    function ZrenderHelperMbService(storeSrv, codeEditorSrv, globalOperatorSrv) {
        var _this_1 = this;
        this.storeSrv = storeSrv;
        this.codeEditorSrv = codeEditorSrv;
        this.globalOperatorSrv = globalOperatorSrv;
        /** 画布宽度 */
        this.width = 0;
        /** 画布高度 */
        this.height = 0;
        /** 屏幕X偏移量 */
        this.screenOffsetX = 0;
        /** 屏幕Y偏移量 */
        this.screenOffsetY = 165;
        /** 缩放系数 */
        this.scaleRatio = 0.65;
        /** 等比系数 */
        this.eRatio = 1;
        this.isStick = 1;
        // 旋转角度转弧度 
        this.rotate = Math.PI / 180;
        // 电脑屏幕宽
        this.body_width = document.body.scrollWidth;
        // 电脑屏幕高
        this.body_height = document.body.scrollHeight - 100;
        storeSrv.getType().subscribe(function (e) {
            if (e === 'stick') {
                _this_1.isStick = 0;
                _this_1.shell_x = (_this_1.body_width - 200 * _this_1.scaleRatio) / 2;
                _this_1.shell_w = (_this_1.body_width - 200 * _this_1.scaleRatio) / 2 + 200 * _this_1.scaleRatio;
                _this_1.screenOffsetX = (_this_1.shell_x + (200 - 128) / 2 * _this_1.scaleRatio);
                _this_1.shell_y = (_this_1.body_height - 400 * _this_1.scaleRatio) > 0 ? (_this_1.body_height - 400 * _this_1.scaleRatio) / 2 : 0;
                _this_1.screenOffsetY = 44;
                _this_1.eRatio = 2;
            }
            else if (e === 'core') {
                _this_1.isStick = 1;
                _this_1.shell_x = (_this_1.body_width - 380 * _this_1.scaleRatio) / 2;
                _this_1.shell_w = (_this_1.body_width - 380 * _this_1.scaleRatio) / 2 + 380 * _this_1.scaleRatio;
                _this_1.screenOffsetX = (_this_1.shell_x + ((380 - 320) / 2 * _this_1.scaleRatio));
                _this_1.shell_y = (_this_1.body_height - 380 * _this_1.scaleRatio) > 0 ? (_this_1.body_height - 380 * _this_1.scaleRatio) / 2 : 0;
                _this_1.screenOffsetY = 65;
                _this_1.eRatio = 1;
            }
            else if (e === 'stick-C') {
                _this_1.isStick = 2;
                _this_1.shell_x = (_this_1.body_width - 235 * _this_1.scaleRatio) / 2;
                _this_1.shell_w = (_this_1.body_width - 235 * _this_1.scaleRatio) / 2 + 235 * _this_1.scaleRatio;
                _this_1.screenOffsetX = (_this_1.shell_x + ((235 - 120) / 2 * _this_1.scaleRatio));
                _this_1.shell_y = (_this_1.body_height - 470 * _this_1.scaleRatio) > 0 ? (_this_1.body_height - 470 * _this_1.scaleRatio) / 2 : 0;
                _this_1.screenOffsetY = 54;
                _this_1.eRatio = 1.5;
            }
            _this_1.screenOffsetY = _this_1.shell_y + 30;
        });
    }
    /** 初始化zrender画布 */
    ZrenderHelperMbService.prototype.init = function (id) {
        var canvarsWapper = document.getElementById(id);
        this.zrenderWorkspace = zrender__WEBPACK_IMPORTED_MODULE_1__["init"](canvarsWapper, { renderer: 'canvas' });
        this.width = this.zrenderWorkspace.getWidth();
        this.height = this.zrenderWorkspace.getHeight();
        window['zrenderWorkspace'] = this.zrenderWorkspace;
        this.zrenderWorkspace.redrawSvg = this.redrawSvg.bind(this);
        this.createComponentSvg = this.createComponentSvg.bind(this);
    };
    /**
     * 生成工具栏
     * @param toolBar 工具栏
     */
    ZrenderHelperMbService.prototype.createToolBarSvg = function (toolBar) {
        var _this_1 = this;
        if (this.storeSrv) {
        }
        toolBar.toolList.forEach(function (toolItem, index) {
            var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
            g.position = [(_this_1.shell_x - 80), _this_1.shell_y + index * 48 * _this_1.scaleRatio];
            var img = new zrender__WEBPACK_IMPORTED_MODULE_1__["Image"]({
                style: {
                    x: 0,
                    y: 0,
                    width: 48 * _this_1.scaleRatio,
                    height: 48 * _this_1.scaleRatio,
                    image: '../../assets/images/components/' + toolItem.icon
                },
                cursor: 'pointer',
                draggable: true
            });
            g.add(img);
            var _this = _this_1;
            // 开始拖拽
            // 生成一个临时svg
            g.on('dragstart', function (ev) {
                ev.target.attr('position', [0, 0]);
                var component = new toolItem.builder({
                    name: '__temp' + Date.now(),
                    layer: 99999
                });
                var svg = _this.createComponentSvg(component);
                _this.zrenderWorkspace.add(svg);
                // 拖拽圆形
                if (component.type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].CIRCLE) {
                    svg.attr('position', [ev.offsetX, ev.offsetY]);
                }
                // 拖拽标签
                else if (component.type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].LABEL) {
                    var x = ev.offsetX - svg.getBoundingRect().width / 2 * _this.scaleRatio;
                    var y = ev.offsetY - svg.getBoundingRect().height / 2 * _this.scaleRatio;
                    svg.attr('position', [x, y]);
                }
                // 拖拽图片
                else if (component.type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].IMAGE) {
                    var x = ev.offsetX - svg.style.width / 2 * _this.scaleRatio;
                    var y = ev.offsetY - svg.style.height / 2 * _this.scaleRatio;
                    svg.attr('position', [x, y]);
                }
                else {
                    var x = ev.offsetX - component.width / 2 * _this.scaleRatio;
                    var y = ev.offsetY - component.height / 2 * _this.scaleRatio;
                    svg.attr('position', [x, y]);
                }
                this.__m5ui = {
                    temp_component_svg: svg,
                    temp_component: component
                };
            });
            // 拖拽结束
            // 清除临时svg
            g.on('dragend', function (ev) {
                _this.zrenderWorkspace.remove(this.__m5ui.temp_component_svg);
                if (_this.screenContainer.children()[0].contain(ev.event.layerX ? ev.event.layerX : ev.event.zrX, ev.event.layerY ? ev.event.layerY : ev.event.zrY)) {
                    // 添加组件成功
                    var defaultName = _this.storeSrv.getComponentDefaultName(this.__m5ui.temp_component.type);
                    var defaultLayer = _this.storeSrv.getComponentDefaultLayer();
                    if (_this.isStick == 0) {
                        defaultLayer += 3;
                    }
                    else if (_this.isStick == 1) {
                        defaultLayer += 3;
                    }
                    else if (_this.isStick == 2) {
                        defaultLayer += 3;
                    }
                    var component = null;
                    switch (this.__m5ui.temp_component.type) {
                        case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].TITLE:
                            component = new _domain_component__WEBPACK_IMPORTED_MODULE_2__["TitleComponent"]({
                                name: defaultName,
                                layer: defaultLayer
                            });
                            break;
                        case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].LABEL:
                            component = new _domain_component__WEBPACK_IMPORTED_MODULE_2__["LabelComponent"]({
                                name: defaultName,
                                layer: defaultLayer,
                                x: this.__m5ui.temp_component_svg.position[0] - _this.screenOffsetX,
                                y: this.__m5ui.temp_component_svg.position[1] - _this.screenOffsetY,
                                rotation: this.__m5ui.temp_component_svg.rotation * this.rotate
                            });
                            break;
                        case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].RECTANGLE:
                            component = new _domain_component__WEBPACK_IMPORTED_MODULE_2__["RectangleComponent"]({
                                name: defaultName,
                                layer: defaultLayer,
                                x: (this.__m5ui.temp_component_svg.position[0] - _this.screenOffsetX),
                                y: (this.__m5ui.temp_component_svg.position[1] - _this.screenOffsetY),
                            });
                            break;
                        case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].CIRCLE:
                            component = new _domain_component__WEBPACK_IMPORTED_MODULE_2__["CircleComponent"]({
                                name: defaultName,
                                layer: defaultLayer,
                                x: (this.__m5ui.temp_component_svg.position[0] - _this.screenOffsetX),
                                y: (this.__m5ui.temp_component_svg.position[1] - _this.screenOffsetY)
                            });
                            break;
                        case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].IMAGE:
                            component = new _domain_component__WEBPACK_IMPORTED_MODULE_2__["ImageComponent"]({
                                name: defaultName,
                                layer: defaultLayer,
                                x: (this.__m5ui.temp_component_svg.position[0] - _this.screenOffsetX),
                                y: (this.__m5ui.temp_component_svg.position[1] - _this.screenOffsetY)
                            });
                            break;
                    }
                    // 重新绘图
                    if (component === null)
                        return;
                    _this.createSvg(component);
                    if (_this.isStick == 0) {
                        component.width = component.width / 2;
                        component.height = component.height / 2;
                        component.x = component.x / 2;
                        component.y = component.y / 2;
                    }
                    else if (_this.isStick == 1) {
                    }
                    else if (_this.isStick == 2) {
                        component.width = component.width / _this.eRatio;
                        component.height = component.height / _this.eRatio;
                        component.x = component.x / _this.eRatio;
                        component.y = component.y / _this.eRatio;
                        component.radius = component.radius / _this.eRatio;
                    }
                    _this.storeSrv.addComponent(component);
                    // 此处将其svg坐标换为zrender坐标
                    component.x = Math.floor(component.x / _this.scaleRatio);
                    component.y = Math.floor(component.y / _this.scaleRatio);
                    if (!_this.globalOperatorSrv.codeLock.value) {
                        _this.codeEditorSrv.updateWorkspaceValue();
                    }
                }
            });
            // 拖拽
            g.on('drag', function (ev) {
                ev.target.attr('position', [0, 0]);
                var x = 0;
                var y = 0;
                // 拖拽圆形
                if (this.__m5ui.temp_component.type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].CIRCLE) {
                    x = ev.offsetX;
                    y = ev.offsetY;
                    this.__m5ui.temp_component_svg.attr('position', [x, y]);
                }
                // 拖拽标签
                else if (this.__m5ui.temp_component.type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].LABEL) {
                    x = ev.offsetX - this.__m5ui.temp_component_svg.getBoundingRect().width / 2 * _this.scaleRatio;
                    y = ev.offsetY - this.__m5ui.temp_component_svg.getBoundingRect().height / 2 * _this.scaleRatio;
                    this.__m5ui.temp_component_svg.attr('position', [x, y]);
                }
                // 拖拽图片
                else if (this.__m5ui.temp_component.type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].IMAGE) {
                    x = ev.offsetX - this.__m5ui.temp_component_svg.style.width / 2 * _this.scaleRatio;
                    y = ev.offsetY - this.__m5ui.temp_component_svg.style.height / 2 * _this.scaleRatio;
                    this.__m5ui.temp_component_svg.attr('position', [x, y]);
                }
                else {
                    x = ev.offsetX - this.__m5ui.temp_component.width / 2 * _this.scaleRatio;
                    y = ev.offsetY - this.__m5ui.temp_component.height / 2 * _this.scaleRatio;
                    this.__m5ui.temp_component_svg.attr('position', [x, y]);
                }
            });
            _this_1.zrenderWorkspace.add(g);
        });
    };
    /** 生成core模拟器 */
    ZrenderHelperMbService.prototype.createSimulator = function () {
        var _this_1 = this;
        var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
        g.position = [this.shell_x, this.shell_y];
        /** 外围 */
        var shell = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 24,
                x: 0,
                y: 0,
                width: 380 * this.scaleRatio,
                height: 380 * this.scaleRatio
            },
            style: {
                stroke: '#5A5A5A',
                lineWidth: 6
            },
            cursor: 'default'
        });
        /** 电池 */
        var power = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: -2 * this.scaleRatio,
                y: 100 * this.scaleRatio,
                width: 5 * this.scaleRatio,
                height: 40 * this.scaleRatio
            },
            style: {
                fill: 'red'
            },
            cursor: 'default'
        });
        g.add(shell);
        g.add(power);
        /** 按钮 */
        var buttons = [{ x: 70, y: 330 }, { x: 160, y: 330 }, { x: 250, y: 330 }];
        buttons.forEach(function (btn, index) {
            var button = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
                shape: {
                    r: 5,
                    x: btn.x * _this_1.scaleRatio,
                    y: btn.y * _this_1.scaleRatio,
                    width: 56 * _this_1.scaleRatio,
                    height: 30 * _this_1.scaleRatio
                },
                style: {
                    fill: '#C2BFCB'
                }
            });
            var id = index === 0 ? '____buttonA' : index === 1 ? '____buttonB' : '____buttonC';
            button.on('click', function (ev) {
                var component = _this_1.storeSrv.getComponentById(id);
                _this_1.globalOperatorSrv.setSelectedComponent(component);
            });
            button.on('dblclick', function (ev) {
                // let blocks = window['BlocklyEditor'].getAllBlocks();
                // // const component = this.storeSrv.getComponentById(id);
                // // Blockly.Blocks['adc']
                // console.log(blocks);  
                var buttonBlock = window['BlocklyEditor'].newBlock('button_callback', window['Blockly'].utils.genUid());
                if (index === 0) {
                    buttonBlock.inputList[0].fieldRow[1].text_ = 'A';
                    buttonBlock.inputList[0].fieldRow[1].value_ = 'A';
                    buttonBlock.moveBy(50, 100);
                }
                else if (index === 1) {
                    buttonBlock.inputList[0].fieldRow[1].text_ = 'B';
                    buttonBlock.inputList[0].fieldRow[1].value_ = 'B';
                    buttonBlock.moveBy(50, 200);
                }
                else if (index === 2) {
                    buttonBlock.inputList[0].fieldRow[1].text_ = 'C';
                    buttonBlock.inputList[0].fieldRow[1].value_ = 'C';
                    buttonBlock.moveBy(50, 300);
                }
                buttonBlock.getRelativeToSurfaceXY(); // 得到块位置
                buttonBlock.initSvg();
                buttonBlock.render();
            });
            g.add(button);
        });
        /** Port口 */
        var ports = [
            { x: -26, y: 230, width: 12, height: 60, fillColr: '#c03546' },
            { x: 110, y: -26, width: 60, height: 12, fillColr: '#5e5e5f' },
            { x: 210, y: -26, width: 60, height: 12, fillColr: 'rgb(0, 160, 200)' }
        ];
        ports.forEach(function (p) {
            var port = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
                shape: {
                    x: p.x * _this_1.scaleRatio,
                    y: p.y * _this_1.scaleRatio,
                    width: p.width * _this_1.scaleRatio,
                    height: p.height * _this_1.scaleRatio
                },
                style: {
                    fill: p.fillColr,
                    opacity: 0
                }
            });
            g.add(port);
        });
        this.zrenderWorkspace.add(g);
    };
    /** M5stick模拟器 */
    ZrenderHelperMbService.prototype.creatM5stickSimulator = function () {
        var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
        g.position = [this.shell_x, this.shell_y];
        /** 外圈 */
        var shell = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 0,
                y: 0,
                width: 200 * this.scaleRatio,
                height: 400 * this.scaleRatio
            },
            style: {
                stroke: '#666',
                fill: '#444',
                lineWidth: 2
            },
            cursor: 'default'
        });
        /** 电池 */
        var power = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: -2 * this.scaleRatio,
                y: 320 * this.scaleRatio,
                width: 5 * this.scaleRatio,
                height: 40 * this.scaleRatio
            },
            style: {
                fill: 'red'
            },
            cursor: 'default'
        });
        /** 复位 */
        var reset = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 198 * this.scaleRatio,
                y: 100 * this.scaleRatio,
                width: 5 * this.scaleRatio,
                height: 40 * this.scaleRatio
            },
            style: {
                fill: '#ccc'
            },
            cursor: 'default'
        });
        /** 红外感应 */
        var induction = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 25 * this.scaleRatio,
                y: -2 * this.scaleRatio,
                width: 14 * this.scaleRatio,
                height: 5 * this.scaleRatio
            },
            style: {
                fill: '#ccc'
            },
            cursor: 'default'
        });
        /** m5logo */
        var text = new zrender__WEBPACK_IMPORTED_MODULE_1__["Text"]({
            position: [40 * this.scaleRatio, 320 * this.scaleRatio],
            style: {
                text: 'M5',
                fontWeight: 700,
                fontSize: 70 * this.scaleRatio,
                textFill: '#ccc'
            },
            cursor: 'default'
        });
        g.add(shell);
        g.add(power);
        g.add(text);
        g.add(reset);
        g.add(induction);
        this.zrenderWorkspace.add(g);
    };
    /** Stick-C 模拟器 */
    ZrenderHelperMbService.prototype.creatStickcMulator = function () {
        var scaleRatio = this.scaleRatio;
        var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
        g.position = [this.shell_x, this.shell_y];
        /** 外圈 */
        var shell = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 0,
                y: 0,
                width: 235 * scaleRatio,
                height: 470 * scaleRatio
            },
            style: {
                stroke: '#666',
                fill: '#ea8432',
                lineWidth: 2
            },
            cursor: 'default'
        });
        /** 底部卡槽 */
        var neck = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: this.shell_x + 50,
                y: this.shell_y - 5,
                width: 50 * this.scaleRatio,
                height: 5 * this.scaleRatio
            },
            style: {
                fill: '#ccc'
            },
            cursor: 'default'
        });
        /** 电池 */
        var power = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: -2 * scaleRatio,
                y: 350 * scaleRatio,
                width: 5 * scaleRatio,
                height: 40 * scaleRatio
            },
            style: {
                fill: 'red'
            },
            cursor: 'default'
        });
        /** 复位 */
        var reset = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 230 * scaleRatio,
                y: 95 * scaleRatio,
                width: 5 * scaleRatio,
                height: 40 * scaleRatio
            },
            style: {
                fill: '#ccc'
            },
            cursor: 'default'
        });
        /** 红外感应 */
        var induction = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 25 * scaleRatio,
                y: -2 * scaleRatio,
                width: 14 * scaleRatio,
                height: 5 * scaleRatio
            },
            style: {
                fill: 'red'
            },
            cursor: 'default'
        });
        /** 灯 */
        var light = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 38 * scaleRatio,
                y: -2 * scaleRatio,
                width: 14 * scaleRatio,
                height: 5 * scaleRatio
            },
            style: {
                fill: '#ccc'
            },
            cursor: 'default'
        });
        /** m5logo */ /** m5logo 按钮 */
        var text_btn = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 3,
                x: 40 * scaleRatio,
                y: 330 * scaleRatio,
                width: 156 * scaleRatio,
                height: 98 * scaleRatio
            },
            style: {
                fill: '#555555'
            },
            cursor: 'pointer'
        });
        var text_btn_bk = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 3,
                x: 43 * scaleRatio,
                y: 333 * scaleRatio,
                width: 150 * scaleRatio,
                height: 105 * scaleRatio
            },
            style: {
                fill: '#ea8432',
            },
            cursor: 'pointer'
        });
        var text = new zrender__WEBPACK_IMPORTED_MODULE_1__["Text"]({
            position: [57 * scaleRatio, 355 * scaleRatio],
            style: {
                text: 'M5',
                fontWeight: 700,
                fontSize: 75 * scaleRatio,
                textFill: '#d96e05',
                fontFamily: 'Verdana, Arial, Helvetica, sans-serif'
            },
            cursor: 'default'
        });
        g.add(shell);
        g.add(power);
        g.add(text_btn);
        g.add(text_btn_bk);
        g.add(text);
        g.add(reset);
        g.add(induction);
        g.add(light);
        g.add(neck);
        this.zrenderWorkspace.add(g);
    };
    /** 创建主编辑区域 */
    ZrenderHelperMbService.prototype.createMainEditArea = function () {
        var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
        g.position = [this.screenOffsetX, this.screenOffsetY];
        this.screenContainer = g;
        this.zrenderWorkspace.add(g);
        this.zrenderWorkspace.screenContainer = g;
    };
    /** 创建删除区域 */
    ZrenderHelperMbService.prototype.createDeleteArea = function () {
        var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
        g.position = [this.shell_w + 50, this.shell_y + 25];
        var img = new zrender__WEBPACK_IMPORTED_MODULE_1__["Image"]({
            style: {
                image: '../../assets/images/trash.png',
                x: 1 * this.scaleRatio,
                y: 120 * this.scaleRatio,
                width: 40 * this.scaleRatio,
                height: 40 * this.scaleRatio,
                opacity: 0.6
            }
        });
        var box = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                x: 0,
                y: 0,
                width: 48 * this.scaleRatio,
                height: 300 * this.scaleRatio
            },
            style: {
                opacity: 0.3,
                fill: 'red'
            }
        });
        g.add(box);
        g.add(img);
        g.hide();
        this.zrenderWorkspace.add(g);
        this.zrenderWorkspace.trash = g;
    };
    /** 创建Unit区域 */
    ZrenderHelperMbService.prototype.createUnitArea = function () {
        var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
        g.position = [(this.shell_x - 80), this.shell_y + 48 * 5 * this.scaleRatio + 30];
        var text = new zrender__WEBPACK_IMPORTED_MODULE_1__["Text"]({
            style: {
                text: 'Units',
                fontWeight: 'bolder',
                fontSize: 24 * this.scaleRatio,
                textFill: '#FFFFFF'
            }
        });
        text.position = [(this.shell_x - 80), this.shell_y + 48 * 5 * this.scaleRatio + 30];
        this.unitContainer = g;
        this.zrenderWorkspace.add(text);
        this.zrenderWorkspace.add(g);
        this.zrenderWorkspace.unitContainer = g;
    };
    /**
     * 创建组件Svg
     * @param component 组件实例
     */
    ZrenderHelperMbService.prototype.createComponentSvg = function (component) {
        switch (component.type) {
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].SCREEN:
                return this.createScreenComponentSvg(component);
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].BUTTON:
                return this.createButtonComponentSvg(component);
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].TITLE:
                return this.createTitleComponentSvg(component);
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].LABEL:
                return this.createLabelComponentSvg(component);
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].RECTANGLE:
                return this.createRectangleComponentSvg(component);
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].CIRCLE:
                return this.createCircleComponentSvg(component);
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].IMAGE:
                return this.createImageComponentSvg(component);
        }
    };
    /**
     * 新增屏幕Svg
     * @param component 屏幕组件实例
     */
    ZrenderHelperMbService.prototype.createScreenComponentSvg = function (component) {
        var screen = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                x: component.x * this.scaleRatio,
                y: component.y * this.scaleRatio,
                width: component.width * this.scaleRatio,
                height: component.height * this.scaleRatio,
            },
            style: {
                fill: component.backgroundColor
            }
        });
        screen.id = component.id;
        screen.__component = component;
        var _this = this;
        screen.on('click', function (ev) {
            _this.componentClick.apply(this, [ev, _this]);
        });
        component.componentSvg = screen;
        return screen;
    };
    /**
     * 新增按钮Svg
     * @param component 按钮组件实例
     */
    ZrenderHelperMbService.prototype.createButtonComponentSvg = function (component) {
        var button = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                x: component.x * this.scaleRatio,
                y: component.y * this.scaleRatio,
                width: component.width * this.scaleRatio,
                height: component.height * this.scaleRatio,
                r: [4, 4, 0, 0]
            },
            style: {
                fill: '#111111',
                stroke: '#FFFFFF',
                textRect: {
                    x: component.x * this.scaleRatio,
                    y: component.y * this.scaleRatio,
                    width: component.width * this.scaleRatio,
                    height: component.height * this.scaleRatio,
                },
                text: component.text,
                textFill: '#FFFFFF',
                fontSize: 15 * this.scaleRatio
            },
            cursor: 'default'
        });
        component.visibility ? button.show() : button.hide();
        component.componentSvg = button;
        return button;
    };
    /**
     * 创建标题组件Svg
     * @param component 标题组件实例
     */
    ZrenderHelperMbService.prototype.createTitleComponentSvg = function (component) {
        var title = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                x: component.x * this.scaleRatio,
                y: component.y * this.scaleRatio,
                width: component.width * this.scaleRatio,
                height: component.height * this.scaleRatio
            },
            style: {
                fill: component.backgroundColor,
                textRect: {
                    x: component.x * this.scaleRatio,
                    y: component.y * this.scaleRatio,
                    width: component.width * this.scaleRatio,
                    height: component.height * this.scaleRatio
                },
                text: component.text,
                textFill: component.color,
                textPosition: [2, 4 * this.scaleRatio],
                fontSize: 15 * this.scaleRatio
            },
            draggable: true
        });
        title.id = component.id;
        title.position = [0, 0];
        title.__component = component;
        var _this = this;
        title.on('dragstart', function (ev) {
            _this.componentDragStart.apply(this, [ev, _this]);
        });
        title.on('drag', function (ev) {
            _this.componentDrag.apply(this, [ev, _this]);
        });
        title.on('dragend', function (ev) {
            _this.componentDragEnd.apply(this, [ev, _this]);
        });
        component.componentSvg = title;
        return title;
    };
    /**
     * 新增标签组件
     * @param component 标签组件实例
     */
    ZrenderHelperMbService.prototype.createLabelComponentSvg = function (component) {
        var font = {
            family: 'sans-serif',
            size: 16
        };
        if (this.isStick == 0) {
            font = { family: 'sans-serif', size: 16 };
        }
        else if (this.isStick == 1) {
            if (component.font === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].UBUNTU_C)
                font = { family: 'Ubuntu-C', size: 15 };
            else if (component.font === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].COMIC)
                font = { family: 'Comic', size: 25 };
            else if (component.font === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_18PX)
                font = { family: 'DejaVuSans', size: 18 };
            else if (component.font === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_24PX)
                font = { family: 'DejaVuSans', size: 24 };
            else if (component.font === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_40PX)
                font = { family: 'DejaVuSans', size: 40 };
            else if (component.font === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_56PX)
                font = { family: 'DejaVuSans', size: 56 };
            else if (component.font === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_72PX)
                font = { family: 'DejaVuSans', size: 72 };
            else
                font = { family: 'sans-serif', size: 16 };
        }
        else if (this.isStick == 2) {
            font = { family: 'sans-serif', size: 16 };
        }
        var label = new zrender__WEBPACK_IMPORTED_MODULE_1__["Text"]({
            style: {
                text: component.text,
                fontSize: font.size * this.scaleRatio,
                fontFamily: font.family,
                textFill: component.color,
            },
            draggable: true,
            rotation: component.rotation * this.rotate
        });
        label.id = component.id;
        label.position = [component.x, component.y];
        label.rotation = component.rotation * this.rotate;
        label.__component = component;
        var _this = this;
        label.on('dragstart', function (ev) {
            _this.componentDragStart.apply(this, [ev, _this]);
        });
        label.on('drag', function (ev) {
            _this.componentDrag.apply(this, [ev, _this]);
        });
        label.on('dragend', function (ev) {
            _this.componentDragEnd.apply(this, [ev, _this]);
        });
        component.componentSvg = label;
        return label;
    };
    /**
     * 新增矩形组件
     * @param component 矩形组件实例
     */
    ZrenderHelperMbService.prototype.createRectangleComponentSvg = function (component) {
        var rect = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                width: component.width * this.scaleRatio,
                height: component.height * this.scaleRatio
            },
            style: {
                fill: component.backgroundColor,
                stroke: component.borderColor
            },
            draggable: true
        });
        rect.id = component.id;
        rect.position = [component.x, component.y];
        rect.__component = component;
        var _this = this;
        rect.on('dragstart', function (ev) {
            _this.componentDragStart.apply(this, [ev, _this]);
        });
        rect.on('drag', function (ev) {
            _this.componentDrag.apply(this, [ev, _this]);
        });
        rect.on('dragend', function (ev) {
            _this.componentDragEnd.apply(this, [ev, _this]);
        });
        component.componentSvg = rect;
        return rect;
    };
    /**
     * 新增圆形组件
     * @param component 圆形组件实例
     */
    ZrenderHelperMbService.prototype.createCircleComponentSvg = function (component) {
        var circle = new zrender__WEBPACK_IMPORTED_MODULE_1__["Circle"]({
            shape: {
                r: component.radius * this.scaleRatio
            },
            style: {
                fill: component.backgroundColor,
                stroke: component.borderColor
            },
            draggable: true
        });
        circle.id = component.id;
        // circle.shape.r= circle.shape.r/this.eRatio;
        circle.position = [component.x, component.y];
        circle.__component = component;
        var _this = this;
        circle.on('dragstart', function (ev) {
            _this.componentDragStart.apply(this, [ev, _this]);
        });
        circle.on('drag', function (ev) {
            _this.componentDrag.apply(this, [ev, _this]);
        });
        circle.on('dragend', function (ev) {
            _this.componentDragEnd.apply(this, [ev, _this]);
        });
        component.componentSvg = circle;
        return circle;
    };
    /**
     * 新增图片组件
     * @param component 图片组件实例
     */
    ZrenderHelperMbService.prototype.createImageComponentSvg = function (component) {
        var img = new Image();
        img.src = '../../assets/images/default.jpg';
        var image = new zrender__WEBPACK_IMPORTED_MODULE_1__["Image"]({
            style: {
                width: 100 * this.scaleRatio * this.eRatio,
                height: 100 * this.scaleRatio * this.eRatio,
                // image: '../../assets/images/' + component.imagePath
                image: img
            },
            draggable: true
        });
        image.id = component.id;
        image.position = [component.x, component.y];
        image.__component = component;
        var _this = this;
        image.on('dragstart', function (ev) {
            _this.componentDragStart.apply(this, [ev, _this]);
        });
        image.on('drag', function (ev) {
            _this.componentDrag.apply(this, [ev, _this]);
        });
        image.on('dragend', function (ev) {
            _this.componentDragEnd.apply(this, [ev, _this]);
        });
        component.componentSvg = image;
        return image;
    };
    /**
     * 创建Svg
     * @param component 新增组件实例
     */
    ZrenderHelperMbService.prototype.createSvg = function (component) {
        this.screenContainer.add(this.createComponentSvg(component));
    };
    /**
     * 重新渲染Svg
     */
    ZrenderHelperMbService.prototype.redrawSvg = function () {
        var _this_1 = this;
        for (var i_1 = 4; i_1 < this.screenContainer.childCount();) {
            this.screenContainer.remove(this.screenContainer.childAt(i_1));
        }
        //  此处修改解决保存为m5后打开则出现错误比例 
        var _this = this;
        for (var i = 4; i < this.storeSrv.componentList.value.length; i++) {
            _this.storeSrv.componentList.value[i].x = Math.floor(_this.storeSrv.componentList.value[i].x * _this.scaleRatio);
            _this.storeSrv.componentList.value[i].y = Math.floor(_this.storeSrv.componentList.value[i].y * _this.scaleRatio);
        }
        this.storeSrv.componentList.value.forEach(function (c) { return (_this_1.screenContainer.add(_this_1.createComponentSvg(c))); });
        for (var i = 4; i < this.storeSrv.componentList.value.length; i++) {
            _this.storeSrv.componentList.value[i].x = Math.floor(_this.storeSrv.componentList.value[i].x / _this.scaleRatio);
            _this.storeSrv.componentList.value[i].y = Math.floor(_this.storeSrv.componentList.value[i].y / _this.scaleRatio);
        }
        // this.storeSrv.unitList.value.forEach(u => this.unitContainer.add(this.updateUnitSvg()));
        this.updateUnitSvg();
    };
    /**
     * 更新Svg
     */
    ZrenderHelperMbService.prototype.updateSvg = function (component, key, value) {
        var _a, _b, _c;
        switch (key) {
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].X:
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].Y:
                if (this.isStick == 0) {
                    component['componentSvg'].attr('position', [component.x * this.scaleRatio * 2, component.y * this.scaleRatio * 2]);
                }
                else if (this.isStick == 1) {
                    component['componentSvg'].attr('position', [component.x * this.scaleRatio, component.y * this.scaleRatio]);
                }
                else if (this.isStick == 2) {
                    component['componentSvg'].attr('position', [component.x * this.scaleRatio * this.eRatio, component.y * this.scaleRatio * this.eRatio]);
                }
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].WIDTH:
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].HEIGHT:
                if (this.isStick == 0) {
                    component['componentSvg'].attr({ shape: (_a = {}, _a[key] = value * this.scaleRatio * 2, _a) });
                }
                else if (this.isStick == 1) {
                    component['componentSvg'].attr({ shape: (_b = {}, _b[key] = value * this.scaleRatio, _b) });
                }
                else if (this.isStick == 2) {
                    component['componentSvg'].attr({ shape: (_c = {}, _c[key] = value * this.scaleRatio * this.eRatio, _c) });
                }
                break;
            // 设置旋转属性
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].ROTATION:
                component['componentSvg'].attr({ rotation: component.rotation * this.rotate });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].RADIUS:
                component['componentSvg'].attr({ shape: { r: value * this.scaleRatio * this.eRatio } });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].TEXT:
                component['componentSvg'].attr({ style: { text: value } });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].COLOR:
                component['componentSvg'].attr({ style: { textFill: value } });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].BORDER_COLOR:
                component['componentSvg'].attr({ style: { stroke: value } });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].BACKGROUND_COLOR:
                component['componentSvg'].attr({ style: { fill: value } });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].FONT:
                if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].UBUNTU_C)
                    component['componentSvg'].attr({ style: { fontFamily: 'Ubuntu-C', fontSize: 15 } });
                else if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].COMIC)
                    component['componentSvg'].attr({ style: { fontFamily: 'Comic', fontSize: 25 } });
                else if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_18PX)
                    component['componentSvg'].attr({ style: { fontFamily: 'DejaVuSans', fontSize: 18 } });
                else if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_24PX)
                    component['componentSvg'].attr({ style: { fontFamily: 'DejaVuSans', fontSize: 24 } });
                else if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_40PX)
                    component['componentSvg'].attr({ style: { fontFamily: 'DejaVuSans', fontSize: 40 } });
                else if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_56PX)
                    component['componentSvg'].attr({ style: { fontFamily: 'DejaVuSans', fontSize: 56 } });
                else if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_72PX)
                    component['componentSvg'].attr({ style: { fontFamily: 'DejaVuSans', fontSize: 72 } });
                else if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEFAULT_SMALL)
                    component['componentSvg'].attr({ style: { fontFamily: 'sans-serif', fontSize: 10 } });
                else
                    component['componentSvg'].attr({ style: { fontFamily: 'sans-serif', fontSize: 13 } });
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].VISIBILITY:
                if (component.type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].BUTTON) {
                    value === 'true' ? component['componentSvg'].show() : component['componentSvg'].hide();
                }
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].LAYER:
                component['componentSvg'].attr({ zlevel: value });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].IMAGE_PATH:
                component['componentSvg'].attr({ style: { image: value } });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].IMAGE_WIDTH:
                component['componentSvg'].attr({ style: { width: value * this.scaleRatio } });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].IMAGE_HEIGHT:
                component['componentSvg'].attr({ style: { height: value * this.scaleRatio } });
                break;
            default:
                break;
        }
        if (!this.globalOperatorSrv.codeLock.value) {
            this.codeEditorSrv.updateWorkspaceValue();
        }
    };
    /**
     * 组件拖拽开始事件
     * @param ev 鼠标事件
     * @param _this 服务作用域
     */
    ZrenderHelperMbService.prototype.componentDragStart = function (ev, _this) {
        ev.event.preventDefault();
        ev.event.stopPropagation();
        this['__zr'].trash.show();
        this['__startX'] = this['__component'].getProp('x');
        this['__startY'] = this['__component'].getProp('y');
        _this.globalOperatorSrv.setSelectedComponent(null);
    };
    /**
     * 组件拖拽事件
     * @param ev 鼠标事件
     * @param _this 服务作用域
     */
    ZrenderHelperMbService.prototype.componentDrag = function (ev, _this) {
        this['__component'].setProp('x', Math.floor(this['position'][0] / _this.scaleRatio));
        this['__component'].setProp('y', Math.floor(this['position'][1] / _this.scaleRatio));
    };
    /**
     * 组件拖拽结束事件
     * @param ev 鼠标事件
     * @param _this 服务作用域
     */
    ZrenderHelperMbService.prototype.componentDragEnd = function (ev, _this) {
        this['__zr'].trash.hide();
        // 判断是否在移除区域
        if (this['__zr'].trash.children()[0].contain(ev.event.layerX ? ev.event.layerX : ev.event.zrX, ev.event.layerY ? ev.event.layerY : ev.event.zrY)) {
            _this.storeSrv.removeComponentById(this['id']);
            _this.globalOperatorSrv.setSelectedComponent(null);
            if (!_this.globalOperatorSrv.codeLock.value) {
                _this.codeEditorSrv.updateWorkspaceValue();
            }
            return this['__zr'].screenContainer.remove(this);
        }
        // 判断是否在可放置区域
        if (!this['__zr'].screenContainer.children()[0].contain(ev.event.layerX ? ev.event.layerX : ev.event.zrX, ev.event.layerY ? ev.event.layerY : ev.event.zrY)) {
            this['attr']('position', [Math.floor(this['__startX'] * _this.scaleRatio), Math.floor(this['__startY'] * _this.scaleRatio)]);
            this['__component'].setProp('x', Math.floor(this['__startX']));
            this['__component'].setProp('y', Math.floor(this['__startY']));
            _this.globalOperatorSrv.setSelectedComponent(this['__component']);
            return;
        }
        // 判断是否为Title组件
        if (this['__component'].type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].TITLE) {
            this['attr']('position', [0, 0]);
            _this.globalOperatorSrv.setSelectedComponent(this['__component']);
            return;
        }
        if (_this.isStick == 0) {
            this['__component'].setProp('x', Math.floor(this['position'][0] / _this.scaleRatio / 2));
            this['__component'].setProp('y', Math.floor(this['position'][1] / _this.scaleRatio / 2));
        }
        else if (_this.isStick == 1) {
            this['__component'].setProp('x', Math.floor(this['position'][0] / _this.scaleRatio));
            this['__component'].setProp('y', Math.floor(this['position'][1] / _this.scaleRatio));
        }
        else if (_this.isStick == 2) {
            this['__component'].setProp('x', Math.floor(this['position'][0] / _this.scaleRatio / _this.eRatio));
            this['__component'].setProp('y', Math.floor(this['position'][1] / _this.scaleRatio / _this.eRatio));
        }
        _this.globalOperatorSrv.setSelectedComponent(this['__component']);
        if (!_this.globalOperatorSrv.codeLock.value) {
            _this.codeEditorSrv.updateWorkspaceValue();
        }
    };
    /**
     * 设置已选中组件
     * @param component 组件实例
     */
    ZrenderHelperMbService.prototype.componentClick = function (ev, _this) {
        _this.globalOperatorSrv.setSelectedComponent(this['__component']);
    };
    /** 更新Unit列表 */
    ZrenderHelperMbService.prototype.updateUnitSvg = function () {
        var _this_1 = this;
        // 清空原内容
        this.zrenderWorkspace.unitContainer.removeAll();
        this.zrenderWorkspace._needsRefresh = true;
        var len = this.storeSrv.unitList.value.length;
        this.storeSrv.unitList.value.forEach(function (u, index) {
            var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
            g.id = u.id;
            g.create_time = u.createTime;
            g.type = u.type;
            var x = index % 5 * 70;
            var y = Math.floor(index / 5) * 70 + 40;
            g.position = [x * _this_1.scaleRatio, y * _this_1.scaleRatio];
            var box = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
                shape: {
                    x: 0,
                    y: 0,
                    width: 48 * _this_1.scaleRatio,
                    height: 48 * _this_1.scaleRatio,
                    r: [4]
                },
                style: {
                    lineWidth: 2,
                    stroke: '#FFFFFF',
                    fill: '#303131'
                }
            });
            var img = new zrender__WEBPACK_IMPORTED_MODULE_1__["Image"]({
                style: {
                    image: '../../assets/images/units/' + u.icon,
                    width: 48 * _this_1.scaleRatio,
                    height: 48 * _this_1.scaleRatio,
                    x: 0,
                    y: 0
                },
                draggable: true
            });
            var _this = _this_1;
            img.on('click', function (ev) {
                _this.globalOperatorSrv.setSelectedUnit(u);
            });
            img.on('dragstart', function (ev) {
                _this.zrenderWorkspace.trash.show();
                this.__originalPosition = {
                    x: this.position[0] * _this.scaleRatio,
                    y: this.position[1] * _this.scaleRatio
                };
            });
            img.on('dragend', function (ev) {
                _this.zrenderWorkspace.trash.hide();
                // 判断是否在移除区域内
                if (this['__zr'].trash.children()[0].contain(ev.event.layerX ? ev.event.layerX : ev.event.zrX, ev.event.layerY ? ev.event.layerY : ev.event.zrY)) {
                    _this.storeSrv.removeUnitById(this.parent.id);
                    _this.updateUnitSvg();
                    if (!_this.globalOperatorSrv.codeLock.value) {
                        _this.codeEditorSrv.updateWorkspaceValue();
                    }
                    return;
                }
                this.attr('position', [this.__originalPosition.x, this.__originalPosition.y]);
            });
            g.add(box);
            g.add(img);
            u.unitSvg = g;
            _this_1.zrenderWorkspace.unitContainer.add(g);
        });
        var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
        var x = len % 5 * 70;
        var y = Math.floor(len / 5) * 70 + 40;
        g.position = [x * this.scaleRatio, y * this.scaleRatio];
        var box = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                x: 0,
                y: 0,
                width: 48 * this.scaleRatio,
                height: 48 * this.scaleRatio,
                r: [4]
            },
            style: {
                lineWidth: 2,
                stroke: '#FFFFFF',
                fill: '#303131'
            }
        });
        var img = new zrender__WEBPACK_IMPORTED_MODULE_1__["Image"]({
            style: {
                image: '../../assets/images/add.png',
                width: 48 * this.scaleRatio,
                height: 48 * this.scaleRatio,
                x: 0,
                y: 0
            }
        });
        img.on('mouseover', function (ev) {
            box.animate('style', false)
                .when(200, {
                fill: 'rgb(0, 100, 160)'
            })
                .start();
        });
        img.on('mouseout', function (ev) {
            box.animate('style', false)
                .when(300, {
                fill: '#303131'
            })
                .start();
        });
        img.on('click', function (ev) {
            var maskModal = _this_1.globalOperatorSrv.createMaskModal(_shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_7__["MaskComponent"]);
            maskModal.instance.createDynamicComponent(_utils_common_data__WEBPACK_IMPORTED_MODULE_3__["DYNAMIC_COMPONENT_TYPE"].UNIT_MODAL);
        });
        g.add(box);
        g.add(img);
        this.zrenderWorkspace.unitContainer.add(g);
    };
    ZrenderHelperMbService = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"])({
            providedIn: 'root'
        }),
        __metadata("design:paramtypes", [_services_store_service__WEBPACK_IMPORTED_MODULE_4__["StoreService"],
            _code_editor_service__WEBPACK_IMPORTED_MODULE_5__["CodeEditorService"],
            _global_operator_service__WEBPACK_IMPORTED_MODULE_6__["GlobalOperatorService"]])
    ], ZrenderHelperMbService);
    return ZrenderHelperMbService;
}());



/***/ }),

/***/ "./src/app/services/zrender-helper.service.ts":
/*!****************************************************!*\
  !*** ./src/app/services/zrender-helper.service.ts ***!
  \****************************************************/
/*! exports provided: ZrenderHelperService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "ZrenderHelperService", function() { return ZrenderHelperService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var zrender__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! zrender */ "./node_modules/zrender/index.js");
/* harmony import */ var zrender__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(zrender__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _domain_component__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ../domain/component */ "./src/app/domain/component/index.ts");
/* harmony import */ var _utils_common_data__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ../utils/common-data */ "./src/app/utils/common-data.ts");
/* harmony import */ var _services_store_service__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ../services/store.service */ "./src/app/services/store.service.ts");
/* harmony import */ var _code_editor_service__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ./code-editor.service */ "./src/app/services/code-editor.service.ts");
/* harmony import */ var _global_operator_service__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./global-operator.service */ "./src/app/services/global-operator.service.ts");
/* harmony import */ var _shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ../shared/mask/mask.component */ "./src/app/shared/mask/mask.component.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};








var ZrenderHelperService = /** @class */ (function () {
    function ZrenderHelperService(storeSrv, codeEditorSrv, globalOperatorSrv) {
        var _this_1 = this;
        this.storeSrv = storeSrv;
        this.codeEditorSrv = codeEditorSrv;
        this.globalOperatorSrv = globalOperatorSrv;
        /** 画布宽度 */
        this.width = 0;
        /** 画布高度 */
        this.height = 0;
        /** 屏幕X偏移量 */
        this.screenOffsetX = 70;
        /** 屏幕Y偏移量 */
        this.screenOffsetY = 165;
        /** 缩放系数 */
        this.scaleRatio = 1;
        /** 等比系数 */
        this.eRatio = 1;
        this.isStick = 1;
        // 旋转角度转弧度  正值为逆时针,负值才是顺时针
        this.rotate = Math.PI / -180;
        storeSrv.getType().subscribe(function (e) {
            if (e === 'stick') {
                _this_1.isStick = 0;
                _this_1.screenOffsetX = 172;
                _this_1.screenOffsetY = 124;
                _this_1.eRatio = 2;
            }
            else if (e === 'core') {
                _this_1.isStick = 1;
                _this_1.screenOffsetX = 70;
                _this_1.screenOffsetY = 165;
                _this_1.eRatio = 1;
            }
            else if (e === 'stick-C') {
                _this_1.isStick = 2;
                _this_1.screenOffsetX = 193;
                _this_1.screenOffsetY = 139;
                _this_1.eRatio = 1.5;
            }
        });
    }
    /** 初始化zrender画布 */
    ZrenderHelperService.prototype.init = function (id) {
        var canvarsWapper = document.getElementById(id);
        this.zrenderWorkspace = zrender__WEBPACK_IMPORTED_MODULE_1__["init"](canvarsWapper, { renderer: 'canvas' });
        this.width = this.zrenderWorkspace.getWidth();
        this.height = this.zrenderWorkspace.getHeight();
        this.scaleRatio = this.width / 460;
        // this.scaleRatio = 1;
        window['zrenderWorkspace'] = this.zrenderWorkspace;
        this.zrenderWorkspace.redrawSvg = this.redrawSvg.bind(this);
        this.createComponentSvg = this.createComponentSvg.bind(this);
    };
    /**
     * 生成工具栏
     * @param toolBar 工具栏
     */
    ZrenderHelperService.prototype.createToolBarSvg = function (toolBar) {
        var _this_1 = this;
        toolBar.toolList.forEach(function (toolItem, index) {
            var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
            g.position = [index * 48 * _this_1.scaleRatio, 0];
            var img = new zrender__WEBPACK_IMPORTED_MODULE_1__["Image"]({
                style: {
                    x: 0,
                    y: 0,
                    width: 48 * _this_1.scaleRatio,
                    height: 48 * _this_1.scaleRatio,
                    image: '../../assets/images/components/' + toolItem.icon
                },
                cursor: 'pointer',
                draggable: true
            });
            g.add(img);
            var _this = _this_1;
            // 开始拖拽
            // 生成一个临时svg
            g.on('dragstart', function (ev) {
                ev.target.attr('position', [0, 0]);
                var component = new toolItem.builder({
                    name: '__temp' + Date.now(),
                    layer: 99999
                });
                var svg = _this.createComponentSvg(component);
                _this.zrenderWorkspace.add(svg);
                // 拖拽圆形
                if (component.type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].CIRCLE) {
                    svg.attr('position', [ev.offsetX, ev.offsetY]);
                }
                // 拖拽标签
                else if (component.type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].LABEL) {
                    var x = ev.offsetX - svg.getBoundingRect().width / 2 * _this.scaleRatio;
                    var y = ev.offsetY - svg.getBoundingRect().height / 2 * _this.scaleRatio;
                    svg.attr('position', [x, y]);
                }
                // 拖拽图片
                else if (component.type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].IMAGE) {
                    var x = ev.offsetX - svg.style.width / 2 * _this.scaleRatio;
                    var y = ev.offsetY - svg.style.height / 2 * _this.scaleRatio;
                    svg.attr('position', [x, y]);
                }
                else {
                    var x = ev.offsetX - component.width / 2 * _this.scaleRatio;
                    var y = ev.offsetY - component.height / 2 * _this.scaleRatio;
                    svg.attr('position', [x, y]);
                }
                this.__m5ui = {
                    temp_component_svg: svg,
                    temp_component: component
                };
            });
            // 拖拽结束
            // 清除临时svg
            g.on('dragend', function (ev) {
                _this.zrenderWorkspace.remove(this.__m5ui.temp_component_svg);
                if (_this.screenContainer.children()[0].contain(ev.event.layerX ? ev.event.layerX : ev.event.zrX, ev.event.layerY ? ev.event.layerY : ev.event.zrY)) {
                    // 添加组件成功
                    var defaultName = _this.storeSrv.getComponentDefaultName(this.__m5ui.temp_component.type);
                    var defaultLayer = _this.storeSrv.getComponentDefaultLayer();
                    if (_this.isStick == 0) {
                        defaultLayer += 3;
                    }
                    else if (_this.isStick == 1) {
                        defaultLayer += 3;
                    }
                    else if (_this.isStick == 2) {
                        defaultLayer += 3;
                    }
                    var component = null;
                    switch (this.__m5ui.temp_component.type) {
                        case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].TITLE:
                            component = new _domain_component__WEBPACK_IMPORTED_MODULE_2__["TitleComponent"]({
                                name: defaultName,
                                layer: defaultLayer
                            });
                            break;
                        case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].LABEL:
                            component = new _domain_component__WEBPACK_IMPORTED_MODULE_2__["LabelComponent"]({
                                name: defaultName,
                                layer: defaultLayer,
                                x: this.__m5ui.temp_component_svg.position[0] - _this.screenOffsetX * _this.scaleRatio,
                                y: this.__m5ui.temp_component_svg.position[1] - _this.screenOffsetY * _this.scaleRatio,
                                rotation: this.__m5ui.temp_component_svg.rotation * this.rotate
                            });
                            break;
                        case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].RECTANGLE:
                            component = new _domain_component__WEBPACK_IMPORTED_MODULE_2__["RectangleComponent"]({
                                name: defaultName,
                                layer: defaultLayer,
                                x: (this.__m5ui.temp_component_svg.position[0] - _this.screenOffsetX * _this.scaleRatio),
                                y: this.__m5ui.temp_component_svg.position[1] - _this.screenOffsetY * _this.scaleRatio,
                            });
                            // console.log(component.x, component.y)
                            break;
                        case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].CIRCLE:
                            component = new _domain_component__WEBPACK_IMPORTED_MODULE_2__["CircleComponent"]({
                                name: defaultName,
                                layer: defaultLayer,
                                x: this.__m5ui.temp_component_svg.position[0] - _this.screenOffsetX * _this.scaleRatio,
                                y: this.__m5ui.temp_component_svg.position[1] - _this.screenOffsetY * _this.scaleRatio
                            });
                            break;
                        case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].IMAGE:
                            component = new _domain_component__WEBPACK_IMPORTED_MODULE_2__["ImageComponent"]({
                                name: defaultName,
                                layer: defaultLayer,
                                x: this.__m5ui.temp_component_svg.position[0] - _this.screenOffsetX * _this.scaleRatio,
                                y: this.__m5ui.temp_component_svg.position[1] - _this.screenOffsetY * _this.scaleRatio
                            });
                            break;
                        default:
                    }
                    // 重新绘图
                    if (component === null)
                        return;
                    _this.createSvg(component);
                    if (_this.isStick == 0) {
                        component.width = component.width / 2;
                        component.height = component.height / 2;
                        component.x = component.x / 2;
                        component.y = component.y / 2;
                    }
                    else if (_this.isStick == 1) {
                    }
                    else if (_this.isStick == 2) {
                        // component.width = component.width / _this.eRatio;
                        // component.height = component.height / _this.eRatio;
                        component.x = component.x / _this.eRatio;
                        component.y = component.y / _this.eRatio;
                        component.radius = component.radius / _this.eRatio;
                        // console.log(component)
                    }
                    _this.storeSrv.addComponent(component);
                    // 此处将其svg坐标换为zrender坐标
                    component.x = Math.floor(component.x / _this.scaleRatio);
                    component.y = Math.floor(component.y / _this.scaleRatio);
                    if (!_this.globalOperatorSrv.codeLock.value) {
                        _this.codeEditorSrv.updateWorkspaceValue();
                    }
                }
            });
            // 拖拽
            g.on('drag', function (ev) {
                ev.target.attr('position', [0, 0]);
                var x = 0;
                var y = 0;
                // 拖拽圆形
                if (this.__m5ui.temp_component.type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].CIRCLE) {
                    x = ev.offsetX;
                    y = ev.offsetY;
                    this.__m5ui.temp_component_svg.attr('position', [x, y]);
                }
                // 拖拽标签
                else if (this.__m5ui.temp_component.type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].LABEL) {
                    x = ev.offsetX - this.__m5ui.temp_component_svg.getBoundingRect().width / 2 * _this.scaleRatio;
                    y = ev.offsetY - this.__m5ui.temp_component_svg.getBoundingRect().height / 2 * _this.scaleRatio;
                    this.__m5ui.temp_component_svg.attr('position', [x, y]);
                }
                // 拖拽图片
                else if (this.__m5ui.temp_component.type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].IMAGE) {
                    x = ev.offsetX - this.__m5ui.temp_component_svg.style.width / 2 * _this.scaleRatio;
                    y = ev.offsetY - this.__m5ui.temp_component_svg.style.height / 2 * _this.scaleRatio;
                    this.__m5ui.temp_component_svg.attr('position', [x, y]);
                }
                else {
                    x = ev.offsetX - this.__m5ui.temp_component.width / 2 * _this.scaleRatio;
                    y = ev.offsetY - this.__m5ui.temp_component.height / 2 * _this.scaleRatio;
                    this.__m5ui.temp_component_svg.attr('position', [x, y]);
                }
            });
            _this_1.zrenderWorkspace.add(g);
        });
    };
    /** 生成模拟器  core */
    ZrenderHelperService.prototype.createSimulator = function () {
        var _this_1 = this;
        var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
        g.position = [40 * this.scaleRatio, 100 * this.scaleRatio];
        /** 外围 */
        var shell = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 24,
                x: 0,
                y: 0,
                width: 380 * this.scaleRatio,
                height: 380 * this.scaleRatio
            },
            style: {
                stroke: '#5A5A5A',
                lineWidth: 6
            },
            cursor: 'default'
        });
        /** 电池 */
        var power = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: -2 * this.scaleRatio,
                y: 100 * this.scaleRatio,
                width: 5 * this.scaleRatio,
                height: 40 * this.scaleRatio
            },
            style: {
                fill: 'red'
            },
            cursor: 'default'
        });
        g.add(shell);
        g.add(power);
        /** 按钮 */
        var buttons = [{ x: 70, y: 330 }, { x: 160, y: 330 }, { x: 250, y: 330 }];
        buttons.forEach(function (btn, index) {
            var button = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
                shape: {
                    r: 5,
                    x: btn.x * _this_1.scaleRatio,
                    y: btn.y * _this_1.scaleRatio,
                    width: 56 * _this_1.scaleRatio,
                    height: 30 * _this_1.scaleRatio
                },
                style: {
                    fill: '#C2BFCB'
                }
            });
            var id = index === 0 ? '____buttonA' : index === 1 ? '____buttonB' : '____buttonC';
            button.on('click', function (ev) {
                var component = _this_1.storeSrv.getComponentById(id);
                _this_1.globalOperatorSrv.setSelectedComponent(component);
            });
            button.on('dblclick', function (ev) {
                var buttonBlock = window['BlocklyEditor'].newBlock('button_callback', window['Blockly'].utils.genUid());
                if (index === 0) {
                    buttonBlock.inputList[0].fieldRow[1].text_ = 'A';
                    buttonBlock.inputList[0].fieldRow[1].value_ = 'A';
                    buttonBlock.moveBy(50, 100);
                }
                else if (index === 1) {
                    buttonBlock.inputList[0].fieldRow[1].text_ = 'B';
                    buttonBlock.inputList[0].fieldRow[1].value_ = 'B';
                    buttonBlock.moveBy(50, 200);
                }
                else if (index === 2) {
                    buttonBlock.inputList[0].fieldRow[1].text_ = 'C';
                    buttonBlock.inputList[0].fieldRow[1].value_ = 'C';
                    buttonBlock.moveBy(50, 300);
                }
                buttonBlock.getRelativeToSurfaceXY(); // 得到块位置
                buttonBlock.initSvg();
                buttonBlock.render();
            });
            g.add(button);
        });
        /** Port口 */
        var ports = [
            { x: -26, y: 230, width: 12, height: 60, fillColr: '#c03546' },
            { x: 110, y: -26, width: 60, height: 12, fillColr: '#5e5e5f' },
            { x: 210, y: -26, width: 60, height: 12, fillColr: 'rgb(0, 160, 200)' }
        ];
        ports.forEach(function (p) {
            var port = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
                shape: {
                    x: p.x * _this_1.scaleRatio,
                    y: p.y * _this_1.scaleRatio,
                    width: p.width * _this_1.scaleRatio,
                    height: p.height * _this_1.scaleRatio
                },
                style: {
                    fill: p.fillColr,
                    opacity: 0
                }
            });
            g.add(port);
        });
        this.zrenderWorkspace.add(g);
    };
    /** M5stick模拟器  stick*/
    ZrenderHelperService.prototype.creatM5stickSimulator = function () {
        var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
        g.position = [136 * this.scaleRatio, 100 * this.scaleRatio];
        /** 外圈 */
        var shell = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 0,
                y: 0,
                width: 200 * this.scaleRatio,
                height: 400 * this.scaleRatio
            },
            style: {
                stroke: '#666',
                fill: '#444',
                lineWidth: 2
            },
            cursor: 'default'
        });
        /** 电池 */
        var power = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: -2 * this.scaleRatio,
                y: 320 * this.scaleRatio,
                width: 5 * this.scaleRatio,
                height: 40 * this.scaleRatio
            },
            style: {
                fill: 'red'
            },
            cursor: 'default'
        });
        /** 复位 */
        var reset = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 198 * this.scaleRatio,
                y: 100 * this.scaleRatio,
                width: 5 * this.scaleRatio,
                height: 40 * this.scaleRatio
            },
            style: {
                fill: '#ccc'
            },
            cursor: 'default'
        });
        /** 红外感应 */
        var induction = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 25 * this.scaleRatio,
                y: -2 * this.scaleRatio,
                width: 14 * this.scaleRatio,
                height: 5 * this.scaleRatio
            },
            style: {
                fill: '#ccc'
            },
            cursor: 'default'
        });
        /** m5logo */
        var text = new zrender__WEBPACK_IMPORTED_MODULE_1__["Text"]({
            position: [40 * this.scaleRatio, 320 * this.scaleRatio],
            style: {
                text: 'M5',
                fontWeight: 700,
                fontSize: 70 * this.scaleRatio,
                textFill: '#ccc'
            },
            cursor: 'default'
        });
        g.add(shell);
        g.add(power);
        g.add(text);
        g.add(reset);
        g.add(induction);
        this.zrenderWorkspace.add(g);
    };
    // static
    /** Static 模拟器  stick-C*/
    ZrenderHelperService.prototype.creatStickcMulator = function () {
        // tslint:disable-next-line: prefer-const
        var scaleRatio = this.scaleRatio;
        var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
        g.position = [136 * scaleRatio, 100 * scaleRatio];
        /** 外圈 */
        var shell = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 20,
                x: 0,
                y: 0,
                width: 235 * scaleRatio,
                height: 470 * scaleRatio
            },
            style: {
                stroke: '#666',
                // fill: '#d96e05',
                fill: '#ea8432',
                lineWidth: 3
            },
            cursor: 'default'
        });
        /** 底部卡槽 */
        var neck = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 92.5 * this.scaleRatio,
                y: 465 * this.scaleRatio,
                width: 50 * this.scaleRatio,
                height: 5 * this.scaleRatio
            },
            style: {
                fill: '#ccc'
            },
            cursor: 'default'
        });
        /** 电池 */
        var power = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: -2 * scaleRatio,
                y: 350 * scaleRatio,
                width: 5 * scaleRatio,
                height: 40 * scaleRatio
            },
            style: {
                fill: 'red'
            },
            cursor: 'default'
        });
        /** 复位 */
        var reset = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 230 * scaleRatio,
                y: 95 * scaleRatio,
                width: 5 * scaleRatio,
                height: 40 * scaleRatio
            },
            style: {
                fill: '#ccc'
            },
            cursor: 'default'
        });
        /** 红外感应 */
        var induction = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 25 * scaleRatio,
                y: -2 * scaleRatio,
                width: 14 * scaleRatio,
                height: 5 * scaleRatio
            },
            style: {
                fill: 'red'
            },
            cursor: 'default'
        });
        /** 灯 */
        var light = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 38 * scaleRatio,
                y: -2 * scaleRatio,
                width: 14 * scaleRatio,
                height: 5 * scaleRatio
            },
            style: {
                fill: '#ccc'
            },
            cursor: 'default'
        });
        /** m5logo */
        /** m5logo 按钮 */
        var text_btn = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 40 * scaleRatio,
                y: 330 * scaleRatio,
                width: 156 * scaleRatio,
                height: 98 * scaleRatio
            },
            style: {
                fill: '#555555'
            },
            cursor: 'pointer'
        });
        var text_btn_bk = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                r: 10,
                x: 43 * scaleRatio,
                y: 333 * scaleRatio,
                width: 150 * scaleRatio,
                height: 105 * scaleRatio
            },
            style: {
                fill: '#ea8432',
            },
            cursor: 'pointer'
        });
        var text = new zrender__WEBPACK_IMPORTED_MODULE_1__["Text"]({
            position: [57 * scaleRatio, 355 * scaleRatio],
            style: {
                text: 'M5',
                fontWeight: 700,
                fontSize: 75 * scaleRatio,
                textFill: '#d96e05',
                fontFamily: 'Verdana, Arial, Helvetica, sans-serif'
            },
            cursor: 'pointer'
        });
        g.add(shell);
        g.add(power);
        g.add(text_btn);
        g.add(text_btn_bk);
        g.add(text);
        g.add(reset);
        g.add(induction);
        g.add(light);
        g.add(neck);
        this.zrenderWorkspace.add(g);
    };
    /** 创建主编辑区域 */
    ZrenderHelperService.prototype.createMainEditArea = function () {
        var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
        g.position = [this.screenOffsetX * this.scaleRatio, this.screenOffsetY * this.scaleRatio];
        this.screenContainer = g;
        this.zrenderWorkspace.add(g);
        this.zrenderWorkspace.screenContainer = g;
    };
    /** 创建删除区域 */
    ZrenderHelperService.prototype.createDeleteArea = function () {
        var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
        g.position = [280 * this.scaleRatio, 0 * this.scaleRatio];
        var img = new zrender__WEBPACK_IMPORTED_MODULE_1__["Image"]({
            style: {
                image: '../../assets/images/trash.png',
                x: 74 * this.scaleRatio,
                y: 8 * this.scaleRatio,
                width: 40 * this.scaleRatio,
                height: 40 * this.scaleRatio,
                opacity: 0.6
            }
        });
        var box = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                x: 0,
                y: 0,
                width: 180 * this.scaleRatio,
                height: 48 * this.scaleRatio
            },
            style: {
                opacity: 0.3,
                fill: 'red'
            }
        });
        g.add(box);
        g.add(img);
        g.hide();
        this.zrenderWorkspace.add(g);
        this.zrenderWorkspace.trash = g;
    };
    /** 创建Unit区域 */
    ZrenderHelperService.prototype.createUnitArea = function () {
        var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
        g.position = [50 * this.scaleRatio, 600 * this.scaleRatio];
        var text = new zrender__WEBPACK_IMPORTED_MODULE_1__["Text"]({
            style: {
                text: 'Units',
                fontWeight: 'bolder',
                fontSize: 24 * this.scaleRatio,
                textFill: '#FFFFFF'
            }
        });
        text.position = [50 * this.scaleRatio, 600 * this.scaleRatio];
        this.unitContainer = g;
        this.zrenderWorkspace.add(text);
        this.zrenderWorkspace.add(g);
        this.zrenderWorkspace.unitContainer = g;
    };
    /**
     * 创建组件Svg
     * @param component 组件实例
     */
    ZrenderHelperService.prototype.createComponentSvg = function (component) {
        switch (component.type) {
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].SCREEN:
                return this.createScreenComponentSvg(component);
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].BUTTON:
                return this.createButtonComponentSvg(component);
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].TITLE:
                return this.createTitleComponentSvg(component);
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].LABEL:
                return this.createLabelComponentSvg(component);
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].RECTANGLE:
                return this.createRectangleComponentSvg(component);
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].CIRCLE:
                return this.createCircleComponentSvg(component);
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].IMAGE:
                return this.createImageComponentSvg(component);
        }
    };
    /**
     * 新增屏幕Svg
     * @param component 屏幕组件实例
     */
    ZrenderHelperService.prototype.createScreenComponentSvg = function (component) {
        var screen = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                x: component.x * this.scaleRatio,
                y: component.y * this.scaleRatio,
                width: component.width * this.scaleRatio,
                height: component.height * this.scaleRatio,
            },
            style: {
                fill: component.backgroundColor
            }
        });
        screen.id = component.id;
        screen.__component = component;
        var _this = this;
        screen.on('click', function (ev) {
            _this.componentClick.apply(this, [ev, _this]);
        });
        component.componentSvg = screen;
        return screen;
    };
    /**
     * 新增按钮Svg
     * @param component 按钮组件实例
     */
    ZrenderHelperService.prototype.createButtonComponentSvg = function (component) {
        var button = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                x: component.x * this.scaleRatio,
                y: component.y * this.scaleRatio,
                width: component.width * this.scaleRatio,
                height: component.height * this.scaleRatio,
                r: [4, 4, 0, 0]
            },
            style: {
                fill: '#111111',
                stroke: '#FFFFFF',
                textRect: {
                    x: component.x * this.scaleRatio,
                    y: component.y * this.scaleRatio,
                    width: component.width * this.scaleRatio,
                    height: component.height * this.scaleRatio,
                },
                text: component.text,
                textFill: '#FFFFFF',
                fontSize: 15 * this.scaleRatio
            },
            cursor: 'default'
        });
        component.visibility ? button.show() : button.hide();
        component.componentSvg = button;
        return button;
    };
    /**
     * 创建标题组件Svg
     * @param component 标题组件实例
     */
    ZrenderHelperService.prototype.createTitleComponentSvg = function (component) {
        var title = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                x: component.x * this.scaleRatio,
                y: component.y * this.scaleRatio,
                width: component.width * this.scaleRatio,
                height: component.height * this.scaleRatio
            },
            style: {
                fill: component.backgroundColor,
                textRect: {
                    x: component.x * this.scaleRatio,
                    y: component.y * this.scaleRatio,
                    width: component.width * this.scaleRatio,
                    height: component.height * this.scaleRatio
                },
                text: component.text,
                textFill: component.color,
                textPosition: [2, 4 * this.scaleRatio],
                fontSize: 15 * this.scaleRatio
            },
            draggable: true
        });
        title.id = component.id;
        title.position = [0, 0];
        title.__component = component;
        var _this = this;
        title.on('dragstart', function (ev) {
            _this.componentDragStart.apply(this, [ev, _this]);
        });
        title.on('drag', function (ev) {
            _this.componentDrag.apply(this, [ev, _this]);
        });
        title.on('dragend', function (ev) {
            _this.componentDragEnd.apply(this, [ev, _this]);
        });
        component.componentSvg = title;
        return title;
    };
    /**
     * 新增标签组件
     * @param component 标签组件实例
     */
    ZrenderHelperService.prototype.createLabelComponentSvg = function (component) {
        var font = {
            family: 'sans-serif',
            size: 16
        };
        if (this.isStick == 0) {
            font = { family: 'sans-serif', size: 16 };
        }
        else if (this.isStick == 1) {
            if (component.font === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].UBUNTU_C)
                font = { family: 'Ubuntu-C', size: 15 };
            else if (component.font === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].COMIC)
                font = { family: 'Comic', size: 25 };
            else if (component.font === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_18PX)
                font = { family: 'DejaVuSans', size: 18 };
            else if (component.font === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_24PX)
                font = { family: 'DejaVuSans', size: 24 };
            else if (component.font === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_40PX)
                font = { family: 'DejaVuSans', size: 40 };
            else if (component.font === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_56PX)
                font = { family: 'DejaVuSans', size: 56 };
            else if (component.font === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_72PX)
                font = { family: 'DejaVuSans', size: 72 };
            else
                font = { family: 'sans-serif', size: 16 };
        }
        else if (this.isStick == 2) {
            font = { family: 'sans-serif', size: 16 };
        }
        var label = new zrender__WEBPACK_IMPORTED_MODULE_1__["Text"]({
            style: {
                text: component.text,
                fontSize: font.size * this.scaleRatio,
                fontFamily: font.family,
                textFill: component.color,
            },
            draggable: true,
            rotation: component.rotation * this.rotate
        });
        label.id = component.id;
        label.position = [component.x, component.y];
        label.rotation = typeof (component.rotation) == "number" ? component.rotation * this.rotate : 1;
        // label.rotation=100;
        label.__component = component;
        var _this = this;
        label.on('dragstart', function (ev) {
            _this.componentDragStart.apply(this, [ev, _this]);
        });
        label.on('drag', function (ev) {
            _this.componentDrag.apply(this, [ev, _this]);
        });
        label.on('dragend', function (ev) {
            _this.componentDragEnd.apply(this, [ev, _this]);
        });
        component.componentSvg = label;
        return label;
    };
    /**
     * 新增矩形组件
     * @param component 矩形组件实例
     */
    ZrenderHelperService.prototype.createRectangleComponentSvg = function (component) {
        var rect = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                width: component.width * this.scaleRatio,
                height: component.height * this.scaleRatio
            },
            style: {
                fill: component.backgroundColor,
                stroke: component.borderColor
            },
            draggable: true
        });
        rect.id = component.id;
        // rect.position = [component.x * this.scaleRatio, component.y * this.scaleRatio];
        rect.position = [component.x, component.y];
        rect.__component = component;
        var _this = this;
        rect.on('dragstart', function (ev) {
            _this.componentDragStart.apply(this, [ev, _this]);
        });
        rect.on('drag', function (ev) {
            _this.componentDrag.apply(this, [ev, _this]);
        });
        rect.on('dragend', function (ev) {
            _this.componentDragEnd.apply(this, [ev, _this]);
        });
        component.componentSvg = rect;
        return rect;
    };
    /**
     * 新增圆形组件
     * @param component 圆形组件实例
     */
    ZrenderHelperService.prototype.createCircleComponentSvg = function (component) {
        var circle = new zrender__WEBPACK_IMPORTED_MODULE_1__["Circle"]({
            shape: {
                r: component.radius * this.scaleRatio
            },
            style: {
                fill: component.backgroundColor,
                stroke: component.borderColor
            },
            draggable: true
        });
        circle.id = component.id;
        circle.position = [component.x, component.y];
        circle.__component = component;
        var _this = this;
        circle.on('dragstart', function (ev) {
            _this.componentDragStart.apply(this, [ev, _this]);
        });
        circle.on('drag', function (ev) {
            _this.componentDrag.apply(this, [ev, _this]);
        });
        circle.on('dragend', function (ev) {
            _this.componentDragEnd.apply(this, [ev, _this]);
        });
        component.componentSvg = circle;
        return circle;
    };
    /**
     * 新增图片组件
     * @param component 图片组件实例
     */
    ZrenderHelperService.prototype.createImageComponentSvg = function (component) {
        var img = new Image();
        img.src = '../../assets/images/default.jpg';
        var image = new zrender__WEBPACK_IMPORTED_MODULE_1__["Image"]({
            style: {
                width: 100 * this.scaleRatio * this.eRatio,
                height: 100 * this.scaleRatio * this.eRatio,
                // image: '../../assets/images/' + component.imagePath
                image: img
            },
            draggable: true
        });
        image.id = component.id;
        image.position = [component.x, component.y];
        image.__component = component;
        var _this = this;
        image.on('dragstart', function (ev) {
            _this.componentDragStart.apply(this, [ev, _this]);
        });
        image.on('drag', function (ev) {
            _this.componentDrag.apply(this, [ev, _this]);
        });
        image.on('dragend', function (ev) {
            _this.componentDragEnd.apply(this, [ev, _this]);
        });
        component.componentSvg = image;
        return image;
    };
    /**
     * 创建Svg
     * @param component 新增组件实例
     */
    ZrenderHelperService.prototype.createSvg = function (component) {
        this.screenContainer.add(this.createComponentSvg(component));
    };
    /**
     * 重新渲染Svg
     */
    ZrenderHelperService.prototype.redrawSvg = function () {
        var _this_1 = this;
        for (var i_1 = 4; i_1 < this.screenContainer.childCount();) {
            this.screenContainer.remove(this.screenContainer.childAt(i_1));
        }
        //  此处修改解决保存为m5后打开则出现错误比例 
        var _this = this;
        for (var i = 4; i < this.storeSrv.componentList.value.length; i++) {
            _this.storeSrv.componentList.value[i].x = Math.floor(_this.storeSrv.componentList.value[i].x * _this.scaleRatio);
            _this.storeSrv.componentList.value[i].y = Math.floor(_this.storeSrv.componentList.value[i].y * _this.scaleRatio);
        }
        this.storeSrv.componentList.value.forEach(function (c) { return (_this_1.screenContainer.add(_this_1.createComponentSvg(c))); });
        for (var i = 4; i < this.storeSrv.componentList.value.length; i++) {
            _this.storeSrv.componentList.value[i].x = Math.floor(_this.storeSrv.componentList.value[i].x / _this.scaleRatio);
            _this.storeSrv.componentList.value[i].y = Math.floor(_this.storeSrv.componentList.value[i].y / _this.scaleRatio);
        }
        // this.storeSrv.unitList.value.forEach(u => this.unitContainer.add(this.updateUnitSvg()));
        this.updateUnitSvg();
    };
    /**
     * 更新Svg
     * 改变弹窗尺寸后修改其比例
     */
    ZrenderHelperService.prototype.updateSvg = function (component, key, value) {
        var _a, _b, _c;
        switch (key) {
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].X:
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].Y:
                if (this.isStick == 0) {
                    component['componentSvg'].attr('position', [component.x * this.scaleRatio * 2, component.y * this.scaleRatio * 2]);
                }
                else if (this.isStick == 1) {
                    component['componentSvg'].attr('position', [component.x * this.scaleRatio, component.y * this.scaleRatio]);
                }
                else if (this.isStick == 2) {
                    component['componentSvg'].attr('position', [component.x * this.scaleRatio * this.eRatio, component.y * this.scaleRatio * this.eRatio]);
                }
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].WIDTH:
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].HEIGHT:
                if (this.isStick == 0) {
                    component['componentSvg'].attr({ shape: (_a = {}, _a[key] = value * this.scaleRatio * 2, _a) });
                }
                else if (this.isStick == 1) {
                    component['componentSvg'].attr({ shape: (_b = {}, _b[key] = value * this.scaleRatio, _b) });
                }
                else if (this.isStick == 2) {
                    // 乘缩放系数
                    component['componentSvg'].attr({ shape: (_c = {}, _c[key] = value * this.scaleRatio * this.eRatio, _c) });
                }
                break;
            // 设置旋转属性
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].ROTATION:
                component['componentSvg'].attr({ rotation: component.rotation * this.rotate });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].RADIUS:
                component['componentSvg'].attr({ shape: { r: value * this.scaleRatio } });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].TEXT:
                component['componentSvg'].attr({ style: { text: value } });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].COLOR:
                component['componentSvg'].attr({ style: { textFill: value } });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].BORDER_COLOR:
                component['componentSvg'].attr({ style: { stroke: value } });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].BACKGROUND_COLOR:
                component['componentSvg'].attr({ style: { fill: value } });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].FONT:
                if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].UBUNTU_C)
                    component['componentSvg'].attr({ style: { fontFamily: 'Ubuntu-C', fontSize: 15 } });
                else if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].COMIC)
                    component['componentSvg'].attr({ style: { fontFamily: 'Comic', fontSize: 25 } });
                else if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_18PX)
                    component['componentSvg'].attr({ style: { fontFamily: 'DejaVuSans', fontSize: 18 } });
                else if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_24PX)
                    component['componentSvg'].attr({ style: { fontFamily: 'DejaVuSans', fontSize: 24 } });
                else if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_40PX)
                    component['componentSvg'].attr({ style: { fontFamily: 'DejaVuSans', fontSize: 40 } });
                else if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_56PX)
                    component['componentSvg'].attr({ style: { fontFamily: 'DejaVuSans', fontSize: 56 } });
                else if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEJAVUSANS_72PX)
                    component['componentSvg'].attr({ style: { fontFamily: 'DejaVuSans', fontSize: 72 } });
                else if (value === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["FONT_ALIAS"].DEFAULT_SMALL)
                    component['componentSvg'].attr({ style: { fontFamily: 'sans-serif', fontSize: 10 } });
                else
                    component['componentSvg'].attr({ style: { fontFamily: 'sans-serif', fontSize: 13 } });
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].VISIBILITY:
                if (component.type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].BUTTON) {
                    value === 'true' ? component['componentSvg'].show() : component['componentSvg'].hide();
                }
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].LAYER:
                component['componentSvg'].attr({ zlevel: value });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].IMAGE_PATH:
                component['componentSvg'].attr({ style: { image: value } });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].IMAGE_WIDTH:
                component['componentSvg'].attr({ style: { width: value * this.scaleRatio } });
                break;
            case _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["COMPONENT_ALIAS"].IMAGE_HEIGHT:
                component['componentSvg'].attr({ style: { height: value * this.scaleRatio } });
                break;
            default:
                break;
        }
        if (!this.globalOperatorSrv.codeLock.value) {
            this.codeEditorSrv.updateWorkspaceValue();
        }
    };
    /**
     * 组件拖拽开始事件
     * @param ev 鼠标事件
     * @param _this 服务作用域
     */
    ZrenderHelperService.prototype.componentDragStart = function (ev, _this) {
        ev.event.preventDefault();
        ev.event.stopPropagation();
        this['__zr'].trash.show();
        this['__startX'] = this['__component'].getProp('x');
        this['__startY'] = this['__component'].getProp('y');
        _this.globalOperatorSrv.setSelectedComponent(null);
    };
    /**
     * 组件拖拽事件
     * @param ev 鼠标事件
     * @param _this 服务作用域
     */
    ZrenderHelperService.prototype.componentDrag = function (ev, _this) {
        this['__component'].setProp('x', Math.floor(this['position'][0] / _this.scaleRatio));
        this['__component'].setProp('y', Math.floor(this['position'][1] / _this.scaleRatio));
    };
    /**
     * 组件拖拽结束事件
     * @param ev 鼠标事件
     * @param _this 服务作用域
     */
    ZrenderHelperService.prototype.componentDragEnd = function (ev, _this) {
        this['__zr'].trash.hide();
        // 判断是否在移除区域
        if (this['__zr'].trash.children()[0].contain(ev.event.layerX ? ev.event.layerX : ev.event.zrX, ev.event.layerY ? ev.event.layerY : ev.event.zrY)) {
            _this.storeSrv.removeComponentById(this['id']);
            _this.globalOperatorSrv.setSelectedComponent(null);
            if (!_this.globalOperatorSrv.codeLock.value) {
                _this.codeEditorSrv.updateWorkspaceValue();
            }
            return this['__zr'].screenContainer.remove(this);
        }
        // 判断是否在可放置区域
        if (!this['__zr'].screenContainer.children()[0].contain(ev.event.layerX ? ev.event.layerX : ev.event.zrX, ev.event.layerY ? ev.event.layerY : ev.event.zrY)) {
            this['attr']('position', [Math.floor(this['__startX'] * _this.scaleRatio), Math.floor(this['__startY'] * _this.scaleRatio)]);
            this['__component'].setProp('x', Math.floor(this['__startX']));
            this['__component'].setProp('y', Math.floor(this['__startY']));
            _this.globalOperatorSrv.setSelectedComponent(this['__component']);
            return;
        }
        // 判断是否为Title组件
        if (this['__component'].type === _utils_common_data__WEBPACK_IMPORTED_MODULE_3__["TYPE_ALIAS"].TITLE) {
            this['attr']('position', [0, 0]);
            _this.globalOperatorSrv.setSelectedComponent(this['__component']);
            return;
        }
        if (_this.isStick == 0) {
            this['__component'].setProp('x', Math.floor(this['position'][0] / _this.scaleRatio / 2));
            this['__component'].setProp('y', Math.floor(this['position'][1] / _this.scaleRatio / 2));
        }
        else if (_this.isStick == 1) {
            this['__component'].setProp('x', Math.floor(this['position'][0] / _this.scaleRatio));
            this['__component'].setProp('y', Math.floor(this['position'][1] / _this.scaleRatio));
        }
        else if (_this.isStick == 2) {
            // console.log(Math.floor(this['position'][0] / _this.scaleRatio / 2), Math.floor(this['position'][1] / _this.scaleRatio / 2));
            this['__component'].setProp('x', Math.floor(this['position'][0] / _this.scaleRatio / _this.eRatio));
            this['__component'].setProp('y', Math.floor(this['position'][1] / _this.scaleRatio / _this.eRatio));
        }
        _this.globalOperatorSrv.setSelectedComponent(this['__component']);
        if (!_this.globalOperatorSrv.codeLock.value) {
            _this.codeEditorSrv.updateWorkspaceValue();
        }
    };
    ZrenderHelperService.prototype.componentClick = function (ev, _this) {
        _this.globalOperatorSrv.setSelectedComponent(this['__component']);
    };
    /** 更新Unit列表 */
    ZrenderHelperService.prototype.updateUnitSvg = function () {
        var _this_1 = this;
        // 清空原内容
        this.zrenderWorkspace.unitContainer.removeAll();
        this.zrenderWorkspace._needsRefresh = true;
        var len = this.storeSrv.unitList.value.length;
        this.storeSrv.unitList.value.forEach(function (u, index) {
            var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
            g.id = u.id;
            g.create_time = u.createTime;
            g.type = u.type;
            var x = index % 5 * 70;
            var y = Math.floor(index / 5) * 70 + 40;
            g.position = [x * _this_1.scaleRatio, y * _this_1.scaleRatio];
            var box = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
                shape: {
                    x: 0,
                    y: 0,
                    width: 48 * _this_1.scaleRatio,
                    height: 48 * _this_1.scaleRatio,
                    r: [4]
                },
                style: {
                    lineWidth: 2,
                    stroke: '#FFFFFF',
                    fill: '#303131'
                }
            });
            var img = new zrender__WEBPACK_IMPORTED_MODULE_1__["Image"]({
                style: {
                    image: '../../assets/images/units/' + u.icon,
                    width: 48 * _this_1.scaleRatio,
                    height: 48 * _this_1.scaleRatio,
                    x: 0,
                    y: 0
                },
                draggable: true
            });
            var _this = _this_1;
            img.on('click', function (ev) {
                _this.globalOperatorSrv.setSelectedUnit(u);
            });
            img.on('dragstart', function (ev) {
                _this.zrenderWorkspace.trash.show();
                this.__originalPosition = {
                    x: this.position[0] * _this.scaleRatio,
                    y: this.position[1] * _this.scaleRatio
                };
            });
            img.on('dragend', function (ev) {
                _this.zrenderWorkspace.trash.hide();
                // 判断是否在移除区域内
                if (this['__zr'].trash.children()[0].contain(ev.event.layerX ? ev.event.layerX : ev.event.zrX, ev.event.layerY ? ev.event.layerY : ev.event.zrY)) {
                    _this.storeSrv.removeUnitById(this.parent.id);
                    _this.updateUnitSvg();
                    if (!_this.globalOperatorSrv.codeLock.value) {
                        _this.codeEditorSrv.updateWorkspaceValue();
                    }
                    return;
                }
                this.attr('position', [this.__originalPosition.x, this.__originalPosition.y]);
            });
            g.add(box);
            g.add(img);
            u.unitSvg = g;
            _this_1.zrenderWorkspace.unitContainer.add(g);
        });
        var g = new zrender__WEBPACK_IMPORTED_MODULE_1__["Group"]({});
        var x = len % 5 * 70;
        var y = Math.floor(len / 5) * 70 + 40;
        g.position = [x * this.scaleRatio, y * this.scaleRatio];
        var box = new zrender__WEBPACK_IMPORTED_MODULE_1__["Rect"]({
            shape: {
                x: 0,
                y: 0,
                width: 48 * this.scaleRatio,
                height: 48 * this.scaleRatio,
                r: [4]
            },
            style: {
                lineWidth: 2,
                stroke: '#FFFFFF',
                fill: '#303131'
            }
        });
        var img = new zrender__WEBPACK_IMPORTED_MODULE_1__["Image"]({
            style: {
                image: '../../assets/images/add.png',
                width: 48 * this.scaleRatio,
                height: 48 * this.scaleRatio,
                x: 0,
                y: 0
            }
        });
        img.on('mouseover', function (ev) {
            box.animate('style', false)
                .when(200, {
                fill: 'rgb(0, 100, 160)'
            })
                .start();
        });
        img.on('mouseout', function (ev) {
            box.animate('style', false)
                .when(300, {
                fill: '#303131'
            })
                .start();
        });
        img.on('click', function (ev) {
            var maskModal = _this_1.globalOperatorSrv.createMaskModal(_shared_mask_mask_component__WEBPACK_IMPORTED_MODULE_7__["MaskComponent"]);
            maskModal.instance.createDynamicComponent(_utils_common_data__WEBPACK_IMPORTED_MODULE_3__["DYNAMIC_COMPONENT_TYPE"].UNIT_MODAL);
        });
        g.add(box);
        g.add(img);
        this.zrenderWorkspace.unitContainer.add(g);
    };
    ZrenderHelperService = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"])({
            providedIn: 'root'
        }),
        __metadata("design:paramtypes", [_services_store_service__WEBPACK_IMPORTED_MODULE_4__["StoreService"],
            _code_editor_service__WEBPACK_IMPORTED_MODULE_5__["CodeEditorService"],
            _global_operator_service__WEBPACK_IMPORTED_MODULE_6__["GlobalOperatorService"]])
    ], ZrenderHelperService);
    return ZrenderHelperService;
}());



/***/ }),

/***/ "./src/app/shared/loading/loading.component.html":
/*!*******************************************************!*\
  !*** ./src/app/shared/loading/loading.component.html ***!
  \*******************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"loading\">\r\n  <div class=\"wrap\">\r\n    <div class=\"k-line2 k-line12-1\"></div>\r\n    <div class=\"k-line2 k-line12-2\"></div>\r\n    <div class=\"k-line2 k-line12-3\"></div>\r\n    <div class=\"k-line2 k-line12-4\"></div>\r\n    <div class=\"k-line2 k-line12-5\"></div>\r\n    <div class=\"k-line2 k-line12-6\"></div>\r\n    <div class=\"k-line2 k-line12-7\"></div>\r\n    <div class=\"k-line2 k-line12-8\"></div>\r\n  <p>{{ 'LOADING' | translate}}</p>\r\n  </div>\r\n</div>\r\n"

/***/ }),

/***/ "./src/app/shared/loading/loading.component.scss":
/*!*******************************************************!*\
  !*** ./src/app/shared/loading/loading.component.scss ***!
  \*******************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".loading {\n  position: fixed;\n  top: 0;\n  left: 0;\n  width: 100%;\n  height: 100%;\n  z-index: 9999999;\n  background-color: black; }\n\n.wrap {\n  position: relative;\n  top: 50%;\n  left: 50%;\n  text-align: center;\n  margin: 0 auto;\n  -webkit-transform: translate(-50%, -50%);\n          transform: translate(-50%, -50%); }\n\np {\n  color: white;\n  font-size: 24px;\n  text-align: center;\n  font-family: Arial; }\n\n.k-line12-1 {\n  -webkit-animation: k-loadingS 4s infinite;\n          animation: k-loadingS 4s infinite;\n  -webkit-animation-delay: .8s;\n          animation-delay: .8s; }\n\n.k-line12-2 {\n  -webkit-animation: k-loadingS 4s infinite;\n          animation: k-loadingS 4s infinite;\n  -webkit-animation-delay: .7s;\n          animation-delay: .7s; }\n\n.k-line12-3 {\n  -webkit-animation: k-loadingS 4s infinite;\n          animation: k-loadingS 4s infinite;\n  -webkit-animation-delay: .6s;\n          animation-delay: .6s; }\n\n.k-line12-4 {\n  -webkit-animation: k-loadingS 4s infinite;\n          animation: k-loadingS 4s infinite;\n  -webkit-animation-delay: .5s;\n          animation-delay: .5s; }\n\n.k-line12-5 {\n  -webkit-animation: k-loadingS 4s infinite;\n          animation: k-loadingS 4s infinite;\n  -webkit-animation-delay: .4s;\n          animation-delay: .4s; }\n\n.k-line12-6 {\n  -webkit-animation: k-loadingS 4s infinite;\n          animation: k-loadingS 4s infinite;\n  -webkit-animation-delay: .3s;\n          animation-delay: .3s; }\n\n.k-line12-7 {\n  -webkit-animation: k-loadingS 4s infinite;\n          animation: k-loadingS 4s infinite;\n  -webkit-animation-delay: .2s;\n          animation-delay: .2s; }\n\n.k-line12-8 {\n  -webkit-animation: k-loadingS 4s infinite;\n          animation: k-loadingS 4s infinite;\n  -webkit-animation-delay: .1s;\n          animation-delay: .1s; }\n\n.k-line2 {\n  display: inline-block;\n  background: #666;\n  height: 10px;\n  width: 10px;\n  opacity: 0;\n  border-radius: 50%;\n  -webkit-transform: translateX(-300px);\n          transform: translateX(-300px);\n  background-color: white; }\n\n@-webkit-keyframes k-loadingS {\n  40% {\n    -webkit-transform: translateX(0);\n            transform: translateX(0);\n    opacity: .8; }\n  100% {\n    -webkit-transform: translateX(300px);\n            transform: translateX(300px);\n    opacity: 0; } }\n\n@keyframes k-loadingS {\n  40% {\n    -webkit-transform: translateX(0);\n            transform: translateX(0);\n    opacity: .8; }\n  100% {\n    -webkit-transform: translateX(300px);\n            transform: translateX(300px);\n    opacity: 0; } }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvc2hhcmVkL2xvYWRpbmcvWjpcXHdvcmtzcGFjZVxcbXlfenJlbmRlclxcZmxvdy9zcmNcXGFwcFxcc2hhcmVkXFxsb2FkaW5nXFxsb2FkaW5nLmNvbXBvbmVudC5zY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUFBO0VBQ0ksZ0JBQWU7RUFDZixPQUFNO0VBQ04sUUFBTztFQUNQLFlBQVc7RUFDWCxhQUFZO0VBQ1osaUJBQWdCO0VBQ2hCLHdCQUFrQyxFQUNyQzs7QUFFRDtFQUNJLG1CQUFrQjtFQUNsQixTQUFRO0VBQ1IsVUFBUztFQUNULG1CQUFrQjtFQUNsQixlQUFjO0VBQ2QseUNBQWdDO1VBQWhDLGlDQUFnQyxFQUNuQzs7QUFFRDtFQUNJLGFBQVk7RUFDWixnQkFBZTtFQUNmLG1CQUFrQjtFQUNsQixtQkFBa0IsRUFDckI7O0FBRUQ7RUFDSSwwQ0FBaUM7VUFBakMsa0NBQWlDO0VBQ2pDLDZCQUFvQjtVQUFwQixxQkFBb0IsRUFDdkI7O0FBRUQ7RUFDSSwwQ0FBaUM7VUFBakMsa0NBQWlDO0VBQ2pDLDZCQUFvQjtVQUFwQixxQkFBb0IsRUFDdkI7O0FBRUQ7RUFDSSwwQ0FBaUM7VUFBakMsa0NBQWlDO0VBQ2pDLDZCQUFvQjtVQUFwQixxQkFBb0IsRUFDdkI7O0FBRUQ7RUFDSSwwQ0FBaUM7VUFBakMsa0NBQWlDO0VBQ2pDLDZCQUFvQjtVQUFwQixxQkFBb0IsRUFDdkI7O0FBRUQ7RUFDSSwwQ0FBaUM7VUFBakMsa0NBQWlDO0VBQ2pDLDZCQUFvQjtVQUFwQixxQkFBb0IsRUFDdkI7O0FBRUQ7RUFDSSwwQ0FBaUM7VUFBakMsa0NBQWlDO0VBQ2pDLDZCQUFvQjtVQUFwQixxQkFBb0IsRUFDdkI7O0FBRUQ7RUFDSSwwQ0FBaUM7VUFBakMsa0NBQWlDO0VBQ2pDLDZCQUFvQjtVQUFwQixxQkFBb0IsRUFDdkI7O0FBRUQ7RUFDSSwwQ0FBaUM7VUFBakMsa0NBQWlDO0VBQ2pDLDZCQUFvQjtVQUFwQixxQkFBb0IsRUFDdkI7O0FBRUQ7RUFDSSxzQkFBcUI7RUFDckIsaUJBQWdCO0VBQ2hCLGFBQVk7RUFDWixZQUFXO0VBQ1gsV0FBVTtFQUNWLG1CQUFrQjtFQUNsQixzQ0FBNkI7VUFBN0IsOEJBQTZCO0VBRTdCLHdCQUF1QixFQUMxQjs7QUFFRDtFQUNDO0lBQ08saUNBQXVCO1lBQXZCLHlCQUF1QjtJQUN2QixZQUNKLEVBQUE7RUFDQTtJQUNJLHFDQUEyQjtZQUEzQiw2QkFBMkI7SUFDM0IsV0FDSixFQUFBLEVBQUE7O0FBUko7RUFDQztJQUNPLGlDQUF1QjtZQUF2Qix5QkFBdUI7SUFDdkIsWUFDSixFQUFBO0VBQ0E7SUFDSSxxQ0FBMkI7WUFBM0IsNkJBQTJCO0lBQzNCLFdBQ0osRUFBQSxFQUFBIiwiZmlsZSI6InNyYy9hcHAvc2hhcmVkL2xvYWRpbmcvbG9hZGluZy5jb21wb25lbnQuc2NzcyIsInNvdXJjZXNDb250ZW50IjpbIi5sb2FkaW5nIHtcclxuICAgIHBvc2l0aW9uOiBmaXhlZDtcclxuICAgIHRvcDogMDtcclxuICAgIGxlZnQ6IDA7XHJcbiAgICB3aWR0aDogMTAwJTtcclxuICAgIGhlaWdodDogMTAwJTtcclxuICAgIHotaW5kZXg6IDk5OTk5OTk7XHJcbiAgICBiYWNrZ3JvdW5kLWNvbG9yOiByZ2JhKDAsIDAsIDAsIDEpO1xyXG59XHJcblxyXG4ud3JhcCB7XHJcbiAgICBwb3NpdGlvbjogcmVsYXRpdmU7XHJcbiAgICB0b3A6IDUwJTtcclxuICAgIGxlZnQ6IDUwJTtcclxuICAgIHRleHQtYWxpZ246IGNlbnRlcjtcclxuICAgIG1hcmdpbjogMCBhdXRvO1xyXG4gICAgdHJhbnNmb3JtOiB0cmFuc2xhdGUoLTUwJSwgLTUwJSk7XHJcbn1cclxuXHJcbnAge1xyXG4gICAgY29sb3I6IHdoaXRlO1xyXG4gICAgZm9udC1zaXplOiAyNHB4O1xyXG4gICAgdGV4dC1hbGlnbjogY2VudGVyO1xyXG4gICAgZm9udC1mYW1pbHk6IEFyaWFsO1xyXG59XHJcblxyXG4uay1saW5lMTItMSB7XHJcbiAgICBhbmltYXRpb246IGstbG9hZGluZ1MgNHMgaW5maW5pdGU7XHJcbiAgICBhbmltYXRpb24tZGVsYXk6IC44cztcclxufVxyXG5cclxuLmstbGluZTEyLTIge1xyXG4gICAgYW5pbWF0aW9uOiBrLWxvYWRpbmdTIDRzIGluZmluaXRlO1xyXG4gICAgYW5pbWF0aW9uLWRlbGF5OiAuN3M7XHJcbn1cclxuXHJcbi5rLWxpbmUxMi0zIHtcclxuICAgIGFuaW1hdGlvbjogay1sb2FkaW5nUyA0cyBpbmZpbml0ZTtcclxuICAgIGFuaW1hdGlvbi1kZWxheTogLjZzO1xyXG59XHJcblxyXG4uay1saW5lMTItNCB7XHJcbiAgICBhbmltYXRpb246IGstbG9hZGluZ1MgNHMgaW5maW5pdGU7XHJcbiAgICBhbmltYXRpb24tZGVsYXk6IC41cztcclxufVxyXG5cclxuLmstbGluZTEyLTUge1xyXG4gICAgYW5pbWF0aW9uOiBrLWxvYWRpbmdTIDRzIGluZmluaXRlO1xyXG4gICAgYW5pbWF0aW9uLWRlbGF5OiAuNHM7XHJcbn1cclxuXHJcbi5rLWxpbmUxMi02IHtcclxuICAgIGFuaW1hdGlvbjogay1sb2FkaW5nUyA0cyBpbmZpbml0ZTtcclxuICAgIGFuaW1hdGlvbi1kZWxheTogLjNzO1xyXG59XHJcblxyXG4uay1saW5lMTItNyB7XHJcbiAgICBhbmltYXRpb246IGstbG9hZGluZ1MgNHMgaW5maW5pdGU7XHJcbiAgICBhbmltYXRpb24tZGVsYXk6IC4ycztcclxufVxyXG5cclxuLmstbGluZTEyLTgge1xyXG4gICAgYW5pbWF0aW9uOiBrLWxvYWRpbmdTIDRzIGluZmluaXRlO1xyXG4gICAgYW5pbWF0aW9uLWRlbGF5OiAuMXM7XHJcbn1cclxuXHJcbi5rLWxpbmUyIHtcclxuICAgIGRpc3BsYXk6IGlubGluZS1ibG9jaztcclxuICAgIGJhY2tncm91bmQ6ICM2NjY7XHJcbiAgICBoZWlnaHQ6IDEwcHg7XHJcbiAgICB3aWR0aDogMTBweDtcclxuICAgIG9wYWNpdHk6IDA7XHJcbiAgICBib3JkZXItcmFkaXVzOiA1MCU7XHJcbiAgICB0cmFuc2Zvcm06IHRyYW5zbGF0ZVgoLTMwMHB4KTtcclxuICAgIC8vIGJhY2tncm91bmQtY29sb3I6ICM0YjljZGI7XHJcbiAgICBiYWNrZ3JvdW5kLWNvbG9yOiB3aGl0ZTtcclxufVxyXG5cclxuQGtleWZyYW1lcyBrLWxvYWRpbmdTIHtcclxuXHQ0MCUge1xyXG4gICAgICAgIHRyYW5zZm9ybTp0cmFuc2xhdGVYKDApO1xyXG4gICAgICAgIG9wYWNpdHk6LjhcclxuICAgIH1cclxuICAgIDEwMCUge1xyXG4gICAgICAgIHRyYW5zZm9ybTp0cmFuc2xhdGVYKDMwMHB4KTtcclxuICAgICAgICBvcGFjaXR5OjBcclxuICAgIH1cclxufSJdfQ== */"

/***/ }),

/***/ "./src/app/shared/loading/loading.component.ts":
/*!*****************************************************!*\
  !*** ./src/app/shared/loading/loading.component.ts ***!
  \*****************************************************/
/*! exports provided: LoadingComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "LoadingComponent", function() { return LoadingComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};

var LoadingComponent = /** @class */ (function () {
    function LoadingComponent() {
    }
    LoadingComponent.prototype.ngOnInit = function () {
    };
    LoadingComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-loading',
            template: __webpack_require__(/*! ./loading.component.html */ "./src/app/shared/loading/loading.component.html"),
            styles: [__webpack_require__(/*! ./loading.component.scss */ "./src/app/shared/loading/loading.component.scss")]
        }),
        __metadata("design:paramtypes", [])
    ], LoadingComponent);
    return LoadingComponent;
}());



/***/ }),

/***/ "./src/app/shared/mask/mask.component.html":
/*!*************************************************!*\
  !*** ./src/app/shared/mask/mask.component.html ***!
  \*************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"wrapper--full--mask\" #wrapperFullMask>\r\n  <ng-template #container></ng-template>\r\n</div>"

/***/ }),

/***/ "./src/app/shared/mask/mask.component.scss":
/*!*************************************************!*\
  !*** ./src/app/shared/mask/mask.component.scss ***!
  \*************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper--full--mask {\n  position: fixed;\n  top: 0;\n  left: 0;\n  width: 100%;\n  height: 100%;\n  z-index: 10000;\n  background-color: rgba(0, 0, 0, 0.66);\n  -webkit-animation: fadeIn .35s ease;\n          animation: fadeIn .35s ease; }\n  .wrapper--full--mask.hide {\n    -webkit-animation: fadeOut .35s ease;\n            animation: fadeOut .35s ease; }\n  @-webkit-keyframes fadeIn {\n  0% {\n    opacity: 0; }\n  100% {\n    opacity: 1; } }\n  @keyframes fadeIn {\n  0% {\n    opacity: 0; }\n  100% {\n    opacity: 1; } }\n  @-webkit-keyframes fadeOut {\n  0% {\n    opacity: 1; }\n  100% {\n    opacity: 0; } }\n  @keyframes fadeOut {\n  0% {\n    opacity: 1; }\n  100% {\n    opacity: 0; } }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvc2hhcmVkL21hc2svWjpcXHdvcmtzcGFjZVxcbXlfenJlbmRlclxcZmxvdy9zcmNcXGFwcFxcc2hhcmVkXFxtYXNrXFxtYXNrLmNvbXBvbmVudC5zY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUFBO0VBQ0ksZ0JBQWU7RUFDZixPQUFNO0VBQ04sUUFBTztFQUNQLFlBQVc7RUFDWCxhQUFZO0VBQ1osZUFBYztFQUNkLHNDQUFxQztFQUNyQyxvQ0FBMkI7VUFBM0IsNEJBQTJCLEVBSzlCO0VBYkQ7SUFXUSxxQ0FBNEI7WUFBNUIsNkJBQTRCLEVBQy9CO0VBR0w7RUFDSTtJQUNJLFdBQVUsRUFBQTtFQUVkO0lBQ0ksV0FBVSxFQUFBLEVBQUE7RUFMbEI7RUFDSTtJQUNJLFdBQVUsRUFBQTtFQUVkO0lBQ0ksV0FBVSxFQUFBLEVBQUE7RUFJbEI7RUFDSTtJQUNJLFdBQVUsRUFBQTtFQUVkO0lBQ0ksV0FBVSxFQUFBLEVBQUE7RUFMbEI7RUFDSTtJQUNJLFdBQVUsRUFBQTtFQUVkO0lBQ0ksV0FBVSxFQUFBLEVBQUEiLCJmaWxlIjoic3JjL2FwcC9zaGFyZWQvbWFzay9tYXNrLmNvbXBvbmVudC5zY3NzIiwic291cmNlc0NvbnRlbnQiOlsiLndyYXBwZXItLWZ1bGwtLW1hc2sge1xyXG4gICAgcG9zaXRpb246IGZpeGVkO1xyXG4gICAgdG9wOiAwO1xyXG4gICAgbGVmdDogMDtcclxuICAgIHdpZHRoOiAxMDAlO1xyXG4gICAgaGVpZ2h0OiAxMDAlO1xyXG4gICAgei1pbmRleDogMTAwMDA7XHJcbiAgICBiYWNrZ3JvdW5kLWNvbG9yOiByZ2JhKDAsIDAsIDAsIDAuNjYpO1xyXG4gICAgYW5pbWF0aW9uOiBmYWRlSW4gLjM1cyBlYXNlO1xyXG5cclxuICAgICYuaGlkZSB7XHJcbiAgICAgICAgYW5pbWF0aW9uOiBmYWRlT3V0IC4zNXMgZWFzZTtcclxuICAgIH1cclxufVxyXG5cclxuQGtleWZyYW1lcyBmYWRlSW4ge1xyXG4gICAgMCUge1xyXG4gICAgICAgIG9wYWNpdHk6IDA7XHJcbiAgICB9XHJcbiAgICAxMDAlIHtcclxuICAgICAgICBvcGFjaXR5OiAxO1xyXG4gICAgfVxyXG59XHJcblxyXG5Aa2V5ZnJhbWVzIGZhZGVPdXQge1xyXG4gICAgMCUge1xyXG4gICAgICAgIG9wYWNpdHk6IDE7XHJcbiAgICB9XHJcbiAgICAxMDAlIHtcclxuICAgICAgICBvcGFjaXR5OiAwO1xyXG4gICAgfVxyXG59XHJcbiJdfQ== */"

/***/ }),

/***/ "./src/app/shared/mask/mask.component.ts":
/*!***********************************************!*\
  !*** ./src/app/shared/mask/mask.component.ts ***!
  \***********************************************/
/*! exports provided: MaskComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "MaskComponent", function() { return MaskComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_services_global_operator_service__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/services/global-operator.service */ "./src/app/services/global-operator.service.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
/* harmony import */ var src_app_workspace_unit_modal_unit_modal_component__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! src/app/workspace/unit-modal/unit-modal.component */ "./src/app/workspace/unit-modal/unit-modal.component.ts");
/* harmony import */ var src_app_core_setting_panel_setting_panel_component__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! src/app/core/setting-panel/setting-panel.component */ "./src/app/core/setting-panel/setting-panel.component.ts");
/* harmony import */ var src_app_core_resource_manager_resource_manager_component__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! src/app/core/resource-manager/resource-manager.component */ "./src/app/core/resource-manager/resource-manager.component.ts");
/* harmony import */ var src_app_core_updata_updata__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! src/app/core/updata/updata */ "./src/app/core/updata/updata.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};







var MaskComponent = /** @class */ (function () {
    function MaskComponent(resolver, globalOperatorSrv) {
        this.resolver = resolver;
        this.globalOperatorSrv = globalOperatorSrv;
        this.dynamicComponent = null;
    }
    MaskComponent.prototype.ngOnInit = function () {
    };
    MaskComponent.prototype.createDynamicComponent = function (dynamicComponentType) {
        var contentClass = null;
        switch (dynamicComponentType) {
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["DYNAMIC_COMPONENT_TYPE"].UNIT_MODAL:
                contentClass = src_app_workspace_unit_modal_unit_modal_component__WEBPACK_IMPORTED_MODULE_3__["UnitModalComponent"];
                break;
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["DYNAMIC_COMPONENT_TYPE"].SETTING_PANEL:
                contentClass = src_app_core_setting_panel_setting_panel_component__WEBPACK_IMPORTED_MODULE_4__["SettingPanelComponent"];
                break;
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["DYNAMIC_COMPONENT_TYPE"].RESOURCE_MANAGER:
                contentClass = src_app_core_resource_manager_resource_manager_component__WEBPACK_IMPORTED_MODULE_5__["ResourceManagerComponent"];
                break;
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["DYNAMIC_COMPONENT_TYPE"].UPDATA_PANEL:
                contentClass = src_app_core_updata_updata__WEBPACK_IMPORTED_MODULE_6__["UpdataComponent"];
                break;
            default:
                break;
        }
        if (contentClass === null)
            return;
        var factory = this.resolver.resolveComponentFactory(contentClass);
        this.dynamicComponent = this.container.createComponent(factory);
        document.getElementsByClassName('app')[0].classList.add('blur');
    };
    MaskComponent.prototype.removeMask = function (callback) {
        var _this = this;
        document.getElementsByClassName('app')[0].classList.remove('blur');
        this.wrapperFullMask.nativeElement.classList.add('hide');
        var timer = setTimeout(function () {
            _this.globalOperatorSrv.maskModal.destroy();
            clearTimeout(timer);
        }, 100);
        if (callback != undefined) {
            setTimeout(function () {
                callback();
            }, 200);
        }
    };
    MaskComponent.prototype.destroy = function () {
    };
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ViewChild"])('wrapperFullMask'),
        __metadata("design:type", _angular_core__WEBPACK_IMPORTED_MODULE_0__["ElementRef"])
    ], MaskComponent.prototype, "wrapperFullMask", void 0);
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ViewChild"])('container', { read: _angular_core__WEBPACK_IMPORTED_MODULE_0__["ViewContainerRef"] }),
        __metadata("design:type", _angular_core__WEBPACK_IMPORTED_MODULE_0__["ViewContainerRef"])
    ], MaskComponent.prototype, "container", void 0);
    MaskComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-mask',
            template: __webpack_require__(/*! ./mask.component.html */ "./src/app/shared/mask/mask.component.html"),
            styles: [__webpack_require__(/*! ./mask.component.scss */ "./src/app/shared/mask/mask.component.scss")]
        }),
        __metadata("design:paramtypes", [_angular_core__WEBPACK_IMPORTED_MODULE_0__["ComponentFactoryResolver"], src_app_services_global_operator_service__WEBPACK_IMPORTED_MODULE_1__["GlobalOperatorService"]])
    ], MaskComponent);
    return MaskComponent;
}());



/***/ }),

/***/ "./src/app/shared/message-box/message-box.component.html":
/*!***************************************************************!*\
  !*** ./src/app/shared/message-box/message-box.component.html ***!
  \***************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"wrapper--message-box\" *ngIf=\"message !== ''\">\r\n  <p \r\n    [class.loading]=\"type === 'loading'\"\r\n    [class.success]=\"type === 'success'\"\r\n    [class.error]=\"type === 'error'\"\r\n    [class.warning]=\"type === 'warning'\"\r\n  >{{ message }}</p>\r\n</div> "

/***/ }),

/***/ "./src/app/shared/message-box/message-box.component.scss":
/*!***************************************************************!*\
  !*** ./src/app/shared/message-box/message-box.component.scss ***!
  \***************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper--message-box {\n  position: fixed;\n  top: 48px;\n  left: 0;\n  right: 0;\n  width: 100%;\n  z-index: 9999998;\n  transition: all .025s ease; }\n  .wrapper--message-box p {\n    padding: 10px 0;\n    text-align: center;\n    font-size: 18px;\n    color: #FFFFFF;\n    font-family: Arial; }\n  .wrapper--message-box p.warning {\n      background-color: #F6B352; }\n  .wrapper--message-box p.success {\n      background-color: #67D5B5; }\n  .wrapper--message-box p.error {\n      background-color: #ff4e50; }\n  .wrapper--message-box p.loading {\n      background-color: #008c9e; }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvc2hhcmVkL21lc3NhZ2UtYm94L1o6XFx3b3Jrc3BhY2VcXG15X3pyZW5kZXJcXGZsb3cvc3JjXFxhcHBcXHNoYXJlZFxcbWVzc2FnZS1ib3hcXG1lc3NhZ2UtYm94LmNvbXBvbmVudC5zY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUFBO0VBQ0ksZ0JBQWU7RUFDZixVQUFTO0VBQ1QsUUFBTztFQUNQLFNBQVE7RUFDUixZQUFXO0VBQ1gsaUJBQWdCO0VBQ2hCLDJCQUEwQixFQXlCN0I7RUFoQ0Q7SUFVUSxnQkFBZTtJQUNmLG1CQUFrQjtJQUNsQixnQkFBZTtJQUNmLGVBQWM7SUFDZCxtQkFBa0IsRUFpQnJCO0VBL0JMO01BaUJZLDBCQUF5QixFQUM1QjtFQWxCVDtNQXFCWSwwQkFBeUIsRUFDNUI7RUF0QlQ7TUF5QlksMEJBQXlCLEVBQzVCO0VBMUJUO01BNkJZLDBCQUF5QixFQUM1QiIsImZpbGUiOiJzcmMvYXBwL3NoYXJlZC9tZXNzYWdlLWJveC9tZXNzYWdlLWJveC5jb21wb25lbnQuc2NzcyIsInNvdXJjZXNDb250ZW50IjpbIi53cmFwcGVyLS1tZXNzYWdlLWJveCB7XHJcbiAgICBwb3NpdGlvbjogZml4ZWQ7XHJcbiAgICB0b3A6IDQ4cHg7XHJcbiAgICBsZWZ0OiAwO1xyXG4gICAgcmlnaHQ6IDA7XHJcbiAgICB3aWR0aDogMTAwJTtcclxuICAgIHotaW5kZXg6IDk5OTk5OTg7XHJcbiAgICB0cmFuc2l0aW9uOiBhbGwgLjAyNXMgZWFzZTtcclxuXHJcbiAgICBwIHtcclxuICAgICAgICBwYWRkaW5nOiAxMHB4IDA7XHJcbiAgICAgICAgdGV4dC1hbGlnbjogY2VudGVyO1xyXG4gICAgICAgIGZvbnQtc2l6ZTogMThweDtcclxuICAgICAgICBjb2xvcjogI0ZGRkZGRjtcclxuICAgICAgICBmb250LWZhbWlseTogQXJpYWw7XHJcblxyXG4gICAgICAgICYud2FybmluZyB7XHJcbiAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6ICNGNkIzNTI7XHJcbiAgICAgICAgfVxyXG5cclxuICAgICAgICAmLnN1Y2Nlc3Mge1xyXG4gICAgICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiAjNjdENUI1O1xyXG4gICAgICAgIH1cclxuXHJcbiAgICAgICAgJi5lcnJvciB7XHJcbiAgICAgICAgICAgIGJhY2tncm91bmQtY29sb3I6ICNmZjRlNTA7XHJcbiAgICAgICAgfVxyXG5cclxuICAgICAgICAmLmxvYWRpbmcge1xyXG4gICAgICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiAjMDA4YzllO1xyXG4gICAgICAgIH1cclxuICAgIH1cclxufSJdfQ== */"

/***/ }),

/***/ "./src/app/shared/message-box/message-box.component.ts":
/*!*************************************************************!*\
  !*** ./src/app/shared/message-box/message-box.component.ts ***!
  \*************************************************************/
/*! exports provided: MessageBoxComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "MessageBoxComponent", function() { return MessageBoxComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};


var MessageBoxComponent = /** @class */ (function () {
    function MessageBoxComponent() {
        this.message = '';
        this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["MESSAGE_TYPE"].SUCCESS;
        this.timer = null;
    }
    MessageBoxComponent.prototype.ngOnInit = function () {
    };
    MessageBoxComponent.prototype.success = function (msg) {
        var _this = this;
        this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["MESSAGE_TYPE"].SUCCESS;
        this.message = msg;
        this.timer = setTimeout(function () {
            _this.message = '';
        }, 3000);
    };
    MessageBoxComponent.prototype.error = function (msg) {
        var _this = this;
        this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["MESSAGE_TYPE"].ERROR;
        this.message = msg;
        this.timer = setTimeout(function () {
            _this.message = '';
        }, 3000);
    };
    MessageBoxComponent.prototype.loading = function (msg) {
        var _this = this;
        this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["MESSAGE_TYPE"].LOADING;
        this.message = msg;
        this.timer = setTimeout(function () {
            _this.message = '';
        }, 3000);
    };
    MessageBoxComponent.prototype.warning = function (msg) {
        var _this = this;
        this.type = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["MESSAGE_TYPE"].WARNING;
        this.message = msg;
        this.timer = setTimeout(function () {
            _this.message = '';
        }, 3000);
    };
    MessageBoxComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-message-box',
            template: __webpack_require__(/*! ./message-box.component.html */ "./src/app/shared/message-box/message-box.component.html"),
            styles: [__webpack_require__(/*! ./message-box.component.scss */ "./src/app/shared/message-box/message-box.component.scss")]
        }),
        __metadata("design:paramtypes", [])
    ], MessageBoxComponent);
    return MessageBoxComponent;
}());



/***/ }),

/***/ "./src/app/shared/shared.module.ts":
/*!*****************************************!*\
  !*** ./src/app/shared/shared.module.ts ***!
  \*****************************************/
/*! exports provided: HttpLoaderFactory, SharedModule */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "HttpLoaderFactory", function() { return HttpLoaderFactory; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "SharedModule", function() { return SharedModule; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_common__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/common */ "./node_modules/@angular/common/fesm5/common.js");
/* harmony import */ var _angular_common_http__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @angular/common/http */ "./node_modules/@angular/common/fesm5/http.js");
/* harmony import */ var _angular_platform_browser_animations__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! @angular/platform-browser/animations */ "./node_modules/@angular/platform-browser/fesm5/animations.js");
/* harmony import */ var _ngx_translate_core__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @ngx-translate/core */ "./node_modules/@ngx-translate/core/fesm5/ngx-translate-core.js");
/* harmony import */ var _ngx_translate_http_loader__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @ngx-translate/http-loader */ "./node_modules/@ngx-translate/http-loader/esm5/ngx-translate-http-loader.js");
/* harmony import */ var _message_box_message_box_component__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./message-box/message-box.component */ "./src/app/shared/message-box/message-box.component.ts");
/* harmony import */ var _loading_loading_component__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ./loading/loading.component */ "./src/app/shared/loading/loading.component.ts");
/* harmony import */ var _mask_mask_component__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! ./mask/mask.component */ "./src/app/shared/mask/mask.component.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};









function HttpLoaderFactory(http) {
    return new _ngx_translate_http_loader__WEBPACK_IMPORTED_MODULE_5__["TranslateHttpLoader"](http);
}
var SharedModule = /** @class */ (function () {
    function SharedModule(translateSrv) {
        translateSrv.setDefaultLang('en');
        translateSrv.use('en');
    }
    SharedModule = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["NgModule"])({
            imports: [
                _angular_common__WEBPACK_IMPORTED_MODULE_1__["CommonModule"],
                _angular_common_http__WEBPACK_IMPORTED_MODULE_2__["HttpClientModule"],
                _angular_platform_browser_animations__WEBPACK_IMPORTED_MODULE_3__["BrowserAnimationsModule"],
                _ngx_translate_core__WEBPACK_IMPORTED_MODULE_4__["TranslateModule"].forRoot({
                    loader: {
                        provide: _ngx_translate_core__WEBPACK_IMPORTED_MODULE_4__["TranslateLoader"],
                        useFactory: HttpLoaderFactory,
                        deps: [_angular_common_http__WEBPACK_IMPORTED_MODULE_2__["HttpClient"]]
                    }
                })
            ],
            declarations: [_message_box_message_box_component__WEBPACK_IMPORTED_MODULE_6__["MessageBoxComponent"], _loading_loading_component__WEBPACK_IMPORTED_MODULE_7__["LoadingComponent"], _mask_mask_component__WEBPACK_IMPORTED_MODULE_8__["MaskComponent"]],
            providers: [],
            exports: [
                _ngx_translate_core__WEBPACK_IMPORTED_MODULE_4__["TranslateModule"],
                _angular_common__WEBPACK_IMPORTED_MODULE_1__["CommonModule"],
                _mask_mask_component__WEBPACK_IMPORTED_MODULE_8__["MaskComponent"],
                _loading_loading_component__WEBPACK_IMPORTED_MODULE_7__["LoadingComponent"]
            ]
        }),
        __metadata("design:paramtypes", [_ngx_translate_core__WEBPACK_IMPORTED_MODULE_4__["TranslateService"]])
    ], SharedModule);
    return SharedModule;
}());



/***/ }),

/***/ "./src/app/utils/common-data.ts":
/*!**************************************!*\
  !*** ./src/app/utils/common-data.ts ***!
  \**************************************/
/*! exports provided: TYPE_ALIAS, COMPONENT_ALIAS, FONT_ALIAS, PORT, UNIT_TYPE, MODE, DYNAMIC_COMPONENT_TYPE, LANG, CONNECT_STATUS, LOCALSTORAGE_KEY, MESSAGE_TYPE, EXAMPLES */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "TYPE_ALIAS", function() { return TYPE_ALIAS; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "COMPONENT_ALIAS", function() { return COMPONENT_ALIAS; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "FONT_ALIAS", function() { return FONT_ALIAS; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "PORT", function() { return PORT; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UNIT_TYPE", function() { return UNIT_TYPE; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "MODE", function() { return MODE; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "DYNAMIC_COMPONENT_TYPE", function() { return DYNAMIC_COMPONENT_TYPE; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "LANG", function() { return LANG; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "CONNECT_STATUS", function() { return CONNECT_STATUS; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "LOCALSTORAGE_KEY", function() { return LOCALSTORAGE_KEY; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "MESSAGE_TYPE", function() { return MESSAGE_TYPE; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "EXAMPLES", function() { return EXAMPLES; });
var TYPE_ALIAS = {
    TITLE: 'title',
    LABEL: 'label',
    RECTANGLE: 'rectangle',
    CIRCLE: 'circle',
    IMAGE: 'image',
    SCREEN: 'screen',
    BUTTON: 'button'
};
var COMPONENT_ALIAS = {
    ID: 'id',
    NAME: 'name',
    COLOR: 'color',
    BORDER_COLOR: 'borderColor',
    BACKGROUND_COLOR: 'backgroundColor',
    TEXT: 'text',
    LAYER: 'layer',
    CREATE_TIME: 'createTime',
    TYPE: 'type',
    X: 'x',
    Y: 'y',
    FONT: 'font',
    WIDTH: 'width',
    HEIGHT: 'height',
    RADIUS: 'radius',
    IMAGE_PATH: 'imagePath',
    IMAGE_WIDTH: 'imageWidth',
    IMAGE_HEIGHT: 'imageHeight',
    VISIBILITY: 'visibility',
    BACKGROUND_IMAGE: 'backgroundImage',
    ROTATION: 'rotation'
};
var FONT_ALIAS = {
    DEFAULT: 'lcd.FONT_Default',
    DEFAULT_SMALL: 'lcd.FONT_DefaultSmall',
    UBUNTU_C: 'lcd.FONT_Ubuntu',
    COMIC: 'lcd.FONT_Comic',
    DEJAVUSANS: 'lcd.FONT_DejaVu24',
    DEJAVUSANS_SMALL: 'lcd.FONT_DejaVu18',
    DEJAVUSANS_18PX: 'lcd.FONT_DejaVu18',
    DEJAVUSANS_24PX: 'lcd.FONT_DejaVu24',
    DEJAVUSANS_40PX: 'lcd.FONT_DejaVu40',
    DEJAVUSANS_56PX: 'lcd.FONT_DejaVu56',
    DEJAVUSANS_72PX: 'lcd.FONT_DejaVu72'
};
var PORT = {
    A: 'A',
    B: 'B',
    C: 'C'
};
var UNIT_TYPE = {
    ENV: 'env',
    ANGLE: 'angle',
    PIR: 'pir',
    NEOPIXEL: 'neopixel',
    JOYSTICK: 'joystick',
    LIGHT: 'light',
    EARTH: 'earth',
    MAKEY: 'makey',
    SERVO: 'servo',
    WEIGH: 'weigh',
    PULSE: 'pulse',
    TRACK: 'track',
    TPNX: '3.96',
    ADC: 'adc',
    BUTTON: 'button',
    COLOR: 'color',
    DAC: 'dac',
    DUALBUTTON: 'dual_button',
    HUB: 'hub',
    IR: 'ir',
    M5CAMEAR: 'm5camera',
    NCIR: 'ncir',
    PROTO: 'proto',
    RELAY: 'relay',
    RGB: 'rgb',
    THERMAL: 'thermal',
    TOF: 'tof',
    EXTIO: 'ext_io',
    FINGER: 'finger',
    RFID: 'rfid',
    LIDARCAR: 'lidarcar',
    CARDKB: 'cardkb'
};
var MODE = {
    BLOCKLY: 'blockly',
    CODE: 'code'
};
var DYNAMIC_COMPONENT_TYPE;
(function (DYNAMIC_COMPONENT_TYPE) {
    DYNAMIC_COMPONENT_TYPE[DYNAMIC_COMPONENT_TYPE["UNIT_MODAL"] = 0] = "UNIT_MODAL";
    DYNAMIC_COMPONENT_TYPE[DYNAMIC_COMPONENT_TYPE["SETTING_PANEL"] = 1] = "SETTING_PANEL";
    DYNAMIC_COMPONENT_TYPE[DYNAMIC_COMPONENT_TYPE["RESOURCE_MANAGER"] = 2] = "RESOURCE_MANAGER";
    DYNAMIC_COMPONENT_TYPE[DYNAMIC_COMPONENT_TYPE["UPDATA_PANEL"] = 3] = "UPDATA_PANEL";
    DYNAMIC_COMPONENT_TYPE[DYNAMIC_COMPONENT_TYPE["ALERT_BLOCKLY"] = 4] = "ALERT_BLOCKLY";
})(DYNAMIC_COMPONENT_TYPE || (DYNAMIC_COMPONENT_TYPE = {}));
;
// 切换语言
var LANG = [
    {
        name: 'English',
        file: 'en'
    },
    {
        name: '简体中文',
        file: 'zh-hans'
    },
    {
        name: 'Русский язык',
        file: 'ru'
    },
    {
        name: 'Español',
        file: 'es'
    },
    {
        name: '日本語',
        file: 'ja'
    },
    {
        name: '한국어',
        file: 'ko'
    },
    {
        name: 'ไทย',
        file: 'th'
    }
];
var CONNECT_STATUS = {
    DISCONNECTED: 'DISCONNECTED',
    CONNECTED: 'CONNECTED',
    CONNECTING: 'CONNECTING'
};
var LOCALSTORAGE_KEY = {
    API_KEY: 'mui_apikey',
    LANGUAGE: 'mui_language'
};
var MESSAGE_TYPE = {
    WARNING: 'warning',
    SUCCESS: 'success',
    ERROR: 'error',
    LOADING: 'loading'
};
// 实例对象,utils
var EXAMPLES = [
    {
        icon: 'WeatherStation.jpg',
        title: 'Weather Station',
        description: 'Display temperature, humidity, atmospheric pressure values, different animations based on humidity values',
        required: [
            {
                unit: 'ENV',
                port: 'A'
            }
        ],
        file: 'WeatherStation.m5f',
        others: []
    },
    {
        icon: 'BreathingRGB.jpg',
        title: 'Breathing RGB',
        description: 'The RGB bar on both sides of the fuselage is like breathing, gradually lighting up and gradually extinguishing, and changing color',
        required: [],
        file: 'BreathingRGB.m5f',
        others: []
    },
    {
        icon: 'Neopixel.jpg',
        title: 'Neopixel',
        description: 'The neopixel flow is lit and extinguished, and the color of the light is randomly changed to achieve the effect of the marquee',
        required: [
            {
                unit: 'Neopixel',
                port: 'A'
            }
        ],
        file: 'Neopixel.m5f',
        others: []
    },
    {
        icon: 'PIR.jpg',
        title: 'PIR',
        description: 'When the human body is detected, the RGB bar is lit and the speaker emits a sound',
        required: [
            {
                unit: 'PIR',
                port: 'B'
            }
        ],
        file: 'PIR.m5f',
        others: []
    },
    {
        icon: 'Earth.png',
        title: 'Earth',
        description: 'Detect soil moisture and display it on the screen',
        required: [
            {
                unit: 'Earth',
                port: 'B'
            }
        ],
        file: 'Earth.m5f',
        others: []
    },
    {
        icon: 'Remote.jpg',
        title: 'Remote',
        description: 'Remote control of RGB bar lighting and extinction, and brightness control via mobile phone or computer',
        required: [],
        file: 'Remote.m5f',
        others: [
            'Scan the screen or the QR code of the UIFlow menu bar to enter the control page'
        ]
    },
    {
        icon: 'Charge.jpg',
        title: 'Battery Animation',
        description: 'Use different size square elements to piece together the shape of the battery, change the color of the square by program, and create an animation of battery charging',
        required: [],
        file: 'Charge.m5f',
        others: []
    },
    {
        icon: 'Joystick.jpg',
        title: 'Joystick',
        description: 'Use the joystick to control the circular movement on the screen, press the rocker to make the circle animate',
        required: [
            {
                unit: 'Joystick',
                port: 'A'
            }
        ],
        file: 'Joystick.m5f',
        others: []
    },
    {
        icon: 'Light.jpg',
        title: 'Light',
        description: 'According to the ambient light intensity, the switch light is controlled to turn on the light at night and turn off the light during the day',
        required: [
            {
                unit: 'Light',
                port: 'B'
            }
        ],
        file: 'Light.m5f',
        others: []
    },
    {
        icon: 'ToF.jpg',
        title: 'ToF',
        description: 'By laser ranging, the distance from the sensor to the object is detected. When the distance is lower than the set value and closer, an alarm of different frequency will be issued according to the distance',
        required: [
            {
                unit: 'ToF',
                port: 'A'
            }
        ],
        file: 'ToF.m5f',
        others: []
    },
    {
        icon: 'RGB.jpg',
        title: 'Traffic light',
        description: 'Controls the three lights on the RGB Unit, changes regularly like a traffic light, and displays a countdown on the screen',
        required: [
            {
                unit: 'RGB',
                port: 'B'
            }
        ],
        file: 'RGB.m5f',
        others: []
    },
    {
        icon: 'servoTest.jpg',
        title: 'Servo tester',
        description: 'Manual Mode: You can set RC servo from 0 to 180 degree.(10 degree per step.)  Center Mode: This mode will lock servo at 90 degree  Sweep Mode: This mode will loop sweeping servo to 0, 90 and 180 degree then sweep back to 90 and 0 degree',
        required: [
            {
                unit: 'Servo',
                port: 'A'
            }
        ],
        file: 'servoTester.m5f',
        others: [],
        author: 'pattiuak'
    },
    {
        icon: 'Neoflash.png',
        title: 'Neoflash',
        description: 'After reboot，breathing led. Then enter the detection mode, once the pir detected any object past in front, one led light up. After button press and the pir detect no object past,turn off all of the led.',
        required: [
            {
                unit: 'Neoflash',
                port: 'B'
            }
        ],
        file: 'Neoflash.m5f',
        others: []
    },
    {
        icon: 'Remote1.jpg',
        title: 'Remote1',
        description: 'The Remote block is featured with network function based on MQTT protocol,you can control your M5 remotely on a web page Just by scan the QRcode generate by your program,call firmware interface through mqtt push on control page to remotely control your M5.',
        required: [
            {
                unit: 'ENV',
                port: 'A'
            }
        ],
        file: 'Remote1.m5f',
        others: []
    },
    {
        icon: 'FlashCard.jpg',
        title: 'Flash Card',
        description: 'After start the device, display the title and the content of the flashcard.In this instance we have ‘M5 Flash Card Real estate Terms Chapter 1 The button A and C ,which are located on the side the device  ,is functional for go through the list of the terms And the button B is used to flip it,just like a flash card u have words on one side and the explanation on the other side.',
        required: [],
        file: 'FlashCard.m5f',
        others: []
    },
    {
        icon: 'module_sim800_01.png',
        title: 'SIM800L',
        description: 'Use the M5 core device to sent AT command to the SIM800L module via UART to realise the GSM/GPRS functions This program will teaches you how to program with UIFlow to receive SMS message',
        required: [],
        file: 'SIM800L.m5f',
        others: []
    }
];


/***/ }),

/***/ "./src/app/utils/common-tool.ts":
/*!**************************************!*\
  !*** ./src/app/utils/common-tool.ts ***!
  \**************************************/
/*! exports provided: genComponentId, rebuildComponentInstance, rebuildUnitInstance, updateOldComponent, updateOldUnit */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "genComponentId", function() { return genComponentId; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "rebuildComponentInstance", function() { return rebuildComponentInstance; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "rebuildUnitInstance", function() { return rebuildUnitInstance; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "updateOldComponent", function() { return updateOldComponent; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "updateOldUnit", function() { return updateOldUnit; });
/* harmony import */ var _domain_component__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ../domain/component */ "./src/app/domain/component/index.ts");
/* harmony import */ var _common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ./common-data */ "./src/app/utils/common-data.ts");
/* harmony import */ var _domain_unit__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ../domain/unit */ "./src/app/domain/unit/index.ts");



/**
 * 生成组件ID
 */
var genComponentId = function () {
    var str = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`!@#$%^&*_+-=';
    var id = '';
    for (var i = 0; i < 16; i++) {
        var random = Math.floor(Math.random() * str.length);
        id += str[random];
    }
    return id;
};
/**
 * 重建组件实例
 * @param data 实例数据
 */
var rebuildComponentInstance = function (data) {
    switch (data.type) {
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].SCREEN:
            return new _domain_component__WEBPACK_IMPORTED_MODULE_0__["ScreenComponent"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].BUTTON:
            return new _domain_component__WEBPACK_IMPORTED_MODULE_0__["ButtonComponent"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].TITLE:
            return new _domain_component__WEBPACK_IMPORTED_MODULE_0__["TitleComponent"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].LABEL:
            return new _domain_component__WEBPACK_IMPORTED_MODULE_0__["LabelComponent"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].RECTANGLE:
            return new _domain_component__WEBPACK_IMPORTED_MODULE_0__["RectangleComponent"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].CIRCLE:
            return new _domain_component__WEBPACK_IMPORTED_MODULE_0__["CircleComponent"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["TYPE_ALIAS"].IMAGE:
            return new _domain_component__WEBPACK_IMPORTED_MODULE_0__["ImageComponent"](data);
    }
};
/**
 * 重建Unit实例
 * @param data Unit实例数据
 */
var rebuildUnitInstance = function (data) {
    switch (data.type) {
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].ENV:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitEnv"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].ANGLE:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitAngle"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].PIR:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitPIR"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].NEOPIXEL:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitNeopixel"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].JOYSTICK:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitJoystick"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].LIGHT:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitLight"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].EARTH:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitEarth"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].MAKEY:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitMakey"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].SERVO:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitServo"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].WEIGH:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitWeigh"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].PULSE:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitPulse"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].TRACK:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitTrack"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].TPNX:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["Unit396"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].ADC:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitADC"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].BUTTON:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitButton"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].COLOR:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitColor"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].DAC:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitDac"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].DUALBUTTON:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitDualButton"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].HUB:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitHub"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].IR:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitIR"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].M5CAMEAR:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitM5Camera"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].NCIR:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitNicr"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].PROTO:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitProto"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].RELAY:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitRelay"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].RGB:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitRGB"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].THERMAL:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitThermal"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].TOF:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitTOF"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].TRACK:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitTrack"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].EXTIO:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitExtio"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].RFID:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitRfid"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].FINGER:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitFinger"](data);
        case _common_data__WEBPACK_IMPORTED_MODULE_1__["UNIT_TYPE"].CARDKB:
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitCardkb"](data);
    }
};
/**
 * 兼容旧版M5F文件 Component部分
 * @param component 旧版组件实例
 */
var updateOldComponent = function (component) {
    switch (component.type) {
        case 'button':
            return new _domain_component__WEBPACK_IMPORTED_MODULE_0__["ButtonComponent"]({
                name: component.name === 'button0' ? 'ButtonA' : component.name === 'button1' ? 'ButtonB' : 'ButtonC',
                buttonIndex: component.name === 'button0' ? _domain_component__WEBPACK_IMPORTED_MODULE_0__["ButtonIndex"].A : component.name === 'button1' ? _domain_component__WEBPACK_IMPORTED_MODULE_0__["ButtonIndex"].B : _domain_component__WEBPACK_IMPORTED_MODULE_0__["ButtonIndex"].C,
                text: component.text,
                visibility: component.visibility
            });
        case 'title':
            return new _domain_component__WEBPACK_IMPORTED_MODULE_0__["TitleComponent"]({
                name: component.name,
                layer: component.layer,
                text: component.text,
                backgroundColor: component.backgroundColor,
                color: component.color
            });
        case 'label':
            return new _domain_component__WEBPACK_IMPORTED_MODULE_0__["LabelComponent"]({
                name: component.name,
                layer: component.layer,
                text: component.text,
                x: component.x,
                y: component.y,
                color: component.color,
                rotation: component.rotation
            });
        case 'rect':
            return new _domain_component__WEBPACK_IMPORTED_MODULE_0__["RectangleComponent"]({
                name: component.name,
                layer: component.layer,
                x: component.x,
                y: component.y,
                width: component.width,
                height: component.height,
                borderColor: component.borderColor,
                backgroundColor: component.backgroundColor
            });
        case 'circle':
            return new _domain_component__WEBPACK_IMPORTED_MODULE_0__["CircleComponent"]({
                name: component.name,
                layer: component.layer,
                x: component.x,
                y: component.y,
                radius: component.radius,
                borderColor: component.borderColor,
                backgroundColor: component.backgroundColor
            });
        case 'image':
            return new _domain_component__WEBPACK_IMPORTED_MODULE_0__["ImageComponent"]({
                name: component.name,
                layer: component.layer,
                x: component.x,
                y: component.y,
                imagePath: 'default.jpg'
            });
    }
};
/**
 * 兼容旧版M5F文件 Unit部分
 * @param data 旧版Unit实例
 */
var updateOldUnit = function (data) {
    switch (data.name) {
        case 'ENV':
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitEnv"]({ name: data.varname, port: data.defaultPort });
        case 'Angle':
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitAngle"]({ name: data.varname, port: data.defaultPort });
        case 'PIR':
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitPIR"]({ name: data.varname, port: data.defaultPort });
        case 'Neopixel':
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitNeopixel"]({ name: data.varname, port: data.defaultPort, count: data.count });
        case 'Joystick':
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitJoystick"]({ name: data.varname, port: data.defaultPort });
        case 'Light':
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitLight"]({ name: data.varname, port: data.defaultPort });
        case 'Earth':
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitEarth"]({ name: data.varname, port: data.defaultPort });
        case 'Makey':
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitMakey"]({ name: data.varname, port: data.defaultPort });
        case 'Servo':
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitServo"]({ name: data.varname, port: data.defaultPort });
        case 'Weigh':
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitWeigh"]({ name: data.varname, port: data.defaultPort });
        case 'Pulse':
            return new _domain_unit__WEBPACK_IMPORTED_MODULE_2__["UnitPulse"]({ name: data.varname, port: data.defaultPort });
    }
};


/***/ }),

/***/ "./src/app/workspace/alert_blockly/alert_blockly.html":
/*!************************************************************!*\
  !*** ./src/app/workspace/alert_blockly/alert_blockly.html ***!
  \************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"panel\" appHighlight [@alertAnim]=\"exampleVisibility ? 'show':'hide'\">\r\n  <div class=\"panel_div\">\r\n    \r\n    <div class=\"alert_p main\">\r\n        <span class=\"hide\" (click)=\"hide_alert()\">×</span>\r\n        <div class=\"div_p\">\r\n          <p>{{Alert_Blockly}}</p>\r\n          <p>{{Alert_Blockly}}</p>\r\n    </div>\r\n    </div>\r\n  </div>\r\n</div>"

/***/ }),

/***/ "./src/app/workspace/alert_blockly/alert_blockly.scss":
/*!************************************************************!*\
  !*** ./src/app/workspace/alert_blockly/alert_blockly.scss ***!
  \************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "@charset \"UTF-8\";\n.panel {\n  position: relative;\n  z-index: 9999999999999999999999;\n  box-shadow: 10px;\n  background-color: var(--bg-color);\n  background-size: 100% 100%; }\n.alert_p {\n  font-size: 18px !important;\n  display: flex;\n  justify-content: center; }\n.panel_div, .alert_p {\n  opacity: 1; }\n.alert_p {\n  font-size: 22px;\n  color: red;\n  padding: 8px;\n  border-radius: 10px; }\n* {\n  margin: 0;\n  padding: 0; }\n.main {\n  max-width: 300px;\n  min-width: 150px;\n  max-height: 300px;\n  min-height: 100px;\n  display: inline-block;\n  color: #ffffff;\n  line-height: 28px;\n  position: relative;\n  padding: 10px;\n  -webkit-border-radius: 5px;\n  -moz-border-radius: 5px;\n  overflow: hidden; }\n/*左三角*/\n.main:before {\n  content: ' ';\n  border-top: 8px solid transparent;\n  border-bottom: 8px solid transparent;\n  border-right: 12px solid var(--bg-color);\n  position: absolute;\n  top: 15px;\n  left: -12px; }\n/*右三角*/\n.main > p {\n  min-width: 100%;\n  max-width: 100%;\n  min-height: 100%;\n  max-height: 100%;\n  color: #ffffff;\n  font-weight: 10; }\n.hide {\n  position: relative;\n  font-size: 20px;\n  right: -95%;\n  top: -14px;\n  cursor: pointer;\n  color: #ffffff; }\n.panel_div {\n  position: relative; }\n.div_p {\n  position: relative;\n  top: -10px;\n  overflow: hidden;\n  max-height: 112px; }\n.div_p > p {\n  padding: 0 6px;\n  max-height: 56px;\n  overflow: hidden;\n  word-break: keep-all;\n  word-break: break-all;\n  word-wrap: break-word;\n  font-size: 14px; }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvd29ya3NwYWNlL2FsZXJ0X2Jsb2NrbHkvYWxlcnRfYmxvY2tseS5zY3NzIiwic3JjL2FwcC93b3Jrc3BhY2UvYWxlcnRfYmxvY2tseS9aOlxcd29ya3NwYWNlXFxteV96cmVuZGVyXFxmbG93L3NyY1xcYXBwXFx3b3Jrc3BhY2VcXGFsZXJ0X2Jsb2NrbHlcXGFsZXJ0X2Jsb2NrbHkuc2NzcyJdLCJuYW1lcyI6W10sIm1hcHBpbmdzIjoiQUFBQSxpQkFBaUI7QUNBakI7RUFDSSxtQkFBa0I7RUFDbEIsZ0NBQStCO0VBQy9CLGlCQUFnQjtFQUdqQixrQ0FBaUM7RUFDcEMsMkJBQTBCLEVBRXpCO0FBQ0Q7RUFDSSwyQkFBMEI7RUFDMUIsY0FBYTtFQUNiLHdCQUF1QixFQUUxQjtBQUNEO0VBQ0ksV0FBVSxFQUNiO0FBRUQ7RUFDSSxnQkFBZTtFQUFDLFdBQVU7RUFDMUIsYUFBWTtFQUNaLG9CQUFtQixFQUN0QjtBQUVEO0VBQ0ksVUFBUztFQUNULFdBQVUsRUFDVjtBQUNEO0VBQ0MsaUJBQWU7RUFDZixpQkFBZ0I7RUFDaEIsa0JBQWlCO0VBQ2pCLGtCQUFpQjtFQUNqQixzQkFBcUI7RUFDckIsZUFBYztFQUNkLGtCQUFpQjtFQUdqQixtQkFBa0I7RUFDbEIsY0FBYTtFQUNiLDJCQUF5QjtFQUN6Qix3QkFBc0I7RUFDdEIsaUJBQWdCLEVBQ2hCO0FBQ0QsT0FBQTtBQUNBO0VBQ0MsYUFBWTtFQUNaLGtDQUFpQztFQUNqQyxxQ0FBb0M7RUFFcEMseUNBQXdDO0VBR3hDLG1CQUFrQjtFQUNsQixVQUFTO0VBQ1QsWUFBVyxFQUNYO0FBQ0QsT0FBQTtBQVVBO0VBQ0gsZ0JBQWU7RUFDZixnQkFBZTtFQUNmLGlCQUFnQjtFQUNoQixpQkFBZ0I7RUFDaEIsZUFBYztFQUNkLGdCQUFlLEVBRVg7QUFFRDtFQUNJLG1CQUFrQjtFQUNsQixnQkFBZTtFQUNmLFlBQVc7RUFDWCxXQUFVO0VBQ1YsZ0JBQWU7RUFDZixlQUNKLEVBQUM7QUFDRDtFQUNILG1CQUFrQixFQUdkO0FBRUQ7RUFDSSxtQkFBa0I7RUFDbEIsV0FBVTtFQUNWLGlCQUFnQjtFQUNoQixrQkFBa0IsRUFDckI7QUFDRDtFQUNJLGVBQWM7RUFDZCxpQkFBZ0I7RUFDaEIsaUJBQWdCO0VBQ2hCLHFCQUFvQjtFQUNwQixzQkFBcUI7RUFDckIsc0JBQXFCO0VBQ3JCLGdCQUFlLEVBQ2xCIiwiZmlsZSI6InNyYy9hcHAvd29ya3NwYWNlL2FsZXJ0X2Jsb2NrbHkvYWxlcnRfYmxvY2tseS5zY3NzIiwic291cmNlc0NvbnRlbnQiOlsiQGNoYXJzZXQgXCJVVEYtOFwiO1xuLnBhbmVsIHtcbiAgcG9zaXRpb246IHJlbGF0aXZlO1xuICB6LWluZGV4OiA5OTk5OTk5OTk5OTk5OTk5OTk5OTk5O1xuICBib3gtc2hhZG93OiAxMHB4O1xuICBiYWNrZ3JvdW5kLWNvbG9yOiB2YXIoLS1iZy1jb2xvcik7XG4gIGJhY2tncm91bmQtc2l6ZTogMTAwJSAxMDAlOyB9XG5cbi5hbGVydF9wIHtcbiAgZm9udC1zaXplOiAxOHB4ICFpbXBvcnRhbnQ7XG4gIGRpc3BsYXk6IGZsZXg7XG4gIGp1c3RpZnktY29udGVudDogY2VudGVyOyB9XG5cbi5wYW5lbF9kaXYsIC5hbGVydF9wIHtcbiAgb3BhY2l0eTogMTsgfVxuXG4uYWxlcnRfcCB7XG4gIGZvbnQtc2l6ZTogMjJweDtcbiAgY29sb3I6IHJlZDtcbiAgcGFkZGluZzogOHB4O1xuICBib3JkZXItcmFkaXVzOiAxMHB4OyB9XG5cbioge1xuICBtYXJnaW46IDA7XG4gIHBhZGRpbmc6IDA7IH1cblxuLm1haW4ge1xuICBtYXgtd2lkdGg6IDMwMHB4O1xuICBtaW4td2lkdGg6IDE1MHB4O1xuICBtYXgtaGVpZ2h0OiAzMDBweDtcbiAgbWluLWhlaWdodDogMTAwcHg7XG4gIGRpc3BsYXk6IGlubGluZS1ibG9jaztcbiAgY29sb3I6ICNmZmZmZmY7XG4gIGxpbmUtaGVpZ2h0OiAyOHB4O1xuICBwb3NpdGlvbjogcmVsYXRpdmU7XG4gIHBhZGRpbmc6IDEwcHg7XG4gIC13ZWJraXQtYm9yZGVyLXJhZGl1czogNXB4O1xuICAtbW96LWJvcmRlci1yYWRpdXM6IDVweDtcbiAgb3ZlcmZsb3c6IGhpZGRlbjsgfVxuXG4vKuW3puS4ieinkiovXG4ubWFpbjpiZWZvcmUge1xuICBjb250ZW50OiAnICc7XG4gIGJvcmRlci10b3A6IDhweCBzb2xpZCB0cmFuc3BhcmVudDtcbiAgYm9yZGVyLWJvdHRvbTogOHB4IHNvbGlkIHRyYW5zcGFyZW50O1xuICBib3JkZXItcmlnaHQ6IDEycHggc29saWQgdmFyKC0tYmctY29sb3IpO1xuICBwb3NpdGlvbjogYWJzb2x1dGU7XG4gIHRvcDogMTVweDtcbiAgbGVmdDogLTEycHg7IH1cblxuLyrlj7PkuInop5IqL1xuLm1haW4gPiBwIHtcbiAgbWluLXdpZHRoOiAxMDAlO1xuICBtYXgtd2lkdGg6IDEwMCU7XG4gIG1pbi1oZWlnaHQ6IDEwMCU7XG4gIG1heC1oZWlnaHQ6IDEwMCU7XG4gIGNvbG9yOiAjZmZmZmZmO1xuICBmb250LXdlaWdodDogMTA7IH1cblxuLmhpZGUge1xuICBwb3NpdGlvbjogcmVsYXRpdmU7XG4gIGZvbnQtc2l6ZTogMjBweDtcbiAgcmlnaHQ6IC05NSU7XG4gIHRvcDogLTE0cHg7XG4gIGN1cnNvcjogcG9pbnRlcjtcbiAgY29sb3I6ICNmZmZmZmY7IH1cblxuLnBhbmVsX2RpdiB7XG4gIHBvc2l0aW9uOiByZWxhdGl2ZTsgfVxuXG4uZGl2X3Age1xuICBwb3NpdGlvbjogcmVsYXRpdmU7XG4gIHRvcDogLTEwcHg7XG4gIG92ZXJmbG93OiBoaWRkZW47XG4gIG1heC1oZWlnaHQ6IDExMnB4OyB9XG5cbi5kaXZfcCA+IHAge1xuICBwYWRkaW5nOiAwIDZweDtcbiAgbWF4LWhlaWdodDogNTZweDtcbiAgb3ZlcmZsb3c6IGhpZGRlbjtcbiAgd29yZC1icmVhazoga2VlcC1hbGw7XG4gIHdvcmQtYnJlYWs6IGJyZWFrLWFsbDtcbiAgd29yZC13cmFwOiBicmVhay13b3JkO1xuICBmb250LXNpemU6IDE0cHg7IH1cbiIsIi5wYW5lbHtcclxuICAgIHBvc2l0aW9uOiByZWxhdGl2ZTtcclxuICAgIHotaW5kZXg6IDk5OTk5OTk5OTk5OTk5OTk5OTk5OTk7XHJcbiAgICBib3gtc2hhZG93OiAxMHB4O1xyXG4vLyAgICBiYWNrZ3JvdW5kLWNvbG9yOicnLFxyXG4gICBcclxuICAgYmFja2dyb3VuZC1jb2xvcjogdmFyKC0tYmctY29sb3IpO1xyXG5iYWNrZ3JvdW5kLXNpemU6IDEwMCUgMTAwJTtcclxuLy8gb3BhY2l0eTogMC41O1xyXG59XHJcbi5hbGVydF9we1xyXG4gICAgZm9udC1zaXplOiAxOHB4ICFpbXBvcnRhbnQ7XHJcbiAgICBkaXNwbGF5OiBmbGV4O1xyXG4gICAganVzdGlmeS1jb250ZW50OiBjZW50ZXI7XHJcbiAgICBcclxufVxyXG4ucGFuZWxfZGl2LC5hbGVydF9we1xyXG4gICAgb3BhY2l0eTogMTtcclxufVxyXG5cclxuLmFsZXJ0X3B7XHJcbiAgICBmb250LXNpemU6IDIycHg7Y29sb3I6IHJlZDtcclxuICAgIHBhZGRpbmc6IDhweDtcclxuICAgIGJvcmRlci1yYWRpdXM6IDEwcHg7XHJcbn1cclxuXHJcbip7XHJcbiAgICBtYXJnaW46IDA7XHJcbiAgICBwYWRkaW5nOiAwO1xyXG4gICB9ICBcclxuICAgLm1haW57XHJcbiAgICBtYXgtd2lkdGg6MzAwcHg7XHJcbiAgICBtaW4td2lkdGg6IDE1MHB4O1xyXG4gICAgbWF4LWhlaWdodDozMDBweCA7XHJcbiAgICBtaW4taGVpZ2h0OiAxMDBweDtcclxuICAgIGRpc3BsYXk6IGlubGluZS1ibG9jaztcclxuICAgIGNvbG9yOiAjZmZmZmZmO1xyXG4gICAgbGluZS1oZWlnaHQ6IDI4cHg7XHJcbiAgICAvLyBiYWNrZ3JvdW5kOiAjRjA5ODFDO1xyXG4gICBcclxuICAgIHBvc2l0aW9uOiByZWxhdGl2ZTtcclxuICAgIHBhZGRpbmc6IDEwcHg7XHJcbiAgICAtd2Via2l0LWJvcmRlci1yYWRpdXM6NXB4O1xyXG4gICAgLW1vei1ib3JkZXItcmFkaXVzOjVweDtcclxuICAgIG92ZXJmbG93OiBoaWRkZW47XHJcbiAgIH1cclxuICAgLyrlt6bkuInop5IqL1xyXG4gICAubWFpbjpiZWZvcmV7XHJcbiAgICBjb250ZW50OiAnICc7XHJcbiAgICBib3JkZXItdG9wOiA4cHggc29saWQgdHJhbnNwYXJlbnQ7XHJcbiAgICBib3JkZXItYm90dG9tOiA4cHggc29saWQgdHJhbnNwYXJlbnQ7XHJcbiAgICAvLyBib3JkZXItcmlnaHQ6IDEycHggc29saWQgI0YwOTgxQztcclxuICAgIGJvcmRlci1yaWdodDogMTJweCBzb2xpZCB2YXIoLS1iZy1jb2xvcik7XHJcblxyXG4gICAgLy8gYmFja2dyb3VuZC1pbWFnZTogJy9zcmMvYXNzZXRzL2ltYWdlcy9hbGVydC5wbmcnO1xyXG4gICAgcG9zaXRpb246IGFic29sdXRlO1xyXG4gICAgdG9wOiAxNXB4O1xyXG4gICAgbGVmdDogLTEycHg7XHJcbiAgIH1cclxuICAgLyrlj7PkuInop5IqL1xyXG4vLyAgICAubWFpbjphZnRlcntcclxuLy8gICAgIGNvbnRlbnQ6ICcgJztcclxuLy8gICAgIGJvcmRlci10b3A6IDhweCBzb2xpZCB0cmFuc3BhcmVudDtcclxuLy8gICAgIGJvcmRlci1ib3R0b206IDhweCBzb2xpZCB0cmFuc3BhcmVudDtcclxuLy8gICAgIGJvcmRlci1sZWZ0OiAxMnB4IHNvbGlkICNGMDk4MUM7XHJcbi8vICAgICBwb3NpdGlvbjogYWJzb2x1dGU7XHJcbi8vICAgICBib3R0b206IDE1cHg7XHJcbi8vICAgICByaWdodDogLTEycHg7XHJcbi8vICAgIH1cclxuICAgLm1haW4+cHtcclxubWluLXdpZHRoOiAxMDAlO1xyXG5tYXgtd2lkdGg6IDEwMCU7XHJcbm1pbi1oZWlnaHQ6IDEwMCU7XHJcbm1heC1oZWlnaHQ6IDEwMCU7XHJcbmNvbG9yOiAjZmZmZmZmO1xyXG5mb250LXdlaWdodDogMTA7XHJcbi8vIGNvbG9yOiByZWQ7XHJcbiAgIH1cclxuXHJcbiAgIC5oaWRle1xyXG4gICAgICAgcG9zaXRpb246IHJlbGF0aXZlO1xyXG4gICAgICAgZm9udC1zaXplOiAyMHB4O1xyXG4gICAgICAgcmlnaHQ6IC05NSU7XHJcbiAgICAgICB0b3A6IC0xNHB4O1xyXG4gICAgICAgY3Vyc29yOiBwb2ludGVyO1xyXG4gICAgICAgY29sb3I6ICNmZmZmZmZcclxuICAgfVxyXG4gICAucGFuZWxfZGl2e1xyXG5wb3NpdGlvbjogcmVsYXRpdmU7XHJcbi8vIGJhY2tncm91bmQtaW1hZ2U6dXJsKCdodHRwczovL2RvY3MubTVzdGFjay5jb20vYXNzZXRzL2ltZy9wcm9kdWN0X3BpY3MvYXBwL2FwcF9mbGlyXzAxLnBuZycpICFpbXBvcnRhbnQ7XHJcbi8vIGJhY2tncm91bmQtc2l6ZTogMTAwJSAxMDAlO1xyXG4gICB9XHJcblxyXG4gICAuZGl2X3B7XHJcbiAgICAgICBwb3NpdGlvbjogcmVsYXRpdmU7XHJcbiAgICAgICB0b3A6IC0xMHB4O1xyXG4gICAgICAgb3ZlcmZsb3c6IGhpZGRlbjtcclxuICAgICAgIG1heC1oZWlnaHQ6IDU2KjJweFxyXG4gICB9XHJcbiAgIC5kaXZfcD5we1xyXG4gICAgICAgcGFkZGluZzogMCA2cHg7XHJcbiAgICAgICBtYXgtaGVpZ2h0OiA1NnB4O1xyXG4gICAgICAgb3ZlcmZsb3c6IGhpZGRlbjtcclxuICAgICAgIHdvcmQtYnJlYWs6IGtlZXAtYWxsO1xyXG4gICAgICAgd29yZC1icmVhazogYnJlYWstYWxsO1xyXG4gICAgICAgd29yZC13cmFwOiBicmVhay13b3JkO1xyXG4gICAgICAgZm9udC1zaXplOiAxNHB4O1xyXG4gICB9Il19 */"

/***/ }),

/***/ "./src/app/workspace/alert_blockly/alert_blockly.ts":
/*!**********************************************************!*\
  !*** ./src/app/workspace/alert_blockly/alert_blockly.ts ***!
  \**********************************************************/
/*! exports provided: Alert_Blockly */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "Alert_Blockly", function() { return Alert_Blockly; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
/* harmony import */ var _animations__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ../../animations */ "./src/app/animations/index.ts");
/* harmony import */ var src_app_services_blockly_editor_service__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! src/app/services/blockly-editor.service */ "./src/app/services/blockly-editor.service.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};




// import { footerService } from 'src/app/services/blockly-editor.service';
var Alert_Blockly = /** @class */ (function () {
    function Alert_Blockly(service, el, renderer2) {
        this.service = service;
        this.el = el;
        this.renderer2 = renderer2;
        this.Alert_Blockly = '122';
        this.exampleVisibility = false;
        this.languageList = src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_1__["LANG"];
    }
    Alert_Blockly.prototype.ngOnInit = function () {
        this.Alert_Blockly = this.service.blockly_alert;
        var _this = this;
        var t;
        var t1;
        // this.service.getAlert().subscribe({
        //   next: (v) => {
        //     // 有变化重新生成
        //        if (v && _this.Alert_Blockly !== v) {
        //       _this.Alert_Blockly = v;
        //       if (this.exampleVisibility) {
        //         this.exampleVisibility = false;
        //         if (t1) {
        //           // clearInterval(t);
        //           clearTimeout(t)   // 清除定时器
        //         }
        //         t1 = setTimeout(() => {
        //           this.exampleVisibility = true;
        //         }, 300);
        //       } else {
        //         this.exampleVisibility = true;
        //       }
        //       if (t) {
        //         // clearInterval(t);
        //         clearTimeout(t)   // 清除定时器
        //       }
        //       t = setTimeout(() => {
        //         this.exampleVisibility = false;
        //       }, 4000);
        //     }
        //     // 没变化,但隐藏的也重新生成
        //     else if (v && _this.Alert_Blockly == v && (this.exampleVisibility == false)) {
        //       // this.exampleVisibility = true;
        //       if (this.exampleVisibility) {
        //         this.exampleVisibility = false;
        //         if (t1) {
        //           // clearInterval(t);
        //           clearTimeout(t1)   // 清除定时器
        //         }
        //         t1 = setTimeout(() => {
        //           this.exampleVisibility = true;
        //         }, 300);
        //       } else {
        //         this.exampleVisibility = true;
        //       }
        //       if (t) {
        //         // clearInterval(t);
        //         clearTimeout(t)   // 清除定时器
        //       }
        //       t = setTimeout(() => {
        //         this.exampleVisibility = false;
        //       }, 4000);
        //     }
        //     else {
        //       // this.exampleVisibility = true;
        //       return false;
        //     }
        //   }
        // })
    };
    Alert_Blockly.prototype.hide_alert = function () {
        // console.log('关闭')
        this.exampleVisibility = false;
        // this.renderer2.setStyle(this.el.nativeElement.parentNode, 'display', 'none');
    };
    Alert_Blockly = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-alert_blockly',
            template: __webpack_require__(/*! ./alert_blockly.html */ "./src/app/workspace/alert_blockly/alert_blockly.html"),
            styles: [__webpack_require__(/*! ./alert_blockly.scss */ "./src/app/workspace/alert_blockly/alert_blockly.scss")],
            animations: [_animations__WEBPACK_IMPORTED_MODULE_2__["alertAnimation"]]
        }),
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Directive"])({
            selector: '[appHighlight]'
        }),
        __metadata("design:paramtypes", [src_app_services_blockly_editor_service__WEBPACK_IMPORTED_MODULE_3__["BlocklyEditorService"],
            _angular_core__WEBPACK_IMPORTED_MODULE_0__["ElementRef"],
            _angular_core__WEBPACK_IMPORTED_MODULE_0__["Renderer2"]])
    ], Alert_Blockly);
    return Alert_Blockly;
}());



/***/ }),

/***/ "./src/app/workspace/blockly-editor/blockly-editor.component.html":
/*!************************************************************************!*\
  !*** ./src/app/workspace/blockly-editor/blockly-editor.component.html ***!
  \************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"wrapper--blockly\" (click)=\"stopPropagation()\" (touchstart)=\"padMethod()\">\r\n  <div id=\"wrapper_blockly_editor\" class=\"wrapper--blockly-editor\" #wrapperBlocklyEditor></div>\r\n  <div id=\"blocklyTrashIcon\"><i class=\"trash icon\" aria-hidden=\"true\"></i></div>\r\n  <xml id=\"wrapper_blockly_toolbox\" style=\"display: none;\" #wrapperBlocklyToolbox>\r\n    <category name=\"%{BKY_EVENT}\" colour=\"%{BKY_BASIC_HUE}\">\r\n      <block type=\"basic_on_loop\"></block>\r\n      <block type=\"button_callback\"></block>\r\n      <block type=\"button_state\"></block>\r\n    </category>\r\n\r\n    <!-- ui -->\r\n    <category colour=\"%{BKY_COMPONENT_HUE}\" name=\"%{BKY_UI}\">\r\n      <category colour=\"%{BKY_COMPONENT_TITLE_HUE}\" name=\"%{BKY_TITLE}\">\r\n        <block type=\"title_set_text\">\r\n          <value name=\"TEXT\">\r\n            <shadow type=\"text\">\r\n              <field name=\"TEXT\">Title</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"title_show\"></block>\r\n        <block type=\"title_hide\"></block>\r\n        <block type=\"title_set_color\"></block>\r\n        <block type=\"title_set_color_rgb\">\r\n          <value name=\"R\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"G\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"B\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n\r\n        <block type=\"title_set_bgcolor\"></block>\r\n        <block type=\"title_set_bgcolor_rgb\">\r\n          <value name=\"R\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"G\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"B\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n      </category>\r\n\r\n      <category colour=\"%{BKY_COMPONENT_LABEL_HUE}\" name=\"%{BKY_LABEL}\">\r\n        <block type=\"label_set_text\">\r\n          <value name=\"TEXT\">\r\n            <shadow type=\"text\">\r\n              <field name=\"TEXT\">Hello M5</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"label_set_position\">\r\n          <value name=\"X\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"Y\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"label_set_position_x\">\r\n          <value name=\"X\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"label_set_position_y\">\r\n          <value name=\"Y\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"label_set_color\"></block>\r\n        <block type=\"label_set_color_rgb\">\r\n          <value name=\"R\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"G\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"B\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"label_set_font\">\r\n        </block>\r\n        <block type=\"label_set_mode\">\r\n        </block>\r\n        <block type=\"label_set_rotate\">\r\n            <value name=\"Y\">\r\n                <shadow type=\"math_number\">\r\n                  <field name=\"NUM\">0</field>\r\n                </shadow>\r\n              </value>\r\n        </block>\r\n      </category>\r\n\r\n      <category colour=\"%{BKY_COMPONENT_RECT_HUE}\" name=\"%{BKY_RECT}\">\r\n        <block type=\"rect_set_size\">\r\n          <value name=\"WIDTH\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">30</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"HEIGHT\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">30</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rect_set_size_width\">\r\n          <value name=\"WIDTH\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">30</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rect_set_size_height\">\r\n          <value name=\"HEIGHT\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">30</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rect_set_position\">\r\n          <value name=\"X\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"Y\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rect_set_position_x\">\r\n          <value name=\"X\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rect_set_position_y\">\r\n          <value name=\"Y\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rect_set_bgcolor\"></block>\r\n        <block type=\"rect_set_bgcolor_rgb\">\r\n          <value name=\"R\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"G\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"B\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rect_set_bordercolor\"></block>\r\n        <block type=\"rect_set_bordercolor_rgb\">\r\n          <value name=\"R\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"G\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"B\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rect_set_mode\">\r\n        </block>\r\n      </category>\r\n\r\n      <category colour=\"%{BKY_COMPONENT_CIRCLE_HUE}\" name=\"%{BKY_CIRCLE}\">\r\n        <block type=\"circle_set_size\">\r\n          <value name=\"RADIUS\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">20</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"circle_set_position\">\r\n          <value name=\"X\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"Y\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"circle_set_position_x\">\r\n          <value name=\"X\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"circle_set_position_y\">\r\n          <value name=\"Y\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"circle_set_bgcolor\"></block>\r\n        <block type=\"circle_set_bgcolor_rgb\">\r\n          <value name=\"R\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"G\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"B\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"circle_set_bordercolor\"></block>\r\n        <block type=\"circle_set_bordercolor_rgb\">\r\n          <value name=\"R\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"G\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"B\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"circle_set_mode\">\r\n        </block>\r\n      </category>\r\n\r\n      <category colour=\"%{BKY_COMPONENT_IMAGE_HUE}\" name=\"%{BKY_IMAGE}\">\r\n        <block type=\"image_show\"></block>\r\n        <block type=\"image_hide\"></block>\r\n        <block type=\"image_set_position\">\r\n          <value name=\"X\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"Y\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"image_set_position_x\">\r\n          <value name=\"X\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"image_set_position_y\">\r\n          <value name=\"Y\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"image_set_image\"></block>\r\n        <!-- <block type=\"image_set_mode\"> -->\r\n        <!-- </block> -->\r\n      </category>\r\n    </category>\r\n    <!-- HARDWARES -->\r\n    <category colour=\"%{BKY_PINS_HUE}\" name=\"%{BKY_HARDWARES}\">\r\n\r\n      <!-- Speaker -->\r\n      <category colour=\"%{BKY_SPEAKER_HUE}\" name=\"%{BKY_SPEAKER}\">\r\n        <block type=\"speaker_tone\">\r\n          <value name=\"FREQ\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1800</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"TIMEOUT\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">200</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"speaker_vol\">\r\n          <value name=\"VOLUME\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"speaker_sing\"></block>\r\n      </category>\r\n      <!--RGB  -->\r\n      <category colour=\"%{BKY_RGB_HUE}\" name=\"%{BKY_RGB}\">\r\n        <block type=\"rgb_set_all\"></block>\r\n        <block type=\"rgb_set_all_rgb\">\r\n          <value name=\"R\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"G\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"B\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rgb_set_dir\"></block>\r\n        <block type=\"rgb_set_dir_rgb\">\r\n          <value name=\"R\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"G\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"B\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rgb_set\">\r\n          <value name=\"INDEX\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rgb_set_rgb\">\r\n          <value name=\"INDEX\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"R\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"G\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"B\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rgb_set_brightness\">\r\n          <value name=\"BRIGHTNESS\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">10</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n      </category>\r\n      <!-- imu -->\r\n      <category colour=\"%{BKY_TIMER_HUE}\" name=\"%{BKY_IMU}\">\r\n        <block type=\"IMU_GET_X\"></block>\r\n        <block type=\"IMU_GET_Y\"></block>\r\n        <block type=\"IMU_GET_Z\"></block>\r\n        <block type=\"IMU_GET_ACC_X\"></block>\r\n        <block type=\"IMU_GET_ACC_Y\"></block>\r\n        <block type=\"IMU_GET_ACC_Z\"></block>\r\n        <block type=\"IMU_IS_LEVEL\"></block>\r\n        <block type=\"IMU_IS_STAND\"></block>\r\n        <block type=\"IMU_IS_LEFT_TILT\"></block>\r\n        <block type=\"IMU_IS_RIGHT_TILT\"></block>\r\n        <!-- <block type=\"IMU_IS_OTHER_SIDE\"></block> -->\r\n      </category>\r\n      <!-- imu -tow -->\r\n      <category colour=\"%{BKY_HARDWARE_IMU_TOW}\" name=\"%{BKY_IMU}\">\r\n        <block type=\"IMU_GET_X_tow\"></block>\r\n        <block type=\"IMU_GET_Y_tow\"></block>\r\n        <block type=\"IMU_GET_Z_tow\"></block>\r\n        <block type=\"IMU_GET_ACC_X_tow\"></block>\r\n        <block type=\"IMU_GET_ACC_Y_tow\"></block>\r\n        <block type=\"IMU_GET_ACC_Z_tow\"></block>\r\n        <block type=\"IMU_IS_LEVEL_tow\"></block>\r\n        <block type=\"IMU_IS_STAND_tow\"></block>\r\n        <block type=\"IMU_IS_LEFT_TILT_tow\"></block>\r\n        <block type=\"IMU_IS_RIGHT_TILT_tow\"></block>\r\n        <!-- <block type=\"IMU_IS_OTHER_SIDE\"></block> -->\r\n      </category>\r\n\r\n      <!-- RTC -->\r\n      <category colour=\"%{BKY_HARDWARE_RTC}\" name=\"RTC\">\r\n        <block type=\"rtc_set_client\">\r\n          <h1>wocao</h1>\r\n          <value name=\"YEAR\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\" ></field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"MONTH\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"DAY\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"HOUR\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"MINUTE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"SECOND\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n\r\n        <block type=\"rtc_set_client_year\"></block>\r\n        <block type=\"rtc_set_client_month\"></block>\r\n        <block type=\"rtc_set_client_day\"></block>\r\n        <block type=\"rtc_set_client_hous\"></block>\r\n        <block type=\"rtc_set_client_minute\"></block>\r\n        <block type=\"rtc_set_client_second\"></block>\r\n        <block type=\"rtc_set_client_time\"></block>\r\n      </category>\r\n\r\n      <!-- LED -->\r\n      <category colour=\"%{BKY_HARDWARE_LED}\" name=\"LED\">\r\n        <block type=\"m5ledoff\"></block>\r\n        <block type=\"m5ledon\"></block>\r\n      </category>\r\n\r\n      <!-- AXP192 -->\r\n      <category colour=\"%{BKY_HARDWARE_AXP}\" name=\"AXP\">\r\n        <block type=\"setlcdvol\">\r\n          <value name=\"ANGLEX\">\r\n            \r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n\r\n        <block type=\"ischarge\"></block>\r\n\r\n      </category>\r\n    </category>\r\n\r\n\r\n    <!-- units -->\r\n    <category colour=\"%{BKY_PINS_HUE}\" name=\"%{BKY_UNITS}\">\r\n      <!-- ENV -->\r\n      <category colour=\"%{BKY_DHT_HUE}\" name=\"%{BKY_ENV}\">\r\n        <block type=\"dht12_pressure\"></block>\r\n        <block type=\"dht12_get_temperature\"></block>\r\n        <block type=\"dht12_get_humidity\"></block>\r\n      </category>\r\n      <!-- angle -->\r\n      <category colour=\"%{BKY_PINS_HUE}\" name=\"%{BKY_ANGLE}\">\r\n        <block type=\"angle_read\"></block>\r\n      </category>\r\n      <!-- PIR -->\r\n      <category colour=\"%{BKY_SERVO_HUE}\" name=\"%{BKY_PIR}\">\r\n        <block type=\"pir_read\"></block>\r\n      </category>\r\n      <!-- RGB Multi -->\r\n      <category colour=\"%{BKY_PINS_HUE}\" name=\"%{BKY_NEOPIXEL}\">\r\n        <block type=\"rgb_multi_set_color\">\r\n          <value name=\"INDEX\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rgb_multi_set_color_from\">\r\n          <value name=\"FROM\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"TO\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">5</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rgb_multi_set_color_from_rgb\">\r\n          <value name=\"FROM\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"TO\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">5</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"R\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"G\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"B\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rgb_multi_set_color_all\"></block>\r\n        <block type=\"rgb_multi_set_brightness\">\r\n          <value name=\"BRIGHTNESS\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">100</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <!-- <block type=\"rgb_multi_set_matrix\"></block>\r\n        <block type=\"rgb_multi_set_matrix_rgb\">\r\n          <value name=\"R\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"G\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"B\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block> -->\r\n        <block type=\"rgb_multi_set_hexagon_matrix\"></block>\r\n        <block type=\"rgb_multi_set_hexagon_matrix_rgb\">\r\n          <value name=\"R\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"G\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"B\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n      </category>\r\n      <!-- Joystick -->\r\n      <category colour=\"%{BKY_DHT_HUE}\" name=\"%{BKY_JOYSTICK}\">\r\n        <block type=\"joystick_x\"></block>\r\n        <block type=\"joystick_y\"></block>\r\n        <block type=\"joystick_press\"></block>\r\n      </category>\r\n      <!-- Light -->\r\n      <category colour=\"%{BKY_SPEAKER_HUE}\" name=\"%{BKY_LIGHT}\">\r\n        <block type=\"light_a_read\"></block>\r\n        <block type=\"light_d_read\"></block>\r\n      </category>\r\n      <!-- Earth -->\r\n      <category colour=\"%{BKY_GPIO_HUE}\" name=\"%{BKY_EARTH}\">\r\n        <block type=\"earth_a_read\"></block>\r\n        <block type=\"earth_d_read\"></block>\r\n      </category>\r\n      <!-- Makey -->\r\n      <category colour=\"%{BKY_NXT_MOTOR_HUE}\" name=\"%{BKY_MAKEY}\">\r\n        <block type=\"makey_value\"></block>\r\n        <block type=\"makey_play_piano\"></block>\r\n        <block type=\"makey_all_value\"></block>\r\n      </category>\r\n      <!-- Servo -->\r\n      <category colour=\"%{BKY_SERVO_HUE}\" name=\"%{BKY_SERVO}\">\r\n        <block type=\"servo_unit_write_angle\">\r\n          <value name=\"ANGLE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"servo_unit_write_us\">\r\n          <value name=\"TIME\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">600</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n      </category>\r\n      <!-- Weigh -->\r\n      <category colour=\"%{BKY_DAC_HUE}\" name=\"%{BKY_WEIGHT}\">\r\n        <block type=\"weigh_zero\"></block>\r\n        <block type=\"weigh_get_weight\"></block>\r\n      </category>\r\n      <!-- Pulse -->\r\n      <category colour=\"%{BKY_RGB_HUE}\" name=\"%{BKY_PULSE}\">\r\n        <block type=\"pulse_get_ir\"></block>\r\n        <block type=\"pulse_get_red\"></block>\r\n      </category>\r\n      <!-- Track -->\r\n      <category colour=\"%{BKY_TRACK_HUE}\" name=\"%{BKY_TRACK}\">\r\n        <block type=\"m5track_get_analog\"></block>\r\n        <block type=\"m5track_get_digital\"></block>\r\n        <block type=\"m5track_set_analog\">\r\n          <value name=\"NUM\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">10</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"NUM1\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">10</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n      </category>\r\n      <!-- Button -->\r\n      <category colour=\"%{BKY_TRACK_HUE}\" name=\"%{BKY_BUTTON}\">\r\n        <block type=\"unit_button_callback\"></block>\r\n        <block type=\"unit_button_state\"></block>\r\n      </category>\r\n      <!-- Dual Button -->\r\n      <category colour=\"%{BKY_RGB_HUE}\" name=\"%{BKY_DUAL_BUTTON}\">\r\n        <block type=\"unit_dual_button_callback\"></block>\r\n        <block type=\"unit_dual_button_state\"></block>\r\n      </category>\r\n      <!-- unit Rgb -->\r\n      <category colour=\"%{BKY_PINS_HUE}\" name=\"RGB\">\r\n        <block type=\"rgb_unit_set_color\">\r\n          <value name=\"INDEX\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rgb_unit_set_color_from\">\r\n          <value name=\"FROM\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"TO\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">3</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rgb_unit_set_color_all\"></block>\r\n        <block type=\"rgb_unit_set_brightness\">\r\n          <value name=\"BRIGHTNESS\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">100</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n      </category>\r\n      <!-- RELAY -->\r\n      <category colour=\"%{BKY_SERVO_HUE}\" name=\"%{BKY_RELAY}\">\r\n        <block type=\"set_relay_on\"></block>\r\n        <block type=\"set_relay_off\"></block>\r\n      </category>\r\n      <!-- ADC -->\r\n      <category colour=\"%{BKY_PINS_HUE}\" name=\"ADC\">\r\n        <block type=\"unit_adc_state\"></block>\r\n      </category>\r\n      <!-- DAC -->\r\n      <category colour=\"%{BKY_DHT_HUE}\" name=\"DAC\">\r\n        <block type=\"unit_dac_state\">\r\n          <value name=\"FROM\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n      </category>\r\n      <!-- TOF -->\r\n      <category colour=\"%{BKY_SPEAKER_HUE}\" name=\"TOF\">\r\n        <block type=\"unit_tof_state\"></block>\r\n      </category>\r\n      <!-- NCIR -->\r\n      <category colour=\"%{BKY_SPEAKER_HUE}\" name=\"NCIR\">\r\n        <block type=\"unit_ncir_read\"></block>\r\n      </category>\r\n      <!-- IR -->\r\n      <category colour=\"%{BKY_SPEAKER_HUE}\" name=\"IR\">\r\n        <block type=\"unit_ir_state\"></block>\r\n        <block type=\"unit_ir_on\"></block>\r\n        <block type=\"unit_ir_off\"></block>\r\n      </category>\r\n      <!-- NXT_IO -->\r\n      <category colour=\"%{BKY_DHT_HUE}\" name=\"EXTIO\">\r\n        <block type=\"extio_set_port\"></block>\r\n        <block type=\"extio_set_pin\"></block>\r\n        <block type=\"extio_set_digiWritePort\">\r\n          <value name=\"FROM\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"extio_set_digiWrite\"></block>\r\n        <block type=\"extio_set_digiRead\"></block>\r\n        <block type=\"extio_get_digiReadPort\"></block>\r\n      </category>\r\n      <!-- COLOR -->\r\n      <category colour=\"%{BKY_TIMER_HUE}\" name=\"Color\">\r\n        <block type=\"color_getR\"></block>\r\n        <block type=\"color_getG\"></block>\r\n        <block type=\"color_getB\"></block>\r\n      </category>\r\n      <!-- FINGER -->\r\n      <category colour=\"%{BKY_SPEAKER_HUE}\" name=\"Finger\">\r\n        <block type=\"finger_get_state\"></block>\r\n        <block type=\"finger_get_access\"></block>\r\n        <block type=\"finger_get_id\"></block>\r\n        <block type=\"finger_removeAll\"></block>\r\n        <block type=\"finger_remove_user\">\r\n          <value name=\"ID\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"finger_add_user\">\r\n          <value name=\"ID\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"ACCESS\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"finger_read\"></block>\r\n      </category>\r\n      <!-- Rfid -->\r\n      <category colour=\"%{BKY_TIMER_HUE}\" name=\"Rfid\">\r\n        <block type=\"rfid_readStr\">\r\n          <value name=\"VALUE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"write_block\">\r\n          <value name=\"VALUE\">\r\n            <shadow type=\"text\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"VALUE1\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"rfid_cardOn\"></block>\r\n        <block type=\"rfid_uid\"></block>\r\n      </category>\r\n      <!-- LidarCar -->\r\n      <!-- CardKb -->\r\n\r\n      <category colour=\"%{BKY_TIMER_HUE}\" name=\"CardKB\">\r\n        <block type=\"cardkb_getkey\"></block>\r\n        <block type=\"cardkb_getstring\"></block>\r\n      </category>\r\n\r\n    </category>\r\n\r\n\r\n    <!-- MODULES-->\r\n    <category colour=\"%{BKY_MOTOR_HUE}\" name=\"%{BKY_MODULES}\">\r\n\r\n      <!--lidarcar-->\r\n      <category colour=\"%{BKY_SPEAKER_HUE}\" name=\"Lidar Car\">\r\n        <block type=\"lidarcar_setrgb\"></block>\r\n        <block type=\"lidarcar_setOnergb\">\r\n          <value name=\"NUM\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"lidarcar_goahead\">\r\n          <value name=\"NUM\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n\r\n\r\n        <block type=\"lidarcar_setStepMotor\">\r\n          <value name=\"NUM\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"NUM1\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"NUM2\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"NUM3\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n\r\n        <block type=\"lidarcar_setServo\">\r\n          <value name=\"NUM\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"ANGLE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n\r\n        <block type=\"lidarcar_control\">\r\n          <value name=\"NUMX\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"NUMY\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n\r\n        <block type=\"lidarcar_drawMap\"></block>\r\n        <block type=\"lidarcar_getdistance\">\r\n          <value name=\"NUY\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n      </category>\r\n\r\n\r\n      <!--lorawan-->\r\n      <category colour=\"%{BKY_TIMER_HUE}\" name=\"LoRaWAN\">\r\n        <block type=\"lorawan_initrx\"></block>\r\n        <block type=\"lorawan_initp2p\">\r\n          <value name=\"VALUE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"lorawan_txt\">\r\n          <value name=\"VALUE\">\r\n            <shadow type=\"text\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"lorawan_data\"></block>\r\n      </category>\r\n\r\n      <!-- Motor -->\r\n      <category colour=\"%{BKY_MOTOR_HUE}\" name=\"%{BKY_STEP_MOTOR}\">\r\n        <block type=\"motor_instance\"></block>\r\n        <block type=\"motor_move_xyz\">\r\n          <value name=\"X\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"Y\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"Z\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"SPEED\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"motor_g_code\">\r\n          <value name=\"TEXT\">\r\n            <shadow type=\"text\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"motor_set_mode\"></block>\r\n        <block type=\"motor_lock\"></block>\r\n        <block type=\"motor_unlock\"></block>\r\n      </category>\r\n\r\n      <category colour=\"%{BKY_SERVO_HUE}\" name=\"%{BKY_SERVO}\">\r\n        <block type=\"servo_angle\">\r\n          <value name=\"ANGLE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"servo_write\">\r\n          <value name=\"TIME\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">600</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n      </category>\r\n      <category colour=\"260\" name=\"%{BKY_BALA}\">\r\n        <block type=\"m5bala_move\">\r\n          <value name=\"SPEED\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">50</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"m5bala_turn\">\r\n          <value name=\"ANGLE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">45</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"m5bala_rotate\">\r\n          <value name=\"ANGLE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">45</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        \r\n        <block type=\"m5bala_get_angle\"></block>\r\n        <block type=\"m5bala_set_offset\">\r\n          <value name=\"ANGLEX\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"m5bala_loop\"></block>\r\n      </category>\r\n      <category colour=\"%{BKY_NXT_MOTOR_HUE}\" name=\"%{BKY_BALA_MOTOR}\">\r\n        <block type=\"nxt_init\"></block>\r\n        <block type=\"nxt_set_pwm\">\r\n          <value name=\"ANGLE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"nxt_run\">\r\n          <value name=\"DISTANCE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">500</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"SPEED\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">255</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"nxt_run_goto\">\r\n          <value name=\"DISTANCE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">500</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"SPEED\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">255</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"nxt_stop\"></block>\r\n        <block type=\"nxt_read_encoder\"></block>\r\n      </category>\r\n      <category colour=\"%{BKY_LEGO_MOTOR_HUE}\" name=\"%{BKY_LEGO_MOTOR}\">\r\n        <block type=\"lego_register_motor\"></block>\r\n        <block type=\"lego_set_pwm\">\r\n          <value name=\"PWM\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <!-- <block type=\"lego_set_speed\">\r\n          <value name=\"SPEED\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block> -->\r\n        <!-- <block type=\"lego_set_angle\">\r\n          <value name=\"ANGLE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block> -->\r\n        <!-- <block type=\"lego_set_angle_zero\"></block> -->\r\n        <block type=\"lego_stop\"></block>\r\n        <block type=\"lego_clear\"></block>\r\n        <block type=\"lego_read_encoder\"></block>\r\n        <!-- <block type=\"lego_brake\"></block> -->\r\n      </category>\r\n\r\n    </category>\r\n\r\n    <sep gap=\"64\"></sep>\r\n\r\n    <category name=\"%{BKY_VARIABLES}\" colour=\"%{BKY_VARIABLES_HUE}\" custom=\"VARIABLE\"></category>\r\n\r\n    <category colour=\"%{BKY_MATH_HUE}\" name=\"%{BKY_MATH}\">\r\n      <block type=\"math_number\"></block>\r\n      <block type=\"math_arithmetic\"></block>\r\n      <block type=\"math_constant\"></block>\r\n      <block type=\"math_modulo\"></block>\r\n      <block type=\"math_number_property\"></block>\r\n      <block type=\"math_on_list\"></block>\r\n      <block type=\"math_random_float\"></block>\r\n      <block type=\"math_random_int\"></block>\r\n      <block type=\"math_round\"></block>\r\n      <block type=\"math_single\"></block>\r\n      <block type=\"math_trig\"></block>\r\n      <block type=\"convent_int\"></block>\r\n      <block type=\"convent_float\"></block>\r\n    </category>\r\n\r\n    <category colour=\"%{BKY_LOOPS_HUE}\" name=\"%{BKY_LOOPS}\">\r\n      <block type=\"controls_repeat\"></block>\r\n      <block type=\"controls_whileUntil\"></block>\r\n      <block type=\"controls_forEach\"></block>\r\n      <block type=\"controls_for\"></block>\r\n      <block type=\"controls_flow_statements\"></block>\r\n    </category>\r\n\r\n    <category colour=\"%{BKY_LOGIC_HUE}\" name=\"%{BKY_LOGIC}\">\r\n      <block type=\"controls_if\"></block>\r\n      <block type=\"controls_ifelse\"></block>\r\n      <block type=\"logic_boolean\"></block>\r\n      <block type=\"logic_compare\"></block>\r\n      <block type=\"logic_negate\"></block>\r\n      <block type=\"logic_null\"></block>\r\n      <block type=\"logic_operation\"></block>\r\n      <block type=\"logic_ternary\"></block>\r\n    </category>\r\n\r\n    <category colour=\"%{BKY_LCD_HUE}\" name=\"%{BKY_GRAPHIC}\">\r\n      <block type=\"lcd_clear\"></block>\r\n      <block type=\"lcd_fill\">\r\n        <field name=\"COLOR\">#000000</field>\r\n      </block>\r\n      <block type=\"lcd_print\">\r\n        <value name=\"TEXT\">\r\n          <shadow type=\"text\">\r\n            <field name=\"TEXT\"></field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"X\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"Y\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <field name=\"COLOR\">#ffffff</field>\r\n      </block>\r\n      <block type=\"lcd_setFont\"></block>\r\n      <block type=\"lcd_pixel\">\r\n        <value name=\"X\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"Y\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <field name=\"COLOR\">#ffffff</field>\r\n      </block>\r\n      <block type=\"lcd_line\">\r\n        <value name=\"X\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"Y\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"X1\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"Y1\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <field name=\"COLOR\">#ffffff</field>\r\n      </block>\r\n      <block type=\"lcd_rect\">\r\n        <value name=\"X\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"Y\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"WIDTH\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"HEIGHT\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <field name=\"COLOR\">#ffffff</field>\r\n      </block>\r\n      <block type=\"lcd_triangle\">\r\n        <value name=\"X\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"Y\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"X1\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"Y1\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"X2\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"Y2\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <field name=\"COLOR\">#ffffff</field>\r\n      </block>\r\n      <block type=\"lcd_circle\">\r\n        <value name=\"X\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"Y\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"RADIUS\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <field name=\"COLOR\">#ffffff</field>\r\n      </block>\r\n      <block type=\"lcd_ellipse\">\r\n        <value name=\"X\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"Y\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"RX\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"RY\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <field name=\"COLOR\">#ffffff</field>\r\n      </block>\r\n      <block type=\"lcd_arc\">\r\n        <value name=\"X\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"Y\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"RADIUS\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"THICK\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"START\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"END\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <field name=\"COLOR\">#ffffff</field>\r\n      </block>\r\n      <block type=\"lcd_polygon\">\r\n        <value name=\"X\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"Y\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"RADIUS\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"SIDES\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"THICK\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">0</field>\r\n          </shadow>\r\n        </value>\r\n        <field name=\"COLOR\">#ffffff</field>\r\n        <field name=\"ROTATE\">10</field>\r\n      </block>\r\n    </category>\r\n\r\n    <category colour=\"%{BKY_EMOJI_HUE}\" name=\"%{BKY_EMOJI}\">\r\n      <block type=\"emoji_show\"></block>\r\n      <block type=\"emoji_set_single\"></block>\r\n      <block type=\"emoji_change\"></block>\r\n    </category>\r\n\r\n    <!-- Timer -->\r\n    <category colour=\"%{BKY_TIMER_HUE}\" name=\"%{BKY_TIMER}\">\r\n      <block type=\"timer_delay\">\r\n        <value name=\"DELAY\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">1</field>\r\n          </shadow>\r\n        </value>\r\n      </block>\r\n    </category>\r\n\r\n    <category colour=\"%{BKY_FUNCTION_HUE}\" name=\"%{BKY_FUNCTIONS}\" custom=\"PROCEDURE\"></category>\r\n\r\n    <category colour=\"%{BKY_TEXTS_HUE}\" name=\"%{BKY_TEXT}\">\r\n      <block type=\"text\"></block>\r\n      <block type=\"text_changeCase\"></block>\r\n      <block type=\"text_charAt\"></block>\r\n      <block type=\"text_count\"></block>\r\n      <block type=\"text_isEmpty\"></block>\r\n      <block type=\"text_length\"></block>\r\n      <block type=\"text_print\"></block>\r\n      <block type=\"text_replace\"></block>\r\n      <block type=\"text_reverse\"></block>\r\n      <block type=\"text_trim\"></block>\r\n      <block type=\"text_prompt\"></block>\r\n      <block type=\"text_prompt_ext\"></block>\r\n      <block type=\"convent_str\"></block>\r\n    </category>\r\n\r\n    <category colour=\"%{BKY_LISTS_HUE}\" name=\"%{BKY_LISTS}\">\r\n      <block type=\"lists_length\"></block>\r\n      <block type=\"lists_isEmpty\"></block>\r\n      <block type=\"lists_indexOf\"></block>\r\n      <block type=\"lists_create_empty\"></block>\r\n      <block type=\"lists_create_with\"></block>\r\n      <block type=\"lists_getIndex\"></block>\r\n      <block type=\"lists_getSublist\"></block>\r\n      <block type=\"lists_repeat\"></block>\r\n      <block type=\"lists_reverse\"></block>\r\n      <block type=\"lists_setIndex\"></block>\r\n      <block type=\"lists_split\"></block>\r\n    </category>\r\n\r\n    <sep gap=\"64\"></sep>\r\n\r\n    <category colour=\"%{BKY_ADVANCED_HUE}\" name=\"%{BKY_ADVANCED}\">\r\n      <!-- PINS -->\r\n      <category colour=\"%{BKY_PINS_HUE}\" name=\"%{BKY_PIN}\">\r\n        <block type=\"pins_analog_read\">\r\n        </block>\r\n        <block type=\"pins_analog_write\">\r\n          <value name=\"PIN\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">26</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"DUTY\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"pins_digital_read\">\r\n          <value name=\"PIN\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"pins_digital_write\">\r\n            <value name=\"PIN\">\r\n                <shadow type=\"math_number\">\r\n                  <field name=\"NUM\">26</field>\r\n                </shadow>\r\n              </value>\r\n              <value name=\"VALUE\">\r\n                <shadow type=\"math_number\">\r\n                  <field name=\"NUM\">0</field>\r\n                </shadow>\r\n              </value>\r\n        </block>\r\n        <block type=\"pins_set_mode\">\r\n          <value name=\"PIN\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">5</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"pins_set_map\">\r\n          <value name=\"MAP\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"FROM_LOW\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"FROM_HIGH\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1023</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"TO_LOW\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"TO_HIGH\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">4</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"pins_analog_toggle\">\r\n            <value name=\"PIN\">\r\n              <shadow type=\"math_number\">\r\n                <field name=\"NUM\">26</field>\r\n              </shadow>\r\n            </value>\r\n          </block>\r\n      </category>\r\n      <category style=\"padding-left: 30px;\" colour=\"%{BKY_GPIO_HUE}\" name=\"%{BKY_GPIO}\">\r\n        <block type=\"gpio_pinout\">\r\n          <value name=\"PIN\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"gpio_pinin\">\r\n          <value name=\"PIN\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"gpio_pinout_value\">\r\n          <value name=\"VALUE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"gpio_pinin_value\"></block>\r\n      </category>\r\n      <category colour=\"%{BKY_PWM_HUE}\" name=\"%{BKY_PWM}\">\r\n        <block type=\"pwm\">\r\n          <value name=\"PIN\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"pwm_freq\">\r\n          <value name=\"VALUE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"pwm_duty\">\r\n          <value name=\"VALUE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n      </category>\r\n      <category colour=\"%{BKY_ADC_HUE}\" name=\"%{BKY_ADC}\">\r\n        <block type=\"adc\">\r\n          <value name=\"PIN\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"adc_read_var\"></block>\r\n        <block type=\"adc_width\"></block>\r\n        <block type=\"adc_read\"></block>\r\n      </category>\r\n      <category colour=\"%{BKY_DAC_HUE}\" name=\"%{BKY_DAC}\">\r\n        <block type=\"dac\">\r\n          <value name=\"PIN\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"dac_write\">\r\n          <value name=\"VALUE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n      </category>\r\n      <category colour=\"%{BKY_UART_HUE}\" name=\"%{BKY_UART}\">\r\n        <block type=\"uart\">\r\n          <value name=\"TX\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">17</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"RX\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">16</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"uart_read\"></block>\r\n        <block type=\"uart_read_characters\">\r\n          <value name=\"NUM\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">10</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"uart_readline\"></block>\r\n        <block type=\"uart_readinto\"></block>\r\n        <block type=\"uart_any\"></block>\r\n        <block type=\"uart_write_number\">\r\n          <value name=\"VALUE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"uart_write_line\">\r\n          <value name=\"VALUE\">\r\n            <shadow type=\"text\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"uart_write\">\r\n          <value name=\"VALUE\">\r\n            <shadow type=\"text\">\r\n              <field name=\"TEXT\"></field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n      </category>\r\n      <category colour=\"%{BKY_IIC_HUE}\" name=\"%{BKY_IIC}\">\r\n        <block type=\"iic_set\"></block>\r\n        <block type=\"iic_scan\"></block>\r\n        <block type=\"iic_addr\">\r\n          <value name=\"ADDR\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"iic_read_addr\">\r\n          <value name=\"ADDR\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"NUM\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"iic_read_addr_from\">\r\n          <value name=\"ADDR\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"REG\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"NUM\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"i2c_read_byte\">\r\n          <value name=\"ADDR\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"i2c_read_addr_from_byte\">\r\n          <value name=\"ADDR\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"REG\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">0</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n      </category>\r\n      <category colour=\"#2b90d9\" name=\"%{BKY_EXECUTE}\">\r\n        <block type=\"execute\"></block>\r\n      </category>\r\n<!-- Network -->\r\n      <category colour=\"%{BKY_PINS_HUE}\" name=\"Network\">\r\n        <block type=\"wifi_connect\"></block>\r\n      </category>\r\n\r\n      <category colour=\"%{BKY_RGB_HUE}\" name=\"MQTT\">\r\n        <block type=\"mqtt_set_client\">\r\n          <value name=\"ID\">\r\n            <shadow type=\"text\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"SERVER\">\r\n            <shadow type=\"text\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"PORT\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">1883</field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"USER\">\r\n            <shadow type=\"text\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"PASSWORD\">\r\n            <shadow type=\"text\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"KEEPALIVE\">\r\n            <shadow type=\"math_number\">\r\n              <field name=\"NUM\">300</field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"mqtt_sub\">\r\n          <value name=\"FROM\">\r\n            <shadow type=\"text\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n        <block type=\"mqtt_start\"></block>\r\n        <block type=\"mqtt_get_topic_data\"></block>\r\n        <block type=\"mqtt_publish\">\r\n          <value name=\"FROM\">\r\n            <shadow type=\"text\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n          <value name=\"MSG\">\r\n            <shadow type=\"text\">\r\n              <field name=\"NUM\"></field>\r\n            </shadow>\r\n          </value>\r\n        </block>\r\n      </category>\r\n    </category>\r\n\r\n    <sep gap=\"64\"></sep>\r\n\r\n    <category colour=\"%{BKY_REMOTE_HUE}\" name=\"%{BKY_REMOTE}\">\r\n      <block type=\"remote_set_qrcode\">\r\n        <value name=\"X\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">72</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"Y\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">32</field>\r\n          </shadow>\r\n        </value>\r\n        <value name=\"SIZE\">\r\n          <shadow type=\"math_number\">\r\n            <field name=\"NUM\">176</field>\r\n          </shadow>\r\n        </value>\r\n      </block>\r\n      <block type=\"remote_add_switch\"></block>\r\n      <block type=\"remote_add_button\"></block>\r\n      <block type=\"remote_add_slider\"></block>\r\n      <block type=\"remote_add_label\"></block>\r\n    </category>\r\n\r\n    <sep gap=\"64\"></sep>\r\n\r\n    <category colour=\"#00A0C8\" name=\"Custom (Beta)\">\r\n      <button text=\"Create *.m5b file\" web-class=\"blockly-btn--style\" callbackKey=\"goToBlockMakerHandler\"></button>\r\n      <button text=\"Open *.m5b file\" web-class=\"blockly-btn--style\" callbackKey=\"addThirdPartyBlockHandler\"></button>\r\n    </category>\r\n\r\n    \r\n\r\n  </xml>\r\n</div>\r\n\r\n<input type=\"file\" id=\"__openM5BBox\" style=\"display:none\" accept=\".m5b\">"

/***/ }),

/***/ "./src/app/workspace/blockly-editor/blockly-editor.component.scss":
/*!************************************************************************!*\
  !*** ./src/app/workspace/blockly-editor/blockly-editor.component.scss ***!
  \************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper--blockly {\n  position: relative;\n  width: 100%;\n  height: 100%;\n  background-color: #303131; }\n\n.wrapper--blockly-editor {\n  width: 100%;\n  height: 100%; }\n\n.collapse, .expand {\n  position: absolute;\n  width: 30px;\n  height: 120px;\n  background-color: white;\n  top: 0;\n  bottom: 0;\n  left: 160px;\n  margin: auto 0;\n  border-top-right-radius: 12px;\n  border-bottom-right-radius: 12px;\n  background-color: #323232;\n  cursor: pointer; }\n\n.collapse.expand, .expand.expand {\n    left: 0; }\n\n.collapse p, .expand p {\n    line-height: 120px;\n    text-align: center;\n    margin: 0;\n    font-size: 24px;\n    font-weight: bolder;\n    color: white; }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvd29ya3NwYWNlL2Jsb2NrbHktZWRpdG9yL1o6XFx3b3Jrc3BhY2VcXG15X3pyZW5kZXJcXGZsb3cvc3JjXFxhcHBcXHdvcmtzcGFjZVxcYmxvY2tseS1lZGl0b3JcXGJsb2NrbHktZWRpdG9yLmNvbXBvbmVudC5zY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUFBO0VBQ0ksbUJBQWtCO0VBQ2xCLFlBQVc7RUFDWCxhQUFZO0VBQ1osMEJBQXlCLEVBQzVCOztBQUVEO0VBQ0ksWUFBVztFQUNYLGFBQVksRUFDZjs7QUFFRDtFQUNJLG1CQUFrQjtFQUNsQixZQUFXO0VBQ1gsY0FBYTtFQUNiLHdCQUF1QjtFQUN2QixPQUFNO0VBQ04sVUFBUztFQUNULFlBQVc7RUFDWCxlQUFjO0VBQ2QsOEJBQTZCO0VBQzdCLGlDQUFnQztFQUNoQywwQkFBeUI7RUFDekIsZ0JBQWUsRUFhbEI7O0FBekJEO0lBY1EsUUFBTyxFQUNWOztBQWZMO0lBa0JRLG1CQUFrQjtJQUNsQixtQkFBa0I7SUFDbEIsVUFBUztJQUNULGdCQUFlO0lBQ2Ysb0JBQW1CO0lBQ25CLGFBQVksRUFDZiIsImZpbGUiOiJzcmMvYXBwL3dvcmtzcGFjZS9ibG9ja2x5LWVkaXRvci9ibG9ja2x5LWVkaXRvci5jb21wb25lbnQuc2NzcyIsInNvdXJjZXNDb250ZW50IjpbIi53cmFwcGVyLS1ibG9ja2x5IHtcclxuICAgIHBvc2l0aW9uOiByZWxhdGl2ZTtcclxuICAgIHdpZHRoOiAxMDAlO1xyXG4gICAgaGVpZ2h0OiAxMDAlO1xyXG4gICAgYmFja2dyb3VuZC1jb2xvcjogIzMwMzEzMTtcclxufVxyXG5cclxuLndyYXBwZXItLWJsb2NrbHktZWRpdG9yIHtcclxuICAgIHdpZHRoOiAxMDAlO1xyXG4gICAgaGVpZ2h0OiAxMDAlO1xyXG59XHJcblxyXG4uY29sbGFwc2UsIC5leHBhbmQge1xyXG4gICAgcG9zaXRpb246IGFic29sdXRlO1xyXG4gICAgd2lkdGg6IDMwcHg7XHJcbiAgICBoZWlnaHQ6IDEyMHB4O1xyXG4gICAgYmFja2dyb3VuZC1jb2xvcjogd2hpdGU7XHJcbiAgICB0b3A6IDA7XHJcbiAgICBib3R0b206IDA7XHJcbiAgICBsZWZ0OiAxNjBweDtcclxuICAgIG1hcmdpbjogYXV0byAwO1xyXG4gICAgYm9yZGVyLXRvcC1yaWdodC1yYWRpdXM6IDEycHg7XHJcbiAgICBib3JkZXItYm90dG9tLXJpZ2h0LXJhZGl1czogMTJweDtcclxuICAgIGJhY2tncm91bmQtY29sb3I6ICMzMjMyMzI7XHJcbiAgICBjdXJzb3I6IHBvaW50ZXI7XHJcbiAgICAmLmV4cGFuZCB7XHJcbiAgICAgICAgbGVmdDogMDtcclxuICAgIH1cclxuXHJcbiAgICBwIHtcclxuICAgICAgICBsaW5lLWhlaWdodDogMTIwcHg7XHJcbiAgICAgICAgdGV4dC1hbGlnbjogY2VudGVyO1xyXG4gICAgICAgIG1hcmdpbjogMDtcclxuICAgICAgICBmb250LXNpemU6IDI0cHg7XHJcbiAgICAgICAgZm9udC13ZWlnaHQ6IGJvbGRlcjtcclxuICAgICAgICBjb2xvcjogd2hpdGU7XHJcbiAgICB9XHJcbn1cclxuIl19 */"

/***/ }),

/***/ "./src/app/workspace/blockly-editor/blockly-editor.component.ts":
/*!**********************************************************************!*\
  !*** ./src/app/workspace/blockly-editor/blockly-editor.component.ts ***!
  \**********************************************************************/
/*! exports provided: BlocklyEditorComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "BlocklyEditorComponent", function() { return BlocklyEditorComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/services/services.module */ "./src/app/services/services.module.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};



var BlocklyEditorComponent = /** @class */ (function () {
    function BlocklyEditorComponent(blocklyEditorSrv, globalOperator, storeSrv) {
        this.blocklyEditorSrv = blocklyEditorSrv;
        this.globalOperator = globalOperator;
        this.storeSrv = storeSrv;
    }
    BlocklyEditorComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.blocklyEditorSrv.init({
            wrapperId: this.wrapperBlocklyEditor.nativeElement.id,
            toolboxId: this.wrapperBlocklyToolbox.nativeElement.id,
            language: localStorage.getItem(src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["LOCALSTORAGE_KEY"].LANGUAGE) || 'en'
        });
        this.storeSrv.getType().subscribe(function (data) {
            _this._type = data;
            switch (data) {
                case 'core':
                    try {
                        window['BlocklyEditor'].toolbox_.tree_.children_[4].element_.setAttribute('style', 'display:block');
                        window['BlocklyEditor'].toolbox_.tree_.children_[10].element_.setAttribute('style', 'display:block');
                        window['BlocklyEditor'].toolbox_.tree_.children_[11].element_.setAttribute('style', 'display:block');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[0].element_.setAttribute('style', 'display:block');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[1].element_.setAttribute('style', 'display:block');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[2].element_.setAttribute('style', 'display:block');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[3].element_.setAttribute('style', 'display:none');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[4].element_.setAttribute('style', 'display:none');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[5].element_.setAttribute('style', 'display:none');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[6].element_.setAttribute('style', 'display:none');
                    }
                    catch (error) {
                    }
                    break;
                case 'stick':
                    try {
                        window['BlocklyEditor'].toolbox_.tree_.children_[4].element_.setAttribute('style', 'display:none');
                        window['BlocklyEditor'].toolbox_.tree_.children_[10].element_.setAttribute('style', 'display:none');
                        window['BlocklyEditor'].toolbox_.tree_.children_[11].element_.setAttribute('style', 'display:none');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[0].element_.setAttribute('style', 'display:block');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[1].element_.setAttribute('style', 'display:none');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[2].element_.setAttribute('style', 'display:none');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[3].element_.setAttribute('style', 'display:none');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[4].element_.setAttribute('style', 'display:none');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[5].element_.setAttribute('style', 'display:none');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[6].element_.setAttribute('style', 'display:none');
                    }
                    catch (error) {
                    }
                    break;
                case 'stick-C':
                    try {
                        window['BlocklyEditor'].toolbox_.tree_.children_[4].element_.setAttribute('style', 'display:none');
                        // window['BlocklyEditor'].toolbox_.tree_.children_[4].element_.setAttribute('style', 'display:none');
                        window['BlocklyEditor'].toolbox_.tree_.children_[10].element_.setAttribute('style', 'display:none');
                        window['BlocklyEditor'].toolbox_.tree_.children_[11].element_.setAttribute('style', 'display:none');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[0].element_.setAttribute('style', 'display:none');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[1].element_.setAttribute('style', 'display:none');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[2].element_.setAttribute('style', 'display:none');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[3].element_.setAttribute('style', 'display:block');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[4].element_.setAttribute('style', 'display:block');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[5].element_.setAttribute('style', 'display:block');
                        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[6].element_.setAttribute('style', 'display:block');
                    }
                    catch (error) {
                    }
                    break;
                default:
                    break;
            }
            try {
                window['Blockly'].mainWorkspace.toolbox_.tree_.children_[17].children_[1].element_.setAttribute('style', 'display:none');
                window['Blockly'].mainWorkspace.toolbox_.tree_.children_[17].children_[2].element_.setAttribute('style', 'display:none');
                window['Blockly'].mainWorkspace.toolbox_.tree_.children_[17].children_[3].element_.setAttribute('style', 'display:none');
            }
            catch (error) {
            }
        });
        // this.hiddenAllblock();
        this.storeSrv.getComponentList().subscribe(function (data) {
            if (data.length === 0) {
                return;
            }
            try {
                window['Blockly'].mainWorkspace.toolbox_.tree_.children_[1].children_[0].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[1].children_[1].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[1].children_[2].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[1].children_[3].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[1].children_[4].element_.setAttribute('style', 'display:none');
            }
            catch (error) {
                return;
            }
            data.forEach(function (d) {
                try {
                    if (d.type === 'title') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[1].children_[0].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'label') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[1].children_[1].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'rectangle') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[1].children_[2].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'circle') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[1].children_[3].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'image') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[1].children_[4].element_.setAttribute('style', 'display:block');
                    }
                }
                catch (err) { }
            });
        });
        this.storeSrv.getUnitList().subscribe(function (data) {
            try {
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[0].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[1].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[2].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[3].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[4].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[5].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[6].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[7].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[8].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[9].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[10].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[11].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[12].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[13].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[14].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[15].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[16].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[17].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[18].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[19].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[20].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[21].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[22].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[23].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[24].element_.setAttribute('style', 'display:none');
                window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[25].element_.setAttribute('style', 'display:none');
            }
            catch (error) {
                return;
            }
            data.forEach(function (d) {
                try {
                    if (d.type === 'env') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[0].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'angle') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[1].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'pir') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[2].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'neopixel') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[3].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'joystick') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[4].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'light') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[5].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'earth') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[6].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'makey') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[7].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'servo') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[8].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'weigh') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[9].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'pulse') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[10].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'track') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[11].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'button') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[12].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'dual_button') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[13].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'rgb') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[14].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'relay') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[15].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'adc') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[16].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'dac') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[17].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'tof') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[18].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'ncir') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[19].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'ir') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[20].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'ext_io') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[21].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'color') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[22].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'finger') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[23].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'rfid') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[24].element_.setAttribute('style', 'display:block');
                    }
                    else if (d.type === 'cardkb') {
                        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[25].element_.setAttribute('style', 'display:block');
                    }
                }
                catch (err) { }
            });
        });
    };
    BlocklyEditorComponent.prototype.ngAfterViewInit = function () {
        var _this = this;
        this.storeSrv.setHiddenBlockly().subscribe(function () {
            setTimeout(function () {
                _this.hiddenAllblock();
                _this.setBlockIcon();
                _this.storeSrv.loddingMODE.next(false);
            }, 500);
        });
    };
    BlocklyEditorComponent.prototype.hiddenAllblock = function () {
        window['Blockly'].svgResize(this.blocklyEditorSrv.workspace);
        this.blocklyEditorSrv.workspace.toolbox_.tree_.expandAll();
        this.blocklyEditorSrv.workspace.toolbox_.tree_.collapseAll();
        switch (this._type) {
            case 'core':
                try {
                    window['BlocklyEditor'].toolbox_.tree_.children_[4].element_.setAttribute('style', 'display:block');
                    window['BlocklyEditor'].toolbox_.tree_.children_[10].element_.setAttribute('style', 'display:block');
                    window['BlocklyEditor'].toolbox_.tree_.children_[11].element_.setAttribute('style', 'display:block');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[0].element_.setAttribute('style', 'display:block');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[1].element_.setAttribute('style', 'display:block');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[2].element_.setAttribute('style', 'display:block');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[3].element_.setAttribute('style', 'display:none');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[4].element_.setAttribute('style', 'display:none');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[5].element_.setAttribute('style', 'display:none');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[6].element_.setAttribute('style', 'display:none');
                }
                catch (error) {
                }
                break;
            case 'stick':
                try {
                    window['BlocklyEditor'].toolbox_.tree_.children_[4].element_.setAttribute('style', 'display:none');
                    window['BlocklyEditor'].toolbox_.tree_.children_[10].element_.setAttribute('style', 'display:none');
                    window['BlocklyEditor'].toolbox_.tree_.children_[11].element_.setAttribute('style', 'display:none');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[0].element_.setAttribute('style', 'display:block');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[1].element_.setAttribute('style', 'display:none');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[2].element_.setAttribute('style', 'display:none');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[3].element_.setAttribute('style', 'display:none');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[4].element_.setAttribute('style', 'display:none');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[5].element_.setAttribute('style', 'display:block');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[6].element_.setAttribute('style', 'display:block');
                }
                catch (error) {
                }
                break;
            case 'stick-C':
                try {
                    // window['BlocklyEditor'].toolbox_.tree_.children_[4].element_.setAttribute('style', 'display:none');
                    window['BlocklyEditor'].toolbox_.tree_.children_[4].element_.setAttribute('style', 'display:none');
                    window['BlocklyEditor'].toolbox_.tree_.children_[10].element_.setAttribute('style', 'display:none');
                    window['BlocklyEditor'].toolbox_.tree_.children_[11].element_.setAttribute('style', 'display:none');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[0].element_.setAttribute('style', 'display:none');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[1].element_.setAttribute('style', 'display:none');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[2].element_.setAttribute('style', 'display:none');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[3].element_.setAttribute('style', 'display:block');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[4].element_.setAttribute('style', 'display:block');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[5].element_.setAttribute('style', 'display:block');
                    window['Blockly'].mainWorkspace.toolbox_.tree_.children_[2].children_[6].element_.setAttribute('style', 'display:block');
                }
                catch (error) {
                }
                break;
            default:
                break;
        }
        try {
            window['Blockly'].mainWorkspace.toolbox_.tree_.children_[17].children_[1].element_.setAttribute('style', 'display:none');
            window['Blockly'].mainWorkspace.toolbox_.tree_.children_[17].children_[2].element_.setAttribute('style', 'display:none');
            window['Blockly'].mainWorkspace.toolbox_.tree_.children_[17].children_[3].element_.setAttribute('style', 'display:none');
        }
        catch (error) {
            console.log(error);
        }
        //  UI 
        window['Blockly'].mainWorkspace.toolbox_.tree_.children_[1].children_[0].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[1].children_[1].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[1].children_[2].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[1].children_[3].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[1].children_[4].element_.setAttribute('style', 'display:none');
        // units
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[0].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[1].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[2].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[3].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[4].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[5].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[6].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[7].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[8].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[9].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[10].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[11].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[12].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[13].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[14].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[15].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[16].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[17].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[18].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[19].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[20].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[21].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[22].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[23].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[24].element_.setAttribute('style', 'display:none');
        window['BlocklyEditor'].toolbox_.tree_.children_[3].children_[25].element_.setAttribute('style', 'display:none');
    };
    BlocklyEditorComponent.prototype.setBlockIcon = function () {
        window['BlocklyEditor'].toolbox_.tree_.children_[6].element_.firstElementChild.children[1].classList.add('blocklyTreeIconVar');
        window['BlocklyEditor'].toolbox_.tree_.children_[7].element_.firstElementChild.children[1].classList.add('blocklyTreeIconMath');
        window['BlocklyEditor'].toolbox_.tree_.children_[8].element_.firstElementChild.children[1].classList.add('blocklyTreeIconLoop');
        window['BlocklyEditor'].toolbox_.tree_.children_[9].element_.firstElementChild.children[1].classList.add('blocklyTreeIconLogic');
        window['BlocklyEditor'].toolbox_.tree_.children_[10].element_.firstElementChild.children[1].classList.add('blocklyTreeIconGraphic');
        window['BlocklyEditor'].toolbox_.tree_.children_[11].element_.firstElementChild.children[1].classList.add('blocklyTreeIconEmoji');
        window['BlocklyEditor'].toolbox_.tree_.children_[12].element_.firstElementChild.children[1].classList.add('blocklyTreeIconTimer');
        window['BlocklyEditor'].toolbox_.tree_.children_[13].element_.firstElementChild.children[1].classList.add('blocklyTreeIconFunction');
        window['BlocklyEditor'].toolbox_.tree_.children_[14].element_.firstElementChild.children[1].classList.add('blocklyTreeIconText');
        window['BlocklyEditor'].toolbox_.tree_.children_[15].element_.firstElementChild.children[1].classList.add('blocklyTreeIconLists');
    };
    BlocklyEditorComponent.prototype.stopPropagation = function () {
        this.globalOperator.setSelectedComponent(null);
        this.globalOperator.setSelectedUnit(null);
    };
    BlocklyEditorComponent.prototype.padMethod = function () {
    };
    BlocklyEditorComponent.prototype.mobel = function () {
    };
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ViewChild"])('wrapperBlocklyEditor'),
        __metadata("design:type", _angular_core__WEBPACK_IMPORTED_MODULE_0__["ElementRef"])
    ], BlocklyEditorComponent.prototype, "wrapperBlocklyEditor", void 0);
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ViewChild"])('wrapperBlocklyToolbox'),
        __metadata("design:type", _angular_core__WEBPACK_IMPORTED_MODULE_0__["ElementRef"])
    ], BlocklyEditorComponent.prototype, "wrapperBlocklyToolbox", void 0);
    BlocklyEditorComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-blockly-editor',
            template: __webpack_require__(/*! ./blockly-editor.component.html */ "./src/app/workspace/blockly-editor/blockly-editor.component.html"),
            styles: [__webpack_require__(/*! ./blockly-editor.component.scss */ "./src/app/workspace/blockly-editor/blockly-editor.component.scss")]
        }),
        __metadata("design:paramtypes", [src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__["BlocklyEditorService"], src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__["GlobalOperatorService"], src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__["StoreService"]])
    ], BlocklyEditorComponent);
    return BlocklyEditorComponent;
}());



/***/ }),

/***/ "./src/app/workspace/code-editor/code-editor.component.html":
/*!******************************************************************!*\
  !*** ./src/app/workspace/code-editor/code-editor.component.html ***!
  \******************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div id=\"wrapper_code_editor\" class=\"wrapper--code-editor\" #wrapperCodeEditor></div>"

/***/ }),

/***/ "./src/app/workspace/code-editor/code-editor.component.scss":
/*!******************************************************************!*\
  !*** ./src/app/workspace/code-editor/code-editor.component.scss ***!
  \******************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper--code-editor {\n  width: 100%;\n  height: 100%; }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvd29ya3NwYWNlL2NvZGUtZWRpdG9yL1o6XFx3b3Jrc3BhY2VcXG15X3pyZW5kZXJcXGZsb3cvc3JjXFxhcHBcXHdvcmtzcGFjZVxcY29kZS1lZGl0b3JcXGNvZGUtZWRpdG9yLmNvbXBvbmVudC5zY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUFBO0VBQ0ksWUFBVztFQUNYLGFBQVksRUFDZiIsImZpbGUiOiJzcmMvYXBwL3dvcmtzcGFjZS9jb2RlLWVkaXRvci9jb2RlLWVkaXRvci5jb21wb25lbnQuc2NzcyIsInNvdXJjZXNDb250ZW50IjpbIi53cmFwcGVyLS1jb2RlLWVkaXRvciB7XHJcbiAgICB3aWR0aDogMTAwJTtcclxuICAgIGhlaWdodDogMTAwJTtcclxufSJdfQ== */"

/***/ }),

/***/ "./src/app/workspace/code-editor/code-editor.component.ts":
/*!****************************************************************!*\
  !*** ./src/app/workspace/code-editor/code-editor.component.ts ***!
  \****************************************************************/
/*! exports provided: CodeEditorComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "CodeEditorComponent", function() { return CodeEditorComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/services/services.module */ "./src/app/services/services.module.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};


var CodeEditorComponent = /** @class */ (function () {
    function CodeEditorComponent(codeEditorSrv) {
        this.codeEditorSrv = codeEditorSrv;
    }
    CodeEditorComponent.prototype.ngOnInit = function () {
        this.codeEditorSrv.init({ id: this.wrapperCodeEditor.nativeElement.id });
    };
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ViewChild"])('wrapperCodeEditor'),
        __metadata("design:type", _angular_core__WEBPACK_IMPORTED_MODULE_0__["ElementRef"])
    ], CodeEditorComponent.prototype, "wrapperCodeEditor", void 0);
    CodeEditorComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-code-editor',
            template: __webpack_require__(/*! ./code-editor.component.html */ "./src/app/workspace/code-editor/code-editor.component.html"),
            styles: [__webpack_require__(/*! ./code-editor.component.scss */ "./src/app/workspace/code-editor/code-editor.component.scss")]
        }),
        __metadata("design:paramtypes", [src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__["CodeEditorService"]])
    ], CodeEditorComponent);
    return CodeEditorComponent;
}());



/***/ }),

/***/ "./src/app/workspace/property-item/property-item.component.html":
/*!**********************************************************************!*\
  !*** ./src/app/workspace/property-item/property-item.component.html ***!
  \**********************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<td class=\"property-key\">\r\n  {{ name + ':' }}\r\n</td>\r\n<td class=\"property-value\" [ngSwitch]=\"key\">\r\n\r\n  <input \r\n    *ngSwitchCase=\"'color'\"\r\n    readonly=\"readonly\"\r\n    spellcheck=\"false\"\r\n    [ngModel]=\"value\" [cpOKButton]=\"'Ok'\" [style.background]=\"value\" [cpPosition]=\"'bottom'\" [(colorPicker)]=\"value\"\r\n    [cpPositionOffset]=\"'-20%'\"\r\n    [cpOutputFormat]=\"'hex'\"\r\n    (colorPickerChange)=\"changePropertyEvent($event)\"\r\n  />\r\n\r\n  <input \r\n    *ngSwitchCase=\"'borderColor'\"\r\n    readonly=\"readonly\"\r\n    spellcheck=\"false\"\r\n    [ngModel]=\"value\" [cpOKButton]=\"'Ok'\" [style.background]=\"value\" [cpPosition]=\"'bottom'\" [(colorPicker)]=\"value\"\r\n    [cpPositionOffset]=\"'-20%'\"\r\n    [cpOutputFormat]=\"'hex'\"\r\n    (colorPickerChange)=\"changePropertyEvent($event)\"\r\n  />\r\n\r\n  <input \r\n    *ngSwitchCase=\"'backgroundColor'\"\r\n    readonly=\"readonly\"\r\n    spellcheck=\"false\"\r\n    [ngModel]=\"value\" [cpOKButton]=\"'Ok'\" [style.background]=\"value\" [cpPosition]=\"'bottom'\" [(colorPicker)]=\"value\"\r\n    [cpPositionOffset]=\"'-20%'\"\r\n    [cpOutputFormat]=\"'hex'\"\r\n    (colorPickerChange)=\"changePropertyEvent($event)\"\r\n  />\r\n\r\n  <select *ngSwitchCase=\"'visibility'\" [value]=\"value\" (change)=\"changePropertyEvent($event)\">\r\n    <option value=\"true\">{{ 'True' }}</option>\r\n    <option value=\"false\">{{ 'False' }}</option>\r\n  </select>\r\n\r\n  <select *ngSwitchCase=\"'font'\" [value]=\"value\" (change)=\"changePropertyEvent($event)\">\r\n    <option value=\"lcd.FONT_Default\">Default</option>\r\n    <option value=\"lcd.FONT_DefaultSmall\">Default Small</option>\r\n    <option value=\"lcd.FONT_Ubuntu\">Ubuntu-C</option>\r\n    <option value=\"lcd.FONT_Comic\">Comic</option>\r\n    <option value=\"lcd.FONT_DejaVu18\">DejaVuSans 18</option>\r\n    <option value=\"lcd.FONT_DejaVu24\">DejaVuSans 24</option>\r\n    <option value=\"lcd.FONT_DejaVu40\">DejaVuSans 40</option>\r\n    <option value=\"lcd.FONT_DejaVu56\">DejaVuSans 56</option>\r\n    <option value=\"lcd.FONT_DejaVu72\">DejaVuSans 72</option>\r\n  </select>\r\n\r\n  <select *ngSwitchCase=\"'imagePath'\" [value]=\"value\" (change)=\"changePropertyEvent($event)\" #selectBox>\r\n    <option value=\"default.jpg\">default.jpg</option>\r\n    <option *ngFor=\"let file of (deviceInfo$ | async)?.resources\" [value]=\"file.filename\">{{ file.filename }}</option>\r\n  </select>\r\n  <a class=\"btn--reload-image\" *ngIf=\"key=='imagePath'\" (click)=\"loadImg()\">{{ loadingText }}</a>\r\n\r\n  <input *ngSwitchDefault type=\"text\" spellcheck=\"false\" [value]=\"value\" (input)=\"changePropertyEvent($event)\" [class.patten]=\"ispatten\">\r\n</td>"

/***/ }),

/***/ "./src/app/workspace/property-item/property-item.component.scss":
/*!**********************************************************************!*\
  !*** ./src/app/workspace/property-item/property-item.component.scss ***!
  \**********************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".property-key, .property-value {\n  font-family: Arial;\n  font-size: 14px;\n  text-align: right; }\n\n.property-key {\n  width: 6em;\n  font-size: 18px; }\n\n.property-value input {\n  font-size: 18px;\n  padding-left: 4px; }\n\n.property-value input.patten {\n    border: 1px solid red;\n    outline: 1px solid red; }\n\n.property-value select {\n  outline: none;\n  border: none;\n  background-color: #FFF;\n  font-size: 18px;\n  padding-left: 4px;\n  max-width: 230px; }\n\n.property-value .btn--reload-image {\n  margin: 0 6px;\n  cursor: pointer;\n  color: #007ACC;\n  -webkit-user-select: none;\n     -moz-user-select: none;\n      -ms-user-select: none;\n          user-select: none; }\n\n.property-key_mb {\n  max-width: 6em;\n  overflow: hidden;\n  font-size: 16px; }\n\n.header_mb > .name {\n  font-size: 18px; }\n\n.property-value_mb, .property-value_mb > input {\n  font-size: 16px; }\n\n.table_mb {\n  height: 200px;\n  overflow-y: scroll; }\n\n.property-value_mb > .ng-star-inserted {\n  max-width: 86px;\n  widows: 86px; }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvd29ya3NwYWNlL3Byb3BlcnR5LWl0ZW0vWjpcXHdvcmtzcGFjZVxcbXlfenJlbmRlclxcZmxvdy9zcmNcXGFwcFxcd29ya3NwYWNlXFxwcm9wZXJ0eS1pdGVtXFxwcm9wZXJ0eS1pdGVtLmNvbXBvbmVudC5zY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUFBO0VBQ0ksbUJBQWtCO0VBQ2xCLGdCQUFlO0VBQ2Ysa0JBQWlCLEVBQ3BCOztBQUVEO0VBQ0ksV0FBVTtFQUNWLGdCQUFlLEVBQ2xCOztBQUVEO0VBRVEsZ0JBQWU7RUFDZixrQkFBaUIsRUFLcEI7O0FBUkw7SUFLWSxzQkFBcUI7SUFDckIsdUJBQ0osRUFBQzs7QUFQVDtFQVVRLGNBQWE7RUFDYixhQUFZO0VBQ1osdUJBQXNCO0VBQ3RCLGdCQUFlO0VBQ2Ysa0JBQWlCO0VBQ2pCLGlCQUFnQixFQUNuQjs7QUFoQkw7RUFrQlEsY0FBYTtFQUNiLGdCQUFlO0VBQ2YsZUFBYztFQUNkLDBCQUFpQjtLQUFqQix1QkFBaUI7TUFBakIsc0JBQWlCO1VBQWpCLGtCQUFpQixFQUNwQjs7QUFHTDtFQUNJLGVBQWM7RUFDZCxpQkFBZ0I7RUFDaEIsZ0JBQWUsRUFFbEI7O0FBQ0Q7RUFDSSxnQkFBZSxFQUNsQjs7QUFDRDtFQUNJLGdCQUFlLEVBRWxCOztBQUNEO0VBQ0EsY0FBWTtFQUNaLG1CQUFpQixFQUNoQjs7QUFDRDtFQUNTLGdCQUFlO0VBQ2hCLGFBQVksRUFDbkIiLCJmaWxlIjoic3JjL2FwcC93b3Jrc3BhY2UvcHJvcGVydHktaXRlbS9wcm9wZXJ0eS1pdGVtLmNvbXBvbmVudC5zY3NzIiwic291cmNlc0NvbnRlbnQiOlsiLnByb3BlcnR5LWtleSwgLnByb3BlcnR5LXZhbHVlIHtcclxuICAgIGZvbnQtZmFtaWx5OiBBcmlhbDtcclxuICAgIGZvbnQtc2l6ZTogMTRweDtcclxuICAgIHRleHQtYWxpZ246IHJpZ2h0O1xyXG59XHJcblxyXG4ucHJvcGVydHkta2V5IHtcclxuICAgIHdpZHRoOiA2ZW07XHJcbiAgICBmb250LXNpemU6IDE4cHg7XHJcbn1cclxuXHJcbi5wcm9wZXJ0eS12YWx1ZSB7XHJcbiAgICBpbnB1dCB7XHJcbiAgICAgICAgZm9udC1zaXplOiAxOHB4O1xyXG4gICAgICAgIHBhZGRpbmctbGVmdDogNHB4O1xyXG4gICAgICAgICYucGF0dGVuIHtcclxuICAgICAgICAgICAgYm9yZGVyOiAxcHggc29saWQgcmVkO1xyXG4gICAgICAgICAgICBvdXRsaW5lOiAxcHggc29saWQgcmVkXHJcbiAgICAgICAgfVxyXG4gICAgfVxyXG4gICAgc2VsZWN0IHtcclxuICAgICAgICBvdXRsaW5lOiBub25lO1xyXG4gICAgICAgIGJvcmRlcjogbm9uZTtcclxuICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiAjRkZGO1xyXG4gICAgICAgIGZvbnQtc2l6ZTogMThweDtcclxuICAgICAgICBwYWRkaW5nLWxlZnQ6IDRweDtcclxuICAgICAgICBtYXgtd2lkdGg6IDIzMHB4O1xyXG4gICAgfVxyXG4gICAgLmJ0bi0tcmVsb2FkLWltYWdlIHtcclxuICAgICAgICBtYXJnaW46IDAgNnB4O1xyXG4gICAgICAgIGN1cnNvcjogcG9pbnRlcjtcclxuICAgICAgICBjb2xvcjogIzAwN0FDQztcclxuICAgICAgICB1c2VyLXNlbGVjdDogbm9uZTtcclxuICAgIH1cclxufVxyXG5cclxuLnByb3BlcnR5LWtleV9tYntcclxuICAgIG1heC13aWR0aDogNmVtO1xyXG4gICAgb3ZlcmZsb3c6IGhpZGRlbjtcclxuICAgIGZvbnQtc2l6ZTogMTZweDtcclxuXHJcbn1cclxuLmhlYWRlcl9tYj4ubmFtZXtcclxuICAgIGZvbnQtc2l6ZTogMThweDtcclxufVxyXG4ucHJvcGVydHktdmFsdWVfbWIsLnByb3BlcnR5LXZhbHVlX21iPmlucHV0e1xyXG4gICAgZm9udC1zaXplOiAxNnB4O1xyXG4gICAgXHJcbn1cclxuLnRhYmxlX21ie1xyXG5oZWlnaHQ6MjAwcHg7XHJcbm92ZXJmbG93LXk6c2Nyb2xsO1xyXG59XHJcbi5wcm9wZXJ0eS12YWx1ZV9tYj4ubmctc3Rhci1pbnNlcnRlZHtcclxuICAgICAgICAgbWF4LXdpZHRoOiA4NnB4OyBcclxuICAgICAgICB3aWRvd3M6IDg2cHg7XHJcbn0iXX0= */"

/***/ }),

/***/ "./src/app/workspace/property-item/property-item.component.ts":
/*!********************************************************************!*\
  !*** ./src/app/workspace/property-item/property-item.component.ts ***!
  \********************************************************************/
/*! exports provided: PropertyItemComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "PropertyItemComponent", function() { return PropertyItemComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_services_store_service__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/services/store.service */ "./src/app/services/store.service.ts");
/* harmony import */ var src_app_services_upload_service__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! src/app/services/upload.service */ "./src/app/services/upload.service.ts");
/* harmony import */ var _ngx_translate_core__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! @ngx-translate/core */ "./node_modules/@ngx-translate/core/fesm5/ngx-translate-core.js");
/* harmony import */ var src_app_services_services_module__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! src/app/services/services.module */ "./src/app/services/services.module.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};





// import { ZrenderHelperMbService } from 'src/app/services/global-operator.service';
var PropertyItemComponent = /** @class */ (function () {
    function PropertyItemComponent(storeSrv, uploadSrv, zrenderHelperSrvmb, globalOperatorSrv, translate) {
        this.storeSrv = storeSrv;
        this.uploadSrv = uploadSrv;
        this.zrenderHelperSrvmb = zrenderHelperSrvmb;
        this.globalOperatorSrv = globalOperatorSrv;
        this.translate = translate;
        this.changePropertyEmitter = new _angular_core__WEBPACK_IMPORTED_MODULE_0__["EventEmitter"]();
        this.updateImgEmitter = new _angular_core__WEBPACK_IMPORTED_MODULE_0__["EventEmitter"]();
        this.changeToDefaultImgEmitter = new _angular_core__WEBPACK_IMPORTED_MODULE_0__["EventEmitter"]();
        this.key = 'Unknow';
        this.value = 'Null';
        this.name = "Null";
        this.loadingText = 'Reload';
        this.ispatten = false;
        this.toLoadImg = '';
        this.stick = true;
    }
    PropertyItemComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.deviceInfo$ = this.storeSrv.getDeviceInfo();
        // tslint:disable-next-line: forin
        // 判断是否是移动端,真 则修改样式以解决在移动端弹窗太大的问题
        if (this.globalOperatorSrv.ismb) {
            document.getElementsByClassName('header')[0].classList.add("header_mb");
            document.getElementsByClassName('wrapper--property--panel')[0].getElementsByTagName('table')[0].classList.add("table_mb");
            for (var i = 0; i < document.getElementsByClassName('property-key').length; i++) {
                try {
                    document.getElementsByClassName('property-key')[i].classList.add("property-key_mb");
                    document.getElementsByClassName('property-value')[i].classList.add("property-value_mb");
                }
                catch (error) {
                }
            }
        }
        for (var key in this.propertyItem) {
            this.key = key;
            this.value = this.propertyItem[key];
            this.translate.get(key).subscribe(function (res) { _this.name = res; });
        }
    };
    // input框参数变化
    PropertyItemComponent.prototype.changePropertyEvent = function (ev) {
        // 表单效验
        if (this.key === 'name') {
            var patten = /^\w+$/ig;
            var trues = patten.test(ev.target.value);
            if (trues) {
                this.ispatten = false;
            }
            else {
                this.ispatten = true;
                return;
            }
        }
        else if (this.key === 'x' || this.key === 'y' || this.key === 'width' || this.key === 'height' || this.key === 'layer' || this.key === 'radius' || this.key === 'rotation') {
            var patten = /^[0-9]+$/ig;
            var trues = patten.test(ev.target.value);
            if (trues) {
                this.ispatten = false;
            }
            else {
                this.ispatten = true;
                return;
            }
        }
        if (typeof ev === 'string') {
            return this.changePropertyEmitter.emit({
                key: this.key,
                value: ev,
                obj: null
            });
        }
        this.changePropertyEmitter.emit({
            key: this.key,
            value: ev.target.value,
            obj: ev
        });
        if (this.key === 'imagePath') {
            this.toLoadImg = ev.target.value;
            this.loadImg();
        }
    };
    // reload刷新
    PropertyItemComponent.prototype.loadImg = function () {
        var _this = this;
        if (this.selectBox.nativeElement.value === 'default.jpg') {
            this.changeToDefaultImgEmitter.emit();
            return;
        }
        var deviceInfo = this.storeSrv.deviceInfo.value;
        var imageData = deviceInfo.resources.filter(function (f) { return f.filename === _this.selectBox.nativeElement.value; })[0].base64;
        if (imageData !== '') {
            this.updateImgEmitter.emit(imageData);
            return;
        }
        this.loadingText = 'Loading';
        this.uploadSrv.reloadImg(this.selectBox.nativeElement.value).subscribe(function (res) {
            if (res.code === 0 && res.data !== '' && res.type === 'base64') {
                var base64Data_1 = res.data.replace('/\n/g', '');
                _this.updateImgEmitter.emit("data:image/jpg;base64," + base64Data_1);
                deviceInfo.resources = deviceInfo.resources.map(function (f) {
                    if (f.filename === _this.selectBox.nativeElement.value) {
                        f.base64 = "data:image/jpg;base64," + base64Data_1;
                    }
                    return f;
                });
                _this.storeSrv.setDeviceInfo(deviceInfo);
            }
            _this.loadingText = 'Reload';
        }, function (err) {
            _this.loadingText = 'Reload';
        });
    };
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Input"])('propertyItem'),
        __metadata("design:type", Object)
    ], PropertyItemComponent.prototype, "propertyItem", void 0);
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Output"])('changePropertyEmitter'),
        __metadata("design:type", Object)
    ], PropertyItemComponent.prototype, "changePropertyEmitter", void 0);
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Output"])('updateImgEmitter'),
        __metadata("design:type", Object)
    ], PropertyItemComponent.prototype, "updateImgEmitter", void 0);
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Output"])('changeToDefaultImgEmitter'),
        __metadata("design:type", Object)
    ], PropertyItemComponent.prototype, "changeToDefaultImgEmitter", void 0);
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ViewChild"])('selectBox'),
        __metadata("design:type", _angular_core__WEBPACK_IMPORTED_MODULE_0__["ElementRef"])
    ], PropertyItemComponent.prototype, "selectBox", void 0);
    PropertyItemComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-property-item',
            template: __webpack_require__(/*! ./property-item.component.html */ "./src/app/workspace/property-item/property-item.component.html"),
            styles: [__webpack_require__(/*! ./property-item.component.scss */ "./src/app/workspace/property-item/property-item.component.scss")]
        }),
        __metadata("design:paramtypes", [src_app_services_store_service__WEBPACK_IMPORTED_MODULE_1__["StoreService"], src_app_services_upload_service__WEBPACK_IMPORTED_MODULE_2__["UploadService"], src_app_services_services_module__WEBPACK_IMPORTED_MODULE_4__["ZrenderHelperMbService"], src_app_services_services_module__WEBPACK_IMPORTED_MODULE_4__["GlobalOperatorService"],
            _ngx_translate_core__WEBPACK_IMPORTED_MODULE_3__["TranslateService"]])
    ], PropertyItemComponent);
    return PropertyItemComponent;
}());



/***/ }),

/***/ "./src/app/workspace/property-panel/property-panel.component.html":
/*!************************************************************************!*\
  !*** ./src/app/workspace/property-panel/property-panel.component.html ***!
  \************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"wrapper--property--panel\" [class.show]=\"(selectedComponent$ | async) !== null\" (mousedown)=\"stopPropagation($event)\" #wrapperPropertyPanel>\r\n  <div class=\"header\">\r\n      <p class=\"property name\">{{ (selectedComponent$ | async)?.name }}</p>\r\n      <span class=\"close\" (click)=\"close()\"><svg class=\"icon\" width=\"16px\" height=\"16.00px\" viewBox=\"0 0 1024 1024\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\"><path fill=\"#515151\" d=\"M958.356218 161.6398l-97.56565-97.563052L511.17061 413.691709 161.550453 64.076748 63.989399 161.6398 413.60456 511.260357 63.989399 860.880515l97.561054 97.557656 349.620158-349.606167 349.620158 349.606167 97.56565-97.557656L608.741257 511.260357 958.356218 161.6398z\" /></svg></span>\r\n  </div>\r\n  <table>\r\n    <tr class=\"wrapper-property\" *ngFor=\"let prop of selectedComponentProperty\">\r\n      <app-property-item \r\n        [propertyItem]=\"prop\"\r\n        (changePropertyEmitter)=\"changePropertyHandler($event)\"\r\n        (updateImgEmitter)=\"updateImgHandler($event)\"\r\n        (changeToDefaultImgEmitter)=\"changeToDefaultImgHandler()\"\r\n      ></app-property-item>\r\n    </tr>\r\n  </table>\r\n\r\n</div>"

/***/ }),

/***/ "./src/app/workspace/property-panel/property-panel.component.scss":
/*!************************************************************************!*\
  !*** ./src/app/workspace/property-panel/property-panel.component.scss ***!
  \************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper--property--panel {\n  display: none;\n  position: absolute;\n  top: 0;\n  left: 0;\n  background-color: rgba(255, 255, 255, 0.88);\n  border: 1px solid #666;\n  z-index: 1000001;\n  padding: 8px;\n  border-radius: 2px; }\n  .wrapper--property--panel.show {\n    display: block; }\n  .header {\n  display: flex; }\n  .header .property.name {\n    flex: 1;\n    font-size: 22px;\n    font-family: Arial; }\n  .header .close {\n    padding-left: 20px; }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvd29ya3NwYWNlL3Byb3BlcnR5LXBhbmVsL1o6XFx3b3Jrc3BhY2VcXG15X3pyZW5kZXJcXGZsb3cvc3JjXFxhcHBcXHdvcmtzcGFjZVxccHJvcGVydHktcGFuZWxcXHByb3BlcnR5LXBhbmVsLmNvbXBvbmVudC5zY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUFBO0VBQ0ksY0FBYTtFQUNiLG1CQUFrQjtFQUNsQixPQUFNO0VBQ04sUUFBTztFQUNQLDRDQUEyQztFQUMzQyx1QkFBc0I7RUFDdEIsaUJBQWdCO0VBQ2hCLGFBQVk7RUFDWixtQkFBa0IsRUFLckI7RUFkRDtJQVlRLGVBQWMsRUFDakI7RUFFTDtFQUNJLGNBQWEsRUFTaEI7RUFWRDtJQUdRLFFBQU87SUFDUCxnQkFBZTtJQUNmLG1CQUFrQixFQUNyQjtFQU5MO0lBUVEsbUJBQWtCLEVBQ3JCIiwiZmlsZSI6InNyYy9hcHAvd29ya3NwYWNlL3Byb3BlcnR5LXBhbmVsL3Byb3BlcnR5LXBhbmVsLmNvbXBvbmVudC5zY3NzIiwic291cmNlc0NvbnRlbnQiOlsiLndyYXBwZXItLXByb3BlcnR5LS1wYW5lbCB7XHJcbiAgICBkaXNwbGF5OiBub25lO1xyXG4gICAgcG9zaXRpb246IGFic29sdXRlO1xyXG4gICAgdG9wOiAwO1xyXG4gICAgbGVmdDogMDtcclxuICAgIGJhY2tncm91bmQtY29sb3I6IHJnYmEoMjU1LCAyNTUsIDI1NSwgMC44OCk7XHJcbiAgICBib3JkZXI6IDFweCBzb2xpZCAjNjY2O1xyXG4gICAgei1pbmRleDogMTAwMDAwMTtcclxuICAgIHBhZGRpbmc6IDhweDtcclxuICAgIGJvcmRlci1yYWRpdXM6IDJweDtcclxuXHJcbiAgICAmLnNob3cge1xyXG4gICAgICAgIGRpc3BsYXk6IGJsb2NrO1xyXG4gICAgfVxyXG59XHJcbi5oZWFkZXIge1xyXG4gICAgZGlzcGxheTogZmxleDtcclxuICAgIC5wcm9wZXJ0eS5uYW1lIHtcclxuICAgICAgICBmbGV4OiAxO1xyXG4gICAgICAgIGZvbnQtc2l6ZTogMjJweDtcclxuICAgICAgICBmb250LWZhbWlseTogQXJpYWw7XHJcbiAgICB9XHJcbiAgICAuY2xvc2Uge1xyXG4gICAgICAgIHBhZGRpbmctbGVmdDogMjBweDtcclxuICAgIH1cclxufVxyXG4iXX0= */"

/***/ }),

/***/ "./src/app/workspace/property-panel/property-panel.component.ts":
/*!**********************************************************************!*\
  !*** ./src/app/workspace/property-panel/property-panel.component.ts ***!
  \**********************************************************************/
/*! exports provided: PropertyPanelComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "PropertyPanelComponent", function() { return PropertyPanelComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/services/services.module */ "./src/app/services/services.module.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
/* harmony import */ var src_app_services_zrender_helper_service__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! src/app/services/zrender-helper.service */ "./src/app/services/zrender-helper.service.ts");
/* harmony import */ var src_app_services_store_service__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! src/app/services/store.service */ "./src/app/services/store.service.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};





var PropertyPanelComponent = /** @class */ (function () {
    function PropertyPanelComponent(globalOperatorSrv, zrenderHelpsrv, zrenderHelperSrvmb, rd2, storeSrv) {
        this.globalOperatorSrv = globalOperatorSrv;
        this.zrenderHelpsrv = zrenderHelpsrv;
        this.zrenderHelperSrvmb = zrenderHelperSrvmb;
        this.rd2 = rd2;
        this.storeSrv = storeSrv;
        this.offsetX = 20;
        this.headerHeight = 48;
        this.selectedComponent = null;
        this.selectedComponentProperty = [];
        this.selectedComponent$ = this.globalOperatorSrv.getSelectedComponent();
        if (this.globalOperatorSrv.ismb) {
            this.UIHELP = this.zrenderHelperSrvmb;
        }
        else {
            this.UIHELP = this.zrenderHelpsrv;
        }
    }
    PropertyPanelComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.globalOperatorSrv.getSelectedComponent().subscribe(function (component) {
            if (component === null)
                return;
            _this.selectedComponent = component;
            if (_this.selectedComponent.type === src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["TYPE_ALIAS"].SCREEN || _this.selectedComponent.type === src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["TYPE_ALIAS"].BUTTON) {
                _this.selectedComponentProperty = component.getAllProps();
            }
            else {
                var _type = localStorage.getItem('_type');
                _this.selectedComponentProperty = component.getAllProps().slice(3);
            }
            if (_this.storeSrv.getType().source['_value'] == "stick") {
                for (var i = 0; i < _this.selectedComponentProperty.length; i++) {
                    if ('rotation' in _this.selectedComponentProperty[i]) {
                        _this.selectedComponentProperty.splice(i, 1);
                    }
                }
            }
            var screenOffsetX = _this.UIHELP.screenOffsetX;
            var screenOffsetY = _this.UIHELP.screenOffsetY;
            if (_this.globalOperatorSrv.ismb) {
                _this.wrapperPropertyPanel.nativeElement.style.left = 'calc(50% - 30px)';
                _this.wrapperPropertyPanel.nativeElement.style.top = '90px';
            }
            else {
                switch (component.type) {
                    case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["TYPE_ALIAS"].TITLE:
                        _this.wrapperPropertyPanel.nativeElement.style.left = (component.x + component['width'] + _this.offsetX + screenOffsetX) * _this.UIHELP.scaleRatio + 'px';
                        _this.wrapperPropertyPanel.nativeElement.style.top = (component.y + screenOffsetY + _this.headerHeight) * _this.UIHELP.scaleRatio + 'px';
                        break;
                    case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["TYPE_ALIAS"].LABEL:
                        _this.wrapperPropertyPanel.nativeElement.style.left = (component.x + _this.offsetX + screenOffsetX + component['componentSvg'].getBoundingRect().width) * _this.UIHELP.scaleRatio + 'px';
                        _this.wrapperPropertyPanel.nativeElement.style.top = (component.y + screenOffsetY + _this.headerHeight) * _this.UIHELP.scaleRatio + 'px';
                        break;
                    case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["TYPE_ALIAS"].RECTANGLE:
                        _this.wrapperPropertyPanel.nativeElement.style.left = (component.x + component['width'] + _this.offsetX + screenOffsetX) * _this.UIHELP.scaleRatio + 'px';
                        _this.wrapperPropertyPanel.nativeElement.style.top = (component.y + screenOffsetY + _this.headerHeight) * _this.UIHELP.scaleRatio + 'px';
                        break;
                    case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["TYPE_ALIAS"].CIRCLE:
                        _this.wrapperPropertyPanel.nativeElement.style.left = (component.x + component['radius'] + _this.offsetX + screenOffsetX) * _this.UIHELP.scaleRatio + 'px';
                        _this.wrapperPropertyPanel.nativeElement.style.top = (component.y - component['radius'] + screenOffsetY + _this.headerHeight) * _this.UIHELP.scaleRatio + 'px';
                        break;
                    case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["TYPE_ALIAS"].IMAGE:
                        _this.wrapperPropertyPanel.nativeElement.style.left = (_this.offsetX + screenOffsetX + 320) * _this.UIHELP.scaleRatio + 'px';
                        _this.wrapperPropertyPanel.nativeElement.style.top = (component.y + screenOffsetY + _this.headerHeight) * _this.UIHELP.scaleRatio + 'px';
                        break;
                    case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["TYPE_ALIAS"].BUTTON:
                        _this.wrapperPropertyPanel.nativeElement.style.left = (component.x + screenOffsetX) * _this.UIHELP.scaleRatio + 'px';
                        _this.wrapperPropertyPanel.nativeElement.style.top = (component.y + screenOffsetY + _this.headerHeight + 90) * _this.UIHELP.scaleRatio + 'px';
                        break;
                    case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["TYPE_ALIAS"].SCREEN:
                        _this.wrapperPropertyPanel.nativeElement.style.left = (component.x + _this.offsetX + screenOffsetX + 320) * _this.UIHELP.scaleRatio + 'px';
                        _this.wrapperPropertyPanel.nativeElement.style.top = (component.y + screenOffsetY + _this.headerHeight) * _this.UIHELP.scaleRatio + 'px';
                        break;
                    default:
                        _this.wrapperPropertyPanel.nativeElement.style.display = 'none';
                        break;
                }
            }
        });
    };
    // 鼠标事件
    PropertyPanelComponent.prototype.stopPropagation = function (ev) {
        ev.stopPropagation();
    };
    // chang改变blockly属性
    PropertyPanelComponent.prototype.changePropertyHandler = function (data) {
        if (this.selectedComponent === null)
            return;
        if (data.key === 'x' || data.key === 'y' || data.key == 'width' || data.key === 'height' || data.key === 'rotation') {
            this.selectedComponent.setProp(data.key, data.value);
        }
        else {
            this.selectedComponent.setProp(data.key, data.value);
        }
        if (data.key === src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["COMPONENT_ALIAS"].IMAGE_PATH)
            return;
        this.UIHELP.updateSvg(this.selectedComponent, data.key, data.value);
    };
    // reload事件
    PropertyPanelComponent.prototype.updateImgHandler = function (base64) {
        var _this = this;
        // let img = new Image();
        var img = document.createElement('img');
        img.onload = function () {
            document.body.appendChild(img);
            var width = img.width - 0;
            var height = img.height - 0;
            img.style.display = 'none';
            _this.UIHELP.updateSvg(_this.selectedComponent, src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["COMPONENT_ALIAS"].IMAGE_PATH, "" + base64);
            _this.UIHELP.updateSvg(_this.selectedComponent, src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["COMPONENT_ALIAS"].IMAGE_WIDTH, width);
            _this.UIHELP.updateSvg(_this.selectedComponent, src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["COMPONENT_ALIAS"].IMAGE_HEIGHT, height);
            _this.selectedComponent.componentSvg.dirty();
            _this.selectedComponent.componentSvg._image.onload = function () {
                _this.selectedComponent.componentSvg.dirty();
            };
            // let img1 = new Image();
            // img1.src = this.selectedComponent.componentSvg.style.image;
            _this.selectedComponent.componentSvg._image.src = _this.selectedComponent.componentSvg.style.image;
            document.body.removeChild(img);
        };
        img.src = "" + base64;
    };
    //img onchange
    PropertyPanelComponent.prototype.changeToDefaultImgHandler = function () {
        var _this = this;
        this.selectedComponent.setProp(src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["COMPONENT_ALIAS"].IMAGE_PATH, 'default.jpg');
        this.UIHELP.updateSvg(this.selectedComponent, src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_2__["COMPONENT_ALIAS"].IMAGE_PATH, "../../../assets/images/default.jpg");
        // 设置reload图片属性
        // this.UIHELP.updateSvg(this.selectedComponent, COMPONENT_ALIAS.IMAGE_WIDTH, width);
        // this.UIHELP.updateSvg(this.selectedComponent, COMPONENT_ALIAS.IMAGE_HEIGHT, height);
        this.selectedComponent.componentSvg.dirty();
        this.selectedComponent.componentSvg._image.onload = function () {
            _this.selectedComponent.componentSvg.dirty();
        };
        this.selectedComponent.componentSvg._image.src = this.selectedComponent.componentSvg.style.image;
    };
    PropertyPanelComponent.prototype.close = function () {
        this.rd2.removeClass(this.wrapperPropertyPanel.nativeElement, 'show');
    };
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ViewChild"])('wrapperPropertyPanel'),
        __metadata("design:type", _angular_core__WEBPACK_IMPORTED_MODULE_0__["ElementRef"])
    ], PropertyPanelComponent.prototype, "wrapperPropertyPanel", void 0);
    PropertyPanelComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-property-panel',
            template: __webpack_require__(/*! ./property-panel.component.html */ "./src/app/workspace/property-panel/property-panel.component.html"),
            styles: [__webpack_require__(/*! ./property-panel.component.scss */ "./src/app/workspace/property-panel/property-panel.component.scss")]
        }),
        __metadata("design:paramtypes", [src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__["GlobalOperatorService"],
            src_app_services_zrender_helper_service__WEBPACK_IMPORTED_MODULE_3__["ZrenderHelperService"],
            src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__["ZrenderHelperMbService"],
            _angular_core__WEBPACK_IMPORTED_MODULE_0__["Renderer2"],
            src_app_services_store_service__WEBPACK_IMPORTED_MODULE_4__["StoreService"]])
    ], PropertyPanelComponent);
    return PropertyPanelComponent;
}());



/***/ }),

/***/ "./src/app/workspace/ui-editor-mb/ui-editor-mb.component.html":
/*!********************************************************************!*\
  !*** ./src/app/workspace/ui-editor-mb/ui-editor-mb.component.html ***!
  \********************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div id=\"wrapper_ui_editor_mb\" [class.hide]=\"!(workspaceVisibility$ | async)\" class=\"wrapper--ui-editor\" #wrapperUIEditorMb></div>\r\n\r\n<app-property-panel></app-property-panel>\r\n\r\n<app-unit-property-panel></app-unit-property-panel>"

/***/ }),

/***/ "./src/app/workspace/ui-editor-mb/ui-editor-mb.component.scss":
/*!********************************************************************!*\
  !*** ./src/app/workspace/ui-editor-mb/ui-editor-mb.component.scss ***!
  \********************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper--ui-editor {\n  width: 100vw;\n  height: 100%;\n  background-color: #303131;\n  position: relative; }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvd29ya3NwYWNlL3VpLWVkaXRvci1tYi9aOlxcd29ya3NwYWNlXFxteV96cmVuZGVyXFxmbG93L3NyY1xcYXBwXFx3b3Jrc3BhY2VcXHVpLWVkaXRvci1tYlxcdWktZWRpdG9yLW1iLmNvbXBvbmVudC5zY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUlBO0VBQ0ksYUFBWTtFQUNaLGFBQVk7RUFDWiwwQkFMYTtFQU1iLG1CQUFrQixFQUNyQiIsImZpbGUiOiJzcmMvYXBwL3dvcmtzcGFjZS91aS1lZGl0b3ItbWIvdWktZWRpdG9yLW1iLmNvbXBvbmVudC5zY3NzIiwic291cmNlc0NvbnRlbnQiOlsiJHdpZHRoOiA0NjBweDtcclxuJHNtYWxsV2lkdGg6IDM2MHB4O1xyXG4kYmdDb2xvcjogIzMwMzEzMTtcclxuXHJcbi53cmFwcGVyLS11aS1lZGl0b3Ige1xyXG4gICAgd2lkdGg6IDEwMHZ3O1xyXG4gICAgaGVpZ2h0OiAxMDAlO1xyXG4gICAgYmFja2dyb3VuZC1jb2xvcjogJGJnQ29sb3I7XHJcbiAgICBwb3NpdGlvbjogcmVsYXRpdmU7XHJcbn1cclxuXHJcblxyXG4iXX0= */"

/***/ }),

/***/ "./src/app/workspace/ui-editor-mb/ui-editor-mb.component.ts":
/*!******************************************************************!*\
  !*** ./src/app/workspace/ui-editor-mb/ui-editor-mb.component.ts ***!
  \******************************************************************/
/*! exports provided: UiEditorMbComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UiEditorMbComponent", function() { return UiEditorMbComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/services/services.module */ "./src/app/services/services.module.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};


var UiEditorMbComponent = /** @class */ (function () {
    function UiEditorMbComponent(uiEditorSrv, globalOperatorSrv, storeSrv) {
        this.uiEditorSrv = uiEditorSrv;
        this.globalOperatorSrv = globalOperatorSrv;
        this.storeSrv = storeSrv;
        this.workspaceVisibility$ = this.globalOperatorSrv.getUIVisibility();
    }
    UiEditorMbComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.wrapperUIEditorMb.nativeElement.addEventListener('touchmove', function (ev) { return ev.preventDefault(); });
        this.storeSrv.getType().subscribe(function (res) {
            _this.uiEditorSrv.init(_this.wrapperUIEditorMb.nativeElement.id, res);
        });
    };
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ViewChild"])('wrapperUIEditorMb'),
        __metadata("design:type", _angular_core__WEBPACK_IMPORTED_MODULE_0__["ElementRef"])
    ], UiEditorMbComponent.prototype, "wrapperUIEditorMb", void 0);
    UiEditorMbComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-ui-editor-mb',
            template: __webpack_require__(/*! ./ui-editor-mb.component.html */ "./src/app/workspace/ui-editor-mb/ui-editor-mb.component.html"),
            styles: [__webpack_require__(/*! ./ui-editor-mb.component.scss */ "./src/app/workspace/ui-editor-mb/ui-editor-mb.component.scss")]
        }),
        __metadata("design:paramtypes", [src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__["UiEditorService"], src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__["GlobalOperatorService"], src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__["StoreService"]])
    ], UiEditorMbComponent);
    return UiEditorMbComponent;
}());



/***/ }),

/***/ "./src/app/workspace/ui-editor/ui-editor.component.html":
/*!**************************************************************!*\
  !*** ./src/app/workspace/ui-editor/ui-editor.component.html ***!
  \**************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div id=\"wrapper_ui_editor\" [class.hide]=\"!(workspaceVisibility$ | async)\" class=\"wrapper--ui-editor\" #wrapperUIEditor></div>\r\n\r\n<button class=\"btn--collapse\" (click)=\"toggleVisibility()\">{{ ((workspaceVisibility$ | async) ? \"HIDEUI\" : \"SHOWUI\") | translate}}</button>\r\n\r\n<app-property-panel></app-property-panel>\r\n\r\n<app-unit-property-panel></app-unit-property-panel>\r\n"

/***/ }),

/***/ "./src/app/workspace/ui-editor/ui-editor.component.scss":
/*!**************************************************************!*\
  !*** ./src/app/workspace/ui-editor/ui-editor.component.scss ***!
  \**************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper--ui-editor {\n  width: 460px;\n  height: 100%;\n  background-color: #303131;\n  position: relative; }\n  .wrapper--ui-editor.hide {\n    display: none; }\n  @media screen and (max-width: 1400px) {\n    .wrapper--ui-editor {\n      width: 360px; } }\n  .btn--collapse {\n  position: absolute;\n  left: 0;\n  bottom: 30px;\n  padding: 8px 16px;\n  font-size: 18px;\n  outline: none;\n  border: none;\n  background-color: #444f59;\n  color: white;\n  font-weight: bolder;\n  cursor: pointer;\n  border-top-right-radius: 6px;\n  border-bottom-right-radius: 6px;\n  z-index: 999999; }\n  @media only screen and (min-width: 320px) and (max-height: 767px) {\n  .wrapper--ui-editor {\n    width: 180px; }\n  .btn--collapse {\n    display: none; } }\n  @media only screen and (min-width: 1024px) {\n  .wrapper--ui-editor {\n    width: 360px; }\n  .btn--collapse {\n    display: block; } }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvd29ya3NwYWNlL3VpLWVkaXRvci9aOlxcd29ya3NwYWNlXFxteV96cmVuZGVyXFxmbG93L3NyY1xcYXBwXFx3b3Jrc3BhY2VcXHVpLWVkaXRvclxcdWktZWRpdG9yLmNvbXBvbmVudC5zY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUlBO0VBQ0ksYUFMUztFQU1ULGFBQVk7RUFDWiwwQkFMYTtFQU1iLG1CQUFrQixFQVNyQjtFQWJEO0lBT1EsY0FBYSxFQUNoQjtFQUVEO0lBVko7TUFXUSxhQWRVLEVBZ0JqQixFQUFBO0VBRUQ7RUFDSSxtQkFBa0I7RUFDbEIsUUFBTztFQUNQLGFBQVk7RUFDWixrQkFBaUI7RUFDakIsZ0JBQWU7RUFDZixjQUFhO0VBQ2IsYUFBWTtFQUNaLDBCQUF5QjtFQUN6QixhQUFZO0VBQ1osb0JBQW1CO0VBQ25CLGdCQUFlO0VBQ2YsNkJBQTRCO0VBQzVCLGdDQUErQjtFQUMvQixnQkFBZSxFQUNsQjtFQUdEO0VBQ0k7SUFDSSxhQUFZLEVBQ2Y7RUFDRDtJQUNJLGNBQWEsRUFDaEIsRUFBQTtFQUdMO0VBQ0k7SUFDSSxhQS9DVSxFQWdEYjtFQUNEO0lBQ0ksZUFBYyxFQUNqQixFQUFBIiwiZmlsZSI6InNyYy9hcHAvd29ya3NwYWNlL3VpLWVkaXRvci91aS1lZGl0b3IuY29tcG9uZW50LnNjc3MiLCJzb3VyY2VzQ29udGVudCI6WyIkd2lkdGg6IDQ2MHB4O1xyXG4kc21hbGxXaWR0aDogMzYwcHg7XHJcbiRiZ0NvbG9yOiAjMzAzMTMxO1xyXG5cclxuLndyYXBwZXItLXVpLWVkaXRvciB7XHJcbiAgICB3aWR0aDogJHdpZHRoO1xyXG4gICAgaGVpZ2h0OiAxMDAlO1xyXG4gICAgYmFja2dyb3VuZC1jb2xvcjogJGJnQ29sb3I7XHJcbiAgICBwb3NpdGlvbjogcmVsYXRpdmU7XHJcblxyXG4gICAgJi5oaWRlIHtcclxuICAgICAgICBkaXNwbGF5OiBub25lO1xyXG4gICAgfVxyXG5cclxuICAgIEBtZWRpYSBzY3JlZW4gYW5kIChtYXgtd2lkdGg6IDE0MDBweCl7XHJcbiAgICAgICAgd2lkdGg6ICRzbWFsbFdpZHRoO1xyXG4gICAgfVxyXG59XHJcblxyXG4uYnRuLS1jb2xsYXBzZSB7XHJcbiAgICBwb3NpdGlvbjogYWJzb2x1dGU7XHJcbiAgICBsZWZ0OiAwO1xyXG4gICAgYm90dG9tOiAzMHB4O1xyXG4gICAgcGFkZGluZzogOHB4IDE2cHg7XHJcbiAgICBmb250LXNpemU6IDE4cHg7XHJcbiAgICBvdXRsaW5lOiBub25lO1xyXG4gICAgYm9yZGVyOiBub25lO1xyXG4gICAgYmFja2dyb3VuZC1jb2xvcjogIzQ0NGY1OTtcclxuICAgIGNvbG9yOiB3aGl0ZTtcclxuICAgIGZvbnQtd2VpZ2h0OiBib2xkZXI7XHJcbiAgICBjdXJzb3I6IHBvaW50ZXI7XHJcbiAgICBib3JkZXItdG9wLXJpZ2h0LXJhZGl1czogNnB4O1xyXG4gICAgYm9yZGVyLWJvdHRvbS1yaWdodC1yYWRpdXM6IDZweDtcclxuICAgIHotaW5kZXg6IDk5OTk5OTtcclxufVxyXG5cclxuXHJcbkBtZWRpYSBvbmx5IHNjcmVlbiBhbmQgKG1pbi13aWR0aDozMjBweCkgYW5kIChtYXgtaGVpZ2h0Ojc2N3B4KSB7XHJcbiAgICAud3JhcHBlci0tdWktZWRpdG9yIHtcclxuICAgICAgICB3aWR0aDogMTgwcHg7XHJcbiAgICB9XHJcbiAgICAuYnRuLS1jb2xsYXBzZSB7XHJcbiAgICAgICAgZGlzcGxheTogbm9uZTtcclxuICAgIH1cclxufVxyXG5cclxuQG1lZGlhIG9ubHkgc2NyZWVuIGFuZCAobWluLXdpZHRoOjEwMjRweCkge1xyXG4gICAgLndyYXBwZXItLXVpLWVkaXRvciB7XHJcbiAgICAgICAgd2lkdGg6ICRzbWFsbFdpZHRoO1xyXG4gICAgfVxyXG4gICAgLmJ0bi0tY29sbGFwc2Uge1xyXG4gICAgICAgIGRpc3BsYXk6IGJsb2NrO1xyXG4gICAgfVxyXG59Il19 */"

/***/ }),

/***/ "./src/app/workspace/ui-editor/ui-editor.component.ts":
/*!************************************************************!*\
  !*** ./src/app/workspace/ui-editor/ui-editor.component.ts ***!
  \************************************************************/
/*! exports provided: UiEditorComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UiEditorComponent", function() { return UiEditorComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/services/services.module */ "./src/app/services/services.module.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};


var UiEditorComponent = /** @class */ (function () {
    function UiEditorComponent(uiEditorSrv, globalOperatorSrv, storeSrv) {
        this.uiEditorSrv = uiEditorSrv;
        this.globalOperatorSrv = globalOperatorSrv;
        this.storeSrv = storeSrv;
        this.workspaceVisibility$ = this.globalOperatorSrv.getUIVisibility();
    }
    UiEditorComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.wrapperUIEditor.nativeElement.addEventListener('touchmove', function (ev) { return ev.preventDefault(); });
        this.storeSrv.getType().subscribe(function (res) {
            _this.uiEditorSrv.init(_this.wrapperUIEditor.nativeElement.id, res);
        });
    };
    UiEditorComponent.prototype.toggleVisibility = function () {
        this.globalOperatorSrv.setSelectedUnit(null);
        this.globalOperatorSrv.setSelectedComponent(null);
        this.globalOperatorSrv.setUIVisibility(!this.globalOperatorSrv.UIVisibility.value);
    };
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ViewChild"])('wrapperUIEditor'),
        __metadata("design:type", _angular_core__WEBPACK_IMPORTED_MODULE_0__["ElementRef"])
    ], UiEditorComponent.prototype, "wrapperUIEditor", void 0);
    UiEditorComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-ui-editor',
            template: __webpack_require__(/*! ./ui-editor.component.html */ "./src/app/workspace/ui-editor/ui-editor.component.html"),
            styles: [__webpack_require__(/*! ./ui-editor.component.scss */ "./src/app/workspace/ui-editor/ui-editor.component.scss")]
        }),
        __metadata("design:paramtypes", [src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__["UiEditorService"], src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__["GlobalOperatorService"], src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__["StoreService"]])
    ], UiEditorComponent);
    return UiEditorComponent;
}());



/***/ }),

/***/ "./src/app/workspace/unit-modal/unit-modal.component.html":
/*!****************************************************************!*\
  !*** ./src/app/workspace/unit-modal/unit-modal.component.html ***!
  \****************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"wrapper--unit-modal\">\r\n  <div class=\"unit-modal\">\r\n    <header>\r\n      <p>{{ 'UNITS' | translate}}</p>\r\n    </header>\r\n\r\n    <ul class=\"list-unit\">\r\n      <li class=\"item-unit\" *ngFor=\"let unit of category\" (click)=\"selectUnit(unit)\" [class.disable]=\"unit.hidden || unit.stickNone=== isstick\" [class.isnone]=\"unit.stickType === isstick\">\r\n        <input class=\"selectUint\" type=\"checkbox\" value=\"{{unit.type}}\" (change)=\"handle($event)\" id={{unit.type}}/>\r\n        <span class=\"checkbox\">\r\n          <img  src=\"../../../assets/images/check.png\" alt=\"checked\">\r\n        </span>\r\n        <span class=\"help\" (click)=\"toDocs(unit, $event)\">\r\n              <img src=\"../../../assets/images/units/wenhaow.png\" alt=\"help\">\r\n        </span>\r\n        <label for=\"{{unit.type}}\" class=\"into\">\r\n            <img [src]=\"'../../../assets/images/units/' + unit.icon\" alt=\"\" class=\"unitImg\">\r\n        </label>\r\n        <div class=\"config-unit\" *ngIf=\"selectedUnit === unit\" (click)=\"stopPropagation($event)\">\r\n          <div class=\"unit-param\">\r\n            <p>{{ 'PORT' | translate }}:</p>\r\n            <select [value]=\"unit.port\" (change)=\"setUnit(unit.type,$event, 'port')\">\r\n              <option *ngFor=\"let port of unit?.default\" value=\"{{port}}\">{{port}}</option>\r\n            </select>\r\n          </div>\r\n          <div class=\"unit-param\" *ngIf=\"unit.hasOwnProperty('count')\">\r\n            <p>{{ 'COUNT'| translate }}:</p>\r\n            <input type=\"text\" [value]=\"unit.count\" (input)=\"setUnit(unit.type,$event,'count')\">\r\n          </div>\r\n        </div>\r\n      </li>\r\n    </ul>\r\n\r\n    <footer>\r\n      <button class=\"btn cancel\" (click)=\"cancel()\">{{ 'CANCEL' | translate }}</button>\r\n      <button class=\"btn ok\" (click)=\"ok()\">{{ 'OK' | translate}}</button>\r\n    </footer>\r\n  </div>\r\n</div>"

/***/ }),

/***/ "./src/app/workspace/unit-modal/unit-modal.component.scss":
/*!****************************************************************!*\
  !*** ./src/app/workspace/unit-modal/unit-modal.component.scss ***!
  \****************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper--unit-modal {\n  position: relative;\n  width: 100%;\n  height: 100%;\n  -webkit-animation: zoomIn .35s ease;\n          animation: zoomIn .35s ease; }\n\n.unit-modal {\n  width: 70%;\n  position: relative;\n  top: 50%;\n  left: 50%;\n  -webkit-transform: translate(-50%, -50%);\n          transform: translate(-50%, -50%);\n  background-color: #2d2d2d;\n  border-radius: 8px; }\n\nheader p {\n  padding: 8px 12px;\n  font-size: 22px;\n  font-family: Arial;\n  border-bottom: 1px solid #555;\n  color: #FFF;\n  font-weight: bolder; }\n\nfooter {\n  text-align: right;\n  border-top: 1px solid #555; }\n\nfooter .btn {\n  outline: none;\n  padding: 6px 16px;\n  font-size: 18px;\n  border: none;\n  border-radius: 5px;\n  margin: 12px 8px;\n  color: white;\n  cursor: pointer;\n  font-weight: bolder; }\n\nfooter .btn.cancel {\n    background-color: #FF5F2E; }\n\nfooter .btn.ok {\n    background-color: #3ac569; }\n\n.list-unit {\n  padding: 0 20px;\n  display: flex;\n  height: 320px;\n  overflow-y: scroll;\n  flex-direction: row;\n  margin: 20px 0;\n  flex-wrap: wrap; }\n\n.item-unit {\n  position: relative;\n  list-style-type: none;\n  width: 80px;\n  height: 170px;\n  margin: 16px 16px 0 16px;\n  cursor: pointer; }\n\n.item-unit.disable {\n    pointer-events: none;\n    -webkit-filter: brightness(50%);\n            filter: brightness(50%); }\n\n.item-unit.disable::after {\n      content: '';\n      display: block;\n      -webkit-filter: brightness(100%);\n              filter: brightness(100%);\n      position: absolute;\n      width: 48px;\n      height: 48px;\n      top: 17px;\n      left: 50%;\n      -webkit-transform: translateX(-50%);\n              transform: translateX(-50%);\n      background-image: url('jinzhi.png'); }\n\n.item-unit.isnone {\n    display: none; }\n\n.item-unit .selectUint {\n    width: 88px;\n    /* clip: rect(0px 0px 0px 0px); */\n    position: absolute;\n    top: -15px;\n    height: 100px;\n    /* background: red; */\n    z-index: 3;\n    opacity: 0;\n    cursor: pointer; }\n\n.item-unit .selectUint + span > img {\n    display: none; }\n\n.item-unit .selectUint:checked + span > img {\n    display: inline-block; }\n\n.item-unit .unitImg {\n    max-width: 100%; }\n\n.item-unit .config-unit {\n    margin-top: 10px; }\n\n.item-unit .config-unit .unit-param {\n      margin-bottom: 6px; }\n\n.item-unit .into {\n    display: inline-block; }\n\n.item-unit img {\n    display: block;\n    margin: 0 auto;\n    opacity: 1; }\n\n.item-unit p {\n    font-family: Arial;\n    color: #eee; }\n\n.item-unit select, .item-unit input {\n    width: 100%;\n    outline: none;\n    background-color: #FFF;\n    border: none;\n    border-radius: 2px;\n    color: #333; }\n\n.item-unit input {\n    padding: 3px; }\n\n.item-unit .checkbox {\n    position: absolute;\n    right: -8px;\n    top: -8px;\n    background-color: white;\n    width: 16px;\n    height: 16px;\n    color: white;\n    border-radius: 3px;\n    z-index: 2; }\n\n.item-unit .checkbox img {\n      display: block; }\n\n.item-unit .help {\n    position: absolute;\n    width: 16px;\n    height: 16px;\n    right: -8px;\n    top: 16px;\n    cursor: help;\n    z-index: 4; }\n\n@media only screen and (min-width: 320px) and (max-height: 767px) {\n  .list-unit {\n    padding: 0 20px;\n    display: flex;\n    height: 115px;\n    overflow-y: scroll;\n    flex-direction: row;\n    margin: 20px 0;\n    flex-wrap: wrap; } }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvd29ya3NwYWNlL3VuaXQtbW9kYWwvWjpcXHdvcmtzcGFjZVxcbXlfenJlbmRlclxcZmxvdy9zcmNcXGFwcFxcd29ya3NwYWNlXFx1bml0LW1vZGFsXFx1bml0LW1vZGFsLmNvbXBvbmVudC5zY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUFBO0VBQ0ksbUJBQWtCO0VBQ2xCLFlBQVc7RUFDWCxhQUFZO0VBQ1osb0NBQTJCO1VBQTNCLDRCQUEyQixFQUM5Qjs7QUFFRDtFQUNJLFdBQVU7RUFDVixtQkFBa0I7RUFDbEIsU0FBUTtFQUNSLFVBQVM7RUFDVCx5Q0FBZ0M7VUFBaEMsaUNBQWdDO0VBQ2hDLDBCQUF5QjtFQUN6QixtQkFBa0IsRUFDckI7O0FBRUQ7RUFDSSxrQkFBaUI7RUFDakIsZ0JBQWU7RUFDZixtQkFBa0I7RUFDbEIsOEJBQTZCO0VBQzdCLFlBQVc7RUFDWCxvQkFBbUIsRUFDdEI7O0FBRUQ7RUFDSSxrQkFBaUI7RUFDakIsMkJBQTBCLEVBQzdCOztBQUVEO0VBQ0ksY0FBYTtFQUNiLGtCQUFpQjtFQUNqQixnQkFBZTtFQUNmLGFBQVk7RUFDWixtQkFBa0I7RUFDbEIsaUJBQWdCO0VBQ2hCLGFBQVk7RUFDWixnQkFBZTtFQUNmLG9CQUFtQixFQVN0Qjs7QUFsQkQ7SUFZUSwwQkFBeUIsRUFDNUI7O0FBYkw7SUFnQlEsMEJBQXlCLEVBQzVCOztBQUdMO0VBQ0ksZ0JBQWU7RUFDZixjQUFhO0VBQ2IsY0FBYTtFQUNiLG1CQUFrQjtFQUNsQixvQkFBbUI7RUFDbkIsZUFBYztFQUNkLGdCQUFlLEVBQ2xCOztBQUVEO0VBQ0ksbUJBQWtCO0VBQ2xCLHNCQUFxQjtFQUNyQixZQUFXO0VBQ1gsY0FBYTtFQUNiLHlCQUF3QjtFQUN4QixnQkFBZSxFQW1HbEI7O0FBekdEO0lBUVEscUJBQW9CO0lBQ3BCLGdDQUF1QjtZQUF2Qix3QkFBdUIsRUFhMUI7O0FBdEJMO01BV1ksWUFBVztNQUNYLGVBQWM7TUFDZCxpQ0FBd0I7Y0FBeEIseUJBQXdCO01BQ3hCLG1CQUFrQjtNQUNsQixZQUFXO01BQ1gsYUFBWTtNQUNaLFVBQVM7TUFDVCxVQUFTO01BQ1Qsb0NBQTJCO2NBQTNCLDRCQUEyQjtNQUMzQixvQ0FBZ0UsRUFDbkU7O0FBckJUO0lBd0JRLGNBQWEsRUFDaEI7O0FBekJMO0lBMkJRLFlBQVc7SUFDWCxrQ0FBa0M7SUFDbEMsbUJBQWtCO0lBQ2xCLFdBQVU7SUFDVixjQUFhO0lBQ2Isc0JBQXNCO0lBQ3RCLFdBQVU7SUFDVixXQUFVO0lBQ1YsZ0JBQWUsRUFDbEI7O0FBcENMO0lBc0NRLGNBQWEsRUFDaEI7O0FBdkNMO0lBeUNRLHNCQUFxQixFQUN4Qjs7QUExQ0w7SUE0Q1EsZ0JBQWUsRUFDbEI7O0FBN0NMO0lBK0NRLGlCQUFnQixFQUtuQjs7QUFwREw7TUFrRFksbUJBQWtCLEVBQ3JCOztBQW5EVDtJQXNEUSxzQkFBcUIsRUFHeEI7O0FBekRMO0lBMkRRLGVBQWM7SUFDZCxlQUFjO0lBQ2QsV0FBVSxFQUNiOztBQTlETDtJQWlFUSxtQkFBa0I7SUFDbEIsWUFBVyxFQUNkOztBQW5FTDtJQXNFUSxZQUFXO0lBQ1gsY0FBYTtJQUNiLHVCQUFzQjtJQUN0QixhQUFZO0lBQ1osbUJBQWtCO0lBQ2xCLFlBQVcsRUFDZDs7QUE1RUw7SUErRVEsYUFBWSxFQUNmOztBQWhGTDtJQW1GUSxtQkFBa0I7SUFDbEIsWUFBVztJQUNYLFVBQVM7SUFDVCx3QkFBdUI7SUFDdkIsWUFBVztJQUNYLGFBQVk7SUFDWixhQUFZO0lBQ1osbUJBQWtCO0lBQ2xCLFdBQVUsRUFJYjs7QUEvRkw7TUE2RlksZUFBYyxFQUNqQjs7QUE5RlQ7SUFpR1EsbUJBQWtCO0lBQ2xCLFlBQVc7SUFDWCxhQUFZO0lBQ1osWUFBVztJQUNYLFVBQVM7SUFDVCxhQUFZO0lBQ1osV0FBVSxFQUNiOztBQUdMO0VBQ0k7SUFDSSxnQkFBZTtJQUNmLGNBQWE7SUFDYixjQUFhO0lBQ2IsbUJBQWtCO0lBQ2xCLG9CQUFtQjtJQUNuQixlQUFjO0lBQ2QsZ0JBQWUsRUFDbEIsRUFBQSIsImZpbGUiOiJzcmMvYXBwL3dvcmtzcGFjZS91bml0LW1vZGFsL3VuaXQtbW9kYWwuY29tcG9uZW50LnNjc3MiLCJzb3VyY2VzQ29udGVudCI6WyIud3JhcHBlci0tdW5pdC1tb2RhbCB7XHJcbiAgICBwb3NpdGlvbjogcmVsYXRpdmU7XHJcbiAgICB3aWR0aDogMTAwJTtcclxuICAgIGhlaWdodDogMTAwJTtcclxuICAgIGFuaW1hdGlvbjogem9vbUluIC4zNXMgZWFzZTtcclxufVxyXG5cclxuLnVuaXQtbW9kYWwge1xyXG4gICAgd2lkdGg6IDcwJTtcclxuICAgIHBvc2l0aW9uOiByZWxhdGl2ZTtcclxuICAgIHRvcDogNTAlO1xyXG4gICAgbGVmdDogNTAlO1xyXG4gICAgdHJhbnNmb3JtOiB0cmFuc2xhdGUoLTUwJSwgLTUwJSk7XHJcbiAgICBiYWNrZ3JvdW5kLWNvbG9yOiAjMmQyZDJkO1xyXG4gICAgYm9yZGVyLXJhZGl1czogOHB4O1xyXG59XHJcblxyXG5oZWFkZXIgcCB7XHJcbiAgICBwYWRkaW5nOiA4cHggMTJweDtcclxuICAgIGZvbnQtc2l6ZTogMjJweDtcclxuICAgIGZvbnQtZmFtaWx5OiBBcmlhbDtcclxuICAgIGJvcmRlci1ib3R0b206IDFweCBzb2xpZCAjNTU1O1xyXG4gICAgY29sb3I6ICNGRkY7XHJcbiAgICBmb250LXdlaWdodDogYm9sZGVyO1xyXG59XHJcblxyXG5mb290ZXIge1xyXG4gICAgdGV4dC1hbGlnbjogcmlnaHQ7XHJcbiAgICBib3JkZXItdG9wOiAxcHggc29saWQgIzU1NTtcclxufVxyXG5cclxuZm9vdGVyIC5idG4ge1xyXG4gICAgb3V0bGluZTogbm9uZTtcclxuICAgIHBhZGRpbmc6IDZweCAxNnB4O1xyXG4gICAgZm9udC1zaXplOiAxOHB4O1xyXG4gICAgYm9yZGVyOiBub25lO1xyXG4gICAgYm9yZGVyLXJhZGl1czogNXB4O1xyXG4gICAgbWFyZ2luOiAxMnB4IDhweDtcclxuICAgIGNvbG9yOiB3aGl0ZTtcclxuICAgIGN1cnNvcjogcG9pbnRlcjtcclxuICAgIGZvbnQtd2VpZ2h0OiBib2xkZXI7XHJcblxyXG4gICAgJi5jYW5jZWwge1xyXG4gICAgICAgIGJhY2tncm91bmQtY29sb3I6ICNGRjVGMkU7XHJcbiAgICB9XHJcblxyXG4gICAgJi5vayB7XHJcbiAgICAgICAgYmFja2dyb3VuZC1jb2xvcjogIzNhYzU2OTtcclxuICAgIH1cclxufVxyXG5cclxuLmxpc3QtdW5pdCB7XHJcbiAgICBwYWRkaW5nOiAwIDIwcHg7XHJcbiAgICBkaXNwbGF5OiBmbGV4O1xyXG4gICAgaGVpZ2h0OiAzMjBweDtcclxuICAgIG92ZXJmbG93LXk6IHNjcm9sbDtcclxuICAgIGZsZXgtZGlyZWN0aW9uOiByb3c7XHJcbiAgICBtYXJnaW46IDIwcHggMDtcclxuICAgIGZsZXgtd3JhcDogd3JhcDtcclxufVxyXG5cclxuLml0ZW0tdW5pdCB7XHJcbiAgICBwb3NpdGlvbjogcmVsYXRpdmU7XHJcbiAgICBsaXN0LXN0eWxlLXR5cGU6IG5vbmU7XHJcbiAgICB3aWR0aDogODBweDtcclxuICAgIGhlaWdodDogMTcwcHg7XHJcbiAgICBtYXJnaW46IDE2cHggMTZweCAwIDE2cHg7XHJcbiAgICBjdXJzb3I6IHBvaW50ZXI7XHJcbiAgICAmLmRpc2FibGUge1xyXG4gICAgICAgIHBvaW50ZXItZXZlbnRzOiBub25lO1xyXG4gICAgICAgIGZpbHRlcjogYnJpZ2h0bmVzcyg1MCUpO1xyXG4gICAgICAgICY6OmFmdGVyIHtcclxuICAgICAgICAgICAgY29udGVudDogJyc7XHJcbiAgICAgICAgICAgIGRpc3BsYXk6IGJsb2NrO1xyXG4gICAgICAgICAgICBmaWx0ZXI6IGJyaWdodG5lc3MoMTAwJSk7XHJcbiAgICAgICAgICAgIHBvc2l0aW9uOiBhYnNvbHV0ZTtcclxuICAgICAgICAgICAgd2lkdGg6IDQ4cHg7XHJcbiAgICAgICAgICAgIGhlaWdodDogNDhweDtcclxuICAgICAgICAgICAgdG9wOiAxN3B4O1xyXG4gICAgICAgICAgICBsZWZ0OiA1MCU7XHJcbiAgICAgICAgICAgIHRyYW5zZm9ybTogdHJhbnNsYXRlWCgtNTAlKTtcclxuICAgICAgICAgICAgYmFja2dyb3VuZC1pbWFnZTogdXJsKCcuLi8uLi8uLi9hc3NldHMvaW1hZ2VzL3VuaXRzL2ppbnpoaS5wbmcnKTtcclxuICAgICAgICB9XHJcbiAgICB9XHJcbiAgICAmLmlzbm9uZSB7XHJcbiAgICAgICAgZGlzcGxheTogbm9uZTtcclxuICAgIH1cclxuICAgIC5zZWxlY3RVaW50IHtcclxuICAgICAgICB3aWR0aDogODhweDtcclxuICAgICAgICAvKiBjbGlwOiByZWN0KDBweCAwcHggMHB4IDBweCk7ICovXHJcbiAgICAgICAgcG9zaXRpb246IGFic29sdXRlO1xyXG4gICAgICAgIHRvcDogLTE1cHg7XHJcbiAgICAgICAgaGVpZ2h0OiAxMDBweDtcclxuICAgICAgICAvKiBiYWNrZ3JvdW5kOiByZWQ7ICovXHJcbiAgICAgICAgei1pbmRleDogMztcclxuICAgICAgICBvcGFjaXR5OiAwO1xyXG4gICAgICAgIGN1cnNvcjogcG9pbnRlcjtcclxuICAgIH1cclxuICAgIC5zZWxlY3RVaW50ICsgc3Bhbj5pbWcge1xyXG4gICAgICAgIGRpc3BsYXk6IG5vbmU7XHJcbiAgICB9XHJcbiAgICAuc2VsZWN0VWludDpjaGVja2VkICsgc3Bhbj5pbWcge1xyXG4gICAgICAgIGRpc3BsYXk6IGlubGluZS1ibG9jaztcclxuICAgIH1cclxuICAgIC51bml0SW1nIHtcclxuICAgICAgICBtYXgtd2lkdGg6IDEwMCU7XHJcbiAgICB9XHJcbiAgICAuY29uZmlnLXVuaXQge1xyXG4gICAgICAgIG1hcmdpbi10b3A6IDEwcHg7XHJcblxyXG4gICAgICAgIC51bml0LXBhcmFtIHtcclxuICAgICAgICAgICAgbWFyZ2luLWJvdHRvbTogNnB4O1xyXG4gICAgICAgIH1cclxuICAgIH1cclxuICAgIC5pbnRvIHtcclxuICAgICAgICBkaXNwbGF5OiBpbmxpbmUtYmxvY2s7XHJcbiAgICAgICAgLy8gd2lkdGg6IDUwcHg7XHJcbiAgICAgICAgLy8gaGVpZ2h0OiA1MHB4O1xyXG4gICAgfVxyXG4gICAgaW1nIHtcclxuICAgICAgICBkaXNwbGF5OiBibG9jaztcclxuICAgICAgICBtYXJnaW46IDAgYXV0bztcclxuICAgICAgICBvcGFjaXR5OiAxO1xyXG4gICAgfVxyXG5cclxuICAgIHAge1xyXG4gICAgICAgIGZvbnQtZmFtaWx5OiBBcmlhbDtcclxuICAgICAgICBjb2xvcjogI2VlZTtcclxuICAgIH1cclxuXHJcbiAgICBzZWxlY3QsIGlucHV0IHtcclxuICAgICAgICB3aWR0aDogMTAwJTtcclxuICAgICAgICBvdXRsaW5lOiBub25lO1xyXG4gICAgICAgIGJhY2tncm91bmQtY29sb3I6ICNGRkY7XHJcbiAgICAgICAgYm9yZGVyOiBub25lO1xyXG4gICAgICAgIGJvcmRlci1yYWRpdXM6IDJweDtcclxuICAgICAgICBjb2xvcjogIzMzMztcclxuICAgIH1cclxuXHJcbiAgICBpbnB1dCB7XHJcbiAgICAgICAgcGFkZGluZzogM3B4O1xyXG4gICAgfVxyXG5cclxuICAgIC5jaGVja2JveCB7XHJcbiAgICAgICAgcG9zaXRpb246IGFic29sdXRlO1xyXG4gICAgICAgIHJpZ2h0OiAtOHB4O1xyXG4gICAgICAgIHRvcDogLThweDtcclxuICAgICAgICBiYWNrZ3JvdW5kLWNvbG9yOiB3aGl0ZTtcclxuICAgICAgICB3aWR0aDogMTZweDtcclxuICAgICAgICBoZWlnaHQ6IDE2cHg7XHJcbiAgICAgICAgY29sb3I6IHdoaXRlO1xyXG4gICAgICAgIGJvcmRlci1yYWRpdXM6IDNweDtcclxuICAgICAgICB6LWluZGV4OiAyO1xyXG4gICAgICAgIGltZyB7XHJcbiAgICAgICAgICAgIGRpc3BsYXk6IGJsb2NrO1xyXG4gICAgICAgIH1cclxuICAgIH1cclxuICAgIC5oZWxwIHsgICAgICAgIFxyXG4gICAgICAgIHBvc2l0aW9uOiBhYnNvbHV0ZTtcclxuICAgICAgICB3aWR0aDogMTZweDtcclxuICAgICAgICBoZWlnaHQ6IDE2cHg7XHJcbiAgICAgICAgcmlnaHQ6IC04cHg7XHJcbiAgICAgICAgdG9wOiAxNnB4O1xyXG4gICAgICAgIGN1cnNvcjogaGVscDtcclxuICAgICAgICB6LWluZGV4OiA0O1xyXG4gICAgfVxyXG59XHJcblxyXG5AbWVkaWEgb25seSBzY3JlZW4gYW5kIChtaW4td2lkdGg6MzIwcHgpIGFuZCAobWF4LWhlaWdodDo3NjdweCkge1xyXG4gICAgLmxpc3QtdW5pdCB7XHJcbiAgICAgICAgcGFkZGluZzogMCAyMHB4O1xyXG4gICAgICAgIGRpc3BsYXk6IGZsZXg7XHJcbiAgICAgICAgaGVpZ2h0OiAxMTVweDtcclxuICAgICAgICBvdmVyZmxvdy15OiBzY3JvbGw7XHJcbiAgICAgICAgZmxleC1kaXJlY3Rpb246IHJvdztcclxuICAgICAgICBtYXJnaW46IDIwcHggMDtcclxuICAgICAgICBmbGV4LXdyYXA6IHdyYXA7XHJcbiAgICB9XHJcbn0iXX0= */"

/***/ }),

/***/ "./src/app/workspace/unit-modal/unit-modal.component.ts":
/*!**************************************************************!*\
  !*** ./src/app/workspace/unit-modal/unit-modal.component.ts ***!
  \**************************************************************/
/*! exports provided: UnitModalComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitModalComponent", function() { return UnitModalComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_services_global_operator_service__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/services/global-operator.service */ "./src/app/services/global-operator.service.ts");
/* harmony import */ var src_app_services_store_service__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! src/app/services/store.service */ "./src/app/services/store.service.ts");
/* harmony import */ var src_app_services_zrender_helper_service__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! src/app/services/zrender-helper.service */ "./src/app/services/zrender-helper.service.ts");
/* harmony import */ var _domain_unit__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ../../domain/unit */ "./src/app/domain/unit/index.ts");
/* harmony import */ var src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! src/app/utils/common-data */ "./src/app/utils/common-data.ts");
/* harmony import */ var src_app_services_code_editor_service__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! src/app/services/code-editor.service */ "./src/app/services/code-editor.service.ts");
/* harmony import */ var src_app_services_zrender_helper_mb_service__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! src/app/services/zrender-helper-mb.service */ "./src/app/services/zrender-helper-mb.service.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};








/**
 * 生成Unit目录
 */
var createUnitCategory = function () {
    return [
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitEnv"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitPIR"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].B, default: ['A', 'B', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitNeopixel"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'B', 'C'] }, count: 10 }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitJoystick"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitMakey"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitServo"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'B', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitWeigh"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'B', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitTrack"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitButton"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].B, default: ['A', 'B', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitDualButton"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'B', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitRGB"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].B, default: ['A', 'B', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitRelay"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].B, default: ['A', 'B', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitADC"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitDac"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitNicr"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitIR"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].B, default: ['A', 'B', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitExtio"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitAngle"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].B, default: ['B'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitLight"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].B, default: ['A', 'B', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitEarth"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].B, default: ['A', 'B', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitTOF"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitColor"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitRfid"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitFinger"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].C, default: ['A', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitCardkb"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'C'] } }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitPulse"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'B', 'C'] } }),
        // new Unit396({ name: '', port: { port: PORT.A, default: ['A','B','C'] }  }),
        // new UnitHub({ name: '', port: { port: PORT.A, default: ['A','B','C'] }  }),
        // new UnitM5Camera({ name: '', port: { port: PORT.B, default: ['A','B','C'] }  }),
        // new UnitProto({ name: '', port: { port: PORT.A, default: ['A','B','C'] }  }),
        new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitThermal"]({ name: '', port: { port: src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["PORT"].A, default: ['A', 'B', 'C'] } }),
    ];
};
var UnitModalComponent = /** @class */ (function () {
    function UnitModalComponent(globalOperatorSrv, storeSrv, zrenderHelperSrv, zrenderHelperSrvmb, codeEditorSrv) {
        this.globalOperatorSrv = globalOperatorSrv;
        this.storeSrv = storeSrv;
        this.zrenderHelperSrv = zrenderHelperSrv;
        this.zrenderHelperSrvmb = zrenderHelperSrvmb;
        this.codeEditorSrv = codeEditorSrv;
        /** Unit目录 */
        this.category = [];
        /** 遮罩层对象 */
        this.maskModal = null;
        /** 已选择Unit */
        this.selectedUnit = null;
        this.selectMoreUnit = [];
        this.Allunit = {};
    }
    UnitModalComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.storeSrv.getType().subscribe(function (res) {
            _this.isstick = res;
            _this.category = createUnitCategory();
            for (var i = 0; i < _this.category.length; i++) {
                _this.category[i].port = (res == "core") ? _this.category[i].port : 'A';
                _this.category[i].default = (res == "core") ? _this.category[i].default : ['A'];
            }
        });
    };
    // close
    UnitModalComponent.prototype.cancel = function () {
        this.globalOperatorSrv.maskModal.instance.removeMask();
    };
    UnitModalComponent.prototype.createUnit = function (type) {
        // let type = this.selectedUnit.type;
        switch (type) {
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].ENV:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitEnv"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].ANGLE:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitAngle"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].PIR:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitPIR"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].NEOPIXEL:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitNeopixel"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] }, count: this.selectedUnit.count });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].JOYSTICK:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitJoystick"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].LIGHT:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitLight"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].EARTH:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitEarth"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].MAKEY:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitMakey"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].SERVO:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitServo"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].WEIGH:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitWeigh"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].PULSE:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitPulse"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].TRACK:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitTrack"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].BUTTON:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitButton"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].DUALBUTTON:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitDualButton"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].RGB:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitRGB"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].RELAY:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitRelay"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].DAC:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitDac"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].ADC:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitADC"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].TOF:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitTOF"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].NCIR:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitNicr"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].IR:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitIR"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].EXTIO:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitExtio"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].COLOR:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitColor"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].FINGER:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitFinger"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].RFID:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitRfid"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
            case src_app_utils_common_data__WEBPACK_IMPORTED_MODULE_5__["UNIT_TYPE"].CARDKB:
                return new _domain_unit__WEBPACK_IMPORTED_MODULE_4__["UnitCardkb"]({ name: this.storeSrv.getUnitDefauleName(type), port: { port: this.selectedUnit.port, default: this.selectedUnit.default || ['A', 'B', 'C'] } });
        }
    };
    UnitModalComponent.prototype.handle = function (e) {
        var _val = e.target.value;
        if (_val in this.Allunit) {
            delete this.Allunit[e.target.value];
        }
        else {
            this.Allunit[_val] = this.createUnit(_val);
        }
    };
    UnitModalComponent.prototype.ok = function () {
        for (var i in this.Allunit) {
            this.storeSrv.addUnit(this.Allunit[i]);
        }
        // this.selectMoreUnit.forEach( e => {
        // this.storeSrv.addUnit(this.createUnit(e));
        // });
        this.globalOperatorSrv.maskModal.instance.removeMask();
        if (this.globalOperatorSrv.ismb) {
            this.zrenderHelperSrvmb.updateUnitSvg();
        }
        else {
            this.zrenderHelperSrv.updateUnitSvg();
        }
        if (!this.globalOperatorSrv.codeLock.value) {
            this.codeEditorSrv.updateWorkspaceValue();
        }
    };
    // xuanz
    UnitModalComponent.prototype.selectUnit = function (unit) {
        // console.log(unit)
        this.selectedUnit = unit;
    };
    UnitModalComponent.prototype.stopPropagation = function (ev) {
        ev.stopPropagation();
        ev.preventDefault();
    };
    // port
    UnitModalComponent.prototype.setUnit = function (type, ev, key) {
        this.Allunit[type][key] = ev.target.value;
    };
    UnitModalComponent.prototype.toDocs = function (unit, e) {
        e.stopPropagation();
        window.open("https://docs.m5stack.com/#/en/unit/" + unit.type, '_blank');
        // e.preventDefault();
    };
    UnitModalComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-unit-modal',
            template: __webpack_require__(/*! ./unit-modal.component.html */ "./src/app/workspace/unit-modal/unit-modal.component.html"),
            styles: [__webpack_require__(/*! ./unit-modal.component.scss */ "./src/app/workspace/unit-modal/unit-modal.component.scss")]
        }),
        __metadata("design:paramtypes", [src_app_services_global_operator_service__WEBPACK_IMPORTED_MODULE_1__["GlobalOperatorService"],
            src_app_services_store_service__WEBPACK_IMPORTED_MODULE_2__["StoreService"],
            src_app_services_zrender_helper_service__WEBPACK_IMPORTED_MODULE_3__["ZrenderHelperService"],
            src_app_services_zrender_helper_mb_service__WEBPACK_IMPORTED_MODULE_7__["ZrenderHelperMbService"],
            src_app_services_code_editor_service__WEBPACK_IMPORTED_MODULE_6__["CodeEditorService"]])
    ], UnitModalComponent);
    return UnitModalComponent;
}());



/***/ }),

/***/ "./src/app/workspace/unit-property-panel/unit-property-panel.component.html":
/*!**********************************************************************************!*\
  !*** ./src/app/workspace/unit-property-panel/unit-property-panel.component.html ***!
  \**********************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"wrapper--property--panel\" [class.show]=\"(selectedUnit$ | async) !== null\" (mousedown)=\"stopPropagation($event)\" #wrapperPropertyPanel>\r\n  <p class=\"property name\">{{ (selectedUnit$ | async)?.name }}</p>\r\n  \r\n  <table>\r\n    <tr>\r\n      <td>\r\n        <span>{{ 'PORT' | translate }}</span>\r\n      </td>\r\n      <td>\r\n        <select [value]=\"iscore?unit?.port:unit?.new_port\" (change)=\"setUnitPort($event)\">\r\n          <!-- <option value=\"A\">A</option> -->\r\n          <option *ngFor=\"let port of iscore?unit?.default:unit?.new_default\" value=\"{{port}}\">{{port}}</option>\r\n        </select>\r\n      </td>\r\n    </tr>\r\n    <tr *ngIf=\"(selectedUnit$ | async)?.type === 'neopixel'\">\r\n      <td>\r\n        <span>{{ 'COUNT' | translate }}</span>\r\n      </td>\r\n      <td>\r\n        <input type=\"text\" spellcheck=\"false\" [value]=\"(selectedUnit$ | async)?.count\" (input)=\"setUnitCount($event)\">\r\n      </td>\r\n    </tr>\r\n  </table>\r\n\r\n</div>"

/***/ }),

/***/ "./src/app/workspace/unit-property-panel/unit-property-panel.component.scss":
/*!**********************************************************************************!*\
  !*** ./src/app/workspace/unit-property-panel/unit-property-panel.component.scss ***!
  \**********************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper--property--panel {\n  display: none;\n  position: absolute;\n  top: 0;\n  left: 0;\n  background-color: rgba(255, 255, 255, 0.88);\n  border: 1px solid #666;\n  z-index: 1000001;\n  padding: 8px; }\n  .wrapper--property--panel.show {\n    display: block; }\n  .property.name {\n  font-size: 22px;\n  font-family: Arial; }\n  table {\n  width: 140px;\n  margin-top: 8px;\n  font-family: Arial; }\n  table td {\n    text-align: right; }\n  table td input, table td select {\n      width: 80px; }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvd29ya3NwYWNlL3VuaXQtcHJvcGVydHktcGFuZWwvWjpcXHdvcmtzcGFjZVxcbXlfenJlbmRlclxcZmxvdy9zcmNcXGFwcFxcd29ya3NwYWNlXFx1bml0LXByb3BlcnR5LXBhbmVsXFx1bml0LXByb3BlcnR5LXBhbmVsLmNvbXBvbmVudC5zY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUFBO0VBQ0ksY0FBYTtFQUNiLG1CQUFrQjtFQUNsQixPQUFNO0VBQ04sUUFBTztFQUNQLDRDQUEyQztFQUMzQyx1QkFBc0I7RUFDdEIsaUJBQWdCO0VBQ2hCLGFBQVksRUFLZjtFQWJEO0lBV1EsZUFBYyxFQUNqQjtFQUdMO0VBQ0ksZ0JBQWU7RUFDZixtQkFBa0IsRUFDckI7RUFFRDtFQUNJLGFBQVk7RUFDWixnQkFBZTtFQUNmLG1CQUFrQixFQVFyQjtFQVhEO0lBTVEsa0JBQWlCLEVBSXBCO0VBVkw7TUFRWSxZQUFXLEVBQ2QiLCJmaWxlIjoic3JjL2FwcC93b3Jrc3BhY2UvdW5pdC1wcm9wZXJ0eS1wYW5lbC91bml0LXByb3BlcnR5LXBhbmVsLmNvbXBvbmVudC5zY3NzIiwic291cmNlc0NvbnRlbnQiOlsiLndyYXBwZXItLXByb3BlcnR5LS1wYW5lbCB7XHJcbiAgICBkaXNwbGF5OiBub25lO1xyXG4gICAgcG9zaXRpb246IGFic29sdXRlO1xyXG4gICAgdG9wOiAwO1xyXG4gICAgbGVmdDogMDtcclxuICAgIGJhY2tncm91bmQtY29sb3I6IHJnYmEoMjU1LCAyNTUsIDI1NSwgMC44OCk7XHJcbiAgICBib3JkZXI6IDFweCBzb2xpZCAjNjY2O1xyXG4gICAgei1pbmRleDogMTAwMDAwMTtcclxuICAgIHBhZGRpbmc6IDhweDtcclxuXHJcbiAgICAmLnNob3cge1xyXG4gICAgICAgIGRpc3BsYXk6IGJsb2NrO1xyXG4gICAgfVxyXG59XHJcblxyXG4ucHJvcGVydHkubmFtZSB7XHJcbiAgICBmb250LXNpemU6IDIycHg7XHJcbiAgICBmb250LWZhbWlseTogQXJpYWw7XHJcbn1cclxuXHJcbnRhYmxlIHtcclxuICAgIHdpZHRoOiAxNDBweDtcclxuICAgIG1hcmdpbi10b3A6IDhweDtcclxuICAgIGZvbnQtZmFtaWx5OiBBcmlhbDtcclxuXHJcbiAgICB0ZCB7XHJcbiAgICAgICAgdGV4dC1hbGlnbjogcmlnaHQ7XHJcbiAgICAgICAgaW5wdXQsIHNlbGVjdCB7XHJcbiAgICAgICAgICAgIHdpZHRoOiA4MHB4O1xyXG4gICAgICAgIH1cclxuICAgIH1cclxufSJdfQ== */"

/***/ }),

/***/ "./src/app/workspace/unit-property-panel/unit-property-panel.component.ts":
/*!********************************************************************************!*\
  !*** ./src/app/workspace/unit-property-panel/unit-property-panel.component.ts ***!
  \********************************************************************************/
/*! exports provided: UnitPropertyPanelComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UnitPropertyPanelComponent", function() { return UnitPropertyPanelComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! src/app/services/services.module */ "./src/app/services/services.module.ts");
/* harmony import */ var src_app_services_zrender_helper_service__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! src/app/services/zrender-helper.service */ "./src/app/services/zrender-helper.service.ts");
/* harmony import */ var src_app_services_store_service__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! src/app/services/store.service */ "./src/app/services/store.service.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};




var UnitPropertyPanelComponent = /** @class */ (function () {
    function UnitPropertyPanelComponent(globalOperatorSrv, zrenderHelperSrv, codeEditorSrv, storeSrv) {
        this.globalOperatorSrv = globalOperatorSrv;
        this.zrenderHelperSrv = zrenderHelperSrv;
        this.codeEditorSrv = codeEditorSrv;
        this.storeSrv = storeSrv;
        this.offsetX = 40;
        this.offsetY = 520;
        // unit参数
        this.unit = {
            port: 'A',
            default: ['A', 'B', 'C']
        };
        this.selectedUnit$ = this.globalOperatorSrv.getSelectedUnit();
    }
    UnitPropertyPanelComponent.prototype.ngOnInit = function () {
        var _this_1 = this;
        var _this = this;
        this.globalOperatorSrv.getSelectedUnit().subscribe(function (unit) {
            if (unit === null)
                return;
            _this.unit = unit;
            var fixY = _this_1.zrenderHelperSrv.scaleRatio === 1 ? 10 : 20;
            _this_1.wrapperPropertyPanel.nativeElement.style.left = (unit.unitSvg.position[0] + _this_1.offsetX + 10 - 0) * _this_1.zrenderHelperSrv.scaleRatio + 'px';
            _this_1.wrapperPropertyPanel.nativeElement.style.top = (unit.unitSvg.position[1] + _this_1.offsetY + 128 - 30) * _this_1.zrenderHelperSrv.scaleRatio + fixY + 'px';
        });
        this.storeSrv.getType().subscribe(function (res) {
            _this_1.iscore = (res == 'core') ? true : false;
            _this_1.globalOperatorSrv.getSelectedUnit().subscribe(function (unit) {
                if (unit === null)
                    return;
                unit.new_port = (res == 'core') ? unit.port : 'A';
                unit.new_default = (res == 'core') ? unit.default : ['A'];
                _this.unit = unit;
                var fixY = _this_1.zrenderHelperSrv.scaleRatio === 1 ? 10 : 20;
                _this_1.wrapperPropertyPanel.nativeElement.style.left = (unit.unitSvg.position[0] + _this_1.offsetX + 10 - 0) * _this_1.zrenderHelperSrv.scaleRatio + 'px';
                _this_1.wrapperPropertyPanel.nativeElement.style.top = (unit.unitSvg.position[1] + _this_1.offsetY + 128 - 30) * _this_1.zrenderHelperSrv.scaleRatio + fixY + 'px';
            });
        });
    };
    UnitPropertyPanelComponent.prototype.stopPropagation = function (ev) {
        ev.stopPropagation();
    };
    UnitPropertyPanelComponent.prototype.setUnitPort = function (ev) {
        this.globalOperatorSrv.selectedUnit.value.port = ev.target.value;
        if (!this.globalOperatorSrv.codeLock.value) {
            this.codeEditorSrv.updateWorkspaceValue();
        }
    };
    UnitPropertyPanelComponent.prototype.setUnitCount = function (ev) {
        var count = ev.target.value;
        if (count !== '') {
            this.globalOperatorSrv.selectedUnit.value.count = +count;
        }
        if (!this.globalOperatorSrv.codeLock.value) {
            this.codeEditorSrv.updateWorkspaceValue();
        }
    };
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ViewChild"])('wrapperPropertyPanel'),
        __metadata("design:type", _angular_core__WEBPACK_IMPORTED_MODULE_0__["ElementRef"])
    ], UnitPropertyPanelComponent.prototype, "wrapperPropertyPanel", void 0);
    UnitPropertyPanelComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-unit-property-panel',
            template: __webpack_require__(/*! ./unit-property-panel.component.html */ "./src/app/workspace/unit-property-panel/unit-property-panel.component.html"),
            styles: [__webpack_require__(/*! ./unit-property-panel.component.scss */ "./src/app/workspace/unit-property-panel/unit-property-panel.component.scss")]
        }),
        __metadata("design:paramtypes", [src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__["GlobalOperatorService"],
            src_app_services_zrender_helper_service__WEBPACK_IMPORTED_MODULE_2__["ZrenderHelperService"],
            src_app_services_services_module__WEBPACK_IMPORTED_MODULE_1__["CodeEditorService"],
            src_app_services_store_service__WEBPACK_IMPORTED_MODULE_3__["StoreService"]])
    ], UnitPropertyPanelComponent);
    return UnitPropertyPanelComponent;
}());



/***/ }),

/***/ "./src/app/workspace/workspace.component.html":
/*!****************************************************!*\
  !*** ./src/app/workspace/workspace.component.html ***!
  \****************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"wrapper workspace\">\r\n  <ng-container *ngIf=\"!stack; else elseTemplate\">\r\n      <div class=\"wrapper--ui-editor\">\r\n          <app-ui-editor></app-ui-editor>\r\n        </div>\r\n  </ng-container>\r\n  <ng-template #elseTemplate>\r\n    <div class=\"wrapper--ui-editor-mb\" [class.ui-editor-hide]=\"ismb\" [class.ui-editor-show]=\"!ismb\">\r\n        <app-ui-editor-mb></app-ui-editor-mb>\r\n    </div>\r\n  </ng-template>\r\n\r\n  <div class=\"wrapper--logic-editor\">\r\n    <app-blockly-editor [class.active]=\"(mode$ | async) == 'blockly'\"></app-blockly-editor>\r\n    <app-code-editor [class.active]=\"(mode$ | async) == 'code'\"></app-code-editor>\r\n  </div>\r\n  <!-- <h2>wocaooojkjkasjdkj1</h2> -->\r\n</div>\r\n<app-loading *ngIf=\"loddingMode\"></app-loading>\r\n<div class=\"alert_position\">\r\n  <app-alert_blockly #alert></app-alert_blockly>\r\n</div>\r\n\r\n\r\n"

/***/ }),

/***/ "./src/app/workspace/workspace.component.scss":
/*!****************************************************!*\
  !*** ./src/app/workspace/workspace.component.scss ***!
  \****************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".wrapper.workspace {\n  display: flex;\n  flex-direction: row;\n  height: 100%; }\n\n.wrapper--logic-editor {\n  display: flex;\n  width: 100%; }\n\n.wrapper--ui-editor-mb {\n  display: flex; }\n\n.ui-editor-show {\n  min-width: 100%; }\n\n.ui-editor-hide {\n  max-width: 0; }\n\napp-ui-editor-mb {\n  width: 100%; }\n\napp-code-editor,\napp-blockly-editor {\n  width: 0;\n  height: 100%; }\n\napp-code-editor {\n  display: none; }\n\napp-code-editor.active,\napp-blockly-editor.active {\n  flex: 1; }\n\napp-code-editor.active {\n  display: block; }\n\n.alert_position {\n  position: fixed;\n  z-index: 100;\n  top: 38%;\n  right: 0;\n  max-width: 300px;\n  max-height: 300px;\n  background-color: var(--bg-color);\n  border-radius: 10px;\n  box-shadow: 20px;\n  opacity: 0.85;\n  overflow: hidden; }\n\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvd29ya3NwYWNlL1o6XFx3b3Jrc3BhY2VcXG15X3pyZW5kZXJcXGZsb3cvc3JjXFxhcHBcXHdvcmtzcGFjZVxcd29ya3NwYWNlLmNvbXBvbmVudC5zY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUFBO0VBQ0ksY0FBYTtFQUNiLG9CQUFtQjtFQUNuQixhQUFZLEVBQ2Y7O0FBRUQ7RUFDSSxjQUFhO0VBQ2IsWUFBVyxFQUNkOztBQUVEO0VBQ0ksY0FBYSxFQUNoQjs7QUFDRDtFQUNJLGdCQUFlLEVBRWxCOztBQUNEO0VBQ0ksYUFBWSxFQUNmOztBQUNEO0VBQ0ksWUFBVyxFQUNkOztBQUNEOztFQUVJLFNBQVE7RUFDUixhQUFZLEVBQ2Y7O0FBRUQ7RUFDSSxjQUFhLEVBQ2hCOztBQUVEOztFQUdRLFFBQU8sRUFDVjs7QUFHTDtFQUVRLGVBQWMsRUFDakI7O0FBR0w7RUFDSSxnQkFBZTtFQUNmLGFBQVk7RUFDWixTQUFPO0VBQ1AsU0FBTztFQUNQLGlCQUFnQjtFQUVoQixrQkFBaUI7RUFFakIsa0NBQWdDO0VBQ2hDLG9CQUFrQjtFQUNsQixpQkFBZ0I7RUFDaEIsY0FBYTtFQUNiLGlCQUFnQixFQUNuQiIsImZpbGUiOiJzcmMvYXBwL3dvcmtzcGFjZS93b3Jrc3BhY2UuY29tcG9uZW50LnNjc3MiLCJzb3VyY2VzQ29udGVudCI6WyIud3JhcHBlci53b3Jrc3BhY2Uge1xyXG4gICAgZGlzcGxheTogZmxleDtcclxuICAgIGZsZXgtZGlyZWN0aW9uOiByb3c7XHJcbiAgICBoZWlnaHQ6IDEwMCU7XHJcbn1cclxuXHJcbi53cmFwcGVyLS1sb2dpYy1lZGl0b3Ige1xyXG4gICAgZGlzcGxheTogZmxleDsgLy8gZmxleC1kaXJlY3Rpb246IGNvbHVtbjtcclxuICAgIHdpZHRoOiAxMDAlO1xyXG59XHJcblxyXG4ud3JhcHBlci0tdWktZWRpdG9yLW1iIHtcclxuICAgIGRpc3BsYXk6IGZsZXg7XHJcbn1cclxuLnVpLWVkaXRvci1zaG93IHtcclxuICAgIG1pbi13aWR0aDogMTAwJTtcclxuICAgIFxyXG59XHJcbi51aS1lZGl0b3ItaGlkZSB7XHJcbiAgICBtYXgtd2lkdGg6IDA7XHJcbn1cclxuYXBwLXVpLWVkaXRvci1tYntcclxuICAgIHdpZHRoOiAxMDAlO1xyXG59XHJcbmFwcC1jb2RlLWVkaXRvcixcclxuYXBwLWJsb2NrbHktZWRpdG9yIHtcclxuICAgIHdpZHRoOiAwO1xyXG4gICAgaGVpZ2h0OiAxMDAlOyAvLyBkaXNwbGF5OiBub25lO1xyXG59XHJcblxyXG5hcHAtY29kZS1lZGl0b3Ige1xyXG4gICAgZGlzcGxheTogbm9uZTtcclxufVxyXG5cclxuYXBwLWNvZGUtZWRpdG9yLFxyXG5hcHAtYmxvY2tseS1lZGl0b3Ige1xyXG4gICAgJi5hY3RpdmUge1xyXG4gICAgICAgIGZsZXg6IDE7XHJcbiAgICB9XHJcbn1cclxuXHJcbmFwcC1jb2RlLWVkaXRvciB7XHJcbiAgICAmLmFjdGl2ZSB7XHJcbiAgICAgICAgZGlzcGxheTogYmxvY2s7XHJcbiAgICB9XHJcbn1cclxuXHJcbi5hbGVydF9wb3NpdGlvbntcclxuICAgIHBvc2l0aW9uOiBmaXhlZDs7XHJcbiAgICB6LWluZGV4OiAxMDA7XHJcbiAgICB0b3A6MzglO1xyXG4gICAgcmlnaHQ6MDtcclxuICAgIG1heC13aWR0aDogMzAwcHg7XHJcbiAgICAvLyBtaW4td2lkdGg6IDE1MHB4O1xyXG4gICAgbWF4LWhlaWdodDogMzAwcHg7XHJcbiAgICAvLyBtaW4taGVpZ2h0OiAxMDBweDtcclxuICAgIGJhY2tncm91bmQtY29sb3I6dmFyKC0tYmctY29sb3IpOyBcclxuICAgIGJvcmRlci1yYWRpdXM6MTBweDsgXHJcbiAgICBib3gtc2hhZG93OiAyMHB4O1xyXG4gICAgb3BhY2l0eTogMC44NTtcclxuICAgIG92ZXJmbG93OiBoaWRkZW47XHJcbn0iXX0= */"

/***/ }),

/***/ "./src/app/workspace/workspace.component.ts":
/*!**************************************************!*\
  !*** ./src/app/workspace/workspace.component.ts ***!
  \**************************************************/
/*! exports provided: WorkspaceComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "WorkspaceComponent", function() { return WorkspaceComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _services_services_module__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../services/services.module */ "./src/app/services/services.module.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};


var WorkspaceComponent = /** @class */ (function () {
    function WorkspaceComponent(globalOperatorSrv, storeSrv) {
        this.globalOperatorSrv = globalOperatorSrv;
        this.storeSrv = storeSrv;
        this.loddingMode = true;
        this.ismb = true;
        this.stack = false;
    }
    WorkspaceComponent.prototype.ngOnInit = function () {
        var _this = this;
        if (/Android|webOS|iPhone|BlackBerry/i.test(navigator.userAgent)) {
            this.stack = true;
        }
        this.mode$ = this.globalOperatorSrv.getMode();
        this.setlodding();
        this.storeSrv.getuiMode().subscribe(function (res) {
            _this.ismb = res;
            //  if (/iPad|iPod/i.test(navigator.userAgent)) {
            //   this.ismb = false;
            //  }
        });
    };
    WorkspaceComponent.prototype.setlodding = function () {
        var _this = this;
        this.storeSrv.setLoddingMode().subscribe(function (mode) {
            _this.loddingMode = mode;
        });
    };
    WorkspaceComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-workspace',
            template: __webpack_require__(/*! ./workspace.component.html */ "./src/app/workspace/workspace.component.html"),
            styles: [__webpack_require__(/*! ./workspace.component.scss */ "./src/app/workspace/workspace.component.scss")]
        }),
        __metadata("design:paramtypes", [_services_services_module__WEBPACK_IMPORTED_MODULE_1__["GlobalOperatorService"], _services_services_module__WEBPACK_IMPORTED_MODULE_1__["StoreService"]])
    ], WorkspaceComponent);
    return WorkspaceComponent;
}());



/***/ }),

/***/ "./src/app/workspace/workspace.module.ts":
/*!***********************************************!*\
  !*** ./src/app/workspace/workspace.module.ts ***!
  \***********************************************/
/*! exports provided: WorkspaceModule */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "WorkspaceModule", function() { return WorkspaceModule; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _shared_shared_module__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../shared/shared.module */ "./src/app/shared/shared.module.ts");
/* harmony import */ var ngx_color_picker__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ngx-color-picker */ "./node_modules/ngx-color-picker/dist/ngx-color-picker.es5.js");
/* harmony import */ var _ui_editor_ui_editor_component__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./ui-editor/ui-editor.component */ "./src/app/workspace/ui-editor/ui-editor.component.ts");
/* harmony import */ var _blockly_editor_blockly_editor_component__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ./blockly-editor/blockly-editor.component */ "./src/app/workspace/blockly-editor/blockly-editor.component.ts");
/* harmony import */ var _code_editor_code_editor_component__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ./code-editor/code-editor.component */ "./src/app/workspace/code-editor/code-editor.component.ts");
/* harmony import */ var _workspace_component__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./workspace.component */ "./src/app/workspace/workspace.component.ts");
/* harmony import */ var _property_panel_property_panel_component__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ./property-panel/property-panel.component */ "./src/app/workspace/property-panel/property-panel.component.ts");
/* harmony import */ var _property_item_property_item_component__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! ./property-item/property-item.component */ "./src/app/workspace/property-item/property-item.component.ts");
/* harmony import */ var _unit_modal_unit_modal_component__WEBPACK_IMPORTED_MODULE_9__ = __webpack_require__(/*! ./unit-modal/unit-modal.component */ "./src/app/workspace/unit-modal/unit-modal.component.ts");
/* harmony import */ var _unit_property_panel_unit_property_panel_component__WEBPACK_IMPORTED_MODULE_10__ = __webpack_require__(/*! ./unit-property-panel/unit-property-panel.component */ "./src/app/workspace/unit-property-panel/unit-property-panel.component.ts");
/* harmony import */ var _ui_editor_mb_ui_editor_mb_component__WEBPACK_IMPORTED_MODULE_11__ = __webpack_require__(/*! ./ui-editor-mb/ui-editor-mb.component */ "./src/app/workspace/ui-editor-mb/ui-editor-mb.component.ts");
/* harmony import */ var _alert_blockly_alert_blockly__WEBPACK_IMPORTED_MODULE_12__ = __webpack_require__(/*! ./alert_blockly/alert_blockly */ "./src/app/workspace/alert_blockly/alert_blockly.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};













var WorkspaceModule = /** @class */ (function () {
    function WorkspaceModule() {
    }
    WorkspaceModule = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["NgModule"])({
            imports: [
                _shared_shared_module__WEBPACK_IMPORTED_MODULE_1__["SharedModule"],
                ngx_color_picker__WEBPACK_IMPORTED_MODULE_2__["ColorPickerModule"]
            ],
            declarations: [_alert_blockly_alert_blockly__WEBPACK_IMPORTED_MODULE_12__["Alert_Blockly"], _ui_editor_ui_editor_component__WEBPACK_IMPORTED_MODULE_3__["UiEditorComponent"], _blockly_editor_blockly_editor_component__WEBPACK_IMPORTED_MODULE_4__["BlocklyEditorComponent"], _code_editor_code_editor_component__WEBPACK_IMPORTED_MODULE_5__["CodeEditorComponent"], _workspace_component__WEBPACK_IMPORTED_MODULE_6__["WorkspaceComponent"], _property_panel_property_panel_component__WEBPACK_IMPORTED_MODULE_7__["PropertyPanelComponent"], _property_item_property_item_component__WEBPACK_IMPORTED_MODULE_8__["PropertyItemComponent"], _unit_modal_unit_modal_component__WEBPACK_IMPORTED_MODULE_9__["UnitModalComponent"], _unit_property_panel_unit_property_panel_component__WEBPACK_IMPORTED_MODULE_10__["UnitPropertyPanelComponent"], _ui_editor_mb_ui_editor_mb_component__WEBPACK_IMPORTED_MODULE_11__["UiEditorMbComponent"]],
            exports: [_workspace_component__WEBPACK_IMPORTED_MODULE_6__["WorkspaceComponent"]],
            schemas: [_angular_core__WEBPACK_IMPORTED_MODULE_0__["NO_ERRORS_SCHEMA"]]
        })
    ], WorkspaceModule);
    return WorkspaceModule;
}());



/***/ }),

/***/ "./src/environments/environment.ts":
/*!*****************************************!*\
  !*** ./src/environments/environment.ts ***!
  \*****************************************/
/*! exports provided: environment */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "environment", function() { return environment; });
// This file can be replaced during build by using the `fileReplacements` array.
// `ng build --prod` replaces `environment.ts` with `environment.prod.ts`.
// The list of file replacements can be found in `angular.json`.
var environment = {
    production: false,
    apiUrl: 'http://localhost:39809/api'
};
/*
 * For easier debugging in development mode, you can import the following file
 * to ignore zone related error stack frames such as `zone.run`, `zoneDelegate.invokeTask`.
 *
 * This import should be commented out in production mode because it will have a negative impact
 * on performance if an error is thrown.
 */
// import 'zone.js/dist/zone-error';  // Included with Angular CLI.


/***/ }),

/***/ "./src/main.ts":
/*!*********************!*\
  !*** ./src/main.ts ***!
  \*********************/
/*! no exports provided */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_platform_browser_dynamic__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/platform-browser-dynamic */ "./node_modules/@angular/platform-browser-dynamic/fesm5/platform-browser-dynamic.js");
/* harmony import */ var _app_app_module__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./app/app.module */ "./src/app/app.module.ts");
/* harmony import */ var _environments_environment__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./environments/environment */ "./src/environments/environment.ts");




if (_environments_environment__WEBPACK_IMPORTED_MODULE_3__["environment"].production) {
    Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["enableProdMode"])();
}
Object(_angular_platform_browser_dynamic__WEBPACK_IMPORTED_MODULE_1__["platformBrowserDynamic"])().bootstrapModule(_app_app_module__WEBPACK_IMPORTED_MODULE_2__["AppModule"])
    .catch(function (err) { return console.error(err); });


/***/ }),

/***/ 0:
/*!***************************!*\
  !*** multi ./src/main.ts ***!
  \***************************/
/*! no static exports found */
/***/ (function(module, exports, __webpack_require__) {

module.exports = __webpack_require__(/*! Z:\workspace\my_zrender\flow\src\main.ts */"./src/main.ts");


/***/ })

},[[0,"runtime","vendor"]]]);
//# sourceMappingURL=main.js.map