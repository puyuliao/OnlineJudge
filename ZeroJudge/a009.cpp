#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 10000

char in[N];

int main()
{
	const int K = -7;
	IOS;
	while(cin.getline(in,sizeof(in))){
		for(int i=0;in[i];i++){
			in[i] += K;
		}
		cout << in << '\n';
	}

   return 0;
}


