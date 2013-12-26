/* Euler Phi function return how many co-prime exist 1-n */

LL Euler_phi(LL num)
{
    LL res = num , i ;
    for ( i = 2 ; i*i <= num ; i++)
    {
        if(num%i==0)
        {
            while(num%i==0) num/=i;
            res -= res/i;
        }
    }
    if(num>1) res -= res/num;
    return res;
}


// O(n) phi sieve
// code courtesy roypalacios ( TC )
#define MAXN 3000000
int phi[MAXN + 1], prime[MAXN/10], sz;
bitset <MAXN + 1> mark;
 
for (int i = 2; i <= MAXN; i++ ){
	if(!mark[i]){
		phi[i] = i-1;
		prime[sz++]= i;
	}
	for (int j=0; j<sz && prime[j]*i <= MAXN; j++ ){
		mark[prime[j]*i]=1;
		if(i%prime[j]==0){
			phi[i*prime[j]] = phi[i]*prime[j];
			break;
		}
		else phi[i*prime[j]] = phi[i]*(prime[j]-1 );
	}
}


// code curtesy Ivan Karasilnikov
// almost half from 1st one
static int isqrt(int a)
{
        register int x, y;

        for (x = a; x > 1; x = y)
                if ((y = ((x + (a / x)) >> 1)) >= x) return x;

        return x;
}

static int phi(int n)
{
        register int r, d, p, m;

        for (p = 0; (n & 1) == 0; n >>= 1, p++);
        r = (p == 0) ? 1 : (1 << (p - 1));

        m = isqrt(n) + 1;
        for (d = 3; d <= m; d += 2) {
                if ((n % d) == 0) {
                        for (n /= d, p = 1; (n % d) == 0; n /= d, p++)
                                r *= d;
                        r *= d - 1;
                        m = isqrt(n) + 1;
                }
        }

        if (n > 1)
                r *= (n - 1);

        return r;
}
