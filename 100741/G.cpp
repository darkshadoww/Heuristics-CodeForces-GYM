/////////////////////////////////////////
//  Author : Akshay Jaggi             //
///////////////////////////////////////

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
#include<set>
#include<map>
#include<unordered_map>
#define rep(i,N) for(int (i)=0;(i)<(N);(i)++)
#define repi(i,j,N) for(int (i)=(j);(i)<(N);(i)++)
#define repg(i,j,N) for((i)=(j);(i)<(N);(i)++)
#define si(i) scanf("%d",&(i))
#define sl(i) scanf("%lld",&(i))
#define pi(i) printf("%d",(i))
#define pl(i) printf("%lld",(i))
#define pin(i) printf("%d\n",(i))
#define pln(i) printf("%lld\n",(i))
#define pw    printf(" ");
#define pn    printf("\n");

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

class SegNode
{
	public:
		int val_;
		//int l_,r_;
		SegNode *left_, *right_;
		//SegNode(int val, int l, int r, SegNode* left, SegNode* right)
			//: val_(val), l_(l), r_(r), left_(left), right_(right)
		//{}
		SegNode(int val, SegNode* left, SegNode* right)
			: val_(val), left_(left), right_(right)
		{}
};

vector<vector<int> > A(470,vector<int>(470,0));
SegNode* trees[470][470];
unordered_map<int,int> map_compressed;
vector<int> compressed;
SegNode* init_tree;
int levels;

SegNode* InitTree(int l)
{
	vector<SegNode*> v;
	rep(i,l)
	{
		v.PB(new SegNode(0, nullptr, nullptr));
	}
	levels=1;
	while(l!=1)
	{
		SegNode* tmp;
		for(int i=0; i<l/2; i++)
		{
			tmp=new SegNode(v[2*i]->val_ + v[2*i+1]->val_, v[2*i], v[2*i+1]);
			v[i]=tmp;
		}
		if(l&1)
		{
			tmp = new SegNode(v[l-1]->val_, v[l-1], nullptr);
			v[l/2]=tmp;
			l=l/2+1;
		}
		else
			l=l/2;
		levels++;
	}
	return v[0];
}

SegNode* MakeNewPersistant(int val, SegNode* root, int level)
{
	if(level == levels)
		return new SegNode(root->val_+1, root->left_, root->right_);
	SegNode* tmp = new SegNode(root->val_+1, root->left_, root->right_);
	if(val<(1<<(levels-level-1)))
		tmp->left_ = MakeNewPersistant(val, tmp->left_, level+1);
	else
		tmp->right_ = MakeNewPersistant(val-(1<<(levels-level-1)), tmp->right_, level+1);
	return tmp;
}

int FindInTree(int num_reqd, vector<SegNode*>& front, vector<SegNode*>& back, int level, int my_curr)
{
	if(level == levels)
	{
		return compressed[my_curr];
	}
	int num_left_gives = 0;
	for(int i=0; i<front.size(); i++)
	{
		num_left_gives+=front[i]->left_->val_-back[i]->left_->val_;
		//cerr<<front[i]->left_->val_<<"*"<<back[i]->left_->val_<<"*"<<endl;
	}
	//cerr<<num_left_gives<<"#"<<endl;
	if(num_reqd > num_left_gives)
	{
		for(int i=0; i<front.size(); i++)
		{
			front[i] = front[i]->right_;
			back[i] = back[i]->right_;
		}
		return FindInTree(num_reqd-num_left_gives, front, back, level+1, my_curr+(1<<(levels-level-1)) );
	}
	else
	{
		for(int i=0; i<front.size(); i++)
		{
			front[i] = front[i]->left_;
			back[i] = back[i]->left_;
		}
		return FindInTree(num_reqd, front, back, level+1, my_curr);
	}
}

int Find(int x1,int y1,int x2,int y2)
{
	int num_elements=(x2-x1+1)*(y2-y1+1);
	int num_reqd=(num_elements+1)/2;
	vector<SegNode*> front, back;
	for(int i=x1; i<=x2; i++)
	{
		front.PB(trees[i][y2]);
		if(y1>0)
			back.PB(trees[i][y1-1]);
		else
			back.PB(init_tree);
	}
	return FindInTree(num_reqd, front, back, 1, 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	set<int> s;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>A[i][j];
			s.insert(A[i][j]);
		}
	}
	tr(s, it)
		compressed.PB(*it);
	s.clear();
	tr(compressed, it)
	{
		static int x=0;
		map_compressed[*it]=x++;
	}
	
	//cerr<<compressed.size()<<endl;
	for(int i=0; i<n;i++)
		for(int j=0;j<n;j++)
			A[i][j]=map_compressed[A[i][j]];

	init_tree = InitTree(compressed.size());

	map_compressed.clear();
	SegNode* prev_tree = init_tree;
	for(int i=0; i<n; i++)
	{
		prev_tree = init_tree;
		for(int j=0; j<n; j++)
		{
			trees[i][j]=MakeNewPersistant(A[i][j], prev_tree, 1);
			prev_tree = trees[i][j];
		}
	}
	A.clear();

	for(int i=0; i<q; i++)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		x1--;
		y1--;
		x2--;
		y2--;
		cout<<Find(x1,y1,x2,y2)<<endl;
	}
  return 0;
}

