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
FILE *fin = freopen("enigmatic.in","r",stdin);
FILE *fout = freopen("enigmatic.out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

// 1(0) 2 4 8 16 32 64 128 256 512 498(10) 464(11) 400(12) 272(13)

int NXT[2010];
int E[14];

class segtree {
    public:
        vector<int> ST[14],LZ,BG;
        int base,ql,qr;

        void print(){
            for(int i = 0; i<2*base; i++)
                trace(i, ST[0][i], ST[1][i], ST[2][i], LZ[i], BG[i]);
        }
        segtree(vector<int> A){
            int N = A.size();
            base = 1;
            while(base<N)base*=2;
            for(int i = 0; i<14; i++)
                ST[i].resize(2*base);
            LZ.resize(2*base);
            BG.resize(2*base);
            for(int j = 0; j<14; j++)
            {
                for(int i = 0; i<N; i++)
                {
                    if(j) ST[j][base+i] = NXT[ST[j-1][base+i]];
                    else ST[j][base+i] = A[i];
                }
                for(int i = base-1; i>0; i--)
                    ST[j][i] = ST[j][2*i] + ST[j][2*i+1];
            }
        }
        
        void up(int id){

            int ll = BG[2*id];
            int rr = BG[2*id+1];
            int i = BG[id];
            int ed = i; if(ed<4)ed = 4;
            int cnt = 0;
            while(1)
            {
                if(i==ed)cnt++;
                if(cnt==2)return;
                ST[i][id] = ST[ll][2*id]  + ST[rr][2*id+1];
                i = E[i]; ll = E[ll]; rr = E[rr];
            }
        }
        
        void push(int id){
            if(id<base){
                LZ[2*id] += LZ[id];
                LZ[1 + 2*id] += LZ[id];
            }
            while(LZ[id]>0 and BG[id]<4){ BG[id]++; LZ[id]--;}
            if(LZ[id]>0)
            {
                BG[id]-=4; BG[id] = (BG[id] + LZ[id]) % 10; BG[id]+=4;
            }
            LZ[id] = 0;
        }

        void update(int id, int l, int r){
            push(id); if(ql>=r or qr<=l)return;
            if(l>=ql and r<=qr){
                LZ[id]++;
                push(id);
                return;
            }
            update(2*id,l,(l+r)/2);
            update(1 + 2*id,(l+r)/2,r);
            up(id);
        }
        int query(int id, int l, int r){
            push(id);
            if(l>=qr or r<=ql)return 0;
            if(l>=ql and r<=qr)return ST[BG[id]][id];
            return query(2*id,l,(l+r)/2) + query(2*id+1,(l+r)/2,r);
        }
        void update(int l, int r){
            ql = l;
            qr = r+1;
            update(1,0,base);
        }
        int query(int l, int r){
            ql = l;
            qr = r+1;
            return query(1,0,base);
        }
};

int main()
{
    int N; si(N);
    vector<int> A; A.resize(N);
    for(int i =0; i<N; i++) si(A[i]);
    for(int i = 0; i<13; i++)E[i] = i+1;
    E[13] = 4;
    for(int i = 0; i<2010; i++)
        NXT[i] = (i*i) % 2010;
    segtree ST(A);
    int Q; si(Q); while(Q--){
        int ch; int l; int r; si(ch); si(l); si(r); l--; r--;
        if(ch==1)
            ST.update(l,r);
        else 
            printf("%d\n",ST.query(l,r));
    }
    return 0;
}

