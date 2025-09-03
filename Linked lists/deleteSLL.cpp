#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at end (helper to build list)
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


void deleteBeg() {
    if(head == NULL) { cout << "List Empty\n"; return; }
    Node* temp = head;
    head = head->next;
    delete temp;
}


void deleteEnd() {
    if(head == NULL) { cout << "List Empty\n"; return; }
    Node* temp = head, *prev = NULL;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if(prev) prev->next = NULL;
    else head = NULL;
    delete temp;
}


void deletePos(int pos) {
    if(head == NULL) { cout << "List Empty\n"; return; }
    Node* temp = head;
    if(pos == 1) {
        head = head->next;
        delete temp; return;
    }
    for(int i=1; i<pos-1 && temp; i++) temp = temp->next;
    if(temp == NULL || temp->next == NULL) {
        cout << "Invalid position\n"; return;
    }
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
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
        cout << "\n--- Deletion Menu ---\n";
        cout << "1. Insert at End (for testing)\n";
        cout << "2. Delete at Beginning\n";
        cout << "3. Delete at End\n";
        cout << "4. Delete at Position\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                insertEnd(val); break;
            case 2:
                deleteBeg(); break;
            case 3:
                deleteEnd(); break;
            case 4:
                cout << "Enter position: "; cin >> pos;
                deletePos(pos); break;
            case 5:
                display(); break;
            case 6:
                cout << "Exiting...\n"; break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 6);
    return 0;
}
