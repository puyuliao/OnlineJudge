#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int sz;
int maap[128];
char in[N];

int main()
{
	IOS;
	while(cin.getline(in,sizeof(in))){
		sz = 0;
		memset(maap,0,sizeof(maap));
		for(int i=0;in[i];i++) {
			if(isalpha(in[i]))maap[tolower(in[i])]++,sz++;
		}
		for(int i='a';i<='z';i++) cout << maap[i] << ' ';
		cout << '\n';
		for(int i='a';i<='z';i++) cout << fixed << setprecision(2) << (double)maap[i]/sz*100 << ' ';
		cout << '\n';
	}
	
   return 0;
}


