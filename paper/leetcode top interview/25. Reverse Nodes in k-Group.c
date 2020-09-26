/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
	struct ListNode *p = NULL, *q = NULL, **stack =NULL, result;
	int len = 0, i, j;

	stack = (struct ListNode **)malloc(sizeof(struct ListNode*) * k);
	p = head;
	while(p != NULL)
	{
		p = p->next;
		++len;
	}

	result.next = NULL;
	p = &result;
	q = head;
	for(i = 0; i < len / k; ++i)
	{
		for(j = 0; j < k; ++j)
		{
			stack[j] = q;
			q = q->next;
		}
		for(j = k-1; j >= 0; --j)
		{
			p->next = stack[j];
			p = p->next;
		}
	}
	p->next = q;
	free(stack);

	return result.next;
}
