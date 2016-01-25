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

#define EPS 1e-7

struct P{
    LL x, y;
    P() {}
    P(LL x_, LL y_): x(x_), y(y_) {}
};

struct L{
    LL a,b,c;
    L() {}
    L(LL a_, LL b_, LL c_): a(a_), b(b_), c(c_) {}
};

L getL(P p1, P p2){
    LL a=p2.y-p1.y;
    LL b=p1.x-p2.x;
    LL c=p1.y*(p2.x-p1.x) - p1.x*(p2.y-p1.y);
    return L(a,b,c);
}

LL sameside(P p1, P p2, L l){
    LL v1 = p1.x*l.a + p1.y*l.b + l.c;
    LL v2 = p2.x*l.a + p2.y*l.b + l.c;
    return (v1*v2);
}

int main()
{
    //ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector< P > ar(n);
    P p1, p2;
    LL ans=0;

    for(int i=0; i<n; i++)
        cin >> ar[i].x >> ar[i].y;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;

    int pt1=0,pt2=1,pt3=1;
    while(sameside(p1, p2, getL(ar[pt2], ar[pt1])) > 0 )pt2++;
    while(sameside(p1, p2, getL(ar[pt3], ar[pt1])) > 0 )pt3++;

    for(pt1=1; pt1<n; pt1++){
        ans += pt3-pt2;
        while(sameside(p1, p2, getL(ar[pt2], ar[pt1])) > 0 )pt2++;
        while(sameside(p1, p2, getL(ar[pt3], ar[pt1])) > 0 )pt3++;
    }
    cout << ans << endl;
    return 0;
}


