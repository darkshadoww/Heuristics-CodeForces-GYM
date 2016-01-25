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


stack<int> S;
string A;

int main()
{
    cin>>A;
    int N = A.size();
    for(int i = 0; i<N; i++)
    {
        if(A[i]=='[')
            S.push(i);
        if(A[i]==']')
        {
            int j = S.top(); S.pop();
            A[i] = ')'; A[j] = '(';
            for(int k = j+1; k<i; k++)
            {
                if(A[k]=='+') A[k]  = '*';
                else if(A[k]=='*') A[k]  = '+';
                else if(A[k]>='a' and A[k]<='z') A[k] += 'A' - 'a';
                else if(A[k]>='A' and A[k]<='Z') A[k] += 'a' - 'A';

            }
        }
    }
    cout<<A<<endl;
    return 0;	
}
