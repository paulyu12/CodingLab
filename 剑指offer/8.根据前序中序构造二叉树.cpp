#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode {
    int val;
    BinaryTreeNode *leftChild;
    BinaryTreeNode *rightChild;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder) {
    int rootValue = *startPreorder;
    BinaryTreeNode *root = new BinaryTreeNode();
    root->val = rootValue;
    root->leftChild = root->rightChild = nullptr;

    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startInorder == rootValue) {
            return root;
        }
        else {
            cout << "错误的输入参数序列！" << endl;
            exit(1);
        }
    }

    int *ptr = startInorder;
    for (; *ptr != rootValue && ptr < endInorder; ptr ++);
    if(ptr == endInorder && *ptr != rootValue) {
        cout << "错误的输入参数序列！" << endl;
        exit(1);
    }

    int leftChildrenNum = ptr - startInorder;
    int rightChildrenNum = endInorder - ptr;
    if (leftChildrenNum > 0) {
        root->leftChild = ConstructCore(startPreorder + 1, startPreorder + leftChildrenNum, startInorder, ptr - 1);
    }
    if (rightChildrenNum > 0) {
        root->rightChild = ConstructCore(startPreorder + leftChildrenNum + 1, endPreorder, ptr + 1, endInorder);
    }

    return root;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
    if (!preorder || !inorder || length <= 0) {
        return nullptr;
    }
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}