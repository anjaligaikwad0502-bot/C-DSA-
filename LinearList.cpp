#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};
class linkedList{
    Node* head;
    Node* tail;
    public:
    linkedList(){
        head=NULL;
        tail=NULL;
    }
    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
    void print(){
        Node* temp=head;
        while(temp !=NULL){
            cout<< temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void pop_front(){
        
        if(head==NULL){
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void pop_back(){
        if(head==NULL){
            return;
        }
        Node* temp=head;
        if(temp->next !=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        delete temp;
        tail=temp;
    }
    void insert(int val,int pos){
        if(pos<0){
            return;
        }
        if(pos==0){
            push_front(val);
            return;
        }
      
        Node* newNode=new Node(val);
        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        
        newNode->next=head->next;
        temp->next=newNode;
    }
    
};
int main(){
    linkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_back(30);
    ll.push_back(50);

    ll.print();
    ll.pop_front();
    ll.pop_back();
    ll.print();
    ll.insert(70,1);
    ll.print();

    return 0;
    
}