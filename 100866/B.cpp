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

#ifdef ONLINE_JUDGE
//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

int N;
long double C,dC;
int dT;

int f(int B1, int B2)
{
    if(B1 < 0 or B1>N)return B2;
    long double x = (B1 - B2) * (   log(100) - log(dT)  );
    x += log(C + N*dC - B1 * dC) - log(C + N*dC - B2 * dC);
    if(x>0)return B1;
    return B2;
}


int main()
{
    cin>>C>>N>>dC>>dT; dT = 100 - dT;
    long double B = 0;
    B = (C/dC + N);
    B -= (100) / (dT * (log(100) - log(dT)));
    int ansB = N;
    int cB = B;
    for(int cc = N; cc>=0 and N-cc<10000; cc--)
        ansB = f(cc,ansB);
    for(int d = 100000; d>=-100000; d--)
        ansB = f(cB+d,ansB);
    ansB = f(0,ansB);
    cout<<N - ansB<<" "<<ansB<<endl;
    return 0;
}

