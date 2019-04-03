#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int n,t,sum;
	while(cin >> n){
		sum = 0;
		for(int i=0;i<n;i++){
			cin >> t;
			sum += t;
		}
		cout << (sum + (n>>1)) / n << '\n';
	}

   return 0;
}


