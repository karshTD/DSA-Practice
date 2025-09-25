#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

node* head = NULL;

// Insert at beginning
void insertBeg(int val) {
    node* newnode = new node;
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
}

// Insert at end
void insertEnd(int val) {
    node* newnode = new node;
    newnode->data = val;
    newnode->next = NULL;

    if(head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
}

// Insert at position
void insertPos(int val, int pos) {
    if(pos == 1) {
        insertBeg(val);
        return;
    }

    node* temp = head;
    for(int i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        cout << "Position out of bounds\n";
        return;
    }

    node* newnode = new node;
    newnode->data = val;
    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

// Display DLL
void display() {
    if(head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Delete from beginning
void deleteBeg() {
    if(head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node* temp = head;
    head = head->next;

    if(head != NULL) {
        head->prev = NULL;
    }
    delete temp;
}

// Delete from end
void deleteEnd() {
    if(head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node* temp = head;
    if(temp->next == NULL) { // Only one node
        head = NULL;
        delete temp;
        return;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
}

// Delete from position
void deletePos(int pos) {
    if(head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node* temp = head;
    if(pos == 1) {
        deleteBeg();
        return;
    }

    for(int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        cout << "Position out of bounds\n";
        return;
    }

    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if(temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    delete temp;
}

int main() {
    int choice, val, pos;
    do {
        cout << "\n--- DLL Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
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
                deleteBeg();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deletePos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 8);

    return 0;
}
f