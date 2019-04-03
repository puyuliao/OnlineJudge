#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

bool chk(int a,int b){
	int g = __gcd(a,b);
	b/=g;
	while(b%2==0)b/=2;
	while(b%5==0)b/=5;
	return b==1;
}

int cyclen(int a,int b){
	unordered_map<int,int> m;
	int len = 0;
	m[a] = len;
	while(true){
		a = a*10%b;
		len++;
		if(m.count(a)) break;
		m[a] = len;
	}
	return len - m[a];
}

int main()
{
	//IOS;
	int a,b,k,t,cnt;
	while(cin >> a >> b && (a||b)){
		cout << '.';
		if(chk(a,b)){
			while(a){
				a*=10;
				cout << a/b;
				a%=b;
			}
			cout << "\nThis expansion terminates.\n";
			continue;
		}
		k = cyclen(a,b); 
		t = a;
		cnt = 1;
		for(int i=0;i<k;i++){
			a*=10;
			cout << a/b;
			cnt++;
			if(cnt == 50){
				cout << '\n';
				cnt = 0;
			}
			a%=b;
		}
		for(int i=k;;i++){
			if(t == a) break;
			t *= 10; a *= 10;
			cout << a/b;
			cnt++;
			if(cnt == 50){
				cout << '\n';
				cnt = 0;
			} 
			a%=b; t%=b;
		}
		if(cnt!=0) cout << '\n';
		cout << "The last " << k << " digits repeat forever.\n";
	}

   return 0;
}


