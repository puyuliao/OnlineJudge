#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100

int in[N];
unordered_set<int> s;

int main()
{
	IOS;
	int n,cnt = 0;
	while(cin >> n){
		s.clear();
		bool ans = true;
		for(int i=0;i<n;i++) cin >> in[i];
		sort(in,in+n);
		if(in[0] < 1) ans = false;
		for(int i=1;i<n;i++) if(in[i] == in[i-1]) ans = false;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(s.count(in[i]+in[j])) {
					ans = false;
					break;
				}
				else s.insert(in[i]+in[j]);
			}
		}
		cout << "Case #" << ++cnt << ": ";
		if(ans && n) cout << "It is a B2-Sequence.\n";
		else cout << "It is not a B2-Sequence.\n";
	}

   return 0;
}


