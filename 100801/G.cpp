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

const int MX=100000;

int n,k;
int indegree[MX+1];
set <int> V[MX+1];
set <int> poss;
VPII ans;

int main()
{
	FILE *fin = freopen("graph.in","r",stdin);
	FILE *fout = freopen("graph.out","w",stdout);
	memset(indegree, 0, sizeof(indegree));
	int m;
	cin>>n>>m>>k;
	for(int i=0; i<m; i++)
	{
		int u,v;
		cin>>u>>v;
		if(V[u].find(v)==V[u].end())
		{
			V[u].insert(v);
			indegree[v]++;
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(indegree[i]==0)
			poss.insert(i);
	}
	priority_queue <int> deferred;
	bool first=false;
	int printed = 0;
	int cur = 0;
	while(printed<n)
	{
		if(!poss.empty())
		{
			int num_links = min(k,(int)poss.size()-1);
			if(num_links!=0)
			{
				k-=num_links;
				auto endpos = poss.begin();
				for(int j=0; j<num_links-1; j++) endpos++;
				for(auto it=endpos; ; it--)
				{
					deferred.push(*it);
					if(it==poss.begin())
						break;
				}
				poss.erase(poss.begin(), ++endpos);
			}
			if(k>0 && !deferred.empty() && deferred.top() > *poss.rbegin())
			{
				//trace(*poss.rbegin());
				deferred.push(*poss.rbegin());
				poss.erase(--poss.end());
				k--;
			}
		}
		if(poss.empty() && !deferred.empty())
		{
			int defcur = deferred.top();
			deferred.pop();
			V[cur].insert(defcur);
			ans.push_back(make_pair(cur, defcur));
			poss.insert(defcur);
		}

		if(first)
		{
			cout<<" ";
		}
		first=true;
		cur = *(poss.begin());
		poss.erase(poss.begin());
		cout<<cur;
		printed++;
		for(auto it = V[cur].begin(); it!=V[cur].end(); it++)
		{
			indegree[*it]--;
			if(indegree[*it]==0)
			{
				poss.insert(*it);
			}
		}
	}
	cout<<endl;
	cout<<ans.size()<<endl;
	for(int i=0; i<ans.size(); i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;	
}

