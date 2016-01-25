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

int main()
{
    string expr;
    cin>>expr;
    long long int value;
    cin>>value;
    long long int ans1=expr[0]-'0';
    for(int i=2; i<expr.size(); i+=2)
    {
        switch(expr[i-1])
        {
            case '*': ans1=ans1*(expr[i]-'0'); break;
            case '+': ans1=ans1+(expr[i]-'0'); break;
        }
    }
    vector <long long int> v;
    for(int i=0; i<expr.size(); i+=2)
        v.PB(expr[i]-'0');
    vector <char> x;
    for(int i=1; i<expr.size(); i+=2)
        x.PB(expr[i]);
    bool check=true;
    while(check)
    {
        check=false;
        for(int i=0; i<x.size(); i++)
        {
            if(x[i]=='*')
            {
                v[i]=v[i]*v[i+1];
                check=true;
                v.erase(v.begin()+i+1);
                x.erase(x.begin()+i);
                break;
            }
        }
    }
    long long int ans2 = 0;
    for(int i=0; i<v.size(); i++)
        ans2+=v[i];
    if(ans2==ans1 && ans1==value)
        cout<<"U"<<endl;
    else if(ans1==value)
        cout<<"L"<<endl;
    else if(ans2==value)
        cout<<"M"<<endl;
    else
        cout<<"I"<<endl;
    return 0;	
}
