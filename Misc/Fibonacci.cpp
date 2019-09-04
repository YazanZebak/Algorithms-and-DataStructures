// Fn = Fn-1 + Fn-2 
// 0,1,1,2,3,5,8,13,21,34,55,89,...
// The "addition" rule: Fn+k = Fk * Fn+1 + Fk-1 * Fn, F2n = Fn(Fn+1 + Fn-1)
// Fnk is multiple of Fn
// GCD(Fm, Fn)= F(GCD(m,n)) good for intervals problems 


pair<ll, ll> fib(ll n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    ll c = p.first * (2 * p.second - p.first);
    ll d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}