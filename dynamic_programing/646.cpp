#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <queue>

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];  // 排序的比较函数
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 0;
        vector<int> dp(pairs.size(), 1);
        // 先对pairs根据第一个元素从小到大排序
        sort(pairs.begin(), pairs.end(), cmp);
        for (int i = 1; i<pairs.size(); i++){
            for (int j=0; j<i; j++){      // 对于每个pair，等于其序列前最后一个第二个元素小于其第一个元素的dp值加1
                if (pairs[j][1] < pairs[i][0])
                    dp[i] = dp[j] + 1;
            }
            ans = max(ans, dp[i]);  // 更新ans的最大值
        }
        return ans;
    }
};

int main() {
    Solution solution = Solution();
    return 0;
}

