#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

int n,x;
bitset<500> bs;

bool chk(int m){
	int t = n-1;
	bs.reset();
	bs[0] = true;
	for(int i=0;t>1;){
		for(int j=m;;) {
			if(!bs[i]) j--;
			if(j==0) break;
			i = (i+1)%n;
		}
		if(i == x) return false;
		bs[i] = true;
		t--;
	}
	return true;
}

int main()
{
	//IOS;
	while(cin >> n >> x && (n||x)){
		x--;
		int m = 1;
		for(;!chk(m);m++);
		cout << m << '\n';
	}

   return 0;
}


