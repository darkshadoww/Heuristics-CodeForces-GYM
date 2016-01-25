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

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

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

typedef long long LL;
typedef pair<LL,LL> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

#define MAXN 1000009
VI adj[MAXN];
int tim,tin[MAXN],tout[MAXN];
int val[MAXN];
int val1[MAXN];
PII tree[4*MAXN];
LL lazy[4*MAXN];

void build_tree(int node, int a, int b) {
    if(a > b) return;

    if(a == b) {
        tree[node].F = tree[node].S = (LL)val1[a];
        return;
    }

    build_tree(node*2, a, (a+b)/2);
    build_tree(node*2+1, 1+(a+b)/2, b);

    tree[node].F = min(tree[node*2].F, tree[node*2+1].F);
    tree[node].S = max(tree[node*2].S, tree[node*2+1].S);
}

void update_tree(int node, int a, int b, int i, int j, int value) {

    if(lazy[node] != 0) {
        tree[node].F += lazy[node];
        tree[node].S += lazy[node];

        if(a != b) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if(a > b || a > j || b < i)
        return;

    if(a >= i && b <= j) {
        tree[node].F += (LL)value;
        tree[node].S += (LL)value; 

        if(a != b) {
            lazy[node*2] += (LL)value;
            lazy[node*2+1] += (LL)value;
        }

        return;
    }

    update_tree(node*2, a, (a+b)/2, i, j, value);
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);

    tree[node].F = min(tree[node*2].F, tree[node*2+1].F);
    tree[node].S = max(tree[node*2].S, tree[node*2+1].S);
}

PII query_tree(int node, int a, int b, int i, int j) {

    if(a > b || a > j || b < i) return {LLONG_MAX, LLONG_MIN};

    if(lazy[node] != 0) {
        tree[node].F += lazy[node];
        tree[node].S += lazy[node];

        if(a != b) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if(a >= i && b <= j)
        return tree[node];

    PII q1 = query_tree(node*2, a, (a+b)/2, i, j);
    PII q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);

    PII res;
    res.F = min(q1.F, q2.F);
    res.S = max(q1.S, q2.S);
    return res;
}


void init(int n){
    for(int i=0; i<=n; i++)
        adj[i].clear();
    tim=0;
    memset(lazy, 0, sizeof(lazy));
}

void dfs(int node){
    tin[node]=tim;
    tim++;
    for(auto &j: adj[node])
        dfs(j);
    tout[node]=tim-1;
}

int main()
{
    int t;
    sd(t);
    while(t--){
        int n,q;
        sd(n);
        init(n);
        for(int i=1; i<n; i++){
            int p;
            sd(p);
            p--;
            adj[p].pb(i);
        }
        for(int i=0; i<n; i++)
            sd(val[i]);

        dfs(0);

        for(int i=0; i<n; i++)
            val1[tin[i]]=val[i];

        build_tree(1, 0, n-1);

        sd(q);
        getchar();
        while(q--){
            char c;
            int upd;
            scanf("%c %d ",&c,&upd);
            upd--;

            if(c=='R'){
                int val;
                scanf("%d ",&val);
                update_tree(1, 0, n-1, tin[upd], tout[upd], val);
            }
            else{
                PII ans=query_tree(1, 0, n-1, tin[upd], tout[upd]);
                printf("%lld\n", ans.S-ans.F);
            }
        }
    }
    return 0;
}

