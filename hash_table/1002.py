class Solution(object):
    def commonChars(self, A):
        """
        :type A: List[str]
        :rtype: List[str]
        """
        char_count = dict()
        for i, word in enumerate(A):
            word_char_count = dict()
            for char in word:
                cnt = word_char_count.setdefault(char, 0)
                word_char_count[char] = cnt + 1
            if i==0:
                for char in word_char_count:
                    char_count[char] = word_char_count[char]
            else:
                for char in char_count:
                    if char not in word_char_count:
                        char_count[char] = 0
                    else:
                        char_count[char] = min(word_char_count[char], char_count[char])
        ret = list()
        for char in char_count:
            if char_count[char] > 0:
                ret.extend([char]*char_count[char])
        return ret


if __name__ == "__main__":
    solution = Solution()
    A = ["bella","label","roller"]
    print solution.commonChars(A)



                