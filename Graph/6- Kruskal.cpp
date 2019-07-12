
pair < int , vector < edge > > Kruskal(int n) { 

      UnionFind tree(n) ;
      vector < edge > edges ;
      int mstCost = 0 ;
      priority_queue < edge > Q  ;
      for(auto e : edge_list) Q.push(e);

      while(!Q.empty()) {
            edge e = Q.top() ; Q.pop() ;
            if( tree.union_set(e.from , e.to) ){
                 mstCost += e.w ;
                 edges.push_back(e);
            }
      }

      if(edges.size() != n - 1) return make_pair( -1 , vector < edge > () ) ;
      return make_pair( mst_cost , edges );
}

// Second MST
// 1) find MST
// 2) for each edge in MST tree
//      3) remove edge from graph
//      4) run MST , compare it for min value
//      5) Back the edge for graph
// 6) Display MST2 value


// Partial MST ( Minimum Spanning Subgraph )
// 1) for each already built edge
//      2) union it
// 3) for all edges new
//      4) run Kruskal

// Minimax (Maxmin)
// The minimax path problem is a problem of finding the minimum of maximum edge weight ,
// among all possible paths between two vertices i to j.
// get the MST and then traversal on tree and get the answer/

// you are given a complete graph consisting of n vertices numbered from 0 to n - 1.
// For all 0 <= u < v < n , vertex u and vertex v are connected with an undirected edge that has weight (u XOR v)
// find the weight of the minimum spanning tree of that graph
// a[n + 1] = b[n] : b(2n) = 2b(n) + n , b(2n + 1) = 2b(n) + n + 1
ll mst(ll n){
   if(n == 1) return 1 ;
   if(n & 1) return 2 * mst(n / 2) + n / 2 + 1 ;
   return 2 * f(n / 2) + n / 2;
}
