// n! % x  where x <= n -> 0
// Wilson theorem: (p - 1)! % p = p IFF p is prime


// Find maximum x where: p^x divides n!, and p is prime!
int factorialPrimePower(int n , int p){
	int ret = 0;
 	while(n){
  	     ret += (n / p);
  	     n /= p ; 
 	}
	return ret ;
}


struct Power{
    int base , power ;
    Power(int base , int power) : base(base) , power(power) {}
};

vector < Power > factorialPrimeFactor(int n){

    vector < Power > ret ;
    for(auto p : primes){
         int power = factorialPrimePower(n , p);
         if(power)
              ret.push_back(Power(p , power));
    }

    return ret ;
}

vector < Power > getPrimeFactor(int n){

     vector < Power > ret ;
     for(int i = 2 ; i * i <= n ; i++){
           int cnt = 0 ;
           while(n % i == 0) n /= i , cnt++ ;
           if(cnt) ret.push_back(Power(i , cnt));
     }
     if(n > 1) ret.push_back(Power(n , 1));

     return ret ;
}

// Find maximum x where: m^x divides n!. (general situation)
int factorialNumberPower(int n , int a){

    vector < Power > factorA = getPrimeFactor(a);
    vector < Power > factorN = factorialPrimeFactor(n);

    int maxPower = (1 << 30) ;
    for(auto i : factorA){
          bool ok = 0 ;
          for(auto j : factorN){
                if(i.b == j.b){
                      ok = 1 ;
                      maxPower = min(maxPower , j.p / i.p);
                      break ;
                }
          }

          if(!ok) return 0 ;
    }

    return maxPower ;
}


// how many trailing zero in N!?
// how zero come in base 10? 2*5
// then if we know N! = 2^a * 5^b * etc... then we have min(a , b) zero
// #2 > #5 => min(a , b) = b
// what about n! base x? how many zeros?
// again every time n! has X , we have another zero
// factorize X , check its primes power in n!