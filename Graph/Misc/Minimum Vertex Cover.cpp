// select the smallest possible set of vertices C
// such that each edge of the tree is incident to at least one vertex of the set C

int MVC(int node , bool flag) {

    int &ret = memo[node][flag] ;

    if(ret != -1) return ret ;

    else if(G[node].size() == 0) // is true if node is a leaf, false otherwise
         ret = flag ;            // 1 / 0 = taken / not

    else if(flag) { // if node is taken
        ret = 1 ;
        for(auto child : G[node]){
            // take the minimum between taking or not taking its children
            ret += min( MVC(child , 1) , MVC(child , 0) ) ;
        }
    }

    else {  // if node is not taken
        ret = 0 ;
        for(auto child : G[node]){
            // we must take its children
            ret += MVC( child , 1);
        }
    }

    return ret ;
}

// select the smallest possible set of vertices C
// such that each node of the tree is incident to at least one vertex of the set C

void dfs(int node , int parent){

      for(auto child : G[node]){

            if(child == parent) continue ;
            dfs(child , node);

            if(!res[child]) res[node] = 1; // if the child not taken we have to take it's parent
            else if(res[child] == 1 && res[node] != 1) res[node] = 2 ; // if the child taken mark it's parent as taken
      }
}

void solve(){
     dfs(1 , -1) ;
     if(!res[1]) res[1] = 1 ;
     for(int i = 1 ; i <= n ; i++) res[i] = (res[i] & 1) ;
}
