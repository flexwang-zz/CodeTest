class Solution {
 public:
     int divide(int dividend, int divisor) {
         if (divisor == 0) return INT_MAX;

         int sign = 1;
         unsigned int udividend, udivisor;
         udividend = dividend;
         udivisor = divisor;
         if (dividend < 0 && divisor< 0) {
             udividend = dividend==INT_MIN?(unsigned int)INT_MAX+1:-dividend;
             udivisor = divisor==INT_MIN?(unsigned int)INT_MAX+1:-divisor;
         }
         else if (dividend < 0) {
             udividend = dividend==INT_MIN?(unsigned int)INT_MAX+1:-dividend;
             sign = -1;
         }
         else if (divisor < 0) {
             udivisor = divisor==INT_MIN?(unsigned int)INT_MAX+1:-divisor;
             sign = -1;
         }

         unsigned int ans = 0;
         unsigned p = 1;
         while ((udivisor << 1) <= udividend && (udivisor << 1) > 0) {
             udivisor <<= 1;
             p <<= 1;
         }

         while (p) {
             if (udividend >= udivisor) {
                 ans += p;
                 udividend -= udivisor;

             }
             udivisor >>= 1;
             p >>= 1;
         }
         if ((int)ans < 0 && sign > 0) return INT_MAX;
         return sign<0 ? -ans : ans;
     }
 };