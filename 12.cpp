#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;
class Solution {
    public:
        
        string intToRoman(int num) {
            string res = "";
            int count;
            map<int,string> table;
            int k[] = {9, 5, 4, 1};

            table[1000] = "M", table[500] = "D", 
            table[100] = "C", table[50] = "L", 
            table[10] = "X", table[5] = "V", table[1] = "I",
            table[900] = "CM", table[400] = "CD", table[90] = "XC",
            table[40] = "XL", table[9] = "IX", table[4] = "IV";
            
           
            while(num >= 1000) {
                res.append(table[1000]);
                num -= 1000;
            }
            if(num != 0){
                for(int i = 2; i >= 0; i--){
                    for(int j = 0; j < 3; j++){
                        if(num / int(pow(10,i)) >= k[j]){
                            res.append(table[k[j] * pow(10, i)]);
                            num -= k[j] * pow(10, i);
                            break;
                        }

                    }
                    while(num / int(pow(10,i)) != 0){
                        res.append(table[pow(10,i)]);
                        num -= pow(10,i);
                    }

                }
            }
            return res;
        
        }
};

int main()
{
    Solution s;
    int num;
    do{
        cin >> num;
        cout << s.intToRoman(num) << endl;
    }while (num);
    

    return 0;
}