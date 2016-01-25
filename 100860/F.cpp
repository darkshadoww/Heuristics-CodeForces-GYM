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

#ifdef ONLINE_JUDGE
//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

bool is_valid(int n)
{
    while(n>0){
    int l = n%4;
    if(l==2)return false; if(l==3)l = -1; 
    n-=l; n/=4;
    }
    return true;
}

int f(int m)
{
    if(m<2)return m;
    if(m<6)return m-1;
    int ret = 3 * f( (m-1) /4 ) + 1;
    while( m%4  != 1)
    {
        if(is_valid(m))ret++; m--;
    }
    return ret;
}

int main()
{
    int n,m; 
    cin>>n>>m;
    LL p = 1; 
    LL sum = 0;
    while(sum<m and n>0)
    {
        sum += p;
        p*=4; n--;
    }
    if(sum<m)m = sum;
    cout<<f(m)<<endl;
    return 0;
}

