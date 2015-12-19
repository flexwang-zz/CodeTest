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
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<int> v;
        for (int i = 0; i<intervals.size(); i++) {
            v.push_back(intervals[i].start);
            v.push_back(intervals[i].end);
        }

        int s = newInterval.start;
        int t = newInterval.end;

        int idx1 = lower_bound(v.begin(), v.end(), s) - v.begin();
        int start = idx1/2;
        int idx2 = upper_bound(v.begin(), v.end(), t) - v.begin();
        if (idx1 < v.size())
            s = min(s, intervals[start].start);
        int end = idx2 % 2 ? idx2 / 2 : idx2/2-1;
        if (start > end) {
            intervals.insert(intervals.begin()+start,newInterval);
            return intervals;
        }
        t = max(t, intervals[end].end);
        intervals.erase(intervals.begin() + start, intervals.begin() + end + 1);
        intervals.insert(intervals.begin() + start, Interval(s, t));
        return intervals;
    }
};

