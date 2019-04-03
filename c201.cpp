#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

unordered_map<string,int> maap;
vector<int> score[100];
int tmp[100];
int rak[100];

bool cmp(int a,int b){
	int sz = min(score[a].size(),score[b].size());
	for(int i=0;i<sz;i++){
		if(score[a][i] != score[b][i]) return score[a][i] > score[b][i];
	}
	return score[a].size() > score[b].size();
}

bool equal(int a,int b){
	if(score[a].size()!=score[b].size()) return false;
	int sz = score[a].size();
	for(int i=0;i<sz;i++){
		if(score[a][i] != score[b][i]) return false;
	}
	return true;
}

int main()
{
	IOS;
	int n,sc,k;
	string s;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> s >> k;
		maap[s] = i;
		while(k--){
			cin >> sc;
			score[i].push_back(sc);
		}
		sort(score[i].begin(),score[i].end());
		reverse(score[i].begin(),score[i].end());
	}
	for(int i=0;i<n;i++) tmp[i] = i;
	sort(tmp,tmp+n,cmp);
	rak[tmp[0]] = 1;
	for(int i=0,j=1;j<n;j++){
		if(!equal(tmp[j],tmp[j-1])) i=j;
		rak[tmp[j]] = i+1;
	}
	
	while(cin >> s){
		cout << rak[maap[s]] << '\n';
	}
   return 0;
}


