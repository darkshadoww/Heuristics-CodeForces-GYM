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

bool DP[33][33];
string A;
pair<PII,LL> Q[5000];
int main()
{
   int N,R; LL B;
   cin>>N>>R>>B;
   cin>>A;
   for(int l = 1; l<N; l++)
      for(int i  = 0; i+l<N; i++)
         DP[i][i+l] = ((A[i]==A[i+l]) and (l==1 or DP[i+1][i+l-1]));
   
   for(int i =0; i<R; i++)
   {
      si(Q[i].F.F); si(Q[i].F.S); cin>>Q[i].S;
      Q[i].F.F--;
      Q[i].F.S--;
   }
   int l = N-1; if(l%2==0)l--;
   for(; l>0; l-=2)
   {
      for(int i=0; i+l<N; i++)
      {
         if(DP[i][l+i])
         {
            LL cst = 0;
            for(int j=0; j<R; j++)
            {
               if(Q[j].F.F>=i and Q[j].F.S <=i+l)
                  cst += Q[j].S;
            }
            if(cst<=B)
            {
               cout<<l+1<<endl; return 0;
            }
         }
      }
   }
   cout<<0<<endl;
	return 0;	
}
