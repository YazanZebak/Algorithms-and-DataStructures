vector < vector < int > > comps ;
int comp[N] , lowLink[N] , dfsn[N] ;
bool inStack[N];
stack < int > st ;

void scc(int u){
     dfsn[u] = lowLink[u] = num ++ ;
     inStack[u] = 1 ;
     st.push(u);

     for(auto v : G[u]){
           if(dfsn[v] == -1){
                scc(v);
                lowLink[u] = min(lowLink[v] , lowLink[u]);
           }
           else if(inStack[v])
                lowLink[u] = min(lowLink[v] , lowLink[u]);
     }

     if(lowLink[u] == dfsn[u]){
            comps.push_back(vector < int >());
            int v = -1 ;
            while(v != u){
                 v = st.top() , st.pop() , inStack[v] = 0 ;
                 comps.back().push_back(v);
                 comp[v] = comps.size() - 1 ;
            }
     }

}

void bridges(int u, int p){
     dfsn[u] = lowLink[u] = num ++ ;

     for(auto v : G[u]){
           if(dfsn[v] == -1){
                bridges(v, u);
                lowLink[u] = min(lowLink[v] , lowLink[u]);
           }
           else if(v != p)
                lowLink[u] = min(lowLink[u] , dfsn[v]);
     }

     if(lowLink[u] == dfsn[u] && p != -1){
         cout << "Bridge " << p << " " << u << endl ;      
     }

}