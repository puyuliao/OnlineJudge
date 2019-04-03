#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}

int in[20001];
int s[20001];
int ts[20001];
int tmp[20001];
int n,k;

int merge_sort(int l,int r,int m){
	if(l >= r-1) return (ts[l]>m)?1:0;
	int mid = l+r>>1;
	int cnt = 0;
	cnt += merge_sort(l,mid,m);
	cnt += merge_sort(mid,r,m);
	
	for(int i = l,j = mid;j<r&&i<mid;){
		if(ts[j] - ts[i] > m) cnt+=r-j,i++;
		else j++;
	}
	memcpy(tmp+l,ts+l,r-l<<2);
	merge(tmp+l,tmp+mid,tmp+mid,tmp+r,ts+l);
	return cnt;
}

bool chk(int m){
	memcpy(ts,s,n+1<<2);
	int cnt = merge_sort(1,n+1,m);
	return cnt+1 > k;
}

void DEBUG(){
	vector<int> v;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++) v.push_back(s[j]-s[i]); 
	}
	sort(v.begin(),v.end());
	for(int i : v) cout << i << ' ';
	cout << '\n';
}

int main()
{
	//IOS;
	int l,r,last,t;
	string str;
	while(getline(cin,str)){
		n = 0;
		stringstream ss(str);
		while(ss >> t) in[++n] = t;
		k = n*(n+1)/4;
		for(int i=1;i<=n;i++) s[i] = s[i-1]+in[i];
		l = r = 0;
		for(int i=1;i<=n;i++){
			last = max(0,last+in[i]);
			r = max(r,last);
		}
		for(int i=1;i<=n;i++){
			last = min(0,last+in[i]);
			l = min(l,last);
		}
		while(l < r){
			int mid = l+r>>1;
			if(chk(mid)) l = mid+1;
			else r = mid;
		}
		cout << l << '\n';
		DEBUG();
	}
  return 0;
}
