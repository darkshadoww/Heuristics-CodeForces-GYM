#include <cstring>
#include <queue>
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

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


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

typedef pair< int , PII> PIII;
typedef vector<PIII> VPIII;

VPIII lines[2];
PII P[4000];
map<PII,int> D;

int main()
{
    int N; si(N);
    for(int i = 0; i<N; i++) cin>>P[i].F>>P[i].S;
    for(int i = 0; i<N-1; i++)
    {
        if(P[i]==P[i+1])continue; // lite
        if(P[i].F==P[i+1].F) // vertical
        {
            int y1 = P[i].S;
            int y2 = P[i+1].S;
            if(y2<y1)swap(y1,y2);
            lines[1].PB(MP(P[i].F , MP(y1,y2)));
        }
        else // horizontal
        {
            int x1 = P[i].F;
            int x2 = P[i+1].F;
            if(x2<x1)swap(x1,x2);
            lines[0].PB(MP(P[i].S , MP(x1,x2)));
        }
    }
    for(int i = 0; i<2; i++)
        sort(lines[i].begin(), lines[i].end());
    int cd = 0;
    int mxl = 4000*20000;
    D[MP(P[0].F,P[0].S)] = 0;
    for(int i = 0; i<N-1; i++)
    {
        if(P[i]==P[i+1])continue; //lite
        // towards right
        if(P[i].S == P[i+1].S and P[i].F < P[i+1].F)
        {
            int y = P[i].S;
            int x = P[i].F; int x2 = P[i+1].F;
            for(auto l : lines[1]) // vertical in increasing x.
            {
                if(l.F>x and l.F<=x2)
                {
                    if(l.S.F <= y and y<=l.S.S)
                    {
                        cd += (l.F - x);
                        x = l.F;
                        if(D.count(MP(x,y)))
                            mxl = min(mxl, cd - D[MP(x,y)]);
                        D[MP(x,y)] = cd;
                    }
                }
            }
            cd += (x2 - x); x = x2;
            D[MP(x,y)] = cd;
        }
        // towards left
        if(P[i].S == P[i+1].S and P[i].F > P[i+1].F)
        {
            // x2<-------x
            int y = P[i].S;
            int x = P[i].F; int x2 = P[i+1].F;
            for(int i = lines[1].size()-1; i>=0; i--)
            {
                PIII l = lines[1][i];
                if(l.F<x and l.F>=x2)
                {
                    if(l.S.F <= y and y<=l.S.S)
                    {
                        cd -= (l.F - x);
                        x = l.F;
                        if(D.count(MP(x,y)))
                            mxl = min(mxl, cd - D[MP(x,y)]);
                        D[MP(x,y)] = cd;
                    }
                }
            }
            cd -= (x2 - x); x = x2;
            D[MP(x,y)] = cd;
        }
        // towards up
        if(P[i].F == P[i+1].F and P[i].S < P[i+1].S)
        {
            int x = P[i].F;
            int y = P[i].S; int y2 = P[i+1].S;
            for(auto l : lines[0]) // horizontal in increasing x.
            {
                if(l.F>y and l.F<=y2)
                {
                    if(l.S.F <= x and x<=l.S.S)
                    {
                        cd += (l.F - y);
                        y = l.F;
                        if(D.count(MP(x,y)))
                            mxl = min(mxl, cd - D[MP(x,y)]);
                        D[MP(x,y)] = cd;
                    }
                }
            }
            cd += (y2 - y); y = y2;
            D[MP(x,y)] = cd;
        }
        // towards down
        if(P[i].F == P[i+1].F and P[i].S > P[i+1].S)
        {
            // x2<-------x
            int x = P[i].F;
            int y = P[i].S; int y2 = P[i+1].S;
            for(int i = lines[0].size()-1; i>=0; i--)
            {
                PIII l = lines[0][i];
                if(l.F<y and l.F>=y2)
                {
                    if(l.S.F <= x and x<=l.S.S)
                    {
                        cd -= (l.F - y);
                        y = l.F;
                        if(D.count(MP(x,y)))
                            mxl = min(mxl, cd - D[MP(x,y)]);
                        D[MP(x,y)] = cd;
                    }
                }
            }
            cd -= (y2 - y); y = y2;
            D[MP(x,y)] = cd;
        }
    }
    mxl = min(mxl,cd);
    cout<<mxl<<endl;
    return 0;	
}
