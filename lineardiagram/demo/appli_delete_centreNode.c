/*
分奇偶性讨论
偶数个选择靠后的节点
依旧快慢指针

每次fast走两步，slow走一步
一旦fast==NULL
此时slow指向的就是中间的指针

void delCentreNode(Node *head){

    Node *fast = head->next;
    Node *slow = head;
    while(fast->next != NULL||fast != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = temp->next;
    free(temp);
}




*/