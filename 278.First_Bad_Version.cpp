#include <iostream>
#include <cmath>


// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
    public:
        int firstBadVersion(int n) {
            int max = n, min = 1;
            for(int i = 0;i < log2(n);i++)
            {
                if(isBadVersion(int((long(max) + long(min)) / 2)) && !isBadVersion(int((long(max) + long(min)) / 2) - 1))
                    return int((long(max) + long(min)) / 2);
                else if(isBadVersion(int((long(max) + long(min)) / 2)))
                {
                    max = int((long(max) + long(min)) / 2);
                }
                else
                {
                    min = int((long(max) + long(min)) / 2);
                }
            }
            return max;
    
        }
    };