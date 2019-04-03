#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#define MAXN 2201

vector<int> prime;
bool bs[MAXN]={true,true};

void build(){
	for(int i=2;i<MAXN;i++){
		if(!bs[i]) prime.push_back(i);
		for(int j=0;i*prime[j]<MAXN;j++){
			bs[i*prime[j]]=true;
			if(i%prime[j] == 0) break;
		}
	}
}

char in[2002];
int asc[128];

int main()
{
	build();
	IOS;
	int T,cnt = 0;
	bool f;
	cin >> T;
	while(T--){
		cin >> in;
		cout << "Case " << (++cnt) << ":\n";
		f = true;
		memset(asc,0,sizeof(asc));
		for(int i=0;in[i];i++) asc[in[i]]++;
		for(int i=0;i<128;i++) if(!bs[asc[i]]){
			cout << (char)(i);f = false;
		} 	
		if(f) cout << "empty";
		cout << '\n';
	}

   return 0;
}


