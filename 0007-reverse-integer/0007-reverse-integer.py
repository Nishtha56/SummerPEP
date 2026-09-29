class Solution:
    def isCheck(self, x: int) -> bool:
        if x<0:
            return True
        else:
            return False

    def count(self, x: int) -> int:
        if self.isCheck(x):
            x=abs(x)
        ct=0

        while x>0:
            ct=ct+1
            x=x//10
        return ct
    def reverse(self, x: int) -> int:
        c=self.count(x)
        temp=x
        x=abs(x)
        ans=0

        while(x>0):
            rem=x%10
            ans=ans*10+rem
            x=x//10

        if temp<0:
            ans=(-1)*ans

        if ans < -2**31 or ans > 2**31 - 1:
            return 0

        return ans