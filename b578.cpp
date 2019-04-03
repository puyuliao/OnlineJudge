#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#define maxn 4294967296ll

int main()
{
	IOS;
	int T;
	uint64_t in[3];
	uint64_t dec;
	cin >> T;
	while(T--){
		cin >> in[0] >> in[1] >> in[2];
		sort(in,in+3);
		dec = (in[2]-in[0])*(in[2]+in[0]);
		if(in[1]>=maxn || in[1]*in[1] > dec) cout << "acute triangle\n";
		else if(in[1]*in[1] == dec) cout << "right triangle\n";
		else cout << "obtuse triangle\n";
	}

   return 0;
}


