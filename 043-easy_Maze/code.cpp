#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5586&page=2
 * 原题为同目录下的 easy_Maze IDA分析文件为 easy_Maze部分静态分析.i64
 */

int main()
{
    int maze[7 * 7] =
    {
        1, 0, 0, 1, 1, 1, 1,
        1, 0, 1, 1, 0, 0, 1,
        1, 1, 1, 0, 1, 1, 1,
        0, 0, 0, 1, 1, 0, 0,
        1, 1, 1, 1, 0, 0, 0,
        1, 0, 0, 0, 1, 1, 1,
        1, 1, 1, 1, 1, 0, 1
    };

	// 从maze[0][0] -> maze[6][6]
	// 沿着 1 走
	// ssddwdwdddssaasasaaassddddwdds
    std::cout << "UNCTF{" << "ssddwdwdddssaasasaaassddddwdds" << "}" << std::endl;
}
