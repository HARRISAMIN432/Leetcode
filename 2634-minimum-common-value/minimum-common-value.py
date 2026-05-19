class Solution(object):
    def getCommon(self, nums1, nums2):
        p1, p2, n, m = 0, 0, len(nums1), len(nums2)
        while p1 < n and p2 < m: 
            if nums1[p1] == nums2[p2]:
                return nums1[p1]
            elif nums1[p1] > nums2[p2]:
                p2 += 1
            else:
                p1 += 1
        return -1
        