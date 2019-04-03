#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 20016

int f[N];

int main()
{
	IOS;
	int n;
	f[0] = f[1] = 1;
	for(int i=2;i<N;i++) f[i] = (f[i-1] + f[i-2]) % 10007;
	while(cin >> n){
		cout << f[n%N] << '\n';
	}

   return 0;
}


