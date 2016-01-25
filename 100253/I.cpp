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

vector<PII> A[3];
int a,b;
vector<PII> B;

void print(int S[3])
{
    int total = 0;
    int ca = 1; int cb = a+1;
    for(int i =0; i<3; i++)
        for(int j =0; j<S[i]; j++)
            total += A[i][j].F;
    cout<<S[0] + S[1] + S[2]<<" "<<total<<endl;
    for(int i =0; i<3; i++)
        for(int j =0; j<S[i]; j++)
        {
            cout<<A[i][j].S<<" ";
            if(i==0){cout<<ca++<<endl;}
            if(i==1){cout<<cb++<<endl;}
            if(i==2)
            {
                if(ca<=a)
                    cout<<ca++<<endl; else cout<<cb++<<endl;
            }
        }
}

int main()
{
    int n;
    cin>>n>>a>>b;
    for(int i =0; i<n; i++)
    {
        int ty,p;
        cin>>ty>>p;
        A[ty-1].PB(MP(p,i+1));
    }
    for(int i=0; i<3; i++)sort(A[i].begin(),A[i].end());

    if(A[0].size()>a)A[0].resize(a);
    if(A[1].size()>b)A[1].resize(b);

    int ta = A[0].size();
    int tb = A[1].size();
    int tall = A[2].size();
    
    int mxloose = max(0,(ta+tb+tall)-(a+b));

    int mna = 0; mna = max(0,(a+b) - (tb+tall));
    int mnb = 0; mnb = max(0,(a+b) - (ta+tall));
    int mxa = a - mna; 
    int mxb = b - mnb; 

    for(int i =0; i<3; i++)
        for(auto c : A[i])
            B.PB(MP(c.F,i));
    sort(B.begin(),B.end());

    int S[3] = {};
    int N = ta+tb+tall;
    for(int i = N-1; i>=0; i--)
    {
        if(mxloose>0)
        {
            if(B[i].S==2)
            {
                mxloose--;
                continue;
            }
            if(B[i].S==0)
            {
                if(mxa>0)
                {
                    mxa--; 
                    mxloose--;
                }
                else
                {
                    S[B[i].S]++; 
                }
            }
            else
            {
                if(mxb>0)
                {
                    mxb--; 
                    mxloose--;
                }
                else
                {
                    S[B[i].S]++;
                }
            }
        }
        else
        {
            S[B[i].S]++;
        }
    }
    print(S);
    return 0;
}


