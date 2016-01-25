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
FILE *fin = freopen("ghanophobia.in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
#endif

int main()
{
	//ios_base::sync_with_stdio(false);
	int T;
	si(T);
	for(int t=1; t<=T; t++)
	{
		int n,m;
		scanf("%d:%d", &n,&m);
		if(n+1 == m+6)
		{
			if(m==1)
			{
				printf("Case %d: PENALTIES\n",t);
			}
			else if(m>1)
			{
				printf("Case %d: NO\n",t);
			}
			else
			{
				printf("Case %d: YES\n",t);
			}
		}
		else if(n+1 > m+6)
		{
				printf("Case %d: YES\n",t);
		}
		else
		{
				printf("Case %d: NO\n",t);
		}
	}
  return 0;	
}

