
// karanaggarwal
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <map>
#include <set>
#include <cstring>

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
#define MAXN 200008
struct node{
   int x,y,cl;
   int l,r;
};
node arr[MAXN];


bool cmp(node a, node b)
{
   return a.y < b.y;
}
set<int> myset[MAXN];
void foo(int ind){
   int color=arr[ind].cl;
   auto it = myset[color].lower_bound(arr[ind].x);
   int xr = INT_MAX; if(it != myset[color].end()) xr = *it;
   int xl = INT_MIN;
   if(xr==arr[ind].x) xl = xr; else
   {
      if(it != myset[color].begin())
      {
         it--; xl = *it;
      }
   }

   myset[color].insert(arr[ind].x);
   arr[ind].l = xl+1; 
   arr[ind].r = xr-1;
}

#define MaxVal (3*MAXN+10)
int tree[MaxVal];

void update(int idx ,int val){
   idx+=2;
   while (idx <= MaxVal){
      tree[idx] += val;
      idx += (idx & -idx);
   }
}
int read(int idx){
   idx+=2;
   int sum = 0;
   while (idx > 0){
      sum += tree[idx];
      idx -= (idx & -idx);
   }
   return sum;
}
int query(int l, int r){
   if(l>r)return 0;
   return read(r)-read(l-1);
}
int main()
{
   int t;
   si(t);
   while(t--){
      int n,k,cl;
      si(n),si(k);
      for(int i=0; i<=k; i++)
         myset[i].clear();
      memset(tree,0,sizeof(tree));
      for(int i=0; i<n; i++){
         si(arr[i].x),si(arr[i].y),si(arr[i].cl);
      }
      sort(arr,arr+n,cmp);
      for(int i=0; i<n; i++){
         foo(i);
      }
      


      set<int> ar;
      for(int i=0; i<n; i++)
      {
         ar.insert(arr[i].x);
         ar.insert(arr[i].r);
         ar.insert(arr[i].l);
      }
      map<int, int> mymap; int c= 0;
      for(auto x : ar) mymap[x] = ++c;
      int ans=0;
      for(int i=0; i<n; i++)
      {
         arr[i].l = mymap[arr[i].l];
         arr[i].r = mymap[arr[i].r];
         arr[i].x = mymap[arr[i].x];
      }
      for(int i=0; i<n; i++)
      {
         int cur=i;
         while(i<n-1 and arr[i].y==arr[i+1].y){
            ans=max(ans,query(arr[i].l,arr[i].r));
            i++;
         }
         ans=max(ans,query(arr[i].l,arr[i].r));
         for(int j=i; j>=cur; j--)
            update(arr[j].x,1);
      }
      cout << ans << endl;
   }
   return 0;	
}
