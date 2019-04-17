#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        // pre_head: 整个链表前一个节点，在第一对换完之后初始化
        ListNode* pre_head = new ListNode(-1);
        // p0: 第一个节点前一个节点
        ListNode* p0 = new ListNode(-1);
        p0->next = head;
        // p1: 第一个节点
        ListNode* p1 = head;
        // p2: 第二个节点
        ListNode* p2 = p1->next;
        // p3: 第二个节点后一个节点
        ListNode* p3 = p2->next;
        int i=0;
        while(p1!=NULL){
            p2->next = p1;
            p1->next = p3;
            p0->next = p2;
            if(i==0)
                pre_head->next = p2;
            i+=1;
            p0 = p1;
            p1 = p1->next;
            if(p1==NULL)
                break;
            p2 = p1->next;
            if(p2==NULL)
                break;
            p3 = p2->next;
        }
        return pre_head->next;
    }
};

int main() {
    /* prepare data */
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    int i=2;
    while(i<=3){
        p->next = new ListNode(i);
        p = p->next;
        i++;
    }
    /* function */
    Solution solution = Solution();
    ListNode* res_head = solution.swapPairs(head);
    /* output */
    ListNode* p1 = res_head;
    while(p1 != NULL)
    {
        cout << p1->val << endl;
        p1 = p1->next;
    }


    return 0;
}
