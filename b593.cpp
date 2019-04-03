#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

char in[30];

bool chk(){
	in[0] = tolower(in[0]);
	for(int i=1;in[i];i++) {
		in[i] = tolower(in[i]);
		if(in[i-1]>in[i]) return false;
	}
		
	return true;
}

int main()
{
	IOS;
	int64_t ans;
	while(cin >> in && in[0] != '0'){
		if(!chk()) {
			cout << "0\n";
			continue;
		}
		ans = 0;
		for(int i=0;in[i];i++){
			ans = ans*26+in[i]-'a'+1;
		}
		cout << ans <<'\n';
	}

   return 0;
}


