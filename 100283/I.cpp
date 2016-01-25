// akshayjaggi

#include<bits/stdc++.h>

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

#ifdef ONLINE_JUDGE
FILE *fin = freopen("zanzibar.in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
#endif

const LL LCM=360360;
bool knap[LCM+1];

LL gcd(LL a, LL b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

set <int> costs;

vector <int> final_vals;

int main()
{
	knap[0]=true;
	for(int i=2; i<=13; i++)
	{
		for(int j=1; j<i; j++)
		{
			costs.insert((LCM/i)*j);
		}
	}
	for(auto it : costs)
	{
		for(int i=it; i<=LCM; i++)
			knap[i]|=knap[i-it];
	}
	for(int i=0; i<=LCM; i++)
	{
		if(knap[i])
			final_vals.PB(i);
	}
	int T;
	si(T);
	for(int t=1; t<=T; t++)
	{
		LL X,Y;
		scanf("%lld %lld", &X, &Y);
		LL newlcm = (Y*LCM)/gcd(Y,LCM);
		LL newX=X*(newlcm/Y);
		int pos = lower_bound(final_vals.begin(), final_vals.end(), (newX*LCM)/newlcm) - final_vals.begin();
		LL val = abs((final_vals[pos]*newlcm)/LCM - newX);
		if(pos>0)
			val = min(val, abs((final_vals[pos-1]*newlcm)/LCM - newX));
		LL gc = gcd(val,newlcm);
		printf("Case %d: %lld/%lld\n",t,val/gc, newlcm/gc);
	}
  return 0;	
}

