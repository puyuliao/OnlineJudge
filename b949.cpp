#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	//IOS;
	char in[40];
	int64_t t[40];
	while(cin>>in) {
		memset(t,0,sizeof(t));
		int n = strlen(in);
		reverse(in,in+n);
		//for(int i=0;i<n;i++) t[i] = in[i] - '0';
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				t[i+j] += (in[i]-'0')*(in[j]-'0');
				t[i+j] *= 25;
			}
		}
		n = 2*n-1;
		for(int i=0;i<n;i++){
			if(t[i] > 9) t[i+1]+=t[i]/10,t[i]%=10; 
		}
		if(t[n]) n++;
		for(int i=n-1;i>=0;i--){
			cout << t[i];
		}
		cout << '\n';
	}

   return 0;
}


