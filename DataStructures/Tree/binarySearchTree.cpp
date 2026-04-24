#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left = NULL;
    Node* right = NULL;
};

struct BST{
    Node *root = NULL;

    void insert(Node* &node, int val){
        if(node == NULL){
            node = new Node;
            node->val = val;
            return;
        }

        if(val < node->val){
            insert(node->left, val);
        }
        else{
            insert(node->right, val);
        }
    }

    void inorderTraversal(Node *node){
        if(node == NULL){
            return;
        }
        else{
            inorderTraversal(node->left);
            cout<<node->val<<" ";
            inorderTraversal(node->right);
        }
    }
    void preorderTraversal(Node *node){
        if (node==NULL){
            return;
        }
        else{
            cout<<node->val<<" ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }
    void postorderTraversal(Node *node){
        if(node == NULL){
            return;
        }
        else{
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout<<node->val<<" ";
        }
    }

    void del(Node*& root, int x){
        if(root == nullptr){
            return;
        }
        if(root->val > x){
            del(root->left, x);
        }
        else if(root->val < x){
            del(root->right, x);
        }
        else{
            if(root->left == nullptr){
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == nullptr){
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            else{
                Node* successor = root-> right;
                while(successor->left!=nullptr){
                    successor = successor->left;
                }
                root->val = successor->val;
                del(root->right,x);
            }
        }
    }
    
};


int main(){
    BST bst1;

    bst1.insert(bst1.root, 10);
    bst1.insert(bst1.root, 5);
    bst1.insert(bst1.root, 15);
    bst1.insert(bst1.root, 3);
    bst1.insert(bst1.root, 7);
    bst1.insert(bst1.root, 20);
    bst1.insert(bst1.root, 1);


    bst1.del(bst1.root,20);

    cout<<"Preorder Traversal:"<<endl;
    bst1.preorderTraversal(bst1.root);
    cout<<endl;
    cout<<"Inorder Traversal:"<<endl;
    bst1.inorderTraversal(bst1.root);
    cout<<endl;
    cout<<"Postorder Traversal:"<<endl;
    bst1.postorderTraversal(bst1.root);
    cout<<endl;
    return 0;
}