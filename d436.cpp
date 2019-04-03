#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

char in[11];

int main()
{
	IOS;
	int T,n;
	cin >> T;
	while(T--){
		cin >> in;
		n = strlen(in);
		sort(in,in+n);
		do{
			cout << in << '\n';
		}while(next_permutation(in,in+n));
		cout << '\n';
	}

   return 0;
}


