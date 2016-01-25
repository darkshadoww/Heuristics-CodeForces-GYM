#include <bits/stdc++.h>
#include <cstring>
#include <queue>
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

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

int S[10000];
int T[10000];
VI DP[1<<10];
VI QueryOrder[1<<10];
int Q[100000]; // candidate in ith query
int ANS[100000]; // answer for ith query

pair<int,int> X[10000];

int main()
{
    int N; int K; si(N); si(K);
    for(int i =0; i<N; i++)
    {
        si(S[i]);
        int m; si(m); while(m--){ int x; si(x); x--; T[i] |= (1<<x);}
        X[i] = MP(-S[i],i);
    }
    sort(X,X+N);

    int q; si(q); 
    for(int i = 0; i<q; i++)
    {
        int x; si(x); x--; Q[i] = x;
        int k; int mask = 0; si(k); while(k--){int y; si(y); y--; mask |= (1<<y);}
        QueryOrder[mask].PB(i);
    }
    for(int mask  = 0; mask <(1<<K); mask++)
    {
        if(QueryOrder[mask].empty())continue;
        for(int i = 0; i <(1<<K); i++)
            DP[i].clear();
        for(int i = 0; i<N; i++)
        {
            int id  = X[i].S;
            DP[T[id] & mask].PB(S[id]);
        }
        for(auto id : QueryOrder[mask])
        {
            int x = Q[id];
            int l = 0; int h = DP[mask & T[x]].size() - 1;
            while(h>l)
            {
                int m = (l+h)/2;
                if(DP[mask & T[x]][m] > S[x])l = m+1; else h = m;
            }
            ANS[id] = 1 + l;
        }
    }
    for(int i = 0; i<q; i++)
        printf("%d\n",ANS[i]);
    return 0;	
}
