//BISMILLAHIRRAHMANIRRAHIM
/*

 Problem Link :: https://www.codechef.com/COOK64/problems/SEATR2
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 The true test of a man's character is what he does when no one is watching.
 Don't let your dreams be dreams.


 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::

*/

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

// Macro
#define eps 1e-9
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sq(a) ((a)*(a))
#define distance(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define iseq(a,b) (fabs(a-b)<eps)
#define eq(a,b) iseq(a,b)
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

double const EPS=3e-8;
using namespace std;

#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

// For loop

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");cout<<a[i][j];}cout<<endl;}

template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p){ return o<<"("<<p.ff<<", "<<p.ss<<")";} //Pair print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Vector print
template<class T> ostream& operator<<(ostream& o, const set<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Set print

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int M = 20000 ;


const int N = 500 ;


const Long mod = 1e9 + 7 ;

int cs , vis[ N + 2 ][ M + 2 ];
Long dp[ N + 2 ][ M + 2 ];

int n , m ;

vector < int > adj[ N + 5 ];


void DP( int x , int par )
{
    for( int i = 1 ; i <= m ; i++ ) dp[ x ][ i ] = 1 ;
    int sz = adj[x].size();
    for( int i = 0 ; i < sz ; i++ )
    {
        int u = adj[x][i];
        if( u == par ) continue ;
        DP( u , x );
        for( int j = 1 ; j <= m ; j++ )
        {
            Long tot = 0 ;
            for( int k = j ; k <= m ; k += j )
            {
                tot += dp[ u ][ k ];
                if( tot >= mod ) tot %= mod ;
            }
            dp[ x ][ j ] = ( dp[ x ][ j ] * tot )%mod ;
        }
    }
}




void ini()
{
    for( int i = 0 ; i <= n + 2 ; i++ ) adj[i].clear();
}




int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int t = II ;
    for( cs = 1 ; cs <= t ; cs++ )
    {
        n  = II , m = II ;
        ini();
        for( int i = 0 ; i < n - 1 ; i++ )
        {
            int x = II , y = II ;
            adj[x].pb( y );
            adj[y].pb( x );

        }
        DP( 1 , -1 );
        Long ans = 0 ;
        for( int i = 1 ; i <= m ; i++ )
        {
            ans += dp[ 1 ][ i ];
            if( ans >= mod )
            ans %= mod ;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
