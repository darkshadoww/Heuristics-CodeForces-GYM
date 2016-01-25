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


int main()
{
	FILE *fin = freopen("black.in","r",stdin);
	FILE *fout = freopen("black.out","w",stdout);
	int b,w;
	cin>>b>>w;
	if(b==1&&w==1)
	{
		cout<<"1 2\n.@"<<endl;
		return 0;
	}
	bool ans[2005][3];
	int cnt=0;
	for(int i=0; i<(b/2)*2; i++)
	{
		if(i&1)
			ans[i][0]=ans[i][1]=ans[i][2]=true;
		else
		{
			ans[i][0]=ans[i][2]=false;
			ans[i][1]=true;
		}
		cnt++;
	}
	ans[cnt][0]=ans[cnt][1]=ans[cnt][2]=true;
	cnt++;
	ans[cnt][0]=ans[cnt][1]=ans[cnt][2]=false;
	cnt++;
	for(int i=(b/2)*2+2; i<(b/2)*2+(w/2)*2+2; i++)
	{
		if((i&1)==0)
			ans[i][0]=ans[i][1]=ans[i][2]=false;
		else
		{
			ans[i][0]=ans[i][2]=true;
			ans[i][1]=false;
		}
		cnt++;
	}
	if((b&1)==0)
		ans[0][1]=false;
	if((w&1)==0)
		ans[cnt-1][1]=true;
	cout<<cnt<<" "<<3<<endl;
	for(int i=0;i<cnt; i++)
	{
		for(int j=0;j<3; j++)
		{
			if(ans[i][j])
				cout<<".";
			else
				cout<<"@";
		}
		cout<<endl;
	}
  return 0;	
}

