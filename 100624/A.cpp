
// karanaggarwal
#include <cstring>
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


int N;
int A[20][20];
int DP[1<<20];

int dp(int mask)
{
   int &ret = DP[mask];
   if(ret!=-1)return ret;
   ret = mask;
   if((mask & (mask-1) ))
   {
      ret = 0;
      for(int i=0; i<N; i++)
         if(mask & (1<<i))
         {
            int c = 0;
            for(int j = 0; j<N; j++)
               if(mask & (1<<j))c+=A[i][j];
            if(c>0)
               ret |= dp(mask - (1<<i));
         }
   }
   return ret;
}

int f(int mask)
{
   int ret = 0;
   while(mask)
   {
      ret++; mask = mask & (mask-1);
   }
   return ret;
}

int main()
{
   int t; si(t); while(t--)
   {
      si(N);
      for(int i=0; i<N; i++) for(int j=0; j<N; j++) si(A[i][j]);
      memset(DP,-1,sizeof(DP));
      int ans = dp((1<<N)-1);

      int k = f(ans);
      for(int i=0; i<N; i++)
         if(ans &  (1<<i) ) cout<<" "<<i+1;
      if(k==0)cout<<k;
      cout<<endl;


   }
   return 0;	
}
