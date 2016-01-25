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

void sout(string x)
{
	cout<<x;
	fflush(stdout);
}

int ans[101];

int main()
{
	//ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector <int> S,N,Z;
		for(int i=1; i<=n; i++)
		{
			cout<<1; sout("\n");
			cout<<i; sout("\n");
			int tmp;
			cin>>tmp;
			if(tmp)
				S.PB(i);
			else
				N.PB(i);
		}
		for(auto x: S)
		{
			cout<<N.size()+1; sout("\n");
			cout<<x<<" ";
			for(auto y: N)
			{
				cout<<y<<" ";
			}
			sout("\n");
			int tmp;
			cin>>tmp;
			if(tmp)
			{
				ans[x]=1;
				Z.PB(x);
			}
			else
				ans[x]=3;
		}
		for(auto x: N)
		{
			cout<<Z.size()+1; sout("\n");
			cout<<x<<" ";
			for(auto y: Z)
			{
				cout<<y<<" ";
			}
			sout("\n");
			int tmp;
			cin>>tmp;
			if(tmp==Z.size())
				ans[x]=2;
			else
				ans[x]=3;
		}
		cout<<-1; sout("\n");
		for(int i=1; i<=n; i++)
			cout<<ans[i]<<" ";
		sout("\n");
	}
  return 0;	
}

