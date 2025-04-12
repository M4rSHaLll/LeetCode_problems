#include <iostream>
#include <math.h>
int lenx(int x)
{
    int count = 0;
    do{
        x /= 10;
        count++;
    }while (x / 10 != 0);
    return count;
}
bool isPalindrome(int x) {
    while (x != 0){
        if(lenx(x) == 1)
            return true;
        if ( x < 0 || x % 10 != x / pow(10,lenx(x) - 1))
            return false;
        
        x /= 10;
        x /= pow(10,lenx(x) - 1);
    }   
}

int main()
{
    std::cout << isPalindrome(121);
}