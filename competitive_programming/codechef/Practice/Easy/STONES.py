# # cook your dish here
# for _ in range(int(input())):
#     j = str(input())
    
#     j1 = dict()
    
#     for c in j:
#         if str(c) in j1.keys():
#             continue
#         else:
#             j1[str(c)] = 1
    
#     s = str(input())
    
#     cnt = 0
    
#     for c in s:
#         if c in j1.keys():
#             cnt += 1
            
#     print(cnt)

# cook your dish here
for _ in range(int(input())):
    j = str(input())
    s = str(input())
    
    cnt = 0
    
    for c in s:
        if c in j:
            cnt += 1
            
    print(cnt)