/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    struct TreeNode* stack[1024*100];
    struct TreeNode* p=root;
    int* array;
    int index=0, n=0;
    
    array=(int*)malloc(sizeof(int)*(1024*100));
    
    while(1)
    {
        while(p != NULL)
        {
            stack[index]=p;
            index++;
            p=p->left;
        }
        if(index == 0){
            break;
        }
        p=stack[index-1];
        index--;
        array[n]=p->val;
        n++;
        p=p->right;
    }
    
    *returnSize=n;
    array=(int*)realloc(array, sizeof(int)*n);
    
    return array;
}

