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
FILE *fin = freopen("triatrip.in","r",stdin);
FILE *fout = freopen("triatrip.out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

    bitset<1500> G[1500];
    bitset<1500> rG[1500];

int main()
{
    int N; si(N);
    for(int i =0; i<N; i++)
    {
        string s; cin>>s; for(int j=0; j<N; j++) if(s[j]=='+'){ G[i].set(j); rG[j].set(i);}
    }
    LL ans = 0;
    for(int i =0; i<N; i++)
        for(int j = 0; j<N; j++)
            if(G[i][j])
                ans += (rG[i] & G[j]).count();
    cout<<ans/3<<endl;
    return 0;
}

