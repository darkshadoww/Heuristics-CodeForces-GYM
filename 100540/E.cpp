#include<bits/stdc++.h>
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

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}


#define MX 20009
int x[MX], y[MX], w[MX];
unordered_map < int , int > mapping;
VPII adj[MX];
int vis[MX], L[MX], tillw[MX];
int actual[MX];
bool found;
int foundnode, foundweight;
int comp[MX];

void dfs1(int node, int level, int weight, int cmpno){
    tillw[node] = weight;
    vis[node] = 1;
    comp[node] = cmpno;
    L[node]=level;
    for(auto &i: adj[node]){
        if(!vis[i.F]){
            if(level%2==0)
                dfs1(i.F, level+1, weight + i.S, cmpno);
            else
                dfs1(i.F, level+1, weight - i.S, cmpno);
        }
        else{
            // odd cycle found
            if((L[i.F]+level)%2==0){
                found = true;
                foundnode = i.F;
                if(level%2==0)
                    foundweight = (weight - tillw[i.F] + i.S)/2;
                else
                    foundweight = -(weight - tillw[i.F] - i.S)/2;
            }
        }
    }
}

void explore(int node, int weight){
    actual[node] = weight;
    queue < int > myq;
    myq.push(node);
    while(not myq.empty()){
        int p=myq.front();
        myq.pop();

        for(auto &i: adj[p])
            if(actual[i.F]==INT_MAX){
                actual[i.F] = (i.S - actual[p]);
                myq.push(i.F);
            }
    }
}

void init(){
    mapping.clear();
    memset(vis, 0, sizeof(vis));
    for(auto &i: adj)
        i.clear();
}

int main()
{
    while(1){
        init();
        int n, q;
        VI tmp;
        sd(n), sd(q);
        if(n+q==0)break;
        for(int i=0; i<n; i++){
            sd(x[i]), sd(y[i]), sd(w[i]);
            if(x[i] == y[i])
                w[i]*=2;
            tmp.pb(x[i]);
            tmp.pb(y[i]);
        }

        sort(all(tmp));
        tmp.erase(unique(all(tmp)), tmp.end());
        for(int i=0; i<tmp.size(); i++){
            mapping[tmp[i]]=i;
            trace(tmp[i], i);
        }

        for(int i=0; i<n; i++){
            adj[mapping[x[i]]].pb({mapping[y[i]], w[i]});
            adj[mapping[y[i]]].pb({mapping[x[i]], w[i]});
        }

        n=tmp.size();


        for(int i=0; i<n; i++)
            actual[i] = INT_MAX;

        for(int i=0; i<n; i++)
            if(not vis[i]){
                found=false;
                dfs1(i, 0, 0, i);
                if(found)
                    explore(foundnode, foundweight);
            }


        for(int i=0; i<n; i++)
            trace(i, actual[i], comp[i]);

        while(q--){
            int x, y;
            sd(x), sd(y);

            if(not mapping.count(x) or not mapping.count(y)){
                printf("*\n");
                continue;
            }

            int nx = mapping[x], ny = mapping[y];
            if(actual[nx]!=INT_MAX and actual[ny]!=INT_MAX){
                if(nx==ny)printf("%d\n", (actual[nx] + actual[ny])/2);
                else printf("%d\n", actual[nx] + actual[ny]);
                continue;
            }

            if(comp[nx] != comp[ny]){
                printf("*\n");
                continue;
            }

            int lx = L[nx], ly = L[ny];
            if((lx + ly)%2 == 0){
                printf("*\n");
                continue;
            }

            int ans;
            if(lx%2==0)ans = -tillw[nx];
            else ans = +tillw[nx];
            if(ly%2==0)ans -= tillw[ny];
            else ans += tillw[ny];

            printf("%d\n", ans);
        }
        printf("-\n");
    }
    return 0;
}


