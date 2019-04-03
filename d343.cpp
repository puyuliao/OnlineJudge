#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 6
#define S 31
#define M 4

int now[N];

int state(){
	int x = 0;
	for(int i=0;i<N;i++) x = x*10 + now[i];
	return x;
}

unordered_map<int,bool> mp;
bool dfs(int sum){
	int t = state();
	if(mp.count(t)) return mp[t];
	mp[t] = true;
	for(int i = 0;i<N;i++){
		if(!now[i] || sum + i + 1 > S) continue;
		else{now[i]--; mp[t] &= dfs(sum+i+1); now[i]++;}
	}
	//for(int i = 0;i<N;i++) cout << M - now[i] << ' ';
	//cout << sum << ' ' << (mp[t]?"false\n":"true\n");
	return mp[t]^=1; 
}

int main()
{
	IOS;
	char in[128];
	while(cin >> in){
		fill(now,now+N,M); int sum = 0,p = 0;
		for(int i=0;in[i];i++,p^=1) now[in[i] - '1']--,sum += in[i] - '0';
		cout << in << ' ' << ((dfs(sum) ^ p)?"A\n":"B\n");
	}
   return 0;
}


