
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
FILE *fin = freopen("iq.in","r",stdin);
FILE *fout = freopen("iq.out","w",stdout);
#endif

int N;
PII A[10000];
int P[10001];
LL DP[10001];

int main()
{
    while(1)
    {
        si(N); if(N==0)return 0;
        for(int i =0; i<N; i++) 
        {
            si(A[i].F);
            A[i].S = i;
        }
        sort(A,A+N);
        DP[0] =0;
        for(int i =1; i<=N; i++)
        {
            DP[i] = (LL)A[i-1].F * N;
            P[i] = 0;
            for(int k = i-1; k>0; k--)
            {
                if(DP[k] + (LL)A[i-1].F * (N-k) < DP[i])
                {
                    P[i] = k;
                    DP[i] = DP[k] + (LL)A[i-1].F * (N-k);
                }
            }
        }
        cout<<DP[N]<<endl;
        vector<VI> TP;
        int i = N;
        while(i>0)
        {
            VI cr;
            int x = i - P[i];
            while(x--)
                cr.PB(A[--i].S + 1);       
            TP.PB(cr);
        }
        int n = TP.size();
        cout<<n<<endl;
        for(int i = n-1; i>=0; i--)
        {
            VI &c =  TP[i];
            cout<<c.size()<<" ";
            for(auto x : c) cout<<x<<" "; cout<<endl;
        }
    }
    return 0;	
}
