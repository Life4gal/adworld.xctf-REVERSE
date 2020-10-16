from hashlib import md5
from itertools import permutations


# 在 main 函数里,在 puts("Badluck! There is no flag") 上有一句判断
# if ( (unsigned __int8)(LOBYTE(dest[0]) - 48) > 74u )
# 所以每个字符都必须都必须小于 122('z')
# 我们不妨从 48('0') 开始遍历字符
# 注意,它的 MD5 函数的参数 3 是作为返回值的,而且从
# *(_WORD *)v31 = v10;
# *(_BYTE *)(v31 + 4) = v12;
# *(_BYTE *)(v31 + 2) = BYTE2(v10);
# *(_BYTE *)(v31 + 3) = HIBYTE(v10);
# *(_BYTE *)(v31 + 12) = v13;
# *(_BYTE *)(v31 + 5) = BYTE1(v12);
# *(_BYTE *)(v31 + 7) = HIBYTE(v12);
# *(_BYTE *)(v31 + 6) = BYTE2(v12);
# *(_DWORD *)(v31 + 8) = v28;
# *(_BYTE *)(v31 + 13) = BYTE1(v13);
# *(_BYTE *)(v31 + 14) = BYTE2(v13);
# *(_BYTE *)(v31 + 15) = HIBYTE(v13);
# 可以看出他应该是取了 MD5 值的前 16 位
def getValidSeq() -> list:
    # 这里要注意数据储存的大小端问题,是每个 qword 按 byte 从后往前读取
    qword_602120 = [
        '4746BBBD02BB590F', 'BEAC2821ECE8FC5C', 'AD749265CA7503EF',
        '4386B38FC12C4227', 'B03ECC45A7EC2DA7', 'BE3C5FFE121734E8'
    ]
    start = ord('0')
    end = ord('z')
    ret = []
    indexMapping = []

    def search() -> None:
        def update() -> bool:
            # 每一组的 4 个字符
            nonlocal a
            nonlocal b
            nonlocal c
            nonlocal d
            r = True
            if a < end:
                a += 1
            else:
                a = start
                if b < end:
                    b += 1
                else:
                    b = start
                    if c < end:
                        c += 1
                    else:
                        c = start
                        if d < end:
                            d += 1
                        else:
                            r = False
            return r

        a = start
        b = start
        c = start
        d = start
        while True:
            seq = chr(a) + chr(b) + chr(c) + chr(d)
            m = md5(seq.encode()).hexdigest()[:16].upper()
            if m in qword_602120:
                ret.append(seq)
                indexMapping.append(qword_602120.index(m))
            if not update():
                break

    search()
    # 为什么还有个 indexMapping 呢?
    # 因为源程序比较的顺序按照 qword_602120 中的顺序进行的
    # 而我们为了加快遍历顺序使用的是 if m in qword_602120 ,这导致了无法确定顺序,所以加入了 indexMapping
    return [ret, indexMapping]


# 返回到 main 函数,它最开始做了一步
# v10 = 0LL;
# v11 = 0;
# while ( v9 != v10 )
# {
#     v12 = *((_BYTE *)input + v10) + v10;
#     ++v10;
#     v11 ^= v12;
# }
def getXorVal(s: str) -> int:
    assert len(s) == 24
    v11 = 0
    for eachChar in range(24):
        v11 ^= (ord(s[eachChar]) + eachChar)
    return v11


if __name__ == "__main__":
    validSeq, order = getValidSeq()
    trueSeq = ""
    for index in order:
        trueSeq += validSeq[index]
    # juhuhfenlapsiuerhjifdunu
    # print(trueSeq)
    xorVal = getXorVal(trueSeq)

    byte_6020DF = [
        254, 233, 244, 226,
        241, 250, 244, 228, 240,
        231, 228, 229, 227, 242,
        245, 239, 232, 255, 246,
        244, 253, 180, 165, 178
    ]

    # 获取所有可能的组合,共有 6! = 6 * 5 * 4 * 3 * 2 * 1 = 720 种
    allProbFlag = []
    for permutation in list(permutations(validSeq)):
        allProbFlag.append(''.join(permutation))

    # 输出所有可能的 flag
    for eachFlag in allProbFlag:
        thisFlag = ""
        for i in range(len(byte_6020DF)):
            thisFlag += chr(xorVal ^ byte_6020DF[i] ^ ord(eachFlag[i]))

        if "flag" in thisFlag:
            print(thisFlag)
