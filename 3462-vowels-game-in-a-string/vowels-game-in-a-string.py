class Solution(object):
    def doesAliceWin(self, s):
        for i in s:
            if i in 'aeiou':
                return True
        return False
        