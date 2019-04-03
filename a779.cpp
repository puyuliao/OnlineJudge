#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

int main()
{
	IOS;
	string in;
	while(getline(cin,in)){
		vector<char> v;
		for(int i=0;in[i];i++) if(isalpha(in[i]) || isdigit(in[i])) v.push_back(tolower(in[i]));
		int sz = v.size();
		bool k = true;
		for(int i=0,j=sz-1;i<j && k;i++,j--){
			if(v[i] != v[j]) k = false;
		}
		if(k) cout << in << "\n-- is a palindrome\n";
		else cout << in << "\n-- is not a palindrome\n";
	}

   return 0;
}


