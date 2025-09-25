#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = NULL;

// Insert at beginning
void insertBeg(int val) {
    node* newnode = new node;
    newnode->data = val;

    if(head == NULL) {
        head = newnode;
        newnode->next = head; // points to itself
        return;
    }

    node* temp = head;
    while(temp->next != head) {
        temp = temp->next; // find last node
    }

    newnode->next = head;
    temp->next = newnode;
    head = newnode; // update head
}

// Insert at end
void insertEnd(int val) {
    node* newnode = new node;
    newnode->data = val;

    if(head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }

    node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;
}

// Insert at position
void insertPos(int val, int pos) {
    if(pos == 1) {
        insertBeg(val);
        return;
    }

    node* newnode = new node;
    newnode->data = val;

    node* temp = head;
    for(int i=1; i<pos-1 && temp->next != head; i++) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// Display CLL
void display() {
    if(head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while(temp != head);
    cout << "(head)\n";
}

int main() {
    int choice, val, pos;
    do {
        cout << "\n--- CLL Insertion Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertBeg(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertEnd(val);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> val;
                cout << "Enter position: ";
                cin >> pos;
                insertPos(val, pos);
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 5);

    return 0;
}

