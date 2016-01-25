
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



int A[15];
int N;
VI valid[1<<15];
bool DP[1<<15];



int main()
{
   cin>>N;
   for(int i=0; i<N; i++)
      cin>>A[i];
   sort(A,A+N);
   for(int i=0; i<N; i++)
      for(int j = i+1; j<N; j++)
         for(int k=j+1; k<N and A[k] < A[i]+A[j]; k++)
            valid[1<<i].PB((1<<i)+(1<<j)+(1<<k));
   int ans = 0;
   DP[0] = true;
   for(int mask = 1; mask < (1<<N); mask++)
   {
      int k = __builtin_popcount(mask);
      if(k%3)continue;
      int d = mask & (-mask);
      for(auto c : valid[d])
         if( (c & mask) == c)
            DP[mask] |= DP[mask - c];
      if(DP[mask])ans = max(ans,k/3);
   }
   cout<<ans<<endl;
   return 0;	
}
