/**
 * @date:   2023/10/29
 * @brief:  UNP的实现是C语言, 这里改用CPP
 */

#include	"unp.h"

ssize_t writen(int fd, const void *vptr, size_t n)
{
    size_t nleft = n; // 还需要写入多少数据
    ssize_t written_byte = 0;
    const char *ptr = (const char*)vptr;
    
    while (nleft > 0)
    {
        written_byte = write(fd, ptr, nleft);
        if ( written_byte == -1)
        {
            if (errno == EINTR)
                written_byte = 0;/* and call write() again */
            else
                return -1;/* error */
        }
        else if(written_byte == 0)
        {
            // 基本不会出现这种情况, 除非用户传入的参数n为0
            return 0;
        }
        
        nleft -= written_byte;
        ptr   += written_byte;
    }
    return n;
}


void Writen(int fd, void *ptr, size_t nbytes)
{
    if (writen(fd, ptr, nbytes) != nbytes)
        err_sys("writen error");
}
