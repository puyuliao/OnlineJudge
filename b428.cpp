#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000

char a[N+1],b[N+1];

int main()
{
	IOS;
	while(cin >> a >> b){
		cout << (int)(b[0] - a[0] + 26)%26 << '\n';
	}

   return 0;
}


