void reverseSLL() {
    node* prev = NULL;
    node* curr = head;
    node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse the link
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }

    head = prev; 
}
