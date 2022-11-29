class RandomizedSet
{
    public:
    vector<int> arr;
    unordered_map<int, int> set;
    RandomizedSet()
    {
       	// set and arr are already intialized to 0
    }

    bool insert(int val)
    {
        if (set.find(val) == set.end())
        {
            arr.push_back(val);
            set.insert({ val,
                arr.size() - 1 });
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if (set.find(val) != set.end())
        {
            int last = arr.back();
            arr[set[val]] = arr.back();

            arr.pop_back();
            set[last] = set[val];
            set.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        int random = rand() % arr.size();
        return arr[random];
    }
};

/**
 *Your RandomizedSet object will be instantiated and called as such:
 *RandomizedSet* obj = new RandomizedSet();
 *bool param_1 = obj->insert(val);
 *bool param_2 = obj->remove(val);
 *int param_3 = obj->getRandom();
 */