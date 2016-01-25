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
bool Occupied[10001][1000];
int main()
{
    int K;
    si(K);
    int N;
    si(N);
    int T;
    si(T);
    for(int i=0; i<T; i++)
    {
        int pl, st, ed;
        si(pl);
        si(st);
        si(ed);
        for(int i=st-1; i<ed-1; i++)
        {
            Occupied[i][pl-1]=true;
        }
    }
        int A[1000];
        for(int i=0; i<K; i++)  A[i]=N-1;
        int f_ed=N-1;
        long long int ans=0;
        for(int i=N-2; i>=0; i--)
        {
            int mx=-1;
            for(int j=0; j<K; j++)
            {
                if(!Occupied[i][j])
                    mx=max(mx,A[j]);
                else
                {
                    A[j]=i;
                }
            }
            if(mx!=-1)
                ans+=(f_ed-mx);
            else  f_ed=i;
        }
    printf("%lld\n", ans);
    return 0;	
}
