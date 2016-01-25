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
FILE *fin = freopen("test.in","r",stdin);
FILE *fout = freopen("test.out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;




VPII G[1000];
int N,M;
void f(int u, int v, int w)
{
    G[u-1].PB(MP(v-1,w));
    printf("%d %d %d\n",u,v,w);
}

int D[1000];
bool V[1000];

void djk()
{
    int inf = 1000000000;
    for(int i = 0; i<N; i++)D[i] = inf; D[0] = 0;
    int ans = 0;
    while(1)
    {
        int i=0; while(V[i])i++;
        if(i==N)break;
        for(int j = i+1; j<N; j++) if(V[j]==false and D[j]<D[i])i = j;
        int cnt = 0;
        for(int j =0; j<N; j++) if(V[j]==false and D[j]==D[i])cnt++;
        assert(cnt==1);
        V[i] = true;
        for(auto p : G[i])
        {
            int nd = D[i]  + p.S;
            if(nd < D[p.F])
            {
                ans++; D[p.F] = nd; 
            }
        }
    }
    assert(ans==M);
}


int main()
{
    cin>>N>>M;
    int inf = 1000000;
    int u = 1; int v = 2;
    for(int i =0; i<M; i++)
    {
        if(v==u+1)
            f(u,v,0);
        else
            f(u,v,inf--);
        v++;
        if(v==N+1)
        {
            u++; v = u+1; 
        }
    }
    djk();
    return 0;
}

