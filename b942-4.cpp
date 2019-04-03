#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 10000
#define INF 0x7fffffff

unordered_map<int,int> dp;
int n,sum;
int in[N];

int64_t hh(int n,int m){
	return ((int64_t)n<<31) + m - n;
}

int f(int i,int j){
	int64_t h = hh(i,j);
	if(i<0) return dp[h] = 0;
	if(dp.count(h)) return dp[h];
	if(j >= in[i]) dp[h] = max(f(i-1,j),f(i-1,j-in[i]) + in[i]);
	else dp[h] = f(i-1,j);
	//cout << "(" << i << ", " << j << ")" << " = " << dp[h] << '\n';
	return dp[h];
}

int main()
{
	IOS;
	srand(time(NULL));
	string s; int t;
	while(getline(cin,s)){
		dp.clear(); dp[0] = 0;
		stringstream ss(s);
		n = sum = 0;
		while(ss >> t) in[n++] = t,sum+=t;
		sort(in,in+n);
		f(n-1,sum>>1);
		cout << (int64_t)dp[hh(n-1,sum>>1)]*(sum - dp[hh(n-1,sum>>1)] ) << '\n';
		//cout << dp.size() << '\n';
	}

   return 0;
}


