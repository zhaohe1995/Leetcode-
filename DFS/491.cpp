#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <stack>
#include <unordered_set>

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;  // 记录返回结果
        vector<int> subseq;      // 记录子序列
        dfs(ans, subseq, nums, 0);   // 从位置0开始对序列进行深度优先搜索
        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& subseq, vector<int>nums, int pos){
        if (subseq.size() > 1)    // 如果当前子序列的长度大于2，则将子序列加入返回结果
            ans.push_back(subseq);
        unordered_set<int> hash;   // 用一个集合存放上一个子序列最后加入的数
        for(int i=pos; i<nums.size(); i++){   // 从位置pos往后开始遍历
            // 如果子序列中无元素或当前元素大于等于子序列的最后元素，且当前元素不与之前所有子序列的最后一个元素重复
            if ((subseq.empty() || subseq.back() <= nums[i]) && hash.find(nums[i]) == hash.end()){
                subseq.push_back(nums[i]);   // 则将当前元素加入子序列中
                dfs(ans, subseq, nums, i+1);   // 递归对下一个位置继续dfs
                subseq.pop_back();   // 深度优先搜索结束弹出子序列最后一个元素
                hash.insert(nums[i]);  // 把当前元素加入集合
            }
        }
    }
};

int main() {
    vector<int> nums = {4, 6, 7, 7};
    Solution solution = Solution();
    vector<vector<int>> ret = solution.findSubsequences(nums);
    return 0;
}

