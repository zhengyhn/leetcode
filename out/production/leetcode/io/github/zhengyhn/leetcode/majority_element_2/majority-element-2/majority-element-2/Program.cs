using System;
using System.Collections.Generic;
using System.Collections.Specialized;

namespace majorityelement2
{
	class MainClass
	{
		public class Solution {
			public IList<int> MajorityElement(int[] nums) {
				int m1, m2, m1Count, m2Count;

				m1 = m2 = m1Count = m2Count = 0;

				for (int i = 0; i < nums.Length; ++i) {
					if (m1 == nums [i]) {
						++m1Count;
					} else if (m2 == nums [i]) {
						++m2Count;
					} else if (m1Count == 0) {
						m1 = nums [i];
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
				for (int i = 0; i < nums.Length; ++i) {
					if (nums[i] == m1) {
						++m1Count;
					} else if (nums[i] == m2) {
						++m2Count;
					}
				}

				IList<int> res = new List<int>();

				if (m1Count > (nums.Length / 3)) {
					res.Add(m1);
				}
				if (m2Count > (nums.Length / 3)) {
					res.Add(m2);
				}
				return res;
			}
		}

		public static void Main (string[] args)
		{
			int[] nums = { 3, 2, 3 };
			Solution sln = new Solution ();
			IList<int> res = sln.MajorityElement (nums);

			foreach (int elem in res) {
				Console.WriteLine (elem);
			}
		}
	}
}
