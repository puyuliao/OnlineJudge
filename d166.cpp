#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

int in[51];
int top;
int ans[51];

int main()
{
	IOS;
	string s;
	while(getline(cin,s)){
		stringstream ss(s);
		top = 0;
		while(ss >> in[top]) top++;
		if(top == 0) continue;
		if(top == 1 && in[top-1] == -1) break;
		memset(ans,0,sizeof(ans));
		for(int i=0;i<top;i++){
			int k,l;
			if(in[i] == 0 && !ans[0]){
				ans[0] = i+1;
				continue;
			}
			for(k=0,l = 0;true;k++) {
				if(!ans[k]) l++;
				if(l == in[i]) break;
			}
			k++;
			while(ans[k]) k++;
			ans[k] = i+1;
		}
		for(int i=0;i<top;i++) cout << ans[i] << ' ';
		cout << '\n';
	}

   return 0;
}


