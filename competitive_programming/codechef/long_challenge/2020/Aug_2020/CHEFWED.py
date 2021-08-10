#During the competition: Problem only partially solved for the test cases where k = 1
#Later: Understood another person's solution (which is what is in this file) and used that to solve the problem fully
#The Solution appears to have a worst case time complexity of O(N^2) with N <= 1000 and sum of N over T <= 5000

# cook your dish here
for _ in range(int(input())):
    n,k = map(int, input().split())
    guests = list(map(int, input().split()))
    
    max_inefficieny = k*n #This is the worst possible inefficiency value
    
    max_forward = max_inefficieny
    
    repeat_limit = 0
    
    while(True):
        tables = []
        current_table = {}
        total_cost = 0
        cost = 0
        repeated = repeat_limit
        
        for guest in guests:
            if guest in current_table and repeated > 0:
                repeated -= 1
                if current_table[guest] == 1:
                    cost += 2
                else:
                    cost += 1
                current_table[guest] += 1
            elif guest in current_table and repeated == 0:
                tables.append(current_table)
                current_table = {}
                current_table[guest] = 1
                total_cost += cost
                cost = 0
                repeated = repeat_limit
            else:
                current_table[guest] = 1
        
        tables.append(current_table)
        total_cost += cost
        
        max_forward = min(max_forward, len(tables) * k + total_cost)
        
        repeat_limit += 1
        
        if len(tables) == 1:
            break
        
    repeat_limit = 0
    max_reverse = max_inefficieny
    guests.reverse()
    
    while(True):
        tables = []
        current_table = {}
        total_cost = 0
        cost = 0
        repeated = repeat_limit
        
        for guest in guests:
            if guest in current_table and repeated > 0:
                repeated -= 1
                if current_table[guest] == 1:
                    cost += 2
                else:
                    cost += 1
                current_table[guest] += 1
            elif guest in current_table and repeated == 0:
                tables.append(current_table)
                current_table = {}
                current_table[guest] = 1
                total_cost += cost
                cost = 0
                repeated = repeat_limit
            else:
                current_table[guest] = 1
        
        tables.append(current_table)
        total_cost += cost
        
        max_reverse = min(max_reverse, len(tables) * k + total_cost)
        
        repeat_limit += 1
        
        if len(tables) == 1:
            break
        
    max_inefficieny = min(max_forward, max_reverse)
    
    print(max_inefficieny)
    
    
    
        
                