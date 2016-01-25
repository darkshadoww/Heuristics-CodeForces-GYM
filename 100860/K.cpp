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


int A[100][100][100];
int N,M; 

int R[100][100]; 
void mul(int C[][100], int A[][100], int B[][100])
{
    for(int i =0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            R[i][j] = 0;
            for(int k = 0; k<N; k++)
                R[i][j] += A[i][k]* B[k][j];
        }
    }
    for(int i =0; i<N; i++) for(int j =0; j<N; j++) C[i][j] = R[i][j];
}



int main()
{
    si(N); si(M); while(M--){
        int x,y; si(x); si(y); x--; y--; A[0][x][y] = A[0][y][x] = 1; 
    }
    printf("%d ",N);
    for(int l = 1; l<N; l++)
    {
        int ans =0;
        for(int i = 0; i<N; i++)
            for(int j = 0; j<N; j++)
                ans += A[l-1][i][j];
        printf("%d ",ans);
        mul(A[l],A[l-1],A[0]);
    }
    printf("\n");
    return 0;
}

