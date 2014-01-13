struct Graph
{
    int node , cost ;
    Graph() {}
    Graph ( int n , int c )
    {
        node = n ;
        cost = c ;
    }
    // sorting inorder to increasing order of cost
    bool operator < ( const Graph &A) const
    {
        return A.cost < cost ;
    }
};

vector < pii > adj[15];

bool visit[15];

int N , dis[15] ,path[15]  ;
void Clean()
{
    int i ;
    FOR(i,1,N) adj[i].clear() , visit[i] = 0  , dis[i] = INF , path[i] = -1 ;
}
// printing path
void rasta(int node)
{
    if( path[node]==-1)
    {
        printf("%d",node);
        return ;
    }
    rasta(path[node]);
    printf(" %d",node);
}
// Basic Dijkstra Code 
void Dijkstra(int s , int d )
{
     priority_queue < Graph > pq ;
     pq.push(Graph(s,0));
     dis[s] = 0 ;
     while(!pq.empty())
     {
         Graph prev = pq.top();
         pq.pop();
         if(visit[prev.node]) continue ; // already discover
         visit[prev.node] = 1 ;

         int i ,  u = prev.node , c = prev.cost ;
         if( u == d ) break ; // reach destination
         int sz = adj[u].size();
         rep(i,sz)
         {
             int v = adj[u][i].first ; // node to go
             int tmp = adj[u][i].second ; // cost between them
             if ( dis[v] > dis[u] + tmp )
             {
                 dis[v] = dis[u] + tmp ;
                 path[v] = u ; // parent ;
                 pq.push(Graph(v,dis[v]));
             }
         }
     }
     
}
