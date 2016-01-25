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
    ret=(ret*b);b=(b*b);n>>=1;}
return (LL)ret;}

FILE *fin = freopen("great.in","r",stdin);
FILE *fout = freopen("great.out","w",stdout);

LL rec(int ind, VI& ar, int k){
    int n=ar.size();
    if(ind==n-1)return ar[ind]+1;
    if((n-ind-1)%2){
        if(ar[ind]==0)
            return rec(ind+1, ar, k);
        else{
            int cnt=0;
            for(int j=ind+1; j<n; j++)
                cnt += ((n-j-1)%2==0);
            return mpow(k, cnt);
        }
    }
    LL ret=0;
    for(int i=0; i<ar[ind]; i++){
        int cnt=0;
        for(int j=ind+1; j<n; j++)
            cnt += ((n-j-1)%2==0);
        ret += mpow(k, cnt);
    }
    ret += rec(ind+1, ar, k);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    LL n,k,ans=0;
    cin >> n >> k;
    VI ar;
    while(n){
        ar.pb(n%k);
        n/=k;
    }

    reverse(all(ar));

    ans += rec(0, ar, k);
    cout << ans << endl;
    return 0;
}


