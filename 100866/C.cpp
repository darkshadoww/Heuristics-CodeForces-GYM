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
//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

const double EPS = 1e-12;

void check(long double xlim, long double xnew, long double vx, long double ynew, long double vy, long double ylim1, long double ylim2, vector<long double>& t)
{
    if(vx==0) return;
    long double tim = (xlim - xnew)/vx;
    long double yc = ynew + vy*tim;
    if( not (yc < ylim1-EPS or yc > ylim2+EPS))
        t.PB(tim);
}

typedef long double LDD;

struct line
{
    long double x, vx, y, vy, t1, t2;
    line(LDD x_, LDD vx_, LDD y_, LDD vy_, LDD t1_, LDD t2_)
        : x(x_), vx(vx_), y(y_), vy(vy_), t1(t1_), t2(t2_)
    {}
};

pair<bool, long double> check2(line A, line B)
{
    long double t1,t2;
    t1 = max(A.t1, B.t1);
    t2 = min(A.t2, B.t2);
    if(t1>t2 + EPS)
        return {false, 0};
    long double a,b,c;
    a = (A.vx-B.vx)*(A.vx-B.vx) + (A.vy-B.vy)*(A.vy-B.vy);
    b = 2*((A.vx-B.vx)*(A.x-B.x) + (A.vy-B.vy)*(A.y-B.y));
    c = (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
    long double chkt = -1*(b/(2*a));
    if(chkt>=t1 && chkt<=t2)
        return {true, a*chkt*chkt + b*chkt + c};
    return {true, min((a*t1*t1+b*t1+c),(a*t2*t2+b*t2+c))};
}


vector <line> v;

int main()
{
    long double xl,yl,xr,yr;
    cin>>xl>>yl>>xr>>yr;
    if(xl>xr) swap(xl,xr);
    if(yl>yr) swap(yl,yr);
    int N;
    cin>>N;
    for(int n=0; n<N; n++)
    {
        long double x,y,v_x,v_y;
        cin>>x>>y>>v_x>>v_y;
        vector<long double> t;
        if(v_x==0 && v_y==0)
        {
            if(x>=xl-EPS && x<=xr+EPS && y>=yl-EPS && y<=yr+EPS)
                v.emplace_back(x,v_x,y,v_y,0,1e11);
            continue;
        }
        check(xl,x,v_x,y,v_y,yl,yr,t);
        check(xr,x,v_x,y,v_y,yl,yr,t);
        check(yl,y,v_y,x,v_x,xl,xr,t);
        check(yr,y,v_y,x,v_x,xl,xr,t);
        sort(t.begin(), t.end());
        if(t.size()==0)
            continue;
        if(t.back()< -EPS) continue;
        if(t.size()==1)
        {
            v.emplace_back(x,v_x,y,v_y,t[0],t[0]);
            continue;
        }
        if(t[0]<EPS)t[0]=0;
        v.emplace_back(x,v_x,y,v_y,t[0],t.back());
    }
    bool ans_e = false;
    long double ans;
    for(int i=0; i<v.size(); i++)
    {
        //trace(v[i].x, v[i].y, v[i].vx, v[i].vy, v[i].t1, v[i].t2);
        for(int j=i+1; j<v.size(); j++)
        {
            if(i!=j)
            {
                auto cur = check2(v[i], v[j]);
                if(cur.F)
                {
                    if(!ans_e)
                        ans = cur.S;
                    else
                        ans = min(ans, cur.S);
                    ans_e = true;
                }
            }
        }
    }
    if(ans_e)
        cout<<fixed<<setprecision(20)<<sqrt(ans)<<endl;
    else
        cout<<"inf"<<endl;
    return 0;
}

