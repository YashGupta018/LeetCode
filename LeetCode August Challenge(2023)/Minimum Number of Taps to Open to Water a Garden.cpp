class Solution {
public
    int minTaps(int n, int[] ranges) {
        int[] maxReach = new int[n + 1];
        for (int i = 0; i < ranges.length; i++) {
            int s = Math.max(0, i - ranges[i]), e = i + ranges[i];
            maxReach[s] = e;
        }
        int tap = 0, currEnd = 0, nextEnd = 0;
        for (int i = 0; i <= n; i++) {
            if (i > nextEnd)
                return -1;
            if (i > currEnd) {
                tap++;
                currEnd = nextEnd;
            }
            nextEnd = Math.max(nextEnd, maxReach[i]);
        }
        return tap;
    }
}