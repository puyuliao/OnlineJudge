#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000
#define push_back emplace_back

vector<int> a,b;

int main()
{
	IOS;
	int n,s,h;
	cin >> n;
	while(n--){
		cin >> s >> h;
		if(s == 1) a.push_back(h);
		else b.push_back(h);
	} 
	int k;
	cin >> k;
	nth_element(a.begin(),a.end()-k,a.end());
	nth_element(b.begin(),b.end()-k,b.end());
	if(*(a.end()-k) >= *(b.end()-k)) cout << "1 " << *(a.end()-k) - *(b.end()-k) << '\n';
	else cout << "2 " << *(b.end()-k) - *(a.end()-k) << '\n';
   return 0;
}


