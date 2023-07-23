class Solution {
public:
    int getCount(ListNode * temp){
        int count = 0;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    void reorderList(ListNode* head) 
    {
        ListNode * temp = head;
        int count = getCount(temp);
        int *arr = new int[count];
        for(int i =0;i<count;i++)
        {
            arr[i] = temp->val;
            temp = temp->next;
        }
        int left = 0,right = count-1;
        temp = head;
        while(left<right)
        {
            temp->val = arr[left];
            (temp->next)->val = arr[right];
            temp =temp->next->next;
            left++;
            right--;
        }
        if(left == right)
        {
            temp->val = arr[left];
        }

    }
};
