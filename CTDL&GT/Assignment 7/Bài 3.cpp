#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* insertBST(TreeNode* root, int value) {
    if (!root) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insertBST(root->left, value);
    } else {
        root->right = insertBST(root->right, value);
    }

    return root;
}

void printSubtreePreOrder(TreeNode* root, int Q) {
    if (!root) {
        return;
    }

    if (root->data == Q || root->data < Q) {
        cout << root->data << " ";
    }

    printSubtreePreOrder(root->left, Q);
    printSubtreePreOrder(root->right, Q);
}

int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(TreeNode* root) {
    if (!root) {
        return 0;
    }

    if (!root->left && !root->right) {
        return 1; // Leaf node
    }

    return countLeaves(root->left) + countLeaves(root->right);
}

int findHeight(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

void printPreOrder(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(TreeNode* root) {
    if (root) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->data << " ";
    }
}

void printInOrder(TreeNode* root) {
    if (root) {
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }
}
TreeNode* deleteLeaves(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    if (!root->left && !root->right) {
        delete root;
        return nullptr;
    }
    root->left = deleteLeaves(root->left);
    root->right = deleteLeaves(root->right);
    return root;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
        return nullptr;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = root->right;
        while (temp->left) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    int N;
    cin >> N;
    TreeNode* root = nullptr;
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        root = insertBST(root, value);
    }
    int Q;
    cin >> Q;
    printSubtreePreOrder(root, Q);
    cout << endl;
    cout << "Number of nodes: " << countNodes(root) << endl;
    cout << "Number of leaves: " << countLeaves(root) << endl;
    cout << "Height of the tree: " << findHeight(root) << endl;
    cout << "Pre-order traversal of BST: ";
    printPreOrder(root);
    cout << endl;
    cout << "Post-order traversal of BST: ";
    printPostOrder(root);
    cout << endl;
    cout << "In-order traversal of BST: ";
    printInOrder(root);
    cout << endl;
    root = deleteLeaves(root);
    int deleteKey;
    cin >> deleteKey;
    root = deleteNode(root, deleteKey);
    return 0;
}
