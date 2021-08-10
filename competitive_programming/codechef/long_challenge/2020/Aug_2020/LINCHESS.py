# cook your dish here
for _ in range(int(input())):
    n,k = map(int, input().split())
    p = list(map(int , input().split()))
    min_pos, min_moves = -1, 10**9
    assert len(p) == n
    
    for itr in range(n):
        if k % p[itr] == 0:
            tmp_min = k / p[itr]
            if min_moves > tmp_min:
                min_moves = tmp_min
                min_pos = itr
                
    if min_pos == -1:
        print(min_pos)
    else:
        print(p[min_pos])