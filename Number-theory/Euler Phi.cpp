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
