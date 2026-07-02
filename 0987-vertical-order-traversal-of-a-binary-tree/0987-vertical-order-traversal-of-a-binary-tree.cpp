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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;    // .push({node, vertex, level});
        //here ordered matters so we use map
        //multiset used for sorting and it allows duplicate value
        map<int, map<int, multiset<int>>> mp;

        q.push({root, {0, 0}});
        while(!q.empty()){
            auto a=q.front();
            q.pop();

            TreeNode* node=a.first;
            int vertex=a.second.first;
            int level=a.second.second;

            mp[vertex][level].insert(node->val);

            if(node->left){
                q.push({node->left, {vertex-1, level+1}});
            }

            if(node->right){
                q.push({node->right, {vertex+1, level+1}});
            }
            
        }

        for(auto it : mp){
            vector<int> col;
            for(auto j : it.second){
                col.insert(col.end(), j.second.begin(), j.second.end());//multiset ke saare elements ko vector ke end mein insert karti hai
            }
            ans.push_back(col);
        }
        return ans;

    }
};