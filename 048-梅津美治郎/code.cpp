#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5575&page=3
 * 原题为同目录下的 babyXor.exe 脱壳程序见 babyXor_dump.exe IDA输出文件见 babyXor_dump.idb
 */

int main()
{
    char doword_40AD98[] = "u1nnf2lg";

	// WTF, 我们永远也无法想象两串密码中间有个 _ 进行连接
    std::cout << "flag{" << "r0b0RUlez!" << "_";
	for(auto i = 0; i < strlen(doword_40AD98); ++i)
	{
        std::cout << char(doword_40AD98[i] ^ 2);
	}
    std::cout << "}" << std::endl;
}
