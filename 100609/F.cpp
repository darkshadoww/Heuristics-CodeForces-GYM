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
FILE *fin = freopen("flat.in","r",stdin);
FILE *fout = freopen("flat.out","w",stdout);
#endif

int main()
{
	ios_base::sync_with_stdio(false);
	int n; double c;
	cin>>n>>c;
	double arr=0;
	int arr_room=0, bed=0;
	for(int i=0; i<n; i++)
	{
		int ctmp;
		string stmp;
		cin>>ctmp>>stmp;
		if(stmp=="balcony")
			arr+=((ctmp*1.0)/2.0);
		else
			arr+=ctmp;
		arr_room+=ctmp;
		if(stmp=="bedroom")
			bed+=ctmp;
	}
	cout<<fixed<<setprecision(8);
	cout<<arr_room<<endl;
	cout<<bed<<endl;
	cout<<arr*c<<endl;
  return 0;	
}

