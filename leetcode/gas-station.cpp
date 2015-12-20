class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        
        int size = gas.size();
        int cur = 0;
        int start = 0;
        int end = 0;
        
        do
        {
            while (cur >= 0)
            {
                cur += (gas[end]-cost[end]);
                
                end = (end+1)%size;
                if (end == start)
                {
                    break;
                }
            }
            
            while (cur < 0)
            {
                start = (start+size-1)%size;
                
                cur += gas[start] - cost[start];
                
                if (end == start)
                {
                    break;
                }
            }
        }while (start != end);
        
        if (cur >= 0)
        {
            return start;
        }
        
        return -1;
    }
};