// P[u][j] is the (2^j)-th parent of u.
// L[u] is the level of u.

void dfs(int u , int p , int d) {
    P[u][0] = p ; // the first ancestor of node u
    L[u] = d;
    for(auto v : G[u]) {
        if(v == p)
            continue;
        dfs(v , u , d + 1);
    }
}

void dp() { 

    for (int i = 0; i < n ; ++i)
        for (int j = 1; (1 << j) < n ; ++j)
            P[i][j] = -1;

    for (int j = 1 ; (1 << j) < n ; ++j)
        for (int i = 0; i < n; ++i)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

int lca(int u, int v) { 

    if(L[u] < L[v])
        swap(u, v);

    int i , log ;
    for(log = 1 ; (1 << log) <= L[u] ; ++log);

    --log;

    for(i = log ; i >= 0 ; --i)
        if(L[u] - (1 << i) >= L[v])
            u = P[u][i];

    if(u == v)
        return u;

    for(i = log ; i >= 0 ; --i)
        if(P[u][i] != -1 && P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];

    return P[u][0];
}


// shortest path between u and v
ll calc(int u , int v) {
    return L[u] + L[v] - 2 * L[lca(u , v)] ;
}

// max , min , xor , gcd , lcm , ......
// dp[i][j] = (dp[i][j - 1] , dp[P[i][j - 1]][j - 1]) , dp[i][0] = weight( u , p[u][0] )
int query(int u , int v){

    int log ;
    for(log = 1 ; (1 << log) <= L[u] ; log++) ;
    log --  ;

    int ret = 0 ;
    for(int i = log ; i >= 0 ; i--)
         if(L[u] - (1 << i) >= L[v])
            ret = (ret , dp[u][i]) , u = P[u][i] ;

    return ret ;
}

// get the parent of u on given distance 
int query(int u , int dist){

    for(int i = 0 ; i < maxlog ; i++)
          if(dist & (1 << i))
               u = P[u][i] ;

    return u ;
}
