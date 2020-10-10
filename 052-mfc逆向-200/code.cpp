#include <iostream>
#include <Windows.h>
/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4824&page=4
 */

int main()
{
    const auto handle = FindWindowExW(
		GetDesktopWindow(), 
		FindWindowW(nullptr, L"这里有一个Key，你能找到它吗"), 
		nullptr,
		L"Flag就在控件里"
	);
	if(handle)
	{
		std::cout << "found handle! address: " << handle << std::endl;
		SendMessage(handle, 0x464, 0, 0);
	}

	system("pause");
}
