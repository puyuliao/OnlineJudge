#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

int main()
{
	IOS;
	int t,ans;
	cin >> t;
	string a;
	while(t--){
		cin>>a;
		ans = 1;
		for(int i=0;i<a.size();i++){
			ans*=a[i]-'0';
		}	
		cout << ans <<'\n';
	}
   return 0;
}


