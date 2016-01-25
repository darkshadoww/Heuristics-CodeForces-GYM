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


int C[10001];
char rM[10001];
string CR;
map<char,int> M;


void g(int val, int th)
{
    if(val<=3){  while(val--) CR += rM[th]; return;}
    if(val==4){ CR+=rM[th]; CR+=rM[5*th];return; }
    if(val<=8){ CR+=rM[5*th];int rem = val-5; while(rem--) CR += rM[th];return; }
    if(val==9){ CR += rM[th]; CR += rM[10*th];}
}
bool valid(string CR)
{
    map<int,int> CC;
    for(auto c : CR)
        CC[M[c]]++;
    for(auto c : CC)
        if(C[c.F] < c.S)return false;
    return true;
}

int main()
{
    M['I'] = 1;
    M['V'] = 5;
    M['X'] = 10;
    M['L'] = 50;
    M['C'] = 100;
    M['D'] = 500;
    M['M'] = 1000;
    rM[10000] = 'T';
    rM[5000] = 'T';
    rM[1000] = 'M';
    rM[500] = 'D';
    rM[100] = 'C';
    rM[50] = 'L';
    rM[10] = 'X';
    rM[5] = 'V';
    rM[1] = 'I';
    string A; cin>>A;
    for(auto c : A)
    {
        if(c>='a' and c<='z')
            c += 'A'-'a';
        if(M.count(c))
            C[M[c]]++;
    }
    string ANS = "";
    for(int i = 3999;i>0; i--)
    {
        int x = i;
        int one = x%10; x/=10;
        int two = x%10; x/=10;
        int three = x%10; x/=10;
        int fr = x%10; x/=10;
        CR = "";
        g(fr,1000); g(three,100); g(two,10); g(one,1);
        if(CR.length() > ANS.length() and valid(CR))
            ANS = CR;
    }
    cout<<ANS<<endl;
    return 0;
}

