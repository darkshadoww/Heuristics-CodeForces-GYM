#include<iostream>
#include<bitset>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<cmath>

#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
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

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

#ifdef ONLINE_JUDGE
//FILE *fin = freopen(stdin,"r",stdin);
//FILE *fout = freopen(stdout,"w",stdout);
#endif


void print(vector<int> & s){
    for(auto &i: s)
        cout << i;
    cout << endl;
    fflush(stdout);
}

int main()
{
    int n;
    cin >> n;
    vector<int> s(n, 0), impl(n, 0);
    while(1){
        fill(all(s), 0);
        for(int i=0; i<n; i++)
            if(rand()%2)
                s[i] = 1;

        print(s);

        int ans;
        cin >> ans;
        if(ans==n)return 0;
        if(ans==n/2)break;
    }

    for(int i=0; i<n-1; i++){
        s[i]=1-s[i];
        s[i+1]=1-s[i+1];

        print(s);

        int ans;
        cin >> ans;
        if(ans==n)return 0;

        if(s[i]==s[i+1] and ans==n/2)
            impl[i]=1;
        else if(s[i]!=s[i+1] and ans==0)
            impl[i]=1;

        s[i]=1-s[i];
        s[i+1]=1-s[i+1];
    }

    fill(all(s), 0);

    for(int i=1; i<n; i++){
        s[i] = s[i-1];
        if(impl[i-1])
            s[i] = 1-s[i];
    }

    print(s);

    int ans;
    cin >> ans;
    if(ans==n)return 0;


    fill(all(s), 0);
    s[0] = 1;
    for(int i=1; i<n; i++){
        s[i] = s[i-1];
        if(impl[i-1])
            s[i] = 1-s[i];
    }

    print(s);

    cin >> ans;
    assert(ans==n);
    return 0;
}


