
// Partial Sum on Tree
// Having a rooted tree, each vertex has a value (initially 0), each query gives you numbers v and u (v is an ancestor of u)
// and asks you to increase the value of all vertices in the path from u to v by 1.
// we have an array p, and for each query, we increase p[u] by 1 and decrease p[par[v]] by 1

void dfs(int node , int parent){

      for(auto child : G[node]){
            if(child == parent) continue ;
            dfs(child , node);      
            pre[node] += pre[child] ;
      }
}
