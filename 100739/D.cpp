
// karanaggarwal
//#include <bits/stdc++.h>
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

int N,M,mod;
int A[1000][1000];
int B[1000][1000];




int main()
{
   si(N); si(M); si(mod);
   for(int i=0; i<N; i++)
      for(int j = 0; j<M; j++)
         si(A[i][j]);
   int c1 = 0; 
   LL ans1 = mod*((LL)N+M);
   for(int c = 0; c<N; c++)
   {
      long long ans = 0;
      for(int i = 0; i<M; i++)
      {
         int x = A[0][i];
         int y = A[0][c];
         int d = y-x; if(d<0)d+=mod;
         ans +=d;
      }
      for(int i = 0; i<N; i++)
      {
         int x = A[i][c];
         int d = mod - x; if(d==mod)d-=mod;
         ans += d;
      }
      if(ans < ans1){ans1 = ans; c1 = c;}
   }

   int c2 = 0; 
   LL ans2 = mod*((LL)M + N);

   for(int c = 0; c<N; c++)
   {
      LL ans = 0;
      for(int i = 0; i<N; i++)
      {
         int d= A[c][0] - A[i][0]; if(d<0)d+=mod; ans+=d;
      }
      for(int i = 0; i<M; i++)
      {
         int d = mod - A[c][i]; if(d!=mod)ans += d;
      }
      if(ans<ans2){ans2 = ans; c2 = c;}
   }
   if(ans1<=ans2)
   {
      printf("%lld\n",ans1);
      for(int i=0; i<N; i++)
      {
         int x = mod - A[i][c1]; if(x>=mod)x-=mod;
         printf("%d ",x);
      }
      printf("\n");
      for(int i=0; i<M; i++)
      {
         int d = A[0][c1] - A[0][i];
         if(d<0)d+=mod;
         printf("%d ",d);
      }
   }
   else
   {
      printf("%lld\n",ans2);
      for(int i=0; i<N; i++)
      {
         int x = A[c2][0] - A[i][0]; if(x<0)x+=mod;
         printf("%d ",x);
      }
      printf("\n");
      for(int i=0; i<M; i++)
      {
         int d = mod - A[c2][i]; if(d>=mod)d=0;
         printf("%d ",d);
      }
   }
   printf("\n");
   return 0;	
}
