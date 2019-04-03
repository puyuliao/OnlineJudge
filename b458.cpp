#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

struct pix{
	int r,g,b;
}in[256][256];

int main()
{
	IOS;
	int t,n,m;
	while(cin >> t >> n >> m){
		for(int i=0;i<m;i++) 
			for(int j=0;j<n;j++) cin >> in[i][j].r >> in[i][j].g >> in[i][j].b;
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				if(in[i][j].r + in[i][j].g + in[i][j].b >= 3*t) cout << "255 255 255 ";
				else cout << "0 0 0 ";
			}
			cout << '\n';
		}
	}
	
   return 0;
}


