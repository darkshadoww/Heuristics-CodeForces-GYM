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

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

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

int freq[109][266];
int tot[109][266];

pair<string, string> names[109];

int main()
{
    int k;
    sd(k);
    for(int i=0; i<k; i++){
        string a,b;
        cin >> a >> b;
        names[i]={a,b};
        for(auto j: a)
            freq[i][j]++;
        for(auto j: b)
            freq[i][j]++;
    }
    for(int i=0; i<k; i++){
        int x,y;
        sd(x),sd(y);
        for(int j=0; j<x; j++){
            string s;
            cin >> s;
            for(auto kk: s)
                tot[i][kk]++;
        }
    }
    int maxtillnow=0,ind=0;
    for(int i=0; i<k; i++){
        int minavail=INT_MAX;
        for(int j=0; j<266; j++)
            if(freq[i][j])
                minavail=min(minavail,tot[i][j]/freq[i][j]);
        if(minavail>maxtillnow)
            maxtillnow=minavail,ind=i;
    }
    cout << names[ind].F << " " << names[ind].S << endl;
    return 0;
}


