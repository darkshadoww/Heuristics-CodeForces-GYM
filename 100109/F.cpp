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

FILE *fin = freopen("input.txt","r",stdin);
FILE *fout = freopen("output.txt","w",stdout);

const int N = 4000;
map<int,vector<int>> M;
VPII x; 
bool cmp(PII a, PII b)
{
   return a.S > b.S;
}
int main()
{
   int n,k;
   cin>>n>>k;
   for(int i=0; i<n; i++)
   {
      int w,c;
      si(w); si(c);
      M[w].PB(c);
   }
   if(M.size() < k)
   {
      cout<<0<<" "<<0<<endl; return 0;
   }
   for(auto &c : M) x.PB(MP(c.F , c.S.size()));
   sort(x.begin(), x.end(), cmp);
   int ns = x[k-1].S;
   vector<int> SS;
   for(auto &c : M)
      if(c.S.size() >= ns)
      {
         sort(c.S.begin(), c.S.end());
         int xx = 0;
         for(int i = 1; i<=ns; i++)
            xx += c.S[c.S.size() - i];
         SS.PB(xx);
      }
   sort(SS.begin(), SS.end());
   int ans = 0;
   for(int i = 1; i<=k; i++)
      ans += SS[SS.size()-i];
   cout<<ns<<" "<<ans<<endl;
   return 0;	
}
