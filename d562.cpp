#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int n,t;
	while(cin >> n){
		deque<int> v;
		while(n--){
			cin >> t;
			v.push_back(t);
		}
		while(v.size()){
			for(int i : v) cout << i << ' ';
			cout << '\n';
			v.pop_front();
			reverse(v.begin(),v.end());
		}
		cout << '\n';
	}

   return 0;
}


