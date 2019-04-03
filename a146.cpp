#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

multiset<int> s;
int in[N];
int mn[N];
int mx[N];

int main()
{
	//IOS;
	int n,m,t;
	while(cin >> n >> m){
		s.clear();
		if(m >= n){
			while(n--){
				cin >> t;
				s.insert(t);
			}
			cout << *s.begin() << '\n' << *(--s.end()) << '\n'; 
			continue;
		}
		for(int i=0;i<n;i++) cin >> in[i];
		for(int i=0;i<m;i++) s.insert(in[i]);
		mn[0] = *s.begin(); mx[0] = *(--s.end());
		for(int j=0,i=m;i<n;i++,j++){
			s.insert(in[i]);
			s.erase(s.find(in[j]));
			mn[j+1] = *s.begin();
			mx[j+1] = *(--s.end());
		}
		for(int i=0;i<=n-m;i++) cout << mn[i] << ' '; cout << '\n';
		for(int i=0;i<=n-m;i++) cout << mx[i] << ' '; cout << '\n';
	}

   return 0;
}


