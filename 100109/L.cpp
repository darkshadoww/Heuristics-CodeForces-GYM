// karanaggarwal
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
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

int T[2];
int C[2];

FILE *fin = freopen("input.txt","r",stdin);
FILE *fout = freopen("output.txt","w",stdout);

int main()
{
   int n;
   cin>>n>>T[0]>>T[1];
   while(1)
   {
      if(C[0]*T[0] == C[1]*T[1])
      {
         if(C[0] + C[1] >=n)break;
         C[0]++; C[1]++; 
      }
      else if( C[0]*T[0] < C[1]*T[1])
      {
         if( C[0] + (C[0]*T[0]) / T[1] >=n)break;
         C[0]++;
      }
      else
      {
         if( C[1] + (C[1]*T[1]) / T[0] >=n)break;
         C[1]++;
      }
   }
   cout<<C[0] + C[1]<<" "<<max(C[0]*T[0],C[1]*T[1])<<endl;
   return 0;	
}
