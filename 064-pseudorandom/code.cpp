#include <algorithm>
#include <iostream>

int main()
{
    // The following three variables are static(unchanged),
    // so we can use debug tool(gdb) to get them
    // at 0x004010f3: var_1c = 846930886
    //  -> loop times for input(how did it possible?)
    // at 0x00401112: var_2c_1 = 0x20000000
    //  -> used as mask? this var used after MD5_Update and SHA1_Update
    // at 0x00401145: var_28 = 65535 -> 2^16-1
    //  -> used as function sub_400ea0's 1st arg for valid the input(input is the 2nd arg)
    //  sub_400ea0 use the integer data overflow(debug test), other wise, it is a endless loop
    /* sub_400ea0 ========>
     * var_20 = 0xa8ede3dd <- init <- will data overflow to control the path
     * var_10 = unknown <- return
     * dead path -> var_20 = 0xd0706b8
     *
     * many confusing paths, in fact, arg1 is always the same (and not 0),
     * and only one path will use arg2(when var_20 is equal 0x1cde6c41),
     * and only this path can break the loop.
     *
     * another good thing is that we always get the same value of var_48_1/rax_23
     * because only arg1 used to get these var, use debug tool(gdb) we can easily get them.
     * var_48_1 = 0x7fff <- 32767 = 2^15-1
     * rax_23 = (0x8000 <- 32768 = 2^15) << 1 = 2^16
     *
     * correct path: (var_48_1 & rax_23) | (var48_1 ^ rax_23) == (arg2 - (0 - arg1))
     * -> 0 | ((2^15-1) + 2^16) == arg2 + (2^16-1)
     * -> arg2 == 2^15
     *
     * leaving this function we noticed that var_28 is not constant, it will add the value we input(arg1 = arg1 + arg2),
     * but we can be sure that the first input must be 2^15
     *
     * after test we found that the change of arg1 does not affect var_48_1, but rax_23 is doubled(65536 -> 131072).
     * then:
     * -> 0 | ((2^15-1) + 2^17) == arg2 + (2^16-1 + 2^15)
     * -> 2 == 2^16
     *
     * and so on....................
     *
     * it is not that easy...there are some thing wrong(after a big loop), but debugging can get results
    */


    // useless code....
//    int var_0x4016e8[] = {
//        0x31, 0x35, 0x62, 0x37, 0x34, 0x62, 0x34, 0x64,
//        0x62, 0x35, 0x37, 0x64, 0x30, 0x61, 0x66, 0x64,
//        0x66, 0x65, 0x39, 0x38, 0x65, 0x62, 0x35, 0x64,
//        0x62, 0x63, 0x33, 0x62, 0x35, 0x34, 0x32, 0x62
//    }; // 15b4b4db57d0afdfe98eb5dbc3b542b
//    decltype(var_0x4016e8) var_198 = {};
//    for(auto var_17c = 0; var_17c < 0x10; ++var_17c){
//        auto rcx_14 = var_17c << 1;
//        var_198[var_17c] = var_0x4016e8 [rcx_14];
//    }
//    std::for_each(
//            std::begin(var_198), std::end(var_198),
//            [](auto i){
//                std::cout << static_cast<const char>(i) << std::endl;
//            }
//    );
}
