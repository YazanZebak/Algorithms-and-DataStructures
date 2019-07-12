

// Recursive 
ll bigMod(ll x , ll y , ll m){
    if (y == 0)
        return 1 % m;
    if (y % 2 == 0){
        ll temp = bigMod(x, y / 2, m);
        return (temp*temp) % m;
    }
    return (x%m * bigMod(x, y - 1, m)) % m;
}

// Iterative
ll bigMod(ll x , ll y , ll m){
	ll res = 1 ; 
	while(y){
		 if(y & 1) 
		 	  res = (res * x) % m ; 
		 y /= 2 ; 
		 x = (x * x) % m ; 
	}
	return res ; 
}