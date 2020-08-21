#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5570&page=1
 * 原题为同目录下的 流浪者.rar 或 cm.exe, IDA 输出文件见 cm.idb
 */

int main()
{
	constexpr char mask[63] = "abcdefghiABCDEFGHIJKLMNjklmn0123456789opqrstuvwxyzOPQRSTUVWXYZ";
	constexpr char password[26] = "KanXueCTF2019JustForhappy";
	const auto begin = std::begin(mask);
	const auto end = std::end(mask);
	const auto maskBegin = std::begin(mask);
	

	int flag[26] = { '\0' };
	
	for(auto i = 0; i < 25; ++i)
	{
		// 找到password当前字符在mask中出现的位置并取得那个字符
		// 我们直接用int储存也不要紧,避免紧缩(虽然也不会发生
		int& c = flag[i] = static_cast<int>(std::find(begin, end, password[i]) - maskBegin);

		// 在外层函数还有一层处理
		// 最外层
		if(c + '0' >= '0' && c + '0' <= '9')
		{
			c += '0'; // 48
		}
		// 第二层
		else if(c + 'W' >= 'a' && c + 'W' <= 'z')
		{
			c += 'W'; // 87
		}
		// 最内层
		else if(c + 29 >= 'A' && c + 29 <= 'Z')
		{
			c += 29;
		}
	}

	for(auto i : flag)
	{
		// 作为 char 输出
		std::cout << char(i);
	}
}
