/* 
     problem Link :: http://poj.org/problem?id=3744 
     Poj 3744 
 */
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std ;
// For loop



/* **************************************  My code start here ****************************************** */
struct Matrix
{
    double mat[2][2];
};

Matrix one ;
void ini()
{
    for ( int i = 0 ; i < 2 ; i++ ) one.mat[i][i] = 1 ;
}
int n , inp[100] ; double p ;
Matrix mul( Matrix a , Matrix b )
{
    Matrix ans ;
    for ( int i = 0 ; i < 2 ; i++ )
    {
        for ( int j = 0 ; j < 2 ; j++ )
        {
            ans.mat[i][j] = 0 ;
            for ( int k = 0 ; k < 2 ; k++ )
            {
                ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) ;
            }
        }
    }
    return ans ;
}
Matrix matpow( Matrix a , int n )
{

    Matrix ret;
    memset(ret.mat,0,sizeof(ret.mat));
    for(int i=0;i<2;i++)ret.mat[i][i]=1;
    Matrix temp=a;
    while(n)
    {
        if(n&1)ret=mul(ret,temp);
        temp=mul(temp,temp);
        n>>=1;
    }
    return ret;
   /* Matrix ans ;
    ms( ans.mat , 0 );
    rep( i , 2 ) ans.mat[i][i] = 1 ;
    Matrix tmp = base ;
    while( p )
    {
        if( p & 1 ) ans = multiplication( ans , tmp );
        tmp = multiplication( tmp , tmp );
        p >>= 1 ;
    }
    return ans ; */

}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   //  cout << fixed << setprecision(10) ;

      //  ini();
        while( scanf("%d%lf",&n,&p) != EOF )
        {
           Matrix ans , base ;

           base.mat[0][0] = p ;
           base.mat[0][1] = 1 - p ;
           base.mat[1][0] = 1 ;
           base.mat[1][1] = 0 ;
           for ( int i = 0 ; i < n ; i++ ) cin >> inp[i] ;
           sort ( inp , inp + n );

           ans = matpow(base , inp[0] - 1 );
           double res = 1;

           res *= ( 1 - ans.mat[0][0] );

           for ( int i = 1 ; i < n ; i++ )
           {
               if( inp[i] == inp[i-1] ) continue ;
               ans = matpow(base , inp[i] - inp[i-1] - 1 );
               res *= ( 1 - ans.mat[0][0] );
           }
           printf("%.7lf\n",res);
        }






    return 0;
}
