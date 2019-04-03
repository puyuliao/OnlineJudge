#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 10001

char s[N<<4];
int64_t in[N];
unordered_set<int64_t> dp;
vector<int64_t> v;
int64_t n,t,m;

int main()
{
	//IOS;
	
	while(cin.getline(s,sizeof(s))){
		n = m = 0;
		for(int i=0;s[i];i++){
			if(isdigit(s[i])){
				t = s[i++] - 48;
				while(isdigit(s[i])) t = t*10 + s[i++] - 48;
				in[n++] = t;
				m+=t;
			}
		}
		dp.clear();
		dp.insert(0);
		for(int i=0;i<n;i++){
			v.clear();
			for(int j : dp) if(j + in[i] <= m) v.push_back(j + in[i]);
			for(int j : v) dp.insert(j);
		}
		vector<int> vv(dp.begin(),dp.end());
		sort(vv.begin(),vv.end());
		t = *lower_bound(vv.begin(),vv.end(),m>>1);
		cout << t*(m-t) << '\n';
	}

   return 0;
}
