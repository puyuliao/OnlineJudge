#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 50

string s[N];

bool cmp(string &a,string &b){
	return (a+b) > (b+a);
}

int main()
{
	IOS;
	int n;
	while(cin >> n && n){
		for(int i=0;i<n;i++) cin >> s[i];
		sort(s,s+n,cmp);
		for(int i=0;i<n;i++) cout << s[i];
		cout << '\n';
	}

   return 0;
}


