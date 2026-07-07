class MedianFinder {
public:
    priority_queue<double> leftHeap;
    priority_queue<double, vector<double>, greater<double>> rightHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftHeap.size() == 0 && rightHeap.size() == 0 || num <= leftHeap.top()) leftHeap.push(num);
        else rightHeap.push(num);
        if(abs((int)leftHeap.size() - (int)rightHeap.size()) > 1) {
            if(leftHeap.size() > rightHeap.size()) {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
            }
            else {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if((leftHeap.size() == rightHeap.size())) return (leftHeap.top() + rightHeap.top()) / 2;
        if(leftHeap.size() > rightHeap.size()) return leftHeap.top();
        return rightHeap.top();
    }
};