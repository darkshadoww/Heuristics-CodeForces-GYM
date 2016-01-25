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

bool V[500][500];
int n,m;
string A[500];
int D[500][500];

bool val(PII a)
{
    if(a.F<0 or a.S<0 or a.F>=n or a.S>=m)return false;
    if(V[a.F][a.S] or A[a.F][a.S]=='#')return false;
    V[a.F][a.S] = true;
    return true;
}
int main()
{
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
    si(m); si(n);
    LL a,b; cin>>a>>b;
    for(int i = 0; i<n; i++)cin>>A[i];
    queue<PII> Q;
    D[0][0] = 0;
    V[0][0] = true;    
    Q.push(MP(0,0));
    while(!Q.empty())
    {
        PII cr = Q.front(); Q.pop();
        for(int i = 0; i<4; i++)
        {
            PII nw = cr;
            nw.F += dx[i]; nw.S += dy[i];
            if(val(nw))
            {
                D[nw.F][nw.S] = 1 + D[cr.F][cr.S];
                Q.push(nw);
            }
        }
    }
    if(V[n-1][m-1]==false)
    {
        cout<<"IMPOSSIBLE\n"; return 0;
    }
    int l = D[n-1][m-1] / 2;
    int r  = D[n-1][m-1] - l;
    cout<<a*l + b*r<<endl;
    return 0;	
}
