class Skiplist
{
    class node
    {
        public:
        int val;
        node * next;
        node * down;
       	// constructor for initializing node val and next, down pointers
        node(int _val, node *_next, node *_down)
        {
            val = _val;
            next = _next;
            down = _down;
        }
    };

    public:
    node * head;
    vector<node*> insertionPoints;

    Skiplist()
    {
        head = new node(0, nullptr, nullptr);
    }

    bool search(int target)
    {
       	// traverse the express lane and stop on the 
       	// node whose next is larger than the target.

        node *curr = head;
        while (curr)
        {
           	// travel through express lane until node's next is larger than target
            while (curr->next and curr->next->val < target) curr = curr->next;

           	// then traverse to deeper layer if such node is found or no next node exists.
            if (!curr->next or curr->next->val > target) curr = curr->down;

           	// if target is found
            else if (curr->val == target or curr->next->val == target) return true;
        }
        return false;
    }

    void add(int num)
    {
        // vector to keep track of insertion points
        insertionPoints.clear();
        node *curr = head;

        // find a place to insert node and store the insertion points.
        while (curr)
        {
            while (curr->next and curr->next->val < num) curr = curr->next;
            insertionPoints.push_back(curr);
            curr = curr->down;
        }

        node *downNode = nullptr;
        bool insertUp = true;

        
        while (insertUp and insertionPoints.size() > 0)
        {
            node *dummy = insertionPoints.back();
            insertionPoints.pop_back();

            dummy->next = new node(num, dummy->next, downNode);
            downNode = dummy->next;

            insertUp = (rand() &1) == 0;
        }
        if (insertUp)
        {
            head = new node(0, new node(num, NULL, downNode), head);
        }
    }

    bool erase(int num)
    {
        node *curr = head;
        bool seen = false;
        while (curr)
        {
            //search the node through the lanes
            while (curr->next and curr->next->val < num) curr = curr->next;
            if (!curr->next or curr->next->val > num) curr = curr->down;
            else
            {
                // if found seen -> true and manipulate the pointors
                seen = true;
                curr->next = curr->next->next;
                curr = curr->down;
            }
        }
        return seen;
    }
};

/**
 *Your Skiplist object will be instantiated and called as such:
 *Skiplist* obj = new Skiplist();
 *bool param_1 = obj->search(target);
 *obj->add(num);
 *bool param_3 = obj->erase(num);
 */