#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // 先对nums进行从大到小的排序
        int len = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        int count = 0;
        // 三个指针：p从头遍历数组，left从p+1往后遍历，right从最后遍历
        // 循环中先固定p
        // 然后将left和right看成是双指针
        // 相当于对于每个left，找到其对应的右边界
        for (int p=0; p<len-2; p++){
            int left = p+1;
            int right = len-1;
            // 两个指针分别从两边向中间遍历
            while(left < right){
                if(nums[left] + nums[right] <= nums[p])
                    right--;
                else{
                    count += (right-left);
                    left++;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {2,2,3,4};
    Solution solution = Solution();
    cout << solution.triangleNumber(nums);


    return 0;
}