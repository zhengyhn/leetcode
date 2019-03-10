class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res = [0 for i in range(numRows)]

        for i in range(0, numRows):
            tmp = [1 for i in range(i + 1)]

            for j in range(1, i):
                tmp[j] = res[i - 1][j - 1] + res[i - 1][j]
            res[i] = tmp

        return res

    def generate_func(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:
            return []
        res = [[1]]
        for i in range(numRows - 1):
            res.append(list(map(sum, zip([0] + res[-1], res[-1] + [0]))))
        return res

    def generate_com(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res = [0 for i in range(numRows)]
        for n in range(numRows):
            row = [1 for i in range(n + 1)]
            for k in range(1, n):
                row[k] = row[k - 1] * (n - k + 1) / k
            res[n] = row
        return res


sln = Solution()
list = sln.generate(10)

for row in list:
    for item in row:
        print(item),
    print ''
