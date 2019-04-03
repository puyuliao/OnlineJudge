#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

bool cmp(pair<char,int> a,pair<char,int> b){
	return a.second > b.second ||  a.second == b.second && a.first < b.first;
}

unordered_map<char,int> maap;

int main()
{
	IOS;
	int T;
	string in;
	cin >> T;
	getline(cin,in);
	while(T--){
		getline(cin,in);
		for(int i=0;i<in.size();i++){
			if(isalpha(in[i])) maap[toupper(in[i])]++;
		}
	}
	vector<pair<char,int> > v(maap.begin(),maap.end());
	sort(v.begin(),v.end(),cmp);
	for(auto i : v){
		cout << i.first << ' ' << i.second << '\n';
	}

   return 0;
}


