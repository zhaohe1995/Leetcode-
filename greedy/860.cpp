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
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int coin_5 = 0, coin_10 = 0, coin_20 = 0;
        for (int i=0; i<n; i++){
            if (bills[i] == 5){
                coin_5++;
            }
            else if (bills[i] == 10){
                if(coin_5 < 1)
                    return false;
                else{
                    coin_5--;
                    coin_10++;
                }
            }
            else if (bills[i] == 20){
                if(coin_10 >= 1 && coin_5 >= 1){
                    coin_10--;
                    coin_5--;
                    coin_20++;
                }
                else if(coin_5 >= 3){
                    coin_5 -= 3;
                    coin_20++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<int> bills = {5,5,5,10,20};
    Solution solution = Solution();
    cout << solution.lemonadeChange(bills);
    return 0;
}
