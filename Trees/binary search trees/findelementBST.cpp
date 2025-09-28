#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

TreeNode* insertBST(TreeNode* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insertBST(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertBST(root->right, value);
    }
    
    return root;
}

// Recursive search function
bool searchElement(TreeNode* root, int value) {
    if (root == nullptr) {
        return false;
    }
    
    if (root->data == value) {
        return true;
    }
    else if (value < root->data) {
        return searchElement(root->left, value);
    }
    else {
        return searchElement(root->right, value);
    }
}

// Iterative search function
bool searchIterative(TreeNode* root, int value) {
    TreeNode* current = root;
    
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        else if (value < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    
    return false;
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = nullptr;
    
    // Create a sample tree
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 70);
    root = insertBST(root, 20);
    root = insertBST(root, 40);
    root = insertBST(root, 60);
    root = insertBST(root, 80);
    root = insertBST(root, 10);
    root = insertBST(root, 25);
    
    cout << "=== Searching in BST ===" << endl;
    
    // Test search values
    int testValues[] = {40, 25, 100, 10, 55, 70};
    int n = sizeof(testValues) / sizeof(testValues[0]);
    
    cout << "Tree contains: 10, 20, 25, 30, 40, 50, 60, 70, 80" << endl;
    cout << endl;
    
    // Test recursive search
    cout << "Recursive Search Results:" << endl;
    for (int i = 0; i < n; i++) {
        if (searchElement(root, testValues[i])) {
            cout << testValues[i] << " : FOUND" << endl;
        } else {
            cout << testValues[i] << " : NOT FOUND" << endl;
        }
    }
    
    cout << endl;
    
    // Test iterative search
    cout << "Iterative Search Results:" << endl;
    for (int i = 0; i < n; i++) {
        if (searchIterative(root, testValues[i])) {
            cout << testValues[i] << " : FOUND" << endl;
        } else {
            cout << testValues[i] << " : NOT FOUND" << endl;
        }
    }
    
    deleteTree(root);
    return 0;
}