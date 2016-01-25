#include<bits/stdc++.h>
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define DRT()  int t; cin>>t; while(t--)

FILE *fin = freopen("jealous.in","r",stdin);
FILE *fout = freopen("jealous.out","w",stdout);


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;


LL CA[101][101];
LL CB[101][101];
int p,q;

void f( LL X, LL C[101][101])
{
    C[0][0] = X;
    for(int i = 0; ;i++)
    {
        if(i) C[i][0] = C[i-1][0] / p;
        if(C[i][0]==0)break;
        for(int j = 1; ;j++){
            C[i][j] = C[i][j-1] / q;
            if(C[i][j]==0)break;
        }
    }
    for(int i = 0; i<100; i++)
        for(int j = 0; j<100; j++){
            C[i][j]-=C[i+1][j]; 
            C[i][j]-=C[i][j+1]; 
            C[i][j]+=C[i+1][j+1];
        }
}

int main()
{
    LL a,b;
    cin>>a>>b>>p>>q; a--; 
    f(a,CA); f(b,CB);
    LL ans = 0;
    for(int i = 1; i<=100; i++)
        for(int j = 0; j<i; j++)
            ans += CB[i][j]-CA[i][j];
    cout<<ans<<endl;
    return 0;
}

