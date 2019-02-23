class Solution:
    def reverse(self, x: int) -> int:
        temp=str(x)
        if temp[0].isdigit():
            result=temp[::-1]
            result=int(result)
            if result<pow(2,31)-1 : return result
            else: return 0
        else:
            result=temp[:0:-1]
            result=int(result)
            if -result>pow(-2,31): return -result
            else : return 0
        
