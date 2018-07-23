
#include <stdint.h>

#include <iostream>

// 除以一个2，原来的数字就会减少一个0，。
// 如果除的过程中有余数，那么就表示当前位置有一个1
int count_one(uint8_t v)
{
    int num = 0;
    while (v)
    {
        if (v % 2 == 1)
            ++num;
        v = v / 2;
    }
    return num;
}

// 使用移位操作
// 复杂度 O(log2 v)
int count_two(uint8_t v)
{
    int num = 0;
    while (v)
    {
        num += v & 0x01;
        v >>= 1;
    }
    return num;
}

// 如何判断给定的二进制数里面有且仅有一个1呢？
// 可以通过判断这个数是否是2的整数次幂来实现。
// 复杂度 O(M) M为v中1的个数
int count_three(uint8_t v)
{
    int num = 0;
    while (v)
    {
        v &= (v - 1);
        ++num;
    }
    return num;
}

// 解法四：使用分支操作
// 解法五：查表法

int main(void)
{
    std::cout << "7 : 3 --> " << count_three(7) << std::endl;
    
    return 0;
}