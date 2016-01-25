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
#define REP(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define all(v) (v).begin(),(v).end()

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

#ifdef ONLINE_JUDGE
FILE *fin = freopen("hentium.in","r",stdin);
FILE *fout = freopen("hentium.out","w",stdout);
#endif


LL graph[102][102];
int A[100],B[100],W[100][100];
int C[101];
int V;

int bfs(LL rGraph[][102], int s, int t, int parent[])
{
    vector<bool> visited(V);
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}
void dfs(LL rGraph[V][V], int s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < V; i++)
        if (rGraph[s][i] && !visited[i])
            dfs(rGraph, i, visited);
}
void minCut(LL graph[V][V], int s, int t)
{
    int u, v;
    LL rGraph[102][102]; // rGraph[i][j] indicates residual capacity of edge i-j
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    vector<int> parent(V);
    while (bfs(rGraph, s, t, parent))
    {
        LL path_flow = LLONG_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }
    vector<bool> 
    bool visited[V];
    memset(visited, false, sizeof(visited));
    dfs(rGraph, s, visited);
    LL val = 0;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (visited[i]) && !visited[j] && graph[i][j])
            {
                val += graph[i][j];
                C[i] = 1;
            }

    return;
}




int main()
{
    while(1)
    {
        int N; si(N);
        memset(graph,0,sizeof(graph));
        if(N==0)return 0;
        for(int i = 0; i<N; i++){si(A[i]); si(B[i]);}
        for(int i =0; i<N; i++)
            for(int j = 0; j<N; j++) si(W[i][j]);
        PushRelabel G(N+2);
        memset(C,0,sizeof(C));

        for(int i =1; i<=N; i++)
        {
            G.AddEdge(0,i,A[i-1]);
            G.AddEdge(i,N+1,B[i-1]);
        }
        for(int i = 1; i<=N; i++)
            for(int j = 1; j<=N; j++)
                if(i!=j)
                {
                    G.AddEdge(i,N+j,W[i-1][j-1]);
                }
        LL ans = G.GetMaxFlow(0,N+N+1);
        cout<<ans<<endl;
        memset(C,0,sizeof(C));
        G.find(0);
        for(auto c : G.Reachable)trace(c);
    }
    return 0;	
}
