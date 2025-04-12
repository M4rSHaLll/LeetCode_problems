#include <iostream>

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };


    class Solution {
        public:
            int minVal(ListNode* l1, ListNode* l2) {
                int min;
                if(l1 == nullptr){
                    min = l2->val;
                    l2 = l2->next;
                    return min;
                }
                if(l2 == nullptr){
                    min = l1->val;
                    l1 = l1->next;
                    return min;
                }

                if(l1->val < l2->val){
                    min = l1->val;
                    l1 = l1->next;
                }
                else{
                    min = l2->val;
                    l2 = l2->next;
                }
                return min;
            }
            ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
                ListNode *head, *temp, *l1 = list1, *l2 = list2;

                while(l1 != nullptr || l2 != nullptr)
                {
                    if(head->next == nullptr){
                        head->val = minVal(l1,l2);
                        temp->val = minVal(l1,l2);
                        head->next = temp;  
                    }
                    temp->next = new ListNode(minVal(l1,l2));
                    temp = temp->next;       
                      
                
                    
                }
                return head;
            }
            
        };



int main()
{
    ListNode list1(1), list2(1),list11(2),list12(4),list21(3),list22(4);
    list11.next = &list12;
    list1.next = &list11;
    list21.next = &list22;
    list2.next = &list21;

    Solution s;
    ListNode *newList = s.mergeTwoLists(&list1,&list2);

    for(int i = 0; i < 6; i++)
    {
        std::cout << newList->val << std::endl;
        newList = newList->next;
    }
    return 0;
}