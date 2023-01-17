#include<iostream>
using namespace std;
template<typename T>
class Node{
    public : 
        T data;
        Node<T> *next;

        Node(T data){
            this->data = data;
            next = NULL;
        }
};
template<typename T>
class Stack{
    Node<T> *head;
    int size;

    public:
        Stack(){
            head = NULL;
            size=0;
        }
        int getSize(){
            return size;
        }

        bool isEmpty(){
            return head == NULL;
        }

        void push(T data){
            Node<T> *node = new Node<T>(data);
            node->next = head;
            head = node;
            size++;
        }
        void pop(){
            if(isEmpty()){
                cout<<"Stack is Empty"<<endl;
                return;
            }
            Node<T> *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            size--;
        }
        T top(){
            if(isEmpty()){
                cout<<"Stack is  Empty"<<endl;
                return 0 ;
            }
            return head->data;
        }
        void display(){
            while(head){
                cout<<top()<<endl;
                pop();
            }
        }
};
int main(){
    Stack<int> s;
    s.push(103);
    s.push(106);
    s.push(107);
    s.push(105);

    cout<<"Size is : "<<s.getSize()<<endl;
    s.display();
    
    return 0;
}