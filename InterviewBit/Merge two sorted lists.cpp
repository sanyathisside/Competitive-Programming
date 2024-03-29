/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A==NULL){
        return B;
    }
    else if(B==NULL){
        return A;
    }
    ListNode* C;
    if(A->val < B->val){
        C=A;
        C->next=mergeTwoLists(A->next, B);
    }
        else{
            C=B;
            C->next=mergeTwoLists(A, B->next);
        }
    
    return C;
}
