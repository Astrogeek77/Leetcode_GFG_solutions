class MedianFinder 
{
private:
    /* 
        we take the stream and divide it into two list 
        one small than the median -> smallList
        and one greator then median -> largeList
        
        at any time if the count is even the median will be avg of 
        smallList->top and largeList->top
        
        if the numbers are odd, more numbers are stored in smallList(max Heap)
    */
    
    // smallList -> maxHeap 
    priority_queue<int> maxHeap; // smallList
    priority_queue<int, vector<int>, greater<int>> minHeap; // largeList
    
public:
    MedianFinder() {}
    
    void addNum(int num) 
    {
        if (maxHeap.empty() or maxHeap.top() >= num)
			maxHeap.push(num);
		else 
            minHeap.push(num);

        // balance the two lists
        // if smallList is larger, push the top element to largeList
		if (maxHeap.size() > minHeap.size() + 1) 
        {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		} 
        // if largeList is larger, push the top element to smallList
        else if (minHeap.size() > maxHeap.size() + 1) 
        {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
    }
    
    double findMedian() 
    {
        // if the two list are of equal size
        if (maxHeap.size() == minHeap.size()) 
        {
            // if empty return 0
			if (maxHeap.empty()) return 0;
			else 
            {
                // calculate avg and return avg
				double avg = (maxHeap.top() + minHeap.top()) / 2.0;
				return avg;
			}

		} 
        // return top element of larger list
        else
			return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
    }
};
/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 */