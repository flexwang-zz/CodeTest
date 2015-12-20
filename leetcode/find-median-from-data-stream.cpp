class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (pmax.empty() || pmax.top() >= num) {
            pmax.push(num);
            if (pmin.size()+1 < pmax.size())
                pmin.push(pmax.top()), pmax.pop();
        }
        else {
            pmin.push(num);
            if (pmax.size() < pmin.size())
                pmax.push(pmin.top()), pmin.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (pmax.size() == pmin.size()) return (pmax.top()+pmin.top())/2.0;
        else return pmax.top();
    }
private:
    priority_queue<int> pmax;
    priority_queue<int, vector<int>, greater<int>> pmin;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();