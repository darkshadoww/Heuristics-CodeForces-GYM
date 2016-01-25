#include<bits/stdc++.h>
using namespace std;

//#define TRACE
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

FILE *fin = freopen("homo.in","r",stdin);
FILE *fout = freopen("homo.out","w",stdout);


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;


int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    map<int, int> m;
    int cnt=0;
    while(n--){
        string s; int val;
        cin >> s >> val;
        if(s=="insert")m[val]++, cnt++;
        else{
            if(m.count(val)){
            m[val]--;
            if(m[val]==0)
                m.erase(val);
            cnt--;
            }
        }
        int fl=0;
        if(m.size()<cnt)
            fl++;
        if(m.size()>1)fl+=2;
        if(fl==0)cout << "neither\n";
        else if(fl==1)cout << "homo\n";
        else if(fl==2)cout << "hetero\n";
        else cout << "both\n";
    }
    return 0;
}

