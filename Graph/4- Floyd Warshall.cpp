
void floydWarshall() {

    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            G[i][j] = (i == j) ? 0 : inf ;


    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            path[i][j] = i ;

    for(int k = 0 ; k < N ; k++) {
        for(int i = 0  ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                if(G[i][k] + G[k][j] < G[i][j]) path[i][j] = path[k][j] ; // get a path
                G[i][j] = min( G[i][j] , G[i][k] + G[k][j] ) ; // Shortest Path
                G[i][j] = max( G[i][j] , G[i][k] + G[k][j] ) ; // Longest Path on DAG
                G[i][j] |= (G[i][k] & G[k][j]) ; // check if a path exist or not
                G[i][j] = min( G[i][j] , max(G[i][k] , G[k][j])) ; // find a path such that maximum value on road is minimum
                G[i][j] = max( G[i][j] , min(G[i][k] , G[k][j])) ; // find a path such that minimum value on road is maximum
                G[i][j] += (G[i][k] * G[k][j]);  // Counting on DAG/Tree
            }
        }
    }

    // Finding the (Cheapest/Negative) Cycle
    // 1) adjMat[i][i] = inf ;
    // 2) Run Floyd Warshall
    // 3) bestCycle = min(bestCycle , adjMat[i][i]);
    // 4) if(bestCycle < 0) we have negtive cyele ;
    // 5) else print bestCycle
}

void print(int st , int en) {

    if(st != en)
        print(st , path[st][en]) ;
    
    printf(" %d", j);
}

bool isNegativeCycle() {

    for(int i = 0 ; i < N ; i++)
        if(G[i][i] < 0)
            return true ; // then node i get to i with overall cost < 0

    return false;
}

bool anyEffectiveCycle(int src , int dest) {

    for(int i = 0 ; i < N ; i++)
        if(G[i][i] < 0 && G[src][i] < inf && G[i][src] < inf)
            return true ;

    return false ; // there is a finite path although cycles if any
}

int diameter() {

    // Longest Path among all shortest ones
    // 1) Run Floyd Warshall

    int ret = 0 ;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            if(G[i][j] < inf)
                ret = max(ret , G[i][j]);

    return ret ;
}


vector < vector < int > > SCC() {

    vector < int > comp(N , -1) ;

    int cnt = 0 ;

    for(int i = 0 ; i < N ; i++) {
        if(comp[i] != -1) continue ;

        comp[i] = cnt ++ ;
        for(int j = 0 ; j < N ; j++)
            if(G[i][j] < inf && G[j][i] < inf) comp[j] = comp[i] ;
    }

    vector < vector < int > > compGraph(cnt , vector < int >(cnt)) ;

    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            if(G[i][j] < inf)
                compGraph[ comp[i] ][ comp[j] ] = 1 ; // DAG

    return compGraph;
}
