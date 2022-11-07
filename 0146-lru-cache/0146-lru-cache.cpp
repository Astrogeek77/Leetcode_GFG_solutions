class LRUCache
{
    public:
    // node class to define a DLL node
    class node
    {
        public:
        int key;
        int val;
        node * next;
        node * prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    // required utilities
    int cap, size;
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    
    // unordered_map<int, node *> map;
    vector<node*> map;

    // initial values and creation of a two node DLL. head -> tail <=> head <- tail
    LRUCache(int capacity)
    {
        cap = capacity;
        size = 0;
        head->next = tail;
        tail->prev = head;
        
        map = vector<node *> (10009, nullptr);
    }
    
    // utility function to add new node just after the head node.
    void addnode(node* newnode)
    {
        // node *temp = new node(-1, -1);
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
        
        size++;
    }
    
    // utility function to delete a node
    void deletenode(node* delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        // delete delnode;
        
        size--;
    }

    int get(int key) 
    {
        // we check if the key exists in the map or not.
        
        // if(map.find(key) == map.end()) return -1;
        if(map[key] == nullptr) return -1; 
        
        // we get the node corresponding to key, delete it and add it again as most recent node.
        node *curr = map[key];
        int val = curr->val;
        
        // map.erase(key);
        map[key] = nullptr;
        
        deletenode(curr);
        addnode(new node(key, val));
        
        
        // map[key] = NULL;
        
        // change the node in the map.        
        map[key] = head->next;
        // return node val;
        return val;
    }

    void put(int key, int value) 
    {
        // check if the node with the key previously exists
        // if does delete the node.
        
        
        // if(map.find(key) != map.end())
        if(map[key] != nullptr)
        {
            node *curr = map[key];
            // map.erase(key);
            map[key] = nullptr;
            deletenode(curr);
        }
        
        // if the capacity is full, delete the least recently used node i.e tail->prev
        if(size == cap)
        {
            // map.erase(tail->prev->key);
            map[tail->prev->key] = nullptr;
            deletenode(tail->prev);
        }
        
        // add new node with the new value as most recent node.
        node *newnode = new node(key, value);
        addnode(newnode);
        map[key] = head->next;
    }
};

/**
 *Your LRUCache object will be instantiated and called as such:
 *LRUCache* obj = new LRUCache(capacity);
 *int param_1 = obj->get(key);
 *obj->put(key,value);
 */