#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

int n,m;

struct item{
	int k[200];
	bool operator <(const item &b)const{
		for(int i=0;i<m;i++) if(k[i] != b.k[i]) return k[i] < b.k[i];
		return false;
	}
}in[10000];

int main()
{
	IOS;
	while(cin >> n >> m){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> in[i].k[j];
			}
		}
		sort(in,in+n);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout << in[i].k[j] << ' ';
			}
			cout << '\n';
		}
	}
	

   return 0;
}


