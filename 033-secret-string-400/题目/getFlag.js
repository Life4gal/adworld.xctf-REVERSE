/*
// 这是通过修改 Machine.js 中的 function run() 获得的
var f = window.machine.registers[1].userinput
var i = f.length 
var nonce = 'groke'; 
var j = 0; 
var out = []; 
var eq = true; 
while (j < i) { 
	out.push(f.charCodeAt(j) ^ nonce.charCodeAt(j % 5)) 
	j++; 
} 
var ex = [1, 30, 14, 12, 69, 14, 1, 85, 75, 50, 40, 37, 48, 24, 10, 56, 55, 46, 56, 60]; 
if (ex.length == out.length) { 
	j = 0; 
	while (j < ex.length) { 
		if (ex[j] != out[j]) 
			eq = false; 
		j += 1; 
	} 
	if (eq) { 
		alert('YOU WIN!'); 
	} else {
		alert('NOPE!');
	}
} else {
	alert('NOPE!');
} 
*/
function getFlag() {
	var nonce = 'groke';
	var ex = [1, 30, 14, 12, 69, 14, 1, 85, 75, 50, 40, 37, 48, 24, 10, 56, 55, 46, 56, 60];
	var flag = "";
	for (var j = 0; j < ex.length; ++j) {
		flag += String.fromCharCode(ex[j] ^ nonce[j % 5].charCodeAt());
	}
	alert(flag);
}
