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
FILE *fin = freopen("brackets.in","r",stdin);
FILE *fout = freopen("brackets.out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

int PO[10001],PC[10001];
int N,K; 
int A[200000];

void print()
{
    for(int i=0; i<N; i++)
        printf("%d ",A[i]); 
    printf("\n");
}

int main()
{
    int t; si(t); while(t--)
    {
        si(N); si(K);
        N*=2;
        
        int last_color;

        for(int i =0; i<2*K; i++)
        {
            int x; si(x); 
            if(x<0)
                PC[-x] = i;
            else
            {
                PO[x] = i;
                last_color = x;
            }
        }

        int first_color = 1;

        for(int i = 1; i<=K; i++)
            if(PO[i] < PO[first_color]) first_color = i;

        for(int i =0 ; i<N; i++)si(A[i]);

        int last_valid = -1;
        stack<int> S;

        for(int i = 0; i<N; i++)
        {
            int cl = A[i];
            int pos = 0;
            if(cl>0) pos = PO[cl];
            else pos = PC[-cl];

            if(S.empty()==false and PC[S.top()] > pos)
                last_valid = i;
            if(S.size()+1 <= (N-i-1) and pos < PO[last_color])
                last_valid = i;
            if(A[i]>0)S.push(A[i]); else S.pop();
        }

        if(last_valid==-1)
        {
            for(int i = 0; i<N; i++)
            {
                if(S.size()+1 <= (N-i-1) and (S.empty() or PO[first_color]<PC[S.top()]))
                {
                    A[i] = first_color; 
                    S.push(first_color);
                }
                else
                {
                    A[i] = - S.top();
                    S.pop(); 
                }
            }
            print(); continue;
        }

        for(int i =0; i<last_valid; i++)
            if(A[i]>0)S.push(A[i]); else S.pop();


        int pos = 0; int cl = A[last_valid]; if(cl>0)pos = PO[cl]; else pos = PC[-cl];

        // next_open is color of next opened.
        int next_open = last_color;
        for(int nc = 1; nc<=K; nc++)
            if(PO[nc] > pos and PO[nc] < PO[next_open]) 
                next_open = nc;
        if( (S.size()+1) > (N-last_valid-1)  or PO[next_open] <= pos)
            next_open = 0;

        // represent the color on top in the stack, only if its closing > pos.
        int next_close = 0;
        if(S.empty()==false and PC[S.top()] > pos)
            next_close = S.top();

        if(next_open > 0 and (next_close==0 or PO[next_open] < PC[next_close]))
        {
            S.push(next_open);
            A[last_valid] = next_open;
        }
        else if(next_close > 0 and (next_open==0 or PO[next_open] > PC[next_close]))
        {
            A[last_valid] = -S.top();
            S.pop();
        }
        for(int i = last_valid+1; i<N; i++)
        {
            if(S.size()+1 <= (N-i-1) and (S.empty() or PO[first_color]<PC[S.top()]))
            {
                A[i] = first_color; 
                S.push(first_color);
            }
            else
            {
                A[i] = - S.top();
                S.pop(); 
            }
        }
        print();
    }    
    return 0;
}

