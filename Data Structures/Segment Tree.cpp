
struct node {
    int mx , mn;
    node(int mx , int mn) : mx(mx) , mn(mn) {}
    node() {
        mx = -inf , mn = inf;
    }
} tree[N << 2] ;

int lazy[N << 2];

void build(int s = 0 , int e = n - 1 , int p = 1) {
    if(s == e)
        return (void) (tree[p] = node(ve[s] , ve[s])) ;
    build(s , (s + e)/2 , 2 * p);
    build((s + e)/2 + 1 , e , 2 * p + 1);
    tree[p].mx = max(tree[2 * p].mx , tree[2 * p + 1].mx) ;
    tree[p].mn = min(tree[2 * p].mn , tree[2 * p + 1].mn) ;
}

void pushLazy(int s , int e , int p){

    if(lazy[p]) {
        tree[p].mx += lazy[p];
        tree[p].mn += lazy[p];
        if(s != e) {
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        }
        lazy[p] = 0 ;
    }

}

node RMQ(int l , int r , int s = 0 , int e = n - 1 , int p = 1) {

	pushLazy(s , e , p) ; 

    if(s > r || e < l) return node(-inf , inf);

    if(s >= l && e <= r) return tree[p] ;

    node left = RMQ(l , r , s , (s + e)/2 , 2 * p) ;
    node right = RMQ(l , r , (s + e)/2 + 1 , e , 2 * p + 1) ;
    return node(max(left.mx , right.mx) , min(left.mn , right.mn));
}

void update(int l , int r , int val , int s = 0 , int e = n - 1 , int p = 1) {
  
    pushLazy(s , e , p) ;

    if(s > r || e < l) return ;

    if(s >= l && e <= r) {
    	lazy[p] += val ;
    	pushLazy(s, e, p);
        return ;
    }

    update(l , r , val , s , (s + e)/2 , 2 * p) ;
    update(l , r , val, (s + e)/2 + 1 , e , 2 * p + 1) ;
    tree[p].mx = max(tree[2 * p].mx , tree[2 * p + 1].mx) ;
    tree[p].mn = min(tree[2 * p].mn , tree[2 * p + 1].mn) ;
}

void setVal(int val , int pos , int s = 0 , int e = n - 1 , int p = 1) {

	pushLazy(s , e , p) ;
    
    if(s > pos || e < pos) return ; 

    if(s == e)
        return (void) (tree[p] = node(val , val));

    setVal(val , pos , s , (s + e)/2 , 2 * p);
    setVal(val , pos , (s + e)/2 + 1 , e , 2 * p + 1);

    tree[p].mx = max(tree[2 * p].mx , tree[2 * p + 1].mx) ;
    tree[p].mn = min(tree[2 * p].mn , tree[2 * p + 1].mn) ;
}
