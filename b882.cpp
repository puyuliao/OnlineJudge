#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

int main()
{
	//IOS;
	int64_t ans[3];
	cin >> ans[2] >> ans[1] >> ans[0];
	ans[1] += ans[0]/60; ans[0]%=60;
	ans[2] += ans[1]/60; ans[1]%=60;
	ans[2]%=24;
	printf("%02lld:%02lld:%02lld",ans[2],ans[1],ans[0]);

   return 0;
}


