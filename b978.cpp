#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 108

pair<int,char> in[N];

int main()
{
	IOS;
	char s[N];
	while(cin >> s){
		int n = strlen(s);
		for(int i=0;i<n;i++) cin >> in[i].first,in[i].second = s[i];
		sort(in,in+n);
		for(int i=0;i<n;i++) cout << in[i].second;
		cout << '\n';
	}

   return 0;
}


