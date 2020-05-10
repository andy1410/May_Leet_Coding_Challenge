/*
Problem:

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
 */

//Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    struct NodeInfo
{
    int key;
    int level;
    TreeNode* parent;
};
public:
    bool isCousins(TreeNode* root, int elem1, int elem2) {
            // return if tree is empty
    if (root == nullptr)
        return false;

    int level = 1;                // level of root is 1
    TreeNode* parent = nullptr;        // parent of root is null

    NodeInfo x = {elem1, level, parent};
    NodeInfo y = {elem2, level, parent};

    // perform in-order traversal of the array and update x and y
    inorder(root, nullptr, 1, x, y);

    // return false if x and y have different level or same parent
    if (x.level != y.level || x.parent == y.parent)
        return false;

    return true;

    }
    

// Perform in-order traversal of the binary tree and update x and y
void inorder(TreeNode* root, TreeNode *parent, int level, NodeInfo &x, NodeInfo &y)
{
    // base case: tree is empty
    if (root == nullptr)
        return;

    // traverse left subtree
    inorder(root->left, root, level + 1, x, y);

    // if first element is found, save its level and parent node
    if (root->val == x.key)
    {
        x.level = level;
        x.parent = parent;
    }

    // if second element is found, save its level and parent node
    if (root->val == y.key)
    {
        y.level = level;
        y.parent = parent;
    }

    // traverse right subtree
    inorder(root->right, root, level + 1, x, y);
}
    
    
};