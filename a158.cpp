#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 40

char ia[N];
char ib[N];

bool spa(char *a){
	for(int i=0;a[i];i++) if(a[i] == ' ') return false;
	return true;
}

int sssstrcmp(char* a,char* b){
	int i,j;
	for(i=0,j=0;a[i] && b[j];i++){
		if(a[i] == ' ') continue;
		if(a[i]!=b[j]) return a[i] - b[j];
		j++;
	}
	return a[i] - b[j];
}

int main()
{
	IOS;
	int T,cnt = 0;
	cin >> T;
	cin.getline(ia,10);
	while(T--){
		cin.getline(ia,sizeof(ia));
		cin.getline(ib,sizeof(ib));
		cout << "Case " << (++cnt) << ": ";
		if(!spa(ia)){
			if(sssstrcmp(ia,ib)!=0) cout << "Wrong Answer\n";
			else cout << "Output Format Error\n";
			continue;
		}
		
		if(sssstrcmp(ia,ib)!=0) cout << "Wrong Answer\n";
		else cout << "Yes\n";
	}
   return 0;
}


