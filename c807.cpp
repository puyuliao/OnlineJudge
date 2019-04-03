#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000

set<int> s;

int main()
{
	IOS;
	int T,cmd,l,r;
	cin >> T;
	while(T--){
		cin >> cmd;
		if(cmd == 1){
			cin >> l;
			s.insert(l);
		}
		else{
			cin >> l >> r;
			for(auto it = s.lower_bound(l);it != s.end() && *it <= r;){
				auto t = it;
				++it;
				s.erase(t);
			}
		}
		if(s.size() == 0) cout << 0 << '\n';
		else if(s.size() == 1) cout << 1 << ' ' << *s.begin() << '\n';
		else cout << 2 << ' ' << *s.begin() << ' ' << *--s.end() << '\n';
	}
   return 0;
}
