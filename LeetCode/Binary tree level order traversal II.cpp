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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return vector<vector<int>>();
        queue<TreeNode*> q;
        TreeNode* cur;
        vector<int> level;
        vector<vector<int>> ans;
        int levelCount = 0;
        
        q.push(root);
        levelCount++;
        
        while(!q.empty()){
            cur = q.front();
            q.pop();
            levelCount--;
            
            level.push_back(cur->val);
            
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            
            //cur is the last of this level
            if(levelCount == 0){
                ans.push_back(level);
                level = vector<int>();
                levelCount = q.size();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
