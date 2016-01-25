#ifdef __APPLE__
#include<cassert>
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<sstream>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

#else

#include<bits/stdc++.h>

#endif  // __APPLE__


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

#define MAXN 10009
#define EPS 1e-11

int t,rain[MAXN],pre[MAXN];
int rain2[MAXN], pre2[MAXN];
double c,d;


double query(int i, int j)
{
    if(j<=i)return 0;
    return pre[j-1] - pre[i-1]; 
}

bool vis[10001];
double mvis[10001];
double ans;
double f(int l, int r)
{
    double lt = 0; 
    double ht = 1;
    double fac = 100;
    if(l>1 and rain[l-1]<fac)fac = rain[l-1];
    if(r<=t and rain[r]<fac)fac = rain[r];
    double con = query(l,r);
    if(con + c/(r-l+1) > ans)return ans;
    int iter = 20;
    if(r-l==t)iter = 0;
    while(iter--)
    {
        double t1 = (lt*2 + ht)/3;
        double t2 = (lt + 2*ht)/3;
        if(  fac*t1 + c/(t1+(r-l)) <   fac*t2 + c/(t2 + (r-l))    )
            ht = t2;
        else
            lt = t1;
    }
    return con +  fac*lt + c/(lt+(r-l));
}



int main()
{
    cin >> t >> c >> d;
    c *= 3600;
    c *= d; 
    c *= d; 

    rain[0] = pre[0] = 0;
    for(int i=1; i<=t; i++)
    {
        sd(rain[i]);
        pre[i] = pre[i-1] + rain[i];
    }
    ans = pre[t] + c/t;
    for(int i = 1; i<=t; i++)
        for(int j = i; j<=t+1; j++)
            ans = min(ans,f(i,j));
    printf("%.9lf\n",ans);
    return 0;
}
