
vector < int > getDivisors(ll n) { 

    vector < int > divisors;
    
    for(ll i = 1 ; i * i <= n ; i++) {
        if(n % i == 0) {
            divisors.push_back(i) ;
            if(n/i != i) divisors.push_back(n/i);
        }
    }

    return divisors ; 
}


ll countDivisors(ll n) {

    ll res = 1;
    ll PF_idx = 0 , PF = primes[PF_idx];
    
    while(PF * PF <= n) {
         ll cnt = 1;
         while(n % PF == 0) n /= PF , cnt++ ;
         res *= cnt ;
         PF = primes[++PF_idx];
    }
    
    if(n > 1)
         res *= 2 ;

    return res;
}