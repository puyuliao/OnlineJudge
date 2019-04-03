#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 10001

int64_t sum,ssum;
int t,t1,t2,n;
int in[N];
multiset<int> s;
string str;

int clo(int t){
	multiset<int>::iterator it = s.lower_bound(t);
	multiset<int>::iterator it2 = s.upper_bound(t);
	if(it == s.end()) return *--it;
	if(it2 == s.begin()) return *it;
	it2--;
	if(*it - t > t - *it2) return *it2;
	return *it; 
}

int main()
{
	cin.tie(0);ios_base::sync_with_stdio(false);
	while(getline(cin,str)){
		ssum = sum = n = 0; s.clear();
		stringstream ss(str);
		while(ss >> t) in[n++] = t,sum += t;
		s.insert(0);
		for(int i=0;i<n && sum != ssum;i++){
			t = in[i] - (sum-ssum>>1);
			if(t < 0){
				sum-=in[i];ssum+=in[i];
				s.insert(in[i]);
				continue;
			}
			t = clo(t);
			if((sum-in[i]+t)*(ssum-t+in[i]) <= sum*ssum) continue;
			sum-=in[i]-t;
			ssum+=in[i]-t;
			s.erase(s.find(t));
			s.insert(in[i]);
		}
		cout << sum*ssum << '\n';
	}
  return 0;
}
