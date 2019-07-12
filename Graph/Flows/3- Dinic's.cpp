// Complexity : O(V^2E)

struct edge{
    int to , cap , rev;
    edge(){}
    edge(int to , int cap,  int rev) : to(to) , cap(cap) , rev(rev) {}
};

void add_edge(int from , int to , int cap){
    G[from].push_back(edge(to , cap , G[to].size()));
    G[to].push_back(edge(from , 0 , G[from].size() - 1));
}

vector < edge > G(10201);
int level[10201];
void bfs(int s){
    memset(level , -1 , sizeof(level));
    queue < int > Q;
    level[s] = 0;
    Q.push(s);
    while(Q.size()){
        int v = Q.front();
        Q.pop();
        for(auto &e : G[v]){
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v] + 1;
                Q.push(e.to);
            }
        }
    }
}

int dfs(int v , int sink , int flow){
    if(v == sink) return flow;
    for(auto &e : G[v]){
        if(e.cap > 0 && level[v] < level[e.to]){
            int d = dfs(e.to , sink  , min(flow , e.cap) );
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int src , int sink){
    int flow = 0;
    while(true){
        bfs(src);
        if(level[sink] < 0)
            return flow;
        int f;
        while( (f = dfs(src , sink , INT_MAX)) > 0){
            flow += f;
        }
    }
    return flow;
}
