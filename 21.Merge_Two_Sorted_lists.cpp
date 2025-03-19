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
            ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
                ListNode *newList, *temp;
                
                list1->val < list2->val ? newList->val = list1->val : newList->val = list2->val;
                list1->val < list2->val ? list1 = list1->next : list2 = list2->next;
                list1->val < list2->val ? newList->next = list1 : newList->next = list2;
                while(list1 != nullptr || list2 != nullptr)
                {
                    if(list1 == nullptr){
                        while(list2 != nullptr){
                            temp = list2->next;
                            list2 = list2->next;   
                        }
                        break;
                    }
                    if(list2 == nullptr){
                        while(list1 != nullptr){
                            temp = list1->next;
                            list1 = list1->next;
                        }
                        break;
                    }
                    if(list1->val < list2->val){
                        temp->val = list1->val;
                        
                        list1 = list1->next;
                        (list1->val < list2->val) ? temp->next = list1 : temp->next = list2;
                    }
                    else{
                        temp->val = list2->val;
                        
                        list2 = list2->next;
                        (list1->val < list2->val) ? temp->next = list1 : temp->next = list2;
                    }
                }
                return newList;
            }
        };

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *newList;
    
    if(list1->val < list2->val){
        newList->val = list1->val;
        list1 = list1->next;

    }
    else{
        newList->val = list2->val;
        list2 = list2->next;
        
    }
    newList->next = mergeTwoLists(list1,list2);            
                
    return newList;
}

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