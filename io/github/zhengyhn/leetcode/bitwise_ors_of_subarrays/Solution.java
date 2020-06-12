package io.github.zhengyhn.leetcode.bitwise_ors_of_subarrays;

import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int subarrayBitwiseORs(int[] A) {
        if (A.length <= 1) {
            return A.length;
        }
        Set<Integer> result = new HashSet<Integer>();
        Set<Integer> current = new HashSet<Integer>();
        current.add(0);
        for (int i = 0; i < A.length; ++i) {
            Set<Integer> temp = new HashSet<Integer>();
            for (int num: current) {
                temp.add(num | A[i]);
            }
            temp.add(A[i]);
            current = temp;
            result.addAll(current);
        }
        return result.size();
    }
    public static void main(String[] args) {
        Solution sln = new Solution();
        System.out.println(sln.subarrayBitwiseORs(new int[]{1, 2, 3}));
    }
}
