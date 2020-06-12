package io.github.zhengyhn.leetcode.median_of_two_sorted_arrays;

class SolutionBinarySearch {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int totalLeft = m + (n - m + 1) / 2;
        int low = 0;
        int high = m;
        int i = 0, j = 0;
        while (low < high) {
            i = low + (high - low + 1) / 2;
            j = totalLeft - i;
            if (nums1[i - 1] < nums2[j]) {
               low = i;
            } else {
                high = i - 1;
            }
        }
        i = low;
        j = totalLeft - i;
        int mLeftMax = (i - 1) < 0 ? Integer.MIN_VALUE : nums1[i - 1];
        int mRightMin = i >= m ? Integer.MAX_VALUE : nums1[i];
        int nLeftMax = (j - 1) < 0 ? Integer.MIN_VALUE : nums2[j - 1];
        int nRightMin = j >= n ? Integer.MAX_VALUE : nums2[j];
        int leftMax = Math.max(mLeftMax, nLeftMax);
        int rightMin = Math.min(mRightMin, nRightMin);
        if ((m % 2 == 0 && n % 2 == 1) || (m % 2 == 1 && n % 2 == 0)) {
            return leftMax;
        } else {
            return (leftMax + (double)(rightMin - leftMax) / 2);
        }
    }

    public static void main(String[] args) {
        SolutionBinarySearch sln = new SolutionBinarySearch();
        assert(2 == sln.findMedianSortedArrays(new int[]{1, 3}, new int[]{2}));
        assert(1.5 == sln.findMedianSortedArrays(new int[]{1}, new int[]{2}));
        assert(1.5 == sln.findMedianSortedArrays(new int[]{}, new int[]{1, 2}));
        assert(1.5 == sln.findMedianSortedArrays(new int[]{3, 3}, new int[]{2, 2}));
        assert(1.5 == sln.findMedianSortedArrays(new int[]{1, 2}, new int[]{3, 4}));
        assert(4.5 == sln.findMedianSortedArrays(new int[]{2}, new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9}));
    }
}
