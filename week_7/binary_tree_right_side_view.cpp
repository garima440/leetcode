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
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;

        if (!root)
        {
            return {};
        }

        vector <int> result;

        q.push(root);

        while(!q.empty())
        {
            int n = q.size();

            TreeNode* temp = nullptr;

            while(n--)
            {
                temp = q.front();
                q.pop();

                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            result.push_back(temp->val);
        }
        return result;
    }
    
};