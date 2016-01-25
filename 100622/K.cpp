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

FILE *fin = freopen("kripke.in","r",stdin);
FILE *fout = freopen("kripke.out","w",stdout);


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MAXN 10000
int color[MAXN];
VI adj[MAXN];

VI bfs(int n, VI st, int mask, bool fl){
    vector<bool>vis(n, false);
    queue<int> myq;
    for(auto &i: st){
        myq.push(i);
        vis[i]=true;
    }
    while(not myq.empty()){
        int p = myq.front();
        myq.pop();
        for(auto &i: adj[p])
            if(not vis[i] and (color[i]&mask) == mask)
                myq.push(i), vis[i]=true;
    }
    VI ret;
    for(int i = 0; i < n; i++)
        if(vis[i] == fl)
            ret.PB(i);

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    int n, m, k, u, v;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i ++){
        int cnt;
        char ch;
        cin >> cnt;
        while(cnt--){
            cin >> ch;
            color[i] |= (1<<(ch-'a'));
        }
    }
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        u--,v--;
        adj[v].PB(u);
    }
    string s; 
    cin >> s;
    VI init;
    for(int i = 0; i<n; i++)
        if(not (color[i]&(1<<(s[7]-'a'))))
            init.PB(i);
    VI ans = bfs(n, bfs(n, init, 0, false), 1<<(s[2]-'a'), true);
    cout << ans.size() << endl;
    for(auto &i: ans)
        cout << i+1 << endl;
    return 0;
}

