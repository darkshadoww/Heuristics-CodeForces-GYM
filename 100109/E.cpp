/////////////////////////////////////////
//  Author : Akshay Jaggi             //
///////////////////////////////////////

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



int main()
{
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false);
	FILE *fin = freopen("input.txt","r",stdin);
	FILE *fout = freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector<pair<int,int> > princess, dragons;
	rep(i,n-1)
	{
		char x;
		int val;
		cin>>x>>val;
		switch(x)
		{
			case 'd': dragons.PB(MP(i+1,val));
								break;
			case 'p': princess.PB(MP(i+1,val));
								break;
		}
	}
/*	int count_min=1000000000;
	vector<pair<int,int> > new_princess;
	for(auto i = princess.rbegin(); i!=princess.rend(); i++)
	{
		if(i==princess.rbegin())
		{
			new_princess.PB(*i);
			continue;
		}
		if(count_min<=(i->S))
		{
		}
		else
		{
			new_princess.PB(*i);
			count_min = i->S;
		}
	}
	princess=new_princess;
	sort(all(princess));
*/
	long long int ans = 0;
	priority_queue<pair<int,int> > dragons_dead;
	auto drag_iter = dragons.begin();
	for(int i=0; i<princess.size()-1; i++)
	{
		while(drag_iter!=dragons.end() && drag_iter->F<princess[i].F)
		{
			dragons_dead.push(MP(-1*drag_iter->S, drag_iter->F));
			drag_iter++;
		}
		while(dragons_dead.size()>=princess[i].S)
			dragons_dead.pop();
	}
	while(drag_iter!=dragons.end())
	{
		dragons_dead.push(MP(-1*drag_iter->S, drag_iter->F));
		drag_iter++;
	}
	if(dragons_dead.size()<princess[princess.size()-1].S)
		cout<<-1<<endl;
	else
	{
		int sz=dragons_dead.size();
		vector<int> v_tmp;
		while(dragons_dead.size()>0)
		{
			ans+=-1*dragons_dead.top().F;
			v_tmp.PB(dragons_dead.top().S);
			dragons_dead.pop();
		}
		sort(all(v_tmp));
		cout<<ans<<endl;
		cout<<sz<<endl;
		tr(v_tmp, it)
			cout<<*it+1<<" ";
		cout<<endl;
	}
	clock_t endTime = clock();
  cerr<<"\nTime:"<< double(endTime - startTime) / CLOCKS_PER_SEC <<" seconds\nClocks:"<<endTime-startTime<<" clocks"<<endl;
  return 0;
}

