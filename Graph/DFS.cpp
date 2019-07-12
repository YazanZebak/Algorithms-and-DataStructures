
void dfs(int node) {
   
    visited[node] = true ;
   
    for(auto child : G[node]) {
        if(!visited[child])
            dfs(child);
    }

    topsort.push_back(node) ; // topological sort for DAG , otherwise is degree 
}

int dr[] = {0 , 1 , 0 , -1 , 1 , -1 , 1 , -1};
int dc[] = {1 , 0 , -1 , 0 , 1 , -1 , -1 , 1};

// Knight moves 
int dr[] = {1 , -1 , -2 , -2};
int dc[] = {-2 , -2 , 1 , -1};

void floodFill(int r , int c , char c1 , char c2) {
    if(r < 0 || r >= R || c < 0 || c >= C) return ;
    if(grid[r][c] != c1) return ;

    grid[r][c] = c2 ;
    for(int d = 0 ; d < 8 ; d++)
        floodFill(r + dr[d] , c + dc[d] , c1 , c2);
}

void dfsOrder(int node , int parent){

    start[node] = ++timer ; 

    for(auto child : G[node]){
         if(child == parent) continue ; 
         dfs(child , node) ;
    }

    finish[node] = timer - 1 ; 
}

bool isAncestor(int u , int v){
     return start[u] <= start[v] && finish[u] >= finish[v] ;
}
