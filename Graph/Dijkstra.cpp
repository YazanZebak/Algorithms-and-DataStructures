
int Dijkstra(int src , int dest = -1) { 

    vector < int > dist(G.size() , OO) ;
    priority_queue < edge > Q ;

    dist[src] = 0 ;
    Q.push( edge(-1 , src , 0) );

    while(!Q.empty()) {

        edge e = Q.top() ;
        Q.pop();

        if(e.w > dist[e.to]) continue ;

        for(auto ne : G[e.to]) {
            if(dist[ne.to] > dist[ne.from] + ne.w) {
                ne.w = dist[ne.to] = dist[ne.from] + ne.w ;
                Q.push(ne);
            }
        }
    }
    return dest == -1 ? -1 : dist[dest] ;
}


int Dijkstra(int src , int dest = -1) { 

    vector < int > dist ((int)G.size() , OO) ;
    priority_queue < pair < int , int > , vector < pair < int , int > > , greater < pair < int , int > > > Q ;

    Q.push({0 , src});
    dist[src] = 0 ;

    while(!Q.empty()) {

        pair < int , int > p = Q.top();
        Q.pop() ;

        int node = p.second , weight = p.first ;

        if(weight > dist[node]) continue ;

        for(auto i : G[node]) {

            int child = i.first ;
            int w = i.second ;
            if(dist[child] > dist[node] + w ) {
                dist[child] = dist[node] + w ;
                Q.push( { dist[child] , child } );
            }
        }
    }

    return dest == -1 ? -1 : dist[dest];
}
