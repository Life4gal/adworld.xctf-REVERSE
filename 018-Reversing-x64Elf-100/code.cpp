#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4826&page=1
 * 原题为同目录下的 Reversing-x64Elf-100.re, IDA 输出文件见 Reversing-x64Elf-100.i64
 */

int main()
{
	char password[3][8] = { "Dufhbmf" , "pG`imos" , "ewUglpt" };
	
	char flag[13] = { '\0' };

	for(int i = 0; i <= 11; ++i)
	{
		flag[i] = static_cast<char>(password[i % 3][2 * (i / 3)] - 1);
	}

	std::cout << flag << std::endl;
}
