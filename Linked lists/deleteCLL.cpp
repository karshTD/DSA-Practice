#include <iostream>
using namespace std;

struct node{
    int data;
    new *node;
}
node * head = NULL;

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

void deletebeg(){
 if ( head  == NULL ){
    cout<< "list empty \n";
    return ;
 }

 node * temp = head ;
 node * last  = head;

 while ( last -> next  ! = head){ 
    last = last -> next;

    if ( head -> next == head){
        delete head;
        head = NULL;
        return; 
    }

      head = head-> next ;
    last -> next = head;
    delete temp;

 }


}

void deletend(){
    if (head == NULL ){
        cout<< "list empty";
        return;
    }

node * temp = head;
node * prev= NULL;

while ( temp -> next != head){
    prev = temp;
     temp = temp-> next; 
    
}

prev-> next = head;
delete temp;


}

void deletepos(int pos){

    if ( head  == NULL ){
        cout<< "list empty";
        return ;
    }

    while ( pos == 1){
        deletebeg();
        return;
    }

    node * temp = head;
    node * prev = NULL;

    for ( int i = 0 ; i < pos - 1 && temp -> next != head; i++){
        prev = temp;
        temp = temp -> next;
    }

    prev-> next = head;
    delete temp;
}

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
        cout << "\n--- CLL Deletion Menu ---\n";
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
                cout << "Enter value: ";
                cin >> val;
                insertend(val);
                break;
            case 2:
                deletebeg();
                break;
            case 3:
                deletend();
                break;
            case 4:
                cout << "Enter position: ";
                cin >> pos;
                deletepos(pos);
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 6);

    return 0;
}
