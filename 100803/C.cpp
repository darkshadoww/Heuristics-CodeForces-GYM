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

PII A[1000];

int main()
{
    int N,m; cin>>N>>m;
    for(int i = 0; i<m; i++)
        cin>>A[i].F>>A[i].S;

    sort(A,A+m);

    int ans = N+1;
    
    int r = 0;
    int l = 0;
    for(int i = 0; i<m; i++)
    {
        if(A[i].F > r)
        {
            ans += 2*(r-l);
            l = A[i].F; r = A[i].S;
        }
        else
        {
            r = max(r,A[i].S);
        }
    }
    ans += 2*(r-l);
    cout<<ans<<endl;
    return 0;	
}
