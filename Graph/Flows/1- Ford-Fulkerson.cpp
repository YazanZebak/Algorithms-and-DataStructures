// Complexity O(E * Flow)

int dfs(int src , int sink , int len , int flow){

	path[len] = src ;
	if(src == sink){
		  pathLen = len + 1 ;
		  return flow ; 
	}

	int ret = 0 ; 
	vis[src] = 1 ;

	for(int i = 1 ; i <= n ; i++){
		  if(vis[i] || cap[src][i] <= 0) continue ; 
		  ret = dfs(i , sink , len + 1 , min(flow , cap[src][i]));
		  if(ret > 0) break ; 
	}

	return ret; 
}

int maxFlow(int src , int sink){

	int flow = 0 ;
	int new_flow ; 

	while(new_flow = dfs(src , sink , 0 , INT_MAX)){
		  memset(vis , 0 , sizeof vis);
		  flow += new_flow ; 
		  for(int i = 1 ; i < pathLen ; i++){
		  	    int prev = path[i - 1] , cur = path[i];
		  	    cap[prev][cur] -= new_flow ;
		  	    cap[cur][prev] += new_flow ;
		  }
	}

	return flow ; 
}