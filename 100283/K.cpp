
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
FILE *fin = freopen("cubes.in","r",stdin);
#endif
int A[100];
int B[100];
int main()
{
    int t; si(t); int T = t; while(t--)
    {
        int N; si(N); for(int i =0; i<N; i++) si(A[i]); sort(A,A+N);
        printf("Case %d:\n",T-t);
        int l = 0; 
        int r = N-1;
        bool left = false;
        for(int i = N-1; i>=0; i--)
        {
            if(left){
                B[l++] = A[i];
                left = false;
            }
            else
            {
                B[r--] = A[i]; left = true;
            }
        }
        for(int i =0; i<N; i++) printf("%d%c",B[i],(i==N-1 ? '\n' : ' '));
    }
    return 0;	
}
