/**
 * @date:   2023/10/29
 * @brief:  UNP的实现是C语言, 这里改用CPP
 */

#include "unp.h"

ssize_t readn(int fd, void* vptr, size_t n)
{
    size_t nleft = n;   // 还需要读取多少数据, 才能达到预期
    ssize_t nread = 0;
    char *ptr = (char*)vptr;

    while(nleft > 0)
    {
        nread = read(fd, ptr, nleft);
        if(nread == -1)
        {
            // 不判断EAGAIN, 非阻塞IO才会出现EAGAIN; EAGAIN应该在上层判断, 决定具体处理方式;
            if(errno == EINTR)
                nread = 0;
            else
                return -1;
        }
        else if(nread == 0)
        {
            break;
        }
        nleft -= nread;
        ptr += nread;   // 移动指针位置, 用户自己保证空间大小足够
    }
    return n - nleft;
}