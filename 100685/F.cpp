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

double C[10000],L[10000];
VI E[10000];
int deg[10000];

int main()
{
   int n,m; si(n); si(m);
   for(int i = 0; i<n; i++)
   {
      cin>>L[i]>>C[i];
   }
   while(m--){int x,y; si(x); si(y); x--; y--; E[x].PB(y); deg[y]++;}
   int x,src,dest; 
   si(src); 
   si(x); 
   si(dest);
   src--; dest--; C[src]+=x;
   VI tord;
   queue<int> Q; for(int i=0; i<n; i++) if(!deg[i])Q.push(i);
   while(!Q.empty()){ int x = Q.front(); Q.pop(); tord.PB(x); for(auto y : E[x]){deg[y]--; if(!deg[y]) Q.push(y);}}
   for(auto x : tord)
   {
      if(C[x]<=L[x])continue;
      double td = C[x]-L[x]; C[x] = L[x];
      if(!E[x].empty())
      {
         td /= (E[x].size());
         for(auto y : E[x])
            C[y]+=td;
      }
   }
   printf("%.7lf\n",C[dest]);
   return 0;	
}
