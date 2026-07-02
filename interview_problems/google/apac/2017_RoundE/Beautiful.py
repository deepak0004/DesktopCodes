def get_base(N, n):
    low = 2
    high = int(pow(N, 1.0 / (n-1))) + 4
    ans = -1
    base = -1
    
    while(low <= high):
        mid = (low + high) / 2
        A = (mid ** n - 1) / (mid - 1)
        if(N >= A):
            ans = A
            base = mid
            low = mid + 1
        else: 
        	high = mid - 1
        
    if ans == N: 
    	return base
    else: 
    	return -1

T = raw_input()
T = int(T)
for t in range(1, T+1):
    n = raw_input(); 
    n = int(n)
    
    a = n-1
    for l in range(3, 64+1):
        x = get_base(n, l)
        if(x != -1): 
        	a = x    
    
    print "Case #" + str(t) + ": " + str(a)