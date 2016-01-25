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



const int N = 100000;
int n;
unordered_map<string,int> mp;
string mp_name[N];
VI E[N];
bool V[N];

vector<int> TP;


void dfs(int x)
{
   if(V[x])return; 
   V[x] = true;
   int nn = E[x].size();
   for(int i = nn-1; i>=0; i--)
      dfs(E[x][i]);
   TP.PB(x);
}


int main()
{
   cin>>n;
   for(int i=0; i<n; i++)
   {
      string ch,name;
      cin>>ch>>name;
      mp[name] = i;
      while(1)
      {
         cin>>ch>>name;
         if(ch=="with")
            E[i].PB(mp[name]);
         else
         {
            mp_name[i] = name;
            break;
         }
      }
   }
   string name;
   cin>>name;
   int source = mp[name];
   dfs(source);
   int nn = TP.size();
   for(int i = nn-1; i>=0; i--)
      cout<<mp_name[TP[i]]<<" ";
   cout<<endl;
	return 0;	
}
