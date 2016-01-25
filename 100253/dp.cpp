#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<cmath>

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
#define sd(n) scanf("%d",&n)
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

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

#ifdef ONLINE_JUDGE
//FILE *fin = freopen(stdin,"r",stdin);
//FILE *fout = freopen(stdout,"w",stdout);
#endif

int main()
{
    //ios_base::sync_with_stdio(false);
    return 0;
}




#define F first
#define S second

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    pair< int, int > K[n+1][W+1];

    K[0][0] = {0, 0};

    // Build table K[][] in bottom up manner
    for (i = 1; i <= n; i++)
    {
        K[i][0] = {0, 0};
        for (w = 1; w <= W; w++)
        {         
            K[i][w] = K[i-1][w];
            if (wt[i-1] <= w)
            {
                int newval = K[i-1][w-wt[i-1]].F + val[i-1];
                int newtaken = 1 + K[i-1][w-wt[i-1]].S;
                if(newval > K[i][w].F)
                {
                    K[i][w] = {newval,newtaken};
                }
                else if(newval==K[i][w].F)
                    K[i][w].S = min(K[i][w].S, newtaken);
            }
        }
    }

    return K[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}

