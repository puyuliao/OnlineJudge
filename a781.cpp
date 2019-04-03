#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

char c1[80];
char c2[80];

int main()
{
	IOS;
	int n;
	while(cin >> n && n){
		char c1c ='#';
		char c2c ='.';
		for(int i=0;i<8;i++){
			swap(c1c,c2c);
			
			for(int j=0;j<n;j++){
				c1[i*n+j] = c1c;
				c2[i*n+j] = c2c;
			}
		}
		c1[n<<3] = c2[n<<3] = '\0';
		for(int i=0;i<8;i++){
			if(i&1) for(int j=0;j<n;j++) cout << c1 << '\n';
			else for(int j=0;j<n;j++) cout << c2 << '\n';
		}
		cout << '\n';
	}

   return 0;
}


