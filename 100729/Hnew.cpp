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


unordered_map<long long,LL> P;
unordered_map<LL,int> DP;


int get_i(LL x, int i)
{
    x>>=(3*i);
    return (x&7);
}
LL dec_i(LL x, int i, int cnt)
{
    x -=  cnt * (1ll<<(3*i));
    return x;
}

int dp(LL state)
{
    if(DP.count(state))return DP[state];
    int &ret = DP[state];
    ret = 14;
    int i = 0;
    LL pstate;
    while(get_i(state,i)==0)i++;

    //same card used
    int p=get_i(state, i);
    for(int j=1; j<=p; j++){
        LL nstate=dec_i(state, i, j);
        LL newval=1 + dp(nstate);
        if(newval<ret)
            ret=newval, pstate=nstate;
    }

    //full house:  i has 3, j has 2
    if(p>=3){
        for(int j=i+1; j<13; j++){
            if(get_i(state, j)>=2){
                LL nstate=dec_i(state, i, 3);
                nstate=dec_i(nstate, j, 2);
                LL newval=1 + dp(nstate);
                if(newval<ret)
                    ret=newval, pstate=nstate;
            }
        }
    }

    //full house:  i has 2, j has 3
    if(p>=2){
        for(int j=i+1; j<13; j++){
            if(get_i(state, j)>=3){
                LL nstate=dec_i(state, i, 2);
                nstate=dec_i(nstate, j, 3);
                LL newval=1 + dp(nstate);
                if(newval<ret)
                    ret=newval, pstate=nstate;
            }
        }
    }

    //straight, starting from i
    LL nstate=dec_i(state, i, 1);
    for(int j=i+1; j<13; j++){
        if(get_i(state, j)==0)break;
        nstate=dec_i(nstate, j, 1);
        if(j-i+1>=5){
            LL newval=1 + dp(nstate);
            if(newval<ret)
                ret=newval, pstate=nstate;
        }
    }

    P[state]=pstate;
    return ret;
}

map<char,int> M;
vector<string> CARD[13];

void print(LL state, LL nstate)
{
    LL dec = state - nstate;

    for(int i =0; i<13; i++)
    {
        int cnt = get_i(dec,i);
        while(cnt--)
        {
            cout<<CARD[i].back()<<" "; CARD[i].pop_back();
        }
    }
    cout<<endl;

}

int main()
{
    M['2'] = 0; M['3'] = 1; M['4'] = 2; M['5'] = 3; M['6'] = 4; M['7'] = 5; M['8'] = 6; M['9'] = 7; 
    M['T'] = 8;
    M['J'] = 9;
    M['Q'] = 10;
    M['K'] = 11;
    M['A'] = 12;
    DP[0] = 0;
    int t; si(t); while(t--)
    {
        for(int i =0; i<13; i++) CARD[i].clear();
        LL state  = 0;
        for(int i =0; i<13; i++)
        {
            string ch; cin>>ch;
            int x = M[ch[0]];
            CARD[x].PB(ch);
            state += (1ll<<(3*x));
        }
        cout<<dp(state)<<endl;
        while(state>0)
        {
            LL nstate = P[state];
            print(state, nstate);
            state = nstate;
        }
    }
    return 0;
}
