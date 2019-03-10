class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False

        first = [0] * 26
        second = first[:]
        for c in s:
            first[ord(c) - ord('a')] += 1
        for c in t:
            second[ord(c) - ord('a')] += 1

        for i in range(0, 26):
            if first[i] != second[i]:
                return False

        return True

sln = Solution()
if sln.isAnagram('rat', 'cat'):
    print 't'
else:
    print 'f'
