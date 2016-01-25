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
#include<unordered_set>
#include<set>
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

vector<string> v,pre;

int main()
{
	clock_t startTime = clock();
	int N;
	scanf("%d ",&N);
	rep(i,N)
	{
		string s;
		getline(cin,s);
		int j=0;
		while(j<s.size())
		{
			if((s[j]>='a'&&s[j]<='z') || (s[j]>='A'&&s[j]<='Z'))
			{
				if(s[j]>='A'&&s[j]<='Z')
					s[j]=s[j]-'A'+'a';
			}
			else
				s[j]=' ';
			j++;
		}
		pre.PB(s);
	}
	unordered_set <string> magic_set;
	cin>>N;
	rep(i,N)
	{
		string s;
		cin>>s;
		magic_set.insert(s);
	}
	tr(pre, it)
	{
		istringstream sss(*it);
		while(!sss.eof())
		{
			string t;
			sss>>t;
			if(t.empty())
				break;
			if(magic_set.find(t)==magic_set.end())
				v.PB(t);
		}
	}
	unordered_map <string, int> m_s;
	map <pair<string,string>,int> m_ss;
	for(int i=0; i<v.size(); i++)
	{
		m_s[v[i]]++;
		if(i+1<v.size())
		{
			if(m_ss.find(MP(v[i],v[i+1]))!=m_ss.end())
				m_ss[MP(v[i],v[i+1])]++;
			else
				m_ss[MP(v[i+1],v[i])]++;
		}
	}
	cin>>N;
	rep(i,N)
	{
		string a,b;
		cin>>a>>b;
		int val;
		if(m_ss.find(MP(a,b))!=m_ss.end())
			val=m_ss[MP(a,b)];
		else
			val=m_ss[MP(b,a)];
		cout<<setprecision(10)<<(((((double)val)/m_s[a])/m_s[b])*v.size()*v.size())/(v.size()-1)<<endl;
	}
	clock_t endTime = clock();
  cerr<<"\nTime:"<< double(endTime - startTime) / CLOCKS_PER_SEC <<" seconds\nClocks:"<<endTime-startTime<<" clocks"<<endl;
  return 0;
}
