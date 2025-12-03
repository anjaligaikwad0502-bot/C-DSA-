#include<iostream>
using namespace std;
# define size 5
class stack{
    int arr[size];
    int top=-1;
    public:
        bool isEmpty(){
            if(top ==-1){
                 return true;
            }else{
                return false;
            }
        }
        void push(int val){
            if(top ==size-1){
                cout<<"\nstack overflow";
            }else{
                top++;
                arr[top]=val;
            }
        }
        void pop(){
            if(isEmpty()){
            cout<<"\nstack underflow";
            }else{
                top--; 
            } 
        }
        void peek(){
            if(top==-1){
                cout<<"\nStack is empty";
            }else{
                cout<<"\nThe top of the arr: "<<arr[top];
            }
        }
        void displayStack(){
            if(isEmpty()){
                cout<<"\nStack is Empty";
            }else{
                for(int i=0;i<=top;i++){
                    cout<<arr[i]<<"  ";
                }
            }
        }
};
int main(){
    stack s;
    s.push(22);
    s.push(33);
   
    s.push(77);
    s.push(78);
   
    s.displayStack();

    cout<<"\nNew :";
    
    s.pop();

    s.displayStack();

    s.peek();3

    return 0;

}
