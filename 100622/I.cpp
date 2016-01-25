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

FILE *fin = freopen("image.in","r",stdin);
FILE *fout = freopen("image.out","w",stdout);


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

int d, h, w;
int color[10][10];
int dp[10][10][1<<10];
VI go[10][10][1<<10];

int dist(int a, int b, int c, int d){
    return abs(a-c)+abs(b-d);
}

int rec(int curx, int cury, int mask){
    if(__builtin_popcount(mask) <= 1)
        return 0;

    int &mindist=dp[curx][cury][mask];
    if(mindist!=-1)return mindist;
    mindist = INT_MAX;

    for(int i = 0; i<h; i++)
        for(int j = 0; j<w; j++){
            int p = mask&color[i][j];
            if(p != mask and p!=0){
                int calc = dist(curx, cury, i, j) + max(rec(i, j, p), rec(i, j, mask-p));
                if(calc<mindist){
                    if(go[curx][cury][mask].empty())
                        go[curx][cury][mask].resize(4);
                    go[curx][cury][mask][0]=i;
                    go[curx][cury][mask][1]=j;
                    go[curx][cury][mask][2]=p;
                    go[curx][cury][mask][3]=mask-p;
                    mindist = calc;
                }
            }
        }
    return mindist;
}

string getpath(int a, int c, int b, int d){
    string ret="";
    if(a<b)
        for(int i=0; i<b-a; i++)
            ret += "D";
    if(a>b)
        for(int i=0; i<a-b; i++)
            ret += "U";
    if(c<d)
        for(int i=0; i<d-c; i++)
            ret += "R";
    if(c>d)
        for(int i=0; i<c-d; i++)
            ret += "L";
    return ret;
}

string build(int curx, int cury, int mask){
    if(__builtin_popcount(mask) <= 1){
        string ret="";
        for(int i = 0; i<d; i++)
            if(mask&(1<<i))
                ret += to_string(i);
        return ret;
    }

    VI rett = go[curx][cury][mask];
    string ret = getpath(curx, cury, rett[0], rett[1]);
    string left = build(rett[0],rett[1],rett[2]);
    string right = build(rett[0],rett[1],rett[3]);

    return ret+'('+left+':'+right+')';
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> d >> h >> w;
    for(int i = 0; i < d; i ++){
        string str;
        for(int j = 0; j < h; j++){
            cin >> str;
            for(int k = 0; k < w; k ++)
                if(str[k]=='W')
                    color[j][k] |= (1<<i);
        }
    }

    rec(0, 0, (1<<d)-1);
    cout << build(0, 0, (1<<d)-1) << endl;
    return 0;
}

