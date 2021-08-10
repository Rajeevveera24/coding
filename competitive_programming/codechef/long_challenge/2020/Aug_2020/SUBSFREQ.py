#Problem only solved for the test cases where the input list a is a pemutation of the integers 1 to n

# cook your dish here
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    
    powers = dict()
    
    powers["0"] = 1
    for x in range(1, n):
        powers[str(x)] = (powers[str(x-1)] * 2) % 1000000007
        
    for x in range(1,n+1):
        print(powers[str(n-x)], end = " ")
    print()