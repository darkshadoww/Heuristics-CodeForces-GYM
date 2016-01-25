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

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

const int b = 500;
bitset<1000> A[b][1000];
bitset<1000> NL;

int D[3];
void process(int t)
{
    int B[3];
    for(int i =0; i<3; i++) B[i] = D[i] % 1000; sort(B,B+3);
    if(t-b <= B[0] and B[0] < t)
        A[B[0] - t + b][B[1]].set(B[2]);
}
int main()
{
    int N,a,bb,d0;
    cin>>N>>a>>bb>>d0;
    int t = 0;
    int ans = 0;
    while(1)
    {
        t+=b;
        D[0] = d0; 
        D[1] =a * D[0] + bb; if(D[1]<0) D[1] += (1ll<<31);
        int pv = 1;
        int cr = 2;
        for(int i = 0; i<N; i++)
        {
            D[cr] =a * D[pv] + bb; if(D[cr]<0) D[cr] += (1ll<<31);
            pv++; cr++; if(pv==3)pv = 0; if(cr==3)cr = 0;
            process(t);
        }
        for(int i =0; i<b; i++)
            for(int j = i; j<1000; j++)
            {
                ans += A[i][j].count();
                A[i][j] = NL;
            }
        if(t>=1000)break;
    }
    cout<<ans<<endl;
    return 0;
}

