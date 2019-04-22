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
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> ans;
        if (n == 1){
            ans.push_back(A[0]*A[0]);
            return ans;
        }
        int i;
        if(A[0] < 0){
            for(i=0; i<n; i++){
                if (i==n-1) break;
                if (A[i] < 0 && A[i+1] >=0)
                    break;
            }
        }
        else{
            i = 0;
        }
        int left = i;
        int right = i+1;
        while(left >=0 && right < n){
            int left_square = A[left] * A[left];
            int right_square = A[right] * A[right];
            if (left_square <= right_square){
                ans.push_back(left_square);
                left--;
            }
            else{
                ans.push_back(right_square);
                right++;
            }
        }
        while(left>=0){
            int left_square = A[left] * A[left];
            ans.push_back(left_square);
            left--;
        }
        while(right < n){
            int right_square = A[right] * A[right];
            ans.push_back(right_square);
            right++;
        }
        return ans;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> A = {0, 2};
    vector<int> ret = solution.sortedSquares(A);
    for (int i=0; i<ret.size(); i++)
        cout << ret[i]<< endl;
    return 0;
}
