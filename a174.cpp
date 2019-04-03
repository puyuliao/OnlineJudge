#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define M 200

set<int> s[200];
set<int>::iterator it;

int main()
{
	int n,m,t,cmd;
	while(scanf("%d%d",&n,&m) == 2){
		while(n--){
			scanf("%d",&cmd);
			if(cmd == 1){
				scanf("%d",&t);
				s[t%m].insert(t);
				continue;
			}
			if(cmd == 2){
				scanf("%d",&t);
				it = s[t%m].find(t);
				if(it != s[t%m].end()) s[t%m].erase(it);
				continue;
			}
			printf("===== s =====\n");
			for(int i = 0; i < m; i++){
				printf("[%03d]:",i);
				for(int it : s[i]) printf("%d -> ",it);
				printf("NULL\n");
			}
			printf("===== e =====\n");
		}
	}

   return 0;
}


