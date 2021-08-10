# subtask 1 passed : n <= 80
# TLE for n > 80  (1 <= n <= 10**5)


n,k = map(int, input().split())

a = [0]

a1 = [int(i) for i in input().split()]

a = a + a1

assert len(a) == n+1

i = n-1

while(i >= n-k):
    a[i] = a[i] * a[n]
    i -= 1

while (i >= 1):
    j = 1 
    mini = i + 1
    
    while (j<= k):
        if a[mini] >= a[i + j]:
            mini = i + j
        
        j += 1
    
    a[i] = a[i] * a[mini]
    
    i -= 1
    
    
print(a[1] % 1000000007)
    


