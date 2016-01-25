
//karanaggarwal
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

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define all(v) (v).begin(),(v).end()

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

const int mod = 1000000007;
inline void add(int &x, int y){x+=y; if(x>=mod)x-=mod; if(x<0)x+=mod;}
inline int mul(int x, int y){ return ((LL)x * y)%mod;}
int gcd(int a, int b){ if(b)return gcd(b,a%b); return a;}
int power(int a ,int p){int ret = 1; while(p){if(p&1)ret=mul(ret,a); a=mul(a,a); p/=2;}return ret;}
int phi(int n){ int ret=n; int i = 2; 
    if(n%i==0){ ret-=ret/i; while(n%i==0)n/=i;}
    for(i=3; i*i<=n; i++)if(n%i==0){ ret-=ret/i; while(n%i==0)n/=i;}
    if(n>1)ret-=ret/n;return ret;
}
#ifdef ONLINE_JUDGE
FILE *fin = freopen("jubilee.in","r",stdin);
FILE *fout = freopen("jubilee.out","w",stdout);
#endif

int V[301];
int G[301];
int process(int x, int y){
    return 6-(x+y);
}
int main()
{
    while(1)
    {
        int N; si(N); if(N==0)return 0;
        if(N<=3)
        {
            cout<<1<<endl;
            for(int i = 0; i<N; i++) cout<<1<<" "; cout<<endl;
            for(int i = 0; i<N; i++) cout<<1<<" "; cout<<endl;
            continue;
        }
        if(N<=6)
        {
            cout<<2<<endl;
            int i = 0;
            for(;i<3;i++) cout<<"1 ";
            for(;i<N;i++) cout<<"2 ";
            cout<<endl;
            for(int i = 0; i<N; i++)
                cout<<(i%2)+1<<" "; 
            cout<<endl;
            continue;
        }
        int i = 0;
        int c = 0;
        if(N%3==1)
        {
            V[i++] = ++c; c%=2;
            V[i++] = ++c; c%=2;
            V[i++] = ++c; c%=2;
            V[i++] = ++c; c%=2;
        }
        while(i<N)
        {
            V[i++] = ++c; c%=3;
        }
        for(int i = 0; i<N; i++)
            G[i] = process(V[i],V[(i+1)%N]);
        cout<<3<<endl;
        for(int i  =0; i<N; i++) cout<<V[i]<<" "; cout<<endl;
        for(int i  =0; i<N; i++) cout<<G[i]<<" "; cout<<endl;
    }
    return 0;	
}
