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
    void nextPermutation(vector<int>& nums) {
        int num = nums.size();
        if (num <= 1) return;  // nums的个数小于1，直接返回原数组
        // 从后往前遍历数组，找到第一个比前面数大的数
        int idx = 0;
        int i = num - 1;
        while(i>0){
            if (nums[i] > nums[i-1])
            {
                idx = i;
                break;
            }
            i--;
        }
        // 如果比前一个数大的数不存在，说明数组是递减的，直接返回该数组的倒序序列即为递增序列
        if (idx != 0) {
            int low_num = nums[idx-1]; // 第一个比后面数小的数
            for (i=num-1; i>=idx; i--){  // 从后往前遍历，找到第一个比low_num大的数
                if(nums[i] > low_num){
                    //与low_num进行互换
                    nums[idx-1] = nums[i];
                    nums[i] = low_num;
                    break;
                }
            }
        }
        // 从idx位置开始往后是递减的序列，反转递减序列
        int left = idx, right = num-1;
        while(left < right){
            int temp = nums[right];
            nums[right] = nums[left];
            nums[left] = temp;
            left++;
            right--;
        }
    }
};

int main() {
    vector<int> nums = {1,2,4,6,5,3};
    Solution solution = Solution();
    solution.nextPermutation(nums);
    for (int i=0; i<nums.size(); i++){
        cout << nums[i]<<endl;
    }
    return 0;
}

