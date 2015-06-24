/* Problem link :: http://acm.timus.ru/problem.aspx?space=1&num=1752 */ 

//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
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

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int NX = 20000 + 10 ;

vector < int > adj[NX] ;
int Level[NX] , ed  , mx , parnt[NX][20] , n , q , x , y ;

void dfs( int x , int frm , int lvl )
{
    if( lvl > mx )
    {
        mx = lvl ;
        ed = x ;
    }
    Level[x] = lvl ;
    parnt[x][0] = frm ;
    int sz = adj[x].size();

    rep ( i , sz )
    {
        int y = adj[x][i];
        if( y == frm ) continue ;
        dfs( y , x , lvl + 1 );
    }

}
int ini()
{
    int i , j ;
    for ( i = 1 ; i <= n ; i++ )
    {
        for ( j = 0 ; ( 1 << j ) <=n ; j++ ) parnt[i][j] = -1 ;
    }
}
int precal()
{
    int i , j ;
    for ( j = 1 ; ( 1 << j ) <= n ; j++ )
    {
        for ( i = 1 ; i <= n ; i++ )
        {
            if( parnt[i][j-1] != -1 )
            {
                parnt[i][j] = parnt[parnt[i][j-1]][j-1];
            }
        }
    }
   // puts(" parent precall \n");
}

int LCA( int a , int b )
{
    if( Level[a] < Level[b] ) swap( a , b );
    int lg , i ;
    for ( lg = 1; ( 1 << lg ) <= Level[a] ; lg++ ) ;
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
        if( parnt[a][i] != -1 && parnt[a][i] != parnt[b][i] )
        {
            a = parnt[a][i];
            b = parnt[b][i];
        }
    }
    return parnt[a][0];
}

int Ans( int u , int d )
{
    int i ;
    for ( i = 0 ; d ; i++ )
    {
        if( d & 1 ) u = parnt[u][i];
        d /= 2 ;
    }
    return u ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   mx = -1 ;
   n = II , q = II ;
   rep ( i , n - 1 )
   {
       x = II , y = II ;
       adj[x].pb(y);
       adj[y].pb(x);
   }
   ini();
   dfs( 1 , -1 , 0 );
  // printf(" after 1st ed :: %d\n",ed);
   mx = -1 ;
   dfs( ed , -1 , 0 );
  // printf(" after 2nd ed :: %d\n",ed);
  // For( i , n ) printf("%d level :: %d\n" , i , Level[i]);
   precal();
   while( q-- )
   {
       int v = II , d = II ;
       if( Level[v] >= d ) printf("%d\n",Ans(v,d));
       else
       {
           int l = LCA( v , ed );
           int can = Level[v] + Level[ed] - ( 2 * Level[l] );
           //printf(" v :: %d level v :: %d ed :: %d level ed :: %dLca :: %d level[l] :: %d can :: %d\n" ,v,Level[v],ed,Level[ed], l  , Level[l], can );
           if( d > can ) printf("0\n");
           else printf("%d\n", Ans( ed , Level[v] + Level[ed] - ( 2 * Level[l] ) - d ));
       }
   }


    return 0;
}
