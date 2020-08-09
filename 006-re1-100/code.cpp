#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4720&page=1
 * 原题为同目录下的 re1-100.zip 或 RE100 , IDA分析文件为 RE100.i64
 */

bool __cdecl confuseKey(char* szKey, int iKeyLength)
{
    char szPart1[15];
    char szPart2[15];
    char szPart3[15];
    char szPart4[15];
    memset(szPart1, 0, 15);
    memset(szPart2, 0, 15);
    memset(szPart3, 0, 15);
    memset(szPart4, 0, 15);
	
    unsigned __int64 v7 = 40;

    if (iKeyLength != 42)
        return false;
    if (!szKey)
        return false;
    if (strlen(szKey) != 42)
        return false;
    if (*szKey != '{')
        return false;
	
    strncpy(szPart1, szKey + 1, 10);    
    strncpy(szPart2, szKey + 11, 10);
    strncpy(szPart3, szKey + 21, 10);
    strncpy(szPart4, szKey + 31, 10);
	
    memset(szKey, 0, iKeyLength);
	
    *szKey = '{';
	
    strcat(szKey, szPart3);
    strcat(szKey, szPart4);
    strcat(szKey, szPart1);
    strcat(szKey, szPart2);
	
    szKey[41] = '}';
	
    return true;
}

int main()
{
    char flag[] = "{daf29f5903   4938ae4efd    53fc275d81   053ed5be8c}";
	
    char result[] = "{53fc275d81053ed5be8cdaf29f59034938ae4efd}";   // 去掉左右的花括号
}
