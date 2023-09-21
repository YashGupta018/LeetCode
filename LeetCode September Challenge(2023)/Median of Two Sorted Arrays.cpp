class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0;
        int r = n1;
        while (l <= r) {
            int mid1 = (l + r) / 2;
            int mid2 = (n1 + n2 + 1) / 2 - mid1;
            int maxLeft1 = (mid1 == 0) ? INT_MIN : nums1[mid1-1];
            int minRight1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int maxLeft2 = (mid2 == 0) ? INT_MIN : nums2[mid2-1];
            int minRight2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((n1 + n2) % 2 == 0) {
                    return (double)(max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2;
                } else {
                    return (double)max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                r = mid1 - 1;
            } else {
                l = mid1 + 1;
            }
        }
        return -1;
    }
};