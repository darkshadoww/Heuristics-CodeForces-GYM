#include<bits/stdc++.h>
using namespace std;

//#define TRACE
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
FILE *fin = freopen("show.in","r",stdin);
FILE *fout = freopen("show.out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

int A[200];
int P[400][200];
VI Valid[200];
VI valid_rows[400];
bool E[400][400];
set<int> G[1000];
set<int> rG[1000];
map<PII,int> mp;
PII rmp[1000];

int nt(int x)
{
    if(x%2)return x-1;
    return x+1;
}

void add_edge(int a, int b)
{
    G[a].insert(b); rG[b].insert(a);
    a = nt(a); b = nt(b);
    G[b].insert(a); rG[a].insert(b);
}

VI topo;
int n;
bool V[1000];
int C[1000];
void dfs(int x)
{
    if(V[x])return; V[x] = true; 
    for(auto y : G[x])dfs(y);
    topo.PB(x);
}
void dfs2(int x, int c)
{
    if(C[x])return; C[x] = c; for(auto y : rG[x]) dfs2(y,c);
}

int SET[1000];
bool bfs(int x)
{
    trace(x,C[x],SET[x]);
    if(SET[x])
    {
        if(SET[x]==-1)return false;
        return true;
    }
    queue<int> Q;
    SET[x] = 1; Q.push(x);
    while(!Q.empty())
    {
        x = Q.front(); Q.pop();


        if(SET[nt(x)]==0 or SET[nt(x)]==-1)
            SET[nt(x)] = -1;
        else 
            return false;
        for(auto i : G[x])
        {
            if(SET[i]==0){SET[i] = 1; Q.push(i);}
            if(SET[i]==-1)return false;
        }
    }
    return true;
}

int main()
{
    int N; si(N); for(int i =0 ;i<N; i++) si(A[i]);
    int M; si(M); for(int i =0; i<M; i++) for(int j = 0; j<N; j++) si(P[i][j]);

    n = 0;

    for(int i =0; i<N; i++)
        for(int j = 0; j<M; j++)
            if(P[j][i] == A[i])
            {
                Valid[i].PB(j);
                mp[MP(i,j)] = n;
                rmp[n] = {i,j};
                n++;
                valid_rows[j].PB(i);
            }

    for(int i =0; i<M; i++)
        for(int j = 0; j<M; j++)
            for(int k =0; k<N; k++)
                if(P[i][k]==P[j][k])
                    E[i][j] = true; 

    for(int i = 0; i<n; i++)
        for(int j = i+1; j<n; j++)
            if(E[rmp[i].S][rmp[j].S])
                add_edge( 2*i , 2*j+1); 

    bool can = true;

    // for each row, exactly one.

    for(int i =0; i<N; i++)
    {
        if(Valid[i].empty()){
            can = false; break;
        }
        else if(Valid[i].size()==2)
        {
            int p0 = Valid[i][0];
            int p1 = Valid[i][1];
            add_edge( 2*mp[{i,p0}] + 1 , 2*mp[ {i,p1}]);
            add_edge( 2*mp[{i,p0}] , 2*mp[ {i,p1}] + 1);
        }
    }
    if(can==false){ cout<<"NO\n"; return 0;}
    for(int i = 0; i<2*n; i++)
        dfs(i);
    reverse(topo.begin(), topo.end()); 
    int c = 0;
    for(auto x : topo)
        if(C[x]==0)
            dfs2(x,++c);
    for(int i =0; i<n; i++)
        if(C[2*i] == C[2*i+1])
            can = false;
    if(can==false){ cout<<"NO\n"; return 0;}
    
    
    
    for(int i =0; i<N; i++)
        if(Valid[i].size()==1){
            can &= bfs(2*mp[MP(i,Valid[i][0])]);
            for(int j =0; j<2*n; j++)trace(j,SET[j]);
        }
    // single true done.

    for(auto x : topo)
        if(SET[x]==0)
            can &= bfs(nt(x));
    if(can==false){ cout<<"NO\n"; return 0;}
    cout<<"YES\n";
    for(int i =0; i<N; i++)
    {
        if(SET[2*mp[MP(i,Valid[i][0])]]==1)
            cout<<Valid[i][0]+1<<" ";
        else
            cout<<Valid[i][1]+1<<" ";
    }
    cout<<endl;

    return 0;
}

