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

vector<int> W(200005), pre(200005), C(200005), pre_cost(200005);

int BS(int st, int end, int val)
{
	while(st<end)
	{
		int mid = (st+end)/2;
		if(mid == st)
		{
			break;
		}
		if(pre[mid]>val)
			end=mid-1;
		else if(pre[mid]<=val)
			st=mid;
	}
	if(st==0&&pre[0]>val)
		return -1;
	if(pre[st+1]<=val)
		return st+1;
	if(pre[st]<=val)
		return st;
	if(pre[st-1]<=val)
		return st-1;
}

int main()
{
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false);
	FILE *fin = freopen("input.txt","r",stdin);
	FILE *fout = freopen("output.txt","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int TotalW = 0;
	rep(i,n)
	{
		cin>>W[i]>>C[i];
		if(i==0)
		{
			pre[i]=W[i];
			pre_cost[i]=C[i];
		}
		else
		{
			pre[i]=pre[i-1]+W[i];
			pre_cost[i]=pre_cost[i-1]+C[i];
		}
		TotalW+=W[i];
	}
	int Wt=0;
	for(int i=n-1; i>=n-m; i--)
		Wt+=W[i];

	int cost=0, mx_cost=0;
	int t=0, h=0;
	int i=0;
	while(i<n+1)
	{
		int mx_wt_rem = TotalW - Wt - Wt/k;
		if(Wt%k!=0)
			mx_wt_rem--;
		int val = BS(0, n-m-i-1, mx_wt_rem);
		if(val>=0 && cost+pre_cost[val] >= mx_cost)
		{
			mx_cost = cost+pre_cost[val];
			h=i;
			t=val+1;
		}

		TotalW-=W[n-1-i];
		Wt+=W[(n-m-1-i)]-W[n-i-1];
		cost+=C[n-i-1];
		if((TotalW-Wt)*k<Wt)
			break;
		i++;
	}
	cout<<t+h<<" "<<mx_cost<<endl;
	rep(i,h)
		cout<<"H";
	rep(i,t)
		cout<<"T";
	cout<<endl;
	clock_t endTime = clock();
  return 0;
}

