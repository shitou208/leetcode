#Given a non-negative number represented as an array of digits, plus one to the number.
#The digits are stored such that the most significant digit is at the head of the list.
#Note:对于list类型的变量，如a,a.reverse()是对a本身进行反转，执行完之后a就发生了反转，而令b=a.reverse()这种赋值是错误的
#

class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        length=len(digits)
        res=[]
        if (digits[length-1]==9):
            flag=True
            res.append(0)
        else:
            flag=False
            res.append(digits[length-1]+1)
        i=length-2
        while (i>=0):
            if flag:
                if(digits[i]==9):
                  flag=True
                  res.append(0)
                else:
                  flag=False
                  res.append(digits[i]+1)
            else:
                res.append(digits[i])
                flag=False
            i=i-1
        if flag:
            res.append(1)
        res.reverse()
        return res