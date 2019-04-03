#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

bool dp[20002];

int main()
{
	//IOS;
	int a,b,c;
	bool bl;
	while(cin >> a >> b >> c){
		bl = true;
		if(__gcd(a,b) != 1) {
			cout << "No\n";
			continue;
		}
		for(int i=c;i<=20000;i++){
			if(i == a*b-a-b){
				cout << "No\n";
				bl = false;
				break;	
			}
		}
		if(bl) cout << "Yes\n";
	}
   return 0;
}


