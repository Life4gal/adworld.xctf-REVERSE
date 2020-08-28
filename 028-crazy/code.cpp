#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5509&page=3
 * 原题为同目录下的 crazy, IDA 分析文件见 crazy.i64
 *
 * 由于没有进行脱壳,所以无法对程序进行 patch,具体见截图
 */

int main()
{
	char flag[33] = "327a6c4304ad5938eaf0efb6cc3e53dc";

	for(char& c : flag)
	{
		c = static_cast<char>((c - 11) ^ 0x13);
	}

	for(char& c : flag)
	{
		c = static_cast<char>((c - 23) ^ 0x50);
	}


	std::cout << "flag{";
	for(int i = 0; i < 32; ++i)
	{
		std::cout << flag[i];
	}
	std::cout << "}" << std::endl;
}
