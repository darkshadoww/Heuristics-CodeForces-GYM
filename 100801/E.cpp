// heuristics
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

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

FILE *fin = freopen("easy.in","r",stdin);
FILE *fout = freopen("easy.out","w",stdout);

string B;
void f(string A)
{
    if(A.size()<2)
    {
        B+=A;
        return;
    }
    B += A[0];
    int i =1;
    while(i<A.size() and A[i]=='0')
    {
        B+="+0";
        i++;
    }
    if(i<A.size())
    {
        B+='+';
        while(i<A.size())B+=A[i++];
    }
}

int main()
{
    string A;
    cin>>A;
    int n = A.size();
    string cr = "";
    bool last = false;
    for(int i = 0; i<n; i++)
    {
        if(A[i]=='+' or A[i]=='-')
        {
            if(last) f(cr);
            else B+=cr;
            B+=A[i];
            cr = "";
            if(A[i]=='-')last = true;
            else last = false;
        }
        else
        {
            cr+=A[i];
        }
    }
    if(last) f(cr); else B+=cr;
    cout<<B<<endl;
    return 0;	
}

 
 

