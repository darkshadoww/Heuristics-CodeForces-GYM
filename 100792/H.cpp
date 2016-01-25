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
const int M = 150;
LL DP[2][M];
int N;
int A[100000];
int g(char c)
{
    if(c>='0' and c<='9')return c-'0';
    return 10 + (c - 'A');
}
int f()
{
    string ch; cin>>ch;
    return 16*(g(ch[0]))  + g(ch[1]);
}

int main()
{
    si(N);
    for(int i =0; i<N; i++)
        A[i] = f();
    int x = 0; 
    int y = 1;
    LL ans = 0;
    for(int i =0; i<N; i++)
        ans += (i)^A[i];
    DP[0][0] = 0;
    for(int i = 1; i<=N; i++)
    {
        x = 1-x; y = 1-y;
        for(int j = 0; j<M and j<=i; j++)
        {
            if(j==i)DP[x][j] = 0;
            else
            {
                DP[x][j] = max( (j ? DP[y][j-1] : 0),  DP[y][j] + ((i-j-1)^(A[i-1])));
                ans = max(ans,DP[x][j]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;	
}
