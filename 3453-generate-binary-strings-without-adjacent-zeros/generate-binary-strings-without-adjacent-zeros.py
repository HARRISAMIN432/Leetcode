class Solution(object):
    def validStrings(self, n):
        ans = []
        temp = []
        self.f(n, temp, ans)
        return ans
        
    @staticmethod
    def f(n, temp, ans):
        if len(temp) == n:
            ans.append("".join(temp)) 
            return
        if len(temp) > 0 and temp[-1] == '0':
            temp.append('1')
            Solution.f(n, temp, ans)
            temp.pop()
        else:
            temp.append('0')
            Solution.f(n, temp, ans)
            temp.pop()
            temp.append('1')
            Solution.f(n, temp, ans)
            temp.pop()