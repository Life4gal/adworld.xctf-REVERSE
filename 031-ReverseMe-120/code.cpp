#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4825&page=2
 * 原题为同目录下的 ReverseMe-120.exe, IDA 输出文件见 ReverseMe-120.idb
 */

int main()
{
	char flag[] = "you_know_how_to_remove_junk_code";

	for(size_t i = 0; i < strlen(flag); ++i)
	{
		flag[i] ^= 0x25;
	}

	std::cout << flag << std::endl;

	// 到 https://tool.oschina.net/encrypt?type=3 对flag进行base64编码即可得到结果
}
