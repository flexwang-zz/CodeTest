class Solution {
public:
    static bool comp(const Interval& in1, const Interval& in2) {
        if (in1.start == in2.start)
            return in1.end < in2.end;
        return in1.start < in2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if (intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end(), comp);
        
        for (int i=0; i<intervals.size(); i++) {
            if (i==0 || intervals[i].start > ans.back().end)
                ans.push_back(intervals[i]);
            else if (intervals[i].end <= ans.back().end)
                continue;
            else 
                ans.back().end = max(ans.back().end, intervals[i].end);
        }
        return ans;
    }

};