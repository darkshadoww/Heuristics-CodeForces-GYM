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


int main()
{
    int N,M,K;
    scanf("%d %d %d", &N, &K, &M);
    vector <int> x;
    for(int i=0; i<N; i++)
    {
        int tmp=0,flag=1;
        for(int j=0; j<M; j++)
        {
            int t;
            scanf("%d",&t);
            if(t<=2)
            {
                flag=0;
            }
            tmp+=t;
        }
        if(flag!=0)
        {
            x.PB(tmp);
        }
    }
    if(x.size()<=K)
    {
        cout<<0<<endl;
        return 0;
    }
    sort(x.rbegin(), x.rend());
    if(x[K-1] == x[K])
        cout<<x[K]<<endl;
    else
        cout<<0<<endl;
    return 0;
}

