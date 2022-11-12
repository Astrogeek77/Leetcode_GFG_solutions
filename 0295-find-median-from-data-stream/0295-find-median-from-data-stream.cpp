class MedianFinder {
private:
    priority_queue<int> maxpart;        // descending
    priority_queue<int, vector<int>, greater<int>> minpart;    //ascending
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {         
        maxpart.push(num);              
        minpart.push(maxpart.top());  
        maxpart.pop();    
        
        if(maxpart.size() < minpart.size())
        {   
            maxpart.push(minpart.top());        
            minpart.pop();                    
        }
    }
    
    double findMedian() {
        if(maxpart.size() > minpart.size()) 
            return maxpart.top();   
        return (maxpart.top() + minpart.top())/2.0;  
    }
};
/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 */