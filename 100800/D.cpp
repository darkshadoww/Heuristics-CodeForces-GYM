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
#define EPS 1e-8

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

bool in(double a, double b, double c)
{
	if(a>=b-EPS && a<=c+EPS)
		return true;
	if(a>=c-EPS && a<=b+EPS)
		return true;
	return false;
}

bool equal(double a, double b)
{
	if(fabs(a-b)<EPS)
		return true;
	return false;
}

double getmindist(double x1, double y1, double x2, double y2, double h)
{
	double a = y2-y1;
	double b = x1-x2;
	double c = x2*y1-x1*y2;
	double x = -c*a/(a*a+b*b);
	double y = -c*b/(a*a+b*b);
	if(in(x,x1,x2) && in(y,y1,y2))
		return sqrt(x*x+y*y+h*h);
	return sqrt(min(x1*x1+y1*y1, x2*x2+y2*y2) + h*h);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin>>N;
	double mn_area=1e14;
	double mx_area=0;
	double ans = 1e8;
	double sec_min=1e8;
	double sec_max=1e8;
	bool went_inside=false;
	for(int i=0; i<N; i++)
	{
		int Hout, Hin;
		cin>>Hout>>Hin;
		int M;
		cin>>M;
		VPII points(M);
		for(int j=0; j<M; j++)
		{
			cin>>points[j].F>>points[j].S;
		}
		double area = 0.0;
		bool inside = false;
		for(int j=0; j<M; j++)
		{
			double x1=points[j].F;
			double y1=points[j].S;
			double x2=points[(j+1)%M].F;
			double y2=points[(j+1)%M].S;
			ans=min(ans,getmindist(x1,y1,x2,y2,min(Hout,Hin)));
			double a = y2-y1;
			double b = x1-x2;
			double c = x2*y1-x1*y2;
			if(-c/a>0 && in(-c/a,x1,x2) && in(0,y1,y2))
			{
				if(equal(-c/a,x1) && equal(0,y1))
				{
					//Do nothing
				}
				else if(equal(-c/a,x2) && equal(0,y2))
				{
					double x3=points[(j+2)%M].F;
					double y3=points[(j+2)%M].S;
					if((y1)*(y3)<0)
						inside=!inside;
				}
				else
				{
					inside=!inside;
				}
			}
			area+=x1*y2-x2*y1;
		}
		//trace(i, inside, area);
		if(!inside && area>mx_area)
		{
			mx_area = area;
			sec_max = Hout;
		}
		if(inside && area<mn_area)
		{
			went_inside = true;
			//trace(went_inside);
			mn_area = area;
			sec_min = Hin;
		}
		//trace(i);
	}
	if(!went_inside)
		sec_min = sec_max;
	cout<<fixed<<setprecision(10)<<min(sec_min,ans)<<endl;
  return 0;	
}
