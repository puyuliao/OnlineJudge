#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 100

int64_t f[N];

int main()
{
	IOS;
	f[0] = 1; f[1] = 2;
	for(int i=2;i<=30;i++) {
		f[i] = 2*f[i-1] + 3*f[i-2];
		for(int j=i-3;j>=0;j--) f[i] += 2*f[j];
	}
	int n,T;
	cin >> T;
	while(T--){
		cin >> n;
		cout << f[n] << '\n';
	}

   return 0;
}


