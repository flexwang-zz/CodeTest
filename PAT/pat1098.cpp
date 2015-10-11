/*
According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Heap sort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region. it involves the use of a heap data structure rather than a linear-time search to find the maximum.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in the first line either "Insertion Sort" or "Heap Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
Sample Output 2:
Heap Sort
5 4 3 1 0 2 6 7 8 9
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int is_inser(vector<int> v1, const vector<int> &v2) {
  for (int i=0; i<=v1.size(); i++) {
      sort(v1.begin(), v1.begin()+i);
      if (v1 == v2) return i;
  }
  return -1;
}

inline void print(const vector<int> &v) {
    for (int i=0; i<v.size(); i++)
        printf("%d%c", v[i], i==v.size()-1?'\n':' ');
}

inline void percolate_down(vector<int> &v, int id, int t) {
    int p = v[id];
    for (int child;id*2+1 < t; id=child) {
        child = id*2+1;
        if (child+1 <t && v[child] < v[child+1])
            child++;
        if (p > v[child]) break;
        else v[id] = v[child];
    }
    v[id] = p;
}
void my_make_heap(vector<int>& v, int t) {
    for (int i=t/2-1; i>=0; i--)
        percolate_down(v, i, t);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i=0; i<n; i++)
        cin >> v1[i];
    for (int i=0; i<n; i++)
        cin >> v2[i];
    int inser = is_inser(v1, v2);
    if (inser >= 0) {
        cout << "Insertion Sort" << endl;
        v1 = v2;
        while (v1 == v2 && inser < n)
            sort(v2.begin(), v2.begin()+(++inser));
        print(v2);
        return 0;
    }
    cout << "Heap Sort" << endl;
    bool do_break = false;
    if (v1 == v2) do_break = true;
    my_make_heap(v1, n);
    for (int i=n-1; i>0; i--) {
        swap(v1[i], v1[0]);
        my_make_heap(v1, i);
        if (do_break) break;
        if (v1 == v2) do_break = true;
    }
    print(v1);
    return 0;
  
    
}
