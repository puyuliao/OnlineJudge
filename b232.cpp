#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

int64_t t[751];

int main()
{
	IOS;
	t[0] = 1;
	for(int i=1;i<=750;i+=2){
		for(int j = i;j <= 750;j++)
			t[j] += t[j-i];
	}
	int m,n;
	while(cin >> m){
		while(m--){
			cin >> n;
			cout << t[n] << '\n';
		}
	}

   return 0;
}


