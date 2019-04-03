#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 25

pair<int,int> dealt[N];
int nowend[N];

int main()
{
	IOS;
	int n,a,b; 
	while(cin >> n){
		int r = 0,br = -1;
		for(int i=0;i<n;i++) cin >> dealt[i].first, dealt[i].second = i;
		sort(dealt,dealt+n,greater<pair<int,int> >());
		//for(int i=0;i<n;i++) cout << complex<int>(dealt[i].first,dealt[i].second) << ' ';
		memset(nowend,0,sizeof(nowend));
		while(cin >> a >> b && (a||b)){
			int mn = (1<<30)+667, bst = -1; 
			for(int i=0;i<n;i++) if(mn > max(a,nowend[i]) + 5 + ((b+dealt[i].first-1)/dealt[i].first)){
				mn = max(a,nowend[i]) + 5 + ((b+dealt[i].first-1)/dealt[i].first);
				bst = i;
			}
			if(r < max(nowend[bst],a) + 5) r = max(nowend[bst],a)+5, br = dealt[bst].second + 1;
			nowend[bst] = mn+10;
			//cout << bst << ' ' << nowend[bst] << '\n';
		}
		cout << r << ' ' << br << '\n';
	}

   return 0;
}


