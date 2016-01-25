#include <cassert>
#include <cstring>
#include <queue>
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

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

const int MX = 20000;

VPII E[10000];
VPII rE[10000];

int D[10001];
int D2[10001];

int C[10000];
bool V[10001];
VI tord;
bool can;


// gives simple topological order. 
void dfs(int x)
{
    if(V[x])return;
    V[x]=true;
    for(auto c : E[x])
        dfs(c.F);
    tord.PB(x);
}

// assign SCC
void dfs2(int x, int c)
{
    if(C[x])return;
    C[x] = c;
    for(auto i : rE[x])
        dfs2(i.F,c);
}

VPII nE[10001];

// topo order in SCC
void dfsn(int x)
{
    if(V[x])return; V[x] = true;
    for(auto c : nE[x])
        dfsn(c.F);
    tord.PB(x);
}
int dfsn2(int x)
{
    if(V[x])return 0;
    V[x] = true;
    int ret = D2[x];
    for(auto c : nE[x])
        ret = max(ret,dfsn2(c.F));
    return ret;
}

int c;
bool f(int inc, int s)
{
    for(int i = 1; i<=c; i++)
        D2[i] = D[i];
    D2[s] += inc;
    for(auto x : tord)
        for(auto it : nE[x])
            D2[it.F] = max(D2[it.F], D2[x] + it.S);
    for(int i = 1; i<=c; i++)
        if(D2[i] > MX)return false; 
    return true;
}
int main()
{
    int N,M;
    si(N); si(M);
    for(int i = 0; i<M; i++)
    {
        int x,y,w; si(x); si(y); si(w); x--; y--; 
        swap(x,y);
        E[x].PB(MP(y,w));
        swap(x,y);
        rE[x].PB(MP(y,w));
    }
    for(int i = 0; i<N; i++)
        dfs(i);
    reverse(tord.begin(), tord.end());
    c = 0;
    for(auto x : tord)
        if(C[x]==0)
            dfs2(x,++c);
    can = true;
    for(int i = 0; i<N; i++)
    {
        int x = C[i];
        for(auto c : E[i])
        {
            int y = C[c.F]; int w = c.S;
            if(y==x)
            {
                if(w)can = false;
                continue;
            }
            nE[x].PB(MP(y,w));
        }
    }
    if(can==false){ cout<<-1<<endl; return 0;}
    for(int i = 1; i<=c; i++) V[i] = false;
    tord.clear();
    for(int i = 1; i<=c; i++)
        dfsn(i);
    reverse(tord.begin(), tord.end());
    for(auto x : tord)
        for(auto it : nE[x])
            D[it.F] = max(D[it.F], D[x] + it.S);


    // check if min possible value of any component has already exceede the MX value
    {
        for(auto x : tord)
            if(D[x]>MX)
                can = false;
        if(can==false){ cout<<-1<<endl; return 0;}
    }

    // increase A1 as much as possible
    {
        int s = C[0];
        int l = 0; 
        int h = MX - D[s];
        while(h-l>1)
        {
            int m = (l+h)/2;
            if(f(m,s))
                l = m; 
            else
                h = m-1;
        }
        if(f(h,s)==false)h--;
        D[s]+=h;
        for(auto x : tord)
            for(auto it : nE[x])
                D[it.F] = max(D[it.F], D[x] + it.S);
    }
    for(int i = 0; i<N; i++)
    {
        int x = C[i];
        printf("%d ",D[x]-10000);
    }
    cout<<endl;
    return 0;	
}
