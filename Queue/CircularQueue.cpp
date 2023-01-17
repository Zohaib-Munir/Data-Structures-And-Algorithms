#include<iostream>
using namespace std;
template<typename T>
class Queue{
    T *array;
    int rear;
    int front;
    int size;
    int capacity;

    public:
        Queue(int capacity){
            this->capacity = capacity;
            array = new T[capacity];
            size=0;
            rear=0;
            front=-1;
        }
        bool isEmpty(){
            return size==0;
        }
        bool isFull(){
            return size==capacity;
        }
        void push(T data){
            if(isFull()){
                T *newArray = new T[capacity*2];
                int i=0;
                do{
                    newArray[i] = array[front];
                    front = (front+1)%capacity;
                    i++;
                }while(i<capacity);
                front =0;
                rear = capacity;
                delete [] array;
                array =newArray;
                capacity *=2; 
            }
            if(isEmpty()){
                array[rear] = data;
                front =0;
            }
            array[rear] = data;
            rear = (rear+1)%capacity;
            size++;
        }
        void pop(){
            if(isEmpty()){
                cout<<"Queue is Empty"<<endl;
                return;
            }
            front = (front+1)%capacity;
            size--;
        }
        T getFront(){
            if(isEmpty()){
                cout<<"Queue is Empty"<<endl;
                return 0;
            }
            return array[front];
        }
        int getSize(){
            return size;
        }
};
int main()
{
    Queue <int> q1(5);
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);
    q1.push(90);
    q1.push(31);
    cout<<"Size  is : "<<q1.getSize()<<endl;

    cout<<"Front Data : "<<q1.getFront()<<endl;
    q1.pop();
    cout<<"Front Data : "<<q1.getFront()<<endl;
    q1.pop();
    cout<<"Front Data : "<<q1.getFront()<<endl;

    cout<<"Size  is : "<<q1.getSize()<<endl;

    q1.pop();
    cout<<"Front Data : "<<q1.getFront()<<endl;

    q1.pop();
    cout<<"Front Data : "<<q1.getFront()<<endl;

    q1.pop();
    cout<<"Front Data : "<<q1.getFront()<<endl;



    return 0;
}