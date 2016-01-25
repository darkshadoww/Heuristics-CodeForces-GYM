// karanaggarwal
//#include <bits/stdc++.h>
#include <cstring>
#include <queue>
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
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

int struct node
{
   int cnt[10][3][2];
   int sum[10];
   node() { for(int k = 0; k<10; k++){sum[k] = 0; for(int i =0; i<3; i++)for(int j = 0; j<2; j++)cnt[k][i][j]=  0;}
};

node T[1<<18];
int A[1<<17];


void merge(node &T, node &L, node &R)
{
   for(int k = 0; k<10; k++)
   {
      for(int j = 0; j<2; j++)
      {
         T.cnt[k][0][j] = L.cnt[k][0][j]; 
         T.cnt[k][0][j] = R.cnt[k][0][ L.sum[k] ^ j];
         T.cnt[k][2][j] = R.cnt[k][2][j];
         T.cnt[k][2][j] = L.cnt[k][2][ L.sum[k] ^ j];
      }
      T.cnt[k][1][0] = L.cnt[k][1][0] + R.cnt[k][1][0];
      T.cnt[k][1][1] = L.cnt[k][1][1] + R.cnt[k][1][1];
      T.cnt[k][1][0] = 
         L.cnt[k][2][0] * R.cnt[k][0][0] +
         L.cnt[k][2][1] * R.cnt[k][0][1]; 
      T.cnt[k][1][1] = 
         L.cnt[k][2][0] * R.cnt[k][0][1] + 
         L.cnt[k][2][1] * R.cnt[k][0][0]; 
      T.cnt[k][1][ T.sum[k]]--;
   }
}

void update(int id)
{
   int l = 2*id; int r = l+1;
   for(int k = 0; k<10; k++)
   {
      for(int j = 0; j<2; j++)
      {
         T[id].cnt[k][0][j] = T[l].cnt[k][0][j]; 
         T[id].cnt[k][0][j] = T[r].cnt[k][0][ T[l].sum[k] ^ j];
         T[id].cnt[k][2][j] = T[r].cnt[k][2][j];
         T[id].cnt[k][2][j] = T[l].cnt[k][2][ T[l].sum[k] ^ j];
      }
      T[id].cnt[k][1][0] = T[l].cnt[k][1][0] + T[r].cnt[k][1][0];
      T[id].cnt[k][1][1] = T[l].cnt[k][1][1] + T[r].cnt[k][1][1];
      T[id].cnt[k][1][0] = 
         T[l].cnt[k][2][0] * T[r].cnt[k][0][0] +
         T[l].cnt[k][2][1] * T[r].cnt[k][0][1]; 
      T[id].cnt[k][1][1] = 
         T[l].cnt[k][2][0] * T[r].cnt[k][0][1] + 
         T[l].cnt[k][2][1] * T[r].cnt[k][0][0]; 
      T[id].cnt[k][1][ T[id].sum[k]]--;
   }
}

void update_base(int id, int y)
{

   for(int k = 0; k<10; k++)
   {
      int x = y&1;
      T[id].sum[k] = x; y/=2;
      for(int j = 0; j<3; j++)
      {
         T[id].cnt[k][j][x] = 1;
         T[id].cnt[k][j][1 - x] = 0;
      }
   }
}

int ql,qr;
node query(int id, int l, int r)
{
   node ret;
   if(ql>r or qr<l)return ret;
   if(l>=ql and r<=qr)return T[id];
   int m = (l+r)/2;
   merge(ret , query(2*id,l,m) , query(2*id+1,m+1,r));
   return ret;
}
int main()
{
   int n,q; si(n); si(q);
   for(int i = 0;i<n; i++)
      si(A[i]);
   int base = 1;
   while(base<n)base*=2;
   for(int i = base; i<2*base; i++)
   {  
      if(i<base + n)
         for(int j = 0; j<10; j++)
            update_base(T[j] + i, (A[i-base] >> j) & 1);
   }
   for(int i = base-1; i>0; i--)
      for(int j = 0; j<10; j++)
         update(T[j], i);

   while(q--)
   {
      int p,x; 
      int ch;
      si(ch);
      if(ch==1)
      {
         int id, val;
         si(id); si(val);
         id--;
         A[id]=val;
         for(int j = 0; j<10; j++)
            update_base(T[j]+base+id, (val>>j) & 1);
         id+=base;id/=2;
         while(id>0)
         {
            for(int j = 0; j<10; j++)
               update(T[j],id);
            id/=2;
         }
      }
      else
      {
         si(ql); si(qr); ql--; qr--;
         node ret = query(1,0,base-1);
      }
   }
   return 0;	
}
