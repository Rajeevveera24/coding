# cook your dish here
for t in range(int(input())):
    
    x,y,k,n = map(int, input().split())
    
    flag = False
    
    for i in range(n):
        p,c = map(int, input().split())
        
        if c <= k and p >= (x-y):
            flag = True
            
    
    if flag:
        print("LuckyChef")
    else:
        print("UnluckyChef")
    
                