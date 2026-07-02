class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;
        TreeNode* curr = root;

        while(curr){

            if(curr->right == NULL){

                ans.push_back(curr->val);
                curr = curr->left;

            }else{

                TreeNode* temp = curr->right;

                while(temp->left && temp->left != curr){
                    temp = temp->left;
                }

                if(temp->left == NULL){

                    ans.push_back(curr->val);
                    temp->left = curr;
                    curr = curr->right;

                }else{

                    temp->left = NULL;
                    curr = curr->left;

                }
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};