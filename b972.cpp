#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 20

int n,t;
int g[N];


int main()
{
	IOS;
	int m,s;
	char c;
	cin >> n >> t;
	while(n--){
		for(int i=0;i<t;i++) {
			cin >> m >> c >> s;
			g[i] += m*60 + s;
		}
	}sort(g,g+t);
	for(int i=0;i<t;i++) cout << g[i] << '\n';

   return 0;
}


