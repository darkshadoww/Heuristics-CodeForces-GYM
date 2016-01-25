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

int A[300000];

typedef pair<int,int> PII;
typedef vector<PII> VPII;
VPII TP;

int main()
{
    int N; si(N);
    for(int i =0; i<N; i++){
        si(A[i]);A[i]--;}
    int s = 0;
    while(s<N)
    {
        int r = s;
        while(A[r]>= r-s)r++; r--;
        int mn = N-1;
        mn = min(mn, s + A[s]);
        int l = s;
        while(mn>l)
        {
            mn = min(mn,l+A[l]);
            l++;
        }
        if(r>=mn)
        {
            TP.PB(MP(s,r));
            s = r+1;
        }
        else
        {
            TP.PB(MP(mn,s)); s = mn+1;
        }
    }
    cout<<TP.size()<<endl;
    for(auto c : TP) cout<<c.F+1<<" "<<c.S+1<<endl;
    return 0;
}


