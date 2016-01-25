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
//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
#endif

LL dp[1002][1002];
LL ans = 0;

vector <LL> v[1001];

int main()
{
	//ios_base::sync_with_stdio(false);
	int N;
	si(N);
	while(N!=0)
	{
		//memset(dp,0,sizeof(dp));
		for(int i=1; i<=N; i++) v[i].clear();
		ans=0;
		for(int i=1; i<=N; i++)
		{
			for(int j=0; j<i; j++)
			{
				LL tmp;
				scanf("%lld", &tmp);
				v[N-j].PB(tmp+(v[N-j].size()?v[N-j].back():0));
			}
		}
		dp[0][0]=0;
		dp[0][1]=0;
		for(int i=1; i<=N; i++)
		{
			dp[i][0]=0;
			for(int j=1; j<=i; j++)
			{
				dp[i][j]= dp[i-1][j]+v[i][j-1];
				dp[i][j]=max(dp[i][j],dp[i][j-1]);
			}
			dp[i][i+1]=dp[i][i];
		}
		printf("%lld\n",dp[N][N+1]);

		si(N);
	}
  return 0;	
}

