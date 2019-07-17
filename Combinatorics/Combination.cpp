// Combinations : C(n , k) = n! / (k! * (n-k)!)
// Combinations with Repetition : C(n , r) = C(n + r - 1 , r) = C(n + r - 1 , n)

// Binomial Coefficients : (x + y)^n = sigma[ C(n ,k) * x^(n-k) * y^k ]
// Pascal Triangle : C(n , k) = C(n - 1 , k - 1) + C(n - 1 , k)

// Partitions with Order : N! / (r1! * r2! * .... rk!) ; r1 + r2 + ... + rk = n ; ri = size for each group
// Partitions Unordered  : N! / (r1! * r2! * .... rk!) * 1 / (c1! * c2! * ... * cn!) , ci = count of ri

// Bell Number : partition n object to whatever number of group = sigma[ stirling2(n , k) ]


// How many ways can you insert a series of values into a BST to form a specific tree?
// https://stackoverflow.com/a/17119117/7551287

// bottom up recurrence to build nCk table
void build(){
	for(int i = 0 ; i < MAX; ++i)
		for(int j = 0 ; j < MAX; ++j)
			C[i][j] = (j == 0) ? 1 : ( (i == 0) ? 0 : C[i - 1][j - 1] + C[i - 1][j]);
}

// Straight forward solution to calculate nCk
ll nCk(int n , int k){
      ll ans = 1 ;
      for(ll i = n ; i > n - k ; i--) ans *= i ;
      for(ll i = 2 ; i <= k ; i ++) ans /= i ;
      return ans ;
}

// partition n object to k non empty groups whatever groups sizes
ll stirling2(ll n , ll k){
   if(n == k || k == 1)
         return 1;
   return k * stirling2(n - 1 , k) + stirling2(n - 1 , k - 1) ;
}

// Combination concept can be related to : Exact / At most / At least
// Atmost(k) = SUM Exact(i) ; i = [0-k]
// Exact(k) = Atmost(k) - Atmost(k - 1)
// In range (start , end) =
// - SUM Exact(i) ; i = [start-end]
// - Atmost(end) - Atmost(start - 1)
// - Atleast(start) - Atleast(end + 1)
