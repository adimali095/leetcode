class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * left = new ListNode(0,head);
        ListNode * right = head;
        int count =0;
        while(count!=n && right!=NULL)
        {
            right = right->next;
            count++;
        }
        while(right!=NULL)
        {
            right = right->next;
            left = left->next;
        }
        ListNode * temp = left->next;
        left->next=temp->next;
        
        return head;
    }
};
