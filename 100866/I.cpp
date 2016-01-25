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
//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;


int EDGE[501][501];
bool V[501][501];
bool V2[501][501];
int ans;
int ans2;

void remove_hori(int x, int y)
{
    EDGE[x][y] &= 11;
    EDGE[x-1][y] &= 14;
}

void remove_vert(int x, int y)
{
    EDGE[x][y] &= 7;
    EDGE[x][y-1] &= 13;
}
void add_hori(int x, int y)
{
    EDGE[x][y] |= (4);
    EDGE[x-1][y] |= 1;
}

void add_vert(int x, int y)
{
    EDGE[x][y] |= 8;
    EDGE[x][y-1] |= 2;
}


int DX[4] = {1,0,-1,0};
int DY[4] = {0,1,0,-1};

void dfs(int i, int j)
{
    if(i<0 or j<0 or i>500 or j>500)return;
    if(V[i][j])return;
    V[i][j] = true;
    ans++;
    for(int d = 0; d<4; d++)
        if(EDGE[i][j] & (1<<d))
            dfs(i+DX[d] , j + DY[d]);
}
void dfs2(int i, int j)
{
    if(i<0 or j<0 or i>500 or j>500)return;
    if(V2[i][j])return;
    V2[i][j] = true;
    ans2++;
    for(int d = 0; d<4; d++)
        if(EDGE[i][j] & (1<<d))
            dfs2(i+DX[d] , j + DY[d]);
}

int main()
{
    int N; 
    si(N);
    for(int i = 0; i<=500; i++)
        for(int j = 0; j<=500; j++)
            EDGE[i][j] = 15;
    while(N--){
        int x1,y1,x2,y2;
        si(x1); si(y1); si(x2); si(y2);
        if(x1==x2)
        {
            int x = x1;
            if(y2<y1)swap(y1,y2);
            for(int y = y1; y<y2; y++)
                remove_hori(x,y);
        }
        if(y1==y2)
        {
            int y = y1;
            if(x2<x1)swap(x2,x1);
            for(int x = x1; x<x2; x++)
                remove_vert(x,y);
        }
    }
    ans = 0;
    dfs(0,0);
    si(N); while(N--){
        int x1,y1,x2,y2;
        si(x1); si(y1); si(x2); si(y2);
        if(x1==x2)
        {
            int x = x1;
            if(y2<y1)swap(y1,y2);
            for(int y = y1; y<y2; y++)
                add_hori(x,y);
        }
        if(y1==y2)
        {
            int y = y1;
            if(x2<x1)swap(x2,x1);
            for(int x = x1; x<x2; x++)
                add_vert(x,y);
        }
    }
    ans2 = 0;
    dfs2(0,0);
    cout<<ans2 - ans<<endl;
    return 0;
}

