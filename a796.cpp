#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 105

bitset<N> bs[N];
int deg[N];

int main()
{
	IOS;
	int n,m,q,a,b,cmd;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		bs[a][b] = bs[b][a] = 1;
		deg[a]++; deg[b]++;
	}
	cin >> q;
	for(int i=0;i<q;i++){
		cin >> cmd;
		if(cmd == 1){
			cin >> a;
			cout << deg[a] << '\n';
		}
		else{
			cin >> a >> b;
			cout << (bs[a][b]?"Yes\n":"No\n");
		}
	}
   return 0;
}


