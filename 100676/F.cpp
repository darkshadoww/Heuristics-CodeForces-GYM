#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <map>
#include <set>
#include<cstring>
#include<string>

using namespace std;

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD 1000000007

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

int visited[50005];
vector<int> V[50005];
string s;

set<char> sss;

void dfs(int i)
{
   visited[i]=1;
   if(s[i-1]!='?')
      sss.insert(s[i-1]);
   for(auto it=V[i].begin(); it!=V[i].end(); it++)
   {
      if(!visited[*it])
      {
         dfs(*it);
      }
   }
}

int main()
{
   int n,m;
   int T;
   cin>>T;
   while(T--)
   {
      cin>>n>>m;
      for(int i=0;i<n+1;i++)
         V[i].clear();
      memset(visited, 0, sizeof(visited));
      cin>>s;
      for(int i=0;i<m;i++)
      {
         int a,b;
         cin>>a>>b;
         V[a].push_back(b);
         V[b].push_back(a);
      }
      for(int i=0;i<n/2;i++)
      {
         V[i+1].push_back(n-i);
         V[n-i].push_back(i+1);
      }
      long long int ans = 1;
      for(int i=1;i<=n;i++)
      {
         sss.clear();
         if(!visited[i])
         {
            dfs(i);
            if(sss.size()==0)
            {
               ans*=26;
               ans%=MOD;
            }
            else if(sss.size()>=2)
            {
               ans*=0;
            }
         }
      }
      cout<<ans<<endl;
   }
   return 0;	
}
