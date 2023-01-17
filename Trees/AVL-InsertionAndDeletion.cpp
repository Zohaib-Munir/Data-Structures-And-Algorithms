                                                                                                                                                                                                                                         #include<iostream>
using namespace std;
class BinaryNode{
    public:
        int data;
        int height;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(int data){
            this->data = data;
            height = 1;
            left = NULL;
            right = NULL;
        }
};
class AVL{
    
    BinaryNode *root;


//Calculate Height;
    int getHeight(BinaryNode *node){
        if(node == NULL){
            return 0;
        }
        return node->height;
    }


//Calculate Balance Factor ;
    int getBalanceFactor(BinaryNode *node){
        if(node == NULL){
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }


// Rotate Left;
    BinaryNode *rotateLeft(BinaryNode *disBalanceNode){
        BinaryNode *newRoot = disBalanceNode->right;
        disBalanceNode->right = disBalanceNode->right->left;
        newRoot->left = disBalanceNode;
        disBalanceNode->height = 1 + max(getHeight(disBalanceNode->left) , getHeight(disBalanceNode->right));
        newRoot->height = 1 + max(getHeight(newRoot->left) , getHeight(newRoot->right));
        return newRoot;
    }


//Rotate Right;
    BinaryNode *rotateRight(BinaryNode *disBalanceNode){
        BinaryNode *newRoot = disBalanceNode->left;
        disBalanceNode->left = disBalanceNode->left->right;
        newRoot->right = disBalanceNode;
        disBalanceNode->height = 1 + max(getHeight(disBalanceNode->left), getHeight(disBalanceNode->right));
        newRoot->height = 1 + max(getHeight(newRoot->left) , getHeight(newRoot->right));
        return newRoot;
    }


// Insert In AVL Tree;
BinaryNode *insertNode(BinaryNode *node , int data){
    if(node == NULL){
        BinaryNode *newNode = new BinaryNode(data);
        return newNode;
    }
    else if(data < node->data){
        node->left = insertNode(node->left, data);
    }
    else{
        node->right = insertNode(node->right,data);
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalanceFactor(node);


    if(balance > 1 && data < node->left->data){
        return rotateRight(node);
    }
    if(balance > 1 && data > node->left->data){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if(balance < -1 && data > node->right->data){
        return rotateLeft(node);
    }
    if(balance < -1 && data < node->right->data){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

// Print Tree;
    void print(BinaryNode *node){
        if(node == NULL){
            return;
        }
        cout<<node->data<<" : ";
        if(node->left){
            cout<<"L "<<node->left->data;
        }
        if(node->right){
            cout<<"R "<<node->right->data;
        }
        cout<<endl;
        print(node->left);
        print(node->right);
    }

//Delete In AVL Tree;
BinaryNode * deleteNode(BinaryNode *node , int data){
    if(node == NULL){
        return NULL;
    }
    if(data > node->data){
        node->right = deleteNode(node->right, data);
    }
    else if(data < node->data){
        node->left = deleteNode(node->left , data);
    }
    else{
        if(node->left == NULL && node->right == NULL){
            delete node;
            return NULL;
        }
        else if(node->right == NULL){
            BinaryNode *temp = node->left;
            node->left = NULL;
            delete node;
            return temp;
        }
        else if(node->left == NULL){
            BinaryNode *temp = node->right;
            node->right = NULL;
            delete node;
            return temp;
        }
        else{
            BinaryNode *minimumNode = node->right;
            while(minimumNode->left){
                minimumNode = minimumNode->left;
            }
            node->data = minimumNode->data;
            node->right = deleteNode(node->right, minimumNode->data);
        }
    }

    int balance = getBalanceFactor(node);
    if(balance > 1 && getBalanceFactor(node->left) >=0){
        return rotateRight(node);
    }
    if(balance > 1 && getBalanceFactor(node->left) < 0){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if(balance < -1 && getBalanceFactor(node->right) <= 0){
        return rotateLeft(node);
    }  
    if(balance < -1 && getBalanceFactor(node->right ) > 0){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    } 
    return node;
}


    public:

        AVL(){
            root = NULL;
        }

        void insertNode(int data){
            root = insertNode(root,data);
        }
        
        void print(){
            print(root);
        }
        void deleteNode(int data){
            root = deleteNode(root,data);
        }
};
int main(){

    AVL avl;
    avl.insertNode(10);
    avl.insertNode(13);
    avl.insertNode(11);
    avl.insertNode(5);
    avl.insertNode(7);
    avl.insertNode(9);
    avl.insertNode(22);
    avl.insertNode(21);
    avl.insertNode(17);


   // avl.deleteNode(10);

    avl.print();
    return 0;
}