#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int T,a,b,cnt = 0;
	cin >> T;
	while(T--){
		cin >> a >> b;
		if(!(a&1)) a++;
		if(!(b&1)) b--;
		cout << "Case " << (++cnt) << ": ";
		cout << (b*b-a*a+a+a+b+b>>2) << '\n';
	}
	
   return 0;
}


