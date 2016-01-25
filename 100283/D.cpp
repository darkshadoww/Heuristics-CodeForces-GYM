//karanaggarwal
#include<bits/stdc++.h>
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

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

const int mod = 1000000007;
inline void add(int &x, int y){x+=y; if(x>=mod)x-=mod; if(x<0)x+=mod;}
inline int mul(int x, int y){ return ((LL)x * y)%mod;}

#ifdef ONLINE_JUDGE
FILE *fin = freopen("rooks.in","r",stdin);
#endif

int F[1001];
int DP[1001][1001];

void f(int X, int Y, int R)
{
    memset(DP,0,sizeof(DP));
    DP[0][0] = 1;
    for(int i =1; i<=Y; i++)
    {
        for(int j = 0; j<=i and j<=X; j++)
        {
            if(j)
                DP[i][j] = DP[i-1][j-1];
            add(DP[i][j],mul(DP[i-1][j] , R-X+j));
        }
    }
    printf("%d %d\n",Y,mul(DP[Y][X],F[X]));
}

int main()
{
    F[0] = 1;
    for(int i =1; i<=1000; i++) F[i] = mul(i,F[i-1]);

    int t; si(t); int T = t; while(t--)
    {
        int R,C,K;
        si(R); si(C); si(K);
        set<int> X,Y;
        while(K--)
        {
            int x,y; si(x); si(y); X.insert(x); Y.insert(y);
        }
        printf("Case %d: ",T-t);
        if(X.size()<Y.size()) 
            f(X.size(),Y.size(),R);
        else 
            f(Y.size(),X.size(),C);
    }
    return 0;	
}
