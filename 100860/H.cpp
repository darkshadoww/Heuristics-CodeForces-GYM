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
    int N,B,W,Bnew,Wnew;
    cin>>N;
    N*=N;
    B=W=N/2;
    if(N&1)
        B++;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int Nnew = (x2-x1+1)*(y2-y1+1);
    Bnew = Wnew = Nnew/2;
    if(Nnew&1)
    {
        if((x1+y1)&1)
            Wnew++;
        else
            Bnew++;
    }
    B-=Bnew;
    W-=Wnew;
    cout<<abs(B-W)<<endl;
    return 0;
}
