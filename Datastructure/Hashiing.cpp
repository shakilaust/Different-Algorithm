/* 
Problem Description :::: 
Monk has magical powers, by which he can compare any part of the strings and figure out if they're equal. His magical powers are faster than a super computer even. So, to prove his worth, he's given a string and he has to answer multiple queries based on the string.

Every query will have four integers - L1, R1, L2, R2. The first two integers denoting String [ L1, R1 ] (including both L1 and R1) denoting the first substring, the next two integers denoting the second substring String [ L2, R2 ] (including both L2 and R2).

For every query, you've to answer in Yes or No whether the two substrings are equal or not. Easy enough?

Input:
The first line contains a string, S.
Then, an integer Q denoting the number of queries in the next line.
Then, for every query, there will be 4 integers L1 R1 L2 R2, denoting the substring S[L1 R1] and S[L2 R2].

Output:
For each query output "Yes" if the two substrings are same , else output "No".

Constraints:
1 ≤ |S| ≤ 105
1 ≤ Q ≤ 105
1 ≤ L1 ≤ R1 ≤ |S|
1 ≤ L2 ≤ R2 ≤ |S|
The string will contain only lowercase letters.

 Input ::: 
 monkandhismonkiness
4
1 1 3 3
1 4 11 14
3 3 6 6
4 5 14 17
Output :: 
No
Yes
Yes
No 

*/ 

  #include<bits/stdc++.h>
     
    using namespace std;
     
    #define vi vector < int >
    #define pii pair < int , int >
    #define pb push_back
    #define mp make_pair
    #define ff first
    #define ss second
    #define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
    #define ll long long
    #define llu unsigned long long
    #define MOD 1000000007
    #define INF 0x3f3f3f3f
    #define dbg(x) { cout<< #x << ": " << (x) << endl; }
    #define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
    #define all(x) x.begin(),x.end()
    #define mset(x,v) memset(x, v, sizeof(x))
    #define sz(x) (int)x.size()
     
    #define B1 33
    #define M1 10000009
    #define B2 163
    #define M2 10000007
     
    string s;
    ll h1[100502],h2[100502];
    ll p1[100502],p2[100502];
     
    map < pair < ll , ll >  , bool > H;
     
    void prec()
    {
        int n = sz(s),i;
        p1[0] = p2[0] = 1;
        for(i=1;i<=n;i++)
        {
            p1[i] = (B1*p1[i-1])%M1;
            p2[i] = (B2*p2[i-1])%M2;
        }
        for(i=1;i<=n;i++)
        {
            h1[i] = (B1*h1[i-1] + s[i-1] - 'a' + 1)%M1;
            h2[i] = (B2*h2[i-1] + s[i-1] - 'a' + 1)%M2;
        }
    }
     
    ll getHash1(int l,int r)
    {
        int len = r - l + 1;
        ll ret = (h1[r] - (h1[l-1]*p1[len])%M1 + M1)%M1;
        return ret;
    }
     
    ll getHash2(int l,int r)
    {
        int len = r - l + 1;
        ll ret = (h2[r] - (h2[l-1]*p2[len])%M2 + M2)%M2;
        return ret;
    }
     
    int main()
    {
        //freopen("input-7.in","r",stdin);
        //freopen("output-7.out","w",stdout);
        int n,q,i;
        cin>>s;
        n = sz(s);
        //cout<<s<<endl;
        assert(1 <= n && n <= 100000);
        for(i=0;i<n;i++)
        {
            assert('a' <= s[i] && s[i] <= 'z');
        }
        //dbg(n);
        prec();
        scanf("%d",&q);
        assert(1 <= q && q <= 100000);
        //dbg(q);
        while(q--)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            assert(1 <= x1 && x1 <= n);
            assert(x1 <= y1 && y1 <= n);
            assert(1 <= x2 && x2 <= n);
            assert(x2 <= y2 && y2 <= n);
            if(y1 - x1 == y2 - x2)
            {
                pair < ll , ll > H1(getHash1(x1,y1),getHash2(x1,y1));
                pair < ll , ll > H2(getHash1(x2,y2),getHash2(x2,y2));
     
                if(H1 == H2)
                {
                    printf("Yes\n");
                    //cout<<x1<<":"<<y1<<":"<<x2<<":"<<y2<<endl;
                }
                else
                {
                    printf("No\n");
                }
            }
            else
            {
                printf("No\n");
            }
        }
        return 0;
    }
