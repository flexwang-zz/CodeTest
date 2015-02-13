/*
One important factor to identify acute stroke (急性脑卒中) is the volume of the stroke core. Given the results of image analysis in which the core regions are identified in each MRI slice, your job is to calculate the volume of the stroke core.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: M, N, L and T, where M and N are the sizes of each slice (i.e. pixels of a slice are in an M by N matrix, and the maximum resolution is 1286 by 128); L (<=60) is the number of slices of a brain; and T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be counted).

Then L slices are given. Each slice is represented by an M by N matrix of 0's and 1's, where 1 represents a pixel of stroke, and 0 means normal. Since the thickness of a slice is a constant, we only have to count the number of 1's to obtain the volume. However, there might be several separated core regions in a brain, and only those with their volumes no less than T are counted. Two pixels are "connected" and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red pixels are connected to the blue one.


Figure 1
Output Specification:

For each case, output in a line the total volume of the stroke core.

Sample Input:
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
Sample Output:
26
*/
#include <stdio.h>
#include <vector>

using namespace std;

vector<int>     pixels;
vector<bool>    used;
int             m, n, l, t;

int delta[][3]=
{
    -1, 0, 0,
    1, 0, 0,
    0, -1, 0,
    0, 1, 0,
    0, 0, -1,
    0, 0, 1
};

void n_to_xyz(int id, int &x, int &y, int &z)
{
    z = id / (m*n);
    y = id % (m*n) / n;
    x = id % (m*n) % n;
}

int xyz_to_n(int x, int y, int z)
{
    return z*m*n + y*n + x;
}

bool is_used(int x, int y, int z)
{
    if (x < 0 || x >= n || y < 0 || y >=m || z < 0 || z >= l)
        return true;
    return used[xyz_to_n(x, y, z)];
}

void dfs(int v, int& volume) 
{
    used[v] = true;
    volume ++;

    int x, y, z;
    n_to_xyz(v, x, y, z);

    for (int i=0; i<6; i++) {
        int id = xyz_to_n(x+delta[i][0], y+delta[i][1], z+delta[i][2]);
        if (!is_used(x+delta[i][0], y+delta[i][1], z+delta[i][2]) && pixels[id])
            dfs(id, volume);
    }
}

void bsf(int v, int& volume) 
{
    vector<int> this_layer, nextlayer;
    this_layer.push_back(v);
    
    while(this_layer.size()) {
        nextlayer.clear();
        for (int i=0; i<this_layer.size(); i++) {
            v = this_layer[i];
            if (used[v]) continue;
            used[v] = true;
            volume ++;
            int x, y, z;
            n_to_xyz(v, x, y, z);

            for (int j=0; j<6; j++) {
                int id = xyz_to_n(x+delta[j][0], y+delta[j][1], z+delta[j][2]);
                if (!is_used(x+delta[j][0], y+delta[j][1], z+delta[j][2]) && pixels[id])
                    nextlayer.push_back(id);
            }
        }
        this_layer = nextlayer;
    }
}





int main()
{
    scanf("%d %d %d %d", &m, &n, &l, &t);

    pixels.resize(m*n*l);
    used.assign(m*n*l, false);

    for (int i=0; i<m*n*l; i++)
        scanf("%d", &pixels[i]);


    int ans = 0;
    for (int i=0; i<m*n*l; i++) {
        if (!used[i] && pixels[i]) {
            int volume = 0;
            bsf(i, volume);
            if (volume >= t)
                ans += volume;
        }
    }

    printf("%d", ans);

    return 0;
}