const fs = require('fs');

const languges = ['es', 'ja', 'ko', 'ru', 'th', 'zh-hans', 'de'];

// let added_json = {};
//for (x in myObj)
// 根据键名将en.json同步至其余语言包
function sync() {
	let en = JSON.parse(fs.readFileSync(`en.json`).toString());
	for (const keys in languges) {
		let json = JSON.parse(fs.readFileSync(`${languges[keys]}.json`).toString());
		for (let key in en) {
			if (key in json) {
				continue;
			} else {
				json[key] = en[key];
				console.log(json[key])
			}
		}
		fs.writeFileSync(`${languges[keys]}.json`, JSON.stringify(json));
	};
}

// 获取几个语言包的长度length
function getlength() {
	var ja_req = /[\u3040-\u309F\u30A0-\u30FF]/;
	const languges = ['es', 'ja', 'ko', 'ru', 'th', 'zh-hans'];
	let en = JSON.parse(fs.readFileSync(`en.json`).toString());
	let es = JSON.parse(fs.readFileSync(`es.json`).toString());
	let ja = JSON.parse(fs.readFileSync(`ja.json`).toString());
	let ko = JSON.parse(fs.readFileSync(`ko.json`).toString());
	let ru = JSON.parse(fs.readFileSync(`ru.json`).toString());
	let th = JSON.parse(fs.readFileSync(`th.json`).toString());
	let zh_hans = JSON.parse(fs.readFileSync(`zh-hans.json`).toString());
	// 咱村keyarr
	keyarr = [];
	// languges.forEach(lang => {
	// 	let json = JSON.parse(fs.readFileSync(`${lang}.json`).toString());
	// 	var ary = Object.keys(json);
	// 	var nary = ary.sort();
	// 	for (var i = 0; i < ary.length; i++) {
	// 		if (nary[i] == nary[i + 1]) {
	// 			console.log("数组重复内容：" + nary[i]);
	// 		} else {

	// 		}
	// 	}
	// });
	// console.log(ary)
	console.log(Object.keys(en).length)
	console.log(Object.keys(es).length)
	console.log(Object.keys(ja).length)
	console.log(Object.keys(ko).length)
	console.log(Object.keys(ru).length)
	console.log(Object.keys(th).length)
	console.log(Object.keys(zh_hans).length)
}

// 根据键名获取值对比其余同键名的值 根据 %切开 对比%数量  若不同于en.json则后续跟上xxxxxxxxxxx以便手动修改
function reduced_val() {
	let en = JSON.parse(fs.readFileSync(`en.json`).toString());
	for (const keys in languges) {
		let json = JSON.parse(fs.readFileSync(`${languges[keys]}.json`).toString());
		for (let key in en) {
			if (key in json) {
				var en_len = 0;
				var json_len = 0;
				if(typeof(en[key])!=='string'){continue;}
				if (en[key].indexOf('%') !== -1) {
					en_len = en[key].split('%').length
				}
				if (json[key].indexOf('%') !== -1) {
					json_len=json[key].split('%').length
				}
				if (en_len !== json_len) {
					console.log('1' + json[key])
					json[key] = en[key]
				}
				continue;
			} else {
				console.log('1' + json[key])
				json[key] = en[key];
			}
		}
		fs.writeFileSync(`${languges[keys]}.json`, JSON.stringify(json));
	};
}
// 根据键名获取值对比其余同键名的值 根据 %切开 对比%数量  若不同于en.json则后续跟上xxxxxxxxxxx以便手动修改
// reduced_val()
// 根据键名将en.json同步至其余语言包
// sync()
reduced_val()
// 获取几个语言包的长度length
getlength()