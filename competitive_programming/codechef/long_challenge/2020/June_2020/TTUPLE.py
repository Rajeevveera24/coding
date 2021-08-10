# cook your dish here

def check2(a, b, a1, b1):
    
#   assert a != a1 and b != b1

    d_a = a1 - a
    d_b = b1 - b

    if d_a == d_b:
        return 1
    
    elif a == 0 or b == 0:
        return 2
    else:
    
        if a1 == b1 and a1 == 0 and b1 == 0:
            return 1
        elif a1 == 0 or b1 == 0:
            return 2
    
        q_a, q_b = a1 / a , b1 / b
    
        if q_a.is_integer() and q_b.is_integer():
            if q_a == q_b:
                return 1
            else:
                return 2
        else:
            return 2
                
    return 2
        


def check_0_nz_nz(q, r, a, b, c):
    assert (q != 0 and r != 0 and q != b and r != c and a != 0) 
    
    d_b, d_c = b - q, c - r
    
    if d_b == d_c and d_c == a:
        return 1
    elif d_b == d_c or d_c == a or a == d_b:
        return 2
    else:
        q_b, q_c = b/q , c/r
    
        if q_b.is_integer() and q_c.is_integer() and q_b == q_c:
            return 2
    
        t1, t2 = (b-a)/q , (c-a)/r
    
        if t1.is_integer() and t2.is_integer() and t1 == t2:
            return 2
    
        t3,t4 = q+a, r+a
        
        if t3 == 0 or t4 == 0:
            return 3
        else:
            t1, t2 = b / t3, c / t4
            if t1.is_integer() and t2.is_integer() and t1 == t2:
                return 2
    
    return 3


def check3(p, q, r, A, B, C):
    d_a = A - p
    d_b = B - q
    d_c = C - r

    min = 3

    assert d_a != d_b and d_c != d_b and d_c != d_a

    if p == q or q == r or r == p:
        print(3)
        return
  
    if (abs(A - B) % abs(p - q) != 0) and (abs(B - C) % abs(r - q) != 0)  and (abs(C - A) % abs(r - p) != 0):
        print(3)
        return

    if (abs(A - B) % abs(p - q) == 0):
        a,b,c,a1,b1,c1 = p,q,r,A,B,C
    
        x = (a1 - b1) / (a-b)
        # print(x)
        y1 = b1 - b*x
    
        # assert y1 == a1 - a*x
        
        if c*x == c1 or c + y1 == c1 or c*x + y1 == c1:
            print(2)
            return
        
        if x == 0:
            print(3)
            return
        
        if b1%x == 0:
            y2 = b1/x - b
    
            if y2.is_integer():
                # assert y2 == a1/x - a
                # print(y2)
                if c+y2 == c1 or c*x == c1 or (c+y2)*x == c1:
                    print(2)
                    return
                else:
                    min = 3
            else:
                min = 3

    if (abs(A - C) % abs(p - r) == 0):
        a,b,c,a1,b1,c1 = p,r,q,A,C,B
    
        x = (a1 - b1) / (a-b)
        # print(x)
        y1 = b1 - b*x
    
        # assert y1 == a1 - a*x
        
        if c*x == c1 or c + y1 == c1 or c*x + y1 == c1:
            print(2)
            return
        
        if x == 0:
            print(3)
            return
        
        if b1%x == 0:
            y2 = b1/x - b
    
            if y2.is_integer():
                # assert y2 == a1/x - a
                # print(y2)
                if c+y2 == c1 or c*x == c1 or (c+y2)*x == c1:
                    print(2)
                    return
                else:
                    min = 3
            else:
                min = 3
                
    if (abs(B - C) % abs(q - r) == 0):
        a,b,c,a1,b1,c1 = q,r,p,B,C,A
    
        x = (a1 - b1) / (a-b)
        # print(x)
        y1 = b1 - b*x
    
        # assert y1 == a1 - a*x
        
        if c*x == c1 or c + y1 == c1 or c*x + y1 == c1:
            print(2)
            return
        
        if x == 0:
            print(3)
            return
        
        if b1%x == 0:
            y2 = b1/x - b
    
            if y2.is_integer():
                # assert y2 == a1/x - a
                # print(y2)
                if c+y2 == c1 or c*x == c1 or (c+y2)*x == c1:
                    print(2)
                    return
                else:
                    min = 3
            else:
                min = 3

    print(3)
    return


for t in range(int(input())):
    
    p, q, r = map(int, input().split())
    
    a, b, c = map(int, input().split())
    
    if p == a:
        if q == b:
            if r == c:
                print(0)
                continue
            else:
                print(1)
                continue
        else:
            if r == c:
                print(1)
                continue
            else:
                print(check2(q, r, b, c))
                continue
    else:
        if q == b:
            if r == c:
                print(1)
                continue
            else:
                print(check2(r, p, c, a))
                continue
        else:
            if r == c:
                print(check2(p, q, a, b))
                continue
            else: 
            
                assert ((p != a) and ((q != b) and (r != c)))
                
                if p == 0:
                    if q == 0:
                        if r == 0:
                            if a == b and b == c:
                                print(1)
                                continue
                            elif a == b or b == c or c == a:
                                print(2)
                                continue
                            else:
                                print(3)
                                continue
                        else:   #p = q = 0, r != 0
                            d1 = c - r
                            if a == b and b == d1:
                                print(1)
                                continue
                            elif a == b or b == d1 or d1 == a:
                                print(2)
                                continue
                            else:
                                print(3)
                                continue
                    else:
                        if r == 0: #q!=0 , p = r = 0
                            d2 = b - q
                            if a == c and c == d2:
                                print(1)
                                continue
                            elif a == c or c == d2 or d2 == a:
                                print(2)
                                continue
                            else:
                                print(3)
                                continue
                        else:
                            assert (( q!= 0) and (r != 0))
                            # print(2)
                            print(check_0_nz_nz(q, r, a, b, c))
                            continue
                            
                        
                else:
                    if q == 0:
                        if r == 0: #p != 0, q = r = 0
                            d3 = a - p
                            if b == c and c == d3:
                                print(1)
                                continue
                            elif b == c or c == d3 or d3 == b:
                                print(2)
                                continue
                            else:
                                print(3)
                                continue
                        else:
                            assert (( p != 0) and (r != 0))
                            # print(2)
                            print(check_0_nz_nz(p, r, b, a, c))
                            continue
                    
                    else:
                        if r == 0:
                            assert (( p!= 0) and (q != 0))
                            print(check_0_nz_nz(q, p, c, b, a))
                            # print(2)
                            continue
                        else:
                            assert p != 0 and q != 0 and r != 0
                            
                            d_a, d_b, d_c = a - p, b - q, c - r
                            
                            q_a, q_b, q_c = a/p, b/q, c/r
                            
                            if d_a == d_b and d_b == d_c:
                                print(1)
                                continue
                            elif q_a.is_integer() and q_b.is_integer() and q_c.is_integer() and q_a == q_b and q_b == q_c:
                                print(1)
                                continue
                            elif d_a == d_b or d_b == d_c or d_c == d_a:
                                print(2)
                                continue
                            elif q_a.is_integer() and q_b.is_integer() and q_c.is_integer() and (q_a == q_b or q_b == q_c or q_c == q_a):
                                print(2)
                                continue
                            else:
                                # print("check3")
                                check3(p,q,r,a,b,c)
                                # print(3)
                                continue
    
    print(3)

                                
    
    
    
    
    
    
    
    