#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr; // Base case

        int mid = left + (right - left) / 2; // Middle element
        TreeNode* root = new TreeNode(nums[mid]); // Create node

        root->left = buildBST(nums, left, mid - 1);  // Left subtree
        root->right = buildBST(nums, mid + 1, right); // Right subtree

        return root;
    }
};
void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(nums);

    cout << "In-order Traversal of BST: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
