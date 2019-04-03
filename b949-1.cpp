#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

void print(__int128 ans){
	static int64_t s[40];
	int top = 0;
	while(ans > 0){
		s[top++] = ans%10000000000000000ll;
		ans/=10000000000000000ll;
	}
	cout << s[top-1]; 
	for(int i=top-2;i>=0;i--) cout << setfill('0') << setw(16) << s[i];
	cout << '\n';
}

int main()
{
	IOS;
	int n;
	__int128 ans;
	while(cin >> n){
		ans = n;
		ans = ans*ans*25;
		print(ans);
	}

   return 0;
}


