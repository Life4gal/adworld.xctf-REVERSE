#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4953&page=2
 * 原题为同目录下的 reverse-for-the-holy-grail-350
 *
 * 没有 IDA 分析文件，具体分析见下
 */

int main()
{
    int flag[18];
    int v14[18];

    int firstChar[8] =
    {
		65, 105, 110,
		69, 111, 97,
    	0,  0,
    };

	// 第一部分，隔三个字符取 firstChar 中的一个字符
	// 我们得到了下标为 0 3 6 9 12 15 的flag的值
    for (int i = 0, j = 0; i < 18; i += 3, ++j)
    {
    	// 在这里 v14 复制了 flag的每一个字符，但是我们暂时无法得知所有字符
        flag[i] = firstChar[j];
    }

    int v7 = 666;
    for (int& i : v14)
    {
    	// 在这里其实是 i ^= v7，但是上面 v14 是复制了 flag 的内容的
    	// 所以在这里我们直接储存 v7 的值，之后再想办法 异或
        i = v7;
        v7 += v7 % 5;
    }
	
    int thirdChar[8] =
    {
        751, 708, 732,
        711, 734, 764,
        0,   0
    };
	
    int masterArray[6] =
    {
        471, 12, 580,
        606, 147, 108
    };

	
    for(int i = 0, step = 0, flagIndex = 0; i < 18; ++i)
    {
		if(step == 2)
		{
			// 我们之前跳过了异或flag的步骤，这里补上
			// v14[i] ^ flag[i] == thirdChar[k]
			flag[i] = thirdChar[flagIndex] ^ v14[i];

			for (int c = 32; c < 127; ++c)
			{
				// 不知道那个字符，只能遍历可输入字符
				// v10其实就是 v14[i - 1] * v14[i]
				// 又因为在获得 v10 后 v5(遍历v14的指针)自增了一次
				// 所以 v10 要算作 v14[i - 2] * v14[i - 1],而 v5 此时是 v14[i]
				// 我们之前跳过了异或flag的步骤，这里补上
				// 我们要寻找的字符 c 就是当前的 flag[i - 1](因为v10是自增前的结果)
				// 到这里我们其实可以知道下标为 0 3 6 9 12 15 的flag的值，再加上上面的
				// 已知值下标为 0 2 3 5 6 8 9 11 12 14 15 17
				// 算出 1 4 7 10 13 16 按照下面的公式都是可行的
				if (((flag[i - 2] ^ v14[i - 2]) * (c ^ v14[i - 1])) % (flag[i] ^ v14[i]) == masterArray[flagIndex])
				{
					flag[i - 1] = c;
					break;
				}
			}
			++flagIndex;
			step = 0;
			}
		else
		{
			if(++step == 3)
			{
				step = 0;
			}
		}
    }

    std::cout << "tuctf{";
    for(int i : flag)
    {
        std::cout << char(i);
    }
    std::cout << "}" << std::endl;
}
