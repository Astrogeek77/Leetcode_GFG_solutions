/**
 *class NestedInteger {
 *  public:
 *   	// Return true if this NestedInteger holds a single integer, rather than a nested list.
 *    bool isInteger() const;
 *
 *   	// Return the single integer that this NestedInteger holds, if it holds a single integer
 *   	// The result is undefined if this NestedInteger holds a nested list
 *    int getInteger() const;
 *
 *   	// Return the nested list that this NestedInteger holds, if it holds a nested list
 *   	// The result is undefined if this NestedInteger holds a single integer
 *const vector<NestedInteger> &getList() const;
 *};
 */

class NestedIterator
{
    vector<int> result;	// end result
    int i = 0;	// index iterator

   	// we create a recursive function to check whether the el is int or a list. we directly push the integer to the result vector and call recursive func again for list. 
    void helper(vector<NestedInteger> &nestedList)
    {
        int n = nestedList.size();
        for (int i = 0; i < n; i++)
        {
            if (nestedList[i].isInteger()) result.push_back(nestedList[i].getInteger());
            else helper(nestedList[i].getList());
        }
    }

    public:
        NestedIterator(vector<NestedInteger> &nestedList) {
            helper(nestedList); // initiate the recursive func.
        }

    int next() {
        int ans = result.at(i); // int at index i
        i++;
        return ans;
    }

    bool hasNext() {
        if(i < result.size()) return true;
        return false;
    }
};

/**
 *Your NestedIterator object will be instantiated and called as such:
 *NestedIterator i(nestedList);
 *while (i.hasNext()) cout << i.next();
 */