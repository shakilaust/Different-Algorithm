
/*
Code for compute distance between two node of a tree 
*/
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

/* **************************************  My code start here ****************************************** */
const int maxn = 40040 ;
typedef long long ll ;
vector < pair <int , int > > Adj[maxn];
int parnt[maxn][20] , Level[maxn] ;
ll dist[maxn];

void dfs(int to , int from , int lvl )
{
    Level[to] = lvl ;
    parnt[to][0] = from ;
    int sz = Adj[to].size();
    int i ;
    for ( i = 0 ; i < sz ; i++ )
    {
        int v = Adj[to][i].first;
        if( v == from ) continue ;
        dist[v] = dist[to] + Adj[to][i].second;
        dfs(v,to,lvl+1);

    }
}
void PreProcess(int n)
{
    int i , j ;
    for ( i = 0 ; i < n ; i++ )
    {
        for ( j = 0 ; ( 1 << j ) < n ; j++ ) parnt[i][j] = -1;
    }
    dfs(0,-1,0);
    for ( j = 1 ; (1 << j ) < n ; j++ )
    {
        for ( i = 0 ; i < n ; i++ )
        {
            if(parnt[i][j-1] != -1 )
            parnt[i][j] = parnt[parnt[i][j-1]][j-1];
        }
    }
}

int LCA(int a , int b)
{
    if( Level[a] < Level[b] ) swap(a,b) ; // a should have higher rank
    int lg , i;
    for ( lg = 1 ; ( 1 << lg ) <= Level[a] ; lg++ ) ;
    lg--;
    for ( i = lg ; i >= 0 ; i-- )
    {
        if( Level[a] - ( 1 << i ) >= Level[b] )
        {
            a = parnt[a][i];
        }
    }
    if( a == b ) return a ;
    for ( i = lg ; i >= 0 ; i-- )
    {
        if ( parnt[a][i] !=-1 && parnt[a][i] != parnt[b][i])
        {
            a = parnt[a][i] ;
            b = parnt[b][i] ;
        }
    }
    return parnt[a][0] ;
}

int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     int cs , t ;
     read(t);
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         int n , m , u , v , c , i;
         read(n) , read(m) ;
         for ( i = 0 ; i < n-1 ; i++ )
         {
             read(u) , read(v) , read(c);
             u-- , v--;
             Adj[u].pb(mp(v,c));
             Adj[v].pb(mp(u,c));
         }
         PreProcess(n);
         for ( i = 0 ; i < m ; i++ )
         {
             read(u) , read(v) ;
             u--, v--;
             c = LCA(u,v);
             cout<< dist[u] + dist[v] - 2*dist[c] << endl;
         }
         for ( i = 0 ; i < n ; i++ ) Adj[i].clear();
     }
   return 0;
}
