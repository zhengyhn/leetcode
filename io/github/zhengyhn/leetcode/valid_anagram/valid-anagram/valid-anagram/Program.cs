using System;

namespace validanagram
{
	public class MainClass {
		public class Solution {
			public bool IsAnagram(string s, string t) {
				if (s.Length != t.Length) {
					return false;
				}

				int[] first = new int[26];
				int[] second = new int[26];

				for (int i = 0; i < s.Length; ++i) {
					first [s [i] - 'a'] += 1;
				}
				for (int i = 0; i < t.Length; ++i) {
					second [t [i] - 'a'] += 1;
				}

				for (int i = 0; i < 26; ++i) {
					if (first [i] != second [i]) {
						return false;
					}
				}
				return true;
			}
		}

		public static void Main (string[] args)
		{
			Solution sln = new Solution ();

			if (sln.IsAnagram("rat", "cat")) {
				Console.WriteLine("t");
			} else {
				Console.WriteLine("f");
			}
		}
	}
}
