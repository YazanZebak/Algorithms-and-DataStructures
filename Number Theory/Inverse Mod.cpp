//! Inverse Mod in Line (b/a)%mod
inline ll inv(ll a, ll mod){
    return a > 1 ? mod - inv(mod % a, a) * mod / a : 1;
}

//! Extended Euclid : Inverse Mod (x/y)%z
pair<ll, pair<ll, ll> > extendedEuclid(ll a, ll b){
    if(a == 0) return make_pair(b, make_pair(0, 1));
    pair<ll, pair<ll, ll> > p;
    p = extendedEuclid(b % a, a);
    return make_pair(p.first, make_pair(p.second.second - p.second.first*(b/a), p.second.first));
}

ll modInverse(ll a , ll m){
    return (extendedEuclid(a,m).second.first + m) % m;
}

ll inverseMod(ll x , ll y , ll z){
    return ( (x%z)*modInverse(y,z) )%z ;
}
