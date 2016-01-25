
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
#include<unordered_map>
#define rep(i,N) for(int (i)=0;(i)<(N);(i)++)
#define repi(i,j,N) for(int (i)=(j);(i)<(N);(i)++)
#define repg(i,j,N) for((i)=(j);(i)<(N);(i)++)
#define si(i) scanf("%d",&(i))
#define sl(i) scanf("%lld",&(i))
#define pi(i) printf("%d",(i))
#define pl(i) printf("%lld",(i))
#define pin(i) printf("%d\n",(i))
#define pln(i) printf("%lld\n",(i))
#define pw    printf(" ");
#define pn    printf("\n");

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

pair<long long int, int> get(string st, int j)
{
	while(st[j]==' ') j++;
	bool neg=false;
	if(st[j]=='-')
	{
		neg=true;
		j++;
	}
	int val=0;
	while(st[j]>='0' && st[j]<='9')
	{
		val*=10;
		val+=st[j]-'0';
		j++;
	}
	int xx=0;
	if(st[j]=='.')
	{
		j++;
		while(st[j]>='0' && st[j]<='9')
		{
			xx++;
			val*=10;
			val+=st[j]-'0';
			j++;
		}
	}
	while(xx<2) {xx++; val*=10;}

	if(neg)
		return MP(-1*val, j);
	return MP(val, j);
}

int main()
{
	clock_t startTime = clock();
	int N;
	cin>>N;
	long long int X[10005];
	vector<int> ans;
	vector <pair<long long int,int> > vv;
	for(int i=0,j=0; i<N; i++)
	{
		string st;
		cin>>st;
		pair <long long int ,int> pl;
		long long int val;
			pl=get(st,0);
			val=pl.F;
			j=pl.S;
			//cout<<val<<" "<<j<<endl;
		if(val>100)
			ans.PB(i+1);
		else
			vv.PB(MP(val, i+1));
	}
	sort(all(vv));
	if(vv.size()!=0)
	{
			for(int i=0; i+1<vv.size(); i+=2)
			{
				if(vv[i].F*vv[i+1].F>10000)
				{
					ans.PB(vv[i].S);
					ans.PB(vv[i+1].S);
				}
			}
			if(ans.size()==0)
			{
				if(vv.size()==1)
					ans.PB(vv[0].S);
				else
				{
					if(vv[0].F*vv[1].F>vv.back().F*100)
					{
						ans.PB(vv[0].S);
						ans.PB(vv[1].S);
					}
					else
						ans.PB(vv.back().S);
				}
			}
	}
	sort(all(ans));
	cout<<ans.size()<<endl;
	tr(ans,it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	clock_t endTime = clock();
  cerr<<"\nTime:"<< double(endTime - startTime) / CLOCKS_PER_SEC <<" seconds\nClocks:"<<endTime-startTime<<" clocks"<<endl;
  return 0;
}

