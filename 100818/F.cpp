#ifdef __APPLE__
    #include<cassert>
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
#define REP(i,a,b) for(int i = (int)a; i < (int)b; i++)


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;


typedef map<int,LL> poly;

poly derivative(poly P)
{
    poly ret;
    for(auto &t : P)
        if(t.F)
            ret[t.F - 1] += t.F * t.S;
    return ret;
}
bool is_zero(poly &P, int r)
{
    LL cr = 0;
    for(auto ip = P.rbegin(); ip != P.rend(); ip++)
        cr = cr*r + ip->S;
    return cr==0;
}

int main()
{
    int N; si(N); 
    poly P;
    P[N] = 1;
    for(int i = N-1; i>=0; i--)
    {
        int x; si(x);
        P[i] = x;
    }
    int ans = N;
    for(int r = -10; r<=10; r++)
    {
        if(r==0)continue;
        poly CR = P;
        while(ans>0 and is_zero(CR,r))
        {
            ans--; 
            CR = derivative(CR);
        }
    }
    cout<<ans<<endl;
    return 0;	
}
