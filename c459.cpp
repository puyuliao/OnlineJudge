#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000

string str;

void con(int s,int b){
	while(s){
		str += (char)('0' + s%b);
		s/=b;
	}
	reverse(str.begin(),str.end());
}

int main()
{
	IOS;
	int b;
	string n;
	cin >> b >> n;
	int sum = 0;
	for(char i : n){
		sum += pow(i-48,n.size())+.5;
	}
	con(sum,b);
	if(str == n) cout << "YES\n";
	else cout << "NO\n";

   return 0;
}


