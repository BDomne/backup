/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

void traversal(struct TreeNode *root, int layer, int array[1024*2], int *n)
{
    array[(*n)*2]=layer;
    array[(*n)*2+1]=root->val;
    (*n)++;
    if(root->left != NULL){
        traversal(root->left, layer+1, array, n);
    }
    if(root->right != NULL){
        traversal(root->right, layer+1, array, n);
    }
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    int array[1024*2], n=0, i, j, cnt=1, layer=0;
    int **result;
    
    if(root == NULL)
    {
        *returnSize=0;
        return NULL;
    }
    traversal(root, 0, array, &n);
    qsort(array, n, sizeof(int)*2, cmp);
    *returnSize=array[(n-1)*2]+1;
    *returnColumnSizes=(int*)malloc(sizeof(int)*(*returnSize));
    result=(int**)malloc(sizeof(int*)*(*returnSize));
    for(i=1; i<n; ++i)
    {
        if(array[i*2] == array[(i-1)*2]){
            cnt++;
        }
        else
        {
            (*returnColumnSizes)[layer]=cnt;
            layer++;
            cnt=1;
        }
    }
    (*returnColumnSizes)[layer]=cnt;
    layer++;
    for(i=0; i<layer; ++i){
        result[i]=(int*)malloc(sizeof(int)*((*returnColumnSizes)[i]));
    }
    n=0;
    for(i=0; i<layer; ++i)
    {
        for(j=0; j<(*returnColumnSizes)[i]; ++j)
        {
            result[i][j]=array[n*2+1];
            n++;
        }
    }
    
    return result;
}

