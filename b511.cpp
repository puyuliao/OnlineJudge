#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

int in[6];
int use[6];
int n;

void dfs(int i,int k){
	if(k==0){
		cout << "(" << use[0];
		for(int i=1;i<n;i++) cout << "," << use[i];
		cout << ")\n";
		return; 
	}
	if(i == n) return;
	for(int j=0;in[i]*j<=k;j++){
		if(k>=in[i]*j){
			use[i] = j;
			dfs(i+1,k-in[i]*j);
		}	
	}
	use[i] = 0;
}

int main()
{
	IOS;
	int k;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> in[i];
	}
	//sort(in,in+n);
	cin >> k;
	dfs(0,k);

   return 0;
}


