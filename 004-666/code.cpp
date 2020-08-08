#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5573&page=1
 * 原题为同目录下的 666.zip 或 666 , IDA分析文件为 666.i64
 */

constexpr int Length = 18;

// 加密的
void Encode(const int* source, char* dest)
{
	for (int i = 0; i < Length; i += 3)
	{
		dest[i] =		static_cast<char>((Length ^ source[i]) + 6);
		dest[i + 1] =	static_cast<char>((Length ^ source[i + 1]) - 6);
		dest[i + 2] =	static_cast<char>((Length ^ source[i + 2]) ^ 6);
	}
}

// 解密的
void Decode(const int* source, char* dest)
{
	for(int i = 0; i < Length; i += 3)
	{
		dest[i] =		static_cast<char>((Length ^ source[i]) - 6);
		dest[i + 1] =	static_cast<char>((Length ^ source[i + 1]) + 6);
		dest[i + 2] =	static_cast<char>((Length ^ source[i + 2]) ^ 6);
	}
}

int main()
{
	//constexpr char compareStr[Length + 1] = "izwhroz\"\"w\"v.K\".Ni";
	constexpr int compareStr[Length + 1] =
	{
		105, 122, 119, 104, 114, 111,
		122, 34, 34, 119,34, 118,
		46, 75, 34, 46, 78, 105,
		0
	};
	char flag[Length + 1];
	memset(flag, '\0', Length + 1);
	
	Decode(compareStr, flag);
	std::cout << flag << std::endl;
}
