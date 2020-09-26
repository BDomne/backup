/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


#define LEN 20001

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    struct ListNode *p, result;
    char lable[LEN];
    int i, j;

    if(listsSize == 0){
        return NULL;
    }

    memset(lable, 0, LEN);
    for(i = 0; i < listsSize; ++i)
    {
        if(lists[i] != NULL)
        {
            p = lists[i];
            ++lable[p->val + 10000];
            while(p->next != NULL)
            {
                p = p->next;
                ++lable[p->val + 10000];
            }
        }
    }

    result.next = NULL;
    p = &result;
    for(i = 0; i < LEN; ++i)
    {
        while(lable[i]-- != 0)
        {
            for(j = 0; j < listsSize; ++j)
            {
                if(lists[j] != NULL && lists[j]->val + 10000 == i)
                {
                    p->next = lists[j];
                    p = p->next;
                    lists[j] = lists[j]->next;
                    break;
                }
            }
        }
    }

    return result.next;
}
