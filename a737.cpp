#include<iostream>
#include<algorithm>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 500

int in[N];

int main()
{
	IOS;
	int n,T,mid,ans;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=0;i<n;i++) cin >> in[i];
		mid = n>>1;
		nth_element(in,in+mid,in+n);
		ans = 0;
		for(int i=0;i<n;i++) ans += abs(in[mid] - in[i]);
		cout << ans << '\n';
	} 
	
   return 0;
}


