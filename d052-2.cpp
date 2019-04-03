#include <iostream>
#include <string>
#include <algorithm>
#define MAX 2001
int lis[MAX],lds[MAX],train[MAX];
//lis[i]代表train[0]到train[i]最長的遞增長度。
//lds[i]代表train[0]到train[i]最長的遞減長度。 
using namespace std;
int main() {
  int m,n;
  cin >> m;
  for(int i=0;i<m;i++){
    cin >> n;
    for(int j=n-1;j>=0;j--){//新加入的放後面 
      cin >> train[j];              
    }      
    for(int j=0;j<n;j++){
      lis[j]=1;
      lds[j]=1;                    
    }      
    for(int j=0;j<n;j++){    
      for(int k=j+1;k<n;k++){
        if (train[j]>train[k]){   //因為train是由後到前輸入 
          lis[k]=max(lis[k],lis[j]+1); //LIS 最長遞增子字串                      
        }
        if (train[j]<train[k]){
          lds[k]=max(lds[k],lds[j]+1); //LDS 最長遞增子字串     
        }        
      }                    
    }
    int max=0;//lds[j]表示代表train[0]到train[j]最長的遞減長度。
    for(int j=0;j<n;j++){ //lds[j]表示代表train[0]到train[j]最長的遞增長度。  
      if (max<lis[j]+lds[j]-1) max=lis[j]+lds[j]-1;  //減1，因為train[j]重複算     
    }
    cout << max <<endl;      
  }
  //system("pause");
}
