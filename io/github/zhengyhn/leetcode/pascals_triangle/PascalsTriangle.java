import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class PascalsTriangle {
    public static class Solution {
        public List<List<Integer>> generate(int numRows) {
            List<List<Integer>> result = new ArrayList<List<Integer>>();
            Integer[][] temp = new Integer[numRows][numRows];

            for (int i = 0; i < numRows; ++i) {
                // 首尾赋值
                temp[i][0] = temp[i][i] = 1;

                // 中间赋值，对称
                for (int j = 1; j <= i / 2; ++j) {
                    temp[i][j] = temp[i][i - j] = temp[i - 1][j - 1] + temp[i - 1][j];
                }

                result.add(Arrays.asList(Arrays.copyOfRange(temp[i], 0, i + 1)));
            }
            
            return result;
        }
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        List<List<Integer>> res = sln.generate(10);

        for (int i = 0; i < res.size(); ++i) {
            for (int j = 0; j < res.get(i).size(); ++j) {
                System.out.print(res.get(i).get(j) + " ");
            }
            System.out.println("");
        }
    }
}
