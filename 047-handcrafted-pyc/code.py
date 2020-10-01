from base64 import b64decode
from zlib import decompress
from os import system

inputFile = "handcrafted-pyc.py_bc552f58fe2709225ca0768c131dd14934a47305"
magicHeader = b"\x03\xf3\x0d\x0a\xfb\x1c\x32\x59"
outputPycFile = "dump.pyc"
outputSrcFile = "output.py"
uncompyleExe = "uncompyle6"

code = 'eJyNVktv00AQXm/eL0igiaFA01IO4cIVCUGFBBJwqRAckLhEIQmtRfPwI0QIeio/hRO/hJ/CiStH2M/prj07diGRP43Hs9+MZ2fWMxbnP6mux' \
       '+oK9xVMHPFViLdCTB0xkeKDFEFfTIU4E8KZq8dCvB4UlN3hGEsdddXU9QTLv1eFiGKGM4cKUgsFCNLFH7dFrS9poayFYmIZm1b0gyqxMOwJaU' \
       '3r6xs9sW1ooakXuRv+un7Q0sIlLVzOCZq/XtsK2oTSYaZlStogXi1HV0iazoN2CV2HZeXqRQ54TlJRb7FUlKyUatISsdzo+P7UU1Gb1POdMru' \
       'ckepGwk9tIXQTftz2yBaT5JQovWvpSa6poJPuqgao+b9l5Aj/R+mLQIP4f6Q8Vb3g/5TB/TJxWGdZr9EQrmn99fwKtTvAZGU7wzS7GNpZpDm2' \
       'JgCrr8wrmPoo54UqGampFIeS9ojXjc4E2yI06bq/4DRoUAc0nVnng4k6p7Ks0+j/S8z9V+NZ5dhmrJUM/y7JTJeRtnJ2TSYJvsFq3CQt/vnfq' \
       'mQXt5KlpuRcIvDAmhnn2E0t9BJ3SvB/SfLWhuOWNiNVZ+h28g4wlwUp00w95si43rZ3r6+fUIEdgOZbQAsyFRRvBR6dla8KCzRdslar7WS+a5' \
       'HFb39peIAmG7uZTHVm17Czxju4m6bayz8e7J40DzqM0jr0bmv9PmPvk6y5z57HU8wdTDHeiUJvBMAM4+0CpoAZ4BPgJeAYEAHmgAUgAHiAj4A' \
       'VAGORtwd4AVgC3gEmgBBwCPgMWANOAQ8AbwBHgHuAp4D3gLuARwoGmNUizF/j4yDC5BWM1kNvvlxFA8xikRrBxHIUhutFMBlgQoshhPphGAXe' \
       '/OggKqqb2cibxwuEXjUcQjccxi5eFRL1fDSbKrUhy2CMb2aLyepkegDWsBwPlrVC0/kLHmeCBQ== '

content = decompress(b64decode(code))

file = open(outputPycFile, 'wb')
data = magicHeader + content
file.write(data)
file.close()

system(f"{uncompyleExe} {outputPycFile} > {outputSrcFile}")


def ROT_TWO(_list):
    if len(_list) >= 2:
        a = _list.pop()
        b = _list.pop()
        _list.append(a)
        _list.append(b)
    return _list


def BINARY_ADD(_list):
    if len(_list) >= 2:
        a = _list.pop()
        b = _list.pop()
        _list.append(b + a)
    return _list


stack = []
for line in open(outputSrcFile):
    if "LOAD_CONST" in line:
        try:
            stack.append(chr(int(line.split()[2])))
        except ValueError:
            pass
    elif "ROT_TWO" in line:
        stack = ROT_TWO(stack)
    elif "BINARY_ADD" in line:
        stack = BINARY_ADD(stack)

print(stack)
