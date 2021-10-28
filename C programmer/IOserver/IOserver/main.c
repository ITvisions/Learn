//
//  main.c
//  IOserver
//
//  Created by vision chen on 2021/4/15.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/select.h>

#define BUFFLEN 1024
#define SERVER_PORT 6666
#define BACKLOG 5
#define CLIENTNUM 10000

int connect_host[CLIENTNUM];
int connect_number = 0;

static void *handle_request(void *argv) {
    time_t now;
    char buff[BUFFLEN];
    int n = 0;
    int maxfd = -1;
    fd_set scanfd;
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    
    int i = 0;
    int err  = -1;
    
    for (;;) {
        maxfd = -1;
        FD_ZERO(&scanfd);
        for (i = 0 ; i < CLIENTNUM ; i++) {
            if (connect_host[i] != -1) {
                {
                    FD_SET(connect_host[i],&scanfd);
                    if (maxfd < connect_host[i]) {
                        {
                            maxfd = connect_host[i];
                        }
                    }
                }
            }
        }
        /*select*/
        switch (err) {
            case 0:
                break;
            case -1:
                break;
            default:
                if (connect_number <= 0)
                    break;
                for (i = 0 ; i < CLIENTNUM; i++) {
                    if (connect_host[i] != -1) {
                        if (FD_ISSET(connect_host[i],&scanfd)) {
                            memset(buff, 0, BUFFLEN);
                            n = recv(connect_host[i], buff, BUFFLEN, 0);
                            if (n > 0 && !strcmp(buff, "TIME")) {
                                memset(buff, 0, BUFFLEN);
                                now = time(NULL);
                                printf(buff,"%24s\r\n",ctime(&now));
                                send(connect_host[i],buff,strlen(buff),0);
                            }
                            connect_host[i] = -1;
                            connect_number--;
                            close(connect_host[i]);
                        }
                    }
                    break;
                }
        }
    }
    return NULL;
}

static void *handle_connect(void *argv) {
    return NULL;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
