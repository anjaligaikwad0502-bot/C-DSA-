#include<iostream>
using namespace std;

int binary(int arr[],int start,int end,int tar){
    if(start>end){
        return -1 ;
    }
    int mid=start+(end-start)/2;
    if(arr[mid]==tar){
        return mid;
    }
    else if(arr[mid]>tar){
        return binary(arr,start,mid-1,tar);
    }
    else if(arr[mid]<tar){
        return binary(arr,mid+1,end,tar);
    }    
}
int main(){
    int arr[]={-1,0,4,5,9};
    int tar=5;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result=binary(arr,0,n-1,tar);
    if(result!=-1){
        cout<<"element is fount at index"<<result;

    }
   else{
    cout<<"element not found";
   }

    return 0;
}