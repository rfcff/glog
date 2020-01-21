#include "common.h"

class CEpollfd{
 public:
    CEpollfd();
    CEpollfd(const CEpollfd& epollfd);
    ~CEpollfd();
    CEpollfd & operator =(const CEpollfd& epollfd);

    /* member function */
 public:
    int create(const char* addr, const short port);
    int recv(char* msg, const int msg_length);
    int send(const char* msg, const int msg_length);
    int close();
};

