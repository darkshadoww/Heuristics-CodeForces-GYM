
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
#define PB push_back
#define MP make_pair


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

int g;
int tm;
VI E[100000];
string A;
LL L[100000];
int S[50000];
void dfs(int x)
{
   S[x] = 1;
   L[x] = g;
   g++;
   while(A[g] != ')')
   {
      int y = ++tm;
      E[x].PB(y);
      dfs(y);
      S[x] += S[y];
   }
   g++;
   L[x] = g - L[x];
}

int main()
{
   tm = 0;
   g=0;
   LL ans = 0;
   cin>>A;
   dfs(0);
   int N = A.size() / 2;
//   for(int i=0; i<N; i++)cout<<S[i]<<endl;
   for(int i=0; i<N; i++)
      for(auto c : E[i])
      {
         ans += (L[i] * S[c])*(S[i]-1 - S[c]);
 //        cout<<ans<<endl;
      }
   ans/=2;
   cout<<ans<<endl;
//   cout<<tm<<" "<<g<<endl;
	return 0;	
}
