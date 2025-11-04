void reverseDLL() {
    node* temp = NULL;
    node* current = head;

    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // move backward (since swapped)
    }


    if (temp != NULL)
        head = temp->prev;
}
