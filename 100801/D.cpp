// heuristics
#ifdef __APPLE__

#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<sstream>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

#else

#include<bits/stdc++.h>

#endif  // __APPLE__

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

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<LL> VLL;
FILE *fin = freopen("distribution.in","r",stdin);
FILE *fout = freopen("distribution.out","w",stdout);

VLL f(LL x)
{
    VLL ret;
    if(x==0)return ret;
    if(x==1)
    {
        ret.PB(1ll); return ret;
    }
    if(x%2==0)
    {
        ret = f(x/2);
        for(auto &c : ret) c*=2;
        return ret;
    }
    LL y = 1;
    while(y<=x)
        y*=3;
    y/=3;
    ret = f(x-y);
    ret.PB(y);
    return ret;
}
int main()
{
    int t; si(t); while(t--)
    {
        LL x; cin>>x;
        VLL tp = f(x);
        cout<<tp.size()<<endl;
        for(auto c : tp) cout<<c<<" "; cout<<endl;
    }
    return 0;	
}
