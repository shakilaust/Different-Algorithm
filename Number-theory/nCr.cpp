const int MX = 10005;
Long nCr[MX][MX];
void pre()
{
    int i , j ;
    for( i = 0 ; i < MX ; i++)
    {
        for ( j = 0 ; j <= i ; j++ )
        {
            if( j == 0 || j == i )
            {
                nCr[i][j] = 1;
            }
            else
            nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
        }
    }
}
