def isPalindrome(self, x: int) -> bool:
        #str변환 후 stack에 쌓아서 비교
        ##############first try################
        '''
        temp=str(x)
        if temp[0] == '-' : return False
        else:
            cnt=0
            for i in range(len(temp)//2+1):
                if temp[i] == temp[len(temp)-i-1]: cnt+=1
            if cnt==len(temp)//2+1: return True
            else: return False'''
        ################second try#############
        '''
        temp=str(x)
        if len(temp) == 1: return True
        elif len(temp) == 2:
            if temp[0] == temp[1] : return True
            else : return False
        else:
            if temp[0] == temp[-1] :
                result=temp[1:len(temp)]
                result=str(result)
                return isPalindrome(self,result)
            else: return False'''
        #########################################
        if x<0 : return False
        else:
            temp=[]
            while x>=10:
                result=x%10
                temp.append(result)
                x=x//10
            temp.append(x)
            cnt=0
            for i in range(0,len(temp)//2+1):
                if temp[i]==temp[len(temp)-i-1]: cnt+=1
            if cnt==len(temp)//2+1: return True
            else: return False
print(isPalindrome(121))
