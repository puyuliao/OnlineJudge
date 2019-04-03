#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

unordered_map<int64_t,int> maap;

int in[100000];

int main()
{
	IOS;
	int n,ans = 0;
	int64_t sum;
	cin >> n;
	for(int i=0;i<n;i++) cin >> in[i];
	sum = 0;
	for(int i=0;i<n;i++) {
		sum += in[i];
		maap[sum]++;
	}
	sum = 0;
	for(int i=n-1;i>=0;i--) {
		sum += in[i];
		ans += maap[sum];
	}
	cout << ans << '\n';
   return 0;
}


