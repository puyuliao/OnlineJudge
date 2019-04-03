#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000

unordered_map<int,vector<int>> v;
unordered_map<int,int> indeg;
unordered_set<int> node;

int dfs(int x,int p){
	int sz = 1;
	for(int i : v[x]) if(i!=p) sz += dfs(i,x);
	return sz;
}

bool chk(){
	if(node.size()==0) return true;
	int root = -1,edg = 0;
	for(auto &i : v){
		if(indeg[i.first] == 0) root = i.first;
		edg += i.second.size();
	}  
	if(!root || edg != node.size()-1) return false;
	return dfs(root,root) == node.size();
}

int main()
{
	IOS;
	int n,m,cnt = 0;
	bool ist = true;
	while(cin >> n >> m){
		if(!~n && !~m) break;
		if(n == m && !m){
			if(!ist || !chk()) cout << "Case " << ++cnt << " is not a tree." << '\n';
			else cout << "Case " << ++cnt << " is a tree." << '\n';
			v.clear();
			indeg.clear();
			node.clear();
			ist = true;
			continue;
		}
		v[n].push_back(m);
		node.insert(n);
		node.insert(m);
		if(++indeg[m] >= 2) ist = false;
	}
	
   return 0;
}


