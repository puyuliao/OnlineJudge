#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int n,ans,tn;
	while(cin >> n){
		tn = max(n,1);
		cout << n << "! = " << tn;
		ans = tn;
		for(int i=tn-1;i>0;i--){
			ans*=i;
			cout << " * " << i;
		}
		cout << " = " << ans << '\n';
	}

   return 0;
}


