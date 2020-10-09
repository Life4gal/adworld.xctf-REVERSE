import idc

start = 0x0804829c
end = 0x08060b32
R0 = 0x08062060
R1 = 0x08062064
R2 = 0x08062068
R3 = 0x0806206c
F0 = 0x08062070
F1 = 0x08062074


def getChar(c: int) -> bool:
    if (ord('0') <= c <= ord('9')) or (ord('a') <= c <= ord('z') or (ord('A') <= c <= ord('Z')) or c == ord('{') or
                                       c == ord('}') or c == ord('_') or c == ord('@') or c == ord('#') or c == ord('!')
                                       or c == ord('&') or c == ord('*') or c == ord('(') or c == ord(')')):
        return chr(c)
    else:
        return ""


# 经过观察,可以发现 flag 字符写在 R2 所在位置,一次写一个字符,每次写都会覆盖之前的字符
flag = ""
while start < end:
    flag += getChar(Byte(start))
    start += 1

print(flag)