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

bool check(double num, int nm, int dm, int K)
{
    int A = num*K;
    int B = (((double)nm)/((double)dm))*K;
    if(A==B)
    {
        cout<<nm<<" "<<dm<<endl;
        return true;
    }
    return false;
}

int main()
{
    string S;
    cin>>S;
    int K = S.size()-2;
    int fact = 1;
    for(int i=0; i<K; i++) fact*=10;
    istringstream is(S);
    double num;
    is>>num;
    for(int i=1; i<100000001; i++)
    {
        int nm = num*i;
        if(check(num,nm,i,fact)) break;
        if(check(num,nm+1,i,fact)) break;
        if(check(num,nm-1,i,fact)) break;
        if(check(num,nm+2,i,fact)) break;
    }
    return 0;
}

