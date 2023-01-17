#include<iostream>
using namespace std;
class Node{
    public : 
        int data;
        Node *next;
        Node *previous;

    Node(int data){
        this->data = data;
        next =NULL;
        previous =NULL;
    }
};
class DoubllyLinkedList{
    Node *head ;
    Node *tail ;
    int size;
    public : 
        DoubllyLinkedList(){
            head = NULL;
            tail =NULL;
            size=0;
        }


        void createList(){
            cout<<"Enter Data : ";
            int data;
            cin>>data;

            while(data != -1){
                Node *node = new Node(data);
                if(head == NULL){
                    head = tail =node;
                }
                else{
                    tail->next = node;
                    node->previous = tail;
                    tail = node;
                }
                size++;
                cout<<"Enter Data : ";
                cin>>data;
                getchar();
            }
        }

        void display(){
            Node *temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }

            cout<<"\nReverse Display"<<endl;

            temp =tail;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->previous;
            }
            cout<<endl;
        }

        Node * getNode(int index){
            int count=1;
            Node *temp = head;
            if(index <=0 || index > size){
                cout<<"Invalid Index "<<endl;
                return NULL; 
            }

            while(count<index){
                temp = temp->next;
                count++;
            }
            return temp;
        }

        void reverseList(){
            Node *temp = head;
            head = tail;
            tail = temp;

            Node *ptr = tail;

            while(ptr){
                Node *temp2 = ptr->next;
                ptr->next = ptr->previous;
                ptr->previous = temp2;
                ptr = ptr->previous;
            }
        }

        void swapNthFirstAndLast(int index){
                if(index <=0 || index >size){
                    cout<<"Invalid Index "<<endl;
                    return;
                }
                if(index == 1){
                    tail->next = head->next;
                    tail->previous->next = head;

                    tail->previous->next->next = NULL;
                    tail->previous->next->previous = tail->previous;
                    head = tail;
                    head->previous =NULL;
                }
        }
};
int main(){

    DoubllyLinkedList l1;
    l1.createList();
    l1.display();
    // cout<<"Reverse Called"<<endl;
    // l1.reverseList();
    // l1.display();

    l1.swapNthFirstAndLast(1);
    l1.display();
    return 0;
}