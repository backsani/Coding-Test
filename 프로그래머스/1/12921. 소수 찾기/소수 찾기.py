def solution(n):
    answer = 0
    
    a = [True] * (n+1)
    a[0] = False
    a[1] = False
    
    for k in range (2,n+1):
        if a[k] == True:
            i=k
            while i<=(n-k):
                a[k+i]=False
                i=i+k
                
        else:
            a[k] = False
            
    count_true = sum(a)
    
    return count_true