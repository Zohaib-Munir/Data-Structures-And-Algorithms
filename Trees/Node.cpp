#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    Node *left;
    Node *right;
    int data;

    
        Node(int data){
            this->data = data;
            left=NULL;
            right = NULL;
        }
};
class BinaryTree{
    bool helper(Node *leftTree, Node *rightTree){
        if(leftTree == NULL && rightTree != NULL) return false;
        if(leftTree != NULL && rightTree == NULL)return false;
        if(leftTree == NULL && rightTree == NULL)return true;
        if(leftTree->data != rightTree->data) return false;

        return helper(leftTree->left ,rightTree->right) && helper(leftTree->right , rightTree->left);
    }
    public:
    Node * createTree(){
        cout<<"Enter Data : ";
        int data;
        cin>>data;

        if(data == -1){
            return NULL;
        }
        Node *root = new Node(data);
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node *first = q.front();
            q.pop();

            cout<<"Enter Left Child of "<<first->data<<" : ";
            cin>>data;

            if(data != -1){
                first->left = new Node(data);
                q.push(first->left);
            }
            cout<<"Enter Right Child of "<<first->data<<" : ";
            cin>>data;
            if(data != -1){
                first->right = new Node(data);
                q.push(first->right);
            }
        }
        return root;
    }
    //8 10 20 30 40 50 60 -1 -1 -1 -1 -1 -1 -1 -1 
    //2 4 4 6 8 8 6 -1 -1 -1 -1 -1 -1 -1 -1
    void display(Node *root){
        if(root == NULL){
            return;
        }
        cout<<root->data<<" : ";
        if(root->left){
            cout<<"L "<<root->left->data<<" ";
        }
        if(root->right){
            cout<<"R "<<root->right->data<<" ";
        }
        cout<<endl;
        display(root->left);
        display(root->right);
    }

    void printLevelWise(Node *root){

        queue<Node*> q;

        q.push(root);
        q.push(NULL);

        while(!q.empty()){


            Node *front = q.front();
            q.pop();
            if(front == NULL){
                cout<<endl;

                if(!q.empty()){

                    q.push(NULL);
                }
            }
            else{
                cout<<front->data<<" ";
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
    }

    int heightOfTree(Node *root){
        if(root ==NULL){
            return 0;
        }
        int left = heightOfTree(root->left);
        int right = heightOfTree(root->right);
        return max(left,right) +1;
    }

    bool symmetricTree(Node *root){
        if(root==NULL)return true;
        return helper(root->left, root->right);
    }
    int searchMinimum(Node *root){
        if(root==NULL){
            return INT8_MAX;
        }
        int leftMinimum = searchMinimum(root->left);
        int rightMinimum = searchMinimum(root->right);
        return min(root->data, min(leftMinimum,rightMinimum));
    }
    int countLeafNodes(Node *root){
        if(root==NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
    void displayDes(Node *root){
    if(root == NULL){
        return;
    }
        displayDes(root->right);
        cout<<root->data<<" ";
        displayDes(root->left);
    }
};


int main(){
    BinaryTree bt;
    Node *root = bt.createTree();
    bt.display(root);
//     cout<<"Level Wise Printing of Tree"<<endl;
//     bt.printLevelWise(root);
//     cout<<"Tree Height is : "<<bt.heightOfTree(root)<<endl;
//     if(bt.symmetricTree(root)){
//         cout<<"Symmetric"<<endl;
//     }  
//     else{
//         cout<<"Not Symmetric"<<endl;
//    }
//     cout<<"Minimum Value in Tree "<<bt.searchMinimum(root)<<endl;

//     cout<<"Leaf Nodes are "<<bt.countLeafNodes(root);


    bt.displayDes(root);
    return 0;
}