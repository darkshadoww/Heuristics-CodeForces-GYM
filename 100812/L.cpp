#ifdef __APPLE__
#include<cassert>
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<sstream>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

#else

#include<bits/stdc++.h>

#endif  // __APPLE__

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


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

LL gcd(LL a, LL b)
{
    if(b)return gcd(b,a%b); 
    return a;
}

LL power(LL a, LL p, LL mod)
{
    LL ret = 1; 
    while(p)
    {
        if(p&1)
            ret = (ret*a) % mod;
        a = (a*a) % mod;
        p/=2;
    }
    return ret;
}

int phi(int n)
{
    int ret = n;
    int i = 2;
    if(n%i==0)
    {
        ret -= ret/i;
        while(n%i==0)n/=i;
    }
    for(i = 3; i*i<=n; i+=2)
    {
    if(n%i==0)
    {
        ret -= ret/i;
        while(n%i==0)n/=i;
    }
    }
    if(n>1)
        ret -= ret/n;
    return ret;
}

int main()
{
    int t=1;
    while(t--){
        LL a,b;
        cin>>a>>b;
        LL n = a; LL m = b;
        LL g = gcd(a,b);
        if(g!=1)
        {
            cout<< a * (b/g) << endl;
            continue;
        }
        LL ans  = b*a;
        if(a==1 or b==1) ans = min(ans,2ll);
        else
        {
            LL t1 = n * power(n,phi(m)-1,m); 
            if(t1>=max(n,m)) ans = min(ans,t1);
            LL t2 = m * power(m,phi(n)-1,n); 
            if(t2>=max(n,m)) ans = min(ans,t2);
        }
        cout<<ans<<endl;
    }
    return 0;	
}
