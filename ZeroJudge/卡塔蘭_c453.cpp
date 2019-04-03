#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 21

int64_t f[N]={1,1,2};

int main()
{
	IOS;
	for(int i=3;i<N;i++){
		for(int j=0;j<i;j++){
			f[i] += f[j]*f[i-j-1];
		}
	}
	int n;
	cin >> n;
	cout << f[n];
   return 0;
}


