#include<bits/stdc++.h>
using namespace std;

bool link[501][501];
vector<int> v[501];
int n,e;
int ans[1032];
bool finished;

void dfs (int s,int ind){
	ans[ind] = s;
	if(ind == n){
		for(int i=0;i<=n;i++) printf("%d\n",ans[i]);
		finished = true;
		return;
	}
	vector<int>::iterator it;
	for(it = v[s].begin();it!=v[s].end();it++){
		if(link[s][*it]){
			link[s][*it] = link[*it][s] = false;
			dfs(*it,ind+1);
			if(finished) return;
			link[s][*it] = link[*it][s] = true;
		}
	}
}

int main()
{
	int s,e;
	scanf("%d",&n);
	for(int i=0,in1,in2;i<n;i++){
		scanf("%d%d",&in1,&in2);
		v[in1].push_back(in2);
		v[in2].push_back(in1);
		link[in1][in2] = link[in2][in1] = true;
	}
	for(int i=1;i<=500;i++) sort(v[i].begin(),v[i].end());
	for(int i=1;i<=500;i++)
		if(v[i].size() > 0){s = i; break;}
	for(int i=1;i<=500;i++){
		if(v[i].size() & 1 == 1){
			s = i;
			break;
		} 
	}
	dfs(s,0);
  return 0;
}
