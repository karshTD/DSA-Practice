#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeg(int val) {
    Node* newnode = new Node;
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

void insertEnd(int val) {
    Node* newnode = new Node;
    newnode->data = val;
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newnode;
}

void insertPos(int val, int pos) {
    Node* newnode = new Node;
    newnode->data = val;

    if(pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }
    Node* temp = head;
    for(int i=1; i<pos-1 && temp; i++) temp = temp->next;
    if(temp == NULL) { cout << "Invalid position\n"; return; }

    newnode->next = temp->next;
    temp->next = newnode;
}


void display() {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int main() {
    int choice, val, pos;
    do {
        cout << "\n--- Insertion Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                insertBeg(val); break;
            case 2:
                cout << "Enter value: "; cin >> val;
                insertEnd(val); break;
            case 3:
                cout << "Enter value: "; cin >> val;
                cout << "Enter position: "; cin >> pos;
                insertPos(val, pos); break;
            case 4:
                display(); break;
            case 5:
                cout << "Exiting...\n"; break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 5);
    return 0;
}
