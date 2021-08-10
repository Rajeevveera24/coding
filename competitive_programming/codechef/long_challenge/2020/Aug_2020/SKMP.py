from itertools import permutations

for _ in range(int(input())):
    s = str(input())
    p = str(input())
    
    # s_list = sorted([x for x in s])
    
    # for perm in permutations(s_list):
    #     permut = "".join(perm)
    #     if p in permut:
    #         ans1 = permut
    #         break
    
    s_sorted = "".join(sorted(s))
    
    s_dict = dict()
    
    for char in s_sorted:
        if not (char in s_dict.keys()):
            s_dict[char] = 1
        else:
            s_dict[char] = s_dict[char] + 1
    
    for char in p:
        s_dict[char] = s_dict[char] - 1
    
    part_string = ""
    
    for char, val in s_dict.items():
        while val > 0:
            part_string = part_string + char
            val = val - 1
    
    # print(part_string)
    min_string = p + part_string
    
    for i in range(1, len(part_string)+1):
        new_string = part_string[:i] + p + part_string[i:]
        if new_string < min_string:
            min_string = new_string
    
    print(min_string)

        