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

#define int long long

typedef long long LL;

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
};


struct PushRelabel {
    int N;
    vector<vector<Edge> > G;
    vector<LL> excess;
    vector<int> dist, active, count;
    queue<int> Q;

    PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

    void AddEdge(int from, int to, int cap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    void Enqueue(int v) { 
        if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
    }
    set<int> Visit;

    void dfs(int x)
    {
        if(Visit.count(x))return;
        Visit.insert(x);
        for(auto y : G[x])
            if(y.flow < y.cap)
                dfs(y.to);
    }

    void Push(Edge &e) {
        int amt = min(excess[e.from], LL(e.cap - e.flow));
        if (dist[e.from] <= dist[e.to] || amt == 0) return;
        e.flow += amt;
        G[e.to][e.index].flow -= amt;
        excess[e.to] += amt;    
        excess[e.from] -= amt;
        Enqueue(e.to);
    }

    void Gap(int k) {
        for (int v = 0; v < N; v++) {
            if (dist[v] < k) continue;
            count[dist[v]]--;
            dist[v] = max(dist[v], N+1);
            count[dist[v]]++;
            Enqueue(v);
        }
    }

    void Relabel(int v) {
        count[dist[v]]--;
        dist[v] = 2*N;
        for (int i = 0; i < G[v].size(); i++) 
            if (G[v][i].cap - G[v][i].flow > 0)
                dist[v] = min(dist[v], dist[G[v][i].to] + 1);
        count[dist[v]]++;
        Enqueue(v);
    }

    void Discharge(int v) {
        for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
        if (excess[v] > 0) {
            if (count[dist[v]] == 1) 
                Gap(dist[v]); 
            else
                Relabel(v);
        }
    }

    LL GetMaxFlow(int s, int t) {
        count[0] = N-1;
        count[N] = 1;
        dist[s] = N;
        active[s] = active[t] = true;
        for (int i = 0; i < G[s].size(); i++) {
            excess[s] += G[s][i].cap;
            Push(G[s][i]);
        }

        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            active[v] = false;
            Discharge(v);
        }

        LL totflow = 0;
        for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
        return totflow;
    }
};














const LL off = 1000000000000ll;
const LL bigoff = 100000000000000000ll;

int N,M;


bool on_boundary(int i, int j)
{
    if(i==0 or i==N-1 or j==0 or j==M-1)return true; return false;
}






string S[50];
#undef int
int main()
#define int long long
{
    int t; cin>>t; while(t--)
    {
        cin>>M>>N;
        LL  d,f,b;
        cin>>d>>f>>b;
        for(int i =0; i<N; i++)
            cin>>S[i];
        LL tc = 0;
        int tN = 2 + N*M;
        int src = 0;
        int dest = tN -1;
        PushRelabel G(tN);
        LL trem = 0;
        for(int i =0; i<N; i++)
            for(int j =0; j<M; j++)
            {
                int nn = 1 + i*M + j;
                if(on_boundary(i,j))
                {
                    if(S[i][j]=='.')
                    {
                        S[i][j] = '#';
                        tc += f;
                    }
                    G.AddEdge(nn,dest,bigoff);
                }
                else
                {
                    trem += off;
                    if(S[i][j]=='#')
                    {
                        G.AddEdge(nn,dest,off + d);
                        G.AddEdge(src,nn,off);
                    }
                    else
                    {
                        G.AddEdge(nn,dest,off);
                        G.AddEdge(src,nn,f + off);
                    }
                    for(int k = 0; k<4; k++)
                    {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        G.AddEdge(nn, 1 + ni*M + nj,b);
                    }
                }
            }
        cout<< tc + G.GetMaxFlow(src,dest) - trem<<endl;
    }
    return 0;	
}
