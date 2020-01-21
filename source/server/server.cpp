#include "common.h"

using namespace std;

#include "CGlog.h"

int main(int argc, char **argv)
{
    if (2 != argc) {
        CGlog::log("Usage:%s port", argv[0]);
        exit(-1);
    }

    int port = atoi(argv[1]);
    if (port < 1024) {
        CGlog::log("port:%d less than 1024", port);
        exit(-1);
    }

    int servfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == servfd) {
        CGlog::log("create socket error:%d,%s", errno, strerror(errno));
        exit(-1);
    }

    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    int reuse = 1;
    setsockopt(servfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    int nonblock = 1;

    if (bind(servfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        CGlog::log("bind port:%d failed!%d:%s", port, errno, strerror(errno));
        close(servfd);
        servfd = -1;
        exit(-1);
    }

    if (listen(servfd, 1000) < 0) {
        CGlog::log("listen failed:%d,%s", errno, strerror(errno));
        close(servfd);
        servfd = -1;
        exit(-1);
    }

    int peerfd = -1;
    socklen_t peer_addr_size = sizeof(struct sockaddr_in);
    struct sockaddr_in peer_addr;
    bzero(&peer_addr, sizeof(peer_addr));
    if ((peerfd = accept(servfd, (struct sockaddr*)&peer_addr, &peer_addr_size)) < 0) {
        CGlog::log("accept failed:%d,%s", errno, strerror(errno));
        close(servfd);
        servfd = -1;
        exit(-1);
    }

    size_t size = 0;
    char msg[1024];
    while (1) {
#if 0
        bzero(msg, sizeof(msg));
        size = recv(peerfd, msg, sizeof(msg), 0);
        if (-1 == size) {
            CGlog::log("peer encounter error:%d.%s", errno, strerror(errno));
            close(peerfd);
            close(servfd);
            servfd = -1;
            exit(-1);
        } else if (0 == size) {
            CGlog::log("peer has closed");
            close(peerfd);
            close(servfd);
            servfd = -1;
            exit(-1);
        } else {
#endif
            strcpy(msg, "hello world");
            send(peerfd, msg, strlen(msg), 0);
            break;
#if 0
            CGlog::log("reply tp peer:%s.%d", inet_ntoa(peer_addr.sin_addr), ntohs(peer_addr.sin_port));
        }
#endif
    }
    if (-1 != servfd) {
        close(servfd);
    }
    return 0;
}


