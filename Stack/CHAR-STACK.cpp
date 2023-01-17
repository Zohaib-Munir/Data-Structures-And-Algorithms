#include<iostream>
using namespace std;
class Node{
    public:
        char data;
        Node *next;

        Node(char data){
            this->data = data;
            next = NULL;
        }
};
class STACK{
    Node *head;
    int size;


    public :
        STACK(){
            head = NULL;
            size =0;
        }
        bool isEmpty(){
            return head==NULL;
        }

        void push(char data){
            Node *node = new Node(data);
            node->next = head;
            head = node;
            size++;
        }
        void pop(){
            if(isEmpty()){
                cout<<"Stack is Empty"<<endl;
                return;
            };
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            size--;
        }
        char top(){
            if(isEmpty()){
                return 0;
            }
            return head->data;
        }
        int getSize(){
            return size;
        }
};