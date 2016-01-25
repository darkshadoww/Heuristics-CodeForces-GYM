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


int N;
vector<unordered_map<int,int>> mymap;
vector<unordered_set<int>> potential_unique; 
int A[200000];
VI P[200001];

int main()
{
   int t; si(t); 
   while(t--)
   {
      map<int,int> mp;
      si(N);
      for(int i=0; i<N; i++)mymap[i].clear();
      :mymap.clear();
      for(int i=0; i<N; i++)
      {
         P[i+1].clear();
         si(A[i]); 
         f(mp.count(A[i])==0)mp[A[i]] = mp.size();
         A[i] =mp[A[i]];
         P[A[i]].PB(i);
      }
      for(int i=1; i<= mymap.size(); i++)P[i].clear();
      for(int i = 0; i<N; i++)P[A[i]].PB(i);
   }
	return 0;	
}
