#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1002
int main()
{
	IOS;
	int w,n;
	string s;
	while(cin >> w >> s){
		n = s.size();
		int ans = 0;
		for(int i=0;i+w<n;i++) {
			int j = i-1, k = i+w;
			while(j >= 0 && k < n){
				if(s.substr(j,i-j) == s.substr(i+w,k-i-w+1)) ans++;
				j--; k++; 
			}
		}
		cout << ans << '\n';
	}
   return 0;
}
