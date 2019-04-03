#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 20000

int in[N];

int main()
{
	IOS;
	int n,m;
	while(cin >> n >> m){
		for(int i=0;i<n;i++) cin >> in[i];
		for(int i=n,j=0;j<n-1;i++,j++) in[i] = in[j];
		int64_t sum = 0, k = 0,mx = 0;
		n = 2*n-1;
		for(int i=0;i<n;i++){
			if(k < m) sum += in[i],k++;
			else sum += in[i] - in[i-m];
			mx = max(mx,sum);
		}
		cout << mx << '\n';	
	}
   return 0;
}


