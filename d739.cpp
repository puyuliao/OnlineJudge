#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

#define MEM 1001
struct binary_graph{
	int l,r;
	vector<int> v[MEM];
	bool visit[MEM]; 
	int my[MEM];
	void Init(int s,int e){l = s; r = e;for(int i=s;i<e;i++) v[i].clear();}
	inline int Size(){return r-l;}
	inline void Addedge(int x,int y){v[x].push_back(y);}
	bool dfs(int x){
		visit[x] = true;
		for(auto i : v[x]) if(!~my[i] || !visit[my[i]] && dfs(my[i])){my[i] = x; return true;}
		return false;
	}
	int MBPM(){
		int ans = 0; memset(my,0xff,sizeof(my));
		for(int i=l;i<r;i++) {memset(visit+l,false,Size());if(dfs(i)) ans++;}
		return ans;
	}
};

binary_graph bg;
int main()
{
	IOS;
	int n,m,s,t;
	while(cin >> n >> m && (n||m)){
		bg.Init(1,n+1);
		while(m--){
			cin >> s >> t;
			bg.Addedge(s,t);
		}
		cout << bg.Size() - bg.MBPM() << '\n';
	}
	
   return 0;
}


