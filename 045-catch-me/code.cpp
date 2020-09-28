#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4798&page=3
 * 原题为同目录下的 catch_me(XZ) -> catch_me~(tar) -> Catch_Me(ELF)
 */

int main()
{
    constexpr auto v0 = 0xb11924e1;
	
    // *(DWORD*)sub_4004C0("CTF") ^ v0 = -18088213 = 0xFEEBFEEB // 静态分析中sub_400C0符号名为 getenv
    constexpr auto sub_4004C0_CTF = 0xFEEBFEEB ^ v0;
    // sub_4004C0_CTF = 1341315594 = 0x 4f f2 da 0a

    // dword_4012AC 紧跟在 byte_6012AB 后面,推测属于同一个数组
    // dword_4012AC = *(DWORD*)sub_4004C0("ASIS")
    // 在试图暴力让
    // if ( sub_4004C0("ASIS") && (*(_DWORD *)sub_4004C0("CTF") ^ v0) == 0xFEEBFEEB )
    // 中的 sub_4004C0("ASIS") 判断通过后,继续允许得到警告
    // got SIGSEGV signal(Segmentation violation)
    // 即没办法进行到下一句 dword_6012AC = *(_DWORD *)sub_4004C0("ASIS"), 也无法获得 dword_6012AC
    // 猜测 sub_4004C0("ASIS") 可能和 sub_4004C0("CTF") 相等
	
    constexpr int byte_6012A8[8] =
    {
    	// v0
        0xb1, 0x19, 0x04, 0xa1,
    	// dword_6012AC
    	0x0a, 0xda, 0xf2, 0x4f
    };

    int xmmword_601280[] = // 静态分析中符号名为 haystack
    {
        // xmmword_601280 -> 0x 7C 80 EE 55 D4 34 60 EE 2D C2 B0 55 C5 34 29 87
        0x87, 0x29, 0x34, 0xc5, 0x55, 0xb0,
        0xc2, 0x2d, 0xee, 0x60, 0x34, 0xd4,
        0x55, 0xee, 0x80, 0x7c,

        // xmmword_601290 -> 0x 2B C1 ED 78 95 33 2C EE 79 9C EB 3D 96 37 2F EE
        0xee, 0x2f, 0x37, 0x96, 0x3d, 0xeb,
        0x9c, 0x79, 0xee, 0x2c, 0x33, 0x95,
        0x78, 0xed, 0xc1, 0x2b
    };

    for(int i = 0; i < 32; ++i)
    {
        xmmword_601280[i] ^= byte_6012A8[i & 7];
    }

    std::cout << "ASIS{";
    for(auto i : xmmword_601280)
    {
        std::cout << char(i);
    }
    std::cout << "}" << std::endl;;
}
