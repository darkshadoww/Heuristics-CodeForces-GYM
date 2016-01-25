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


int main()
{
    int h,m,s;
    char ap;
    int a,b;
    scanf("%2d:%2d:%2d%c%*s",&h,&m,&s,&ap);
    if(h==12) h=0;
    a = h*60*60 + m*60 + s;
    if(ap=='P')
        a+=12*60*60;
    scanf("%2d:%2d:%2d%c%*s",&h,&m,&s,&ap);
    if(h==12) h=0;
    b = h*60*60 + m*60 + s;
    if(ap=='P')
        b+=12*60*60;
    int dif = b-a;
    if(dif<=0) dif+=24*60*60;
    s=dif%60;
    dif/=60;
    m=dif%60;
    dif/=60;
    h=dif;
    printf("%02d:%02d:%02d\n", h,m,s);
    return 0;
}

