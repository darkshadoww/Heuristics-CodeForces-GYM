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
FILE *fin = freopen("explicit.in","r",stdin);
FILE *fout = freopen("explicit.out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;


int main()
{
    int ar[10],cnt=0;
    for(int i=0; i<10; i++)
        si(ar[i]);
    for(int i=0; i<10; i++)
        for(int j=i+1; j<10; j++)
            if(ar[i]+ar[j]!=0)
                cnt++;
    for(int i=0; i<10; i++)
        for(int j=i+1; j<10; j++)
            for(int k=j+1; k<10; k++)
                if(ar[i]+ar[j] + ar[k]!=0)
                    cnt++;
    if(cnt%2)cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}

