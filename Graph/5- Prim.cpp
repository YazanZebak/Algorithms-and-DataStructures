
struct edge{
	int from , to , w;
	edge(){}
	edge(int from, int to, int w) : from(from), to(to), w(w) {}
	bool operator < (const edge &e){
		 return w > e.w ;
	}
};

pair < int , vector < edge > > prim(int n) { 

    int mst = 0 ;
    vector < int > vis(n , 0);
    vector < edge > edges ;

    priority_queue < edge > Q ;
    Q.push( edge(-1 , 0 , 0) ) ;

    while(!Q.empty()) {
        edge e = Q.top() ;
        Q.pop() ;

        if(vis[e.to]) continue ;
        vis[e.to] = 1 ;
        mst += e.w ;
        if(e.to) edges.push_back(e);

        for(auto ne : G[e.to]) {
            if(!vis[ne.to])
                Q.push( ne ) ;
        }
    }

    if(edges.size() != n - 1) return make_pair(mst , vector < edge >()) ;
    return make_pair(mst , edges) ;
}

