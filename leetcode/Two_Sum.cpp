class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans(2);
		map<int, int> m;
		for (int i=0; i<numbers.size(); i++) {
			map<int, int>::iterator iter = m.find(target-numbers[i]);
			if (iter != m.end()) {
				ans[0] = iter->second+1;
				ans[1] = i+1;
				break;
			}
			m.insert(make_pair(numbers[i], i));
		}
        return ans;
    }
};