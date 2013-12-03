/*
Sherlock Holmes received a note with some strange strings: "Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". It took him only a minute to figure out that those strange strings are actually referring to the coded time "Thursday 14:04" -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter 'D', representing the 4th day in a week; the second common character is the 5th capital letter 'E', representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is 's' at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

Input Specification:

Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.

Output Specification:

For each test case, print the decoded time in one line, in the format "DAY HH:MM", where "DAY" is a 3-character abbreviation for the days in a week -- that is, "MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, "THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" for Sunday. It is guaranteed that the result is unique for each case.

Sample Input:
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
Sample Output:
THU 14:04
*/

#include<stdio.h>
#include<string.h>

#define min(a,b) (a<b)?a:b

int main()
{
	int day, hour, minute;
	char s1[65], s2[65], s3[65], s4[65];

	scanf("%s %s %s %s", s1, s2, s3, s4);

	int len = min(strlen(s1), strlen(s2));

	int ncommon = 0;

	int start;

	for( int i=0; i<len; i++)
	{
		if( s1[i] == s2[i] )
		{
			if( s1[i] <='G' && s1[i] >='A')
			{
				day = s1[i] - 'A' + 1;
				start = i+1;
				break;
			
			}
		}
	}
	
	for(int i=start; i<len; i++)
	{
		if( s1[i] == s2[i])
		{
			if( s1[i] <='N' && s1[i] >='A')
			{
				hour = s1[i] - 'A' + 10;	
				break;
			}
			else if( s1[i] <='9' && s1[i] >= '0')
			{
				hour = s1[i] - '0';	
				break;
			}
		}
	}
	len = min(strlen(s3), strlen(s4));

	for( int i=0; i<len; i++)
	{
		if( s3[i] >='A' && s3[i] <='Z' || s3[i] >='a' && s3[i] <= 'z')
		{
			if( s3[i] == s4[i])
			{
				minute = i;
				hour += minute/60;
				minute = minute%60;
				hour = hour%24;

				day = (day-1)%7+1;
				break;
			}
		}
	}

	char days[][4]={"","MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

	printf("%s %02d:%02d", days[day], hour, minute);
	return 0;
}