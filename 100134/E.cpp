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

//#define TRACE
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

//FILE *fin = freopen("exact.in","r",stdin);
//FILE *fout = freopen("exact.out","w",stdout);

int main()
{
    ios_base::sync_with_stdio(false);
    string x;
    int n;
    cin>>x>>n;
    reverse(x.begin(),x.end());
    vector<LL> vach;
    for(auto c:x)
    {
        vach.PB(c-'0');
    }
    vector<pair<pair<int, LL>,int> > v;
    for(int i=0; i<n; i++)
    {
        int k; LL q;
        cin>>k>>q;
        v.PB(MP(MP(k,-1*q),i+1));
    }
    sort(v.begin(), v.end());
    vector<int> ans;;
    LL rem=0;
    int k=0;
    for(int i=0; i<vach.size(); i++)
    {
        trace(vach[i]);
        rem/=10;
        if(vach[i]!=0 && rem!=0)
        {
            LL torem = min(vach[i],rem);
            vach[i]-=torem;
            rem-=torem;
        }
        if(vach[i]!=0)
        {
            LL som=0;
            trace(k);
            trace(v[k].F.F, v[k].F.S, v[k].S);
            for(int k=0; k<v.size(); k++)
            {
                if(v[k].F.F==i and v[k].F.S)
                {
                    trace(v[k].F.F, v[k].F.S, v[k].S);
                    ans.PB(v[k].S);
                    LL torem = min(vach[i],-1*v[k].F.S);
                    vach[i]-=torem;
                    som=(-1*v[k].F.S)-torem;
                    v[k].F.S=0;
                    if(vach[i]==0)
                    {
                        break;
                    }
                }
            }
            rem=som;
        }
            for(int k=0; k<v.size(); k++)
            {
                if(v[k].F.F==i)
                {
                    v[k].F.F++;
                    v[k].F.S/=10;
                }
            }
            sort(v.begin(), v.end());
        trace(vach[i]);
    }
    for(int i=0; i<vach.size(); i++)
        if(vach[i]!=0)
        {
            trace(i,vach[i]);
            cout<<"-1"<<endl;
            return 0;
        }
    cout<<ans.size()<<endl;
    for(auto it:ans)
        cout<<it<<" ";
    return 0;
}


