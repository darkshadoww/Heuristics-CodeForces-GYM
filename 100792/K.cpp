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

int indeg[200009];
VI adj[200009];

int main()
{
    int n,m,x,y;
    VI ans;
    sd(n),sd(m);
    set< PII > myset;
    for(int i=0; i<m; i++){
        sd(x),sd(y);
        if(myset.find(mp(x,y))!=myset.end())continue;
        indeg[x]++;
        adj[y].pb(x);
        myset.insert(mp(x,y));
    }
    priority_queue < int > myq;
    for(int i=1; i<=n; i++)
        if(indeg[i]==0)myq.push(i);
    while(not myq.empty()){
        int p=myq.top();
        ans.pb(p);
        myq.pop();
        for(auto &j: adj[p]){
            indeg[j]--;
            if(indeg[j]==0)
                myq.push(j);
        }
    }
    reverse(all(ans));
    for(int i=0; i<ans.size(); i++)
        printf("%d ",ans[i]);
    return 0;
}

