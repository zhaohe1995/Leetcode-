#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

class Solution {
public:
    int nthUglyNumber(int n) {
        // 返回第n个丑数
        if (n==0) return 0; // 第0个返回0
        int m2 = 0, m3 = 0, m5 = 0;
        int i = 0;
        vector<int> ans = {1};
        while(i<n){
            int minnum = min(min(ans[m2]*2, ans[m3]*3), ans[m5]*5);
            ans.push_back(minnum);
            // m2: *2之后获得到的当前最大值
            if(ans[m2] * 2 == minnum) m2+=1;
            // m3: *3之后获得到的当前最大值
            if(ans[m3] * 3 == minnum) m3+=1;
            // m5: *5之后获得到的当前最大值
            if(ans[m5] * 5 == minnum) m5+=1;
            i+=1;
        }
        return ans[i-1];
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.nthUglyNumber(6);
    return 0;
}