void reverseCLL() {
    if (head == NULL || head->next == head)
        return; // empty or single node

    node* prev = NULL;
    node* curr = head;
    node* next = NULL;

    do {
        next = curr->next;     // store next
        curr->next = prev;     // reverse link
        prev = curr;           // move prev forward
        curr = next;           // move curr forward
    } while (curr != head);

    // fix circular connection
    head->next = prev;  // old head's next = last node
    head = prev;        // update new head
}
