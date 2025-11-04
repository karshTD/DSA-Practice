node* concatSLL(node* head1, node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;
    return head1; // new head of combined list
}
