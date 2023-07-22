struct node
{
    int val;
    struct node * next;
};
struct node * getNode(int val)
{
    struct node * ptr = new node;
    ptr->val = val;
    ptr->next = NULL;
    return ptr;
}
void addAtHead(struct node **head,int val)
{
    struct node * insert = getNode(val);
    insert->next = *head;
    *head = insert;    
}
void deleteAtHead(struct node ** head)
{
    struct node * temp;
    temp = *head;
    *head = (*head)->next;
    delete temp;
}
class MinStack {
public:
    struct node * topNode;
    stack<int> minStack;
    int min;
    MinStack() {
        topNode = NULL;
        min = std::numeric_limits<int>::max();
        minStack.push(min);
    }
    
    void push(int val) 
    {
        if(minStack.top() > val)
        {
            minStack.push(val);
        }
        else
        {
            minStack.push(minStack.top());
        }
        if(min>val)
        {
            min = val;
        }
        addAtHead(&topNode,val);
    }
    
    void pop() {
        
        /*if(minStack.top() == topNode->val)
        {
            minStack.pop();
        }
        */
        minStack.pop();
        deleteAtHead(&topNode);
        if(topNode == NULL)
        {
            min = std::numeric_limits<int>::max();
        }
    }

    int top() {
        if(topNode!=NULL)
        {

            return topNode->val;
        }
        return -1;
    }
    
    int getMin() 
    {
        //return min;

        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
