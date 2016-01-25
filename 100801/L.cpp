#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
using namespace std;
FILE *fin = freopen("lucky.in","r",stdin);
FILE *fout = freopen("lucky.out","w",stdout);

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

int dir1[4]={1,0,-1,0};
int dir2[4]={0,1,0,-1};

int main()
{
    int r,c,ar[109][109],ans=0;
    sd(r),sd(c);
    for(int i=1; i<=r; i++)
        for(int j=1; j<=c; j++)
            sd(ar[i][j]);
    for(int i=1; i<=r; i++)
        for(int j=1; j<=c; j++){
            int temp=ans;
            int fl=1;
            for(int k=j+1; k<=c; k++)
                if(ar[i][k]>=ar[i][j]){fl=0;break;}
            ans += fl;
            fl=1;
            for(int k=j-1; k>=1; k--)
                if(ar[i][k]>=ar[i][j]){fl=0;break;}
            ans += fl;
            fl=1;
            for(int k=i-1; k>=1; k--)
                if(ar[k][j]>=ar[i][j]){fl=0;break;}
            ans += fl;
            fl=1;
            for(int k=i+1; k<=r; k++)
                if(ar[k][j]>=ar[i][j]){fl=0;break;}
            ans += fl;
        }
    cout << ans << endl;
    return 0;
}
