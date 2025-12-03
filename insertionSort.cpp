#include<iostream>
using namespace std;
void insertionSort(int n,int arr[]){
    // cout<<"Insertion Sort:"<<endl;
    for(int i=1;i<n;i++){
        int current=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>current){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=current;
    }

}
void printArray(int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;
}
int main(){
    int n=5;
    int arr[]={4,1,5,2,3};
    cout<<"\nthe original array:";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<"\nthe sorted array:";
    insertionSort(n,arr);
    printArray(arr,n);
    return 0;
}