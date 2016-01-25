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
const int MN = 100000;
VI G[MN];
int U[MN],V[MN], W[MN];
int node(int i, int x)
{
    return x ^ U[i] ^ V[i];
}
unordered_map<int,LL> D[MN]; // D[x][s]
unordered_set<int> vis[MN]; // D[x][s]
typedef pair<LL,pair<int,int>>  PLII;

LL ANS[MN];

int main()
{
    int N,M; si(N); si(M);
    priority_queue<PLII> PQ;
    for(int i = 0; i<N; i++)
    {
        int x; si(x);
        if(x)
        {
            D[i][i] = 0;
            PQ.push(MP(0,MP(i,i)));
        }
    }
    for(int i = 0; i<M; i++)
    {
        int u,v; si(u); si(v); si(W[i]);
        u--; v--; 
        U[i] = u; V[i] = v;
        G[u].PB(i);
        G[v].PB(i);
    }
    while(!PQ.empty())
    {
        PLII a = PQ.top(); PQ.pop();
        int x = a.S.F;
        int s = a.S.S;
        LL d = -a.F;
        if( not D[x].count(s))continue;
        if(vis[x].count(s)) continue;
        vis[x].insert(s);
        for(auto i : G[x])
        {
            int y = node(i,x);
            if(vis[y].size()==2 or vis[y].count(s))continue;
            LL nd = d + W[i];
            // y has not been explored by 2 nodes and y has not been explored by node s.
            if(D[y].count(s))
            {
                if(D[y][s] > nd)
                {
                    D[y][s] = nd;
                    PQ.push(MP(-nd,MP(y,s)));
                }
            }
            else
            {
                if(D[y].size()<2)
                {
                    D[y][s] = nd;
                    PQ.push(MP(-nd,MP(y,s)));
                }
                else
                {
                    auto it1 = D[y].begin(); 
                    LL d1 = it1->S;
                    auto it2 = it1; it2++; 
                    LL d2 = it2->S;
                    if(nd < max(d1,d2))
                    {
                        if(d2>d1)it1 = it2;
                        D[y].erase(it1);
                        D[y][s] = nd;
                        PQ.push(MP(-nd,MP(y,s)));
                    }
                }
            }
        }
    }
    bool found = false;
    int ans;
    for(int i = 0; i<N; i++)
        if(vis[i].size()==2)
        {
            LL cr = 0;
            auto it = D[i].begin(); cr += it->S; it++; cr += it->S;
            ANS[i] = cr;
            if(not found)
            {
                found = true;
                ans = i;
            }
            else
            {
                if(ANS[i] < ANS[ans]) ans = i;
            }
       }
    if(not found) cout<<"No luck at all\n";
    else
    {
        cout<<ANS[ans]<<endl;
        auto it = D[ans].begin(); 
        cout<<1 + it->F<<" ";
        it++;
        cout<<1 + it->F<<"\n";
    }
    return 0;	
}
