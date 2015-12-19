/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int ans = 0;
        for (auto p:points) {
            int same = 0;
            unordered_map<double, int> um;
            for (auto q:points) {
                if (p.x == q.x && p.y==q.y)
                    same ++;
                else
                    um[atan2(q.y-p.y, q.x-p.x)]++;
            }
            ans = max(ans, same);
            for (auto x:um)
                ans = max(ans, same+x.second);
        }
        return ans;
    }
};