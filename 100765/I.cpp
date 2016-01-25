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


struct node{
    int cost,ind,sum;
    node(int a, int b, int c): cost(a), ind(b), sum(c) {}
    bool operator<(const node other) const{
        return cost<other.cost;
    }
};

int b[609];
vector< node > box[609];
int dp[609][609];
PII parent[609][609];

int rec(int i, int j){
    if(i<1){
        if(j==0)return 0;
        return MOD;
    }
    if(j==0)return 0;
    int &ret=dp[i][j];
    if(ret!=-1)return ret;

    parent[i][j]=mp(i-1,j);
    ret=rec(i-1,j);
    int size=box[i].size();
    for(int used=1; used<=min(size,j); used++){
        int cost=box[i][used-1].sum + (used>0)*b[i];
        int p=cost + rec(i-1, j-used);
        if(p<ret)parent[i][j]=mp(i-1,j-used),ret=p;
    }
    return ret;
}

void back(int i, int j){
    if(j==0 or i<1)return;
    int used=j-parent[i][j].S;
    for(int k=0; k<used; k++)
        printf("%d ",box[i][k].ind);
    back(parent[i][j].F,parent[i][j].S);
}


int main()
{
    memset(dp,-1,sizeof(dp));
    int n,k,p;
    sd(n),sd(k),sd(p);
    for(int i=1; i<=k; i++)
        sd(b[i]);
    for(int i=1; i<=n; i++){
        int x,y;
        sd(x),sd(y);
        box[y].pb(node(x,i,0));
    }
    for(int i=1; i<=k; i++)
        sort(all(box[i]));
    for(int i=1; i<=k; i++){
        for(int j=0; j<box[i].size(); j++)
            if(j==0)box[i][j].sum=box[i][j].cost;
            else box[i][j].sum=box[i][j-1].sum + box[i][j].cost;
    }
    int ans=0;
    for(int used=0; used<=n; used++)
        if(rec(n,used)<=p)ans=used;
    cout << ans << endl;
    back(n,ans);
    return 0;
}

