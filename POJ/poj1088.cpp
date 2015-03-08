/*
Description

Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长底滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子 
 1  2  3  4 5

16 17 18 19 6

15 24 25 20 7

14 23 22 21 8

13 12 11 10 9

一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
Input

输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
Output

输出最长区域的长度。
Sample Input

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
Sample Output

25
*/
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int	max_n = 105;
int			h[max_n][max_n];
int			r, c;
int			dat[max_n][max_n];

int dp(int x, int y) {
	if (dat[x][y] > 0)
		return dat[x][y];
	int ans = 1;
	if (x > 0 && h[x][y] > h[x-1][y])
		ans = max(dp(x-1, y)+1, ans);
	if (x < r-1 && h[x][y] > h[x+1][y])
		ans = max(dp(x+1, y)+1, ans);
	if (y > 0 && h[x][y] > h[x][y-1])
		ans = max(dp(x, y-1)+1, ans);
	if (y < c-1 && h[x][y] > h[x][y+1])
		ans = max(dp(x, y+1)+1, ans);
	dat[x][y] = ans;
	return ans;
}
int main()
{
	scanf("%d%d", &r, &c);
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			scanf("%d", &h[i][j]);
	int ans = 0;
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			ans = max(ans, dp(i, j));
	printf("%d\n", ans);
	return 0;
}