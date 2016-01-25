// karanaggarwal
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
const int P = 300;
int A[P+1][P];
int B[100000];
int main()
{
   int n,m; si(n); si(m);
   for(int i=0; i<n; i++)si(B[i]);

   for(int p = 1; p<=P; p++)
   {
      for(int i = 0,q=0; i<n; i++,q++)
      {
         if(q==p)q=0;
         A[p][q] += B[i];
      }
   }
   while(m--)
   {
      int p,q; 
      si(q);
      si(p); 
      if(q<0 or q>=p)
      {
         printf("0\n"); continue;
      }
      int ans = 0;
      if(p<=P)
         ans = A[p][q];
      else
         for(int i = q; i<n; i+=p)
            ans += B[i];
      printf("%d\n",ans);
   }
   return 0;	
}
