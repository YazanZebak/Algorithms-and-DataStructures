

vector< vector< int > > G ; 
vector< int > vis, colAssign, rowAssign;

// matrix rows = top , cols = bottom 
// G[rows][cols]

bool canMatch(int u) { // O(E)

    for(int v = 0 ; v < G[u].size() ; v++){
         if(!G[u][v] || vis[v]) continue ;  
         vis[v] = 1 ;

         if(colAssign[v] < 0 || canMatch(colAssign[v])){
         	   colAssign[v] = u , rowAssign[u] = v ;
         	   return true; 
         }
    }

    return false;
}

vector< pair<int, int> > bipartiteMatching() {	// O(EV)
    // In case spares graph, use adjList
    vector< pair<int, int> > matches;

    if(G.size() == 0)
        return matches;

    int maxFlow = 0, rows = G.size() , cols = G[0].size();
    colAssign = vector<int> (cols, -1), rowAssign = vector<int> (rows, -1);

    for(int u = 0 ; u < rows ; u++) {
        vis = vector<int> (cols, 0);
        if( canMatch(u)  )
            maxFlow++;
    }

    for(int j = 0 ; j < cols ; j++) if(colAssign[j] != -1)
        matches.push_back( make_pair(colAssign[j], j));
   
    /*
    vector< vector<int> > mnPathCvs;

    lp(j, n) if(colAssign[j] == -1) {
    	vector<int> v(1, j+1);
    	int t = rowAssign[j];
    	while(t != -1) {
    		v.push_back(t+1);
    		t = sz(v)%2 ? rowAssign[j] : colAssign[j] ;
    	}
    	mnPathCvs.push_back(v);
    }
    rep(i, mnPathCvs)
    {
    	rep(j, mnPathCvs[i])
    		cout<<mnPathCvs[i][j]<<" ";
    	cout<<"\n";
    }
    */

    return matches;
}

