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

#ifdef ONLINE_JUDGE
FILE *fin = freopen("immediate.in","r",stdin);
FILE *fout = freopen("immediate.out","w",stdout);
#endif

int E[18][18];
int D[1<<18];
int bestL[1<<18];
int bestMM[1<<18];
int sP[18][18];
int sE[18][18];
int N;
int DP[1<<18][18];
int P[1<<18][18];

void push_sp(int x, int y, VI &tp)
{
    while(y>=0 and y!=x)
    {
        tp.PB(y+1); y = sP[x][y];
    }
}


void print(int mask)
{
    int last = bestL[mask];
    VI TP;
    while(last>0)
    {
        push_sp(P[mask][last] , last, TP);
        int nmask = mask - (1<<last);
        last = P[mask][last];
        mask = nmask;
    }
    TP.PB(1);
    reverse(TP.begin(),TP.end());
    printf("%d",TP.size()-1);
    for(auto c : TP)printf(" %d",c); printf("\n");
}


void djk(int src)
{
    set<PII> PQ;
    sE[src][src] = 0; 
    sP[src][src] = -1;
    
    PQ.insert(MP(sE[src][src] , src));

    while(!PQ.empty())
    {
        int d = PQ.begin()->F;
        int x = PQ.begin()->S; 
        PQ.erase(PQ.begin());
        for(int y = 0; y<N; y++)
        {
            if(sE[src][y] > d + E[x][y])
            {
                auto it = PQ.find(MP(sE[src][y],y));
                if(it != PQ.end())PQ.erase(it);
                sE[src][y] = E[x][y] + sE[src][x];
                sP[src][y] = x;
                PQ.insert(MP(sE[src][y],y));
            }
        }
    }
}


void process(int mask, int last)
{
    if(DP[mask][last] < D[mask])
    {
        D[mask] = DP[mask][last];
        bestL[mask] = last;
    }
}

int main()
{

    memset(E,31,sizeof(E));
    memset(sE,31,sizeof(E));
    memset(DP,31,sizeof(DP));
    memset(D,31,sizeof(D));
    int M; cin>>N>>M;
    for(int i =0; i<M; i++)
    {
        int x,y,c; cin>>x>>y>>c; x--; y--; E[x][y] = E[y][x] = c;
    }
    for(int i = 0; i<N; i++)djk(i);

    DP[1][0] = 0; 
    P[1][0] = -1;
    process(1,0);
    
    for(int mask = 3; mask<(1<<N); mask+=2)
    {
        for(int last = 0; last<N; last++) 
        {
            if((mask>>last)&1)
            {
                int nmask = mask - (1<<last);
                for(int u = 0; u<N; u++)
                    if((nmask>>u)&1)
                    {
                        if(sE[u][last] + DP[nmask][u] < DP[mask][last])
                        {
                            P[mask][last] = u;
                            DP[mask][last] = DP[nmask][u] + sE[u][last];
                        }
                    }
                process(mask,last);
            }
        }
    }

    for(int mask = 1; mask<(1<<N); mask+=2) bestMM[mask] = mask;
    
    for(int mask = (1<<N)-1; mask>0; mask-=2)
    {
        for(int i =1; i<N; i++)
        {
            if((mask>>i)&1)continue;
            int nmask = mask | (1<<i);
            if(D[bestMM[nmask]] < D[bestMM[mask]])
                bestMM[mask] = bestMM[nmask];
        }
    }

    LL mask1 = 1;
    int tmask = (1<<N) -1;
    LL ans = D[bestMM[tmask]];

    for(int mask =3; mask < (1<<N); mask+=2)
    {
        if( max(D[bestMM[mask]] , D[bestMM[tmask-mask+1]]) < ans)
        {
            ans = max(D[bestMM[mask]], D[bestMM[tmask-mask+1]]);
            mask1 = mask;
        }
    }
    cout<<ans<<endl;
    print(bestMM[mask1]);
    print(bestMM[tmask-mask1+1]);
    return 0;	
}
