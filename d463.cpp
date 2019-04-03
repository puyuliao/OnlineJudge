#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

int main()
{
	//IOS;
	int64_t n;
	const double k = 1.0/3.0;
	while(cin >> n){
		cout << (int)(pow(n,k)+0.5) << '\n';
	}

   return 0;
}


