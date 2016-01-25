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
FILE *fin = freopen("galaxy.in","r",stdin);
FILE *fout = freopen("galaxy.out","w",stdout);
#endif

int col[5001];
bool init[10][10];
vector<int> v[5001];
int n,k,m;

bool check(vector<int>& st)
{
	for(int i=0; i<st.size(); i++)
	{
		if(!init[st[i]][st[(i+1)%st.size()]])
			return false;
	}
	return true;
}

//void dfs(int node, int cl, int par)
//{
	//if(col[node]!=-1) return;
	//col[node]=cl;
	//for(auto it : v[node])
		//if(it!=par)
			//dfs(it, (cl+1)%k, node);
//}

int parent[5001];

int main()
{
	//ios_base::sync_with_stdio(false);
	memset(col,-1,sizeof(col));
	memset(init,0,sizeof(init));
	si(n);
	si(k);
	si(m);
	for(int i=0; i<m; i++)
	{
		int a,b;
		si(a); si(b);
		a--;
		b--;
		if(a<k && b<k)
			init[a][b]=init[b][a]=true;
		else
		{
			v[a].PB(b);
			v[b].PB(a);
		}
	}
	vector <int> st;
	for(int i=0; i<k; i++)
		st.PB(i);
	do
	{
		if(check(st))
			break;
	} while(next_permutation(++st.begin(),st.end()));

	queue<int> q;
	for(int i=0; i<k; i++)
	{
		//dfs(st[i],i,-1);
		col[st[i]]=i;
		for(auto it : v[st[i]])
		{
			q.push(it);
			parent[it]=st[i];
		}
	}

	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		if(col[cur]!=-1) continue;
		
		int mn_cur = (col[parent[cur]]+1)%k;
		vector<bool> pos(k,false);
		for(auto it:v[cur])
		{
			if(col[it]!=-1)
				pos[col[it]]=true;
		}
		for(int i=0; i<k; i++)
		{
			if(!pos[(mn_cur+i)%k])
			{
				col[cur]=(mn_cur+i)%k;
				break;
			}
		}

		for(auto it:v[cur])
		{
			if(col[it]==-1)
			{
				q.push(it);
				parent[it]=cur;
			}
		}
	}

	for(int i=0; i<n; i++)
		printf("%d ", col[i]+1);
	printf("\n");
  return 0;	
}

