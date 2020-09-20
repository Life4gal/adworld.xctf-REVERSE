#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4997&page=3
 * 原题为同目录下的 easyre-153 IDA输出文件为 easyre-153.idb
 */


int main()
{
    constexpr char buf[27] = "69800876143568214356928753";
    char flag[8] = { '\0' };
    flag[0] = 2 * buf[1];
    flag[1] = buf[4] + buf[5];
    flag[2] = buf[8] + buf[9];
    flag[3] = 2 * buf[12];
    flag[4] = buf[18] + buf[17];
    flag[5] = buf[10] + buf[21];
    flag[6] = buf[9] + buf[25];
	
    std::cout << "RCTF{" << flag << "}" << std::endl;
}
