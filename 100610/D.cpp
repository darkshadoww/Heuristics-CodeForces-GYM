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

FILE *fin = freopen("defense.in","r",stdin);
FILE *fout = freopen("defense.out","w",stdout);

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;


int main()
{
    set<int> X,Y;
    int w,h; si(w); si(h);
    int N; si(N); 
    for(int i = 0; i<N;i++){
        int x,y; si(x); si(y); X.insert(x); Y.insert(y);
    }
    X.insert(0); X.insert(w+1);
    Y.insert(0); Y.insert(h+1);

    int W = 1;
    int p = 0;
    for(auto c : X)
    {
        W = max(W, c - p);
        p = c;
    }
    int H = 1;
    p = 0;
    for(auto c : Y)
    {
        H = max(H, c - p);
        p = c;
    }
    W--; H--;
    cout<<W*H<<endl;
    return 0;
}

