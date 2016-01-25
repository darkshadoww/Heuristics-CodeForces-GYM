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

int ans(int wr, int lr, int wt, int lt)
{
	if(wr>=wt && lr>=lt)
	{
	int an=0;
	an+=(wr/wt)*(lr/lt);
	int rem1=0, rem2=0;
	if(wr%wt!=0)
		rem1=(wt/(wr%wt));
	if(lr%lt!=0)
		rem2=(lt/(lr%lt));
	if(rem1==0)
	{
		if(rem2==0)
			return an;
		an+=((wr/wt)-1)/rem2 + 1;
	}
	else if(rem2==0)
	{
		an+=((lr/lt)-1)/rem1 + 1;
	}
	else
	{
		an+=((wr/wt)-1)/rem2 + ((lr/lt)-1)/rem1 + 2;
		if((wr/wt)%rem2==0 && (lr/lt)%rem1 ==0)
			an++;
	}
	return an;
	}
	else if(wr<=wt && lr>=lt)
	{
		return (((((lr-1)/lt)+1)-1) / (wt/wr)) + 1;
	}
	else if(wr>=wt && lr<=lt)
	{
		return (((((wr-1)/wt)+1)-1) / (lt/lr)) + 1;
	}
	else
	{
		return 1;
	}
}

int main()
{
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false);
	int wr, lr, wt, lt;
	cin>>wr>>lr>>wt>>lt;
	cout<<ans(wr,lr,wt,lt)<<endl;
	//cout<<ans(wr,lr,wt,lt)<<ans(wr,lr,lt,wt)<<endl;
	clock_t endTime = clock();
  cerr<<"\nTime:"<< double(endTime - startTime) / CLOCKS_PER_SEC <<" seconds\nClocks:"<<endTime-startTime<<" clocks"<<endl;
  return 0;
}
