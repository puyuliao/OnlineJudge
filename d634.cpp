#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

string in[100001];

int main()
{
	IOS;
	int n;
	cin >> n;
	getline(cin,in[0]);
	for(int i=0;i<n;i++) getline(cin,in[i]);
	sort(in,in+n);
	for(int i=0;i<n;i++) cout << in[i] << '\n';
   return 0;
}


