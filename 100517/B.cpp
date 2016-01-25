// heuristics

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

FILE *fin = freopen("bubble.in","r",stdin);
FILE *fout = freopen("bubble.out","w",stdout);


int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	unsigned long long int k;
	cin>>n>>k;
	while(!(n==0 && k==0))
	{
		k--;
	int p=0;
	for(p=0; (1ull<<p)<=k; p++);
	int cur=1;
	for(cur=1; cur+p<=n-1; cur++)
		cout<<cur<<" ";
	while(p>=0)
	{
		p--;
		while(p>=0 && (((1ull<<p)&k)==0)){p--;cout<<cur++<<" ";};
		int cnt=0;
		while(p>=0 && ((1ull<<p)&k)){p--;cnt++;}
		cout<<cur+cnt<<" ";
		for(;cnt!=0;cnt--,cur++)
			cout<<cur<<" ";
		cur++;
	}
	while(cur<=n){cout<<cur++<<" ";};
	cout<<endl;
	cin>>n>>k;
	}
  return 0;	
}

