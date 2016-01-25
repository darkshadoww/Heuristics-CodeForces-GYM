#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
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

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
	ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

vector <pair<LL,LL> > coords;
map <string,int> mm;
vector <string> revmm;
vector <int> graph[101];
vector <bool> present;
vector <int> indegree;
double distt[101][101];

LL dist(string A, string B)
{
	pair<LL,LL> p1 = coords[mm[A]], p2 = coords[mm[B]];
	return (p1.F-p2.F)*(p1.F-p2.F) + (p1.S-p2.S)*(p1.S-p2.S);
}

int main()
{
	int T;
	si(T);
	while(T--)
	{
		mm.clear();
		coords.clear();
		revmm.clear();
		memset(distt, 0x7f, sizeof(distt));
		for(int i=0; i<101; i++)
			graph[i].clear();
		present = vector<bool>(101,false);
		indegree = vector<int>(101,0);

		int n,m;
		si(n);si(m);
		for(int i=0; i<n; i++)
		{
			distt[i][i]=0;
			string tmp;
			int x,y;
			cin>>tmp>>x>>y;
			mm[tmp]=i;
			coords.PB(MP(x,y));
			revmm.PB(tmp);
			//trace(tmp,x,y)
		}

		getchar();
		set <string> xxx;
		for(int i=0; i<m; i++)
		{
			string tmp;
			getline(cin,tmp);
			istringstream is(tmp);
			string S1,S2,S3,ignore;
			is>>S1>>ignore>>S2>>ignore>>ignore>>S3;
			//trace(S1,S2,S3);
			distt[mm[S2]][mm[S3]] = min(distt[mm[S2]][mm[S3]], sqrt((double)dist(S1,S3)) - sqrt((double)dist(S1,S2)) - 1e-9);
			present[mm[S2]] = present[mm[S3]] = true;
			xxx.insert(S2);
			xxx.insert(S3);
		}

		for(int k=0; k<n; k++)
		{
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					distt[i][j] = min(distt[i][j], distt[i][k]+distt[k][j]);
				}
			}
		}

		bool check=false;
		for(int i=0; i<n; i++)
		{
			if(distt[i][i]<0)
			{
				check=true;
				break;
			}
		}

		if(check)
		{
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(present[i]&&present[j] && distt[i][j]<0)
				{
					graph[i].PB(j);
					indegree[j]++;
				}
			}
		}

		queue <int> q;
		for(int i=0; i<n; i++)
		{
			if(present[i] && indegree[i]==0)
				q.push(i);
		}

		string ans;
		vector<string> ans_vector;
		while(!q.empty())
		{
			if(q.size()!=1)
				break;
			int top = q.front();
			q.pop();
			ans_vector.PB(revmm[top]);
			for(auto it : graph[top])
			{
				//trace(it);
				indegree[it]--;
				if(indegree[it]==0)
					q.push(it);
			}
		}
		if(q.empty())
			assert(xxx.size()==ans_vector.size());
		if(!q.empty() || xxx.size()!=ans_vector.size())
		{
			cout<<"UNKNOWN"<<endl;
		}
		else
		{
			for(auto& x: ans_vector)
				cout<<x<<" ";
			cout<<endl;
		}

	}
	return 0;
}


