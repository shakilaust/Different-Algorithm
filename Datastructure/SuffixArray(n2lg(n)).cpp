// Templete for Suffix And LCP compute
const int N = 10005;
int SA[32][N] , Res , Repeat, stp , cnt , sz , a , b; // SA r vitor all substring ase
string inp;
struct entry
{
       int nr[2], p;
} L [N] ; // Safiix array er position thake
bool cmp(entry A , entry B )
{
       if(A.nr[0] == B.nr[0] ) return A.nr[1] < B.nr[1];
       return A.nr[0] < B.nr[0];
}
int Value (int i )
{
       if(i > 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1] ) return SA[stp][L[i-1].p] ;
       return i;
}
void Suffix()
{
       cin >> inp ; // taking input
       sz = inp.size ();
       int i ;
       for ( i = 0 ; i < sz ; i++ ) SA[0][i] = inp[i] - 'a' ;
       for( stp = 1 , cnt = 1 ; cnt >> 1 < sz ; cnt <<= 1 , stp++ )
       {
              for ( i = 0 ; i < sz ; i++ )
              {
                     L[i].nr[0] = SA[stp-1][i];
                     L[i].nr[1] = i + cnt < sz ? SA[stp-1][i+cnt] : -1;
                     L[i].p = i ;

              }
              sort ( L, L+sz , cmp);
              for ( i = 0 ; i < sz ; i++ )
              SA[stp][L[i].p] = Value(i);
       }

}
int LCP(int x, int y)
{
       int ret = 0 , k ;
       if( x == y ) return sz - x ;
       for ( k = stp - 1; k >=0 && x < sz && y < sz ; k--)
       if(SA[k][x] == SA[k][y] ) x += 1 << k , y += 1 << k , ret += 1 << k ;
       return ret;

}
