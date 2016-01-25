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

double A[60][60];
vector<pair<pair<int,int>,int> > v;
map<string, int> m; 

long long int dist(LL x1, LL y1, LL z1, LL x2, LL y2, LL z2)
{
    LL ans = 0;
    ans = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
    return ans;        
}


int main()
{
    ios_base::sync_with_stdio(false);
    int T,t;
    cin>>T;
    t=0;
    while(T--)
    {
        t++;
        cout<<"Case "<<t<<":"<<endl;
        int p;
        cin>>p;
        v.clear();
        m.clear();
        for(int i=0; i<p; i++)
        {
            string s;
            int x,y,z;
            cin>>s>>x>>y>>z;
            m[s]=i;
            v.PB(MP(MP(x,y),z));
        }
        for(int i=0; i<p; i++)
        {
            for(int j=0; j<p; j++)
            {
                A[i][j]=sqrt(dist(v[i].F.F,v[i].F.S,v[i].S,v[j].F.F,v[j].F.S,v[j].S));
                A[j][i]=A[i][j];
            }
        }
        int w;
        cin>>w;
        for(int i=0; i<w; i++)
        {
            string a,b;
            cin>>a>>b;
            A[m[a]][m[b]]=0;
        }
        for(int k=0; k<p; k++)
        {
            for(int i=0; i<p; i++)
            {
                for(int j=0; j<p; j++)
                {
                    A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
                }
            }
        }
        int q;
        cin>>q;
        while(q--)
        {
            string a,b;
            cin>>a>>b;
            cout<<"The distance from "<<a<<" to "<<b<<" is "<<llround((A[m[a]][m[b]]))<<" parsecs."<<endl;
        }
    }
    return 0;
}
