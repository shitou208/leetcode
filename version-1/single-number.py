#single number
#先排序，再找就简单了
def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        flag=True
        nums.sort()
        for i in range(len(nums)-1)[::2]:
            if nums[i]!=nums[i+1]:
              flag=False
              return nums[i]
              break
        if  flag:
          return nums[len(nums)-1]