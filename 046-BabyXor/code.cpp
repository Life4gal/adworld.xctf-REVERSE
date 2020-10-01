#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5575&page=3
 * 原题为同目录下的 babyXor.exe 脱壳程序见 babyXor_dump.exe IDA输出文件见 babyXor_dump.idb
 */

int main()
{
    constexpr int unk_435DC0[14] =
    {
		102, 109, 99, 100, 127,   
		55, 53, 48, 48, 107,   
		58, 60, 59, 32,  
    };

    constexpr int dword_435DF8[14] =
    {
        0x37, 0x6f, 0x38, 0x62, 0x36,
    	0x7c, 0x37, 0x33, 0x34, 0x76,
    	0x33, 0x62, 0x64, 0x7a
    };

    constexpr int dword_435E30[14] =
    {
    	0x1a, 0x00, 0x00, 0x51, 0x05,
    	0x11, 0x54, 0x56, 0x55, 0x59,
    	0x1d, 0x09, 0x5d, 0x12
    };

    int v1[14];
	for(int i = 0; i < 14; ++i)
	{
        v1[i] = unk_435DC0[i] ^ i;
	}

    int v2[14];
    v2[0] = dword_435DF8[0];
	for(int i = 1; i < 14; ++i)
	{
        v2[i] = unk_435DC0[i] ^ dword_435DF8[i] ^ unk_435DC0[i - 1];
	}

    int v5[14];
    v5[0] = dword_435E30[0] ^ dword_435DF8[0];
	for(int i = 1; i < 14; ++i)
	{
		// 这里使用 j 是因为 v5 是 dword_435E30[0] ^ dword_435DF8[0] 与 后面的数据拼接而来的,所以这里的运算要从 0 开始
        const int j = i - 1;
        v5[i] = (dword_435E30[j + 1] ^ v2[j]) ^ j;
	}

	for(auto i : v1)
	{
        std::cout << char(i);
	}
    for (auto i : v2)
    {
        std::cout << char(i);
    }
    for (auto i : v5)
    {
        std::cout << char(i);
    }
}
