#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int val) {
    Node *newNode = new Node;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertion(Node *root, int item) {
    if (root == NULL) {
        return createNode(item);
    }
    if (item < root->data) {
        root->left = insertion(root->left, item);
    } else if (item > root->data) {
        root->right = insertion(root->right, item);
    }
    return root;
}

Node *minValueNode(Node *node) {
    Node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node *deletion(Node *root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deletion(root->left, key);
    } else if (key > root->data) {
        root->right = deletion(root->right, key);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deletion(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void display(Node *root) {
    if (root == NULL) {
        cout << "The tree is empty." << endl;
        return;
    }
    cout << "Tree contents (Inorder Traversal): ";
    inorder(root);
    cout << endl;
}

int main() {
    Node *root = NULL;
    int choice, value;

    do {
        cout << "\n--- Binary Search Tree Menu ---" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Traversal (Inorder)" << endl;
        cout << "4. Traversal (Preorder)" << endl;
        cout << "5. Traversal (Postorder)" << endl;
        cout << "6. Display (Inorder)" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                if (cin >> value) {
                    root = insertion(root, value);
                    cout << value << " inserted into the tree." << endl;
                }
                break;

            case 2:
                cout << "Enter value to delete: ";
                if (cin >> value) {
                    root = deletion(root, value);
                    cout << "Attempted to delete " << value << "." << endl;
                }
                break;

            case 3:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 6:
                display(root);
                break;

            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}