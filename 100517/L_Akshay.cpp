#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

//#define TRACE
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
#define REP(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define all(v) (v).begin(),(v).end()

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

const int mod = 1000000007;
inline void add(int &x, int y){x+=y; if(x>=mod)x-=mod; if(x<0)x+=mod;}
inline int mul(int x, int y){ return ((LL)x * y)%mod;}
int gcd(int a, int b){ if(b)return gcd(b,a%b); return a;}
int power(int a ,int p){int ret = 1; while(p){if(p&1)ret=mul(ret,a); a=mul(a,a); p/=2;}return ret;}
int phi(int n){ int ret=n; int i = 2; 
	if(n%i==0){ ret-=ret/i; while(n%i==0)n/=i;}
	for(i=3; i*i<=n; i++)if(n%i==0){ ret-=ret/i; while(n%i==0)n/=i;}
	if(n>1)ret-=ret/n;return ret;
}

#ifdef ONLINE_JUDGE
FILE *fin = freopen("lca.in","r",stdin);
FILE *fout = freopen("lca.out","w",stdout);
#endif

class tree
{
	public:
		VI P,L,R,IN;
		int N;
		int tm;

		void dfs(int x)
		{
			if(x==0)return;
			IN[x] = tm++;
			dfs(L[x]);
			dfs(R[x]);
		}

		void generalize()
		{
			VI nL(N+1);
			VI nR(N+1);
			P.resize(N+1);
			tm = 1;
			dfs(1);
			for(int i = 1; i<=N; i++)
			{
				nL[IN[i]] = IN[L[i]];
				nR[IN[i]] = IN[R[i]];
				P[nL[IN[i]]] = IN[i];
				P[nR[IN[i]]] = IN[i];
			}
			L = move(nL); R = move(nR);
		}

		tree(int N_, VI&& L_, VI&& R_)
			: N(N_),
			L(move(L_)),
			R(move(R_)),
			IN(N_+1),
			P()
	{
		generalize();
	}


		bool isleaf(int i)
		{
			return (i and L[i]+R[i]==0);
		}
		void print()
		{
			printf("%d\n",N);
			for(int i =1; i<=N; i++) 
				printf("%d %d\n",L[i],R[i]);
		}
		void remove(int x)
		{
			priority_queue<int> PQ;
			for(int i =1; i<=N; i++)
				if(isleaf(L[i]) and isleaf(R[i]))
					PQ.push(i);
			while(x--)
			{
				N-=2;
				int y = PQ.top(); PQ.pop();
				trace(y,L[y],R[y],P[y]);
				L[y] = R[y] = 0;
				y = P[y];
				if(isleaf(L[y]) and isleaf(R[y]))
					PQ.push(y);
			}
			generalize();
		}
};

bool same(tree T1, tree T2)
{
	int N = T1.N;
	for(int i = 1; i<=N; i++)
		if(T1.L[i] != T2.L[i] or T1.R[i] != T2.R[i])return false;
	return true;
}



int main()
{
	while(1)
	{
		int XN;
		si(XN);
		trace(XN);
		if(XN==0) return 0;
		VI L(XN+1),R(XN+1);
		for(int i=1; i<=XN; i++)
		{
			si(L[i]);
			si(R[i]);
		}
		tree T1(XN, move(L), move(R));
		si(XN);
		trace(XN);
		L.resize(XN+1);
		R.resize(XN+1);
		for(int i=1; i<=XN; i++)
		{
			si(L[i]);
			si(R[i]);
		}
		tree T2(XN, move(L), move(R));
		trace(XN);
		//T1.print();
		//T2.print();
		if(T1.N > T2.N)
			T1.remove((T1.N - T2.N)/2);
		else if(T2.N > T1.N)
			T2.remove((T2.N - T1.N)/2);
		//T1.print();
		//T2.print();
		if(same(T1,T2))
		{
			//T1.print();
			continue;
		}
		int rem=0;
		int N = T1.N;
		trace("find max",rem);
		for(rem = 1; rem*2<N; rem*=2)
		{
			trace(rem);
			tree cT1 = T1; 
			cT1.remove(rem);
			tree cT2 = T2; 
			cT2.remove(rem);
			cT1.print(); cT2.print();
			trace(rem);
			if(same(cT1,cT2))break;
			trace(rem);
		}
		trace("got max",rem);
		while(rem>1)
		{
			rem/=2;
			trace(rem);
			tree cT1 = T1; 
			cT1.remove(rem);
			tree cT2 = T2; 
			cT2.remove(rem);
			if(same(cT1,cT2)==false)
			{
				T1 = cT1; T2 = cT2;
			}
		}
		T1.remove(1); T2.remove(1);
		T1.print();
	}
	return 0;	
}
