#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

pair<int,int> in[N];
pair<int,int> tmp[N];
int t;
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first < b.first || a.first == b.first && a.second > b.second;
}

int l

int main()
{
	IOS;
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> in[i].first >> in[i].second;
	sort(in,in+n);
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			if() tmp[t++] = in[j];
		}
	}
	vector<int> v;
	v.push_back(-1);
	for(int i=0;i<n;i++){
		if(tmp[i].second > v.back()) v.push_back(tmp[i].second);
		else *lower_bound(v.begin(),v.end(),tmp[i].second) = tmp[i].second;
	}
	cout << v.size() - 1;
   return 0;
}


