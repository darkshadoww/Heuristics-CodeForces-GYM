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

const int M = 10;
const int N = 10000;
LL BIT[M][N+1];
int n,m;

void update(int idx, int mod, LL val)
{
   while(idx<=n)
   {
      BIT[mod][idx] += val;
      idx += (idx & (-idx));
   }
}

LL query(int idx, int mod)
{
   LL ret  = 0;
   while(idx>0)
   {
      ret += BIT[mod][idx];
      idx = idx & (idx-1);
   }
   return ret;
}

LL A[N+1];
int main()
{
   si(n); si(m);
   for(int i=1; i<=n; i++)
   {
      scanf("%lld",&A[i]);
      int mod = A[i] % m;
      update(i,mod,A[i]);
   }
   int q; si(q); while(q--)
   {
      string ch; cin>>ch;
      if(ch[0]=='+' or ch[0]=='-')
      {

         int idx,val;
         scanf("%d%d",&idx,&val);
         if(ch[0]=='-')val = -val;
         if(val + A[idx] >= 0)
         {
            update(idx,A[idx] % m, -A[idx]);
            A[idx] += val;
            update(idx, A[idx] % m, A[idx]);
         }
         printf("%lld\n",A[idx]);
      }
      else
      {
         int l,r,mod; 
         scanf("%d%d%d",&l,&r,&mod); l--;
         printf("%lld\n", query(r,mod) - query(l,mod));
      }
   }
   return 0;	
}
