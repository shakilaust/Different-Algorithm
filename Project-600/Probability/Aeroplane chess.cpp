/* 
 
    problem Link ::: http://acm.hdu.edu.cn/showproblem.php?pid=4405

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

const int NX = 100000 + 10 ;
struct abc
{
    int frm , to ;
    int nxt ;
};

abc edge[NX];
int idx , head[NX] , n , m  ;
double dp[NX];
bool vis[NX];
void add_edg( int u , int v )
{
    edge[idx].frm = u ;
    edge[idx].to = v ;
    edge[idx].nxt = head[u];
    head[u] = idx++;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   cout << fixed << setprecision(4) ;
    while( scanf("%d %d",&n,&m) == 2 )
    {
        if( !n && !m ) break ;
        ms( head , -1 );
        ms( dp ,  0 );
        ms( vis , 0 );
        int i , j ;
        idx = 0 ;
        rep( i , m )
        {
            int x = II , y = II ;
            add_edg(y,x);
        }
        dp[n] = -1 ;
        for ( i = n ; i >= 0 ; i-- )
        {
            if( vis[i]== 0 )
            {
                dp[i] += 1 ;
                for ( j = i + 1 ; j <= i + 6 ; j++ )
                {
                    dp[i] += ( dp[j]/6.0);
                }
                vis[i] = 1 ;
            }
            for ( j = head[i] ; j != -1 ; j = edge[j].nxt )
            {
                int v = edge[j].to ;
                dp[v] = dp[i];
                vis[v] = 1 ;
            }
        }
        cout << dp[0] << endl ;
    }



    return 0;
}
