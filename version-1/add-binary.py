
#Given two binary strings, return their sum (also a binary string).
#For example,
#a = "11"
#b = "1"
#Return "100".

class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        numa=0
        numb=0
        res=[]
        for i in range(len(a)):
          numa=numa+(int(a[i])*(2**(len(a)-i-1)))
        for j in range(len(b)):
          numb=numb+(int(b[j])*(2**(len(b)-j-1)))
        numc=int(numa+numb)
        if numc==0:
            return '0'
        while (numc):
          if(numc%2):
            res.append('1')
          else:
            res.append('0')
          numc=numc/2;
        res.reverse()
        str2=''.join(res)
        return str2