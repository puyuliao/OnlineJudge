#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

struct boook{
	int in,zun;
	bool operator < (const boook &b)const{
		return zun > b.zun;
	}
}in[1001];

int main()
{
	IOS;
	int n;
	while(cin >> n){
		for(int i=0;i<n;i++) cin >> in[i].in >> in[i].zun;
		sort(in,in+n);
		int mx = 0,sum = 0;
		for(int i=0;i<n;i++){
			sum += in[i].in;
			mx = max(mx,sum+in[i].zun);
		}
		cout << mx << '\n';
	}

   return 0;
}


