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

//#define TRACE
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
//FILE *fin = freopen(stdin,"r",stdin);
//FILE *fout = freopen(stdout,"w",stdout);
#endif

vector <pair<pair<int,int>,int> > v; // <  <time,score> , id>

const int MAXL = 10000;

bool net_access[MAXL+1];
int tmp[MAXL+3];
int last;
int dp[MAXL+1][31][31];

int parent[MAXL+1][31][31];

int n,m;

void compute_dp(int cnt, int last)
{
	memset(dp,0,sizeof(dp));
	//for(int i=0; i<=n; i++)
	//{
		//for(int j=0; j<=i; j++)
		//{
			//dp[0][i][j]=dp[1][i][j]=0;
			//parent[0][i][j] = parent[1][i][j] = 0;
		//}
	//}

	int cnt2=1;
	for(int k=1, checker=1; k<=last; k++,checker++)
	{
		while(tmp[checker]==1)
		{
			checker++;
			cnt2++;
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=cnt2; j<=i && j<=cnt; j++)
			{
				dp[k][i][j] = dp[k-1][i][j];
				parent[k][i][j]=0;
				if(k-v[i-1].F.F >=0 && dp[k][i][j] < dp[k-v[i-1].F.F][i-1][j-1]+v[i-1].F.S)
				{
					parent[k][i][j] = 2;
					dp[k][i][j] = dp[k-v[i-1].F.F][i-1][j-1]+v[i-1].F.S;
				}
				if(dp[k][i][j] < dp[k][i-1][j])
				{
					parent[k][i][j]=1;
					dp[k][i][j] = dp[k][i-1][j];
				}
				trace(k,i,j,dp[k][i][j]);
			}
		}
	}
}

int main()
{
	si(n);
	si(m);
	for(int i=0; i<n; i++)
	{
		int s,t;
		si(s);
		si(t);
		v.PB(MP(MP(t,s),i));
	}
	sort(v.begin(), v.end());

	for(int i=0; i<m; i++)
	{
		int l,r;
		si(l);
		si(r);
		l++;
		r++;
		for(int j=l;j<r;j++)
			net_access[j]=true;
		last = max(last,r-1);
	}

	int cnt=0;
	int ans_mx=0, cnt_mx=0;
	int save_last = last;

	for(int ll = last; ll>0 && cnt<n; ll--)
	{
		if(net_access[ll])
		{
			tmp[ll]=1;
			cnt++;
			last--;

			compute_dp(cnt, last);
			trace(last, n, cnt, dp[last][n][cnt]);

			if(dp[last][n][cnt]>ans_mx)
			{
				ans_mx = dp[last][n][cnt];
				cnt_mx = cnt;
			}
		}
	}
	memset(tmp, 0, sizeof(tmp));
	vector <int> xx;

	last = save_last;
	int save_cnt = cnt_mx;
	for(int ll=save_last; ll>=0 && cnt_mx>0; ll--)
		if(net_access[ll])
		{
			trace(ll);
			last--;
			tmp[ll]=1;
			cnt_mx--;
			xx.PB(ll-1);
		}

	compute_dp(save_cnt, last);

	printf("%d ", ans_mx);
	int basek=last, basei=n, basej=save_cnt;
	vector<int> anss;
	while(basej>0)
	{
		int p = parent[basek][basei][basej];
		if(p==0)
			basek--;
		else if(p==1)
			basei--;
		else
		{
			anss.PB(v[basei-1].S);
			basej--;
			basei--;
			basek-=v[basei].F.F;
		}
	}
	reverse(anss.begin(), anss.end());
	printf("%d\n", anss.size());
	for(int i=0; i<anss.size(); i++)
		cout<<anss[i] + 1<<" "<<xx[save_cnt-i-1]<<endl;
	return 0;
}


