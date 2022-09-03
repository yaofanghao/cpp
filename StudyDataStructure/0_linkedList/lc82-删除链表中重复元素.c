// 作者：you-zhi-dong-zuo
// 链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/solution/82-by-you-zhi-dong-zuo-mfxc/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head){
        return head;
    }

    struct ListNode* last=malloc(sizeof(struct ListNode));
//新建一个链表
    last->next=head;
//头节点为head的前一个节点
    struct ListNode * cur= last;
//新建指针，从head前的节点开始

    while(cur->next&&cur->next->next){
//如果下个节点和下下节点都不为空就继续循环，否则无法进行删除
        if(cur->next->val==cur->next->next->val){
//如果下节点和下下节点的数值相同
            int num=cur->next->val;
//设一个变量来标记下节点的数值，也可以方便后续循环删除
            while(cur->next&&cur->next->val==num){
//注意这里的条件是cur->next不为空且cur->next->val=num
//进入删除节点循环，只要下一个节点是相同的就删除下一个节点，因为是有节点就删所以是全删
                cur->next=cur->next->next;
            }
        }
//下节点和下下节点不同
        else{
            cur=cur->next;
        }
    }
    return last->next;
//注意dummy的头节点是dummy->next，所以返回dummy->next.
}
