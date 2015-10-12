//BISMILLAHIRRAHMANIRRAHIM
/*

 Problem Link :: https://www.hackerearth.com/tracks/pledge-2015-medium/tree-coloring/
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 The true test of a man's character is what he does when no one is watching.


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

template< class T > T gcd(T a, T b)
{
    return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b)
{
    return (a / gcd<T>(a, b) * b);
}

//Fast Reader
template<class T>inline bool read(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int NX = 1e5 + 10 ;
Long mod = ( 1e9 + 7 );
Long fact[ NX ] , rv[ NX ] ;

Long BigMod( int p , Long v , Long mod )
{
    if( p == 0 ) return 1 ;
    if( p == 1 ) return v ;
    Long x = BigMod( p/2 , v , mod );
    x = ( x * x ) % mod ;
    if( p & 1 ) x = ( x * v )%mod ;
    return x ;
}

void ini()
{
    fact[0] = 1 ;
    rv[0] = 1 ;
    for ( Long i = 1 ; i < NX ; i++ )
    {
        fact[i] = ( i * fact[ i - 1] ) % mod ;
    }
    for ( int i = 0 ; i < NX ; i++ )
    {
        rv[ i ] = BigMod( mod - 2 , fact[i] , mod );
    }
}

vector < int > adj[ NX ] ;
Long subtree[ NX ] , f[ NX ];

Long nCr( Long n , Long r )
{
    Long ans = ((fact[ n ]  * rv[ r ] ) % mod * rv[ n - r ]) % mod ;
    return ans ;
}
void tree( int x , int par = -1 )
{
    subtree[ x ] = 1 , f[ x ] = 1 ;
    int sz = adj[ x ].size();
    rep ( i , sz )
    {
        int u = adj[ x ][ i ];
        if( u == par ) continue ;
        tree( u , x );
        subtree[ x ] += subtree[ u ];
    }
    Long s = subtree[ x ] - 1 ;
   // printf(" x :: %d s :: %lld\n" , x , s );
    for ( int i = 0 ; i < sz ; i++ )
    {
        int u = adj[ x ][ i ];
        if( u == par ) continue ;
        Long y = (nCr( s , subtree[ u ] ) * f[ u ] )% mod ;
        f[ x ] = ( y * f[ x ] )% mod ;
        s -= subtree[ u ] ;
       // printf(" f[ x ] :: %lld y :: %lld \n" , f[ x ] , y  );
    }
}
int main()
{
    // I will always use scanf and printf
    // May be i won't be a good programmer but i will be a good human being
    ini();
   // cout << nCr( 4 , 3 ) << endl ;
    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        int n = II ;
        for ( int i = 0 ; i < n - 1; i++ )
        {
            int x = II , y = II ;
            adj[  x ].pb( y );
            adj[ y ].pb( x );
        }
        tree( 1 ) ;
        cout << f[1] << endl ;
        if( cs != t )
        {
            rep( i , n + 1 ) adj[i].clear();
        }
    }


    return 0;
}
