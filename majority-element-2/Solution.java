import java.util.List;
import java.util.ArrayList;

public class Solution {
    public static List<Integer> majorityElement(int[] nums) {
        int m1, m2 , m1Count, m2Count;
        m1 = m2 = m1Count = m2Count = 0;

        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == m1) {
                ++m1Count;
            } else if (nums[i] == m2) {
                ++m2Count;
            } else if (m1Count == 0) {
                m1 = nums[i];
                m1Count = 1;
            } else if (m2Count == 0) {
                m2 = nums[i];
                m2Count = 1;
            } else {
                --m1Count;
                --m2Count;
            }
        }

        m1Count = m2Count = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (m1 == nums[i]) {
                ++m1Count;
            } else if (m2 == nums[i]) {
                ++m2Count;
            }
        }
        List<Integer> res = new ArrayList<Integer>();

        if (m1Count > (nums.length / 3)) {
            res.add(m1);
        }
        if (m2Count > (nums.length / 3)) {
            res.add(m2);
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5,
            6, 6, 6, 6, 6, 6, 6, 7, 8};
        List<Integer> res = majorityElement(nums);
        System.out.println(res);

        return;
    }
}
