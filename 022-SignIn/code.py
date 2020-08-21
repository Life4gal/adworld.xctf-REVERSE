# RSA 加密
p = 366669102002966856876605669837014229419
q = 282164587459512124844245113950593348271
e = 65537
N = 103461035900816914121390101299049044413950405173712170434161686539878160984549

c = 0xad939ff59f6e70bcbfad406f2494993757eee98b91bc244184a377520d06fc35


def func(a, b):
    last_t, t = 0, 1
    last_r, r = a, b

    if b == 0:
        return 0
    else:
        while r != 0:
            global q
            q = last_r // r
            last_r, r = r, last_r - q * r
            last_t, t = t, last_t - q * t
        return last_t


euler = (p - 1) * (q - 1)
d = func(euler, e)

while d < 0:
    d += euler

flag = pow(c, d, N)

# [2:]切掉0x
print(bytes.fromhex(hex(flag)[2:]))
