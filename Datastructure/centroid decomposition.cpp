//BISMILLAHIRRAHMANIRRAHIM
/*
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

template< class T > T gcd(T a, T b)
{
    return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b)
{
    return (a / gcd<T>(a, b) * b);
}
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<"\t";
        return *this;
    }
} dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");cout<<a[i][j];}cout<<endl;}

template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p)
{
    return o<<"("<<p.ff<<", "<<p.ss<<")";   //Pair print
}
template<class T> ostream& operator<<(ostream& o, const vector<T>& v)
{
    o<<"[";    //Vector print
    forstl(it,v)o<<*it<<", ";
    return o<<"]";
}
template<class T> ostream& operator<<(ostream& o, const set<T>& v)
{
    o<<"[";    //Set print
    forstl(it,v)o<<*it<<", ";
    return o<<"]";
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


// centroid decompossion

const int NX = 1e5 + 10 ;

const int LOGN = 20 ;

int LCA[ LOGN + 2 ][ NX ] , Level[ NX ] , subtree[ NX ] , par[ NX ] ;

Long ans[ NX ];

int total = 0 , n , m ;

set < int > g[ NX ];


void dfs0( int x )
{
    forstl( it , g[x] )
    {
        if( *it != LCA[0][x] )
        {
            LCA[0][*it] = x ;
            Level[*it] = Level[x] + 1 ;
            dfs0( *it );
        }
    }
}

void prepocess( )
{
    Level[0] = 0 ;
    LCA[0][0] = 0 ;
    dfs0( 0 );
    for( int i = 1 ; i < LOGN ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            LCA[i][j] = LCA[i-1][LCA[i-1][j]];
        }
    }
}

int lca( int a , int b )
{
    if( Level[a ] > Level[ b ] ) swap( a , b );
    int d = Level[b] - Level[a];
    for( int i = 0 ; i < LOGN ; i++ )
    {
        if( d & ( 1 << i ) ) b = LCA[i][b];
    }
    if( a == b ) return a ;
    for( int i = LOGN - 1 ; i >= 0 ; i-- )
    {
        if( LCA[i][a] != LCA[i][b] )
        {
            a = LCA[i][a];
            b = LCA[i][b];
        }
    }
    return LCA[0][a];
}


Long dist( int a , int b )
{
    return Level[a] + Level[b] - 2 * Level[ lca( a , b ) ];
}

/******************PreProcessPart**********************/

void dfs1( int u , int p )
{
    subtree[ u ] = 1 ;
    total++;
    forstl( it , g[u] )
    {
        if( *it != p )
        {
            dfs1( *it , u );
            subtree[ u ] += subtree[ *it ];
        }
    }
}

int findcentroid( int u , int p )
{
    forstl( it , g[u] )
    {
        if( *it != p && subtree[ *it ] > total / 2 )
        {
            return findcentroid( *it , u );
        }
    }
    return u ;
}


void decompossion( int u , int p )
{
    total = 0 ;
    dfs1( u , u );
    int centeroid = findcentroid( u , u );
    if( p == -1 ) p = centeroid;
    par[ centeroid ] = p ;
    forstl( it , g[centeroid] )
    {
        g[*it].erase( centeroid );
        decompossion( *it , centeroid );
    }
    g[ centeroid ].clear();
}

void update( int u )
{
    int x = u ;
    while( 1 )
    {

        ans[x] = min( ans[x] , dist( x , u ) );
        if( par[x] == x ) break ;
        x = par[x];
    }
}

Long solve( int u )
{
    int x = u ;
    Long res = ( 1e15 );
    while( 1 )
    {
        res = min( res , ans[x] + dist( x , u ) );
        if( x == par[x] ) break ;
        x = par[x];
    }
    return res ;
}
int main()
{
    // I will always use scanf and printf
    // May be i won't be a good programmer but i will be a good human being
     n = II , m = II ;
     rep( i , n - 1 )
     {
         int x = II , y = II ;
         g[x-1].insert( y - 1 );
         g[y-1].insert( x - 1 );
     }
     prepocess();
     decompossion(0 , -1 );
     for( int i = 0 ; i < n ; i++ ) ans[i] = 1e15 ;
     update(0);
     rep( i , m )
     {
         int t = II , x = II ;
         x--;
         if( t == 1 ) update( x );
         else printf("%lld\n",solve(x));
     }

    return 0;
}
/*
3
1 2
1 3
W B B
6
1 2
2 3
3 4
4 5
5 6
W B W B W B



*/
