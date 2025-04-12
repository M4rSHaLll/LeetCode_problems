#include <iostream>

#include <vector>

using namespace std;
class Solution {
    public:
        
        vector<int> intToVect(int x)
        {
            vector<int> temp;
            while(x != 0){
                temp.push_back(x % 10);
                x /= 10;
            }
            return temp;
        }
        bool isPalindrome(int x) {
            if(x < 0)
                return false;
            vector<int> list_num = intToVect(x);
            while(list_num.size() != 0){
                if(list_num[0] != list_num[list_num.size() - 1])
                    return false;
                else{
                    if(list_num.size() == 1)
                        list_num.pop_back();
                    else{
                        list_num.pop_back();
                        list_num.erase(list_num.begin());
                    }
                }
            }
            return true;
            
        }
    };

int main()
{
    Solution s;
    int num;
    do{
        
        cin >> num;
        cout << s.isPalindrome(num) << '\n';
    }while(num);
    
}