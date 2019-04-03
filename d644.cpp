#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define mod 100019

vector<int> v;

int main()
{
	//IOS;
	v.push_back(0);
	v.push_back(1);
	for(int j=2;;j++){
		int i = v[v.size()-1] + v[v.size()-2];
		if(j % 3 == 1) i--;
		if(i < 0) i += mod;
		i %= mod;
		v.push_back(i);
		if(v[v.size()-1] == 1 && v[v.size()-2] == 0 && j % 3 == 2) break;
		if(v.size() > 1e8){
			cout << "OO";
			break;
		}
	}
	cout << v.size() << '\n';
	int n;
	while(cin >> n){
		cout << v[n % v.size()] << '\n';
	}
   return 0;
}


