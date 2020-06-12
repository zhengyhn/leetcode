package io.github.zhengyhn.leetcode.fraction_to_recurring_decimal;

import java.util.HashMap;
import java.util.Map;

public class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        int sign = 1;
        long num = numerator;
        long deno = denominator;
        if (num < 0) {
            sign = -sign;
            num = -num;
        }
        if (deno < 0) {
            sign = -sign;
            deno = -deno;
        }

        long divider = num / deno;
        String s = divider + "";
        long mod = num % deno;
        if (mod == 0) {
            return sign < 0 ? "-" + s : s;
        }
        s += ".";
        Map<Long, Integer> map = new HashMap<Long, Integer>();
        while (mod != 0) {
            long key = mod * 10;
            divider = key / deno;
            mod = key % deno;
            if (map.containsKey(key)) {
                int i = map.get(key);
                s = s.substring(0, i) + "(" + s.substring(i) + ")";
                break;
            }
            map.put(key, s.length());
            s += divider + "";
        }
        return sign < 0 ? "-" + s : s;
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        System.out.println(sln.fractionToDecimal(109, 900));
    }
}
