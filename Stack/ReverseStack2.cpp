#include<iostream>
#include<stack>
using namespace std;
class ReverseStack{
    void insertAtBottom(stack<int> &s1,int temp){
        if(s1.empty()){
            s1.push(temp);
            return;
        }
        int ele = s1.top();
        s1.pop();
        insertAtBottom(s1,temp);
        s1.push(ele);
        return;
    }
    public :
        void reverseStack(stack<int> &s1){
            if(s1.empty()){
                return;
            }
            int temp = s1.top();
            s1.pop();
            reverseStack(s1);
            insertAtBottom(s1,temp);
        }
};
int main(){
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);


    ReverseStack s;
    s.reverseStack(s1);


    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    return 0;
}