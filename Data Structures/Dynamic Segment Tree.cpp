
struct node {
	node *left , *right;
	ll sum , lazy ; 
	node() {
		left = right = 0 ; 
		sum = lazy = 0 ; 
	} 
};

void pushLazy(node *cur , int &s , int &e) {
	if (cur->lazy) {
		if(cur->left == 0) cur->left = new node(); 
		if (cur->right == 0) cur->right = new node();
		cur->left->lazy += cur->lazy;
		cur->right->lazy += cur->lazy;
		cur->sum += (e - s + 1) * cur->lazy;
		cur->lazy = 0; 
	}
}

void update(node *&cur, int l, int r, int val, int s = 1, int e = n) {
	if (cur == 0) cur = new node(); 
	
	pushLazy(cur , s , e);
	
	if (l > e || r < s) return ; 
	
	if (l <= s && r >= e) { 
		cur->lazy = val; 
		pushLazy(cur,s,e); 
		return ; 
	}

	int mid = (s + e) / 2;
	update(cur->left, l, r, val, s, mid); 
	update(cur->right, l, r, val, mid + 1, e); 
	cur->sum = cur->left->sum + cur->right->sum;
}

ll query(node *cur, int l, int r, int s = 1, int e = n) {
	
	if (cur == 0) return 0; 

	pushLazy(cur, s, e);
	
	if (l > e || r < s) return 0; 
	
	if (l <= s && r >= e) return cur->sum; 
	
	int mid = (s + e) / 2 ;  
	ll c1 = query(cur->left, l, r, s, mid); 
	ll c2 = query(cur->right, l, r, mid + 1, e); 
	return c1 + c2; 
}