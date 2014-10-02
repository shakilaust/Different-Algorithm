int T[MAX];
string A,B;
int lenA,lenB;
vector <int> shift;
void init()
{  rep(i,lenA+5) T[i]=0;
}
void ComputePrefixFunction()
{  int k=0,q;
   T[1]=0;
   for(q=2;q<=lenB;q++)
   {  while (k>0 && B[k]!=B[q-1]) k=T[k];
         if(B[k]==B[q-1]) k++;
         T[q]=k;
   }
}
 void KMP_Matcher()
 {  int q=0;
    ComputePrefixFunction();
    rep(i,lenA)
        {   while( q>0 && B[q]!=A[i]) q=T[q];
           if(B[q]==A[i]) q++;
         if(q==lenB) { shift.pb(1+i-lenB); q=T[q];}
        }
   
 }
int main()
{    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
        int test;
        cin>>test;
        ROF(kase,1,test)
        {  cin>>A>>B;
           lenA=A.size();
           lenB=B.size();
           shift.clear();
           init();
           KMP_Matcher();
           printf("Case %d: %d\n",kase,shift.size());
        }
        
