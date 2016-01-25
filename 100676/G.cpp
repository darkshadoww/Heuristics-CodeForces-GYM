// karanaggarwal
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

int DP[1<<18];
PII E[1000];
int ind[18];
int W[18];
char Name[18][1000];


int N,M; 
int dp(int mask)
{
  if(DP[mask]!=-1)return DP[mask];
  int &ret = DP[mask];
  ret = 0;
  int k = (N+1) - __builtin_popcount(mask);
  for(int i = 0; i<N; i++)
  {
    if(  (mask & (1<<i) ) and  !(mask & (ind[i])) )
    {
        ret = max(ret, dp(mask - (1<<i))  +   k*W[i]);
    }
  }
  return ret;
}


int main()
{
  int t; si(t); while(t--)
  {
    si(N); si(M);
    for(int i = 0; i < (1<<N); i++)
      DP[i] = -1;
    for(int i=0; i<N; i++) 
      ind[i] = 0;

    map<string,int> mm;
    for(int i=0; i<N; i++)
    {
      char XX[500];
      scanf(" %[^0-9]", XX);
      si(W[i]);
      mm[XX] = i;
    }
    for(int i=0; i<M; i++)
    { 
      int x,y;
      char XX[50];
      scanf(" %[^-]",XX);
      x=mm[XX];
      scanf("-->");
      scanf(" %[^\n]",XX);
      string tmp(XX);
      tmp=tmp+" ";
      y=mm[tmp];
      E[i] = MP(x,y);
    }
    for(int i=0; i<M; i++)
    {
      int u = E[i].F;
      int v = E[i].S;
      ind[v] |= (1<<u);
    }
    cout << dp( (1<<N)   - 1)<<endl;
  }
  return 0;	
}
