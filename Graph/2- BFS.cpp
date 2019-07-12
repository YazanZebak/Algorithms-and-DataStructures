
vector < int > bfs(int src) {

    vector < int > dist((int)G.size() , inf);
    queue < int > Q ;

    dist[src] = 0 ;
    Q.push(src) ;

    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        
        for(auto child : G[node]) {
            
            if(dist[child] > dist[node] + 1) {
                dist[child] = dist[node] + 1 ;
                Q.push(child) ;
            }
        
        }
    }

    return dist ; 
}

// if and only if our edges weights can only be 0 and x (x >= 0)
void zeroOneBfs(int src) { 

    vector < int > dist((int)G.size() , OO) ;

    deque < int > Q ;
    dist[src] = 0 ;
    Q.push_back(src) ;

    while(!Q.empty()) {
        int node = Q.front() ;
        Q.pop_front() ;

        for(auto i : G[node]) {

            int child = i.first ;
            int weight = i.second ;

            if(dist[child] > dist[node] + weight) {  
                dist[child] = dist[node] + weight ;
                if(weight == 0)
                    Q.push_front(child) ;
                else
                    Q.push_back(child) ;
            }
        }
    }
}

