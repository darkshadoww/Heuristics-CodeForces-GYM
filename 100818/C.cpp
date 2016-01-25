// heuristics
#ifdef __APPLE__

    #include<iostream>
    #include<iomanip>
    #include<ctime>
    #include<cstdio>
    #include<vector>
    #include<algorithm>
    #include<utility>
    #include<queue>
    #include<stack>
    #include<string>
    #include<cstring>
    #include<sstream>
    #include<map>
    #include<set>
    #include<unordered_map>
    #include<unordered_set>

#else

    #include<bits/stdc++.h>

#endif  // __APPLE__

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

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

map <long long int, map<int,double> > memoize;

map <int, double> dfs(long long int N)
{
	if(memoize.find(N)!=memoize.end())
		return memoize[N];
	map<int,double> ret;
	int times = 0;
	for(int i=2; i*i<=N; i++)
	{
		if(N%i==0)
		{
			times++;
			if(i!=N/i)
				times++;
			map <int, double> m1 = dfs(N/i);
			map <int, double> m2 = dfs(i);
			for(auto it : m1)
			{
				for(auto it2 : m2)
				{
					int fact = (i==N/i)?1:2;
					ret[max(it.F, it2.F)+1] += fact*it.S*it2.S;
				}
			}
		}
	}
	for(auto& it : ret)
		it.S/=times;
	if(ret.size()==0)
		ret[0]=1;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		long long int N;
		cin>>N;
		map <int,double> x = dfs(N);
		double ans = 0;
		for(auto it : x)
		{
			ans += it.F*it.S;
			trace(it.F, it.S);
		}
		cout<<fixed<<setprecision(8)<<ans<<endl;
	}
  return 0;	
}

