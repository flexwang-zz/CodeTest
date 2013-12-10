class Solution {
public:
    int reverse(int x) {
        int result = 0; 
        
        do
        {
            result = result*10 + x%10;
            x /= 10;
        }while(x);
        
        return result;
    }
};