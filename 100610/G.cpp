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

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define DRT()  int t; cin>>t; while(t--)

#ifdef ONLINE_JUDGE
FILE *fin = freopen("gadgets.in","r",stdin);
FILE *fout = freopen("gadgets.out","w",stdout);
#endif

#define EPS 1e-13

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

pair <long double, long double> get_min( LL a, LL b, LL c, LL l, LL r)
{
    long double mid = -b/(2*((long double)a));
    if(mid > l && mid < r)
        return {a*mid*((long double)mid) + b*((long double)mid) + c, mid};

    if(a*l*((long double)l) + b*((long double)l) + c < a*r*((long double)r) + b*((long double)r) + c)
        return {a*l*((long double)l) + b*((long double)l) + c, l};
    return {a*r*((long double)r) + b*((long double)r) + c, r};
}

int main()
{
    int N,M;
    cin>>N>>M;
    vector <set<int> > v(N);
    for(int i=0; i<M; i++)
    {
        int a,b;
        cin>>a>>b;
        a = (a+100001)*2;
        v[b-1].insert(a);
    }
    map<int, vector<int> > m;
    for(int i=0; i<N; i++)
    {
        int prev=-1;
        for(auto it : v[i])
        {
            m[it];
            if(prev!=-1)
                m[(it-prev)/2 + prev].PB(i);
            prev = it;
        }
    }

    long long int a=0, b=0, c=0;
    for(int i=0; i<N; i++)
    {
        int first = *(v[i].begin());
        a+= 1;
        c+= ((LL)first)*(first);
        b-= 2*first;
    }
    int beg = 0;
    int end = 2*1000009;
    if(!m.empty())
        end = m.begin()->F;

    long double ans;
    set <long double> ans_vector;
    auto cur = get_min(a,b,c,beg,end);
    ans = cur.F;
    ans_vector.clear();
    ans_vector.insert(cur.S);

    for(auto it = m.begin(); it!=m.end(); it++)
    {
        for(auto x : it->S)
        {
            auto nw = v[x].lower_bound(it->F);
            c+=((LL)*nw)*(*nw);
            b-=2*(*nw);
            nw--;
            c-=((LL)*nw)*(*nw);
            b+=2*(*nw);
        }
            beg = end;
            auto tmp = it;
            tmp++;
            if(tmp == m.end())
                end = 2*1000009;
            else
                end = tmp->F;
            auto cur = get_min(a,b,c,beg,end);
            if(cur.F < ans )
            {
                ans = cur.F;
                ans_vector.clear();
                ans_vector.insert(cur.S);
            }
            else if(fabs(cur.F - ans) < 1e-13)
            {
                ans_vector.insert(cur.S);
            }
        
    }

    cout<<ans_vector.size()<<endl;
    cout<<fixed<<setprecision(7);
    for(auto it : ans_vector)
        cout<<(it/2)-100001<<endl;

    return 0;
}

