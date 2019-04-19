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
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];  // 对vector的排序函数
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> t(2);
        vector<vector<int>> ans;
        if (n==0) return ans;
        sort(intervals.begin(), intervals.end()); // 对intervals根据第一个元素从小到大排序
        t[0] = intervals[0][0];
        t[1] = intervals[0][1];
        if (n==1){
            ans.push_back(t);
            return ans;
        }
        for (int i=1; i<n; i++){
            if(intervals[i][0] <= t[1]){
                t[1] = max(t[1], intervals[i][1]);
            }
            else{
                ans.push_back(t);
                t = intervals[i];
            }
        }
        ans.push_back(t);
        return ans;
    }
};

int main() {
    Solution solution = Solution();
    vector<vector<int>> = {};
    return 0;
}
