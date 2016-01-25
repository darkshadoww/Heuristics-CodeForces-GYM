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
FILE *fin = freopen("easy.in","r",stdin);
FILE *fout = freopen("easy.out","w",stdout);
#endif

int main()
{
    //ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    VI ar[11], pt(n, 0);
    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        ar[i].resize(p);
        for(int j=0; j<p; j++)
            cin >> ar[i][j];
    }
    int cnt=0, curdif=0;
    while(1){
        for(int i=0; i<n; i++){
            if(pt[i]<ar[i].size()){
                if(ar[i][pt[i]]>=curdif)
                    curdif += ar[i][pt[i]], cnt++;
                pt[i]++;
            }
            else curdif += 50, cnt++;
            if(cnt==k)break;
        }
        if(cnt==k)break;
    }
    cout << curdif << endl;
    return 0;
}


