

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int kthSmallest(struct TreeNode* root, int k)
{
    struct TreeNode *stack[1024*100], *p=root;
    int index=-1, n=1, result;
    
    while(1)
    {
        while(p != NULL)
        {
            index++;
            stack[index]=p;
            p=p->left;
        }
        if(n == k)
        {
            result=stack[index]->val;
            break;
        }
        p=stack[index];
        p=p->right;
        index--;
        n++;
    }
    
    return result;
}

