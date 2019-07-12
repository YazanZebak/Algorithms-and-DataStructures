// https://codeforces.com/blog/entry/44351

const int N = 1e5 ;
int cnt[N];
bool big[N];

void add(int u , int p , int val){
	 cnt[ col[u] ] += val; 
	 for(auto v : G[u]){
	 	  if(big[v] || v == p) continue ; 
	 	  add(v , u , val);
	 }
}

void dfs(int u , int p , bool keep){

	int mx = -1 , bigChild = -1 ;
	for(auto v : G[u]){
         if(v == p) continue ;
         if(sz[v] > mx) {
         	   mx = sz[v];
         	   bigChild = v;
         }
	}

	for(auto v : G[u]){
         if(v == p || v == bigChild) continue ;
         dfs(v, u, 0);
	}

	if(bigChild != -1)
		 dfs(bigChild, u, 1) , big[bigChild] = 1;

	add(u , p , 1);

	if(bigChild != -1)
		 big[bigChild] = 0;
	if(keep == 0) 
		 add(u, p, -1);
}