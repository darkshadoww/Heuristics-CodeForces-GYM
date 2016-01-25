#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
using namespace std;


typedef long long LL;
typedef pair<int,int> PII;

#ifdef ONLINE_JUDGE
FILE *fin = freopen("john.in","r",stdin);
FILE *fout = freopen("john.out","w",stdout);
#endif

int BIT[100001];

int query(int x)
{
    int ret = 0;
    while(x>0){
        ret += BIT[x];
        x &= (x-1);
    }
    return ret;
}
void update(int id)
{
    while(id<=100000)
    {
        BIT[id]++;
        id += (id & (-id));
    }
}

map<int,int>M;
PII A[100000];

int main()
{
    int N; si(N);
    for(int i =0; i<N; i++)
    {
        si(A[i].F); si(A[i].S);
        M[A[i].S];
    }
    sort(A,A+N);
    int cnt = 0;
    for(auto &c : M)c.S = ++cnt;
    int j = 0;
    LL ans = 0;
    for(int i =0; i<N; i++)
    {
        A[i].S = M[A[i].S];
        if(i and A[i].F != A[i-1].F)
        {
            while(j<i)
            {
                update(A[j].S); j++;
            }
        }
        ans += ( j - query(A[i].S));
    }
    cout<<ans<<endl;
    return 0;
}


