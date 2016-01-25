
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

unordered_map<int,int> M;
int A[17];
int main()
{
   int n,m; cin>>n>>m;
   for(int i=0; i<n; i++)
      cin>>A[i];
   for(int mask = 1; mask < (1<<n); mask++)
   {
      int cs = 0;
      for(int i=0; i<n; i++)
         if(mask & (1<<i))
            cs += A[i];
      M[cs]++;
   }
   n = m;
   LL ans = 0;
   for(int i=0; i<n; i++)
      cin>>A[i];
   for(int mask = 1; mask < (1<<n); mask++)
   {
      int cs = 0;
      for(int i=0; i<n; i++)
         if(mask & (1<<i)) cs += A[i];
      ans += M[cs];
   }
   cout<<ans<<endl;
	return 0;	
}
