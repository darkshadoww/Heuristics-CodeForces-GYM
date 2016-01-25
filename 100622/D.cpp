#include<bits/stdc++.h>
using namespace std;

//#define TRACE
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

FILE *fin = freopen("dragon.in","r",stdin);
FILE *fout = freopen("dragon.out","w",stdout);


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;


int main()
{
    int n,d;
    cin>>n>>d;
    if(n<=7)
    {
        int val=1;
        for(int i=0; i<n-1; i++)
            val*=10;
        val = val + ((d-(val%d))%d);
        int num=0, chk=val;
        while(chk!=0)
        {
            num++;
            chk/=10;
        }
        if(num!=n)
            cout<<"No solution"<<endl;
        else
            cout<<val<<endl;
    }
    else
    {
        int mod=1;
        for(int i=0; i<n-1; i++)
            mod=(mod*10)%d;
        mod=(d-mod)%d;
        int num=0, chk=mod;
        while(chk!=0)
        {
            num++;
            chk/=10;
        }
        cout<<1;
        for(int i=0; i<n-num-1; i++) cout<<0;
        if(num!=0)
            cout<<mod;
        cout<<endl;
    }
    return 0;
}

