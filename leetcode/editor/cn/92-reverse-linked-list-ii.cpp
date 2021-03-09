//反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。 
//
// 说明: 
//1 ≤ m ≤ n ≤ 链表长度。 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL, m = 2, n = 4
//输出: 1->4->3->2->5->NULL 
// Related Topics 链表 
// 👍 707 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverseListN(ListNode *head, int n)
    {
        if(n == 1){
            return head;
        }
        ListNode *tail = head->next;
        ListNode *p = reverseListN(head->next, n - 1);
        head->next = tail->next;
        tail->next = head;

        return p;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *res = ListNode(0, head);
        ListNode *p = head;
        ListNode *q = res;
        while(--left){
            q = q->next;
            p = p->next;
        }
        p = reverseListN(q, right - left + 1);

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
}