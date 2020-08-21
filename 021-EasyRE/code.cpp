#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5446&page=1
 * 原题为同目录下的 EasyRE.exe, IDA 输出文件见 EasyRE.idb
 */

int main()
{
	char flag[] = "xIrCj~<r|2tWsv3PtI\x7Fzndka";

	// 这里好像对结束字符处理有问题,导致出现了个不需要的 [](类似'\v',好像是^E),去掉即可
	for (char& i : flag)
	{
		i = static_cast<char>((i ^ 6) - 1);
	}
	
	std::reverse(std::begin(flag), std::end(flag));
	
	for(char c : flag)
	{
		std::cout << c;
	}
}
