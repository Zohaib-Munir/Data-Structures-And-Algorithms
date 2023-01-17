#include<iostream>
using namespace std;
template<typename T>
class StackTemp{
    T *array;
    int nextIndex;
    int capacity;

    
    public : 
        StackTemp(){
            capacity = 4;
            array = new T[capacity];
            nextIndex =0;
        }
    
        void push(T data){
            if(nextIndex == capacity){
                T *newArray = new T[2*capacity];
                for(int i=0; i<capacity ;i++){
                    newArray[i] = array[i];
                }
                delete array;
                array = newArray;
                capacity *=2; 
            }
            array[nextIndex] = data;
            nextIndex++;
        }
        void pop(){
            if(isEmpty()){
                cout<<"Stack is Empty"<<endl;
                return;
            }
            nextIndex--;
        }
        int getCapacity(){
            return this.capacity;
        }
        bool isEmpty(){
            return nextIndex==0;
        }
        int getSize(){
            return nextIndex;
        }
        bool isFull(){
            return nextIndex == capacity;
        }
        T top(){
            if(isEmpty()){
                cout<<"Stack is Empty"<<endl;
                return 0;
            }
            return array[nextIndex-1];
        }
        void display(){
            while(!isEmpty()){
                cout<<top()<<" ";
                pop();
            }
        }
};
int main(){
    StackTemp<char>s;
    s.push(101);
    s.push(103);
    s.push(104);
    s.push(113);
    int size = s.getSize();
    cout<<"Size is : "<<size<<endl;
    s.display();

    return 0;
}