
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


using namespace std;

const int INF = 2000000000;

struct Edge {
   int from, to, cap, flow, index;
   Edge(int from, int to, int cap, int flow, int index) :
      from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
   int N;
   vector<vector<Edge> > G;
   vector<Edge *> dad;
   vector<int> Q;

   Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

   void AddEdge(int from, int to, int cap) {
      G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
      if (from == to) G[from].back().index++;
      G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
   }

   long long BlockingFlow(int s, int t) {
      fill(dad.begin(), dad.end(), (Edge *) NULL);
      dad[s] = &G[0][0] - 1;

      int head = 0, tail = 0;
      Q[tail++] = s;
      while (head < tail) {
         int x = Q[head++];
         for (int i = 0; i < G[x].size(); i++) {
            Edge &e = G[x][i];
            if (!dad[e.to] && e.cap - e.flow > 0) {
               dad[e.to] = &G[x][i];
               Q[tail++] = e.to;
            }
         }
      }
      if (!dad[t]) return 0;

      long long totflow = 0;
      for (int i = 0; i < G[t].size(); i++) {
         Edge *start = &G[G[t][i].to][G[t][i].index];
         int amt = INF;
         for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
            if (!e) { amt = 0; break; }
            amt = min(amt, e->cap - e->flow);
         }
         if (amt == 0) continue;
         for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
            e->flow += amt;
            G[e->to][e->index].flow -= amt;
         }
         totflow += amt;
      }
      return totflow;
   }

   long long GetMaxFlow(int s, int t) {
      long long totflow = 0;
      while (long long flow = BlockingFlow(s, t))
         totflow += flow;
      return totflow;
   }
};


string A;
int N;
map<char,int> mp;
map<char,int> mp2;
int main()
{
   cin>>A>>N;
   for(int i=0; i<A.length(); i++)
      mp2[A[i]]++;
   int c=N;
   for(auto it : mp2)
      mp[it.F] = ++c;
   Dinic G(N+2+mp.size());
   for(auto c : mp2)
      G.AddEdge( mp[c.F] , N + mp.size() + 1, c.S );
   for(int i=1; i<=N; i++)
   {
      G.AddEdge(0,i,1);
      set<char> st;
      for(int j=0; j<6; j++)
      {
         string ch; cin>>ch; if(mp.count(ch[0])) st.insert(ch[0]); 
      }
      for(auto c : st)
         G.AddEdge(i,mp[c],1);
   }
   if(G.GetMaxFlow(0,1 + N + mp.size()) == A.length())
      cout<<"YES\n"; else cout<<"NO\n";
   return 0;	
}
