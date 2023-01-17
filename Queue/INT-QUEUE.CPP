#include<iostream>
using namespace std;
class Queue{
    int *array;
    int front;
    int rear;
    int capacity;


    public :
        
        Queue(int capacity){
            this->capacity = capacity;
            array = new int[capacity];
            front = rear =0;
        }
        void enQueue(int data){
            if(rear==capacity){
                int *newArray = new int[capacity*2];
                for(int i=0;i<capacity;i++){
                    newArray[i] = array[i];
                }
                capacity = capacity*2;
                delete [] array;
                array = newArray;
            }
            array[rear] = data;
            rear++;
        }
        void deQueue(){
            if(isEmpty()){
                cout<<"Queue is Empty"<<endl;
                return;
            }
            for(int i=0;i<capacity;i++){
                array[i] = array[i+1];
            }
            rear--;
        }
        int getSize(){
            return rear;
        }
        int getFront(){
            if(isEmpty()){
                cout<<"Empty Queue"<<endl;
                return -1;
            }
            return array[front];
        }
        int getCapacity(){
            return capacity;
        }
        bool isEmpty(){
            return rear ==0;
        }
        bool isFull(){
            return rear ==capacity;
        }
};
int main()
{

    Queue q1(4);
    q1.getFront();
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.enQueue(40);
    cout<<"Capacity is : "<<q1.getCapacity()<<endl;
    cout<<"Front is : "<<q1.getFront()<<endl;
    q1.deQueue();
    cout<<"Front is : "<<q1.getFront()<<endl;
    q1.deQueue();
    cout<<"Front is : "<<q1.getFront()<<endl;
    q1.deQueue();
    cout<<"Front is : "<<q1.getFront()<<endl;
    q1.deQueue();
    q1.deQueue();
    return 0;
}