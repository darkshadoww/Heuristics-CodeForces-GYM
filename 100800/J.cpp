#ifdef __APPLE__
#include<cassert>
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<sstream>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

#else

#include<bits/stdc++.h>

#endif  // __APPLE__

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
#define REP(i,a,b) for(int i = (int)a; i < (int)b; i++)


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

PII st,ed;
VPII P[209];
int L[209];
const int T=120;
bool valid[60][60][T];
bool valid2[60][60][T];
bool visited[60][60][T];
string str[60];

PII f(int i, int t)
{
    if(L[i]==1)return P[i][0];
    t%=(2*L[i]-2);
    if(t>=L[i])t=2*L[i]-2-t;
    return P[i][t];
}

int N,M,p;

void gen(){
    memset(valid,true,sizeof(valid));
    memset(valid2,true,sizeof(valid2));
    for(int i=0; i<T; i++)
        for(int j=0; j<p; j++)
        {
            PII x=f(j,i);
            valid[x.F][x.S][i]=false;
        }
    for(int t = 0; t<T; t++)
    {
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
            {
                if(valid[i][j][t]==false)
                {
                    for(int k=i+1; k<N; k++)
                    {
                        if(str[k][j]=='#')break;
                        valid2[k][j][t]=false;
                    }
                    for(int k=i-1; k>=0; k--)
                    {
                        if(str[k][j]=='#')break;
                        valid2[k][j][t]=false;
                    }
                    for(int k = j+1; k<M; k++)
                    {
                        if(str[i][k]=='#')break;
                        valid2[i][k][t] = false;
                    }
                    for(int k = j-1; k>=0; k--)
                    {
                        if(str[i][k]=='#')break;
                        valid2[i][k][t] = false;
                    }
                }
            }
        for(int i =0; i<N; i++)
            for(int j = 0; j<M; j++)
                if(valid2[i][j][t]==false)
                {
                    valid[i][j][t]=false;
                }
    }
}

bool foo(int x, int y, int t)
{
    if(x>=N or x<0 or y>=M or y<0)return false;
    if(visited[x][y][t] or valid[x][y][t]==false or str[x][y]=='#')return false;
    visited[x][y][t]=true;
    return true;
}

struct node{
    int x,y,t,ans;
    node(int x_, int y_, int t_, int ans_): x(x_), y(y_), t(t_), ans(ans_) {}
};

int main()
{
    int dir1[4] = {-1,0,0,1};
    int dir2[4] = {0,-1,1,0};
    si(N); si(M);
    scanf(" (%d %d) ",&st.F,&st.S);
    scanf(" (%d %d) ",&ed.F,&ed.S);
    if(st==ed){cout << 0 << endl; return 0;}
    st.F--;st.S--;
    ed.F--;ed.S--;
    for(int i=0; i<N; i++)
        cin >> str[i];
    si(p);
    for(int i=0; i<p; i++)
    {
        cin >> L[i];
        P[i].resize(L[i]);
        for(int j=0; j<L[i]; j++)
        {
            scanf(" ( %d %d ) ",&P[i][j].F,&P[i][j].S);
            P[i][j].F--;
            P[i][j].S--;
        }
    }
    gen();
    node cur(st.F,st.S,0,0);
    visited[st.F][st.S][0]=true;
    queue < node > myq;
    myq.push(cur);
    while(not myq.empty()){
        node p=myq.front();
        myq.pop();
        int newt=p.t+1;
        int newans=p.ans+1;
        if(newt==T){
            assert(2>1);
            newt=0;
        }

        if(foo(p.x,p.y,newt))
            myq.push(node(p.x,p.y,newt, newans));

        for(int i=0; i<4; i++)
        {
            int newx,newy;
            newx=p.x+dir1[i];
            newy=p.y+dir2[i];
            if(newx==ed.F and newy==ed.S){
                printf("%d\n",newans);
                return 0;
            }
            if(foo(newx,newy, newt))
                myq.push(node(newx, newy, newt, newans));
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;	
}
