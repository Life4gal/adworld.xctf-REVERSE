#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4881&page=1
 * 原题为同目录下的 hackme , IDA分析文件为 hackme.i64
 */

int main()
{
	// 22字节有效数据
	unsigned char mask[] =
	{
		0x5F, 0xF2, 0x5E, 0x8B,
		0x4E, 0x0E, 0xA3, 0xAA,
		0xC7, 0x93,0x81, 0x3D,
		0x5F, 0x74, 0xA3, 0x09,
		0x91, 0x2B, 0x49, 0x28,
		0x93, 0x67, 0x00, 0x00
	};
	// 密码长度
	constexpr int passwordLength = 22;
	// 密码
	unsigned char password[passwordLength];
	for(int i = 0; i < passwordLength; ++i)
	{
		const unsigned char maskNum = mask[i];
		
		int compareNum = 0;
		for(int j = 0; j <= i; ++j)
		{
			compareNum = 1828812941 * compareNum + 12345;
		}
		// 要让 maskNum == (compareNum ^ passwordNum) 
		// 即 passwordNum == compareNum ^ maskNum
		password[i] = compareNum ^ maskNum;
		
	}

	for (const unsigned char i : password)
	{
		// 直接打印有乱码
		printf("%c", i);
	}
}
