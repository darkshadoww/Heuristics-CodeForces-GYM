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


VI A;
map<int,int> C;
int main()
{
    int N,K;
    cin>>N>>K;
    A.resize(N);
    for(int i = 0; i<N; i++){
        si(A[i]); C[A[i]]++;
    }
    sort(A.begin(),A.end()); 
    A.erase(unique(A.begin(),A.end()),A.end());
    int n = A.size();
    int there = 0;
    int tm = 0;
    int rem = 0;
    int i = 0;
    while(there<N)
    {
        int added = 0;
        if(A[i]==tm)
            added = C[A[i++]];
        tm++;
        rem-=there;
        if(added)
            rem = max( rem,K - (there+1));
        if(rem<0)rem =0;
        there += added;
    }
    while(rem>0)
    {
        tm++; rem-=N;
    }
    cout<<tm<<endl;
    return 0;
}

