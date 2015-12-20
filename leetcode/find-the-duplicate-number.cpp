
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> v = nums;
        for (int i=0; i<v.size(); i++)
            while (v[i] != i+1 && v[i] != v[v[i]-1])
                swap(v[i], v[v[i]-1]);
        for (int i=0; i<v.size(); i++)
            if (v[i] != i+1) return v[i];
    }
};