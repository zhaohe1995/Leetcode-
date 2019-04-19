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
    int n;
    void permute(int d, vector<bool>& f, vector<int>& nums, vector<int>& t, vector<vector<int>>& ans){
        // 用来决定每个元素
        if (d >= n){
            ans.push_back(t);   // 如果序列中的元素个数大于n，将当前置换序列加入结果ans
            return;
        }
        for (int i=0; i<n; i++){  // 从头往后开始遍历元素
            if (f[i] == 1)    // 如果元素i在标记数组中已经被标记过（放进置换序列了），则跳过
                continue;
            if (i>0 && nums[i] == nums[i-1] && f[i-1] == 0)  // 如果当前元素等于前一个元素且前个元素没有放入置换序列了（保证重复的元素按照索引的顺序依次加入到置换序列）
                continue;
            t[d] = nums[i];   // 将当前元素加入置换序列
            f[i] = 1;    // 更新标记数组
            permute(d+1, f, nums, t, ans);   // 递归地决定下一个元素
            f[i] = 0;   // 递归返回后，把当前元素的标记数组回归0
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());  // 将数组按照升序排列，使重复的元素彼此相邻
        vector<vector<int>> ans;
        vector<int> t(n);   // 一次置换的序列
        vector<bool> f(n, 0);  // 用来记录前面重复的元素是否已经放入了置换序列中，把f标记数组全部初始化为0
        permute(0, f, nums, t, ans);   // 从第一个元素开始对序列进行置换
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    Solution solution = Solution();
    solution.permuteUnique(nums);
    return 0;
}
