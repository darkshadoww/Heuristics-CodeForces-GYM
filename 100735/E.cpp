
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

LL A[100][100];
LL S[100];
LL S2[100];
LL D[100];
LL DS;
int main()
{
   int N; cin>>N;
   for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
      {
         cin>>A[i][j]; S[i] += A[i][j];
      }
   if(N>1){
      for(int i=0; i<N;i++)
      {
         D[i] = S[0] - S[i];
         A[i][i] = D[i];
         DS += D[i];
      }
      LL dd = (S[0] - DS) / (N-1);
      for(int i=0; i<N; i++)
         A[i][i] += dd;
   }
   for(int i=0; i<N; i++)
   {
      for(int j=0; j<N; j++)
      {
         cout<<A[i][j]<<" "; 
      }
      cout<<endl;
   }
   return 0;	
}
