#include<iostream>
using namespace std;
class Stack{
    int *array;
    int nextIndex;
    int capacity;

    public : 
        Stack(){
            capacity = 4;
            array = new int[capacity];
            nextIndex =0;
        }
        int getCapacity(){
            return capacity;
        }
        int size(){
            return nextIndex;
        }
        bool isEmpty(){
            return nextIndex==0;
        }
        void push(int data){
            if(nextIndex ==capacity){
                int *newArray = new int[2*capacity];

                for(int i=0; i<capacity;i++){
                    newArray[i] = array[i];
                }
                delete[] array;
                array = newArray;
                capacity = capacity * 2;
            }
            array[nextIndex] = data;
            nextIndex++;
        }
        void pop(){
            if(isEmpty()){
                return;
            }
            nextIndex--;
        }
        int top(){
            if(isEmpty()){
                return -1;
            }
            return array[nextIndex-1];
        }
        void display(){
            if(isEmpty()){
                cout<<"Empty Stack"<<endl;
                return;
            }
            while(!isEmpty()){
                cout<<top()<<" ";
                pop();
            }
            cout<<endl;
        }
};
int main(){
    Stack s1;
    if(s1.isEmpty()){
        cout<<"Empty Stack"<<endl;
    }
    else{
        cout<<"Stack Has Elements"<<endl;
    }
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(69);
    cout<<"Size is : "<<s1.size()<<endl;
    s1.display();
    cout<<"Capacity is : "<<s1.getCapacity()<<endl;
    cout<<"Top is "<<s1.top()<<endl;
}