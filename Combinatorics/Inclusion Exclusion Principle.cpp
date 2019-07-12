// Inclusion-Exclusion Principle
//
// Most of counting involves duplicate counting issue [count item more than once].
// IE principle is a generic sum rule to solve that.
//
// General Computations:
// - Enumerate all subsets
// - Compute each one intersection
// - If odd subset add (include) it
// - If even subset subtract (exclude) it

// E.g : How many integers in {1 , 2 , ..... , n} are divisible by arr[]  
ll inc_exe(int idx = 0 , ll d = 1 , int sign = -1){
    if(idx == sz){
        if(d == 1) return 0 ; // nothing selected
        return sign * n/d ;
    }
    return inc_exe(idx + 1 , d , sign) + inc_exe(idx + 1 , (d * arr[idx])/__gcd(d , arr[idx]) , sign * -1);
}
