/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;
 node* mergeTwoLists( node* l1,  node* l2) {
    node *l=NULL,*L,*t,*p;
    while(l1!=NULL && l2!=NULL){
        if(l1->val>l2->val){
            if(l==NULL){
                l=l2;
                L=l;
                t=l2->next;
                l2=t;
            }else{
                l->next=l2;
                l=l2;
                t=l2->next;
                l2=t;
            }
        }
        else if(l1->val<l2->val){
            if(l==NULL){
                l=l1;
                L=l;
                t=l1->next;
                l1=t;
            }else{
                l->next=l1;
                l=l1;
                t=l1->next;
                l1=t;
            }
        }
        else{
            if(l==NULL){
                l=l1;
                L=l;
                t=l1->next;
                l1=t;
            }else{
                l->next=l1;
                l=l1;
                t=l1->next;
                l1=t;
            }
            l->next=l2;
            l=l2;
            t=l2->next;
            l2=t;
        }
    }
    if(l1==NULL && l2!=NULL){
        if(l==NULL){
            l=l2;
            L=l;
        }else{
            l->next=l2;
        }
    }else if(l2==NULL && l1!=NULL){
        if(l==NULL){
            l=l1;
            L=l;
        }else{
            l->next=l1;
        }
    }
    return L;
}