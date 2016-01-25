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

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define DRT()  int t; cin>>t; while(t--)

#ifdef ONLINE_JUDGE
//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

int D[10000];
set<int> G[10000];
int N,M; 
int s,t; 
VI TP;

pair<bool,int> dfs(int x, int d)
{
    D[x] = d; 
    pair<bool,int> ret = {false,d};
    if(x==t)
        ret.F = true;
    for(auto y : G[x])
    {
        if(D[y])
        {
            ret.S = min(ret.S,D[y]);
        }
        else
        {
            pair<bool,int>  back = dfs(y,d+1);
            ret.F |= back.F;
            ret.S = min(ret.S,back.S);
            if(x!=s and back.F and back.S>=d)TP.PB(x+1);
        }
    }
    return ret;
}

int main()
{
    si(N); si(M); while(M--){
        int x, y; si(x); x--; si(y); y--; 
        if(x!=y){
            G[x].insert(y); G[y].insert(x);
        }
    }
    si(s); si(t); s--; t--; 
    dfs(s,1);
    sort(TP.begin(),TP.end());
    printf("%d\n",TP.size()); for(auto x : TP) printf("%d\n",x);
    return 0;
}

