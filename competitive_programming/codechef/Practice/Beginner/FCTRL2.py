# cook your dish here
def factor(n):
    fct = 1
    for i in range(2,int(n)+1):
        fct *= i
    return fct
    
t = int(input())
while t>0:
    t = t-1
    n = int(input())
    print(factor(n))
