#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	//IOS;
	int T,a,b;
	char c[2];
	scanf("%d",&T);
	while(T--){
		scanf("%X%s%X",&a,c,&b);
		bitset<13> ba(a);
		bitset<13> bb(b);
		if(c[0] == '+') printf("%s %s %s = %d\n",ba.to_string().c_str(),c,bb.to_string().c_str(),a+b);
		else            printf("%s %s %s = %d\n",ba.to_string().c_str(),c,bb.to_string().c_str(),a-b);
	}

   return 0;
}


