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


map<string,int> M_user;
map<string,set<int>> M_word_user;
map<string,int> M_word_count;

int main()
{
    int n;
    cin >> n; getchar();
    for(int i=0; i<n; i++)
    {
        string s,word;
        getline(cin, s);
        stringstream ss(s);
        ss >> word;
        if(M_user.count(word)==0) M_user[word] = M_user.size();
        int user_id = M_user[word];
        while((ss >> word))
        {
            M_word_user[word].insert(user_id);
            M_word_count[word]++;
        }
    }
    vector< pair< int, string > > my;
    for(auto &p : M_word_user)
        if(p.S.size() == M_user.size())
            my.PB(MP(-M_word_count[p.F] , p.F));
    sort(my.begin(),my.end());
    if(my.empty())
    {
        cout<<"ALL CLEAR\n"; return 0;
    }
    for(auto p : my)
        cout<<p.S<<endl;
    return 0;	
}
