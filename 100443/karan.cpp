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

int D[100];
LL DP[40][2];

int main()
{

    DP[0][0] = 1;
    DP[0][1] = 0;
    for(int l = 1; l<40;l++)
    {
        if(l%2)
        {
            DP[l][0] = 5 * DP[l-1][0];
            DP[l][1] = 5 * DP[l-1][1];
        }
        else
        {
            DP[l][0] = 3 * DP[l-1][0]  + 2 * DP[l-1][1];
            DP[l][1] = 3 * DP[l-1][1]  + 2 * DP[l-1][0];
        }
    }
    LL X;
    while(cin>>X)
    {
        if(X==-1)return 0;
        int l =0;
        LL x = X;
        while(x)
        {
            D[l++]  = x%5; x/=5;
        }
        int L = l;
        LL ans = 0;
        int want = 0;
//        trace(L);
 //       for(int i = L-1; i>=0; i--)cout<<D[i]; cout<<endl;
        for(int i = L-1; i>=0; i--)
        {
            if(i%2)
            {
                for(int d = 0; d<D[i]; d++)
                {
                    if(d%2)
                        ans += DP[i][1-want]; 
                    else 
                        ans += DP[i][want];
                }
                if(D[i]%2)want = 1 - want;
            }
            else
                ans += D[i] * DP[i][want];

        }
        if(want==0)ans++;
        cout<<ans<<endl;
    }
    return 0;
}


