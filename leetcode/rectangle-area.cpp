class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (C-A)*(D-B)+(G-E)*(H-F)-overLap(A, C, E, G) * overLap(B, D, F, H);
    }
    
    int overLap(int s1, int t1, int s2, int t2) {
        if (s1 >= t2 || s2 >= t1) return 0;
        return min(t1, t2) - max(s1, s2);
    }
};