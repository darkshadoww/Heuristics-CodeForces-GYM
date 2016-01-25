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
#define si(n) scanf("%d",&n)
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



set<int> Q[101];
int T,N; 
inline bool val(int x)
{
    if(x<0 or x>T)return false;
    return true;
}

int main()
{
    bool possible = true;
    int test; si(test); while(test--)
    {
        si(T); si(N);
        for(int i = 0; i<=N; i++)
             Q[i].clear();
        for(int t = 0; t<=T; t++)
            Q[0].insert(t);
        for(int i = 0; i<N; i++)
        {
            int st,et;
            si(st); si(et);
            int d = et-st;
            for(auto x : Q[i])
            {
                if(val(x-d)) Q[i+1].insert(x-d);
                if(val(x+d)) Q[i+1].insert(x+d);
            }
        }
        if(Q[N].empty()) 
        {
            possible = false;
            break;
        }
    }
    if(possible)cout<<"possible\n"; else cout<<"impossible\n";
    return 0;
}
