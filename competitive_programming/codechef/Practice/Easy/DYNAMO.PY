# cook your dish here

for i in range(int(input())):
    n = int(input())
    a = int(input())
    s = a + (1 + 1) + 2 * ((10 ** n) - 1)
    print(s, flush = True)
    b = int(input())
    c = s - (a+b) - (1 + (10 ** n - 1))
    print(c, flush = True)
    d = int(input())
    e = s - (a+b+c+d)
    print(e, flush = True)
    t = int(input())
    if t == 1:
        continue
    elif t == -1:
        # print("exiting")
        exit()
    