class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	
		int size = s.length();
		map<char, bool> dict;

		int curlen = 0;
		int maxlen = 0;
		int start = 0;

		for(int i=0; i<size; i++)
		{
			char ch = s[i];

			if (!dict[ch])
			{
				dict[ch] = true;
				
				if( ++curlen > maxlen)
				{
					maxlen = curlen;
				}
			}
			else
			{
				for (start; start < i; start++)
				{
					if (s[start] == ch)
					{
						start++;
						break;
					}
					dict[s[start]] = false;
					curlen--;
				}
			}
		}

		return maxlen;
        
    }
};