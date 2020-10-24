#include <iostream>
#include <array>
/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=5041&page=4
 * 原题为同目录下的 reverse_box
 */

// ================== 取自 IDA ==========================

typedef unsigned int uint;
typedef unsigned char uint8;

// rotate left
template<class T> T __ROL__(T value, int count)
{
    const ::uint nbits = sizeof(T) * 8;

    if (count > 0)
    {
        count %= nbits;
        T high = value >> (nbits - count);
        if (T(-1) < 0) // signed value
            high &= ~((T(-1) << count));
        value <<= count;
        value |= high;
    }
    else
    {
        count = -count % nbits;
        T low = value << (nbits - count);
        value >>= count;
        value |= low;
    }
    return value;
}

inline uint8  __ROR1__(uint8  value, int count) { return __ROL__((uint8)value, -count); }
// ============================================


void GenerateTable(const int randomVal, std::array<int, 256>& table)
{
    table[0] = randomVal;
	
    unsigned __int8 index = 1;
    char v8 = 1;

	do
	{
		const int v2 = index ^ 2 * index;
		const char v3 = (index & 0x80u) == 0 ? 0 : 27;
        index = v2 ^ v3;

		const char v4 = static_cast<char>(4 * (2 * v8 ^ v8) ^ 2 * v8 ^ v8);
		const char v9 = static_cast<char>(16 * v4 ^ v4);
		const char v5 = (v9 >= 0) ? 0 : 9;
        v8 = static_cast<char>(v9 ^ v5);

        const int result = 
            static_cast<unsigned __int8>(__ROR1__(v8, 4)) ^ 
            static_cast<unsigned __int8>(__ROR1__(v8, 5)) ^ 
            static_cast<unsigned __int8>(__ROR1__(v8, 6)) ^ 
            static_cast<unsigned __int8>(__ROR1__(v8, 7)) ^
            static_cast<unsigned __int8>(v8 ^ randomVal);
        table[index] = result;
    } while (index != 1);
}

int main()
{
	//char target[] = "95eeaf95ef94234999582f722f492f72b19a7aaf72e6e776b57aee722fe77ab5ad9aaeb156729676ae7a236d99b1df4a";
    int target[] =
    {
        0x95, 0xee, 0xaf, 0x95, 0xef, 0x94, 0x23, 0x49, 0x99, 0x58,
        0x2f, 0x72, 0x2f, 0x49, 0x2f, 0x72, 0xb1, 0x9a, 0x7a, 0xaf,
        0x72, 0xe6, 0xe7, 0x76, 0xb5, 0x7a, 0xee, 0x72, 0x2f, 0xe7,
        0x7a, 0xb5, 0xad, 0x9a, 0xae, 0xb1, 0x56, 0x72, 0x96, 0x76,
        0xae, 0x7a, 0x23, 0x6d, 0x99, 0xb1, 0xdf, 0x4a,
    };
	std::array<int, 256> table{};
	
	// unsigned __int8 -> 0~256
	for(auto i = 0; i < 256; ++i)
	{
        GenerateTable(i, table);

		// flag固定格式为 TWCTF{*******}
		// table[ord('T')] is 0x95 
        // table[ord('W')] is 0xee
        // table[ord('C')] is 0xaf
        // table[ord('F')] is 0xef 
        // table[ord('{')] is 0x94 
        // table[ord('}')] is 0x4a:
		if(table['T'] == 0x95)
		{
            break;
		}
	}

	for(auto eachVal : target)
	{
		const auto result = std::find(table.begin(), table.end(), eachVal) - table.begin();
        std::cout << char(result);
	}
    std::cout << std::endl;

    // 打印这张表
    for(int i = 0; i < 256; ++i)
    {
        printf("%02x\t", table[i]);
    }
}
