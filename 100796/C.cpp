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
const int MN = 100000;
VI E[MN];
bool isL[MN];
int Mn[100000],Mx[100000];
int A[MN];
int Depth[MN];
int P[MN];
void dfs(int x, int d)
{
    if(E[x].size()>1)d++;
    Depth[x] = d;
    Mn[x] = 1000000000;
    Mx[x] = A[x];
    if(isL[x])Mn[x] = A[x];
    for(auto c : E[x])
    {
        dfs(c,d);
        Mx[x] = max(Mx[x], Mx[c]);
        Mn[x] = min(Mn[x], Mn[c]);
    }
}
int main()
{

    int N,k;
    si(N); si(k);
    for(int i =0; i<N; i++)isL[i] = true;
    P[0] = 0;
    for(int i = 1; i<N; i++)
    {
        int p; si(p); p--; P[i] = p;
        E[p].PB(i);
        isL[p] = false;
    }
    for(int i =0; i<N; i++) si(A[i]);
    dfs(0,0);
    int l = 0;
    for(int i = 0; i<N; i++ )if(isL[i])l++;
    
//    for(int i = 0; i<N; i++)trace(i,isL[i],Mn[i],Mx[i],Depth[i]);
    
    int mn = Mx[0];
    for(int i = 0; i<N; i++)
        if(Depth[i] <= k)
            for(auto c : E[i]) mn = min(mn,Mx[c]);
    k = N-l-k;
        int mx = Mn[0];
    for(int i = 0; i<N; i++)
        if(Depth[i] <= k)
            for(auto c : E[i]) mx = max(mx,Mn[c]);
    cout<<mn<<" "<<mx<<endl;
    return 0;	
}
