#include "CEpollfd.h"

CEpollfd::CEpollfd()
{

}

CEpollfd::CEpollfd(const CEpollfd& epollfd)
{

}

CEpollfd::~CEpollfd()
{

}

CEpollfd& CEpollfd::operator =(const CEpollfd& epollfd)
{
    if (this == &epollfd) return *this;
    return *this;
}

int CEpollfd::create(const char* addr, const short port)
{
    return 0;
}

int CEpollfd::recv(char* msg, const int msg_length)
{
    return 0;
}

int CEpollfd::send(const char* msg, const int msg_length)
{
    return 0;
}

int CEpollfd::close()
{
    return 0;
}

