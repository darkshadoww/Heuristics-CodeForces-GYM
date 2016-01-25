#ifdef __APPLE__
#include<cassert>
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<sstream>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

#else

#include<bits/stdc++.h>

#endif  // __APPLE__

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
#define sd(x) scanf("%d",&x)
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define REP(i,a,b) for(int i = (int)a; i < (int)b; i++)


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

#define MAXN 500000
#define LOGMAXN 20
const int MOD = 1000000007;

int N;
int P[MAXN][LOGMAXN]; 
int T[MAXN];
VI adj[MAXN]; 
int tin[MAXN],tout[MAXN];
int tim;
LL value[MAXN]; // path from root to node
unordered_map < int, LL > upd;
int L[MAXN];



void add(int &a ,int b){
    a += b;
    if(a>=MOD)a-=MOD;
}

// is x a (subtree) children of p
inline bool anc(int x, int p)
{
    if(tin[p]<=tin[x] and tout[p]>=tout[x])return true;
    return false;
}

void process3()
{
    for (int i = 0; i < N; i++)
        P[i][0] = T[i];
    for (int j = 1; 1 << j < N; j++)
        for (int i = 0; i < N; i++)
                P[i][j] = P[P[i][j - 1]][j - 1];
}
inline int query(int p, int q)
{
    int tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    for (log = 1; 1 << log <= L[p]; log++);
    log--;
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];
    if (p == q)
        return p;
    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];
    return T[p];
}

void dfs(int u, int h){
    L[u]=h;
    tin[u]=++tim;
    for(auto &j: adj[u]){
        dfs(j, h+1);
    }
    tout[u]=tim;
}

void dfs1(int u, LL sum){
    sum += upd[u];
    value[u] += sum;
    for(auto &j: adj[u])
        dfs1(j, sum);
}

const int BUFSIZE = 10000;

int main()
{
    int x, y;
    sd(N);
    for(int i=1; i<N; i++){
        sd(x), sd(y);
        adj[x].pb(y);
        T[y]=x;
    }
    T[0] = 0;
    dfs(0, 0);
    process3();

    for(int i=0; i<N; i++){
        sd(x);
        upd[i]=x;
    }
    dfs1(0, 0);
    upd.clear();
    int q,k,x0,y0,A,B,C,D,u,v;
    sd(q);
    while(q--){
        sd(k),sd(x0),sd(y0),sd(A),sd(B),sd(C),sd(D),sd(u),sd(v);

        for(int i=0; i<k; i++){
            upd[x0] += y0;
            x0=((LL)A*x0 + B)%N;
            y0=((LL)C*y0 + D)%MOD;
        }

        if(upd.size()>=BUFSIZE){
            dfs1(0, 0);
            upd.clear();
        }
        int lca = query(u,v); 
        LL ans=value[u] + value[v] - 2*value[lca] + (value[lca] - (lca ? value[P[lca][0]] : 0)   );
        for(auto &i: upd){
            if( (anc(u,i.F) or anc(v,i.F)) and anc(i.F, lca))
                ans += i.S;
        }
        printf("%lld\n", ans);
    }
    return 0;	
}
