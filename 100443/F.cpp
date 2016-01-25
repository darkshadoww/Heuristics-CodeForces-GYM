#include<bits/stdc++.h>

#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
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

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

map<LL,LL> ANS;

bool is_even(LL x)
{
    LL ans = 0;
    while(x)
    { 
        x/=5; ans+=x;
    }
    return ans%2==0;
}

LL f(LL x)
{
    if(x<100000)return L[x];
    LL X = x;

    LL rem = 0;

    while()
    

}
int L[100000];

int main()
{

    for(int i =0; i<100000; i++)
        L[i] = is_even(i);
    for(int i = 1; i<100000; i++)L[i] += L[i-1];
    int t; si(t); while(t--)
    {
        LL n;
        cin>>n;
        LL ans = 0;
        while(n>=0 and n%5) 
        {
            if(is_even(n--))
                ans ++;
        }
    }
    return 0;
}


