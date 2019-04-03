#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 10001
#define MP make_pair

int n;
vector<pair<int,int> > v[N];
bool inq[N];
int mx[N];

int SPFA(int a,int b){
	memset(mx,-1,sizeof(mx));
	memset(inq,false,sizeof(inq));
	inq[a] = true; mx[a] = 66666666;
	queue<int> q; q.push(a);
	while(!q.empty()){
		int x = q.front(); q.pop(); inq[x] = false;
		for(auto i : v[x]){
			if(min(mx[x],i.second) > mx[i.first]){
				mx[i.first] = min(mx[x],i.second);
				if(!inq[i.first]) {
					inq[i.first] = true;
					q.push(i.first);
				}
			}
		}
	}
	return mx[b];
}

int main()
{
	IOS;
	int m,a,b,w,q;
	cin >> n >> m;
	while(m--){
		cin >> a >> b >> w;
		v[a].push_back(MP(b,w));
		v[b].push_back(MP(a,w));
	}
	cin >> q;
	while(q--){
		cin >> a >> b;
		cout << SPFA(a,b) << '\n';
	}

   return 0;
}


