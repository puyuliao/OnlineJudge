#include <iostream>
#include <string>
#include <algorithm>
#define MAX 2001
int lis[MAX],lds[MAX],train[MAX];
//lis[i]�N��train[0]��train[i]�̪������W���סC
//lds[i]�N��train[0]��train[i]�̪���������סC 
using namespace std;
int main() {
  int m,n;
  cin >> m;
  for(int i=0;i<m;i++){
    cin >> n;
    for(int j=n-1;j>=0;j--){//�s�[�J����᭱ 
      cin >> train[j];              
    }      
    for(int j=0;j<n;j++){
      lis[j]=1;
      lds[j]=1;                    
    }      
    for(int j=0;j<n;j++){    
      for(int k=j+1;k<n;k++){
        if (train[j]>train[k]){   //�]��train�O�ѫ��e��J 
          lis[k]=max(lis[k],lis[j]+1); //LIS �̪����W�l�r��                      
        }
        if (train[j]<train[k]){
          lds[k]=max(lds[k],lds[j]+1); //LDS �̪����W�l�r��     
        }        
      }                    
    }
    int max=0;//lds[j]��ܥN��train[0]��train[j]�̪���������סC
    for(int j=0;j<n;j++){ //lds[j]��ܥN��train[0]��train[j]�̪������W���סC  
      if (max<lis[j]+lds[j]-1) max=lis[j]+lds[j]-1;  //��1�A�]��train[j]���ƺ�     
    }
    cout << max <<endl;      
  }
  //system("pause");
}
