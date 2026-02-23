const fs = require('fs');

const languges = [ 'es', 'ja', 'ko', 'ru', 'th', 'zh-hans'];

// let added_json = {};
//for (x in myObj)
	 let en = JSON.parse(fs.readFileSync(`en.json`).toString());
 for(let key in en) {
	 languges.forEach(lang => {
    let json = JSON.parse(fs.readFileSync(`${lang}.json`).toString());
	if(key in json){
	return false;
	}else{
	json.key=en[key];
	// console.log(key)
	}

});
 }
