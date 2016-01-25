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


int gcd(int a, int b)
{
    if(b)return gcd(b,a%b); return a;
}

int C[100009];

int foo(int K, int N)
{
    for(int i = 0; i<N-1; i++)
        if( (C[i+1] - C[i]) % (K*N))return 0; 
    int cc = C[0]; cc/=K;
    if(cc<=N)return 0;
    int md = cc%N;
    if(md==0)return (cc/N)-1;
    return cc/N;
}

int main()
{
    while(1)
    {
        int n,gc=0;
        LL ans=0;
        si(n);
        if(not n)return 0;
        for(int i=0; i<n; i++)
        {
            si(C[i]);
            gc=gcd(gc, C[i]);
        }
        sort(C, C+n);
        for(int i=1; i*i<=gc; i++)
        {
            if(gc%i==0)
            {
                ans += foo(i, n);
                if(i*i!=gc)
                {
                    ans += foo(gc/i, n);
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;	
}
