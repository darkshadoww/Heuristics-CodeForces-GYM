#include<bits/stdc++.h>
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

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define DRT()  int t; cin>>t; while(t--)

FILE *fin = freopen("kitchen.in","r",stdin);
FILE *fout = freopen("kitchen.out","w",stdout);

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

VI set_bits[1<<18];

int W,L; 
int N;

int sq(int x){return x*x;}
double sq(double x){return x*x;}

PII A[18];

double dist2(PII a, PII b)
{
    return sqrt(sq(a.F-b.F) + sq(a.S-b.S));
}


VPII boundary(PII a)
{
    VPII ret; 
    ret.PB({a.F,0});
    ret.PB({a.F,L});
    ret.PB({0,a.S});
    ret.PB({W,a.S});
    return ret;
}

double DP[1<<18][18];

double f(int l1, int l2, int d)
{
    double D = d; D/=(l1+l2);
    return 
        sqrt(sq(l1) + sq(l1*D))
        +
        sqrt(sq(l2) + sq(l2*D));
}

double dist(int i, int j)
{
    VPII bound;
    double ret = 1e10;
    int x1 = A[i].F; int y1 = A[i].S;
    int x2 = A[j].F; int y2 = A[j].S;
    ret = min(ret, f(x1,x2,abs(y1-y2)));
    ret = min(ret, f(W-x1,W-x2,abs(y1-y2)));
    ret = min(ret, f(y1,y2,abs(x1-x2)));
    ret = min(ret, f(L-y1,L-y2,abs(x1-x2)));
    return ret;
}



int main()
{
    cin>>W>>L;
    si(N);
    for(int i =0; i<N; i++) {
        si(A[i].F); si(A[i].S);
    }
    PII src; cin>>src.F>>src.S;
    for(int mask = 1; mask<(1<<N); mask++)
    {
        set_bits[mask] = set_bits[mask/2];
        for(auto &c : set_bits[mask])c++; 
        if(mask%2)set_bits[mask].PB(0);
    }
    for(int mask=1; mask<(1<<N); mask++)
    {
        if(set_bits[mask].size()==1)
        {
            for(auto p : set_bits[mask])
                DP[mask][p] = dist2(A[p],src);
            continue;
        }
        for(auto u : set_bits[mask])
            DP[mask][u] = 1e10;
        for(auto u : set_bits[mask])
            for(auto v : set_bits[mask])
                if(u!=v)
                    DP[mask][u] = min(DP[mask][u],DP[mask - (1<<u)][v]  + dist(u,v));
    }
    double ans = 1e10;
    int tm = (1<<N) - 1;
    for(int i = 0; i<N; i++)
    {
        VPII bound = boundary(A[i]);
        for(auto p : bound)
            ans = min(ans,DP[tm][i] + dist2(A[i],p));
    }
    printf("%.9lf\n",ans);
    return 0;
}

