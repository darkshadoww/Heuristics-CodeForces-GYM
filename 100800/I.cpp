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

bool is_h[256];
map<char,string> M;
char con[256];

char to_lower(char c)
{
    if(c>='a' and c<='z')return c;
    return c + 'a'-'A';
}
char mp(char c)
{
    return con[to_lower(c)];
}

char change(char a, char b)
{
    int d = to_lower(b) - to_lower(a);
    return a+d;
}

void f(string B)
{
    string cr="";
    vector<string> A;
    for(auto c : B)
    {
        if(c=='-')
        {
            if(!cr.empty())
                A.PB(cr);
            cr = "";
        }
        else
            cr+=c;
    }
    if(!cr.empty())
        A.PB(cr);
    char sp = mp(A[0][0]);
    A[0][0] = change(A[0][0],sp);
    for(int i = 0 ; i<A.size(); i++)
    {
        int n = A[i].size();
        if(i!=0)
        {
        for(int j = 0; j<n; j++)
            if(is_h[to_lower(A[i][j])])
                A[i][j] = change(A[i][j],sp);
        }
        if(i==A.size()-1)
        {
            if(is_h[to_lower(A[i][n-1])])
                A[i] += M[to_lower(A[i][n-1])];
        }
    }
    for(auto &c : A)
        cout<<c;
    cout<<" ";
}


int main()
{
    string s = "bcdgknpt";
    string s2 = "aou";
    sort(s.begin(), s.end());
    for(auto c : s)
        is_h[c] = true;
    con['a'] = con['b'] = 'b';
    con['t'] = con['u'] = con['v'] = con['w'] = con['x'] = con['y'] = con['z'] = 't';
    for(char c = 'c'; c<'t'; c++)
    {
        char cl,cr;
        cl = c; cr = c; 
        while(is_h[cl]==false)cl--;
        while(is_h[cr]==false)cr++;
        if(c-cl <= cr-c)
            con[c] = cl;
        else con[c] = cr;
    }


    for(auto c : s)
    {
        char ans = 'a';
        for(auto c2 : s2)
            if( abs(c-ans) > abs(c2-c) ) ans = c2;
        string cc = "h"; cc = ans+cc;
        M[c] = cc;
    }
    string B;
    while(cin>>B)
        f(B);
    cout<<endl;
    return 0;	
}
