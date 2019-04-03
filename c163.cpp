#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000

unordered_set<int> s;
int ans;
vector<int> in;
mt19937 rd(time(NULL));

int main()
{
	IOS;
	int n;
	cin >> n;
	in.resize(n);
	for(int i=0;i<n;i++) cin >> in[i],s.insert(in[i]);
	sort(in.begin(),in.end());
	for(int i=0;i<1000000 && s.size() > 2;i++){
		int a = rd()%n, b = (a+rd()%(n-1)+1)%n;
		auto it = s.find(in[a] + in[b]);
		if(it != s.end()) s.erase(it),ans++;
	}
//	for(int i : s){
//		int l = 0, r = upper_bound(in.begin(),in.end(),i) - in.begin();
//		for(r--;;r--){
//			while(in[l] + in[r] < i && l < r) l++;
//			if(r <= l) break;
//			if(in[l] + in[r] == i) {
//				ans++;
//				break;
//			}
//		}
//	}
	cout << ans << '\n';
   return 0;
}
