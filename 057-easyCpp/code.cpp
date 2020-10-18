#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5475&page=4
 * 原题为 easyCpp 目录下的 easyCpp IDA输出文件见 easyCpp.i64
 */

#include <vector>
#include <algorithm>

constexpr __int64 GetFib(const __int64 n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return GetFib(n - 1) + GetFib(n - 2);
}

int main()
{
	// 从斐波那契数列逆推
    std::vector<__int64> fibVec;
	for(auto i = 0; i <= 15; ++i)
	{
        fibVec.push_back(GetFib(i));
	}

	// 逆序
    std::reverse(fibVec.begin(), fibVec.end());

	// 减去加上的值(应该是当前的第一个值)
    for(size_t i = 1; i < fibVec.size(); ++i)
    {
        fibVec[i] -= fibVec[0];
    }

    // 去掉偶数
    fibVec.erase(std::remove_if(fibVec.begin(), fibVec.end(), [](const auto v) { return v % 2 == 0; }), fibVec.end());

	// 输出
    std::cout << "flag{";
	for(const auto& v : fibVec)
	{
        std::cout << v;
	}
    std::cout << "}" << std::endl;
}
