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
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = (int)a; i < (int)b; i++)

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

int N,M,K;
VPII E[20000];
int bf;
int off;
int P[15];
int pop_count[1<<15];
int last[1<<15];
int C[1<<15];
VI child[15];
int Dist[20000], D[15][20000];
const int inf = 2000000000;
int DP[1<<15];
void dfs(int mask, int last, int cost)
{
    if(mask)
        C[mask] = min(C[mask],cost);
    if(pop_count[mask]==4 or pop_count[mask]==K)return;
    for(int i = 0; i<K; i++)
    {
        if((mask>>i) & 1)continue;
        int cst = cost;
        if(last==-1)
            cst += Dist[P[i]];
        else
            cst += D[last][P[i]];
        dfs(mask | (1<<i), i, cst);
    }
}

void djk(int src, int D[])
{
   for(int i =0; i<N; i++)
       D[i] = inf;
   D[src] = 0;
   set<pair<int,int>> PQ;
   PQ.insert(MP(0,src));
   while(!PQ.empty())
   {
        PII a = *PQ.begin(); PQ.erase(PQ.begin());
        int x = a.S; int d = a.F;
        for(auto p : E[x])
        {
            int nd = d + p.S;
            int y = p.F;
            if(nd < D[y])
            {
                auto it = PQ.find(MP(D[y],y));
                if(it != PQ.end()) PQ.erase(it);
                D[y] = nd;
                PQ.insert(MP(D[y],y));
            }
        }
   }
}

int main()
{
    si(N); si(M);
    while(M--)
    {
        int t,x,y;
        int c; 
        si(t); si(x); si(y); si(c);
        x--; y--; 
        E[x].PB(MP(y,c));
        if(t==2)
            E[y].PB(MP(x,c));
    }
    si(bf); si(off); off--;
    si(K);
    for(int i = 0; i<K; i++){si(P[i]); P[i]--;}
    pop_count[0] = 0;
    for(int i =1; i<(1<<K); i++)
    {
        pop_count[i] = (i&1) + pop_count[i/2];
        C[i] = inf;
        int j = 0; 
        int mask = i; while((mask&1)==0){mask/=2;j++;}
        last[i] = j;
        if(pop_count[i]<=4)
            child[j].PB(i);
    }
    djk(off,Dist);
    for(int i = 0; i<K; i++)
        djk(P[i],D[i]);
    dfs(0,-1,bf);
    DP[0] = 0;
    for(int mask = 1; mask < (1<<K); mask++)
    {
        DP[mask] = inf;
        int j = last[mask];
        for(auto c : child[j])
            if((c | mask) == mask)
                DP[mask] = min(DP[mask], C[c] + DP[mask - c]);        
    }
    cout<<DP[(1<<K)-1]<<endl;
    return 0;	
}
