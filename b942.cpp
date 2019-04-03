#include<bits/stdc++.h>
using namespace std;

int sum,t;
bitset<60001> bs;
string s;
int main()
{
	cin.tie(0);ios_base::sync_with_stdio(false);
	while(getline(cin,s)){
		bs.reset();
		stringstream ss(s);
		bs[0] = 1; sum = 0;
		while(ss >> t){
			bs |= (bs << t);
			sum += t;
		}
		int i;
		for(i = sum>>1;i>=0;i--) if(bs[i]) break;
		cout << (long long)(sum-i)*i << '\n';	
	}
  return 0;
}
