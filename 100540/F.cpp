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

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

#define MAXN 600001

int lcp[MAXN], cnt[256], cls[2][MAXN], sa[2][MAXN], st[MAXN], rnk[MAXN];
void suffixArray(string s) 
{
    int i, j;
    memset(cnt, 0, sizeof(cnt));
    int n = s.size();
    for (i = 0; i < n; i++) { cnt[s[i]] ++; cls[0][i] = s[i];}
    for (i = 1; i <= 255; i++) cnt[i] += cnt[i - 1];
    for (i = 0; i < n; i++) sa[0][--cnt[cls[0][i]]] = i;
    int cur = 0;
    for (i = 0; (1 << i) < n; i++) 
    {
        int clen = (1 << i);
        for (j = 0; j < n; j++) 
        {
            if (j > 0 && sa[cur][j - 1] + clen < n 
                    && cls[cur][sa[cur][j]] == cls[cur][sa[cur][j - 1]] 
                    && cls[cur][sa[cur][j] + clen / 2] == cls[cur][sa[cur][j - 1] + clen / 2])
                cls[1 - cur][sa[cur][j]] = cls[1 - cur][sa[cur][j - 1]];
            else 
                cls[1 - cur][sa[cur][j]] = j;
        }
        for(j=0;j<n;j++)
        {
            st[j]=j;sa[1-cur][j]=sa[cur][j];
        }
        for (j = 0; j < n; j++) 
        {
            int cele = sa[cur][j] - clen;
            if (cele >= 0) sa[1 - cur][st[cls[1 - cur][cele]]++] = cele;
        }
        cur = 1 - cur; 
    }
    for (i = 0; i < n; i++) { sa[0][i] = sa[cur][i]; rnk[sa[cur][i]] = i;}
    int x = 0;
    for (i = 0; i < n; i++) 
    {
        if (rnk[i] < n - 1) 
        {
            for (j = sa[cur][rnk[i] + 1]; max(i, j) + x < n && s[i + x] == s[j + x]; x++);
            lcp[rnk[i] + 1] = x; if (x > 0) x--;
        } 
    }
}



string A;
string F[60];
int sF[60];
int file_no[600000];
LL MASK[600000];

LL give_mask(int x)
{
    x = parent(x);
    return MASK[x];
}

void merge(int x, int y)
{
    x = parent(x); y = parent(y);
    if(x==y)return;
    P[x] = y;
    MASK[y] |= MASK[x];
}

set<string> sF;
string F[60];

int main()
{
    while(1)
    {
        int N; cin>>N;
        A = "";
        int c = 0;
        sF.clear();
        for(int i = 0; i<N; i++)
        {
            string s; cin>>s; sF.insert(s);
        }
        N = 0;
        for(auto x : sF)F[N++] = x;
        for(int i =0; i<N; i++)
        {
            sF[i] = F[i].size();
            int x = sF[i];
            while(x--) file_no[c++] = i;
            A += F[i];
        }
        suffixArray(A);
        for(int i = 0; i<c; i++)
            trace(i,sa[0][i],lcp[i],rnk[i]);            
    }
    return 0;	
}
