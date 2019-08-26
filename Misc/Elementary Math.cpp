const double PI = acos(-1);
const double e = exp(1.0) ;
const double phi = (1.0 + sqrt(5.0))/2.0 ;
const double inf = std::numeric_limits<double>::infinity();
const double nan = std::numeric_limits<double>::quiet_NaN();

//! get length of digits before cycle of a/b
void solve(int a , int b) {

    int result = a/b , remainder = a%b , index = 0 ;
    map < int , int > remainderIndex ;
    vector < int > digits ;

    while(!remainderIndex.count(remainder)) {
        remainderIndex[ remainder ] = index++ ;
        result = remainder * 10 / b ;
        digits.push_back( result );
        remainder = (remainder * 10) % b  ;
    }

    int cycleStartIndex = remainderIndex[ remainder ];
    int cyclSize = index - cycleStartIndex ;
}


// round : nearest integer to x
// ceil  : round up
// floor : round down
// trunc : round toward zero ( remove fraction )

// Warning!! : round(4.5) = 5
// round(x , m) * m == greatest multiple of m smaller than x
int integer_round(int x , int y){
    (x > 0 ? (x + y/2)/y : (x - y/2)/y) ;
}

int integer_ceil(int x , int y){
    return (x + y - 1)/y ;
}

void logArithmetic() {
   // logb( sqrtP(x) ) =  logb(x) / p;
   // b = 1 / (x ^ logb(x)) ;
   // x * ( b ^ y ) = b ^ ( logb( x ) + y );
}

//! power comparison a^b ? c^d
int comp(int a , int b , int c , int d){
     double c1 = b * log(a) , c2 = d * log(c) ;
     if(c1 - c2 < 0) return -1 ;
     else if(c1 - c2 > 0) return 1 ;
     else 0
}

double logBase(double base , double x) {
    return (log(x) / log(base));
}

long double fib(ll n){
	 return ( pow(phi , n) - pow(1 - phi , n) ) / sqrt(5.0);
}

//  ( a * b ) % m 

typedef long long unsigned int llu;
typedef long long int ll ;
typedef long double ld;
 
llu mul_mod(llu a, llu b, llu m){
   llu y = (llu)((ld)a*(ld)b/m+(ld)1/2);
   y = y * m;
   llu x = a * b;
   llu r = x - y;
   if ( (ll)r < 0 ){
      r = r + m; y = y - 1;
   }
   return r;
}