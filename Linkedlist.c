#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

int main() {
    node *start, *temp, *newnode;
    char choice;
    start = NULL;

    do {
        newnode = (node*)malloc(sizeof(node));
        cout << "Enter data: ";
        cin >> newnode->data;
        newnode->next = NULL;

        if (start == NULL) {
            temp = newnode;
            start = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    temp = start;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}
