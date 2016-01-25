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

int N,M;
VPII D[900];  // <source,dist>
int ANS[900][900];
VI E[900];
int U[150000], V[150000];


void process(int x)
{
    for(int i = 0; i<N; i++)
        D[i].clear();
    D[x].PB(MP(x,0));
    D[x].PB(MP(x,0));
    queue<PII> Q; //<id,node>
    for(auto v : E[x])
    {
        Q.push(MP(0,v));
        D[v].PB(MP(v,1));
    }
    while(!Q.empty())
    {
        PII a = Q.front(); Q.pop();
        int u = a.S;
        int id = a.F;
        int d = D[u][id].S;
        int src = D[u][id].F;
        for(auto y : E[u])
        {
            if(D[y].size()>=2)continue;
            if(D[y].empty() or D[y][0].F!=src)
            {
                D[y].PB(MP(src,d+1));
                Q.push(MP(D[y].size()-1,y));
            }
        }
    }
    for(auto y : E[x])
        if(D[y].size()==2)
            ANS[x][y] = D[y][1].S;
}


int main()
{
    while(cin>>N>>M)
    {
        for(int i =0; i<N; i++)
        {
            E[i].clear(); 
            for(int j =0; j<N; j++) ANS[i][j] = 0;
        }
        for(int i =0; i<M; i++)
        {
            si(U[i]); si(V[i]); U[i]--; V[i]--;
            E[U[i]].PB(V[i]);
        }
        for(int i  = 0; i<N; i++)
            if(!E[i].empty())
                process(i);
        for(int i =0; i<M; i++)
            printf("%d ",ANS[U[i]][V[i]]); printf("\n");
    }
    return 0;	
}
