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

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);


LL sqr(LL m){
    LL ret=sqrt(m);
    if(ret*ret==m)return ret;
    ret++;
    if(ret*ret==m)return ret;
    ret-=2;
    if(ret*ret==m)return ret;
    return -1;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    int t;
    sd(t);

    while(t--){
        LL m;
        sl(m);
        set< pair< LL, LL > > ans;
        ans.insert({m, 1});
        ans.insert({m, m-1});

        LL sq=sqr(1+8*m);
        if(sq!=-1){
            if((sq+1)%2==0){
                LL my=(sq+1)/2;
                if(my>=2){
                    ans.insert({my, 2});
                    ans.insert({my, my-2});
                }
            }
        }

        for(LL n = 2; n<=200000; n++)
        {
            LL cr = (n * (n-1)) / 2;
            for(LL r = 3; r<=n/2; r++)
            {
                cr *= (n-r+1); cr/=r;
                if(cr>=m){
                    if(cr==m){
                        ans.insert({n, r});
                        ans.insert({n, n-r});
                    }
                    break;
                }
            }
        }

        printf("%d\n",(int)ans.size());
        for(auto &i: ans)
            printf("(%lld,%lld) ",i.F,i.S);
        printf("\n");
    }
    return 0;
}


