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

FILE *fin = freopen("acm.in","r",stdin);
FILE *fout = freopen("acm.out","w",stdout);

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

int A[10],B[10];

int main()
{
    int N,M; si(N); si(M);
    for(int i =0; i<N; i++)si(A[i]); sort(A,A+N);
    for(int i =0; i<M; i++)si(B[i]); sort(B,B+M);
    string ans="";
    for(int i=0; i<N; i++){
        string cur="(10";
        for(int j=0; j<A[i]; j++)
            cur += "-1";
        cur +=")";
        ans += cur;
        if(i!=N-1)ans += "*";
    }
    cout << ans << "=0\n";
    return 0;
}

