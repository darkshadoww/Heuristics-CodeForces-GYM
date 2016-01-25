// karanaggarwal
#include <bits/stdc++.h>
#include <queue>
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

queue<int> A[3];
int C[3];
int N[3];
string S;

int main()
{
   int n;
   cin>>n>>N[0]>>N[1]; N[2] = n - (N[0] + N[1]);
   if(N[2]<0){
      cout<<-1<<endl; return 0;}
   cin>>S;
   for(int i=0; i<n; i++)
   {
      C[S[i]-'0']++;
      A[S[i]-'0'].push(i);
   }
   int ans = 0;
   while(1)
   {
      bool done = false;
      for(int i=0; i<3; i++)
         for(int j = 0; j<3; j++)
            if(C[i]>N[i] and C[j]<N[j])
            {
               C[i]--; C[j]++;
               done = true;
               int x = A[i].front(); A[i].pop();
               S[x] = j + '0';
               ans++;
            }
      if(done==false)break;
   }
   cout<<ans<<endl; cout<<S<<endl;
   return 0;	
}
