class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        delimiters = ' !?\',;.'
        for d in delimiters:
            paragraph = paragraph.replace(d, ' ')
        paragraph = paragraph.lower()
        
        tokens = paragraph.split()
        
        banned_set = set(banned)
        
        word_num = dict()
        for token in tokens:
            if not (token in banned_set):
                if word_num.get(token) == None:
                    word_num[token] = 1
                else:
                    word_num[token] += 1
        maximum = 0
        maximum_word = ""
        for item in word_num:
            if maximum < word_num.get(item):
                maximum_word = item
                maximum = word_num.get(item)
            
        return maximum_word