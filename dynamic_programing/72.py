"""
求解编辑距离：
----------- 题意 -----------
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符
----------- 题解 -----------
动态规划：
两个指针i，j分别指向word1和word2
定义dp[i][j]表示word1[:i]转换成word2[:j]需要的最少步骤
初始化时，dp[i][0] = i, dp[0][j] = j
如果word1[i-1] == word2[j-1]时：
    dp[i][j] = dp[i-1][j-1]  // 什么都不需要做
反之，如果word1[i] == word2[j]时：
    dp[i][j] = min(
        dp[i-1][j] + 1, // 向word2插入一个字符
        dp[i][j-1] + 1, // 向word1插入一个字符
        dp[i-1][j-1] + 1,  // 将word1和word2最后一个字符进行替换
    )
最后返回dp[word1_len][word2_len]即为最终结果
"""
class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        word1_len, word2_len = len(word1), len(word2)
        dp = [[0]*(word2_len+1) for _ in range(word1_len+1)]
        for i in range(1, word1_len+1):
            dp[i][0] = i
        for j in range(1, word2_len+1):
            dp[0][j] = j
        for i in range(1, word1_len+1):
            for j in range(1, word2_len+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
        return dp[word1_len][word2_len]


if __name__ == "__main__":
    word1 = 'intention'
    word2 = 'execution'
    solution = Solution()
    print(solution.minDistance(word1, word2))