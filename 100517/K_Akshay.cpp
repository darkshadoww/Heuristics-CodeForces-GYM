// heuristics
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
FILE *fin = freopen("kingdom.in","r",stdin);
FILE *fout = freopen("kingdom.out","w",stdout);
#endif

struct point
{
	LL x,y;
	point() {}
	point(LL x, LL y)
		: x(x), y(y) {}
};

struct line
{
	LL a,b,c;
	line(point p1, point p2)
	{
		a=p1.y-p2.y;
		b=p2.x-p1.x;
		c=-(a*p1.x+b*p1.y);
	}
	bool is_online(point p)
	{
		return a*p.x+b*p.y+c==0;
	}
	bool on_left(point p)
	{
		return a*p.x+b*p.y+c>0;
	}
    bool on_same(point p1, point p2)
    {
        if(is_online(p1) or is_online(p2))return true;
        return on_left(p1) == on_left(p2);
    }
    bool on_same(point p1, point p2, point p3)
    {
        return on_same(p1,p2) and on_same(p1,p3) and on_same(p2,p3);
    }
};

vector<point> P;

int main()
{
	while(1)
	{
		P.clear();
		int n;
		si(n);
		if(n==0) break;
		for(int i=0; i<n; i++)
		{
			LL x,y;
			scanf("%lld %lld",&x,&y);
			P.emplace_back(x,y);
		}
		point A,B;
		scanf("%lld %lld",&A.x, &A.y);
		scanf("%lld %lld",&B.x, &B.y);
		line AB(A,B);
		bool left = AB.on_left(P[0]);
		int st=0,end=0;
		for(int i=1; i<n; i++)
		{
			if(AB.on_left(P[i])!=left && !AB.is_online(P[i]))
			{
				st=i;
				for(end=st+1; end<n && AB.on_left(P[end])==AB.on_left(P[st]); end++);
				break;
			}
		}
		vector <point> L,R;
		//trace(st,end,P.size());
		L.insert(L.end(),P.begin()+st,P.begin()+end);
		R.insert(R.end(),P.begin()+end,P.end());
		R.insert(R.end(),P.begin(),P.begin()+st);
		if(AB.is_online(L.back()))
			L.erase(--L.end());
		if(AB.is_online(R.back()))
			R.erase(--R.end());
		if(AB.is_online(R[0]))
			R.erase(R.begin());

        if(L.empty() or R.empty())
        {
            cout<<0<<endl; continue;
        }
        int l = 0;
        int r = 0;
        LL ans = 0;
        int m = R.size();
        point last = R[m-1]; 

        line ll1(L[0],A);
        line ll2(L[0],B);
        if(ll1.is_online(last) or !(ll1.on_same(B,last)))swap(A,B);
        for(auto p : L)
        {
            while(l<m)
            {

                line ll(p,R[l]);
                if(ll.is_online(A))l++;
                else if(ll.is_online(B))break;
                else if (ll.on_same(A,B)==false)break;
                else
                if(ll.is_online(A) or (ll.is_online(last)==false and ll.on_same(A,last)))
                    l++;
                else break;
            }
            r = max(r,l);
            while(r<m)
            {
                line ll(p,R[r]);
                if(ll.is_online(B)==false and ll.on_same(A,B))r++;
                else break;
            }
            ans += (r-l);
        }
		cout<<ans<<endl;
	}
  return 0;	
}

