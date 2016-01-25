#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%lld",&n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
       cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
       const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define int long long
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;


FILE *fin = freopen("treasures.in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

const int mod = 1000000007;
inline void add(int &x, int y){x+=y; if(x>=mod)x-=mod; if(x<0)x+=mod;}
inline int mul(int x, int y){ return ((LL)x * y)%mod;}


int mark[2][209][209];
int pre[209][209];
int mat[209][209];

int getsum(int x1, int y1, int x2, int y2, int n, int m){

    int temp=x1;
    x1 = x1 + y1 - 1;
    y1 = y1 - temp + n;
    temp=x2;
    x2 = x2 + y2 - 1;
    y2 = y2 - temp + n;


    assert(x1<=x2);
    assert(y1<=y2);

    if(x1<1)x1=1;
    if(y1<1)y1=1;
    if(x1>=n+m)x1=n+m-1;
    if(y1>=m+n)y1=m+n-1;
    if(x2<1)x2=1;
    if(y2<1)y2=1;
    if(x2>=n+m)x2=n+m-1;
    if(y2>=m+n)y2=n+m-1;

    int ret=pre[x2][y2];
    add(ret, - pre[x1-1][y2]);
    add(ret, - pre[x2][y1-1]);
    add(ret,  pre[x1-1][y1-1]);
    return ret;
}

#undef int
int main()
#define int long long
{
    int t,pp;
    sd(t);
    pp=t;
    while(t--){
        memset(mark, 0, sizeof(mark));
        int n,m,s;
        PII st;
        sd(n),sd(m),sd(s);
        sd(st.F),sd(st.S);

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                sd(mat[i][j]);

        mark[s%2][st.F + st.S - 1][st.S - st.F + n]=1;

        for(int iter=s-1; iter>=1; iter--){
            int p = 1-(iter%2);
            int len = iter;
            for(int i=1; i<=n+m; i++)
                for(int j=1; j<=n+m; j++){
                    pre[i][j] =  mark[p][i][j];
                    add( pre[i][j] , pre[i-1][j]);
                    add( pre[i][j] , pre[i][j-1]);
                    add( pre[i][j] , -pre[i-1][j-1]);
                }


            for(int i=1; i<=n; i++)
                for(int j=1; j<=m; j++){
                    mark[1 - p][i + j -1][j - i + n] = getsum(i, j-iter, i, j+iter, n, m);
                }

        }
        int ans=0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++){
                if(s%2){
                add(ans, mul(mark[(s%2)][i + j -1][j - i + n], mat[i][j]));
                }
                else
                add(ans, mul(mark[1-(s%2)][i + j -1][j - i + n], mat[i][j]));
            }
        printf("Case %lld: %lld\n",pp-t,ans);
    }
    return 0;
}


