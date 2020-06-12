package io.github.zhengyhn.leetcode.median_of_two_sorted_arrays;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int i = 0, j = 0, k = 0;
        int mid = m + (n - m) / 2;
        int current = m > 0 ? nums1[0] : nums2[0];
        int last = current;
        while (k <= mid) {
            last = current;
            if (i < m && j < n && nums1[i] < nums2[j]) {
                current = nums1[i];
                ++i;
            } else if (j < n) {
                current = nums2[j];
                ++j;
            } else {
                current = nums1[i];
                ++i;
            }
            ++k;
        }
        if ((m % 2 == 0 && n % 2 == 1) || (m % 2 == 1 && n % 2 == 0)) {
            return current;
        } else {
            return (last + (double)(current - last) / 2);
        }
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        assert(2 == sln.findMedianSortedArrays(new int[]{1, 3}, new int[]{2}));
        assert(1.5 == sln.findMedianSortedArrays(new int[]{1}, new int[]{2}));
        assert(1.5 == sln.findMedianSortedArrays(new int[]{}, new int[]{1, 2}));
        assert(1.5 == sln.findMedianSortedArrays(new int[]{3, 3}, new int[]{2, 2}));
        assert(1.5 == sln.findMedianSortedArrays(new int[]{1, 2}, new int[]{3, 4}));
        assert(4.5 == sln.findMedianSortedArrays(new int[]{2}, new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9}));
    }
}
