#include<iostream>
using namespace std;


class TreeNode{
    public : 
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};
class BinarySearchTree{

    TreeNode *root;

    void print(TreeNode *root){
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
        print(root->left);
        print(root->right);
    }


    TreeNode* insert(TreeNode* root , int data){
        if(root == NULL){
            TreeNode* node = new TreeNode(data);
            return node;
        }
        if(data > root->data){
            root->right = insert(root->right, data);
        }
        else{
            root->left = insert(root->left, data);
        }
        return root;
    }



    bool hasData(TreeNode *root , int data){
        if(root == NULL){
            return false;
        }
        if(root->data == data){
            return true;
        }
        if(root->data > data){
            return hasData(root->left , data);
        }
        else{
            return hasData(root->right, data);
        }
    }



    int maxElement(TreeNode *root){
            if(root == NULL){
                return INT16_MAX;
            }
            if(root->right == NULL){
                return root->data;
            }
            return maxElement(root->right);
    }


    int minElement(TreeNode *root){
        if(root == NULL){
            return -1;
        }
        if(root->left == NULL){
            return root->data;
        }
        return minElement(root->left);
    }



    int heightOfTree(TreeNode *root){

        if(root==NULL){
            return 0;
        }
        return max(heightOfTree(root->left) , heightOfTree(root->right))+1;
    }




    TreeNode* deleteData(TreeNode *root, int data){
        if(root == NULL){
            return NULL;
        }
        if(root->data > data){
            root->left = deleteData(root->left , data);
        }
        else if(root->data < data){
            root->right = deleteData(root->right , data);
        }
        else{
            if(root->right == NULL && root->left == NULL){
                delete root;
                return NULL;
            }
            else if(root->right == NULL){
                TreeNode *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else if(root->left == NULL){
                TreeNode *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else{
                TreeNode *rightNode = root->right;
                while(rightNode->left){
                    rightNode = rightNode->left;
                }
                int minimum = rightNode->data;

                root->data = minimum;
                root->right = deleteData(root->right, minimum);
            }
        }
        return root;
    }



    public:
        BinarySearchTree(){
            root = NULL;
        }
        void printTree(){
            print(root);  
        }
        void insert(int data){
            root = insert(root, data);
        }
        bool hasData(int data){
            return hasData(root,data);
        }
        int maxElement(){
            return maxElement(root);
        }
        int minElement(){
            return minElement(root);
        }
        int heightOfTree(){
            return heightOfTree(root);
        }



        TreeNode * constructTree(int *array, int start, int end){
            if(start > end){
                return NULL;
            }
            int midPoint = (start + end)/2;
            TreeNode * root = new TreeNode(array[midPoint]);
            root->left = constructTree(array,start,midPoint-1);
            root->right = constructTree(array,midPoint+1,end);
            this->root = root;
            return this->root;
        }
        void deleteData(int data){
            root = deleteData(root, data);
        }
};

int main(){
    BinarySearchTree b;
    int array[] = {1,2,3,4,5,6,7};
    b.constructTree(array,0,6);




    // b.insert(10);
    // b.insert(5);
    // b.insert(15);
    // b.insert(7);
    // b.insert(40);
    // b.insert(11);
    // b.insert(9);
    // b.insert(13);


    // b.printTree();
    // cout<<endl;
    // cout<<b.hasData(15);
    // cout<<endl;
    // cout<<"Max is : "<<b.maxElement();
    // cout<<endl;
    // cout<<"Min is : "<<b.minElement();
    // cout<<endl;
    // cout<<"Height : "<<b.heightOfTree();

    // cout<<endl;
    // b.deleteData(10);

    // cout<<endl;
    b.printTree();
    return 0;
}