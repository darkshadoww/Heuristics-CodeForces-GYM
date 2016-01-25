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

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;


string S[500];
int N,M;
int mp[500][500];

bool is_w(int i, int j)
{
    if(i<0 or j<0 or i>=N or j>=M)return false;
    return S[i][j]=='W';
}
bool is_b(int i, int j)
{
    if(i<0 or j<0 or i>=N or j>=M)return false;
    return S[i][j]=='B';
}

VI E[500000];
VI rE[500000];
int C[500000];
VI tord;
bool V[500000];

void implies(int a, int b)
{
    trace(a,b);
    E[a].PB(b);
    rE[b].PB(a);
    if(a%2==0)a++; else a--;
    if(b%2==0)b++; else b--;
    E[b].PB(a);
    rE[a].PB(b);
}
void dfs(int x)
{
    if(V[x])return; V[x] = true;
    for(auto y : E[x])dfs(y); tord.PB(x);
}
void dfs(int x, int cn)
{
    if(C[x])return; C[x] = cn;
    for(auto y : rE[x])dfs(y,cn);
}

bool tSAT(int n)
{
    for(int i = 0; i<n; i++){C[i] = 0;V[i] = false;}
    tord.clear();
    for(int i =0; i<n; i++)
        if(V[i]==false)
            dfs(i);
    int cn = 0;
    reverse(tord.begin(),tord.end());
    for(auto x : tord)
        if(C[x]==0)
        {
            cn++;
            dfs(x,cn);
        }
    for(int i = 0; i<n; i++){E[i].clear();rE[i].clear();}
    for(int i = 0; i<n; i+=2)
        if(C[i]==C[i+1])return false; return true;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>N>>M;
        for(int i =0; i<N; i++) cin>>S[i];
        int CB = 0;
        int CW = 0;
        int c =0;
        for(int i =0; i<N; i++)
            for(int j =0; j<M; j++)
            {
                CB += (S[i][j]=='B');
                if(S[i][j]=='B')mp[i][j] = c++;
                CW += (S[i][j]=='W');
            }
        trace(N,M,CB,CW);
        bool can = true;
        if(CW != 2*CB)can = false;
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<M; j++)
            {
                if(S[i][j]=='B')
                {
                    if(  is_w(i-1,j)==false and is_w(i+1,j)==false)
                        can = false;
                    if(  is_w(i,j-1)==false and is_w(i,j+1)==false)
                        can = false;
                }
                if(S[i][j]=='W')
                    if(  is_b(i-1,j)==false and is_b(i+1,j)==false and is_b(i,j-1)==false and is_b(i,j+1)==false)
                        can = false;
            }
        }
        if(can==false)
            {cout<<"NO\n"; continue;}
        int n = 4*c;
        trace(CW,CB,n);
        for(int i =0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(S[i][j]=='B')
                {
                    // right is white.
                    if(is_w(i,j+1))
                    {
                        // upper.
                        if(is_b(i-1,j+1))
                            implies(4*mp[i][j] +2, 4*mp[i-1][j+1] + 0);
                        // right.
                        if(is_b(i,j+2))
                            implies(4*mp[i][j]+2, 4*mp[i][j+2]+2);
                        // down
                        if(is_b(i+1,j+1))
                            implies(4*mp[i][j]+2, 4*mp[i+1][j+1]+1);
                    }
                    //down is white
                    if(is_w(i+1,j))
                    {
                        // right black
                        if(is_b(i+1,j+1))
                            implies(4*mp[i][j]+1,4*mp[i+1][j+1]+2);
                        // down is black
                        if(is_b(i+2,j))
                            implies(4*mp[i][j]+1, 4*mp[i+2][j]+1);
                    }
                    // left is white
                    if(is_w(i,j-1))
                    {
                        //down black
                        if(is_b(i+1,j-1))
                            implies(4*mp[i][j]+3,4*mp[i+1][j-1]+1);
                    }
                }
            }
        }
        if(tSAT(n)) cout<<"YES\n"; else cout<<"NO\n";
    }
    return 0;	
}
