#include<iostream>
using namespace std;
int factorial(int n){
    if(n==1||n==0){
        
         return 1 ;
    }
    cout<< n <<"*"<<n-1<<"!"<<"\n";
    return n*factorial(n-1);
    
}
int main(){
    
    cout<<factorial(8);
    return 0;
}