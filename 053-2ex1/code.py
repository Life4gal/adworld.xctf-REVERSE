"""
Base64具体转换步骤:
    第一步，将待转换的字符串每三个字节分为一组，每个字节占8bit，那么共有24个二进制位
    第二步，将上面的24个二进制位每6个一组，共分为4组
    第三步，在每组前面添加两个0，每组由6个变为8个二进制位，总共32个二进制位，即四个字节
    第四步，根据Base64密码表获得对应的值
"""


def b64Encode(dataToEncode: str, b64Table=None, dontUseStandard=False) -> str:
    """
    :param dataToEncode: 要加密的字节序列
    :param b64Table: 所使用的加密表,不填则用标准加密表
    :param dontUseStandard: 是否使用自带的base64库(用于调试)
    :return: 加密后的结果

    StandardBase64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
    """
    if b64Table is None:
        if not dontUseStandard:
            from base64 import b64encode
            return b64encode(dataToEncode).decode()
        else:
            b64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

    assert len(b64Table) is 64, f"Fatal Error: base64 Table's length must be 64(current is {len(b64Table)})"
    dataLength = len(dataToEncode)
    result = ""
    for itForData in range(0, dataLength, 3):
        # 每次取三个字符并转为二进制
        curr3Seq = dataToEncode[itForData:itForData + 3]
        binaryOf3Seq = ""
        for itForPerCharIn3Seq in curr3Seq:
            # 切掉0b, 对齐 8 位
            binaryOf3Seq += str(bin(ord(itForPerCharIn3Seq))[2:].rjust(8, "0"))
        if len(curr3Seq) is not 3:
            # 上一组不够三个, 先算出缺了几个
            pad = 3 - dataLength % 3
            # 缺几个,补几个 * 8 个 0
            binaryOf3Seq += pad * 8 * "0"
        # 再 6 个一组切
        assert len(binaryOf3Seq) is 24, f"Fatal Error: length of binaryOf3Seq is not 24(current is {len(binaryOf3Seq)})"
        for itForBinary in range(0, 24, 6):
            # 先补齐 8 位,然后以 2 进制基数转为 int ,这个 int 即为码表对应字符下标
            # 但是要注意,最后的两位如果是因为不够而补的 0 则并不是对应下标为0,而是用 '='填充
            index = int(binaryOf3Seq[itForBinary:itForBinary + 6].rjust(8, "0"), 2)
            if itForData > dataLength - 3 and index is 0:
                result += "="
            else:
                result += b64Table[index]
    return result


def b64Decode(dataToDecode: str, b64Table=None, dontUseStandard=False) -> str:
    """
    :param dataToDecode: 要解密的字符串
    :param b64Table: 所使用的加密表,不填则用标准加密表
    :param dontUseStandard: 是否使用自带的base64库(用于调试)
    :return: 解密后的结果
    """
    if b64Table is None:
        if not dontUseStandard:
            from base64 import b64decode
            return b64decode(dataToDecode).decode()
        else:
            b64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

    assert len(b64Table) is 64, f"Fatal Error: base64 Table's length must be 64(current is {len(b64Table)})"
    assert len(dataToDecode) % 4 is 0, f"Fatal Error: decode data's length must be multiple of 4(current is {len(dataToDecode)})"
    dataLength = len(dataToDecode)
    result = ""
    for itForData in range(0, dataLength, 4):
        # 这次要反着来了,每次取四个字符并转为二进制
        curr4Seq = dataToDecode[itForData:itForData + 4]
        binaryOf4Seq = ""
        for itForPerCharIn4Seq in curr4Seq:
            # 切掉0b,并去掉前两个0
            # 这里我们就要注意了,因为可能会有 "=" ,我们应该将其视作 0
            if itForPerCharIn4Seq is not "=":
                # 这里我们先去掉 0b ,然后补齐 8 位再切为 6 位
                # 注意不是把字符直接转为整型,而是寻找字符在密码表中对应的下标
                assert itForPerCharIn4Seq in b64Table, f"Fatal Error: char {itForPerCharIn4Seq} should in base64 Table {b64Table} but not found"
                binaryOf4Seq += str(bin(b64Table.index(itForPerCharIn4Seq))[2:].rjust(8, "0")[2:])
            else:
                # 是 = 的话直接加 6 个 0
                binaryOf4Seq += "0" * 6
        assert len(binaryOf4Seq) is 24, f"Fatal Error: length of binaryOf3Seq is not 24(current is {len(binaryOf4Seq)})"
        for itForBinary in range(0, 24, 8):
            # 以 2 进制基数转为 int ,再将这个 int 转为 char 即为原来的数据
            result += chr(int(binaryOf4Seq[itForBinary:itForBinary + 8], 2))
    return result


MyBase64Table = "@,.1fgvw#`/2ehux$~\"3dity%_;4cjsz^+{5bkrA&=}6alqB*-[70mpC()]89noD"
out = "│_r-+_Cl5;vgq_pdme7#7eC0="
# 很容易注意到这个out的第一个字符 | 并没有出现在密码表中,而且去掉它out长度刚好是 4 的倍数(24)
out = out[1:]
print(b64Decode(out, MyBase64Table, dontUseStandard=True))
