#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;


        Node(int data){
            this->data = data;
            next = NULL;
        }
};
class Queue{
    Node *head;
    Node *tail;
    int size;


    Queue(){
        head = NULL;
        tail = NULL;
        size =0;
    }

    void push(int data){
        Node *node = new Node(data);
        if(head== NULL){
            head = tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
        size++;
    }
    bool isEmpty(){
        return head==NULL;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
    int front(){
        return head->data;
    }
    int getSize(){
        return size--;
    }
};
int main()
{



    return 0;
}