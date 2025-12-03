#include<iostream>
using namespace std;
int Sum(int n){
    if(n==1){
        return 1;
    }
    cout<<n<<"+"<<n-1<<"\n";
    return n + Sum(n-1);
    
}
int main(){
    
    cout<<Sum(8);
    return 0;
}