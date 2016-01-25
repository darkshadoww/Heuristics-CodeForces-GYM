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


int main()
{
	ios_base::sync_with_stdio(false);
	double d;
	int n,b;
	cin>>d>>n>>b;
	vector <pair<double, double> > obs;
	for(int i=0; i<n; i++)
	{
		double p,h;
		cin>>p>>h;
		obs.PB(MP(p,h));
	}
	double ans=1e12;
	for(int i=0; i<=b; i++)
	{
		double num_parts = i+1;
		double vx_reqd = 1e12, to_sub=0.0, vy_reqd=0.0;
		for(int j=0; j<obs.size(); j++)
		{
			while(obs[j].F-to_sub >=d/num_parts)
				to_sub+=d/num_parts;
			double x = obs[j].F-to_sub;
			double y = obs[j].S;
			double vxsq = ((d/num_parts - x)*x)/(2*y);
			double vysq;
			if(vxsq==0)
				vysq=1e12;
			else
				vysq = (d/num_parts)*(d/num_parts)/(4*vxsq);
			if(vysq > vy_reqd)
			{
				vy_reqd=vysq;
				vx_reqd=vxsq;
			}
		}
		if((d/num_parts)/2 > vy_reqd)
		{
			vy_reqd =(d/num_parts)/2;
			vx_reqd = vy_reqd;
		}
		ans=min(ans,sqrt(vy_reqd+vx_reqd));
	}
	cout<<fixed<<setprecision(5)<<ans<<endl;
  return 0;	
}

