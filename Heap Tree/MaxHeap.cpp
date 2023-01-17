#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class MaxHeap{
    vector<int> v;
    
    public: 


    bool isEmpty(){
        return v.size()==0;
    }
    void insertData(int data){
        v.push_back(data);

        int child = v.size()-1;

        while(child > 0){
            int parent = floor((child-1)/2);
            if(v.at(parent) < v.at(child)){
                swap(v.at(parent), v.at(child));
                child = parent;
            }
            else{
                break;
            }
        }
    }

    void removeMax(){
        if(isEmpty()){
            return;
        }
        swap(v.at(0), v.at(v.size()-1));
        v.pop_back();
        
        int parent =0;

        while (true)
        {
            int left = (2*parent)+1;
            int right = (2*parent)+2;
            int minimum = parent;


            if(left < v.size() && v.at(left) > v.at(minimum)){
                minimum = left;
            }
            if(right < v.size() && v.at(right) > v.at(minimum)){
                minimum = right;
            }
            if(parent == minimum){
                break;
            }
            swap(v.at(parent), v.at(minimum));
            parent = minimum;
        }
        
    }

    void printTree(){
        if(isEmpty()){
            return;
        }
        int left, right =0;

        for(int i=0; i<v.size();i++){
            left = (2*i)+1;
            right = (2*i)+2;

            cout<<"Parent -> "<<v.at(i);
            if(left < v.size()){
                cout<<" L "<<v.at(left);
            }
            if(right < v.size()){
                cout<<" R "<<v.at(right);
            }
            cout<<endl;
        }
        cout<<"\n\n\n";
    }

};
int main(){


    MaxHeap mht;
    mht.insertData(65);
    mht.insertData(78);
    mht.insertData(14);
    mht.insertData(32);
    mht.insertData(48);
    mht.insertData(15);
    mht.insertData(81);


    mht.printTree();


    mht.removeMax();

    mht.printTree();
 
    return 0;
}