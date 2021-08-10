# cook your dish here
for t in range(int(input())):
    n, k = map(int, input().split())
    loss = 0

    d = input().split()
    
    for i in range(len(d)):
        if int(d[i]) > k:
            loss += (int(d[i]) - k)
    
    # print(d)
    
    print(loss)