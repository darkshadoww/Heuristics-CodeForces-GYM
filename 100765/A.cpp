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
	string A;
	int K;
	cin>>A>>K;
	priority_queue<pair<char,int> > pq;
	int i=0, rem=K, cur_front=-1, cur_rem=0;
	string ans;
	while(rem>0 && i<A.length())
	{
		for(; i<cur_front+1+rem+1 && i<A.length(); i++)
		{
			pq.push(MP(A[i],-i));
		}
		while(!pq.empty())
		{
			auto cur=pq.top();
			pq.pop();
			if(-1*cur.S < cur_front)
			{
				rem--;
				continue;
			}
			ans+=cur.F;
			cur_front=-1*cur.S;
			cur_rem++;
			rem=K-(cur_front-(cur_rem-1));
			break;
		}
	}
	for(int i=cur_front+1; i<A.length(); i++)
	{
		ans+=A[i];
	}
	for(int i=0; i<ans.length()-rem; i++)
		cout<<ans[i];
	cout<<endl;
	clock_t endTime = clock();
	cerr<<"\nTime:"<< double(endTime - startTime) / CLOCKS_PER_SEC <<" seconds\nClocks:"<<endTime-startTime<<" clocks"<<endl;
	return 0;
}
