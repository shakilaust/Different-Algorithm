/* Algo 
1 . For each node find the minimum incoming edge except root 
2 . Look for cycle if there is no cycle its MST 
3 . If cycle then consider one cycle as a one single vertex , give every vertex a new indx  and again recalculate the every edge 
4 . goto step 2 
*/

#define INF 1<<29
const int Maxn = 1005 ; // Highest Vertex
struct edge
{
    int u , v , w ;
    edge() {}
    edge(int _u, int _v , int _w ) { u = _u , v = _v , w = _w ; }
};
int nV , nE , root ; // nV = number of vertex , nE = number of edge , root is root
int vis[Maxn] , parnt[Maxn] ; // vis[] will store from which cycle it belogs , pre[] store its parnt
int Idx[Maxn] ; // will store new indxing Id
int dis[Maxn] ; // store the lowest incoming edge of a root
vector < edge > adj ;
void DMST()
{
    int Res  = 0 , i , u ,  v , w  ;
    while(1)
    {
        int i  ;
        rep(i,nV)
        {
            dis[i] = INF ;
            vis[i] = -1 ;
            Idx[i] = -1 ;
        }
        rep(i,nE)
        {
            u = adj[i].u ;
            v = adj[i].v ;
            w = adj[i].w ;
            if ( u != v && dis[v] > w) // lowest Incoming Edge
            {
                parnt[v] = u ;
                dis [v] = w ;
            }
        }
        parnt[root] = root ;
        dis[root] = 0 ;
        rep(i,nV)
        {
            if ( dis[i] == INF )
            {
                puts("impossible"); // its not possible to reach
                return ;
            }
            Res += dis[i];
        }
        int idx = 0 ;
        // cycle detection
        rep(i,nV)
        {

            if(vis[i]==-1) // not yet visited
            {
                int cur = i ;
                while ( vis[cur]==-1)
                {
                    vis[cur] = i ;
                    cur = parnt[cur] ;
                }
                if ( cur == root || vis[cur] != i )  continue ; // not cycle
                Idx[cur] = idx ; // new indexing
                for (  u = parnt[cur] ; cur != u ; u = parnt[u] )
                Idx[u] = idx ;
                idx++;
            }
        }
        if(idx==0) break ; // no cycle
        for ( i = 0 ; i < nV ; i++ )
        {
            if(Idx[i]==-1) // yet not find any grp
            {
                Idx[i] = idx++;
            }
        }
        rep(i,nE)
        {
            adj[i].w -= dis[adj[i].v];
            adj[i].u = Idx[adj[i].u] ;
            adj[i].v = Idx[adj[i].v];
        }
        nV = idx++;
        root = Idx[root];
    }
    printf("%d\n",Res);
}
int main()
{
    int cs , t  ;
    read(t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        read(nV) , read(nE) , read(root) ;
        int i , u , v , w ;
        adj.clear();
        rep(i,nE)
        {
            read(u) , read(v) , read(w) ;
            adj.pb(edge(u,v,w));
        }
        printf("Case %d: ",cs);
        DMST();
    }
   return 0;
}
