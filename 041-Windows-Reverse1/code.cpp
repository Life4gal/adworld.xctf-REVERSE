#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5514&page=3
 */

int main()
{
	// byte_402ff8 -> byte_403018 相差 32 字节,我们无法确定内容,但是加上32偏移即可
	// 由于有一些特殊符号,使用 R"()" 来无视特殊符号
    constexpr char byte_403018[] = R"(~}|{zyxwvutsrqponmlkjihgfedcba`_^]\[ZYXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:9876543210/.-,+*)(',27h,'&%$#"!)";
    constexpr char compare[] = "DDCTF{reverseME}";
	char flag[17] = { '\0' };

	
	for(int i = 0; i < 16; ++i)
	{
		flag[i] = char(std::find(std::begin(byte_403018), std::end(byte_403018), compare[i]) - std::begin(byte_403018) + 32);
	}

	std::cout << "flag{" << flag << "}" << std::endl;
}
