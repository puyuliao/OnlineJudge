#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define MAXN 100001
 
int in[MAXN];
int tmp[MAXN];
int64_t ans;
 
void merge_sort(int *a,int s,int e){
	if(e <= s+1) return;
	if(e == s+2) {
		if(a[s]>a[s+1]){
			swap(a[s],a[s+1]);
			ans++;
		}
		return;
	}
	int mid = s+e>>1;
	merge_sort(a,s,mid);
	merge_sort(a,mid,e);
	int i = s,j = mid,k = 0;
	while(i < mid && j < e){
		if(a[i]>a[j]) {
			tmp[k++] = a[j++];
			ans+=mid-i;
		}
		else tmp[k++] = a[i++];
	}
	while(i<mid){
		tmp[k++] = a[i++];
	}
	while(j<e){
		tmp[k++] = a[j++];
	}
	for(int x = s,y=0;y<k;x++,y++){
		a[x] = tmp[y];
	}
}
 
int main()
{
	IOS;
	int n;
	while(cin >> n && n){
		for(int i=0;i<n;i++){
			cin >> in[i];
		}
		ans = 0;
		merge_sort(in,0,n);
		cout << ((ans&1)?"Marcelo":"Carlos");
	}
  return 0;
}
