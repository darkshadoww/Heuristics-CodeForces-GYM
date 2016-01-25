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

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define DRT()  int t; cin>>t; while(t--)

#ifdef ONLINE_JUDGE
FILE *fin = freopen("ideal.in","r",stdin);
FILE *fout = freopen("ideal.out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

pair<int,int> check1(string& t)
{
    istringstream is(t);
    int state=0, num_problems = 0;
    string tmp;
    while(is>>tmp)
    {
        switch(state)
        {
            case 0: if(tmp=="Team") state++;
                    else state=-1; break;
            case 1: if(tmp[0]=='A'+num_problems) num_problems++;
                    else if(tmp[0]=='=') state++;
                    else state=-1; break;
            case 2: if(tmp=="Time") state++;
                    else state=-1; break;
            case 3: if(tmp=="R") state++;
                    else state=-1; break;
            case 4: state=-1; break;
        }
        if(state==-1) return {false, 0};
    }
    if(state==4)
        return {true, num_problems};
    return {false, 0};
}

bool check2(string& t)
{
    for(auto it:t)
    {
        if(it!='-')
            return false;
    }
    return true;
}

struct data
{
    int num_solved;
    bool solved[26];
};

pair<int, data> parse(string& t, int num_problems)
{
    data ret;
    memset(&ret, 0, sizeof(ret));
    stack<string> s;
    istringstream is(t);
    string tmp;
    while(is>>tmp)
    {
        s.push(tmp);
    }
    int rank = stoi(s.top());
    s.pop();
    s.pop();
    ret.num_solved = stoi(s.top());
    s.pop();

    stack<bool> sss;
    int cnt = 0;
    while(!s.empty() && cnt<num_problems)
    {
        string cur = s.top();
        s.pop();
        if(cur[0]=='.' || cur[0]=='-')
            sss.push(false);
        else
            sss.push(true);
        cnt++;
    }
    int cur = 0;
    while(!sss.empty())
    {
        ret.solved[cur++] = sss.top();
        sss.pop();
    }
    return {rank, ret};
}

int main()
{
    vector<string> txt;
    while(!cin.eof())
    {
        string tmp;
        getline(cin,tmp);
        if(tmp.length()==0) continue;
        txt.PB(move(tmp));
    }

    int state=0;
    int num_problems=0, num_columns=0, num_teams=0;

    map <int, vector<data> > m;

    for(int i=0; i<txt.size(); i++)
    {
        if(state==0)
        {
            auto result = check1(txt[i]);
            if(result.F)
            {
                state++;
                num_problems = result.S;
                num_columns = num_problems + 3;
            }
        }
        else if(state==1)
        {
            if(check2(txt[i]))
            {
                state++;
            }
            else
            {
                //state=0;
            }
        }
        else
        {
            auto cur = parse(txt[i], num_problems);
            m[cur.F].PB(cur.S);
            num_teams++;
            // travel and do stuff
        }
    }
    double V=0, O=0, E=0, U=0, IP[26];
    for(auto itm : m)
    {
        for(auto itt : itm.S)
        {
            if(itt.num_solved == 0)
                V+=(1.0/(double)num_teams);
            else if(itt.num_solved == num_problems)
                O+=(1.0/(double)num_teams);
        }
    }
    int last_solv;
    for(auto itm : m)
    {
        if(itm.F!=1 && last_solv - itm.S[0].num_solved > 1)
        {
            E += (last_solv - itm.S[0].num_solved - 1)/((double)num_problems);
        }
        last_solv = itm.S[0].num_solved;
    }
    bool solved[26];
    int last_solved[26];
    memset(solved, 0, sizeof(solved));
    memset(IP, 0, sizeof(IP));
    memset(last_solved, 0, sizeof(last_solved));
    for(auto itm : m)
    {
        for(auto itt : itm.S)
        {
            for(int i=0; i<num_problems; i++)
            {
                solved[i] |= itt.solved[i];
                if(itt.solved[i])
                    last_solved[i] = max(last_solved[i], itm.F);
            }
        }
    }
    for(int i=0; i<num_problems; i++)
        if(!solved[i])
            U += (1/((double)num_problems));
    
    for(int i=0; i<num_problems; i++)
    {
        for(auto itm : m)
        {
            if(itm.F >= last_solved[i])
                break;
            for(auto itt : itm.S)
            {
                if(!itt.solved[i])
                    IP[i] += 1/((double)num_teams);
            }
        }
    }
    cout<<fixed<<setprecision(3);
    cout<<"Vainness = "<<V<<endl;
    cout<<"Oversimplification = "<<O<<endl;
    cout<<"Evenness = "<<E<<endl;
    cout<<"Unsolvability = "<<U<<endl;
    double sum = 0;
    for(int i=0; i<num_problems; i++)
    {
        cout<<"Instability "<<i+1<<" = "<<IP[i]<<endl;
        sum+=IP[i];
    }
    double N = 1.03*V + 3.141*O + 2.171*E + 1.414*U + sum/num_problems;
    cout<<"Negidealness = "<<N<<endl;
    return 0;
}

