#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100

 

int main()
{
	IOS;
	int n;
	int64_t in[4];
	cin >> n;
	while(n--){
		for(int i=0;i<4;i++) cin >> in[i];
		sort(in,in+4);
		if(in[0]<=0 || in[0]+in[1]+in[2] <= in[3]) cout << "banana\n";
		else if(in[0] == in[1] && in[1] == in[2] && in[2] == in[3]) cout << "square\n";
		else if(in[0] == in[1] && in[3] == in[2]) cout << "rectangle\n";
		else cout << "quadrangle\n";
	}
   return 0;
}


