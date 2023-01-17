#include<iostream>
using namespace std;
class Node {
    public : 
        int data;
        Node *next;


        Node(int data){
            this->data = data;
            next = NULL;
        }
};
    Node * mergeList2(Node *head, Node *head2){
    if(head == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head;
    }
    Node * finalHead = head;
    if(head->data < head2->data){
        finalHead = head;
        head = head->next;
    }
    else{
        finalHead = head2;
        head2 = head2->next;
    }
    Node *finaltail = finalHead;

    while(head && head2){

        if(head->data < head2->data){
            finaltail->next = head;
            head = head->next;
        }
        else{
            finaltail->next = head2;
            head2 = head2->next;
        }
        finaltail = finaltail->next;
    }

    if(head){
        finaltail->next = head;
    }
    else{
        finaltail->next = head2;
    }
    head = finalHead;
    return head;
}
Node *mergeSort(Node *head){
    if(head == NULL){
        return head;
    }
    if(head->next == NULL){
        return head;
    }


    Node *slow = head;
    Node *fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newHead = slow->next;
    slow->next= NULL;


    Node *first = mergeSort(head);
    Node *second = mergeSort(newHead);

    head = mergeList2(first,second);

    return head;

}
void display(Node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
    Node n1(9);
    Node n2(1);
    Node n3(3);
    Node n4(2);
    Node n5(7);
    Node n6(5);
    Node n7(6);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;

    Node *head = &n1;

    display(head);
    cout<<head<<endl;

    cout<<"Merge Sort "<<endl;

    Node *newHead = mergeSort(head);

    display(newHead);

    return 0;
}
