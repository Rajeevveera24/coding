# cook your dish here
for i in range(int(input())):
    n = int(input())
    mini = 10**10
    for i in range(1, int(n ** 0.5 + 1)):
        # print(i)
        if n % i == 0:
            a = i
            b = n/i
            dif = abs(a - b)
            # print(dif, mini)
            if dif < mini:
                # print(a, b, dif)
                mini = dif
    
    print(int(mini))