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
string s;
string ans;
int n;

int dp[5009][27];
PII parent[5009][27];

int rec(int i, int j){
    if(i==0)return (j>=0 and j<n);
    else if(j<0 or j>=n)return 0;
    int &ret=dp[i][j];
    if(ret!=-1)return ret;
    if(s[i-1]=='='){
        parent[i][j]={i-1, j};
        return ret=rec(i-1, j);
    }
    if(s[i-1]=='>'){
        for(int k=j+1; k<n; k++)
            if(rec(i-1, k))
            {
                parent[i][j]={i-1, k};
                return ret=1;
            }
        return ret=0;
    }
    else{
        for(int k=j-1; k>=0; k--)
            if(rec(i-1, k)){
                parent[i][j]={i-1, k};
                return ret=1;
            }
        return ret=0;
    }
}

void back(int i, int j){
    ans += (char)(j+'a');
    if(i==0)
        return;
    back(parent[i][j].F, parent[i][j].S);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cin >> s;
    int m=s.length();
    for(int i=0; i<n; i++)
        if(rec(m, i)){
            back(m, i);
            reverse(all(ans));
            cout << ans << endl;
            return 0;
        }
    printf("-1\n");
    return 0;
}


