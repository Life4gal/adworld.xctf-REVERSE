#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4590&page=1
 * 原题为同目录下的 IgniteMe.exe, IDA 输出文件见 IgniteMe.idb
 */

int main()
{
	char mask[] =
	{
	   13,  19,  23,  17,   2,   1,  32,  29,  12,   2,
	   25,  47,  23,  43,  36,  31,  30,  22,   9,  15,
	   21,  39,  19,  38,  10,  47,  30,  26,  45,  12,
	   34,   4
	};

	char sequence[25] = "GONDPHyGjPEKruv{{pj]X@rF";

	char flag[25] = { '\0' };
	
	for(int i = 0; i < 24; ++i)
	{
		char tmp = static_cast<char>((mask[i] ^ sequence[i]) - 72 ^ 85);
		// 这里他对内容进行了处理,我们需要对字母转为小写,非字母则保持不变
		if(tmp >= 'A' && tmp <= 'Z')
		{
			tmp += 32;
		}
		flag[i] = tmp;
	}

	std::cout << "EIS{" << flag << "}" << std::endl;
}
