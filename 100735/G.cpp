
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


int main()
{
   int c0 = 0;
   string A; cin>>A; for(auto c : A) c0 += (c=='0');
   int N = A.length(); N-=c0;
   cout<<min( N , c0)<<endl;
	return 0;	
}
