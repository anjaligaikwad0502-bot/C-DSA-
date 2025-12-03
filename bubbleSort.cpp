#include <iostream>
using namespace std;
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool isSwap=false;
        cout<<"\nPass"<<i+1<<":";
        for(int j=0;j<n-i-1;j++){
            cout<<"\nIteration"<<j+1<<":";
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                isSwap=true;
            }
            for(int k=0;k<n;k++){
                cout<<arr[k]<<"  ";
            }
            
        }
        if(!isSwap){
                cout<<"\nThe array is already sorted.";
        }
    }
    
}
void printSort(int arr[],int n){
    cout<<"\nthe final sorted array is:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}
int main() {
   int n=5;
   int arr[]={6,4,9,2,5};
   cout<<"the original array is:";
   for(int i=0;i<n;i++){
       cout<<arr[i]<<"  ";
   }
   bubbleSort(arr,n);
   printSort(arr,n);
   
   
    return 0;
}