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

int C[300000];

int process()
{
    string s; cin>>s;
    int x = 0;
    for(int i =0; i<s.length(); i++){
        if(s[i]=='.')continue; x = x*10 + (s[i]-'0');}
    return x;
}

int main()
{
    int N,M,r;
    cin>>N>>M>>r;
    r*=10;
    r = sqrt(r*r - 100);
    for(int i =0; i<N; i++)
        C[i] = process();
    int st = 0;
    long long dist = 0;
    for(int i =0; i<M; i++)
    {
        int x = process();

        int L = lower_bound(C,C+N,x-r) - C;
        int R = upper_bound(C,C+N,x+r) - C - 1;
        if(st>=L and st<=R) continue;
        if(st<L)
        {
            dist += C[L] - C[st]; st = L;
        }
        else
        {
            dist += C[st] - C[R]; st = R;
        }
    }
    int y = dist%10; dist/=10; cout<<dist<<"."<<y<<endl;
    return 0;
}


