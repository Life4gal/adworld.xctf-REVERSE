#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4706&page=1
 * 原题为同目录下的 parallel-comparator-200.c
 */

int main()
{
	constexpr int FLAG_LEN = 20;
	constexpr char differences[FLAG_LEN] = { 0, 9, -9, -1, 13, -13, -4, -11, -9, -1, -7, 6, -13, 13, 3, 9, -13, -11, 6, -7 };
	// (first_letter + differences[i]) ^ user_string[i] = 0
	// constexpr int just_a_string[FLAG_LEN] = { 115, 116, 114, 97, 110, 103, 101, 95, 115, 116, 114, 105, 110, 103, 95, 105, 116, 95, 105, 115 };
	// just_a_string = "strange_string_it_is"

	// 经测试,由于随机数产生器没有给种子,所以固定是 108
	constexpr auto first_letter = 108;
	char user_string[FLAG_LEN + 1] = { '\0' };

	for(int i = 0; i < FLAG_LEN; ++i)
	{
		user_string[i] = static_cast<char>(first_letter + static_cast<int>(differences[i]) ^ 0);
	}

	std::cout << user_string << std::endl;
}
