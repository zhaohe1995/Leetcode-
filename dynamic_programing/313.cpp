using namespace std;
#include <iostream>
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
        int minnum = ans[0] * primes[0];
        while(i<n){
            for (int j=0; j<num; j++){
                int factor = primes[j];
                int index = m_list[j];
                minnum = min(minnum, ans[index] * factor);
            }
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