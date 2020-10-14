from struct import unpack
from os.path import getsize


# 第一步 读取 out 文件的 二进制 内容
def un_sub_400CC0() -> tuple:
    """
    :return: 返回一个元祖,内容是从 out 文件中读取的内容
    """
    # 读取 out 文件
    outFilePath = "./out"
    outLength = getsize(outFilePath)
    with open(outFilePath, 'rb') as outFile:
        # B = unsigned char
        return unpack(''.join(['B' * outLength]), outFile.read())


# 第二步 处理 out 的内容
def un_sub_400DB4(t: tuple) -> list:
    """
    :param t: out 中读取的内容
    :return: 返回一个列表,是 out 中内容对 sub_400DB4 函数的逆变换
    """
    # 按 byte 读取,所以 & 0xFF
    v3 = (t[-1] << 5 | t[0] >> 3) & 0xFF
    _list = [v3]
    for i in range(len(t) - 1):
        _list.append(((t[i] << 5) | t[i + 1] >> 3) & 0xFF)
    return _list


# 第三步 读取 that_girl
def un_sub_400AAA() -> dict:
    """
    :return: 返回一个字典,内容为经过 sub_400936 函数变换后的 that_girl 的内容每个字符与其出现的次数
    """
    # sub_400936 对每个字符的处理
    def sub_400936(char: str) -> int:
        """
        :param char: 读取的字符
        :return: 变换对应的整数
        """
        char = ord(char)
        result = char - 10
        if char is 10:
            result = char + 35  # 10 -> 45 : '\n' -> '-'
        elif char is 32 or char is 33 or char is 34:
            # 其实只有 ' '
            result = char + 10  # 32 33 34 -> 42 43 44 : ' ' or '!' or '"' -> '*' or '+' or ','
        elif char is 39:
            result = char + 2  # 39 -> 41 : '\'' -> ')'
        # 经测试,下面这几个分支没用
        # elif char is 44:
        #     result = char - 4  # 44 -> 40 : ',' -> '('
        # elif char is 46:
        #     result = char - 7  # 46 -> 39 : '.' -> '\''
        # elif char is 58 or char is 59:  # 58 59 -> 37 38 : ':' or ';' -> '%' '&'
        #     result = char - 21
        # elif char is 63:
        #     result = char - 27  # 63 -> 37 : '?' -> '%'
        elif char is 95:
            result = char - 49  # 95 -> 46 : '_' -> '.'
        else:
            if char <= 47 or char > 48:  # not 48('0')
                if char <= 64 or char > 90:
                    if 96 < char <= 122:
                        result = char - 87  # a ~ z -> 10 ~ 35
                else:
                    result = char - 55  # [A ~ Z] -> 10 ~ 35
            else:
                # 这个也是不存在的
                result = char - 48  # '0' -> 0
        return result
    songFilePath = "./that_girl"
    # 原来的操作是 ++*(_DWORD *)(4LL * v2 + ptr); 但其实它的指针类型是 __int64,而实际的数据类型为 byte,我们可以不需要乘这个4
    # 经过测试命中区域处于 40 ~ 184 之间, (184 - 40) / 4 = 36
    _list = [0] * 37
    with open(songFilePath, "r") as song:
        for c in song.read():
            v2 = sub_400936(c)
            _list[v2 - 10] += 1
    """
        观察 sub_400936 函数我们不难发现其实就是一个映射关系
        不分大小写
        a~z(A~Z) 映射到 _list[0~25]
        剩下的依次是
            '\'' -> 31
            ' ' -> 32
            '\\n'' -> 35
            '_' -> 36
        其他的都是无效的
        我们可以只返回有效的数据
    """
    ret = _list[:26]
    ret.append(_list[31])
    ret.append(_list[32])
    ret.append(_list[35])
    ret.append(_list[36])
    return dict(zip("abcdefghijklmnopqrstuvwxyz' \n_", ret))


# 第四步 获取flag
def getFlag(_list: list, mapping: dict) -> str:
    """
    :param _list: 这个列表带着处理后的 out 的内容
    :param mapping: 这个字典带着 字符 与 出现次数 的映射
    :return:
    """
    def un_sub_400D33() -> None:
        """
            处理 getFlag 传进来的 _list
        """
        # 直接用外面传进来的列表
        nonlocal _list
        dword_6020A0 = [
            0x16, 0x00, 0x06, 0x02, 0x1e,
            0x18, 0x09, 0x01, 0x15, 0x07,
            0x12, 0x0a, 0x08, 0x0c, 0x11,
            0x17, 0x0d, 0x04, 0x03, 0x0e,
            0x13, 0x0b, 0x14, 0x10, 0x0f,
            0x05, 0x19, 0x24, 0x1b, 0x1c,
            0x1d, 0x25, 0x1f, 0x20, 0x21,
            0x1a, 0x22, 0x23
        ]
        """
            dword_6020A0 = [
            22, 0, 6, 2, 30,
            24, 9, 1, 21, 7,
            18, 10, 8, 12, 17,
            23, 13, 4, 3, 14,
            19, 11, 20, 16, 15,
            5, 25, 36, 27, 28,
            29, 37, 31, 32, 33,
            26, 34, 35
            ]
    
            index -> dword_6020A0[index]
            0 -> [22] = 20
            20 -> [20] = 19
            19 -> [19] = 14
            14 -> [14] = 17
            17 -> [17] = 4
            4 -> [4] = 30
            30 -> [30] = 29
            29 -> [29] = 28
            28 -> [28] = 27
            27 -> [27] = 36
            36 -> [36] = 34
            34 -> [34] = 33
            33 -> [33] = 32
            32 -> [32] = 31
            31 -> [31] = 37
            37 -> [37] = 35
            35 -> [35] = 26
            26 -> [26] = 25
            25 -> [25] = 5
            5 -> [5] = 24
            24 -> [24] = 15
            15 -> [15] = 23
            23 -> [23] = 16
            16 -> [16] = 13
            13 -> [13] = 12
            12 -> [12] = 8
            8 -> [8] = 21
            21 -> [21] = 11
            11 -> [11] = 10
            10 -> [10] = 18
            18 -> [18] = 3
            3 -> [3] = 2
            2 -> [2] = 6
            6 -> [6] = 9
            9 -> [9] = 7
            7 -> [7] = 1
            1 -> [1] = 0
            没有重复,没有覆盖,可以还原
        """
        v2 = 37
        while dword_6020A0.index(v2) is not 37:
            _list[v2] = _list[dword_6020A0.index(v2)]
            v2 = dword_6020A0.index(v2)

    un_sub_400D33()

    flag = []
    mappingKey = list(mapping.keys())
    mappingValue = list(mapping.values())
    for i in _list:
        index = mappingValue.index(i)
        flag.append(mappingKey[index])
    return f"QCTF{{{''.join(flag)}}}"


print(getFlag(un_sub_400DB4(un_sub_400CC0()), un_sub_400AAA()))
