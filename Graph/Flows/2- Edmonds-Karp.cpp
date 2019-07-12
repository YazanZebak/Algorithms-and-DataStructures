// Complexity O(VE^2)

int bfs(int src , int sink , vector < int > &parent){

	fill(parent.begin() , parent.end() , -1) ;
	parent[src] = -2 ; 

	queue < pair < int , int > > Q ; 
	Q.push({s , INT_MAX});

	while(!Q.empty()){
		 auto p = Q.front() ; 
		 Q.pop() ;
		 int u = p.first , flow = p.second ; 
		 for(int v = 1 ; v <= sink ; v++){
		 	  if(parent[v] != -1 || capacity[u][v] <= 0) continue ; 
		 	  parent[v] = u ;
		 	  int new_flow = min(flow , capacity[u][v]);
		 	  if(v == sink) return new_flow ;
		 	  Q.push({v , new_flow});
		 }
	}

	return 0 ;
}

int maxFlow(int src , int sink){

	int flow = 0 ;
	vector < int > parent(n + 1) ; 
	int new_flow ; 

	while(new_flow = bfs(src , sink , parent)){

		  flow += new_flow ; 
		  int cur = sink ; 
		  while(cur != src){
		  	  int prev = parent[cur] ;
		  	  capacity[prev][cur] -= new_flow ; 
		  	  capacity[cur][prev] += new_flow ; 
		  	  cur = prev ; 
		  }
	}

	return flow ; 
}