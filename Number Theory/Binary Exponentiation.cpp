

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
	for( ; y; y >>= 1){
		if(y & 1) res = (res * a) % m;
		x = (x * x) % m;
	}
	return res ; 
}

ll mult64(ll a, ll b, ll m) {
  a %= m, b %= m;
  ll ret = 0;
  for (; b; b >>= 1) {
    if (b & 1) ret = (ret + a) % m;
    a = (a + a) % m;
  }
  return ret;
}