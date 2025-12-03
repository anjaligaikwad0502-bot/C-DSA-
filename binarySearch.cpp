#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }  
        }
    }
}
void printSort(int arr[],int n){
    cout<<"\nthe final sorted array is:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}
int binarySearch(int tar,int arr[],int n){
    int st,end;
    st=0;
    end=n-1;
    while(st<=end){
        int mid=(st+end)/2;
        if(tar<arr[mid]){
            end=mid-1;
        }
        else if(tar>arr[mid]){
            st=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main() {
   int n=5;
   int tar=9;
   int arr[]={6,4,9,2,5};
   cout<<"the original array is:";
   for(int i=0;i<n;i++){
       cout<<arr[i]<<"  ";
   }
   bubbleSort(arr,n);
   printSort(arr,n);
   int result= binarySearch(tar,arr,n);
   if(result!=-1){
    cout<<"\nTarget "<<tar<<" is found at index "<<result;
   }
   else{
    cout<<"\nTarget "<<tar<<" is not found!!"<<endl;
   
   }
    return 0;
}



