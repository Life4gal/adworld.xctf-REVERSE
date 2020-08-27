#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4662&page=2
 * 解题步骤见 解题步骤.md
 */

int main()
{
	int flag[14] =
	{
		102, 109, 99, 100, 127,
		107, 55, 100, 59, 86,
		96, 59, 110, 112
	};

	for(int i = 0; i <= 13; ++i)
	{
		std::cout << char(flag[i] ^ i);
	}
}
