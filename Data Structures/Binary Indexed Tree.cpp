
struct BIT {

    vector<int> tree ;

    BIT(int n){
        tree = vector<int>(n, 0) ;
    }

    void update(int i , int add) {
        for( ; i < (int)tree.size() ; i += (i & (-i))) tree[i] += add ;
    }

    int sum(int i) {
        int ans = 0 ;
        for( ; i ; i -= (i & (-i))) ans += tree[i];
        return ans ;
    }

    // Search for a prefix sum (return Index) 
    int getKth(int val) {
    	
    	int sum = 0 , pos = 0 ;
    	
    	for(int i = LOG_N ; i >= 0 ; i--){
    		if(pos + (1 << i) < N && sum + tree[pos + (1 << i)] < val){
    			   pos += (1 << i);
    			   sum += tree[pos];
    		}
    	}

    	return pos + 1 ; // +1 because 'pos' will have position of largest value less than 'v'
    }

    int RSQ(int l , int r){
        return sum(r) - (l == 1 ? 0 : sum(l - 1));
    }

    void insert(int x) {
        update(x , 1);
    }

    void erase(int x) {
        update(x , -1);
    }

};

struct 2D_BIT {
	
	vector<vector<int>> tree;

	2D_BIT(int n , int m){
		tree = vector<vector<int>> (n);
		for(int i = 0 ; i < n ; i++) tree[i] = vector<int> (m, 0);
	}

    void update(int i , int j , int val){
    	 for( ; i < tree.size() ; i += (i & (-i)))
    	 	  for(int k = j ; k < tree.size() ; k += (k & (-k)))
    	 	    	tree[i][k] += val; 
    }

    int sum(int i , int j){
    	int ret = 0;
    	for( ; i >= 0 ; i -= (i & (-i)))
    		for(int k = j ; k >= 0 ; k -= (k & (-k)))
    			ret += tree[i][k];
    	return ret ; 
    }

    // (x1 , y1) top-left , (x2 , y2) bottom right
    int query(int x1, int y1, int x2, int y2){
    	return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 -1);
    }
};
