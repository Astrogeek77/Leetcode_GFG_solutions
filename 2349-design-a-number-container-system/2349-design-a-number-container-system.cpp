class NumberContainers
{
    unordered_map<int, set < int>> set;	// for getting smallest value
    unordered_map<int, int> map;	// index / key - value pair
    public:
    NumberContainers() {}

   	//logn 
    void change(int index, int number)
    {
        // check if value previously exists
        if (map.count(index))
        {
            // store the value and erase it
            int val = map[index];
            set[val].erase(index);
        }

       	//update key / index - value pair and add corresponding index to the set
        map[index] = number;
        set[number].insert(index);
    }

   	//logn
    int find(int number)
    {
       	// check if the number is prev inserted or not
        if (set[number].size() == 0) return -1;
       	// return first of set which will be the minimum value
        return *(set[number].begin());
    }
};