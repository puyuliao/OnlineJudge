#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	stack<pair<int,int> > s;
	int n,t,ans = 0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> t;
		int ts = i;
		while(!s.empty() && t < s.top().first){
			ans = max(ans,s.top().first*(i-s.top().second));
			ts = s.top().second;
			s.pop();
		}
		s.push({t,ts});
	}
	while(!s.empty()){
		ans = max(ans,s.top().first*(n-s.top().second));
		s.pop();
	}
	cout << ans << '\n';
   return 0;
}


