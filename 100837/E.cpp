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

//FILE *fin = freopen("e.in","r",stdin);
//FILE *fout = freopen("e.out","w",stdout);

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


int C[65];
string xtoa(int x)
{
    string a = "";
    while(x)
    {
        a = (char)(x%10 + '0')  +a;
        x/=10;
    }
    return a;
}

int main()
{
    string A;
    cin>>A;
    int N = A.size();
    for(int i =0; i<N; i++)
    {
        if(A[i]=='R')
        {
            int j = i+1;
            while(j<N and A[j]!='R')j++;
            int dc =0;
            int num = 0;
            j--;
            while(A[j]=='.'){dc++; j--;}
            if(j==i+1)
                num = A[j]-'0';
            else
                num = (A[i+1]-'0')*10 + (A[j]-'0');
            C[num]++;
            while(dc--)
            {
                num*=2; C[num]++;
            }
        }
    }
    int cr = 64;
    while(cr>1)
    {
        C[cr/2] += C[cr] / 2;
        C[cr] &= 1;
        cr/=2;
    }
    vector<string> TP;
    while(C[1]>1)
    {
        C[1]--;
        TP.PB("R1a");
    }
    int last = -1;
    int cnt;
    for(int cr = 1; cr<=64; cr*=2)
    {
        if(C[cr]==0)
        {
            last = -1; continue;
        }
        if(last==-1){last = cr; cnt = 0;}else cnt++; 
        if(cr==64 or C[cr*2]==0)
        {
            string nw = "R"; 
            nw += xtoa(last);
            while(cnt--)nw+='.'; 
            TP.PB(nw+'a');
        }
    }
    sort(TP.begin(), TP.end());
    for(auto &s : TP) for(int i = 0; i<s.length()-1; i++) cout<<s[i];
    cout<<endl;
    return 0;
}


