class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        unordered_map<ListNode *,ListNode*> mp;
        ListNode * temp =head;
        while(temp!=NULL)
        {
            if(mp.find(temp->next) != mp.end())
            {
                return true;
            }
            mp[temp->next] = temp;
            temp = temp->next;
        }
        return false;
    }
};
