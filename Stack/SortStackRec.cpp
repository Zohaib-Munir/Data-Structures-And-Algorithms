#include<iostream>
#include "INT-STACK.cpp"
using namespace std;
class SortStack{

    void insertInStack(STACK &s, int temp){
        if(s.isEmpty()){
            s.push(temp);
            return;
        }
        else if(s.top() >= temp){
            s.push(temp);
            return;
        }
        else{
            int element = s.top();
            s.pop();
            insertInStack(s,temp);
            s.push(element);
            return;
        }
    }

    public:


        void sortStack(STACK &s){
            if(s.isEmpty()){
                return;
            }
            int number = s.top();
            s.pop();
            sortStack(s);
            insertInStack(s,number);
        }

        void display(STACK s){
            if(s.isEmpty()){
                return;
            }
            cout<<s.top()<<" ";
            s.pop();
            display(s);
        }

        
};
int main(){
    STACK s;
    s.push(9);
    s.push(3);
    s.push(7);
    s.push(5);
    s.push(11);


    SortStack ss;
    ss.sortStack(s);


    ss.display(s);
    return 0;
}