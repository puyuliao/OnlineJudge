#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1001
#define M 51

int box[M],bs;
int item[N],si;
int n,m;
int cnt = 0;

bool dfs(int x,int pb){
	if(x<0) return true;
	int s = 0;
	if(~pb && item[x] == item[x+1]) s = pb;
	for(int i=s;i<m;i++){
		if(item[x] > box[i]) continue;
		box[i] -= item[x];
		bool r = dfs(x-1,i);
		box[i] += item[x];
		if(r) return true;
	}
	return false;
}

int main()
{
	//IOS;
	cin >> m >> n;
	for(int i=0;i<m;i++) cin >> box[i],bs += box[i];
	for(int i=0;i<n;i++) cin >> item[i];
	sort(item,item + n);
	int dep;
	for(dep = 0;dep < n;dep++) {
			si += item[dep];
		if( si > bs) break;

		if (!dfs(dep,-1)) break; 
	}
	cout << dep << '\n';

   return 0;
}
