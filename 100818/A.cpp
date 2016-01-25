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

string E1,E2;

map<char,bool> M;

bool eval(string &E)
{
    int N = E.length();
    stack<char> S1;
    stack<bool> S2;
    for(int i =0 ; i<N; i++)
    {
        if(E[i]=='~')
        {
            bool tp = S2.top(); 
            S2.pop();
            S2.push(not tp);
            continue;
        }
        if(E[i]==')' or E[i]=='^' or E[i]=='V')
        {
            S1.push(E[i]);
            continue;
        }
        char c = E[i];
        if( (c>='a' and c<='z') or (c>='A' and c<='Z') )
        {
            S2.push(M[c]);
            continue;
        }
        if(E[i]=='(')
        {
            while(1)
            {
                char c2 = S1.top(); S1.pop();

                if(c2==')')break;
                if(c2=='^')
                {
                    bool tp1 = S2.top(); S2.pop();
                    bool tp2 = S2.top(); S2.pop();
                    S2.push(tp1 and tp2);
                }
                if(c2=='V')
                {
                    bool tp1 = S2.top(); S2.pop();
                    bool tp2 = S2.top(); S2.pop();
                    S2.push(tp1 or tp2);
                }
            }
        }
    }
    while(!S1.empty())
    {
                char c2 = S1.top(); S1.pop();
                if(c2=='^')
                {
                    bool tp1 = S2.top(); S2.pop();
                    bool tp2 = S2.top(); S2.pop();
                    S2.push(tp1 and tp2);
                }
                if(c2=='V')
                {
                    bool tp1 = S2.top(); S2.pop();
                    bool tp2 = S2.top(); S2.pop();
                    S2.push(tp1 or tp2);
                }
    }
    return S2.top();
}


int main()
{
    getline(cin,E1);
    getline(cin,E2);
    istringstream is(E1);
    string A; 
    string CR = "";
    while(is>>A)
    {
        for(auto c : A)
        {
            if(c==' ')continue;
            CR+=c;
            if( (c>='a' and c<='z') or (c>='A' and c<='Z') )
                M[c];
        }
    }
    E1 = CR;
    CR = "";
    istringstream is1(E2);
    CR = "";
    while(is1>>A)
    {
        for(auto c : A)
        {
            if(c==' ')continue;
            CR+=c;
            if( (c>='a' and c<='z') or (c>='A' and c<='Z') )
                M[c];
        }
    }
    E2 = CR;
    bool equal = true;
    int iter = 10000;
    reverse(E1.begin(), E1.end());
    reverse(E2.begin(), E2.end());
    while(iter--)
    {
        for(auto &p : M)
            p.S = rand() % 2;
        if( eval(E1) != eval(E2)) 
        {
            equal = false; break;
        }
    }
    if(equal) cout<<1<<endl; else cout<<0<<endl; return 0;
}
