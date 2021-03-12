class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        s = re.sub('[^a-z0-9]', '', s)
        s_len = len(s)
        for i in range(0, int(s_len/2)):
            if s[i] != s[-1-i]:
                return False
        
        return True
        