import hashlib


def yanghuiTriangle():
    n = [1]
    while True:
        yield n
        n.append(0)
        n = [n[s - 1] + n[s] for s in range(len(n))]


i = 0
x = ''
for t in yanghuiTriangle():
    # print(t)
    x += ''.join(map(str, t))
    i += 1
    if i == 20:
        break

print('RCTF{%s}' % hashlib.md5(x.encode()).hexdigest())
