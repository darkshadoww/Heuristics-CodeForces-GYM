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

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

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

int N,M;
string A[300];

void f(int mnx, int mxx, int mny, int mxy)
{
	for(int i = mnx; i<=mxx; i++)
		for(int j = mny; j<=mxy; j++)
			A[i-mnx][j-mny] = A[i][j];
	N = mxx - mnx + 1;
	M = mxy - mny + 1;
	for(int i=0;i<N;i++)
		A[i].resize(M);
}

bool B[300][300];
string C[300];

int val(int n, int m)
{
	for(int i =0; i<N; i++)
		for(int j = 0; j<M; j++)
			B[i][j] = false;
	int xoff = N-n;
	int yoff = M-m;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(i>=xoff && j>=yoff) continue;
			B[i][j]=(A[i][j]=='#'?true:false);
		}
	}
	for(int i=xoff; i<N; i++)
		for(int j=yoff; j<M; j++)
		{
			if(i<n && j<m) continue;
			B[i-xoff][j-yoff]=(A[i][j]=='#'?true:false);
		}
	for(int i = 0; i+xoff<n; i++)
		for(int j = 0; j+yoff<m; j++)
			if(B[i][j]==false && A[i+xoff][j+yoff]=='#') {
				B[i+xoff][j+yoff] = true;
			}

	for(int i=0; i<N; i++)
	{
		C[i]=A[i];
		for(int j=0; j<M; j++)
			C[i][j] = '.';
	}

	for(int i =0 ;i<n; i++)
		for(int j = 0 ;j<m; j++)
		{
			if(B[i][j])
				C[i][j]='#';
		}
	for(int i =0 ;i<n; i++)
		for(int j = 0 ;j<m; j++)
		{
			if(B[i][j])
				C[i+xoff][j+yoff]='#';
		}
	for(int i=0; i<N; i++)
	{
		//trace(n,m,C[i],A[i]);
		if(C[i]!=A[i])
			return -1;
	}
	//trace(n,m);
	int cnt = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			if(B[i][j])
				cnt++;
	}
	return cnt;
}

int main()
{
	int t; si(t); while(t--)
	{
		si(N); si(M);
		for(int i = 0; i<N; i++)cin>>A[i];
		int mnx = N; int mxx = -1;
		int mny = M; int mxy = -1;
		for(int i =0; i<N; i++)
			for(int j = 0; j<M; j++)
				if(A[i][j]=='#')
				{
					if(i>mxx)mxx = i;
					if(i<mnx)mnx = i;
					if(j>mxy)mxy = j;
					if(j<mny)mny = j;
				}
		if(mnx==N)
		{
			cout<<0<<endl; continue;
		}
		f(mnx,mxx,mny,mxy);
		int ans = N*M;
		for(int n = 1; n<=N; n++)
			for(int m = 1; m<=M; m++)
			{
				if(n==N && m==M)
					continue;
				int tmp=val(n,m);
				if(tmp!=-1)
				{
					ans = min(ans,tmp);
				}
			}
		for(int i=0; i<N; i++)
			reverse(A[i].begin(),A[i].end());
		for(int n = 1; n<=N; n++)
			for(int m = 1; m<=M; m++)
			{
				if(n==N && m==M)
					continue;
				int tmp=val(n,m);
				if(tmp!=-1)
				{
					ans = min(ans,tmp);
				}
			}

		cout<<ans<<endl;
	}
	//ios_base::sync_with_stdio(false);
	return 0;
}
