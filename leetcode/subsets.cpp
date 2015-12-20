/*
Given a set of distinct integers, S, return all possible subsets.

Note:
	Elements in a subset must be in non-descending order.
	The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        
        int size = 1<<S.size();
        
        sort(S.begin(), S.end());
        
        vector<vector<int>> result(size);
        
        for (int i=0; i<size; i++)
        {
            int x = i;
            int j = 0;
            
            while(x)
            {
                if (x%2)
                {
                    result[i].push_back(S[j]);
                }
                x = x>>1;
                j++;
            }
        }
        
        return result;
    }
};