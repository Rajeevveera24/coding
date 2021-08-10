# cook your dish here
for t in range(int(input())):
    n = int(input())
    
    a = input().split()
    
    five = 0
    ten = 0
    fifteen = 0
    
    flag = True
    
    for i in range(len(a)):
        if(int(a[i]) == 5):
            five += 1 
        elif(int(a[i]) == 10):
            if five == 0:
                flag = False
                break
            else:
                five -= 1
                ten += 1 
        else:
            if ten == 0:
                if five < 2:
                    flag = False
                    break
                else:
                    fifteen += 1
                    five -= 2
            else:
                fifteen += 1
                ten -= 1
                
    if flag == True:
        print("YES")
    else:
        print("NO")        