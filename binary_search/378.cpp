/*
行和列分别递增的矩阵，找第k大的元素。
二分查找
*/
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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1]+1;
        int mid = left;
        while(left < right){
            mid = left + (right - left)/2;
            int cnt = 0, cnt2 = 0;
            for (int i=0; i<n; i++){
                auto &v = matrix[i];
                // lower_bound 从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址
                cnt += lower_bound(v.begin(), v.end(), mid) - v.begin();
                // upper_bound 从数组的begin位置到end-1位置二分查找第一个大于num的数字，找到返回该数字的地址
                cnt2 += upper_bound(v.begin(), v.end(), mid) - v.begin();
            }
            if (cnt<k && cnt2>=k) return mid;
            if (cnt<k) left = mid+1;
            else right = mid;
        }
        return mid;
    }
};

int main() {
    vector<int> bills = {5,5,5,10,20};
    Solution solution = Solution();
    
    return 0;
}
