// using queue

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(root == NULL){
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> result;
        bool level = true;

        while(!q.empty()){

            int n = q.size();
            vector<int> ans;

            for(int i = 0;i < n;i++){

                TreeNode* temp = q.front();
                q.pop();
                ans.push_back(temp -> val);
                
                if(temp -> left){
                    q.push(temp -> left);
                }
                if(temp -> right){
                    q.push(temp -> right);
                }
            }
            if(!level){
                reverse(ans.begin(),ans.end());
            }
            level = !level;
            result.push_back(ans);
        }

        return result;
    }
};

// using queue

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> path;
        bool direction = true;

        while(!q.empty()){

            int n = q.size();
            vector<int> ans(n);

            for(int i = 0;i < n;i++){

                TreeNode* temp = q.front();
                q.pop();

                int idx = direction ? i : n - i - 1;
                ans[idx] = temp -> val;

                if(temp -> left){
                    q.push(temp -> left);
                }
                if(temp -> right){
                    q.push(temp -> right);
                }
            }

            direction = !direction;
            path.push_back(ans);
        }
        return path;
    }
    
};