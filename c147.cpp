#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int tmp[2000];
int w[1000];
int v[1000];
int dp[N+1]; 

int main()
{
	IOS;
	int n;
	int top = 0;
	while(cin >> n){
		tmp[top++] = n;
	}
	n = top>>1;
	for(int i=0;i<n;i++){
		w[i] = tmp[i];
		v[i] = tmp[i+n];
	}
	for(int i=0;i<n;i++){
		for(int j=tmp[top-1];j>=w[i];j--){
			dp[j] = max(dp[j],dp[j-w[i]] + v[i]);
		}
	}
	cout << dp[tmp[top-1]] << '\n';
   return 0;
}


