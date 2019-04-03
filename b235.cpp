#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

bitset<N> bs;
vector<int> prime;
vector<int> avgprime;

void pbuild(){
	bs[0] = bs[1] = true;
	for(int i=2;i<N;i++){
		if(!bs[i]) prime.push_back(i);
		for(int j=0;i*prime[j]<N;j++){
			bs[i*prime[j]] = true;
			if(i % prime[j] == 0) break; 
		}
	}
}

bool chk(int n){
	if(bs[n]) return false;
	int t = n<<1;
	for(int i : prime){
		if(i>=n) break;
		if(!bs[t-i]) return true;
	}
	
	return false;
}

int main()
{
	IOS;
	pbuild();
	avgprime.push_back(2);
	for(int i=5;avgprime.size() <= 450;i++){
		if(chk(i)) avgprime.push_back(i);
	}
	int n,T;
	cin >> T;
	while(T--){
		cin >> n;
		cout << avgprime[n] << '\n';
	}
   return 0;
}


