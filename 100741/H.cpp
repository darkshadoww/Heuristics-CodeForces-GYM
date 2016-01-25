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


LL W,H,R;

double sq(LL x){return x*x;}
const double eps = 1e-6;
int f(double d)
{
   if(d>=2*R)return H/(2*R);
   if(d<R)return 0;
   double x = sqrt(sq(2*R) - d*d);
//   cout<<x<<endl;
   if(x < R) x = R;
   double h = H - (2*R + x); int h2 = (h / (2*x)); while( h2 * (2*x) <= h)h2++;
   return h2;
}

int main()
{
   cin>>W>>H>>R;
   W*=2; H*=2;
   LL nW = W - 2*R;
   long long ans = 0;
   if(W<2*R or H<2*R)ans = 0; else ans = 1;
   if(nW==0)ans=max(ans,H/(2*R));
  // cout<<f(1.8)<<endl;
   
   else if(nW>0)
   {
      for(int d = 1; ; d++)
      {
         int dd = d;
         int cn = f(((double)nW) / dd);
  //       cout<<d<<" "<<cn<<" "<< ((double)nW) / dd<<endl;
         if(cn==0)break;
         ans = max(ans ,  (1 + d) * (LL)cn);
//         cout<<d<<" "<<ans<<endl;
         d = dd; 
      }
   }
   swap(W,H);
   nW = W - 2*R;
   if(nW==0)ans=max(ans,H/(2*R));
   else if(nW>0)
   {
      for(int d = 1; ; d++)
      {
         int dd = d;
         int cn = f(((double)nW) / dd);
         if(cn==0)break;
         ans = max(ans ,  (1 + d) * (LL)cn);
         d = dd; 
      }
   }
   cout<<ans<<endl;
   return 0;	
}
