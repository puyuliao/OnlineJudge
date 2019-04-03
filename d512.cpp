#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 20

unordered_set<int> s;
int in[N];

int main()
{
	IOS;
	int n;
	while(cin >> n){
		s.clear();
		for(int i=0;i<n;i++) cin >> in[i];
		int t = 1 << n;
		for(int i=1;i<t;i++){
			int sum = 0;
			for(int j = 0;j<n;j++){
				if(i & (1 << j)) sum += in[j];
			}
			s.insert(sum);
		}
		//for(int i : s) cout << i << ' ';
		cout << s.size() << '\n';
	}

   return 0;
}


