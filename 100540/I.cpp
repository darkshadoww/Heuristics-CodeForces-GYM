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


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

string B[3][100];
string S;

string MP[3][10];

int process(int x)
{
    for(int i =0; i<10; i++)
        if(B[0][x]==MP[0][i] and B[1][x]==MP[1][i] and B[2][x]==MP[2][i])return i;
}

int main()
{
    string A[10] = {".*", "*.", "*.", "**", "**", "*.", "**", "**", "*.", ".*"};
    for(int i =0; i<10; i++)MP[0][i] = A[i];
    string X[10] = {"**", "..", "*.", "..", ".*", ".*", "*.", "**", "**", "*."};
    for(int i =0; i<10; i++)MP[1][i] = X[i];
    string Y[10]  = {"..", "..", "..", "..", "..", "..", "..", "..", "..", ".."};
    for(int i =0; i<10; i++)MP[2][i] = Y[i];

    while(1)
    {
        int N; cin>>N; if(N==0)return 0;
        string ty;
        cin>>ty;
        if(ty[0]=='S')
        {
            cin>>S;
            for(int j = 0; j<3; j++)
            {
                for(int i =0; i<N; i++)
                cout<<MP[j][S[i]-'0']<<" ";
                cout<<endl;
            }
        }
        else
        {
            for(int j = 0; j<3; j++)
                for(int i =0; i<N; i++)
                    cin>>B[j][i];
            for(int i =0; i<N; i++)
                cout<<process(i);
            cout<<endl;
        }
    }
    return 0;	
}
