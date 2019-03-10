package io.github.zhengyhn.leetcode.permutations;

import java.time.LocalDateTime;
import java.time.ZoneOffset;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.function.Function;
import java.util.function.Supplier;
import java.util.stream.Collectors;

public class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        helper(list, 0, nums);

        return list;
    }

    private void helper(List<List<Integer>> list, int begin, int[] nums) {
        if (begin >= nums.length) {
            list.add(Arrays.stream(nums).boxed().collect(Collectors.toList()));
            return;
        }
        for (int i = begin; i < nums.length; ++i) {
            swap(nums, begin, i);
            helper(list, begin + 1, nums);
            swap(nums, begin, i);
        }
    }

    private void swap(int[] nums, int i, int j) {
        if (i == j) {
            return;
        }
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private void swapChar(char[] nums, int i, int j) {
        if (i == j) {
            return;
        }
        char temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public List<String> permuteString(String str) {
        List<String> list = new ArrayList<>();
        stringHelper(list, 0, str.toCharArray());

        return list;
    }

    public void stringHelper(List<String> list, int begin, char[] str) {
        if (begin >= str.length) {
            list.add(new String(str));
            return;
        }
        for (int i = 0; i < str.length; ++i) {
            swapChar(str, begin, i);
            stringHelper(list, begin + 1, str);
            swapChar(str, begin, i);
        }
    }

    public String nextPermutation(String string) {
        char[] chars = string.toCharArray();
        int i = chars.length - 1;
        for (; i > 0; --i) {
            if (chars[i] > chars[i - 1]) {
                break;
            }
        }
        if (i > 0) {
            int j = chars.length - 1;
            for (; j >= i; --j) {
                if (chars[j] > chars[i - 1]) {
                    break;
                }
            }
            swapChar(chars, j, i -1);
        }
        int end = chars.length - 1;
        while (i < end) {
            swapChar(chars, i++, end--);
        }
        return new String(chars);
    }

    public List<String> permuteStringIter(String str) {
        List<String> list = new ArrayList<>();
        if (str.length() <= 0) {
            return list;
        }
        String string = str;
        list.add(string);
        while (true) {
            String nextString = this.nextPermutation(string);
            if (nextString.equals(str)) {
                break;
            }
            list.add(nextString);
            string = nextString;
        }
        return list;
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
//        int[] nums = {1, 2, 3, 4, 5};
//        List<List<Integer>> ret = sln.permute(nums);
//        ret.forEach(System.out::println);
//
//        List<String> test = sln.permuteString2("");
//        test.forEach(System.out::println);
//
//        test = sln.permuteString2("a");
//        test.forEach(System.out::println);
//
//        test = sln.permuteString2("abc");
//        test.forEach(System.out::println);
        Supplier<Long> now = () ->  LocalDateTime.now().toInstant(ZoneOffset.UTC).toEpochMilli();
        long startTime = now.get();
        sln.permuteStringIter("abcdefgh");
        long endTime = now.get();
        System.out.println(endTime - startTime);

        startTime = now.get();
        sln.permuteString("abcdefgh");
        endTime = now.get();
        System.out.println(endTime - startTime);
        // test.forEach(System.out::println);
    }
}
