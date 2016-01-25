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

const int N = 2000;
VPII E[N];
int D[2][N];
int n; 
const int inf = 1000000000;
bool V[N];
void djk(int x, int ty)
{
    for(int i = 0; i<n; i++)
    {
        V[i] = false;
        D[ty][i] = inf;
    }
    D[ty][x] = 0;
    priority_queue<PII> PQ;
    PQ.push(MP(-D[ty][x],x));
    while(!PQ.empty())
    {
        PII a = PQ.top(); PQ.pop();
        if(V[a.S])continue;
        V[a.S] = true;
        int x = a.S;
        int d = D[ty][x];
        for(auto i : E[x])
        {
            int nd = d + i.S;
            int y = i.F;
            if(D[ty][y] > nd)
            {
                D[ty][y] = nd;
                PQ.push(MP(-nd,y));
            }
        }
    }
}

bool val[N];
VI mx[N];
int ANS[N];


int main()
{
    si(n);
    int s,t; 
    si(s); si(t); s--; t--;
    int m; si(m); 
    for(int i = 0; i<m; i++)
    {
        int x,y,w; si(x); si(y); si(w); x--; y--; 
        E[x].PB(MP(y,w));
        swap(x,y);
        E[x].PB(MP(y,w));
    }
    djk(s,0);
    if(D[0][t]==inf)
    {
        for(int i = 0; i<n; i++)
            printf("0 ");
        cout<<endl;
        return 0;
    }

    djk(t,1);
    
    for(int i = 0; i<n; i++)
        if(D[0][i] + D[1][i] == D[0][t])
            val[i] = true;
    for(int i = 0; i<n; i++)
    {
        if(val[i])
        {
            for(auto it : E[i])
            {
                int x = i; int y = it.F;
                if(val[y] and D[0][y]==D[0][x]+it.S)
                    mx[x].PB(D[0][y]);
            }
        }
    }

    vector< PII > B;
    for(int i = 0; i<n; i++)
        if(val[i])
            B.PB(MP(D[0][i], i));
    priority_queue<int> PQ;
    sort(B.begin(), B.end());
    int j = 0;
    for(int i = 0; i<B.size(); i++)
    {
        if(i<B.size()-1 and B[i].F == B[i+1].F)continue;
        int oj = j;
        while(!PQ.empty())
        {
            int x = PQ.top(); 
            if(x < -B[i].F)break;
            PQ.pop();
        }
        while(oj<=i)
        {
            ANS[B[oj].S] = (i-j+1) + PQ.size();
            oj++;
        }
        while(j<=i)
        {
            for(auto c : mx[B[j].S])
                PQ.push(-c);
            j++;
        }
    }
    for(int i = 0; i<n; i++) printf("%d ",ANS[i]);
    cout<<endl;
    return 0;	
}
