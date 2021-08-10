# cook your dish here
for _ in range(int(input())):
    D,d,P,Q = map(int, input().split())
    
    n = (D//d) - 1
    sumQ = (n*(n+1))/2
    
    ans = (P*D) + (sumQ*Q*d) + ((D%d)*(n+1)*Q)
    
    print(int(ans))
