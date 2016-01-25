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



// 0.  1
// 1.  2
// 2.  3
// 3.  4

// 6.  s5
// 7.  s6
// 8.  s7
// 9.  s8
// 10. s9
// 11. s10
// 12. s11
// 13. s12
// 14. s13

unordered_map<long long,int> P;
unordered_map<LL,int> DP;


LL statetoll(int A[13])
{
    LL ret = 0;
    for(int i =12; i>=0; i--)
        ret = ret*8 + A[i];
    return ret;
}

void lltostate(LL m, int A[13])
{
    for(int i = 0; i<13; i++)
    {
        A[i] = (m&7); m/=8;
    }
}

int get_i(LL x, int i)
{
    x>>=(3*i);
    return (x&7);
}

LL set_i(LL x, int i, int val)
{
    LL cp = x & (  (1ll<<(3*i))-1 );
    x >>= (3*(i+1));
    x = (x<<3) + val;
    x = x<<(3*i) + cp;
    return x;
}

inline void dec_i(LL &x, int i, int cnt)
{
    x -=  cnt * (1ll<<(3*i));
}

bool is_valid(LL state, int i, int mv)
{
    if(mv<4)
    {
        mv++;
        return get_i(state,i) >= mv;
    }
    else if(mv==4)
    {
        return i+1<=12 and get_i(state,i)>=2 and get_i(state,i+1)>=3;
    }
    else if(mv==5)
    {
        return i+1<=12 and get_i(state,i)>=3 and get_i(state,i+1)>=2;
    }
    else if(mv<15)
    {
        mv--;
        if(i+mv>13)return false;
        while(mv--)
            if(get_i(state,i++)==0)return false;
        return true;
    }
    else
    {
        int j
    }
}

LL get_nw(LL state, int i, int mv)
{
    if(mv<4)
    {
        dec_i(state,i,mv+1); 
    }
    if(mv==4)
    {
        dec_i(state,i,2);
        dec_i(state,i+1,3);
    }
    if(mv==5)
    {
        dec_i(state,i,3);
        dec_i(state,i+1,2);
    }
    if(mv>=6)
    {
        mv--;
        while(mv--)
            dec_i(state,i++,1);
    }
    return state;
}

int dp(LL state)
{
    if(DP.count(state))return DP[state];
    int &ret = DP[state];
    ret = 14;
    int i =0;
    while(get_i(state,i)==0)i++;
    
    LL nstate = state;
    dec_i(nstate,i,1);
    ret = 1 + dp(nstate);
    P[state] = 0;
    
    for(int mv = 1; mv<15; mv++)
    {
        if(is_valid(state,i,mv))
        {
            LL nstate = get_nw(state,i,mv);
            int ndp = 1 + dp(nstate); if(ndp<ret){ret = ndp; P[state] = mv;}
        }
    }
    return ret;
}

map<char,int> M;
int main()
{
    M['2'] = 0; M['3'] = 1; M['4'] = 2; M['5'] = 3; M['6'] = 4; M['7'] = 5; M['8'] = 6; M['9'] = 7; 
    M['T'] = 8;
    M['J'] = 9;
    M['Q'] = 10;
    M['K'] = 11;
    M['A'] = 12;
    int t; si(t); while(t--)
    {
        DP[0] = 0;
        LL state  = 0;
        for(int i =0; i<13; i++)
        {
            string ch; cin>>ch;
            int x = M[ch[0]];
            state += (1ll<<(3*x));
        }
        int A[13];
        lltostate(state,A);
        for(int i = 0; i<13; i++)trace(i,A[i]);
        cout<<dp(state)<<endl;
        while(state>0)
        {
            int mv = P[state];
            trace(mv);
            int i = 0; while(get_i(state,i)==0)i++;
            state = get_nw(state,i,mv);
        }
    }
    return 0;
}
