#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==0) return 0;
        int num = primes.size();
        if(num==0) return 0;
        vector<int> m_list = vector<int>(num, 0);
        vector<int> ans = {1};
        int i=0;
        int minnum;
        while(i<n){
            minnum = ans[m_list[0]] * primes[0];
            for (int j=0; j<num; j++){
                int factor = primes[j];
                int index = m_list[j];
                minnum = min(minnum, ans[index] * factor);
                //cout << factor <<" "<< index<< " "<<minnum<<endl;
            }
            ans.push_back(minnum);
            for (int j=0; j<num; j++){
                int factor = primes[j];
                int index = m_list[j];
                if (minnum == ans[index] * factor){
                    m_list[j]++;
                }
            }
            i++;
        }
        return ans[i-1];
    }
};

int main() {
    vector<int> primes = {2,7,13,19};
    Solution solution = Solution();
    cout << solution.nthSuperUglyNumber(12, primes);
    return 0;
}