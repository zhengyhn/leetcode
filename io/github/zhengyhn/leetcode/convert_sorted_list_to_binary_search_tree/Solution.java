package io.github.zhengyhn.leetcode.convert_sorted_list_to_binary_search_tree;

import javax.swing.tree.TreeNode;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public TreeNode sortedListToBST(ListNode head) {
        List<Integer> list = new ArrayList<>(10);
        ListNode p = head;
        while (p != null) {
            list.add(p.val);
            p = p.next;
        }
        return buildTree(list, 0, list.size() - 1);
    }

    private TreeNode buildTree(List<Integer> list,  int start, int end) {
        if (end < start) {
            return null;
        }
        int mid = (start + end + 1) / 2;
        TreeNode root = new TreeNode(list.get(mid));
        root.left = buildTree(list, start, mid - 1);
        root.right = buildTree(list, mid + 1, end);

        return root;
    }

    private static ListNode createList(int[] arr) {
        if (arr.length < 1) {
           return null;
        }
        ListNode head = new ListNode(arr[0]);
        ListNode p = head;
        for (int i = 1; i < arr.length; ++i) {
           p.next = new ListNode(arr[i]);
           p = p.next;
        }
        return head;
    }

    private static void printTree(TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.left != null) {
            printTree(root.left);
        }
        System.out.print(root.val + " ");
        if (root.right != null) {
            printTree(root.right);
        }
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        ListNode head = createList(new int[]{-10, -3, 0, 5, 9});
        TreeNode root = sln.sortedListToBST(head);
        printTree(root);
        System.out.println();
    }
}
