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

#define MX 50000

int D[MX+1];
int n,t;
VPII V;

bool possible(int r)
{
	deque <pair<long long int,int> > dq;
	dq.push_back(MP(0,1));
	for(int i=2; i<=n; i++)
	{
		while(!dq.empty() && dq.front().S + r < i)
			dq.pop_front();
		long long int cur = dq.front().F + D[i];
		while(!dq.empty() && dq.back().F >= cur)
			dq.pop_back();
		dq.push_back(MP(cur,i));
	}
	if(dq.back().F + n - 1<=t)
		return true;
	return false;
}


int main()
{
	FILE *fin = freopen("journey.in","r",stdin);
	FILE *fout = freopen("journey.out","w",stdout);
	cin>>n>>t;
	PII A[MX-1];
	for(int i=1; i<=n-1; i++)
	{
		cin>>A[i-1].F;
		A[i-1].S=i;
	}
	sort(A,A+n-1);	//check
	V.push_back(A[0]);
	int mx_r = A[0].S;
	for(int i=1; i<n-1; i++)
	{
		if(A[i].S>mx_r)
		{
			mx_r=A[i].S;
			V.push_back(A[i]);
		}
	}
	D[0]=D[1]=D[n]=0;
	for(int i=2; i<=n-1; i++)
		cin>>D[i];
	
	auto lo = V.begin();
	auto hi = V.end();
	while(lo<hi)
	{
		auto mid = lo + (hi-lo)/2;
		if(mid!=V.end())
		{
			if(possible(mid->S))
			{
				hi=mid;
			}
			else
			{
				lo=mid+1;
			}
		}
	}
	if(lo!=V.begin() && possible((lo-1)->S))
		cout<<(lo-1)->F<<endl;
	else if(lo!=V.end() && possible(lo->S))
		cout<<lo->F<<endl;
	else if(lo!=V.end() && (lo+1)!=V.end() && possible((lo+1)->S))
		cout<<(lo+1)->F<<endl;
  return 0;	
}

