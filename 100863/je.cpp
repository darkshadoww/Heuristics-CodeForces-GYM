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
#define pb push_back
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

int N,W,H;

VPII rect;

void traceVI(VPII ar){
    cout << "-------\n";
    for(auto &i: ar)
        trace(i.F, i.S);
    cout << "-------\n";
}

void merge(VPII& ar){
    VPII ret;
    ret.pb(ar[0]);
    for(int i=1; i<ar.size(); i++){
        assert(ar[i].F);
        if(ar[i].S==ret.back().S)
            ret.back().F+=ar[i].F;
        else
            ret.pb(ar[i]);
    }
    ar=ret;
}

struct node{
    int a, b, c, d;
    node(int a_, int b_, int c_, int d_):
        a(a_), b(b_), c(c_), d(d_)
    {}
};

vector<node> ans;

bool printed=false;

void print(){
    for(auto &i: ans)
        cout << i.a << " " << i.b << " " << i.c << " " << i.d << endl;
     printed=true;
}

VPII ar;

void back(int mask){
    if(printed)return;
    VPII cpy=ar;
    int topleft, p=ar.size(), maxh=0, dist=0;
    for(int i=0; i<p; i++){
        if(ar[i].S>maxh)
            maxh=ar[i].S, topleft=i;
    }
    for(int i=0; i<topleft; i++)
        dist += ar[i].F;

    if(maxh==0){
        if(mask==(1<<N)-1)
            print();
        return ;
    }


    for(int i=0; i<N; i++)
        if(not (mask&(1<<i))){
            if(ar[topleft].F>=rect[i].F and ar[topleft].S>=rect[i].S){
                ans.pb(node(dist, ar[topleft].S-rect[i].S, dist + rect[i].F, ar[topleft].S));
                int oldwidth = ar[topleft].F;
                ar[topleft].F = rect[i].F;
                ar[topleft].S -= rect[i].S;
                if(oldwidth!=rect[i].F)
                    ar.insert(ar.begin() + topleft + 1, {oldwidth-rect[i].F, maxh});

                merge(ar);
                back(mask|(1<<i));
                ans.pop_back();
                ar = cpy;
            }
            swap(rect[i].F, rect[i].S);
            if(ar[topleft].F>=rect[i].F and ar[topleft].S>=rect[i].S){

                ans.pb(node(dist, ar[topleft].S-rect[i].S, dist + rect[i].F, ar[topleft].S));
                int oldwidth = ar[topleft].F;
                ar[topleft].F = rect[i].F;
                ar[topleft].S -= rect[i].S;
                if(oldwidth!=rect[i].F)
                    ar.insert(ar.begin() + topleft + 1, {oldwidth-rect[i].F, maxh});

                merge(ar);
                back(mask|(1<<i));
                ans.pop_back();
                ar = cpy;
            }
            swap(rect[i].F, rect[i].S);
        }
}


int main()
{
    cin >> N >> W >> H;
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        rect.pb({x, y});
    }
//    random_shuffle(rect.begin(),rect.end());
    ar.pb({W, H});
    back(0);
    return 0;
}
