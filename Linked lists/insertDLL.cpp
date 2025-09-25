#include <iostream>
using namespace std;


struct node{
    int data;
    new *node;

}
node *head  = NULL;

void insertbeg(int val){
    node *newnode = new node;
    newnode->data = val;
    newnode-> next = head;
    newnode-> prev = NULL;
    
    if (head != NULL){
        head-> prev = newnode;
    }
    
    head = newnode; 
}

void insertend(int val){
    node *newnode = new node; 
    newnode-> data = val;
    newnode-> next = NULL;

    if ( head == NULL){
        newnode-> prev = NULL;
        head = newnode;
        return ;

    }

    node *temp = head;
    while( temp){
        temp = temp-> next;
        temp-> next = newnode;
        newnode-> prev = temp;

    }
}

void insertpos(int val, int pos) {
    node* newnode = new node;
    newnode->data = val;

    if(pos == 1) {
        insertBeg(val);
        return;
    }

    node* temp = head;

    
    for(int i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        cout << "Invalid position\n";
        return;
    }

    // Link the new node
    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}


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

int main() {
    int choice, val, pos;
    do {
        cout << "\n--- DLL Insertion Menu ---\n";
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
                insertbeg(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertend(val);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> val;
                cout << "Enter position: ";
                cin >> pos;
                insertpos(val, pos);
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