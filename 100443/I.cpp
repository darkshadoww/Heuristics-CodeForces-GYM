#include<bits/stdc++.h>

#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
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


queue< vector<string> > myq;
unordered_map < string, int > cnt;
map < int, set<string> > revcnt;


int main()
{
    string s;
    while((cin >> s)){
        if(s=="<text>"){
            vector<string> today;
            while(1){
                cin >> s;
                if(s=="</text>")break;
                if(s.length()>=4)today.pb(s);
            }
            myq.push(today);
            for(auto &i: today){
                revcnt[cnt[i]].erase(i);
                cnt[i]++;
                revcnt[cnt[i]].insert(i);
            }

            if((int)myq.size()>7){
                vector<string> m=myq.front();
                myq.pop();

                for(auto &i: m){
                    revcnt[cnt[i]].erase(i);
                    cnt[i]--;
                    if(cnt[i])revcnt[cnt[i]].insert(i);
                }
            }
        }
        else if(s=="<top"){
            int n;
            cin >> n;
            cin >> s;

            cout << "<top " << n << ">\n";
            auto it=revcnt.rbegin();
            while(1){
                if(n<=0 or it==revcnt.rend())break;
                n-= it->S.size();
                for(auto &i: it->S)
                    cout << i << " " << it->F << endl;
                if(n<=0 or it==revcnt.rend())break;
                it++;
            }
            cout << "</top>\n";
        }
    }
    return 0;
}


