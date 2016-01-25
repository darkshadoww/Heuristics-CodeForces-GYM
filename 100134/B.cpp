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

LL n,c,B,prevB,ans = 0, ansbit;
vector < LL > weight;
map < LL, int > weno;

void solve(){
    for(int i=0; i<(1<<n); i++){
        LL cur=0;
        for(int j=0; j<n; j++)
            if((i&(1<<j)))
                cur += weight[j];
        if(cur<=c){
            if(cur > ans)
                ans = cur, ansbit=i;
        }
    }
    for(int i=0; i<n; i++)
        if((ansbit&(1<<i)))
            weno[weight[i]]++;
}

void AC(){
    cout << "accept" << endl;
    fflush(stdout);
}

void DC(){
    cout << "decline" << endl;
    fflush(stdout);
}

void STOP(){
    cout << "stop" << endl;
    fflush(stdout);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> c >> prevB;
    AC();
    while(prevB>0)
    {
        cin >> B;
        if(B==c){STOP(); return 0;}
        if(B < prevB){
            AC();
            prevB = B;
        }
        else{
            DC();
        }
    }
    while(weight.size()<n)
    {
        cin >> B;
        if(B==c){STOP(); return 0;}
        if(B > prevB){
            AC();
            weight.pb(B-prevB);
            prevB = B;
        }
        else{
            DC();
        }
    }
    solve();
    c = ans; 
    while(prevB>0)
    {
        cin>>B; 
        if(B==c){STOP(); return 0;}
        if(B<prevB){AC();prevB = B;}
        else DC();
    }
    while(1)
    {
        cin >> B;
        if(B==c){STOP(); return 0;}
        if(B > prevB){
            LL diff = B - prevB;
            if(weno[diff]){
                weno[diff]--;
                AC();
            prevB = B;
            }
            else
                DC();
        }
        else{
            DC();
        }
    }
    return 0;
}


