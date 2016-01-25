#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
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

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

#ifdef ONLINE_JUDGE
FILE *fin = freopen("army.in","r",stdin);
#endif
//FILE *fout = freopen("out","w",stdout);

vector <LL> sq_sum;
vector <LL> normal_sum;

int main()
{
	sq_sum.PB(0);
	normal_sum.PB(0);
	for(LL i=1; i<1500001; i++)
	{
		sq_sum.PB((i*i) + sq_sum.back());
		normal_sum.PB(i+normal_sum.back());
	}
	int T;
	si(T);
	for(int t=1; t<=T; t++)
	{
		LL N, ans=0;
		scanf("%lld", &N);
		LL pos = lower_bound(sq_sum.begin(), sq_sum.end(), N) - sq_sum.begin();
		if(sq_sum[pos]>N)
			pos--;
		N-=sq_sum[pos];
		ans+=pos*pos;
		pos++;
		if((pos*(pos+1))/2 <= N)
		{
			N-=(pos*(pos+1))/2;
			ans+=pos;
			LL torem = normal_sum[pos-1] - N;
			LL pos2 = lower_bound(normal_sum.begin(), normal_sum.end(), torem) - normal_sum.begin();
			if(normal_sum[pos-1] - normal_sum[pos2] < N)
				pos2--;
			N-=normal_sum[pos-1] - normal_sum[pos2];
			ans+= (pos-1)-pos2;
		}
		else
		{
			LL pos2 = lower_bound(normal_sum.begin(), normal_sum.end(), N) - normal_sum.begin();
			N-=normal_sum[pos2];
			ans+=pos2;
		}
		printf("Case %d: %lld\n", t, ans);
	}
	return 0;
}


