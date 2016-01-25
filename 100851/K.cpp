#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<cmath>

#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
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

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector< PII > VPII;


#ifdef ONLINE_JUDGE
FILE *fin = freopen("king.in","r",stdin);
FILE *fout = freopen("king.out","w",stdout);
#endif

const int MN = 100000;
set<int> IN[MN];
set<int> OUT[MN];
int N,M;
bool indone[MN];
bool outdone[MN];
int NXT[MN];
int PRV[MN];

queue<int> IN1;
queue<int> OUT1;

void process(int x, int y)
{
    indone[y] = outdone[x] = true;
    NXT[x] = y; PRV[y] = x;
    for(auto y2 : OUT[x])
    {
        IN[y2].erase(x);
        if(IN[y2].size()==1)
            IN1.push(y2);      
    }
    for(auto x2 : IN[y])
    {
        OUT[x2].erase(y);
        if(OUT[x2].size()==1)OUT1.push(x2);
    }
    OUT[x].clear(); IN[y].clear();
}


VI nn[1<<20];
bool DP[1<<20][20];
int P[1<<20][20];
bool isEdge[20][20];

void cycle(int N, VI &path)
{
    for(int mask  = 0; mask <(1<<N); mask++)
        for(int j = 0; j<N; j++)
            if(mask & (1<<j))nn[mask].PB(j);
    DP[1][0] = true;
    P[1][0] = -1;
    for(int mask = 3; mask<(1<<N); mask+=2)
    {
        for(auto l : nn[mask])
        {
            for(auto u : nn[mask - (1<<l)])
            {
                if(isEdge[u][l] and DP[mask-(1<<l)][u])
                {
                    P[mask][l] = u;
                    DP[mask][l] = true;
                    break;
                }
            }
        }
    }
    int fm = (1<<N) - 1;
    int last = -1;
    for(int l = 1; l<N; l++)
    {
        if(DP[fm][l] and isEdge[l][0])
        {
            last = l; break;
        }
    }
    if(last==-1)return;
    while(fm>0)
    {
        path.PB(last); 
        int nl = P[fm][last];
        fm -= (1<<last);
        last = nl;
    }
    reverse(path.begin(),path.end());
}

VI Chain[100000];

int main()
{
    si(N); si(M);
    if(M<N)
    {cout<<"There is no route, Karl!\n"; return 0;}
    while(M--)
    {
        int x,y; si(x); si(y); x--; y--; OUT[x].insert(y); IN[y].insert(x);
    }

    for(int i =0; i<N; i++)
    {
        if(IN[i].empty() or OUT[i].empty())
        {cout<<"There is no route, Karl!\n"; return 0;}
    }
    for(int i = 0; i<N; i++)
    {
        if(IN[i].size()==1)
            IN1.push(i);
        if(OUT[i].size()==1)
            OUT1.push(i);
    }
    while(1)
    {
        if(IN1.empty() and OUT1.empty())break;
        if(!IN1.empty())
        {
            int y = IN1.front(); IN1.pop();
            if(indone[y])continue;
            if(IN[y].empty())
            {cout<<"There is no route, Karl!\n"; return 0;}
            int x = *IN[y].begin();
            if(outdone[x])
            {cout<<"There is no route, Karl!\n"; return 0;}
            process(x,y);
        }
        if(!OUT1.empty())
        {
            int x = OUT1.front(); OUT1.pop();
            if(outdone[x])continue;
            if(OUT[x].empty())
            {cout<<"There is no route, Karl!\n"; return 0;}
            int y = *OUT[x].begin();
            if(indone[y])
            {cout<<"There is no route, Karl!\n"; return 0;}
            process(x,y);
        }
    }

    VI NM;
    int n = 0;
    map<int,int> rM;
    for(int i =0; i<N; i++)if(indone[i]==false)
    {
        NM.PB(i); rM[i] = n++;
        int x = i;
        Chain[x].PB(x); while(outdone[x]){ x= NXT[x]; Chain[i].PB(x);  }
    }
    VI TP;
    if(n==0)
    {
        int x = 0;
        TP.PB(1);
        while(1)
        {
            x = NXT[x];
            TP.PB(x+1); if(x==0)break;
        }
        if(TP.size()!=N+1)
        {cout<<"There is no route, Karl!\n"; return 0;}
        for(auto c : TP) cout<<c<<" "; cout<<endl; return 0;
    }

    for(int i =0; i<n; i++)
    {
        int x = NM[i]; x = Chain[x].back();
        for(auto y : OUT[x])
            isEdge[i][rM[y]] = true;
    }
    VI path;
    cycle(n,path);
    if(path.size() != n)
    {cout<<"There is no route, Karl!\n"; return 0;}
    for(auto c : path)
    {
        c = NM[c]; 
        for(auto x : Chain[c])
            TP.PB(x+1);
    }
    if(TP.size() < N)
    {cout<<"There is no route, Karl!\n"; return 0;}
    int i = 0;
    while(TP[i]!=1)i++;
    for(int j = i; j<N; j++)
        printf("%d ",TP[j]);
    for(int j = 0; j<=i; j++)
        printf("%d ",TP[j]);
    cout<<endl;
    return 0;
}


