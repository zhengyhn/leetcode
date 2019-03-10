using System;
using System.Collections.Generic;
using System.Collections.Specialized;

namespace pascalstriangle
{
	class MainClass
	{
		public class Solution {
			public IList<IList<int>> Generate(int numRows) {
				IList<IList<int>> result = new List<IList<int>> (numRows);

				if (numRows <= 0) {
					return result;
				}
				for (int i = 0; i < numRows; ++i) {
					IList<int> row = new List<int> (numRows);
					row.Add(1);	

					for (int j = 1; j < i; ++j) {
						row.Add(result [i - 1] [j - 1] + result [i - 1] [j]);
					}
					if (i > 0) {
						row.Add (1);
					}
					result.Add(row);
				}
				return result;
			}
		}

		public static void Main (string[] args)
		{
			Solution sln = new Solution ();
			IList<IList<int>> list = sln.Generate (10);

			for (int i = 0; i < list.Count; ++i) {
				for (int j = 0; j < list [i].Count; ++j) {
					Console.Write(list[i][j]);
					Console.Write (" ");
				}
				Console.WriteLine ();
			}
		}
	}
}
