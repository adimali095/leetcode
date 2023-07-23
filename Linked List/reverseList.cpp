class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode * rev = NULL;
        ListNode * temp = head;
        while(temp!= NULL)
        {
            insertHead(&rev,temp->val);
            temp = temp->next;
        }
        return rev;
    }
    void insertHead(ListNode ** head,int data)
    {
        if(*head == NULL)
        {
            *head = new ListNode(data);
        }
        else
        {
            ListNode * insertNode = new ListNode(data);
            insertNode->next = *head;
            *head = insertNode;
        }
    }
};
