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

int cal(string s)
{
    int x  = 0;
    for(auto c : s)
        if(c>='0' and c<='9')
            x = x*10 + (c-'0');
    return x;
}
PII  input()
{
    PII a;
    string s; 
    cin>>s; a.F = cal(s); cin>>s;
    cin>>s; a.S = cal(s); cin>>s; return a;
}

int main()
{
    int N,M; 
    cin>>N>>M; N/=200; M/=200;

    PII s = input();
    PII d = input();

    int cs = 0; 
    if(  (s.F % 2)  != (s.S) % 2 )
        cs = 1;

    int CH = abs( s.F - d.F);
    int CV = abs( s.S - d.S);

    // start H.
    int AH = CH; int AV = CV;
    if(CH%2 == CV%2)
    {
        AH = AV = max(CH,CV);
    }
    else{
        if(cs==0)
        {
            AV = max(CV,CH-1);
            AH = AV + 1;
        }
        else
        {
            AH = max(CH,CV-1); AV = AH+1;
        }
    }

    cout<< 200 * (AH  +AV) << endl;

    return 0;
}

