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


int main()
{
    map<int, vector<int> > m, mm;
    int n,tot=0;
    si(n);
    for(int i=0; i<n; i++){
        int v, c;
        si(v), si(c);
        if(c==2)tot++;
        if(not m.count(v))
            m[v].resize(3);

        m[v][c]++;
    }
    m[0].resize(3);

    vector<int> ar(3,0);
    for(auto &i: m){
        for(int j=0; j<3; j++)
            ar[j] += i.S[j];
        mm[i.F]=ar;
    }

    int maxvalue = INT_MIN, ansi, ansj, maxi=INT_MIN, ansmy;
    for(auto &i: mm){
        int q = i.S[0]-i.S[1];
        if(q > maxi)
            maxi = q, ansj=i.F;

        int p = tot + maxi + i.S[1]-i.S[2];
        if(p > maxvalue){
            maxvalue = p, ansi=i.F, ansmy=ansj;
        }
    }
    cout << ansmy << " " << ansi << endl;
    return 0;
}

