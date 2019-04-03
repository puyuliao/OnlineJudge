#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 4
	
char M[N],in[N];	
bool mch[N];

int main()
{
	IOS;
	int n;
	for(int i=0;i<N;i++) cin >> M[i];
	cin >> n;
	while(n--){
		for(int i=0;i<N;i++) cin >> in[i],mch[i] = false;
		int a = 0,b = 0;
		for(int i=0;i<N;i++) if(M[i] == in[i]){
			mch[i] = true;
			a++;
		}		
		for(int i=0;i<N;i++) if(!mch[i]){
			for(int j=0;j<N;j++) if(!mch[j] && i != j && M[i] == in[j]) b++;
		}
		cout << a << "A" << b << "B" << '\n';
	}

   return 0;
}


