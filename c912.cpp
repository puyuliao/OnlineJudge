#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	string in;
	cin >> in;
	stack<pair<int,int> > s;
	int ans = 0,tmp,kil,lst;
	int now = 0;
	for(char i : in){
		if(i == 'H') {
			//cout << now << ' ';
			lst = kil = tmp = 0;
			while(!s.empty() && now > s.top().first){
				tmp += (now - s.top().first)*s.top().second;
				kil += s.top().second;
				lst = s.top().first;
				s.pop();
			}
			if(!s.empty()) ans += tmp;
			else ans += tmp-(now-lst)*kil;
			s.push({now,kil+1});
			if(now == 0) while(!s.empty()) s.pop();
			//cout << "(" << ans << ") ";
		}
		else if(i == 'U') now++;
		else now--;
	} 
	cout << ans << '\n';
   return 0;
}
