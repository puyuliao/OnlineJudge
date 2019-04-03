#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	//IOS;
	int n;
	while(cin >> n){
		n>>=1;
		cout << (n>>1)*((n>>1)+(n&1));
	}

   return 0;
}


