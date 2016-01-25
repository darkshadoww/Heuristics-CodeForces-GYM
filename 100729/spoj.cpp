
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

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

VPII E[10001];
const int inf = 1000000000;
int D[100001];

int main()
{
    int t; si(t); while(t--)
    {
        int N,M; si(N); si(M); for(int i =1; i<=N; i++){E[i].clear();D[i] = inf;}
        while(M--)
        {
            int x,y,c; si(x); si(y); si(c); E[x].PB(MP(y,c));
        }
        int s,d; si(s); si(d);
        for(int i = 1; i<=N; i++)D[i] = inf;
        D[s] = 0; set<int> Q;
        Q.insert(s);
        while(!Q.empty())
        {
            int x = *Q.begin(); Q.erase(x);
            for(auto p   : E[x])
                if(D[x] + p.S < D[p.F])
                {
                    D[p.F] = D[x] + p.S; Q.insert(p.F);
                }
        }
        if(D[d]!=inf)printf("%d\n",D[d]); else printf("NO\n");
    }
    return 0;	
}
