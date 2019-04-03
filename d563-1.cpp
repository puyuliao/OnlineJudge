#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

int in[100001];

int main()
{
	IOS;
	int n,ans,sum1,sum2;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> in[i];
	}
	ans = sum1 = sum2 = 0;
	for(int i=0,j=n-1;i<n && j>=0;) {
		if(sum1 == sum2){
			ans++; sum1 += in[i++]; sum2 += in[j--];
		} 
		else if(sum1 < sum2) sum1 += in[i++];
		else sum2 += in[j--];
	}
	cout << ans << '\n';
   return 0;
}


