class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string words[]={"", " Thousand"," Million", " Billion"};
        string ans;
        for (int i=0; num; i++) {
            if (num%1000)
                ans = numberToWordHelper(num%1000)+words[i] + ans;
            num /= 1000;
        }
        return ans.substr(1);
    }
    string numberToWordHelper(int num) {
        string words1[]={"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
        string words2[]={" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
        string words3[]={"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
        string ans;
        if (num / 100)
            ans += words1[num/100]+" Hundred";
        if (num % 100 < 20 && num % 100 >= 10)
            ans += words2[num%100-10];
        else if (num % 100 < 10 && num % 100 > 0)
            ans += words1[num%100];
        else if (num % 100 >= 20) {
            ans += words3[num%100/10];
            if (num%10 > 0)
                ans += words1[num%10];
        }
        return ans;
    }
};