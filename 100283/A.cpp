
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
FILE *fin = freopen("zeriba.in","r",stdin);
#endif

double PI;
int A[1000];

int main()
{
    PI = atan2(0,-1);
    int t; si(t); int T = t; while(t--)
    {
        int N;
        si(N);
        for(int i =0; i<N; i++) si(A[i]); sort(A,A+N);
        int sum = 0;
        for(int i =0; i<N; i++)sum+=A[i];
        printf("Case %d: ",T-t);
        if(sum-A[N-1] <= A[N-1])
        {
            printf("can't form a convex polygon\n"); continue;
        }
        double l = A[N-1];
        double h = sum;
        int iter = 100;
        while(iter--)
        {
            double m = (l+h)/2;
            double theta = 0;
            for(int i =0; i<N; i++)
                theta += asin(A[i]/m);
            if(theta > PI) l = m; else h = m;
        }
        printf("%.4lf\n",l/2);
    }
    return 0;	
}
