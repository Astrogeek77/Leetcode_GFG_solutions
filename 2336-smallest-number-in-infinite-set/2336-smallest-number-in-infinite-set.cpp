class SmallestInfiniteSet 
{
    int min_num = 1;
    priority_queue<int, vector<int>, greater<int>> heap;
    unordered_set<int> nums;
public:
    int popSmallest() 
    {
        if (!heap.empty()) 
        {
            int smallest = heap.top();
            heap.pop();
            
            nums.erase(smallest);
            return smallest;
        }
        min_num++;
        return min_num - 1;
    }

    void addBack(int num) 
    {
        if (min_num > num && nums.find(num) == nums.end()) 
        {
            heap.push(num);
            nums.insert(num);
        }
    }
};