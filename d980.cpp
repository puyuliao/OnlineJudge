#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int T,in[3],cnt = 0;
	cin >> T;
	while(T--){
		for(int i=0;i<3;i++) cin >> in[i];
		sort(in,in+3);
		cout << "Case " << (++cnt) << ": ";
		if(in[0] <= 0 || in[0]+in[1] < in[2]) cout << "Invalid\n";
		else if(in[0] == in[1] && in[1] == in[2]) cout << "Equilateral\n";
		else if(in[0] != in[1] && in[1] != in[2] && in[2] != in[0]) cout << "Scalene\n";
		else cout << "Isosceles\n";
	}

   return 0;
}


