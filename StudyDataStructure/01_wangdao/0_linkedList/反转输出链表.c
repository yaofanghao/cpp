// https://leetcode.cn/leetbook/read/illustration-of-algorithm/5dt66m/

struct ListNode {
     int val;
     struct ListNode *next;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){
    int n = 0;
    int *returnArray;

    struct ListNode* p = head;
    for( p=head; p; p=p->next )
        n++;
    returnArray = (int*)malloc(sizeof(int)*n);
    *returnSize = n;
    for( p=head; p; p=p->next )
        returnArray[--n] = p->val;
    return returnArray;
}
