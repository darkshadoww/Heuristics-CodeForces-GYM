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

const int MM = 200000;
const int MN = 100000;
VI E[MN]; int P[MN];
int U[MM],V[MM], W[MM];
bool IsBridge[MM];
int N,M;
int Depth[100000];
bool Visited[100000];
LL Mx[100000][2];

int parent(int x){  if(P[x]!=x) P[x] = parent(P[x]); return P[x];}
bool unite(int x, int y)
{ 
   x = parent(x); y = parent(y); 
   if(x==y)return false;
   if(x>y)swap(x,y);
   P[y] = x;
   return true;
}


int dfs(int x, int p)
{
   Visited[x] = true;
   int ret = Depth[x];
   for(auto c : E[x])
   {
      int u = x; int v = U[c]^V[c]^u;
      int w = W[c];
      if(Visited[v]==false)
      {
         Depth[v] = 1 + Depth[u];
         int rt = dfs(v,u);
         if(rt > Depth[u])
            IsBridge[c] = true;
         else
            ret = min(ret,rt);
      }
      else if(v!=p)
            ret = min(ret, Depth[v]);
   }
   return ret;
}

void dfs2(int x, int p)
{
   Mx[x][0] = Mx[x][1] = 0;
   for(auto c : E[x])
   {
      int u = x; int v = U[c]^V[c]^u;
      int w = W[c];
      if(v != p)
      {
         dfs2(v,u);
         LL d = w + Mx[v][0]; 
         if(d>Mx[u][1])
         {
            Mx[x][1] = d;
            if(d>Mx[u][0])swap(Mx[x][0], Mx[x][1]);
         }
      }
   }
}

pair<long long, int> ANS;

void dfs3(int x, int p, LL back)
{
   LL md = max(Mx[x][0],back);
   ANS = min(ANS, MP(md,x));
   for(auto c : E[x])
   {
      int u = x; int v = U[c]^V[c]^u;
      int d = W[c];
      if(v != p)
      {
         LL mx = Mx[x][0]; if(mx== d + Mx[v][0]) mx = Mx[x][1];
         dfs3(v,u, d + max(mx, back));
      }
   }
}

int main()
{
   int t; si(t); while(t--)
   {
      si(N); si(M);
      for(int i=0; i<N; i++)
      {
         E[i].clear();
         Visited[i] = false;
      }
      for(int i=0; i<M; i++)
      {
         si(U[i]); si(V[i]);
         si(W[i]); U[i]--; V[i]--;
         E[U[i]].PB(i);
         E[V[i]].PB(i);
         IsBridge[i] = false;
      }
      Depth[0] = 0;
      dfs(0,0);
      for(int i=0; i<N; i++)P[i] = i;
      for(int i=0; i<M; i++) if(IsBridge[i]==false)unite(U[i],V[i]);
      for(int i=0; i<N; i++)E[i].clear();
      for(int i=0; i<M; i++) if(IsBridge[i])
      {
         U[i] = parent(U[i]);
         V[i] = parent(V[i]);
         //cout<<U[i]<<" "<<V[i]<<" "<<W[i]<<endl;
         E[U[i]].PB(i);
         E[V[i]].PB(i);
      }
      dfs2(0,0);
      ANS = MP(Mx[0][0],0);
      dfs3(0,0,0);
      cout<<ANS.S + 1<<" "<<ANS.F<<endl;
   }
	return 0;	
}
