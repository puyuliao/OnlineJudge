#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int T,n,m;
	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=j;k++) cout << j;
				cout << '\n';
			}
			for(int j=n-1;j;j--){
				for(int k=1;k<=j;k++) cout << j;
				cout << '\n';
			}
			cout << '\n';
		}
		
	}

   return 0;
}


