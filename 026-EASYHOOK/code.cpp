#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4664&page=2
 * 原题为同目录下的 EASYHOOK.exe, IDA 输出文件见 EASYHOOK.idb
 */

int main()
{
	unsigned char flag[] =
	{
		97, 106, 121, 103, 107, 70, 109, 46, 127, 95,
		126, 45, 83, 86, 123, 56, 109, 76, 110, 0
	};

	flag[18] ^= 0x13;
	
	for(int i = 17; i >= 0; --i)
	{
		const auto v3 = static_cast<char>(i ^ flag[i]);
		if(i % 2)
		{
			flag[i] = v3 + i;
		}
		else
		{
			flag[i + 2] = v3;
		}
	}

	// 得到的结果是 alag{Ho0k_w1th_Fun}
	// 但其实 alag{Ho0k_w1th_Fun} 和 flag{Ho0k_w1th_Fun} 都是对的
	for(auto i : flag)
	{
		std::cout << i;
	}
}
