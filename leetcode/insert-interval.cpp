/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int i;
        for (i=0; i<intervals.size() && intervals[i].end<newInterval.start; i++)
            result.push_back(intervals[i]);
        for (;i<intervals.size() && intervals[i].start <= newInterval.end; newInterval.end=max(newInterval.end, intervals[i].end), newInterval.start=min(newInterval.start, intervals[i].start), i++);
        result.push_back(newInterval);
        for (;i<intervals.size(); i++)
            result.push_back(intervals[i]);
        return result;
    }
};