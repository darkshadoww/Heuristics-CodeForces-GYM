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



void add(string a, string b, string &c)
{
   c = "";
   int cr = 0;
   for(int i=0; i<max(a.length(), b.length()); i++)
   {
      cr = cr + (i < a.length() ? a[i]-'0' : 0) + (i<b.length() ? b[i]-'0' : 0);
      c += (cr%10 + '0'); cr/=10;
   }
   if(cr)
      c += (cr + '0');
}

int main()
{
   string a,b,c;
   cin>>a>>b>>c;
   reverse(a.begin(),a.end());
   reverse(b.begin(),b.end());
   reverse(c.begin(),c.end());
   string aa; add(a,a,aa);
   string ab; add(a,b,ab);
   string ac; add(a,c,ac);
   string bb; add(b,b,bb);
   string bc; add(b,c,bc);
   string cc; add(c,c,cc);
   if(aa==b or aa==c or ab==c or ac==b or bb==a or bb==c or bc==a or cc == a or cc== b)cout<<"YES\n"; else cout<<"NO\n";
	return 0;	
}
