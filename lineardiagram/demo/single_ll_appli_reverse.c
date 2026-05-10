/*反转一个链表
Node* reverseList(Node* head)
{
    Node *first = NULL;
    Node *second = head->next;
    Node *third;

    while(second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    head->next = first;
}




*/