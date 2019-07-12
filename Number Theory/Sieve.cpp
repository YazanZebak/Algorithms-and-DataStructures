
void sieve() {

    isprime.set();
    isprime[0] = isprime[1] =  0 ;
    primes.push_back(2);

    for(int i = 3 ; i * i <= N ; i += 2)
        if(isprime[i])
            for(int j = i * 2 ; j <= N ; j += i) isprime[j] = 0 ;

    for(int i = 3 ; i <= N ; i += 2) if(isprime[i]) primes.push_back(i) ;
}

bool isPrime(ll n) { 
    if(n % 2 == 0) return (n == 2) ;

    else if(n < N) return isprime[n];

    for(int i = 0 ; i < (int)primes.size() ; i++)
        if(n % primes[i] == 0) return false;

    return true ;
}

bool isPrime(ll n) { 
    for(ll i = 2 ; i * i <= n ; i++)
        if(n % i == 0) return false ;
    return true ;
}