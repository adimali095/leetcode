class Solution {
public:
    ListNode * getNode(int val)
    {
        ListNode * ptr = new ListNode(val);
        ptr->next = NULL;
        return ptr;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        
        ListNode * ptr1,*ptr2,*res,*resPtr;
        ptr1 = list1;
        ptr2 = list2;
        res = NULL;

        while(ptr1!=NULL && ptr2!= NULL)
        {
            if(res == NULL)
            {
                if(ptr1->val < ptr2->val)
                {
                    res = ptr1;
                    ptr1 = ptr1->next;
                    resPtr = res;
                }
                else
                {
                    res = ptr2;
                    ptr2 = ptr2->next;
                    resPtr = res;
                }
                continue;

            }
            if(ptr1->val < ptr2->val)
            {
                resPtr->next = ptr1;
                resPtr = resPtr->next;
                ptr1 = ptr1->next;
            }
            else
            {
                resPtr->next = ptr2;
                resPtr = resPtr->next;
                ptr2 = ptr2->next;
            }
        }
        while(ptr1!=NULL)
        {
            resPtr->next = ptr1;
            resPtr = resPtr->next;
            ptr1 = ptr1->next;
        }
        while(ptr2!=NULL)
        {
            resPtr->next = ptr2;
            resPtr = resPtr->next;
            ptr2 = ptr2->next;
        }
        return res;
    }
};
