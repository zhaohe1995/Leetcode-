#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <queue>

struct P{
    int x, y;
    P(int x_, int y_): x(x_), y(y_) {}
    bool operator < (const P &p) const{
        return x*x + y*y < p.x * p.x + p.y * p.y;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        vector<vector<int>> ans;
        priority_queue<P> heap;   // 建一个最大堆

        for (auto &p : points){
            P t(p[0], p[1]);
            if (heap.size() < K){  // 如果当前堆内元素个数小于K
                heap.push(t);   // 直接将点插入堆
            }
            else{
                if(t < heap.top()){  // 否则判断当前p到原点距离是否小于堆顶
                    heap.pop();
                    heap.push(t);  // 如果比堆顶小，将堆顶元素弹出，当前点p插入堆
                }
            }
        }
        while(!heap.empty()){  // 依次从堆中弹出元素加入返回ans数组
            P t = heap.top();
            heap.pop();
            ans.push_back({t.x, t.y});
        }
        return ans;
    }
};

int main() {
    Solution solution = Solution();
    return 0;
}
