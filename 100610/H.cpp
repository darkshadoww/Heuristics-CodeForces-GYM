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
FILE *fin = freopen("horrible.in","r",stdin);
FILE *fout = freopen("horrible.out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;


int main()
{
    int N; cin>>N;
    if(N==1)
    {
        cout<<1<<endl;
        cout<<"1 0\n"; return 0;
    }
    int C = (2 * (N-1) * (N-1)) + N + 2;
    cout<<C<<endl;
    printf("%d %d\n",2,-1);
    for(int i = 1; i<N; i++)
    {
        printf("%d %d\n",i,0);
        for(int j = 1; j<=N; j++)
        {
            if(j!=(i+1))printf("%d %d\n",j,-(i+1));
            if(j!=i)printf("%d %d\n",j,i);
        }
    }
    printf("%d %d\n",N,0);
    printf("%d %d\n",1,N);
    return 0;
}

