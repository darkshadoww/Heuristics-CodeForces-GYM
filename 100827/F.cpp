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

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

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

#define MOD 1000000009ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

int m;
LL bs[1<<8];

bool check(int m1, int m2){
    if(bs[m1]==0 or bs[m2]==0)return false;
    int k = m;
    int rem = ((1<<k) - 1) & m1;
    rem<<=k;
    if((m2>>k)==(rem>>k))
    {
        int na = 0;
        for(int i = 0; i<k; i++)
        {
            if((m1>>i)&1)
            {
                int ni = i-2;
                if(ni>=0 and ni<k)
                    na |= (1<<ni);
                ni = i+2;
                if(ni>=0 and ni<k)
                    na |= (1<<ni);
            }
        }
        for(int i = k; i<2*k; i++)
        {
            if((m1>>i)&1)
            {
                int ni = i-k-1;
                if(ni>=0 and ni<k)
                    na |= (1<<ni);
                ni = i-k+1;
                if(ni>=0 and ni<k)
                    na |= (1<<ni);
            }
        }
        if(na & m2)return false;
        return true;
    }
    return false;
}

typedef vector<vector<LL> > matrix;

matrix mul(matrix A, matrix B)
{
    int K=A.size();
    matrix C(K, vector<LL>(K, 0));
    for(int i=0; i<K; i++)
        for(int j=0; j<K; j++)
            for(int k=0; k<K; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

matrix poww(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, poww(A, p-1));
    matrix X = poww(A, p/2);
    return mul(X, X);
}

bool val(int mask)
{
    int k = m;
    for(int i = 0; i<k; i++)
        if( (mask>>i) & 1)
        {
            int ni = i-2; 
            if(ni>=0 and ni<k and ((mask)>>(k+ni))&1)return false;
            ni = i+2;
            if(ni>=0 and ni<k and ((mask)>>(k+ni))&1)return false;
        }
    return true;
}

int main()
{
    int t;
    sd(t);
    while(t--){
        int n,siz;
        LL ans=0;
        sd(m),sd(n);
        siz=(1<<(2*m));
        for(int i = 0; i<siz; i++)
            if(val(i)) bs[i] = 1; else bs[i] = 0;
        vector< vector<LL > > mat(siz, vector<LL>(siz, 0));
        for(int i=0; i<(1<<(2*m)); i++)
            for(int j=0; j<(1<<(2*m)); j++)
                if(bs[i] and bs[j] and check(i, j))mat[i][j]=1;


        matrix p=poww(mat, n);        for(int i = 0; i<siz; i++)
        {
            ans += p[0][i]; if(ans>=MOD)ans-=MOD;
        }
        cout << ans << endl;
    }
    return 0;
}


