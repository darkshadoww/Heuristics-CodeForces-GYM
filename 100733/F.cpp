#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
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
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

#define MAXN 100009
LL d[MAXN];
int t[MAXN],v[MAXN];
LL dp[MAXN];
unordered_map < LL, int> mapped;

LL tree[12*MAXN];
class segtree{
    public:
        void update(int node, int a, int b, int i, LL value) {
            if(a > b || b < i || a>i)
                return;
            if(a == b) {
                tree[node] = max(tree[node], value);
                return;
            }
            update(node*2, a, (a+b)/2, i, value);
            update(1+node*2, 1+(a+b)/2, b, i, value);
            tree[node] = max(tree[node*2], tree[node*2+1]);
        }
        LL query(int node, int a, int b, int i, int j) {
            if(a > b || a > j || b < i) return LLONG_MIN;
            if(a >= i && b <= j)
                return tree[node];
            LL q1 = query(node*2, a, (a+b)/2, i, j);
            LL q2 = query(1+node*2, 1+(a+b)/2, b, i, j);
            return max(q1, q2);
        }
};

int main()
{
    
    vector<LL> my;
    segtree mytree;
    int n;
    sd(n);
    for(int i=0; i<n; i++){
        scanf("%lld %d %d",&d[i],&v[i],&t[i]);
        my.pb(d[i]);
        if(d[i]>=(LL)t[i])my.pb(d[i]-(LL)t[i]);
    }
    sort(all(my));
    my.erase(unique(all(my)),my.end());
    for(int i=0; i<my.size(); i++)
        mapped[my[i]]=i+1;

    int N=my.size()+10;
    dp[0]=v[0];
    LL ans=dp[0];
    mytree.update(1,0,N,mapped[d[0]],dp[0]);

    for(int i=1; i<n; i++){
        dp[i]=(LL)v[i]+mytree.query(1,0,N,mapped[d[i]-(LL)t[i]],mapped[d[i]]);
        mytree.update(1,0,N,mapped[d[i]],dp[i]);
        ans=max(ans,dp[i]);
    }
    cout << ans << endl;
    return 0;
}


