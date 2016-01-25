// karanaggarwal
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <map>
#include <set>

using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
   cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
   const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

const int mod = 99990001;
const int N  = 200000;
int IN[N],OUT[N],D[N], mT[N];
set<int> E[N];
VI fE[N];

struct edge{int u; int v; int w;};
edge Ed[N-1];


class node
{
   public:
      int l,r;
      node *left,*right;
      int sum;
      node(int _l,int _r) : l(_l), r(_r), left(NULL), right(NULL), sum(0) {}
};

int val_node(node* x)
{
   if(x)return x->sum;
   return 0;
}
void update_node(node *x)
{
   x->sum = val_node(x->left) +  val_node(x->right);
}

void insert_node(node* tmp, int x)
{
   if(tmp->l == tmp->r)
   {
      tmp->sum = 1;
      return;
   }
   int l = tmp->l; int r = tmp->r;
   int m = (l+r)/2;
   if(x<=m)
   {
      if(tmp->left==NULL)
         tmp->left = new node(l,m);
      insert_node(tmp->left,x);
   }
   else
   {
      if(tmp->right==NULL)tmp->right = new node(m+1,r);
      insert_node(tmp->right,x);
   }
   update_node(tmp);
}

int query_range(node* tmp, int ql, int qr)
{
   if(tmp==NULL)return 0;
   if(tmp->l > qr or tmp->r < ql)return 0;
   if(tmp->l >= ql and tmp->r<=qr)return tmp->sum;
   return query_range(tmp->left,ql,qr) + query_range(tmp->right,ql,qr);
}

node* delete_node(node* tmp, int ql, int qr)
{
   if(tmp==NULL)return tmp;
   if(tmp->l > qr or tmp->r < ql)return tmp;
   if(tmp->l >= ql and tmp->r<=qr){
      free(tmp);return NULL;
   }
   tmp->left = delete_node(tmp->left, ql, qr);
   tmp->right = delete_node(tmp->right, ql, qr);
   update_node(tmp);
   if(tmp->sum==0)
   {
      free(tmp);
      return NULL;
   }
   return tmp;
}

class tree
{
   public:
      tree(int root_nod) :n(0), a(1), b(0), root_node(root_nod) { root = new node(IN[root_node],OUT[root_node]); }
      node* root;
      int root_node;
      int n,a,b;
      set<int> nodes;
      void insert(int x)
      {
         nodes.insert(x);
         n++;
         insert_node(root,IN[x]);
      }
      void remove(int x)
      {
         n--; 
         nodes.erase(x);
         delete_node(root,IN[x],IN[x]);
      }
};

int tm_;

void dfs(int x, int p)
{
   mT[x] = 0;
   tm_++;
   IN[x] =tm_;
   for(auto c : fE[x])
      if(c!=p)
      {
         E[x].insert(c);
         D[c] = 1 + D[x];
         dfs(c,x);
      }
   OUT[x] = tm_;
}

vector<tree> TT;

void remove_dfs(int x, int t1, int t2)
{
   TT[t2].insert(x);
   mT[x] = t2;
   TT[t1].remove(x);
   for(auto c: E[x])
      remove_dfs(c,t1,t2);
}
/*
FILE *fin = freopen("input.txt","r",stdin);
FILE *fout = freopen("output.txt","w",stdout);
*/
int main()
{
   int n;
   si(n);
   for(int i=0; i<n-1; i++)
   {
      int u,v; si(u); si(v); u--; v--; 
      Ed[i].u = u;
      Ed[i].v = v;
      si(Ed[i].w);
      fE[u].PB(v); fE[v].PB(u);
   }
   D[0] = 0; tm_ = 0;
   dfs(0,0);
   TT.emplace_back(0);
   for(int i=0; i<n; i++)
      TT[0].insert(i);
   for(int i=0; i<n-1; i++)
   {
      int edge_id; si(edge_id); edge_id--;
      int u,v; u = Ed[edge_id].u; v = Ed[edge_id].v; int w = Ed[edge_id].w;
      int idx = mT[u]; 
      //assert(idx == mT[v]);
      int tp = ((LL)TT[idx].a * w + (LL)TT[idx].b) % mod;
      printf("%d\n",tp);
      fflush(stdout);
     // trace(i,idx,w,tp);
      if(D[u]>D[v])swap(u,v);
      E[u].erase(v);
      int sub_tree = query_range(TT[idx].root, IN[v], OUT[v]);
      int rem_tree = TT[idx].n  - sub_tree;
      int root = v;
      if(rem_tree < sub_tree)
      {
         root = TT[idx].root_node;
         TT[idx].root_node = v;
      }
      TT.emplace_back(root);
      TT[TT.size()-1].a = TT[idx].a;
      TT[TT.size()-1].b = TT[idx].b;
      remove_dfs(root, idx, TT.size() - 1);
      int i1 = idx; int i2 = TT.size() - 1;
  //    for(auto &c : TT)
    //     trace(c.root_node, c.n, c.a, c.b);
      if(TT[i1].n > TT[i2].n or (TT[i1].n == TT[i2].n and *(TT[i2].nodes.begin()) < *(TT[i1].nodes.begin()) )) swap(i2,i1);
//      trace(i,i1,i2);
      swap(i1,i2);
      TT[i2].b = (TT[i2].b * (LL)tp) % mod;
      TT[i2].a = (TT[i2].a * (LL)tp) % mod;
      TT[i1].b = (TT[i1].b + (LL)tp) % mod;
   }
   return 0;	
}
