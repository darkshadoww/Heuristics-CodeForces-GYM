#include<bits/stdc++.h>
#include<unordered_map>
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
#define TRACE
using namespace std;

FILE *fin = freopen("input.txt","r",stdin);
FILE *fout = freopen("output.txt","w",stdout);


#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define traceVI(a) {cerr << #a << " : ";for(int i=0; i<a.size(); i++){cerr << a[i] << " | ";}cout << endl;}

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

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

unordered_map < string, int > init;
map < VI, int > total;

int main()
{
    int n,m,x,cnt=1;
    sd(n);
    for(int i=0; i<n; i++){
        vector<string> y;
        sd(x);
        y.resize(x);
        for(int j=0; j<x; j++){
            cin >> y[j];
            if(init.count(y[j])==0){
                init[y[j]]=cnt;
                cnt++;
            }
        }
        for(int j=1; j<(1<<x); j++){
            VI my;
            for(int k=0; k<x; k++)
                if((j&(1<<k)))
                    my.pb(init[y[k]]);
            sort(my.begin(),my.end());
            total[my]++;
        }
    }
    sd(m);
    for(int i=0; i<m; i++){
        vector<string> y;
        vector<int> my;
        int ans=1;
        sd(x);
        y.resize(x);
        for(int j=0; j<x; j++){
            cin >> y[j];
            my.pb(init[y[j]]);
        }
        sort(my.begin(),my.end());
        if(ans==0)printf("%d\n",ans);
        else printf("%d\n",total[my]);
    }
    return 0;
}
