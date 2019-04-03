#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 20

int in[N][N];

bool chk(int n,int m){
	for(int i=0,a=n-1;i<n;i++,a--)
		for(int j=0,b=m-1;j<m;j++,b--){
			if(in[i][j] != in[a][b]) return false;
		}
	return true;
}

int main()
{
	IOS;
	int T,n,m;
	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin >> in[i][j];
		cout << (chk(n,m)?"go forward\n":"keep defending\n");
	}

   return 0;
}


