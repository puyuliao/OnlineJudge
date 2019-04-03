#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

map<int,map<int,int> > maap;
map<string,int> ginput;
map<string,int> ainput;
map<int,string> gin;
map<int,string> ain;

int main()
{
	IOS;
	int n,t;
	string ani,gru;
	while(cin >> n){
		maap.clear();
		ginput.clear();
		ainput.clear();
		gin.clear();
		ain.clear();
		for(int i=1;i<=n;i++){
			cin >> ani >> t >> gru;
			if(!ginput[gru]) ginput[gru] = i,gin[i] = gru;
			if(!ainput[ani]) ainput[ani] = i,ain[i] = ani;
			maap[ginput[gru]][ainput[ani]] += t;
		}
		for(auto i : maap){
			cout << gin[i.first] << " : ";
			int tmp = 0;
			for(auto j : i.second)
				if(!tmp) tmp = 1,cout << ain[j.first] << ' ' << j.second;
				else cout << ", " << ain[j.first] << ' ' << j.second;
			cout << '\n';
		}
	}

   return 0;
}


