void concatDLL(node* head1, node* head2) {
    if (head1 == NULL) {
        head = head2;
        return;
    }

    if (head2 == NULL)
        return;

    node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link last of list1 to head of list2
    temp->next = head2;
    head2->prev = temp;
}
