package io.github.zhengyhn.leetcode.temp;

import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int xVote = in.nextInt();
        int yVote = in.nextInt();
        for(int i = 1; i < n;i++) {
            int x = in.nextInt();
            int y = in.nextInt();

            //write your code
            while (true) {
                int a = xVote * y;
                int b = yVote * x;
                if (a == b) {
                    break;
                } else if (a < b) {
                    xVote = (b / y - xVote) > 0 ? b / y : (xVote + 1);
                } else {
                    yVote = (a / x - yVote) > 0 ? a / x : (yVote + 1);
                }
            }
        }
        System.out.println(xVote + yVote);
    }
}
