class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        m1, m2, m1Count, m2Count = 0, 0, 0, 0

        for num in nums:
            if m1 == num:
                m1Count += 1
            elif m2 == num:
                m2Count += 1
            elif m1Count == 0:
                m1 = num
                m1Count = 1
            elif m2Count == 0:
                m2 = num
                m2Count = 1
            else:
                m1Count -= 1
                m2Count -= 1

        m1Count = m2Count = 0
        for num in nums:
            if m1 == num:
                m1Count += 1
            elif m2 == num:
                m2Count += 1

        res = []
        if m1Count > (len(nums) / 3):
            res.append(m1)
        if m2Count > (len(nums) / 3):
            res.append(m2)
        return res
                
sln = Solution()
print sln.majorityElement([1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5])
