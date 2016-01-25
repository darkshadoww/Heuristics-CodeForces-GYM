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

const int MN = 200000;
int N,K;
pair<PII,int> P[MN];
set<int> ss[MN];
int XL[MN], XR[MN];

int BIT[2000005];

bool cmp(pair<PII,int> a, pair<PII,int> b)
{
   return a.F.S <  b.F.S;
}
vector<int> CL[200000];

int NN;


int Q(int x)
{
   int ret  = 0;
   int cp = x;
   while(x>0)
   {
      ret += BIT[x];
      x = x & (x-1);
   }
   cout<<"Query "<<cp<<" "<<ret<<endl;
   return ret;
}

void U(int id)
{
   cout<<"Update "<<id<<endl;
   while(id <= NN)
   {
      BIT[id]++;
      id += (id & (-id));
   }
}

int query(int l, int r)
{
   if(r<=l)return 0;
   return Q(r) - Q(l);
}

int main()
{
   int t; si(t); while(t-- )
   {
      si(N); si(K);
      set<int> xx;
      set<int> clr;
      for(int i=0; i<N; i++)
      {
         si(P[i].F.F);
         si(P[i].F.S);
         si(P[i].S); P[i].S--;
         clr.insert(P[i].S);
         xx.insert(P[i].F.F);
      }
      if(clr.size() != K)
      {
         cout<<N<<endl; continue;
      }
      map<int,int> mm; 
      int c = 0;
      for(auto x : xx)
         mm[x] = ++c;
      int x_mx = mm.size() + 1;
      int x_mn = 0;
      for(int i=0; i<K; i++)CL[i].clear();
      sort(P,P+N,cmp);
      for(int i=0; i<K; i++)
      {
         set<int> ss;
         ss.insert(x_mn); ss.insert(x_mx);}
         for(auto j : CL[i])
         {
            P[j].F.F = mm[P[j].F.F];
            int cl = P[j].S;
            int x = P[j].F.F;
            auto it = ss[cl].lower_bound(x);
            XR[j] = *it; XR[j]--;
            if(XR[j]!=x) it--; 
            XL[j] = *it; 
            ss[cl].insert(x);
         }
   }
}
ss[i].insert(x_mn); ss[i].insert(x_mx);}
NN = x_mx;
int ans = 0;
int j= 0;
for(int i=0; i<N; i++)
{
   while(j<i and P[j].F.F < P[i].F.F)
   {
      U(P[j].F.F); j++;
   }
   ans = max(ans,query(XL[i],XR[i]));
}
for(int i=0; i<=NN; i++)BIT[i] = 0;
cout<<ans<<endl;
}
return 0;	
}
