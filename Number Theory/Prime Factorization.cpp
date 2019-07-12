
vector < int > factorization(ll n) { 

    vector < int > primeFactors;

    ll PF_idx = 0 , PF = primes[PF_idx] ;

    while(PF * PF <= n) {
        while(n % PF == 0) primeFactors.push_back(PF) , n /= PF ;
        PF = primes[++PF_idx];
    }

    if(n > 1)
        primeFactors.push_back(n);

    return primeFactors ;
}

vector < int > factorization(ll n){

	 vector < int > primeFactors ; 

	 for(int i = 2 ; i * i <= n ; i++){
	 	    while(n % i == 0) primeFactors.push_back(i) , n /= i ;
	 }
	 if(n > 1) primeFactors.push_back(n);

	 return primeFactors;  
}