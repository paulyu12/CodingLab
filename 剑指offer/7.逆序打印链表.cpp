#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

void PrintListReversingly_Iteratively(ListNode* pHead)
{
    stack<int> stk;

    ListNode *pNode = pHead;
    while (pNode) {
        stk.push(pNode->val);
        pNode = pNode->next;
    }

    while (!stk.empty()) {
        cout << stk.top() << endl;
        stk.pop();
    }
}

void PrintListReversingly_Recursively(ListNode* pHead)
{
    if (!pHead) {
        return;
    }
    else {
        if (pHead->next) {
            PrintListReversingly_Recursively(pHead->next);
        }

        cout << pHead->val << endl;
    }
}

ListNode *CreateListNode(int val) {
    ListNode *node = new ListNode();
    node->val = val;
    node->next = nullptr;

    return node;
}

void ConnectListNodes(ListNode *p1, ListNode *p2) {

    if (!p1) {
        cout << "Error" << endl;
        return;
    }
    p1->next = p2;
}

int main() {

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    PrintListReversingly_Recursively(pNode1);
    PrintListReversingly_Iteratively(pNode1);

    return 0;

}
