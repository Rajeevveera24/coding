# cook your dish here
for t in range(int(input())):
    
    s = input()
    
    n = len(s)
    
    s = s + 'a'
    
    i = 0
    
    # g = 'a'
    
    pair = 0
    
    while i < n:
        
        if s[i] == 'x' and s[i+1] == 'y':
            pair += 1
            i += 1
        elif s[i] == 'y' and s[i+1] == 'x':
            pair += 1 
            i += 1
        
        i += 1
    
    print(pair)
    