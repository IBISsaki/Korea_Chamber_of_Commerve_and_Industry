#include "gcd.h"

int gcd(int a, int b)
{
    int remain;
    
    while (remain = a % b )
    {
        a = b;
        b = remain;
    }
    
    return b;
}

// int gcd(int a, int b)           // 최대공약수 구하기
// {
//     if(b > a)
//     {
//         int tmp = a;
//         a = b;
//         b = tmp;
//     }

//     int result = 1;
//     for(int i = 1; i <= b; ++i)
//     {
//         if (a % 1 == 0 && b % i == 0)
//         {
//             result = i;
//         }
//     }
    
//     return result;
// }