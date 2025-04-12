#include <iostream>



class Solution {
    public:
        int mySqrt(int x) {
            long long n = x;
            while(n * n >= x)
            {
                if(n * n == x)
                    return n;
                else{
                    n = (n + x / n) / 2;
    
                }
            }
            return n;
            
        }
    };
    
int main()
{
    Solution s;
    int num;
    do{
        std::cin >> num;
        std::cout << "   " << s.mySqrt(num) << '\n';
    }while (num);
    
    

    return 0;
}