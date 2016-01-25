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

void f(int l, int r, queue<int> &ret)
{
   queue<int> L,R;
   if(l==r)
   {
      ret.push(l); return;
   }
   int m = (l+r)/2;
   f(l,m,L); f(m+1,r,R);
   while(!L.empty() and !R.empty())
   {
      int x = L.front(); int y = R.front();
      cout<<"1 "<<x<<" "<<y<<endl; cout.flush();
      string ch; cin>>ch; 
      if(ch=="YES") 
      {
         ret.push(x); L.pop();
      }
      else
      {
         ret.push(y); R.pop();
      }
   }
   while(!L.empty()){int x = L.front(); L.pop(); ret.push(x);}
   while(!R.empty()){int x = R.front(); R.pop(); ret.push(x);}
}

int main()
{
   int N; si(N);
   queue<int> Q;
   f(1,N,Q);
   cout<<0;
   while(!Q.empty()){ int x = Q.front(); Q.pop(); cout<<" "<<x;} cout<<endl; cout.flush();
	return 0;	
}
