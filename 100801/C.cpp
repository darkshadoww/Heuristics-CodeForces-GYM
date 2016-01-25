#ifdef __APPLE__

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

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define F first
#define S second
#define MP make_pair

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

#define MAXN 200009
int lcp[MAXN], cnt[256], cls[2][MAXN], sa[2][MAXN], st[MAXN], rnk[MAXN];
void suffixArray(string s) {
    int i, j;
    memset(cnt, 0, sizeof(cnt));
    int n = s.size();
    for (i = 0; i < n; i++) { cnt[s[i]] ++; cls[0][i] = s[i];}
    for (i = 1; i <= 255; i++) cnt[i] += cnt[i - 1];
    for (i = 0; i < n; i++) sa[0][--cnt[cls[0][i]]] = i;
    int cur = 0;
    for (i = 0; (1 << i) < n; i++) {
        int clen = (1 << i);
        for (j = 0; j < n; j++) 
        {
            if (j > 0 && sa[cur][j - 1] + clen < n && cls[cur][sa[cur][j]] == cls[cur][sa[cur][j - 1]] && cls[cur][sa[cur][j] + clen / 2] == cls[cur][sa[cur][j - 1] + clen / 2]
               )
                cls[1 - cur][sa[cur][j]] = cls[1 - cur][sa[cur][j - 1]];
            else cls[1 - cur][sa[cur][j]] = j;
        }
        for (j = 0; j < n; j++) { st[j] = j; sa[1 - cur][j] = sa[cur][j]; }
        for (j = 0; j < n; j++) {
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
bool nt[200005];
LL f(int n)
{
    LL cr = 0;
    LL ret = 0;
    for(int i = 1; i<n; i++)
    {
        int cnt = 1; 
        if(nt[sa[0][i-1]])
            cnt = 0;
        if(lcp[i])
            cr += cnt;
        else
            cr = 0;
        if(!nt[sa[0][i]])
            ret += cr;
    }
    return ret;
}

FILE *fin = freopen("concatenation.in","r",stdin);
FILE *fout = freopen("concatenation.out","w",stdout);

int main()
{
    string a,b;
    cin >> a >> b;
    int n=a.length(),m=b.length();
    LL ans = n; ans *=m;
    suffixArray(a);
    nt[0] = true;
    ans+=f(n);
    nt[0] = false;
    suffixArray(b);
    nt[m-1] = true;
    ans+= f(m);
    nt[m-1] = false;
    suffixArray(a+"#"+b);
    nt[0] = nt[n+m] = true;
    ans -= f(n+m+1);
    nt[0] = nt[n+m] = false;
    cout<<ans<<endl;
    return 0;
}

