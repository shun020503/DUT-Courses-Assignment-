#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

bool isBST(TreeNode* node, int min_val = INT_MIN, int max_val = INT_MAX) {
    if (!node) {
        return true;
    }
    if (node->value <= min_val || node->value >= max_val) {
        return false;
    }
    return isBST(node->left, min_val, node->value - 1) && isBST(node->right, node->value + 1, max_val);
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << boolalpha << isBST(root) << endl;  
    return 0;
}
