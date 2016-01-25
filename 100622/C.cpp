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

FILE *fin = freopen("circles.in","r",stdin);
FILE *fout = freopen("circles.out","w",stdout);


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

PII f(int xc, int yc, int r, int w, int h, int y){
    assert(y>=0 and y<h and y>=yc-r and y<=yc+r);
    int d = abs(y-yc);
    int x = sqrt(r*r-d*d);
    return {xc-x, xc+x};
}


int get(set<PII> & ar, int w){
    int ret=0, maxtill=-1;
    for(auto i: ar){
        if(i.S<0)continue;
        if(i.F>=w)continue;

        if(i.F<0)i.F=0;
        if(i.S>=w)i.S=w-1;
        
        if(i.F>i.S)continue;

        maxtill = max(maxtill, i.F-1);

        if(i.S > maxtill){
            ret += i.S-maxtill;
            maxtill = i.S;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    int w, h, n, x, y, r;
    cin  >> w >> h >> n;
    set <  PII >  mark[40000];
    for(int i = 0; i < n; i ++){
        cin >> x >> y >> r;
        for(int j = max(0, y-r); j < min(h, y+r+1); j++)
            mark[j].insert(f(x, y, r, w, h, j));
    }

    int ans=0;


    for(int i = 0; i < h; i ++){
        ans += w-get(mark[i], w);
    }
    cout << ans << endl;
    return 0;
}

