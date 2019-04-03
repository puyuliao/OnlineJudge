#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100000

int main()
{
	IOS;
	int m,n,T,s;
	cin >> T;
	for(int c = 1;c<=T;c++){
		cin >> n >> m;
		int s = 0;
		for(int i=2;i<=n;i++){
			s = (s+m)%i;
		}
		cout << "Case " << c << ": " << s+1 << '\n';
	}

   return 0;
}


