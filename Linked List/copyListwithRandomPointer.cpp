class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*,Node*> mp;
        Node * temp = head;
        while(temp!=NULL)
        {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL)
        {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};
