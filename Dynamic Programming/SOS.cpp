
void build(){

	for(int i = 0 ; i < (1 << N) ; ++i)
		dp[i] = A[i];

	for(int i = 0 ; i < N ; ++i) for(int mask = 0 ; mask < (1 << N) ; ++mask){
		if(mask & (1 << i))
			dp[mask] += dp[mask ^ (1 << i)];
	}
	
}