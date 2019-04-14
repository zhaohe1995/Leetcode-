class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        right = len(arr) - k
        left = 0
        while left < right:  # 目的是在查找左边界
            mid = (left + right) / 2
            if x - arr[mid] > arr[mid+k] - x:  # 如果左边界的值到x的差，比右边界值到x的差还大，则正确的左边界一定在mid的右边
                left = mid+1   # 因此向右继续查找
            else:
                right = mid   # 否则正确的左边界一定是mid或在mid的左边
        return arr[left:left+k]  # 因此向左继续查找
        

if __name__ == "__main__":
    solution = Solution()
    arr = [1,3,4,5,7,9]
    ret = solution.findClosestElements(arr, 4, 7)
    print ret
