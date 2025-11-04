node* concatCLL(node* head1, node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    node* temp1 = head1;
    while (temp1->next != head1)
        temp1 = temp1->next;

    node* temp2 = head2;
    while (temp2->next != head2)
        temp2 = temp2->next;

    temp1->next = head2;
    temp2->next = head1;

    return head1;
}
