class Solution(object):
    def longestCommonPrefix(self, arr1, arr2):
        ans = 0
        st = set()
        for x in arr1:
            s, temp = str(x), ""
            for c in s:
                temp += c
                st.add(temp)
        for x in arr2:
            s, temp = str(x), ""
            for c in s:
                temp += c
                if(temp in st):
                    ans = max(ans, len(temp))
        return ans
                
                
        