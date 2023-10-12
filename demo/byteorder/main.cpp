#include <iostream>

#include "unp.h"


union ByteOrder
{
    short num;
    char arr[sizeof(short)];
};


int main()
{
    // 输出CPU,操作系统相关简略信息;
    std::cout << CPU_VENDOR_OS << std::endl;

    ByteOrder var;
    var.num = 0x0102; // 1字节8位, 刚好是0x01表示
    if(sizeof(short) == 2)
    {
        if(var.arr[0] == 1 && var.arr[1] == 2)
        {
            std::cout << "big-endian!" << std::endl; 
        }
        else if(var.arr[0] == 2 && var.arr[1] == 1)
        {
            std::cout << "little-endian!" << std::endl;
        }
        else
        {
            std::cout << "unkown!" << std::endl;
        }
    }
    else
    {
        std::cout << "sizeof(short) != 2, 无法判断!" << std::endl;
    }
    return 0;
}
 