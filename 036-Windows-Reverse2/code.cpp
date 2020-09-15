#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5507&page=2
 * 原题为同目录下的 _UnPacked.exe IDA输出文件为 _UnPacked.idb
 */

int main()
{
	// 这里只是为了证明的确是用的 base64 加密
    int byte_143020[] =
    {
       55,  52,  53,  50,  51,  48,  49,  62,  63,  60,
       61,  58,  59,  56,  57,  38,  39,  36,  37,  34,
       35,  32,  33,  46,  47,  44,  23,  20,  21,  18,
       19,  16,  17,  30,  31,  28,  29,  26,  27,  24,
       25,   6,   7,   4,   5,   2,   3,   0,   1,  14,
       15,  12,  70,  71,  68,  69,  66,  67,  64,  65,
       78,  79,  93,  89
    };

	// base64 标准密码表
	for(auto i : byte_143020)
	{
        std::cout << char(i ^ 0x76);
	}

    // C++ 实现 base64 还是算了吧
	// 上 python3 代码
	// 将字符串 "reverse+" 进行 base64 解密得到字节串,转为十六进制(其实就是把/x去掉),然后再转为大写(因为源程序中有判断若为字母则必须为 ABCDEF 其中之一)
	/*
		import base64
		print(base64.b64decode('reverse+').hex().upper())

		result: ADEBDEAEC7BE
	 */
	// 可恶,这偷懒的感觉竟然如此甜美...
}
