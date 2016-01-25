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

struct date
{
    int D,M,Y;
    date(int D_, int M_, int Y_)
        : D(D_), M(M_), Y(Y_) {}
    void add_month(int month);
    void refine();
    bool operator < (const date& other)
    {
        if(Y != other.Y)
            return Y < other.Y;
        if(M != other.M)
            return M < other.M;
        return D < other.D;
    }
};

void date::add_month(int month)
{
    M--;
    M+=month;
    Y+=M/12;
    M%=12;
    M++;
    refine();
}

void date::refine()
{
    if(D==31 && !(M==1 || M==3 || M==5 || M==7 || M==8 || M==10 || M==12))
    {
        D=1;
        M++;
    }
    else if(D==30 && M==2)
    {
        D=1;
        M++;
    }
    else if(D==29 && M==2 && !(Y%4==0 && (Y%100!=0 || Y%400==0)))
    {
        D=1;
        M++;
    }
    M--;
    Y+=M/12;
    M%=12;
    M++;
}

int main()
{
    int M,N,K,D,MM,Y;
    scanf("%d %d %d", &M, &N, &K);
    scanf("%2d%*c%2d%*c%4d", &D, &MM, &Y);
    vector<date> v;
    v.emplace_back(0,0,0);
    date cur(1,1,2012);
    for(int i=0; i<K; i++)
    {
        date tmp = cur;
        tmp.add_month(i*N);
        v.PB(tmp);
    }
    date dob(D,MM,Y);
    int cr=0;
    if(K==0)
    {
        date tmp = dob;
        tmp.add_month(60*12);
        printf("%02d.%02d.%4d\n", tmp.D, tmp.M, tmp.Y);
        return 0;
    }
    while(1)
    {
        date tmp = dob;
        tmp.add_month(cr*M + 60*12);
        int it = lower_bound(v.begin(), v.end(), tmp) - v.begin();
        if(it == v.size() || tmp < v[it]) it--;
        //trace(cr , it, tmp.D, tmp.M, tmp.Y, v[it].D, v[it].M, v[it].Y);
        if(it <= cr)
        {
            printf("%02d.%02d.%4d\n", tmp.D, tmp.M, tmp.Y);
            break;
        }
        cr++;
    }
    return 0;
}

