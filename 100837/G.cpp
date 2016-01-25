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

FILE *fin = freopen("g.in","r",stdin);
FILE *fout = freopen("g.out","w",stdout);

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
int parent[MAXN];
unordered_map < int , list<int> > mymap;

int find(int x){
    if(parent[x]==x)return x;
    return parent[x]=find(parent[x]);
}

void merge(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y)return;

    parent[y] = x;
    mymap[x].splice(mymap[x].end(),mymap[y]);
}

vector< vector<int> > upd;
bool cmp(const VI& a, const VI& b){
    return a[0]>b[0];
}

bool cmp1(const list<int>& a, const list<int>& b){
    return a.front()<b.front();
}


int main()
{
    //ios_base::sync_with_stdio(false);
    int n,m,q;
    sd(n),sd(m),sd(q);
    upd.resize(m);

    for(int i=1; i<=n; i++){
        parent[i]=i;
        mymap[i].push_back(i);
    }


    for(int i=0; i<m; i++){
        int height,l,x;
        sd(height),sd(l);
        if(l==0)continue;
        upd[i].pb(height);
        for(int j=0; j<l; j++){
            sd(x);
            upd[i].pb(x);
        }
    }

    sort(all(upd), cmp);
    for(auto &i: upd){
        VPII myar;
        for(int j=1; j<i.size(); j++)
            myar.pb({mymap[find(i[j])].front(), i[j]});
        sort(all(myar));
        for(int j=1; j<myar.size(); j++)
            merge(myar[0].S, myar[j].S);
    }

    vector< list<int> > finupd;
    vector< int> fin;
    for(int i=1; i<=n; i++)
        if(parent[i]==i)
            finupd.pb(mymap[i]);
    sort(all(finupd), cmp1);

    for(auto &i: finupd)
        for(auto &j: i)
            fin.pb(j);
    while(q--){
        int x;
        sd(x);
        x--;
        printf("%d\n",fin[x]);
    }
    return 0;
}

