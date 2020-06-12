package io.github.zhengyhn.leetcode.walking_robot_simulation;

import java.io.IOException;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        int[] commands = new int[]{4,-1,4,-2,4};
        int[][] obstacles = new int[][]{{2, 4}};
        System.out.println(new Solution().robotSim(commands, obstacles));
    }

    public int robotSim(int[] commands, int[][] obstacles) {
        int x = 0;
        int y = 0;
        int dir = 0;
        int max = 0;
        Map<Integer, List<Integer>> xMap = new HashMap<Integer, List<Integer>>();
        Map<Integer, List<Integer>> yMap = new HashMap<Integer, List<Integer>>();
        for (int i = 0; i < obstacles.length; ++i) {
            if (!xMap.containsKey(obstacles[i][1])) {
                xMap.put(obstacles[i][1], new ArrayList<Integer>());
            }
            xMap.get(obstacles[i][1]).add(obstacles[i][0]);

            if (!yMap.containsKey(obstacles[i][0])) {
                yMap.put(obstacles[i][0], new ArrayList<Integer>());
            }
            yMap.get(obstacles[i][0]).add(obstacles[i][1]);
        }
        for (int command : commands) {
            if (command == -2) {
                dir -= 1;
                if (dir < 0) {
                    dir = 3;
                }
            } else if (command == -1) {
                dir += 1;
                if (dir > 3) {
                    dir = 0;
                }
            } else {
                int nextX = x;
                int nextY = y;
                if (dir == 0) {
                    nextY = y + command;
                } else if (dir == 1) {
                    nextX = x + command;
                } else if (dir == 2) {
                    nextY = y - command;
                } else {
                    nextX = x - command;
                }
                if (xMap.containsKey(nextY)) {
                    for (int i : xMap.get(nextY)) {
                        if (nextX <= i && x > i) {
                            nextX = i + 1;
                        } else if (nextX >= i && x < i) {
                            nextX = i - 1;
                        }
                    }
                }
                if (yMap.containsKey(nextX)) {
                    for (int i : yMap.get(nextX)) {
                        if (nextY <= i && y > i) {
                            nextY = i + 1;
                        } else if (nextY >= i && y < i) {
                            nextY = i - 1;
                        }
                    }
                }
                x = nextX;
                y = nextY;
                max = Math.max(max, x * x + y * y);
            }
        }
        return max;
    }
}
