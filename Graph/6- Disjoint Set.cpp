struct UnionFind {

    vector < int > ranks , parent ;
    int forests ;

    UnionFind(int n) {
        ranks = parent = vector < int > (n) ;
        forests = n  ;
        for(int i = 0 ; i < n ; i++) parent[i] = i , ranks[i] = 1 ;
    }

    int find_set(int node) { 
        if(node == parent[node]) return node ;
        return parent[node] = find_set( parent[node] );
    }

    void link(int u , int v) {
        if(ranks[u] > ranks[v]) swap(u , v);
        parent[u] = v ;
        if(ranks[u] == ranks[v]) ranks[v]++ ;
    }

    bool union_set(int u , int v) { 
        u = find_set(u) , v = find_set(v);
        if(u != v) {
            link(u , v);
            forests-- ;
        }
        return u != v ;
    }

    bool same_set(int u , int v) {
        return find_set(u) == find_set(v) ;
    }
};
