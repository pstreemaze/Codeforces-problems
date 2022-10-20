#include <iostream>
using namespace std;
int max(int arr[],int n){
    int a = arr[0];
    for(int i =1;i<n;i++){
        a = max(a,arr[i]);
    }
    return a;
}
int main(){
    int t;
    cin>>t;
    for(int i =0;i<t;i++){
        int n;
        cin>>n;
        int arr[n];
        arr[n-1] = n;
        arr[n-2] = n-1;
        if(n%2==0){
            for(int i =0;i<n-2;i++){
                arr[i] = n-2-i;
            }
        }else{
            arr[0] = 1;
            for(int i =1;i<n-2;i++){
                arr[i] = n-1-i;
            }
        }
        for(int i =0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
}
