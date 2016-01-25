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

#ifdef ONLINE_JUDGE
//FILE *fin = freopen(stdin,"r",stdin);
//FILE *fout = freopen(stdout,"w",stdout);
#endif

int base=5;
vector<int> ar;

LL dp1[11][50][2];
LL dp2[50][2];

LL f(int i, int j, int k){
    if(j==1)return 1;
    LL &ret=dp1[i][j][k];
    if(ret!=-1)return ret;
    ret=0;
    for(int l=0; l<base; l++){
        if(j%2==0)
            ret += f(l, j-1, (i+k)%2);
        else
            ret += f(l, j-1, k);
    }
    return ret;
}

LL g(int ind, int cursum){
    if(ind<0)return 1;

    LL &ret=dp2[ind][cursum];
    if(ret!=-1)return ret;
    ret=0;
    if(ind%2)cursum += ar[ind];
    cursum%=2;

    for(int i=0; i<ar[ind]; i++){
        ret += f(i, ind, cursum%2);
    }

    ret += g(ind-1, cursum);
    return ret;
}

bool is_even(LL x)
{
    LL ans = 0;
    while(x)
    {
        x/=5; ans+=x;
    }
    return ans%2==0;
}

int main()
{
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    int ans2 = 0;
    LL n;
    cin >> n;
    while(n){
        ar.pb(n%base);
        n/=base;
    }

    LL ans=g((int)ar.size()-1, 0);
    cout << ans << endl;
    return 0;
}


