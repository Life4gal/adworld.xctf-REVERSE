#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4966&page=2
 * 原题为同目录下的 crackme.exe
 *
 * 由于没有进行脱壳,所以无法对程序进行 patch,具体见截图
 */

int main()
{
	int mask[42] =
	{
		0x12 , 0x04 , 0x08 , 0x14 ,
		0x24 , 0x5C , 0x4A , 0x3D ,
		0x56 , 0x0A , 0x10 , 0x67 ,
		0x00 , 0x41 , 0x00 , 0x01 ,
		0x46 , 0x5A , 0x44 , 0x42 ,
		0x6E , 0x0C , 0x44 , 0x72 ,
		0x0C , 0x0D , 0x40 , 0x3E ,
		0x4B , 0x5F , 0x02 , 0x01 ,
		0x4C , 0x5E , 0x5B , 0x17 ,
		0x6E , 0x0C , 0x16 , 0x68 ,
		0x5B , 0x12
	};
	char sequence[17] = "this_is_not_flag";
	int flag[42];

	// 这是模拟两段字符逐个比较的汇编代码段
	// 其中 eax 是 mask & flag 的下标, ecx 是 sequence 的下标
	__asm
	{
		push eax
		push ecx

		xor eax, eax
	L1:
		mov ecx, eax
		and ecx, 0x8000000F		// 这个运算就相当于令 ecx 对 0xF(16) 取模
		jns L2
		dec ecx
		or ecx, 0xFFFFFFF0
		inc ecx
		// ecx = ?
	L2:
		inc eax
		cmp eax, 0x2A
		jnz L1

		pop eax
		pop ecx
	}
	
	for(int i = 0; i < 42; ++i)
	{
		flag[i] = mask[i] ^ sequence[i % 16];
	}

	for(int i : flag)
	{
		std::cout << char(i);
	}
}
