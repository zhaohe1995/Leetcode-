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
        priority_queue<int> q;   // 维护一个大小为k的大顶堆，堆顶为最大值
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                q.push(matrix[i][j]);
                if (q.size()>k) q.pop();
            }
        }
        return q.top();
    }
};

int main() {
    vector<int> bills = {5,5,5,10,20};
    Solution solution = Solution();
    cout << solution.lemonadeChange(bills);
    return 0;
}