class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        sum=0
        tot=0
        n=len(nums)
        for i in range(n+1):
            if(n>i):
                sum=sum+nums[i]
            tot=tot+i
        return tot-sum

        
        

        