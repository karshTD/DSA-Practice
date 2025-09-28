#include <iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *createnode(int value){
    node *newnode = new node;
    newnode-> data = value;
    newnode-> left = NULL;
    newnode-> right = NULL;

    return newnode;
    
}

node *insertbst(node *root, int value){
    if ( root == nullptr){
        return createnode(value);
        
    }

    if (value < root->data){
        root-> left = insertbst(root->left, value);


    }

    else if (value > root-> data){
        root->right = insertbst(root->right, value);
    }

    return root;
}

void displaytree(node* root){

 if (root == nullptr)
  return;
    
    displaytree(root->left);
    cout << root->data << " ";
    displaytree(root->right);
}




 int main() {
    node* root = nullptr;
    
    
    cout << "=== Creating and Inserting into BST ===" << endl;
    
    root = insertbst(root, 50);
    root = insertbst(root, 30);
    root = insertbst(root, 70);
    root = insertbst(root, 20);
    root = insertbst(root, 40);
    root = insertbst(root, 60);
    root = insertbst(root, 80);
    
    
    cout << "BST elements (in sorted order): ";
    displaytree(root);
    cout << endl;

    return 0;
}