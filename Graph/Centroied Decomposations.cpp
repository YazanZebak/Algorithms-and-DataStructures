int P[N] , subTree[N] ;
bool blocked[N] ;
vector < int > G[N] ;

void get_size(int u , int p){

     P[u] = p ;
     subTree[u] = 1;
     for(auto v : G[u]){
          if(v == p || blocked[v]) continue ;
          get_size(v , u) ;
          subTree[u] += subTree[v] ;
     }
}

void get_centroid(int src){

   get_size(src , src) ;

   int centroid = src , best = subTree[src] ;
   queue < int > Q ;
   Q.push(src) ;

   while(!Q.empty()){
         int u = Q.front() ;
         Q.pop() ;

         int size = subTree[src] - subTree[u] ;
         for(auto v : G[u]){
               if(v == P[u] || blocked[v]) continue ;
               Q.push(v) ;
               size = max(size , subTree[v]);
         }

         if(best > size){
              best = size;
              centroid = u ;
         }
   }

   blocked[centroid] = true ;

   for(auto v : G[centroid]){
        if(blocked[v]) continue ;
        get_centroid(v) ;
   }

}