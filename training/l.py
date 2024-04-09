n = int(input())

m = {"pink": 1.0}

for x in range(n):
    inp = input().split()
    a = inp[0];
    b = inp[1];
    if not a in m:
        m[a] = 0.0
    if not b in m:
        m[b] = 0.0
    rate = float(inp[2]);
    if (rate * m[b] > m[a]):
        m[a] = rate * m[b]


if not "blue" in m:
    m["blue"] = 0.0
if (m["blue"] > 10.0):
    m["blue"] = 10.0

print(m["blue"])
