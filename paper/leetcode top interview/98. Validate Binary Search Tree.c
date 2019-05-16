/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void search(struct TreeNode *root, int array[1024], int *n)
{
    if(root->left != NULL){
        search(root->left, array, n);
    }
    array[*n]=root->val;
    (*n)++;
    if(root->right != NULL){
        search(root->right, array, n);
    }
}

bool isValidBST(struct TreeNode* root)
{
    int array[1024*100], n=0, i;
    
    if(root == NULL || root->left == NULL && root->right == NULL){
        return 1;
    }
    
    search(root, array, &n);
    for(i=1; i<n; ++i)
    {
        if(array[i] <= array[i-1]){
            break;
        }
    }
    if(i == n){
        return 1;
    }
    
    return 0;
}

