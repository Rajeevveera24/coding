# cook your dish here
for _ in range(int(input())):
    k = int(input())
    
    assert k >= 1 and k <= 64
    cnt = 1
    
    flg = False
    
    for i in range(8):
        for j in range(8):
            if flg == False:
                print('O', end = '')
                flg = True
                continue
            if cnt < k:
                print('.', end = '')
            else:
                print('X', end = '')
            cnt += 1
        print()
    