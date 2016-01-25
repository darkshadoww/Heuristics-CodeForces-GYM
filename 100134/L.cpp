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

FILE *fin = freopen("labyrinth.in","r",stdin);
FILE *fout = freopen("labyrinth.out","w",stdout);

#define MAXN 1509
int pre[MAXN][MAXN];
int markL[MAXN][MAXN];
int markR[MAXN][MAXN];
int vis[MAXN][MAXN];
int n,m;
string str[MAXN];
int preL[MAXN][MAXN];
int preR[MAXN][MAXN];

int dir1[4]={-1, 0, 1, 0};
int dir2[4]={0, -1, 0, 1};

bool valid(int x, int y){
    if(x<0 or y<0 or x>=n or y>=m or vis[x][y] or str[x][y]=='#')return false;
    return true;
}

int FF[4] = {2,3,0,1};


bool dfs(PII node, int fl){
    vis[node.F][node.S]=1;
    if(node==mp(n-1, m-1)){
        markL[node.F+1][node.S+1]=1;
        return true;
    }
    for(int i=(fl+1)%4; i!=fl; i=(i+1)%4){
        int newx=node.F+dir1[i];
        int newy=node.S+dir2[i];
        if(not valid(newx, newy))continue;
        if(dfs({newx, newy}, FF[i])){
            markL[node.F+1][node.S+1]=1;
            return true;
        }
    }
    return false;
}

bool dfs1(PII node, int fl){
    vis[node.F][node.S]=1;
    if(node==mp(n-1, m-1)){
        markR[node.F+1][node.S+1]=1;
        return true;
    }
    for(int i=(fl-1+4)%4; i!=fl; i=(i-1+4)%4){
        int newx=node.F+dir1[i];
        int newy=node.S+dir2[i];
        if(not valid(newx, newy))continue;
        if(dfs1({newx, newy}, FF[i])){
            markR[node.F+1][node.S+1]=1;
            return true;
        }
    }
    return false;
}

int sum(int ar[][MAXN], int x1, int y1, int x2, int y2){
    return ar[x2][y2]-ar[x1-1][y2]-ar[x2][y1-1]+ar[x1-1][y1-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for(int i=0; i<n; i++)
        cin >> str[i];
    dfs({0, 0}, 0);
    memset(vis, 0, sizeof(vis));

    dfs1({0, 0}, 0);

    str[0][0]=str[n-1][m-1]='#';

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            preL[i][j]=preL[i-1][j] + preL[i][j-1] - preL[i-1][j-1] + markL[i][j];
            preR[i][j]=preR[i-1][j] + preR[i][j-1] - preR[i-1][j-1] + markR[i][j];
            pre[i][j]=pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            if(str[i-1][j-1]=='#')pre[i][j]++;
        }


    /*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
            cout << markL[i][j];
        cout << endl;
    }
    cout << "---------\n";

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
            cout << markR[i][j];
        cout << endl;
    }
    cout << "---------\n";
    */
    int ans=INT_MAX,ansx,ansy;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            int l=0,r=min(n-i+1, m-j+1),mid, x2, y2;
            while(r-l>1){
                mid=(r+l)/2;
                x2=i+mid-1,y2=j+mid-1;
                if(sum(preL, i, j, x2, y2) and sum(preR, i, j, x2, y2))r=mid;
                else l=mid;
            }
            
            x2=i+l,y2=j+l;

            int p=sum(preL, i, j, x2, y2);
            int q=sum(preR, i, j, x2, y2);
            int rr=sum(pre, i, j, x2, y2);

//            trace(i, j, x2, y2, p, q, rr);

            if(p==0 or q==0 or rr>0)continue;

            if(l+1<ans)
                ans=l+1, ansx=i, ansy=j;
        }

    if(ans==INT_MAX)
        printf("Impossible\n");
    else{
        cout << ans << " " << ansy << " " << ansx << endl;
    }
    return 0;
}


